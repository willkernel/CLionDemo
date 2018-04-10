#include <iostream>
#include <stdarg.h>
#include "teacher.h"

//1. C++可以与C代码进行混编，C++里面可以写C，但是反过来不可以
//2. C++是面向对象编程语言、C是面向过程的编程
//3. C++对C的一个增强。C++有class、引用的概念，堆内存的分配释放除了C语言的malloc、free，
// 还有new、delete关键字

using namespace std;

//自定义命名空间
namespace name1 {
    int a = 1;
    namespace name1_1 {
        int a = 3;
    }
}

namespace name2 {
    int a = 2;
}


//C++中的结构体、结构体与命名空间
//C++是C的增强，C++中的结构体可以有访问修饰符，修饰符是多个变量或者函数共用的一个的
//C++中的结构体与Java中的类非常类似，在C语音中只能用函数指针当作成员函数，在C++中直接就是函数
//C++中的结构体有一个this指针，指向自身
//C++中通过using使用了命名空间之后，在使用结构体的时候，struct关键字可以省略
namespace name3 {
    //结构体
    struct Teacher1 {
    private:
        char *name;
    public:
        int age;

        void say() {
            cout << "my age is " << this->age << endl;
        }
    };
};


using name3::Teacher1;

//与Java类似，有一个tihs指针指向自身
//类的定义末尾需要有分号
//这里的main函数中的c是存在于栈内存的，可以通过new关键字在堆内存中创建对象的实体，但是我们需要
class Aclass {
public:
    int getA() {
        return a;
    }

    void setA(int a) {
        this->a = a;
    }

private:
    int a;
};

//C++中的函数
//函数参数可以有默认值，与PHP一样
void test1(int a = 10) {

}

//一旦某个参数值定了默认值，那么后面的所有参数都需要有
void test2(int a, int b = 13, int c = 16) {

}

//函数的可变参数
//需要使用头文件stdarg.h
//通过va_start开始读取可变参数，其中形参i是最后一个固定参数
//通过va_arg读取，需要指定类型
//通过va_end结束读取
void test3(int i, ...) {
    va_list args_p;
    va_start(args_p, i);
//    开始读取
//    也可以循环读取，但是需要有条件（比如可变参数都大于0），且可变参数的类型都一样
    int a = va_arg(args_p, int);
    char b = va_arg(args_p, int);
    int c = va_arg(args_p, int);
    va_end(args_p);

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}

void test4(int i, ...) {
    va_list args_p;
    va_start(args_p, i);

    while (true) {
        int a = va_arg(args_p, int);

        if (a <= 0) {
            break;
        }
        cout << a << endl;
    }
    va_end(args_p);
}


Teacher::Teacher() {}

Teacher::~Teacher() {}

//c语言模板函数，相当于Java中的泛型
void myswap(int &a, int &b) {
    int tmp = 0;
    tmp = a;
    a = b;
    b = tmp;
}

void myswap(char &a, char &b) {
    int tmp = 0;
    tmp = a;
    a = b;
    b = tmp;
}

//这两个函数业务逻辑一样，数据类型不一样，因此这个时候就可以使用函数模板来减少代码量
template<typename T>
void myswap(T &a, T &b) {
    T tmp = 0;
    tmp = a;
    a = b;
    b = tmp;
}

//自定义模板类
template<class T>
class A1 {
public:
    A1(T a) {
        this->a = a;
    }

protected:
    T a;
};

//自定义普通类继承模板类
class B : public A1<int> {
public:
    B(int a) : A1<int>(a) {}
};

//自定义模板类继承普通类
template<class T>
class C : public A1<T> {
public:
    C(T a) : A1<T>(a) {}
//    C(int a) : A1<T>(a) {}
};

//通过using namespace来使用std这个命名空间。也可以通过std::的方式来时用命名空间，::叫做访问修饰符
//cout是头文件iostream的输出函数，C++中头文件的包含不需要写.h后缀
//其中<<是运算符重载  endl是换行的意思
int main() {
    cout << "I luv u" << endl;
    std::cout << "I " << endl;

//    错误
//    name1::count << a << endl;
//    name1::name1_1::count << a << endl;
//    name2::count << a << endl;

//    正确的
    cout << name1::a << endl;
    cout << name1::name1_1::a << endl;
    cout << name2::a << endl;

    Teacher1 t{};
    t.age = 5;
    t.say();

    Aclass c{};//栈内存
    c.setA(6);
    cout << c.getA() << endl;

//    布尔类型  bool的值有true、false，实质是1和0，占一个字节大小
//    在C/C++中，条件表达式中，大于0就为真，小于等于0就为假。而Java中只能用true和false
    bool b = true;
    if (b) {
        cout << b << endl;
        cout << sizeof(bool) << endl;
    }

    test3(20, 30, 'a', 56);
    test4(1, 10, 20, 40, -1);//-1相当于结束符

    int a1 = 29, b1 = 43;
    myswap<int>(a1, b1);
    cout << a1 << "," << b1 << endl;
    char x = 'v', y = 'w';
    myswap(x, y);
    cout << x << "," << y << endl;

//    模板类的实例化
    A1<int>(10);
    B(10);
    C<int>(20);
}
