#include <iostream>
#include <limits.h>
#include <float.h>

using namespace std;

int main(const int argc, const char* const argv[]) {
    int x;
    unsigned int y;

    x = atoi(argv[1]); //Convert argument 1 to int
    y = x;

    //output the values of x and y to cout
    cout << "The value of x is " << x << endl;
    cout << "The value of y is " << y << endl;

    // Output the most significant bit of x to cout
    cout << "The most significant bit of x is " << ((x >> 8 * sizeof(int)-1) & 1) << endl;

    //Output the most significant bit of y to cout
    cout << "The most significant bit of y is " << ((y >> 8 * sizeof(unsigned int)-1) & 1) << endl;

    //output variable information
    cout << "Type: \"signed char\"; Size: " << sizeof(signed char) << "; Minimum value: " << SCHAR_MIN << "; Maximum value: " << SCHAR_MAX << endl;
    cout << "Type: \"short int\"; Size: " << sizeof(signed short int) << "; Minimum value: " << SHRT_MIN << "; Maximum value: " << SHRT_MAX << endl;
    cout << "Type: \"int\"; Size: " << sizeof(signed int) << "; Minimum value: " << INT_MIN << "; Maximum value: " << INT_MAX << endl;
    cout << "Type: \"long int\"; Size: " << sizeof(signed long int) << "; Minimum value: " << LONG_MIN << "; Maximum value: " << LONG_MAX << endl;
    cout << "Type: \"long long int\"; Size: " << sizeof(signed long long int) << "; Minimum value: " << LONG_LONG_MIN << "; Maximum value: " << LONG_LONG_MAX << endl;
    cout << "Type: \"unsigned char\"; Size: " << sizeof(unsigned char) << "; Minimum value: " << CHAR_MIN << "; Maximum value: " << UCHAR_MAX << endl;
    cout << "Type: \"unsigned int\"; Size: " << sizeof(unsigned int) << "; Minimum value: " << INT_MIN << "; Maximum value: " << UINT_MAX << endl;
    cout << "Type: \"unsigned short int\"; Size: " << sizeof(unsigned short int) << "; Minimum value: " << SHRT_MIN << "; Maximum value: " << USHRT_MAX << endl;
    cout << "Type: \"unsigned long int\"; Size: " << sizeof(unsigned long int) << "; Minimum value: " << LONG_MIN << "; Maximum value: " << ULONG_MAX << endl;
    cout << "Type: \"unsigned long long int\"; Size: " << sizeof(unsigned long long int) << "; Minimum value: " << LONG_LONG_MIN << "; Maximum value: " << ULLONG_MAX << endl;
    cout << "Type: \"float\"; Size: " << sizeof(float) << "; Minimum value: " << FLT_MIN << "; Maximum value: " << FLT_MAX << endl;
    cout << "Type: \"double\"; Size: " << sizeof(double) << "; Minimum value: " << DBL_MIN << "; Maximum value: " << DBL_MAX << endl;
    cout << "Type: \"long double\"; Size: " << sizeof(long double) << "; Minimum value: " << -DBL_MIN << "; Maximum value: " << -DBL_MAX << endl;

    return 0;
}