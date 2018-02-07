//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <float.h>
#include <fstream>
#include <cmath>

using namespace std;

//////////////////////////////////////////////////////////////
//
// local #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING

#include <iostream>

#endif


//////////////////////////////////////////////////////////////
//
// struct definitions 
//
#ifndef MARMOSET_TESTING
struct Student {
    int studentID;
    int grade;
};

struct Dataset {
    int numStudents;
    Student *students;
};

struct Rejects {
    int numRejects;
    int *rejects;
};

struct Mode {
    int numModes;
    int *modes;
};

struct Statistics {
    int minimum;
    float average;
    int maximum;
    float popStdDev;
    float smplStdDev;
    Mode mode;
    int histogram[10];
};
#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
//
int readCSV(const char filename[], const int minAcceptableID,
            const int maxAcceptableID, Dataset &data,
            Rejects &rejects);

int computeStatistics(Dataset &data, Statistics &stats);

int writeCSV(const char filename[], const Statistics &stats);

//////////////////////////////////////////////////////////////
//
// Function definitions. PLEASE USE HELPER FUNCTIONS
//
int maxNumErrors = 10;

int rejector(int numRejects){
    if (numRejects == maxNumErrors) {
        return -1;
    }
    else {
        return 0;
    }
}

int readCSV(const char filename[], const int minAcceptableID,
            const int maxAcceptableID, Dataset &data,
            Rejects &rejects) {
    if (filename == NULL || filename[0] == '\0' || minAcceptableID > maxAcceptableID) {
        //cout << "-20" << endl;
        return -1;
    }

    int x = 0;
    char fileNameCSV[1000];

    while (filename[x] != '\0' && filename[x] != '.') {
        fileNameCSV[x] = filename[x];
        x++;
    }

    fileNameCSV[x++] = '.';
    fileNameCSV[x++] = 'c';
    fileNameCSV[x++] = 's';
    fileNameCSV[x++] = 'v';
    fileNameCSV[x++] = '\0';

    ifstream infile;

    infile.open(fileNameCSV);
    if (!infile.is_open())
        return -1;

    int numRejects = 0;
    int numData = 0;
    int maxLineLength = 100;
    char line[maxLineLength];
    int fileLineNumber = 0;
    bool done = false;
    int grades = 0;


    rejects.rejects = new int[maxNumErrors];
    if (rejects.rejects == NULL) {
        return -1;
    }

    data.students = new Student[1000];

    while (!done) {
        ++fileLineNumber;

        if (!infile.getline(line, maxLineLength)) { // Get next line
            if (infile.eof()) { // End of file
                done = true;
            } else { // Some error reading file
                //cout << "-1234" << endl;
                return -1;
            }
        }

        int count = 0;
        long iD = 0;

        //add rejects, if tab or space
        while (line[count] == '\t' || line[count] == ' ') {
            if (line[count] == '\0') {
                if(rejector(numRejects) == -1)
                    return -1;
                else{
                    rejects.rejects[numRejects++] = fileLineNumber;
                    continue;
                }
            }
            count++;
        }

        //increment reject for ','
        if (line[count] == ',') {
            if(rejector(numRejects) == -1)
                return -1;
            else{
                rejects.rejects[numRejects++] = fileLineNumber;
                continue;
            }
        }

        //line count
        while (line[count] != ',') {
            //build iD for the numbers
            if (line[count] <= '9' && line[count] >= '0') {
                iD = (iD * 10) + (int) (line[count]) - 48;
            } else {
                if(rejector(numRejects) == -1)
                    return -1;
                else {
                    rejects.rejects[numRejects++] = fileLineNumber;
                    break;
                }
            }
            count++;
        }

        if (rejects.rejects[numRejects - 1] == fileLineNumber) {
            continue;
        }

        //if the iD is out of bounds of min and max acceptable id
        if (iD > maxAcceptableID || iD < minAcceptableID) {
            if(rejector(numRejects) == -1)
                return -1;
            else{
                rejects.rejects[numRejects++] = fileLineNumber;
                continue;
            }
        }

        count++;
        //skip the empty spaces and tabs
        while (line[count] == '\t' || line[count] == ' ') {
            count++;
        }

        //When dash
        if (line[count] == '-') {
            if(rejector(numRejects) == -1)
                return -1;
            else{
                rejects.rejects[numRejects++] = fileLineNumber;
                continue;
            }
        } else if (line[count] == '\0' || line[count] == ',') {
            if(rejector(numRejects) == -1)
                return -1;
            else{
                rejects.rejects[numRejects++] = fileLineNumber;
                continue;
            }
        }

        //line count for grades
        while (line[count] != '\0') {
            if (line[count] <= '9' && line[count] >= '0') {
                grades = (grades * 10) + (int) (line[count]) - 48;
            } else if (line[count] != '\r') {
                if(rejector(numRejects) == -1)
                    return -1;
                else{
                    rejects.rejects[numRejects++] = fileLineNumber;
                    break;
                }
            }
            count++;
        }
        if (rejects.rejects[numRejects - 1] == fileLineNumber) {
            continue;
        }
        data.students[numData].grade = grades;
        data.students[numData].studentID = iD;
        numData++;
    }

    rejects.numRejects = numRejects;
    data.numStudents = numData;
    return numRejects;
}


int computeStatistics(Dataset &data, Statistics &stats) {
    //if no students
    if (data.numStudents <= 1) {
        return -1;
    }

    float sum = 0;
    float min = data.students[0].grade;
    float max = data.students[0].grade;

    //initialize histogram to 0
    for (int x = 0; x < 10; x++) {
        stats.histogram[x] = 0;
    }

    //add data
    for (int x = 0; x < data.numStudents; x++) {
        if (data.students[x].grade < min) {
            min = data.students[x].grade;
        } else if (data.students[x].grade > max) {
            max = data.students[x].grade;
        }

        sum = sum + data.students[x].grade;

        int size = data.students[x].grade / 10;

        //100 divided by 10 = 10, but bucket only goes up to 9
        if (data.students[x].grade == 100)
            size = 9;
        stats.histogram[size] = stats.histogram[size] + 1;
    }

    float average = sum / data.numStudents;

    float summation = 0;

    for (int x = 0; x < data.numStudents; x++) {
        summation = summation + pow((data.students[x].grade - average), 2);
    }

    float pop = pow(summation / data.numStudents, 0.5);

    float smpl = pow(summation / (data.numStudents - 1), 0.5);

    for (int x = 0; x < data.numStudents; x++) {
        for (int j = 0; j < data.numStudents - x - 1; j++) {
            if (data.students[j].grade > data.students[j + 1].grade) {
                Student sorted = data.students[j];
                data.students[j] = data.students[j + 1];
                data.students[j + 1] = sorted;
            }
        }
    }

    stats.minimum = min;
    stats.maximum = max;
    stats.average = average;
    stats.popStdDev = pop;
    stats.smplStdDev = smpl;
    stats.mode.numModes = 3; //not calculated yet
    return 0;
}

int writeCSV(const char filename[], const Statistics &stats) {

    ofstream finalFileWriting;
    char fileNameCSV[100];

    int x = 0;

    while (filename[x] != '\0' && filename[x] != '.') {
        fileNameCSV[x] = filename[x];
        x++;
    }

    fileNameCSV[x++] = '.';
    fileNameCSV[x++] = 's';
    fileNameCSV[x++] = 't';
    fileNameCSV[x++] = 'a';
    fileNameCSV[x++] = 't';
    fileNameCSV[x++] = '\0';

    finalFileWriting.open(fileNameCSV);

    if (!finalFileWriting.is_open()) {
        return -1;
    }

    finalFileWriting << "Minimum: " << stats.minimum << endl;
    finalFileWriting << "Average: " << stats.average << endl;
    finalFileWriting << "Maximum: " << stats.maximum << endl;
    finalFileWriting << "Population Standard Deviation: " << stats.popStdDev << endl;
    finalFileWriting << "Sample Standard Deviation: " << stats.smplStdDev << endl;
    finalFileWriting << "Modes: ";

    for (int x = 0; x < stats.mode.numModes; x++) {
        if (x == stats.mode.numModes - 1) {
            finalFileWriting << stats.mode.modes[x] << endl;
        } else {
            finalFileWriting << stats.mode.modes[x] << ", ";
        }
    }

    finalFileWriting << "Histogram:" << endl;
    finalFileWriting << "[0-9]: " << stats.histogram[0] << endl;
    finalFileWriting << "[10-19]: " << stats.histogram[1] << endl;
    finalFileWriting << "[20-29]: " << stats.histogram[2] << endl;
    finalFileWriting << "[30-39]: " << stats.histogram[3] << endl;
    finalFileWriting << "[40-49]: " << stats.histogram[4] << endl;
    finalFileWriting << "[50-59]: " << stats.histogram[5] << endl;
    finalFileWriting << "[60-69]: " << stats.histogram[6] << endl;
    finalFileWriting << "[70-79]: " << stats.histogram[7] << endl;
    finalFileWriting << "[80-89]: " << stats.histogram[8] << endl;
    finalFileWriting << "[90-100]: " << stats.histogram[9] << endl;

    return 0;
}
//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
//

#ifndef MARMOSET_TESTING

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself

int main(const int argc, const char *const argv[]) {

    // Some test driver code here ....
    int minAcceptableID = 0;
    int maxAcceptableID = 2000000;

    Dataset data = {0};
    Rejects rejects = {0};
    Statistics stats = {0};

    std::cout << std::endl << "Implement some more appropriate tests in main()" << std::endl << std::endl;

    if (readCSV(argv[1], minAcceptableID, maxAcceptableID, data, rejects) < 0) {
        std::cout << ".csv file could not be read" << std::endl;
    }

    if (computeStatistics(data, stats) < 0) {
        std::cout << "Stats could not be computed" << std::endl;
    }

    if (writeCSV(argv[1], stats) < 0) {
        std::cout << ".stat file could not be written" << std::endl;
    }

    std::cout << "Average: " << stats.average << std::endl;
    std::cout << "Minimum: " << stats.minimum << std::endl;
    std::cout << "Maximum: " << stats.maximum << std::endl;
    std::cout << "Population standard deviation: " << stats.popStdDev << std::endl;
    std::cout << "Sample standard deviation: " << stats.smplStdDev << std::endl;


    for (unsigned char i = 0; i < stats.mode.numModes; i++) {
        std::cout << "Mode: " << stats.mode.modes[i] << std::endl;
    }

    for (unsigned char i = 0; i < 10; i++) {
        std::cout << "Histogram bin [" << (i * 10) << ", " << ((((i + 1) * 10) - 1) + i / 9) << "]: "
                  << stats.histogram[i] << std::endl;
    }


    return 0;
}

#endif
