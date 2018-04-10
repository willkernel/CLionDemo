#include <iostream>

using namespace std;

//使用指针交换值
void swap1(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//使用引用交换值
void swap2(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

struct Teacher {
    char *name;
};

void set1(Teacher **t) {
    (*t)->name = const_cast<char *>("wu");
}

//指针的引用，可以代替二级指针
void set2(Teacher *&t) {
    t->name = const_cast<char *>("lu");
//    t->name = "lu";
}

//常引用
void set(const int &a) {
//引用必须有值，不为空，指针就不一定
//const的意思是在函数内部不能修改值
//a = 8;
}

//引用的主要作用：作为函数的参数或者返回值，代替指针，使得程序可读性加强
//单纯给变量取别名没有任何意义，作为函数参数传递，能保证参数传递过程中不产生副本
//引用可以直接操作变量，指针要通过取值(*p)，间接操作变量，指针的可读性差
//引用的大小（sizeof）跟类型一样大
int main() {
    int a = 10;
    int &b = a;
    int *c = &a;
//    变量a和引用b实质是访问同一个内存地址 跟指针的概念差不多
    b = 20;
    cout << b << endl;
    cout << a << endl;
    cout << *c << endl;

    int d = 12, e = 21;
    swap1(&d, &e);
    swap2(d, e);
    cout << d << endl;
    cout << e << endl;

    //找到最大的数，此时为e，然后e赋值为30
    //C++的三目运算符可以进行赋值
    d > e ? d : e = 30;
    cout << e << endl;

    Teacher t;
    Teacher *p_t = &t;
    set1(&p_t);
    cout << t.name << endl;

    set2(p_t);
    cout << t.name << endl;

    //指针常量，指针的常量，不改变地址的指针，但是可以修改它指向的内容
    int *const p1 = &a;
    *p1 = 30;
    cout << &p1 << *p1 << endl;
    //常量指针，指向常量的指针，指向的内容不能修改，可以改变地址
    const int *p2 = &a;
    p2 = &b;
//    *p2=40; read only
    cout << &p2 << *p2 << endl;


    int x = 0;
    //引用必须有值，不能为空
//    int &y=NULL;


    //常引用，不能再进行赋值，相当于final
    const int &z = x;
//    z=20; read only
    const int &q = 1;//字面量
}
