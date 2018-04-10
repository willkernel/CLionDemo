#include <iostream>
#include <cstring>

using namespace std;
//类的定义是在头文件，实现在源文件中，这里为了方便，都写在源文件中


class Teacher {
public:
    Teacher() {
        cout << "no arg" << endl;
    }

public:
    Teacher(char *name, int age) {
        cout << "has args" << endl;
        this->name = name;
        this->age = age;
        cout << name << age << endl;
    }

private:
    char *name;
    int age;
};

class Student {
public:
//    现在有Student类，里面有Teacher的私有成员两个。Student构造的时候需要初始化Teacher，但是又不能直接访问Teacher类的私有属性
//    因此只能通过初始化列表的方式来调用
    Student(int id, char *t1_name, int t1_age, char *t2_name, int t2_age) : t1(t1_name, t1_age), t2(t2_name, t2_age) {
        //t1.name = t1_name;不可以这样赋值，因为Teacher的私有属性不可以访问
    }

private:
    int id;
    Teacher t1, t2;
};


//析构函数
//        析构函数：当对象要被系统释放时（例如函数栈退出的时候），析构函数被调用
//        作用：善后处理，例如释放动态分配的内存
class Teacher1 {
public:
    Teacher1() {
        cout << "no arg" << endl;
        name = (char *) malloc(sizeof(char) * 100);
        strcpy(name, "lu");
        age = 18;
    }

    ~Teacher1() {
        cout << "Teacher1 Destructor" << endl;
        free(name);
    }

private:
    char *name;
    int age;
};

void fun() {
    Teacher1 t1;
}


//拷贝构造函数
//        系统默认的拷贝构造函数就是拷贝值的，跟下面的写法一样
//拷贝构造函数被调用的场景有（实质上都是第一种的变种），有印象即可：
//一、声明时赋值（只有声明的时候才会调用）
//二、作为参数传入，实参给形参赋值（引用传值不会调用，因为指向的都是同一片内存，不存在拷贝问题）
//三、作为函数返回值返回，给变量初始化赋值

//浅拷贝
//        默认的拷贝构造函数实现是浅拷贝，即值拷贝

//值拷贝带来的问题：
//如果有动态内存分配的时候，如果单纯是值拷贝，析构的时候就会析构两次
//例如代码中的char* name，t1、t2都指向了同一个地址，那么析构的时候就会free两次，因为一个内存地址不能释放两次，因此会触发异常中断。
class Teacher2 {
public:
    Teacher2(char *name, int age) {
        cout << "2 args" << endl;
        this->name = name;
        this->age = age;
    }

    Teacher2(const Teacher2 &obj) {
        cout << "shallow copy" << endl;
        this->name = obj.name;//浅拷贝，是值拷贝
        this->age = obj.age;
    }

    ~Teacher2() {
        cout << "Teacher2 Destructor" << endl;
        free(name);
    }

private:
    char *name;
    int age;
};


Teacher2 fun2(Teacher2 &teacher2) {
    return teacher2;
}

void fun3() {
    Teacher2 t1 = Teacher2("fun3", 12);
    Teacher2 t2 = t1;
}


//深拷贝
//        重写覆盖默认的浅拷贝，自己写一个深拷贝：
//t2的name是新分配的内存，因此t1、t2指向的是两片不同的内存，因此析构的时候分别释放，互不干扰，解决了浅拷贝的问题

//浅拷贝，值拷贝：拷贝的是指针的地址
//深拷贝：拷贝的是指针指向的数据内容
class Teacher3 {
public:
    Teacher3() {
        cout << "no arg" << endl;
        this->name = (char *) malloc(sizeof(char) * 100);
        strcpy(name, "Teacher3");
        this->age = age;
    }

    //深拷贝
    Teacher3(const Teacher3 &obj) {
        cout << "deep copy" << endl;
        int len = strlen(obj.name);
        this->name = (char *) malloc(sizeof(char) * (len + 1));//+1 因为结束符，深拷贝分配内存
        strcpy(this->name, obj.name);
        this->age = obj.age;
    }

    ~Teacher3() {
        cout << "Teacher3 Destructor" << endl;
    }

private:
    char *name;
    int age;
};

void fun_teacher3() {
    Teacher3 t1;
    Teacher3 t2 = t1;
}


//    类的静态属性和方法
//    类的静态属性必须放在全局的地方初始化
//    非静态、静态函数可以访问静态属性，但是静态函数只能访问静态属性。（跟Java一样）
//    静态的属性和方法可以直接通过 类名:: 来访问（如果是public的话）。也可以通过 对象:: 来访问
class StaticTestClass {
public:
    void m1() {
        count++;
    }

    static void m2() {
        count++;
        cout << "m2 " << count << endl;
    }

private:
    static int count;
};

int StaticTestClass::count = 0;

//类的大小（sizeof）
//C++的内存分区：
//栈
//堆
//全局（静态、全局）
//常量区（字符串）
//程序代码区

//结构体有字节对齐的概念，那么类的普通属性与结构体相同的内存布局。
//例如下面的结构体大小是32 = 4 x 8：
struct C {
public:
    int i;//8个字节（由于字节对齐，与double一样为8个字节）
    int j;//8个字节
    int k;//8个字节
    double x;//8个字节
    void (*test)();//指针是4个字节，但是存放在代码区
};

//例如下面的类的大小是24（这里没搞懂，先放一放，以后回来再补）
class A {
public:
    int i;//8个字节（由于字节对齐，与double一样为8个字节）
    int j;//8个字节
    int k;//8个字节
    double t;//8个字节

    static int m;//4个字节，但是存在于全局静态区
    void test() {//4个字节，相当于函数指针的写法，但是存放在代码区
        cout << "打印" << endl;
    }
};

//类的this指针常函数
//const写在函数后面
//此时的const修饰的是this指针，this指针本来就是指针常量，不能修改值
//此处增加了const的修饰之后，this指针更加是一个常量指针，指针指向的值不能修改
class Teacher4 {
private:
    char *name;
    int age;
public:
    Teacher4(char *name, int age) {
        this->name = name;
        this->age = age;
    }

    //常函数，修饰的是this
    //既不能改变指针的值，也不能改变指针指向的内容
    //const Teacher* const this
    void myprint() const {
        printf("%#x\n", this);
//        改变属性的值
//        this->name = "yuehang";//改不了值
//        改变this指针的值
//        this = (Teacher*)0x00009;//不能改变指针的值
        cout << this->name << "," << this->age << endl;
    }
};
//我们用结构体去模拟类的时候，就需要自定义this指针了。所以说，在JNI开发的时候，JniEnv在C语音里面是二级指针
//（结构体实现，C语言中结构体没有tihs指针），在C++中是一级指针（类实现，类有this指针）



//Java内存分区
//JVM Stack（基本数据类型、对象引用）
//Native Method Stack（本地方法栈）
//方法区
//程序计数区
//直接内存
//热修复的基本概念：拿到错误的函数的指针，指向正确的函数的指针。（两个函数都已经加载的情况下）


//友元函数 函数中可以访问类的私有的属性
//主要作用：类、类与函之间的数据共享。比如类已经写好了，不想去改动类的结构（比如访问权限，那么最好的办法就是使用友元）
class FriendTest {
private:
    int i;

    //友元函数声明
    friend void fun(FriendTest &test, int i);

public:
    FriendTest(int i) {
        this->i = i;
    }
};

//友元函数实现，可以是全局的，也可以是其他类的

void fun(FriendTest &test, int i) {
    test.i = i;
    cout << "friend i " << i << endl;
}


//同理，B是A的友元类，因此B可以访问A的私有属性：
class FriendA {
    friend class B;

private:
    int i;
};

class B {
public:
    void test() {
        a.i = 20;
    }

private:
    FriendA a;
    int i;
};
//拓展：在Java（Java是C++写的嘛）中Class就可以理解为Object的“友元类”，Class类就可以访问Object的任何成员


//运算符重载，本质函数的调用
class Point {
//    注意，如果Point的x、y属性都是私有的话，就需要用到友元函数了，例如类已经写好了，不想破坏类的结构
    friend Point operator+(Point &p1, Point &p2);

public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

//    如果是在类内部的运算符重载，因为有this指针，重载的时候可以省略一个参数，
//    类可以直接访问自己的私有成员
    Point operator+(Point &p2) {
        return Point(this->x + p2.x, this->.y + p2.y);
    }

private:
    int x;
    int y;

};

//需要重载“+”
Point operator+(Point &p1, Point &p2) {
    return Point(p1.x + p2.x, p1.y + p2.y);
}


int main() {
    Teacher t1 = Teacher("cpp", 12);
    Teacher t2("c++", 12);

    Student s(1, "as", 23, "ee", 25);

    fun();

    Teacher2 t3 = Teacher2("android", 13);
    Teacher2 t4 = t3;//声明赋值，拷贝构造函数
    Teacher2 t5 = fun2(t3);//传递参数，作为函数返回值返回，给变量初始化赋值，拷贝构造函数

    cout << "-------" << endl;
    fun3();//析构释放内存多次

    cout << "-------" << endl;
    fun_teacher3();


//    动态内存分配
//    C++中使用new和delete进行动态内存分配，这时候构造和析构会调用。
//    C中使用malloc和free进行动态内存分配，构造和析构不会调用
    cout << "C++ using new delete control memory" << endl;
    Teacher *t6 = new Teacher("cai", 20);
    delete t6;

    cout << "C using malloc free control memory" << endl;
    Teacher *t7 = (Teacher *) malloc(sizeof(Teacher));
    free(t7);

    //数组动态内存分配，delete的时候需要加上[]
    int *arr1 = (int *) malloc(sizeof(int) * 10);
    arr1[0] = 1;
    free(arr1);

    int *arr2 = new int[10];
    arr2[0] = 1;
    delete[](arr2);
    cout << "-------" << endl;

    StaticTestClass::m2();

    Teacher4 teacher4 = Teacher4("const this", 21);
    teacher4.myprint();

    FriendTest friendTest = FriendTest(12);
    fun(friendTest, 23);

//    system("pause");
    return 0;
}