#include <stdio.h>

//联合体，共用体
//不同类型的变量共同占用同一段内存，相互覆盖，联合变量任何时刻只有一个成员存在，节省内存
//联合体变量的大小=最大的成员所占的字节数（字节对齐 ），比喻同穿一条裤子

union MyValue {
    int x;
    int y;
    double z;
};

//JNI头文件中的联合体
//typedef union jvalue {
//    jboolean z;
//    jbyte b;
//    jchar c;
//    jshort s;
//    jint i;
//    jlong j;
//    jfloat f;
//    jdouble d;
//    jobject l;
//};

//枚举（列举所有的情况），限定值的取值范围，保证取值的安全性
enum Day {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday,
};

void main() {
    union MyValue v;
    v.x = 90;
    v.y = 80;
    v.z = 23.5;//最后一次赋值有效

    printf("float size %d\n", sizeof(float));
    printf("double size %d\n", sizeof(double));
    printf("%d %d %lf\n", v.x, v.y, v.z);
    v.x = 20;
    printf("%d\n", v.x);

    enum Day day=Tuesday;

    printf("Tuesday %#x,%d\n",&day,day);
}