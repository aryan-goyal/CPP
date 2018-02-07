//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <fstream>

using namespace std;

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING

#include <iostream>

#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//

int histogram(const char filename[], int histogram[10],
              const int minAcceptableID, const int maxAcceptableID,
              int *&rejects);

bool sort(int dataset[], const int size);

bool selection(int dataset[], const int size);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  
// Return -1 if you cannot compute the histogram for any
// reason;
// Return 0 if the histogram is correct and there are no
// rejections;
// Return the number of rejects if there are rejected
// records from the file
//

bool sort(int dataset[], const int size) {
    return selection(dataset, size);
}

bool selection(int dataset[], const int size) {
    //reference from obtalk
    //https://obtalk.wordpress.com/2013/02/27/c-sort-array-with-selection-sort-using-recursion/
    //sorting in ascending order

    int maxIndex = 0;
    int holder = 0;
    int index = 0;

    //calculating index
    for (index = maxIndex; index < size; index++) {
        if (dataset[index] > dataset[maxIndex]) {
            maxIndex = index;
        }
    }

    //performing swaps
    holder = dataset[size - 1];
    dataset[size - 1] = dataset[maxIndex];
    dataset[maxIndex] = holder;

    //recursion
    if (size > 1) {
        int sizeNew = size - 1;
        selection(dataset, sizeNew);
    } else {
        return true;
    }
}

int histogram(const char filename[], int histogram[10],
              const int minAcceptableID, const int maxAcceptableID,
              int *&rejects) {
    //if there is nothing in the histogram return -1
    if (histogram == NULL) {
        return -1;
    }
    //if retarded information is passed in return 0
    if (maxAcceptableID < minAcceptableID) {
        return -1;
    }

    // declare the file object
    ifstream infile;

    // open the file
    infile.open(filename);

    // Unable to open file
    if (!infile.is_open()) {
        return -1;
    }

    //declare variables
    int maxLineLength = 100;
    char dataSet[maxLineLength];
    int grades[maxLineLength];
    int iD[maxLineLength];
    int numRejects = 0;

    //initialize arrays
    for (int x = 0; x < 10; x++) {
        histogram[x] = 0;
    }
    for (int x = 0; x < maxLineLength; x++) {
        iD[x] = 0;
        grades[x] = 0;
    }

    bool done = false;
    int fileLineNumber = 0;

    while (!done) { // Read from file

        if (!infile.getline(dataSet, maxLineLength)) { // Get next line
            if (infile.eof()) { // End of file
                done = true;
            } else { // Some error reading file
                return -1;
            }
        }

        bool checkOne = false;
        bool checkTwo = false;

        int x = 0;

        //parse(line)
        while (!dataSet[x] == 0) {
            if (dataSet[x] == 9 || dataSet[x] == 32) {
                //check spaces, do nothing
            } //comma
            else if (dataSet[x] == 44) {
                checkOne = true;
            } //https://piazza.com/class/j1zccf00a1z1qs?cid=310 negative number check
            else if (dataSet[x] == '-'){
                checkTwo = true;
            }
                //if the number is between 0 and 9
            else if (dataSet[x] >= 48 && dataSet[x] <= 57) {
                if (checkOne) {
                    grades[fileLineNumber] = grades[fileLineNumber] * 10 + dataSet[x] - 48;
                }
                    //numbers to ID
                else {
                    iD[fileLineNumber] = iD[fileLineNumber] * 10 + dataSet[x] - 48;
                }
            } else {
                return -1;
            }
            x++;
        }
        if(checkTwo){
            grades[fileLineNumber] = grades[fileLineNumber] * -1;
        }
        fileLineNumber++;
    }

    //calculate the rejections
    rejects = new int[fileLineNumber];

    //initialize the rejects to zero
    for (int x = 0; x < fileLineNumber; x++) {
        rejects[x] = 0;
    }

    int x = 0;
    while(!grades[x] == 0) {
        if (0 <= grades[x] && grades[x] < 10) {
            histogram[0]++;
        } else if (10 <= grades[x] && grades[x] < 20) {
            histogram[1]++;
        } else if (20 <= grades[x] && grades[x] < 30) {
            histogram[2]++;
        } else if (30 <= grades[x] && grades[x] < 40) {
            histogram[3]++;
        } else if (40 <= grades[x] && grades[x] < 50) {
            histogram[4]++;
        } else if (50 <= grades[x] && grades[x] < 60) {
            histogram[5]++;
        } else if (60 <= grades[x] && grades[x] < 70) {
            histogram[6]++;
        } else if (70 <= grades[x] && grades[x] < 80) {
            histogram[7]++;
        } else if (80 <= grades[x] && grades[x] < 90) {
            histogram[8]++;
        } else if (90 <= grades[x] && grades[x] <= 100) {
            histogram[9]++;
        } else {
            rejects[numRejects] = x + 1;
            numRejects++;
        }
        x++;
    }

    x = 0;
    while (!iD[x] == 0) {
        if (iD[x] < minAcceptableID || maxAcceptableID < iD[x]) {

            rejects[numRejects] = x + 1;
            numRejects++;

            if (0 <= grades[x] && grades[x] < 10) {
                histogram[0]--;
            } else if (10 <= grades[x] && grades[x] < 20) {
                histogram[1]--;
            } else if (20 <= grades[x] && grades[x] < 30) {
                histogram[2]--;
            } else if (30 <= grades[x] && grades[x] < 40) {
                histogram[3]--;
            } else if (40 <= grades[x] && grades[x] < 50) {
                histogram[4]--;
            } else if (50 <= grades[x] && grades[x] < 60) {
                histogram[5]--;
            } else if (60 <= grades[x] && grades[x] < 70) {
                histogram[6]--;
            } else if (70 <= grades[x] && grades[x] < 80) {
                histogram[7]--;
            } else if (80 <= grades[x] && grades[x] < 90) {
                histogram[8]--;
            } else if (90 <= grades[x] && grades[x] <= 100) {
                histogram[9]--;
            }
        }
        x++;
    }

    sort(rejects, numRejects);
    return numRejects;
}



//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
// This is required so that when you submit your code,
// this test driver will be ignored by Marmoset
//

#ifndef MARMOSET_TESTING

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself

int main(const int argc, const char *const argv[]) {

    // Some test driver code here ....
    if (argc < 2) {

    }
    const int numBuckets = 10;
    const int bucketRange = 100 / numBuckets;
    int buckets[numBuckets];
    int *rejectedRecords;
    int retCode = histogram(argv[1], buckets, 22200000, 22299999, rejectedRecords);
    if (retCode < 0) {
        cout << "Unable to compute histogram." << endl;
    } else {
        for (int i = 0; i < numBuckets; ++i)
            if (i != numBuckets - 1)
                cout << "Number [" << i * bucketRange << "," << (((i + 1) * bucketRange) - 1) << "]: " << buckets[i]
                     << endl;
            else
                cout << "Number [" << i * bucketRange << "," << (((i + 1) * bucketRange)) << "]: " << buckets[i]
                     << endl;
        if (retCode > 0) {
            cout << "Number of rejected records: " << retCode << endl;
            cout << "Rejected records are:";
            for (int i = 0; i < retCode; ++i)
                cout << " " << rejectedRecords[i];
            cout << endl;
            delete[] rejectedRecords;
        }
    }

    return 0;
}

#endif
