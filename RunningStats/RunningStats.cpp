#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(const int argc, const char *argv[]) {

    if (argc <2){
        cerr << "Error: Insufficient arguments; number of arguments are less than 2" << endl;
        return 1;
    }

    int x = 1;

    float sum = 0;
    float min = atof(argv[1]);
    float max = 0;

    if(argc >=2) {
        cout << "Sample Value Minimum Average Maximum" << endl;
        while (x != argc) {
            sum = sum + atof(argv[x]);

            if (atof(argv[x]) < min) {
                min = atof(argv[x]);
            }

            if (atof(argv[x]) >= max) {
                max = atof(argv[x]);
            }
            cout << x << "      " << atof(argv[x]) << "     " << min << "       " << (sum / x) << "       " << max
                 << endl;
            x++;
        }
        return 0;
    }
}