#include <iostream>
#include <stdexcept>

using namespace std;

void fun1() throw(char*) {
    throw "fun1 exception";
}


void fun2() throw(out_of_range) {
    throw out_of_range("out of range");
}

class MyException : public exception {
public:
    MyException(char *msg) : exception() {
        cout << msg << endl;
    }
};

void fun3() throw(MyException) {
    throw MyException("MyExc");
}


class Err {
public:
    class MyExc : public exception {
    public:
        MyExc() {
            cout << "Err::MyExc()" << endl;
        }
    };
};


//抛出内部类的异常
void fun4() throw(Err::MyExc) {
    throw Err::MyExc();
}

int main() {

// throw不同类型的异常，就会在相应的catch块里面捕获到
// 其中...能够捕获所有类型的异常，catch有先后，如果先捕获到异常，后面的catch块就不会执行了
    try {
//        throw 1;
//        throw "exc";
        throw 9.5;
    } catch (int a) {
        cout << "int exc" << endl;
    } catch (char *a) {
        cout << "char* exc" << endl;
    } catch (...) {
        cout << "unKnow exc" << endl;
    }

//    try {
//        fun1();
//    } catch (const char *s) {
//        cout << "char* exc: " << s << endl;
//    }

    try {
        fun2();
    } catch (out_of_range err) {
        cout << "err: " << err.what() << endl;
    }


    try {
        fun3();
    } catch (MyException err) {
        cout << "err: " << err.what() << endl;
    }

    try {
        //    下面这条语句是抛出异常指针：
//        但是我们一般不推荐抛出异常指针，因为new出来的类是存在于堆内存的，我们还需要手动去delete。
        throw new MyException("My Custom Exc");
    } catch (MyException *err) {
        cout << "MyException err:  " << (*err).what() << endl;
    }

    try {
        fun4();
    } catch (Err::MyExc err) {
        cout << "Err::MyExc err:  " << err.what() << endl;
    }

    return 0;
}