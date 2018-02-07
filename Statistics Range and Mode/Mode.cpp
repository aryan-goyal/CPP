//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//


//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING

#include <iostream>

using namespace std;
#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//

int range(const int dataset[], const int size);

int mode(const int dataset[], const int size, int mode[]);

bool sort(int dataset[], const int size);

bool selection(int dataset[], const int size);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  Return -1 if there there are any problems with the dataset.
//

int range(const int dataset[], const int size) {
    if (size <= 1) {
        return -1;
    }

    sort(const_cast<int *>(dataset), size);

    int range = dataset[size - 1] - dataset[0];
    return range;
}

int modeHelper(int data[], int size, int mode[]) {
    int newDataSet[size];

    //set all values of the array to zero
    for (int x = 0; x < size; x++) {
        newDataSet[x] = 0;
    }

    //initialize integers
    int count = 0;
    int maximum = 0;
    int DNEMode = 0;
    int numberOfModes = 0;
    int currentNumber = 0;

    for (int w = 0; w < size; w++) {
        count = 0;
        currentNumber = data[w];

        //search for the number stored in currentNumber
        for (int x = w; x < size; x++) {
            if (currentNumber == data[x]) {
                count++; //currentNumber was found, increment
            }
        }

        newDataSet[w] = count;

        if (count >= 2) {
            DNEMode++; //a mode does exist so increment
        }
    }

    //Check if no mode exists, turn off the function
    if (DNEMode == 0) {
        return -1;
    }

    int newCount = 0;

    //find the highest number
    for (int x = 0; x < size; x++) {
        if (newDataSet[x] > maximum) {
            maximum = newDataSet[x];
        }
    }

    //Determine number of modes in the set
    for (int x = 0; x < size; x++) {
        if (newDataSet[x] == maximum) {
            numberOfModes++;
        }
    }

    //add the new modes
    for (int x = 0; x < size; x++) {
        if (newDataSet[x] == maximum) {
            mode[newCount] = data[x];
            newCount++;
        }
    }

    //sort using selection
    selection(mode, numberOfModes);

    return numberOfModes;
}

int mode(const int dataset[], const int size, int mode[]) {
    if (size < 1) {
        return -1;
    }

    //sort array, remove the constant
    sort(const_cast<int *>(dataset), size);

    int getModes = modeHelper(const_cast<int *>(dataset), size, mode);

    return getModes;
}

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

    // Some test driver code here ....
    int data[] = {1, 1, 2, 3, 4, 5};
    int size = 6;
    //change this to however many modes you expect to find
    int modeArray[100] = {0};
    int rng = range(data, size);
    int modes = mode(data, size, modeArray);
    cout << "range: " << rng << " number of Modes: " << modes << " Modes are this: ";
    for (int i = 0; i < modes; i++) {
        cout << modeArray[i];
        if (i < modes - 1) {
            cout << ", ";
        }
    }
    cout << endl;
    return 0;
}

#endif