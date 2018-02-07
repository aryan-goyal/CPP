#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(int argc, char * argv[]) {
    cout << "Initial car velocity: " << argv[1] << " m/s" << endl;
    cout << "Distance to obstacle: " << argv[2] << " m" << endl;
    cout << "Minimum deceleration: " << (atof(argv[1]) * atof(argv[1]))/(2*atof(argv[2])) << " m/s/s" << endl;
    cout << "Maximum stopping time: " << 2*atof(argv[2])/atof(argv[1]) << " s" << endl;

    return 0;
}