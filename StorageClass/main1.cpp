#include <iostream>

using namespace std;
extern int sum;

void write_extern() {
    cout << "sum is " << sum << endl;
}