//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING

#include <iostream>

using namespace std;

int SWStats(const float dataset[], const int size,
            const int currentSample, const int windowSize,
            float &min, float &avg, float &max,
            float &smplSD, float &mdn);

int SWMinimum(const float dataset[], const int size,
              const int currentSample, const int windowSize,
              float &minimum);

int SWAverage(const float dataset[], const int size,
              const int currentSample, const int windowSize,
              float &average);

int SWMaximum(const float dataset[], const int size,
              const int currentSample, const int windowSize,
              float &maximum);

int SWSmplStdDev(const float dataset[], const int size,
                 const int currentSample, const int windowSize,
                 float &smplStdDev);

int SWMedian(const float dataset[], const int size,
             const int currentSample, const int windowSize,
             float &median);

#endif

//////////////////////////////////////////////////////////////
//
// Your code here ...
//

#include <cmath>

int SWStats(const float dataset[], const int size,
            const int currentSample, const int windowSize,
            float &min, float &avg, float &max,
            float &smplSD, float &mdn) {

    SWMinimum(dataset, size, currentSample, windowSize, min);
    SWAverage(dataset, size, currentSample, windowSize, avg);
    SWMaximum(dataset, size, currentSample, windowSize, max);
    SWSmplStdDev(dataset, size, currentSample, windowSize, smplSD);
    SWMedian(dataset, size, currentSample, windowSize, mdn);

    if (size < 1) {
        return -1;
    }
    if (windowSize <= 0) {
        return -2;
    }
    if (size < windowSize) {
        return 1;
    }
    if (windowSize == 1) {
        return 2;
    }
    return 0;
}



int SWMinimum(const float dataset[], const int size,
              const int currentSample, const int windowSize,
              float &minimum) {
    float buff[windowSize];
    for (int x = 0; x < windowSize; x++) {
        if ((currentSample - x) < 0) {
            buff[x] = dataset[0];
        } else {
            buff[x] = dataset[currentSample - x];
        }
    }

    minimum = buff[0];
    for (int x = 0; x < windowSize; x++) {
        if (buff[x] < minimum) {
            minimum = buff[x];
        }
    }
    return 0;
}

int SWAverage(const float dataset[], const int size,
              const int currentSample, const int windowSize,
              float &average) {
    float buff[windowSize];
    float sum = 0;
    for (int x = 0; x < windowSize; x++) {
        if ((currentSample - x) < 0) {
            buff[x] = dataset[0];
            sum += buff[x];
        } else {
            buff[x] = dataset[currentSample - x];
            sum += buff[x];
        }
    }

    average = sum / windowSize;
    return 0;
}

int SWMaximum(const float dataset[], const int size,
              const int currentSample, const int windowSize,
              float &maximum) {
    float buff[windowSize];
    for (int x = 0; x < windowSize; x++) {
        if ((currentSample - x) < 0) {
            buff[x] = dataset[0];
        } else {
            buff[x] = dataset[currentSample - x];
        }
    }

    maximum = buff[0];
    for (int x = 0; x < windowSize; x++) {
        if (buff[x] > maximum) {
            maximum = buff[x];
        }
    }
    return 0;
}

int SWSmplStdDev(const float dataset[], const int size,
                 const int currentSample, const int windowSize,
                 float &smplStdDev) {
    float buff[windowSize];
    for (int x = 0; x < windowSize; x++) {
        if ((currentSample - x) < 0) {
            buff[x] = dataset[0];
        } else {
            buff[x] = dataset[currentSample - x];
        }
    }

    float mean;
    float total;
    SWAverage(dataset, size, currentSample, windowSize, mean);
    for (int x = 0; x < windowSize; x++) {
        total += pow((buff[x] - mean), 2);
    }

    smplStdDev = pow(total / (windowSize - 1), 0.5);
    return 0;
}

//github bubbleSort algorithm
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

int SWMedian(const float dataset[], const int size,
             const int currentSample, const int windowSize,
             float &median) {
    float buff[windowSize];
    for (int x = 0; x < windowSize; x++) {
        if ((currentSample - x) < 0) {
            buff[x] = dataset[0];
        } else {
            buff[x] = dataset[currentSample - x];
        }
    }

    bubbleSort(buff, windowSize);
    if (windowSize % 2) {
        median = buff[windowSize / 2];
    } else {
        median = (buff[(windowSize - 1) / 2] + buff[(windowSize + 1) / 2]) / 2;
    }
    return 0;
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
    int windowSize = 2;
    int currentSample = 0;
    float min;
    float avg;
    float max;
    float smplSD;
    float median;

    cout << "Sample \t Minimum \t Average \t Median \t Maximum \t Sample Standard Deviation" << endl;

    while (currentSample < size) {
        int retCode = SWStats(dataset, size, currentSample, windowSize, min, avg, max, smplSD, median);
        if (retCode >= 0) {
            cout << currentSample << "\t " << min << "\t " << avg << "\t " << max << "\t " << median << "\t " << smplSD
                 << endl;
            if (retCode > 0)
                cerr << "Warning: something weird happened, but we computed stats anyway ... YMMV" << endl;
        } else {
            cerr << "Error: unable to compute sliding-window statistics; exiting" << endl;
            return (-1);
        }
        ++currentSample;
    }
    return 0;
}

#endif