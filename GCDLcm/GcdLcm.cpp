#include <iostream>
#include <stdlib.h>

using namespace std;

//gcd function
int gcd(int c, int d) {
    if (d != 0) {
        return gcd(d, c % d);
    } else {
        return c;
    }
}

//main
int main(const int argc, const char *argv[]) {
    if (argc < 3) {
        cerr << "Error: Unable to compute GCD and/or LCM because number of arguments are less than 3" << endl;
        return 1;
    }
    if (argc > 3) {
        cerr << "Warning: Number of arguments greater than 3" << endl;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    int GCD = 0;
    int LCM = 0;

    if (a < 1 || b < 1) {
        cerr << "Error: Unable to compute GCD and/or LCM because arguments not greater than or equal to 1" << endl;
        return 1;
    }

    //calculate GCD
    GCD = gcd(a, b);

    //calculate LCM using the simple formula
    LCM = (a / GCD) * b;

    //printout
    cout << "GCD(" << a << ", " << b << ") = " << GCD << endl;
    cout << "LCM(" << a << ", " << b << ") = " << LCM << endl;

    return 0;
}


