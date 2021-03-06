#include <iostream>
#include <stdlib.h>

using namespace std;

float nthRoot(float x) {
    if (x < 0) {
        x *= -1;
    }
    return x;
}

//main
int main(const int argc, const char *argv[]) {
    if (argc < 4) {
        cerr << "Error: Unable to compute Nth root because number of arguments are less than three" << endl;
        return -1;
    } else if (argc > 4) {
        cerr << "Warning: Number of arguments greater than three; ignoring extraneous arguments" << endl;
    }

    float number = atof(argv[1]);
    int root = atoi(argv[2]);
    float precision = atof(argv[3]);

    if (root % 2 == 0 && number < 0) {
        cerr << "Error: Unable to compute Nth Root because number negative" << endl;
        return 1;
    } else if (root < 2) {
        cerr << "Error: Unable to compute Nth Root because because root less than two" << endl;
        return 1;
    } else if (precision <= 0) {
        cerr << "Error: Unable to compute Nth Root because precision less than zero" << endl;
        return 1;
    }

    float holder1 = 0;
    float holder2= 0;
    float ro = (float) root;
    float holdNew = number/ro;

    //calculate nthRoot and precision
    while (nthRoot(holder1 - holdNew) > precision) {

        holder1 = holdNew;
        holder2 = holdNew;

        for (int x = 0; x < ro - 2; x++) {
            holder2 *= holder1;
        }
        holdNew = (((ro - 1)/ro) * holder1) + (number/ (ro * holder2));
    }

    //printout
    cout << "Root(" << number << ", " << root << ") = " << holdNew << endl;
    cout << "(with precision " << precision << ")" << endl;

    return 0;
}       