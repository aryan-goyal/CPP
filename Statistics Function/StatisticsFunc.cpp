//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <cmath>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING

#include <iostream>

using namespace std;

bool statistics(const float dataset[], const int size,
                float &min, float &avg, float &max,
                float &popSD, float &smplSD, float &mdn);

float minimum(const float dataset[], const int size);

float average(const float dataset[], const int size);

float maximum(const float dataset[], const int size);

float popStdDev(const float dataset[], const int size);

float smplStdDev(const float dataset[], const int size);

float median(const float dataset[], const int size);

#endif

//////////////////////////////////////////////////////////////
//
// Your code here ...
//

//piazza Julien Parkin answer
#ifndef NAN
#define NAN (0.0 / 0.0)
#endif


bool statistics(const float dataset[], const int size,
                float &min, float &avg, float &max,
                float &popSD, float &smplSD, float &mdn) {
    if (size < 2) {
        return false;
    }
    min = minimum(dataset, size);
    avg = average(dataset, size);
    max = maximum(dataset, size);
    popSD = popStdDev(dataset, size);
    smplSD = smplStdDev(dataset, size);
    mdn = median(dataset, size);
    return true;
}

float total;

float summation(const float dataset[], const int size) {
    int x = 0;
    float sum = 0;
    while (x != (size)) {
        sum += dataset[x];
        x++;
    }
    total = 0;
    total = sum;
    return sum;
}

float minimum(const float dataset[], const int size) {
    int x = 0;
    float min = dataset[0];
    while (x != (size)) {
        if (dataset[x] < min) {
            min = dataset[x];
        }
        x++;
    }
    return min;
}

float average(const float dataset[], const int size) {
    summation(dataset, size);
    float average = total / size;
    return average;
}

float maximum(const float dataset[], const int size) {
    int x = 0;
    float max = dataset[0];
    while (x != (size)) {
        if (dataset[x] > max) {
            max = dataset[x];
        }
        x++;
    }
    return max;
}

float popStdDev(const float dataset[], const int size) {
    if (size < 1) {
        return NAN;
    } else {
        float summation = 0;
        float mean = total / size;
        for (int x = 0; x < size; x++) {
            summation = summation + pow((dataset[x] - mean), 2);
        }
        float pop = pow(summation / size, 0.5);
        return pop;
    }
}

float smplStdDev(const float dataset[], const int size) {
    if (size - 1 < 1) {
        return NAN;
    } else {
        float summation = 0;
        float mean = total / size;
        for (int x = 0; x < size; x++) {
            summation = summation + pow((dataset[x] - mean), 2);
        }
        float smpl = pow(summation / (size - 1), 0.5);
        return smpl;
    }
}

void bubbleSort(float dataset[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (dataset[j] < dataset[i]) {
                float buff = dataset[i];
                dataset[i] = dataset[j];
                dataset[j] = buff;
            }
        }
    }
}

float median(const float dataset[], const int size) {
    float buff[size];
    for (int x = 0; x < size; x++) {
        buff[x] = dataset[x];
    }
    bubbleSort(buff, size);
    if (size % 2) {
        return buff[size/2];
    } else {
        return (buff[(size-1)/2] + buff[(size+1)/2])/2;
    }
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

int main(const int argc, const char *const argv[]) {
    int size = 5;
    float dataset[] = {1, 2, 3, 4, 5};
    float min;
    float avg;
    float max;
    float popStDev;
    float smplStDev;
    float median;

    if (statistics(dataset, size, min, avg, max, popStDev, smplStDev, median)) {
        cout << "Minimum: " << min << endl
             << "Average: " << avg << endl
             << "Median:  " << median << endl
             << "Maximum: " << max << endl
             << "Population Standard Deviation: " << popStDev << endl
             << "Sample Standard Deviation:     " << smplStDev << endl;
    } else
        cout << "Error: unable to compute statistics" << endl;

    return 0;
}

#endif