#include <stdio.h>
#include <malloc.h>
#include <winuser.h>

void speak() {
    printf("speak\n");
}

struct Person {
    char *name;
    int age;

    void (*speak)();//函数指针，类似java 成员方法
//结构体可以在定义之后跟着声明或者初始化变量
} p3 = {"black", 12, speak}, p4 = {"white", 15, speak};

void introduce(struct Person p) {
    printf("name is %s,age is %d\n", p.name, p.age);
}

//匿名结构体
//控制结构体变量的个数（限量版），相当于单例
struct {
    char *name;
    int age;

    void (*speak)();
} p5, p6 = {"anon", 1, speak};

struct Man {
    int age;//4字节
    double weight;//8字节
} m1 = {23, 34.0};

void main() {
//    只有在声明的时候才能用{}进行初始化，否则只能逐一赋值
//    结构体的嵌套，初始化的时候{}嵌套即可，或者连.操作
//    结构体的初始化方式一
    struct Person p1 = {"lu", 20, speak};
    printf("name is %s,age is %d\n", p1.name, p1.age);
    p1.speak();

//    结构体初始化方式二
    struct Person p2;
    p2.name = "hei";
    p2.age = 10;
    p2.speak = speak;

    printf("name is %s,age is %d\n", p2.name, p2.age);
    p2.speak();

    introduce(p3);
    introduce(p4);

    printf("name is %s,age is %d\n", p5.name, p5.age);
    printf("name is %s,age is %d\n", p6.name, p6.age);

    struct Person *p7 = &p2;

//    结构体与指针
    printf("%s %d\n", (*p7).name, (*p7).age);
    //equals
    printf("%s %d\n", p7->name, p7->age);

//    结构体数组
    struct Person persons[] = {{"xxx", 32, speak},
                               {"yyy", 43, speak}};

//    求出结构体数组的大小
    int size = sizeof(persons) / sizeof(struct Person);
    printf("size %d\n", size);
    //通过指针去遍历
    struct Person *p = persons;
    for (; p < persons + size; p++) {
        printf("%s %d\n", p->name, p->age);
    }

    //一般的数组方式去遍历,index 遍历
    int i = 0;
    for (; i < size; i++) {
        printf("%s %d\n", persons[i].name, persons[i].age);
    }

//    结构体的大小
//    字节对齐，结构体变量的大小，必须是最宽基本数据类型的整数倍。通过空间换取时间来提升读取效率
    printf("struct size %d\n", sizeof(m1));

    //结构体与动态内存分配
//    struct Man* man=(struct Man*)malloc(sizeof(struct Man)*10);
    struct Man *man = (struct Man *) calloc(10, sizeof(struct Man));

    int manSize = sizeof(man) / sizeof(struct Man);
    struct Man *loop = man;
    for (; loop < man + manSize; loop++) {
        (*loop).age = 29;
        (*loop).weight = 100;
    }

    printf("man age %d weight %f \n", (*loop).age, (*loop).weight);
    if (man != NULL) {
        free(man);
        man = NULL;
    }

//    typedef取别名，定义新的类型，方便使用
//    typedef int jnit;
//    #if defined(__cplusplus)
//    typedef _JNIEnv JNIEnv;
//    typedef _JavaVM JavaVM;
//    3.书写简洁

//    整型取别名
    typedef int Age;
    Age age=10;

//    Person结构体取别名
    typedef struct Person P;
    P person;

//    Person结构体指针取别名
    typedef struct Person* PP;
    PP pp=&p2;

//    在结构体定义的时候取别名（对应以上两种）
    typedef struct Person{
        int age;
        char* name;
    } P1,*P2;//P1是结构体的别名，P2是结构体指针的别名，与变量的声明区分开（没有typedef）

    P1 p11={20,"p1"};
    P2 p21=&p11;


//  终极例子  定义一个Girl结构体，包括属性和方法
    typedef struct Girl{
        char* name;
        int age;
        //函数指针
        void(*sayHi)(char*);
    }Girl;//给结构体取一个别名Girl（别名可以与结构体原本的名字相同）

    typedef Girl* GirlP;

    void sayHi(char* text){
        MessageBox(0,text,"title",0);
    }

    void reGirlName(GirlP girlP){
        girlP->name="babe";
    }

    Girl girl={"baby",22,sayHi};
    girl.sayHi("hello");

    GirlP girlP=&girl;
    girlP->sayHi("baby");

    //传递指针，改名（只有传递指针才能修改值，所以指针是比较常用的方式）
    reGirlName(girlP);

}