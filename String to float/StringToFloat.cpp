//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
// You are allowed float.h
#include <cmath>
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

bool stringToFloat(const char input[], float &value);

//////////////////////////////////////////////////////////////
bool stringToFloat(const char input[], float &value) {
    float number = 0;

    int numOfDecimalPLaces = 1;

    int powNumber = 0;

    bool decimalTrue = false;
    bool eTrue = false;
    bool powPositive = false;
    bool powNegative = false;

    bool close = true;
    bool eClose = true;

    int x = 0;

    if (input[x - 1] == '.' || input[x - 1] == 'e' || input[x - 1] == 'E' || input[0] == 'E' || input[0] == 'e' ||
        input[x + 1] == '+' || input[x + 1] == '-') {
        return false;
    }

    //if + -, or number is up front,
    if (input[0] == '+' || input[0] == '-' || (input[0] >= 48 || input[0] <= 57) || input[0] == '.') {

        //increment based on first value
        if (input[0] == '+' || input[0] == '-') {
            x++;
        }

        for (x; input[x] != 0; x++) {
            if ((input[x] < 48 || input[x] > 57) && input[x] != 46 && input[x] != 101 && input[x] != 69 &&
                input[x] == '+' &&
                input[x] == '-') {
                return false;
            } else if ((input[x] >= 48 && input[x] <= 57) && !decimalTrue && !eTrue) {
                number = number * 10 + input[x] - 48;
            } else if (input[x] == 46) {
                decimalTrue = true;
                if (input[x + 1] == 'e' || input[x + 1] == 'E') {
                    return false;
                }
            } else if ((input[x] >= 48 && input[x] <= 57) && decimalTrue && !eTrue) {
                number = number + (input[x] - 48) / (pow(10, numOfDecimalPLaces));
                numOfDecimalPLaces++;
            } else if (eClose && (input[x] == 101 || input[x] == 69)) {
                eTrue = true;
                eClose = false;
            } else if (close && eTrue && (input[x] == '+' || (input[x] >= 48 && input[x] <= 57))) {
                x--;
                powPositive = true;
                close = false;
            } else if (close && eTrue && input[x] == '-') {
                x--;
                powNegative = true;
                close = false;
            } else if (powPositive && (input[x] >= 48 && input[x] <= 57)) {
                powNumber = powNumber * 10 + input[x] - 48;
            } else if (powNegative && (input[x] >= 48 && input[x] <= 57)) {
                powNumber = powNumber * 10 + input[x] - 48;
            }
        }

        if (powPositive) {
            number = number * pow(10, powNumber);
        } else if (powNegative) {
            number = number * (1 / pow(10, powNumber));
        }

        if (number == 0) {
            value = number;
            return true;
        }

        if (input[0] == '+' || (input[0] >= 48 && input[0] <= 57) || input[0] == '.') {
            value = number;
            if (value > 0) {
                return true;
            } else {
                return false;
            }
        } else if (input[0] == '-') {
            value = (number * (-1));
            if (value < 0) {
                return true;
            } else {
                return false;
            }
        }
    }
    return false;
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
    float argv1;

    if (argc < 2) {
        cerr << "Error: Usage: " << argv[0] << " <float>" << endl;
        return -1;
    }

    if (stringToFloat(argv[1], argv1))
        cout << "argv[1] is a float with value: " << argv1 << endl;
}

#endif