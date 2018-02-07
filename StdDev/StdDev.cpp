#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

//main
int main(const int argc, const char *argv[]) {
    if (argc < 2) {
        cerr << "Error: Unable to compute statistics over data set because there are no arguments." << endl;
        return -1;
    }

    //store into float array
    float inputArray[argc - 1];
    for (int x = 0; x < (argc - 1); x++) {
        inputArray[x] = atof(argv[x + 1]);
    }

    int x = 0;

    float sum;
    float min = inputArray[x];
    float max = 0;

    //calculate min, max, sum
    while (x != (argc - 1)) {
        sum = sum + inputArray[x];

        if (inputArray[x] < min) {
            min = inputArray[x];
        }

        if (inputArray[x] >= max) {
            max = inputArray[x];
        }
        x++;
    }

    //perform summation
    float summation = 0;
    float mean = sum / (argc - 1);
    for (int x = 0; x < (argc - 1); x++) {
        summation = summation + pow((inputArray[x] - mean), 2);
    }

    cout << "Number of floating-point numbers: " << (argc - 1) << endl;
    cout << "Minimum floating-point number: " << min << endl;
    cout << "Average floating-point number: " << sum / (argc - 1) << endl;
    cout << "Maximum floating-point number: " << max << endl;

    if ((argc - 1) < 1) {
        cerr << "Warning: There are not enough arguments to compute population standard deviation." << endl;
        cout << "Population standard deviation: infinity";
    } else {
        cout << "Population standard deviation: " << pow(summation / (argc - 1), 0.5) << endl;
    }

    if ((argc - 2) < 1) {
        cerr << "Warning: There are not enough arguments to compute sample standard deviation." << endl;
        cout << "Sample standard deviation: infinity" << endl;
    } else {
        cout << "Sample standard deviation: " << pow(summation / (argc - 2), 0.5) << endl;
    }

    return 0;
}