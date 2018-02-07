#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(const int argc, const char *const argv[]) {
    int P;
    int Q;

    P = atoi(argv[1]); // Convert argument 1 to int
    Q = atoi(argv[2]); // Convert argument 2 to int

    // Output the values of P and Q to cout
    cout << "P: " << P << endl;
    cout << "Q: " << Q << endl;

    // Output the result of (P AND Q) to cout
    cout << "P AND Q: " << (P && Q) << endl;

    // Output the result of (P OR Q) to cout
    cout << "P OR Q: " << (P || Q) << endl;

    // Output the NEGATION of P and the NEGATION of Q to cout
    cout << "NOT P: " << !P << endl;
    cout << "NOT Q: " << !Q << endl;

    return 0;
}