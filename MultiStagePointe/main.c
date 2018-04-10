#include <stdio.h>
#include <stdlib.h>

int main() {
    //数组在内存中是连续存储的
    //指针的运算在数组遍历的时候才有意义
    //ids+i等价于&ids[i]

    //二维数组的行指针、列指针
    //*(ids+i)等价于ids[i]
    int ids[] = {0, 1, 2, 3, 4, 6};
    int *p = &ids;
    //数组的首地址，下面都是一个意思
    printf("%#x\n", ids);
    printf("%#x\n", &ids[0]);
    printf("%#x\n", &ids);
    printf("%#x\n", p);

    //指针的加减法，移动sizeof(数据类型)个字节
    p++;
    //输出数组中的数据1
    printf("%d\n", *p);

    //通过指针给数组赋值,高级写法,[]运算符的重载
    int i = 0;
    for (; i < 6; i++) {
        ids[i] = 12;
        printf("%d %d \n", i,ids[i]);
    }

    //普通写法，利用指针
    p = ids;
    for (; p < ids + 5; p++) {
        *p = 16;
        printf("%d %d \n", i,*p);
    }
}