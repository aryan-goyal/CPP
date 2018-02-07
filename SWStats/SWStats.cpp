#include <iostream>
#include <stdlib.h>

using namespace std;

//main
int main(const int argc, const char *argv[]) {
    if (argc < 3) {
        cerr << "Error: Unable to compute statistics over data set because number of arguments are less than two"
             << endl;
        return -1;
    } else if (atoi(argv[1]) <= 0) {
        cerr << "Error: Unable to compute statistics over data set because the window size cannot be negative or zero "
             << endl;
        return -1;
    }


    int windowSize = atoi(argv[1]);

    //store into float array
    int size = argc - 2;
    float inputArray[size];
    for (int x = 0; x < (size); x++) {
        inputArray[x] = atof(argv[x + 2]);
    }

    //another error
    if (windowSize == 1 || windowSize >= size) {
        cerr << "Warning: Window size is equal to 1 or is greater than the number of arguments." << endl;
    }

    //display printout
    cout << "Window Size: " << windowSize << endl;
    cout << "Sample  Value  SWMinimum  SWAverage  SWMaximum" << endl;

    float holder[windowSize];
    int count = 0;

    for (int x = 0; x < size; x++) {
        for (int k = x; k >= (x - windowSize - 1); k--) {
            if (k < 0) {
                holder[count] = inputArray[0];
                count++;
            } else {
                holder[count] = inputArray[k];
                count++;
            }
        }

        float sum = 0;
        float min = holder[0];
        float max = holder[0];
        float average = 0;


        //calculate min, max, sum
        for (int y = 0; y < windowSize; y++) {
            sum = sum + holder[y];

            if (holder[y] < min) {
                min = holder[y];
            }

            if (holder[y] > max) {
                max = holder[y];
            }
        }
        average = sum / windowSize;
        cout << x + 1 << "  " << inputArray[x] << "  " << min << "  " << average << "  " << max << endl;
        average = 0;
        sum = 0;
        count = 0;
        min = 0;
        max = 0;
    }
    return 0;
}