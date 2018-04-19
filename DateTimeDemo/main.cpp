#include <iostream>
#include <ctime>

using namespace std;

int main() {
    // 基于当前系统的当前日期/时间
    time_t now = time(nullptr);
    cout << "now " << now << endl;
    // 把 now 转换为字符串形式
    char *dt = ctime(&now);
    cout << "local date/time " << dt << endl;
    // 把 now 转换为 tm 结构
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
    cout << "UTC date/time " << dt << endl;

    tm *ltm = localtime(&now);
    cout << "Y: " << ltm->tm_year << endl;
    cout << "M: " << ltm->tm_mon << endl;
    cout << "D: " << ltm->tm_mday << endl;
    cout << "Time: " << ltm->tm_hour << ":";
    cout << " " << ltm->tm_min << ":";
    cout << " " << ltm->tm_sec << endl;

    char name[50];
    int age;
    cout << "your name age :";
    cin >> name >> age;
    cout << " name is " << name << ", age is " << age << endl;

    char str[] = "exec";

    cerr << "error " << str << endl;
    wcerr << "error " << str << endl;

    clog << "error " << str << endl;
    wclog << "error " << str << endl;
    return 0;
}

