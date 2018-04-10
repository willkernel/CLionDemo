#include <iostream>

using namespace std;

//继承
class Human {
private:
    char *name;
    int age;
public:
    Human(char *name, int age) {
        this->name = name;
        this->age = age;
        cout << "Human constructor" << endl;
    }

    ~Human() {
        cout << "Human destructor" << endl;
        free(name);
    }

    void say() {
        cout << "Human say" << endl;
    }
};

//通过:public来继承Human
//通过在自身构造的时候给父类构造函数传参。（同时给属性对象赋值）因为子类构造的时候，会先构造父类
//构造与析构的调用顺序：构造的时候先调用父类的构造函数，然后调用子类的构造函数。析构的时候相反。总结就是，先构造，先释放
//上面的继承中，子类覆盖了父类的say方法，但是这并不是多态（没有virtual关键字）。只是父类的say方法被隐藏了。子类可以对象调用父类的方法
class Woman : public Human {
public:
    Woman(char *name, int age, float weight)
            : Human(name, age), m(name, age) {
        this->weight = weight;
        cout << "Woman constructor" << endl;
    }

    ~Woman() {
        cout << "Woman destructor" << endl;
    }

    void shopping() {
        cout << "woman shopping" << endl;
    }

    void say() {
        cout << "woman say" << endl;
    }

private:
    float weight;
    Human m;
};

void work(Human &m) {
    m.say();
    cout << "Human work" << endl;
}


//继承的访问修饰符
//主要的规律就是，两个之中的最小值
//基类中      继承方式             子类中
//public     ＆ public继承        => public
//public     ＆ protected继承     => protected
//public     ＆ private继承       => private
//
//protected  ＆ public继承        => protected
//protected  ＆ protected继承     => protected
//protected  ＆ private继承       => private
//
//private    ＆ public继承        => 子类无权访问
//private    ＆ protected继承     => 子类无权访问
//private    ＆ private继承       => 子类无权访问

//补充说明：
//public关键字能够在类本身、子类、类以外的地方使用
//protect关键字只能够在 类本身、子类 中使用
//private关键字只能够在 类本身 中使用

//多继承
class Person {
public:
    Person() {
        cout << "Person" << endl;
    }
};

class Citizen {
public:
    Citizen() {
        cout << "Citzen" << endl;
    }
};

class Student : public Person, Citizen {
public:
    Student() {
        cout << "Student" << endl;
    }
};

//多继承二义性问题
//问题：B中有两个name的副本。但是我们一般情况下只需要一份
//解决办法：虚继承，不同路径继承来的同名成员只有一份拷贝，解决不明确的问题：
//如果某个类B的两个父类（A1、A2）都继承于同一父类（A），那么这两个父类（A1、A2）可以通过在继承的时候加上virtual关键字来解决二义性问题
class A {
public:
    char *name;
};

class A1 : virtual public A {

};

class A2 : virtual public A {

};

class B : public A1, public A2 {

};


//多态
//        多态的作用：程序的扩展性
//        继承的作用：程序的重用性
//多态分类：
//动态多态：程序运行过程中，觉得哪一个函数被调用（重写）
//静态多态：重载

//这里主要讨论动态多态，动态多态的条件：
//继承
//父类的引用或者指针指向子类的对象
//函数的重写（需要增加virtual关键，否则的话就是覆盖）
class Human1 {
public:
    virtual void say() {
        cout << "Human1 say" << endl;
    }
};

class Woman1 : public Human1 {
public:
    virtual void say() {
        cout << "Woman1 say" << endl;
    }
};

class Man1 : public Human1 {
public:
    virtual void say() {
        cout << "Man1 say" << endl;
    }
};

void say(Human1 &h) {
    h.say();
}


//纯虚函数(抽象类)
//当一个类具有一个纯虚函数，这个类就是抽象类
//抽象类不能实例化对象
//子类继承抽象类，必须要实现纯虚函数，如果没有，子类也是抽象类

//抽象类（逻辑上就是Java中的接口）的作用：为了继承约束
//（新增加的类必须实现父类，提高代码重用性，保证系统的条理性、封闭性）
//根本不知道未来的实现（例如JDBC中的驱动就是接口）
class Shape {
public:
    //纯虚函数
    virtual void sayArea()=0;
};

class Circle : public Shape {
private:
    int r;
public:
    Circle(int r) {
        this->r = r;
    }

//    error: cannot declare variable 'c' to be of abstract type 'Circle'
//    because the following virtual functions are pure within 'Circle':
//    virtual void sayArea()=0;
    void sayArea() override {
        cout << "area is " << 3.14 * r * r << endl;
    }
};

// C++中的接口是按照逻辑上区分出来的，不像Java中有专门的interface关键字
// 例如在C++中我们可以把只有纯虚函数的类看做一个接口：
class Drawble {
    virtual void draw();
};

int main() {
    Student s();
    Woman woman("dan", 25, 85);
    woman.Woman::say();
    woman.Human::say();
    woman.shopping();
//调用父类的say方法（显示指明，或者用子类去初始化父类的时候）
    Human h = woman;
    h.say();
    work(woman);

    B b;
    //当没有virtual ,虚继承 这句话编译不通过，因为存在二义性  error: request for member 'name' is ambiguous
    b.name = "b";

    //B中有两个name的副本，我们可以指定使用哪个父类的name
    b.A1::name = "1";
    b.A2::name = "2";

    Woman1 w1;
    Man1 m1;

    //调用父类方法
    m1.Human1::say();
    //父类的引用指向子类的对象，调用子类的方法
    say(w1);
    say(m1);

//    error: cannot declare variable 's' to be of abstract type 'Shape'
//    Shape s;

    Circle c(10);
    c.sayArea();

    return 0;
}