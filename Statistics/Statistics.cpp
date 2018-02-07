#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

int main(const int argc, const char *const argv[]) {

    if (argc <=1) {
        cerr << "Error: Insufficient amount of command-line arguments" << endl;
        return 0;
    }

    int x = 1;
    float sum = 0;
    float min = atof(argv[1]);
    float max = atof(argv[1]);

    if (argc >= 2) {
        while (x != argc) {
            sum = sum + atof(argv[x]);

            if (atof(argv[x]) < min) {
                min = atof(argv[x]);

            }

            if (atof(argv[x]) > max) {
                max = atof(argv[x]);
            }
            x++;
        }
        cout << "Number of floating-point numbers: " << (argc - 1) << endl;
        cout << "Minimum floating-point number: " << min << endl;
        cout << "Average floating-point number: " << (sum / (argc - 1)) << endl;
        cout << "Maximum floating-point number: " << max << endl;
    }

    return 0;
}