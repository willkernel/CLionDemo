#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int main() {
    short s = 10;
    int i = -10000;
    long l = 100000;
    float f = 230.45;
    double d = 200.43;

    cout << sin(d) << endl;
    cout << abs(i) << endl;
    cout << log(s) << endl;
    cout << pow(s, 2) << endl;
    cout << hypot(3, 4) << endl;
    cout << floor(d) << endl;
    cout << sqrt(f) << endl;

    //生成随机数,设置种子
    srand((unsigned) time(NULL));
    //生成10个随机数
    int r;
    for (int j = 0; j < 10; j++) {
        r = rand();
        cout << "random " << r << endl;
    }
    return 0;
}