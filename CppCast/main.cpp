#include <iostream>
//stl：standard template library 标准模板库，相当于Java中的util工具集
//注意这里使用的是C++的string文件，而不是string.h
#include <string>
//容器
#include <vector>

using namespace std;
//C++类型转换分类：
//static_cast 普遍情况
//const_cast 去常量
//dynamic_cast 子类类型、父类类型互转
//reinterpret_cast 函数指针转型，不具备移植性（不常用）
//作用：
//提高代码的可读性
//降低存在的风险

void *fun1(int type) {
    switch (type) {
        case 1: {
            int i = 9;
            return &i;
        }
        case 2: {
            int a = 'x';
            return &a;
        }

        default:
            return NULL;
    }
}


void fun2(const int &i) {
    //去除常量
    //C的写法，可读性差
    int *p_i = (int *) &i;
    *p_i = 20;

    //c++,可读性好
    int *p_c = const_cast<int *>(&i);
    *p_c = 30;
}

class Person {
public:
    virtual void print() {
        cout << "Person" << endl;
    }
};

class Man : public Person {
public:
    void print() {
        cout << "Man" << endl;
    }

    void chasing() {
        cout << "girl" << endl;
    }
};

class Woman : public Person {
public:
    void print() {
        cout << "Woman" << endl;
    }

    void carebaby() {
        cout << "baby" << endl;
    }
};

void fun3(Person &p) {

    //为了调用子类的特有的函数，需要转为实际的类型

    //C的写法，这时候并不知道转型是否失败
    //Woman* w = (Woman*)&p;
    //w->carebaby();

    Woman *w = dynamic_cast<Woman *>(&p);
    if (w != NULL) {
        w->carebaby();
    }
}

void func1() {
    cout << "func1" << endl;
}

char *func2() {
    cout << "func2" << endl;
    return "abc";
}

//定义函数指针类型
typedef void(*f_p)();

int main() {
//    需要把void* 转换为 int* 或者 char*
//    c 的写法
    int *p_i = (int *) fun1(1);
//   c++的写法，意图更明确
//   static_cast 广泛用于类型转换的关键字
    char *p_c = static_cast<char *>(fun1(2));

//    函数指针数组
    f_p f_array[6];

//    赋值
    f_array[0] = func1;

    //c 方式
    f_array[1] = (f_p) (func2);
    //C++方式
    f_array[2] = reinterpret_cast<f_p>(func2);

    f_array[1]();

    //VS的编译器自带STL，如果使用Eclipse NDK，那么就需要配置
    string s1 = "s1";
    string s2 = "s2";


    cout << s1 << endl;


    //C++字符串使用与Java的类似，并且提供了一系列方法
    string s3 = s1 + s2;
    cout << s3.at(2) << endl;


    //转化为c的字符串
    char *c_str = const_cast<char *>(s3.c_str());
    cout << c_str << endl;

    //c++容器，MAP，Vector等等
    //动态数组
    //不需要使用动态内存分配，就可以使用动态数组
    vector<int> v;
    v.push_back(12);
    v.push_back(10);
    v.push_back(5);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }

    return 0;
}