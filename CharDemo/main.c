#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

//C语音的字符串有两种：
//1.字符数组实现,数组可以修改其中某一个值，不可以整体赋值
//2.字符指针实现,字符指针不可以修改其中某一个值，可以整体赋值。使用指针加法，结合结束符，可以进行截取

void main() {
    //使用字符数组，内存连续，可以修改(StringBuilder,buffer)
    char str1[] = {'a', 'b', 'c', '\0'};//可以不指定长度，但是需要结束符
    int null = NULL;
    printf("null %d\n", null);
    printf("finish sign %d\n", str1[3]);
    char str2[6] = {'a', 'b', 'c'};//可以指定长度，后面就不会乱码
    char str3[] = {'a', 'b', 'c', 'd'};//没有结束符'\0' 乱码
    char str4[] = "abcdeabcde";//直接用双引号
    str4[0] = 's';//修改某个字符
    printf("str1 %s\n", str1);
    printf("str2 %s\n", str2);
    printf("str3 %s\n", str3);
    printf("str4 %s\n", str4);

    //字符数组不能整体赋值，只能在声明的时候整体赋值，优点是可以局部修改某一个字符。需要重新整体赋值的话，需要使用strcpy
//    str1 = "abcde";
    strcpy(str1, "cde");
    printf("str1 %s\n", str1);

    //字符指针，不需要、不能修改某一个字符串（String）
    char *str5 = "abcdefg";
    //不能修改某一个字符串，否则会提示访问冲突
    //str5[0] = '7';str5++;str5 = "哈哈";

    //但是可以整体赋值
    str5 = "chardemo";
    printf("str5 %s\n", str5);

    //使用指针加法，截取字符串
    str5 += 3;
    while (*str5) {
        printf("%c\n", *str5);
        str5++;
    }


//    字符串常用方法
//    strcpy字符串赋值
//    原型：extern char *stpcpy(char *dest,char *src);
//    用法：#include <string.h>
//    功能：把src所指由NULL结束的字符串复制到dest所指的数组中
//    说明：src和dest所指内存区域不可以重叠且dest必须有足够的空间来容纳src的字符串
//    返回：指向dest结尾处字符(NULL)的指针。
//    注意：因为底层需要进行单个字符的操作，因此dest需要是一个字符数组类型，且空间必须足够大
    char dest1[10];
    char *src1 = "123";
    strcpy(dest1, src1);
    printf("dest1 %s\n", dest1);

//    strcat字符串拼接
//    原型：extern char *strcat(char *dest,char *src);
//    用法：#include <string.h>
//    功能：把src所指字符串添加到dest结尾处(覆盖dest结尾处的'\0')并添加'\0'
//    说明：src和dest所指内存区域不可以重叠且dest必须有足够的空间来容纳src的字符串
//    返回：指向dest的指针
    char dest2[50];
    char *a = "super";
    char *b = "man is hero";
    strcpy(dest2, a);
    strcat(dest2, b);
    printf("dest2 %s\n", dest2);

//    strchr字符查找
//    原型：extern char *strchr(char *s,char c)
//    用法：#include <string.h>
//    功能：查找字符串s中首次出现字符c的位置,查找单个字符'c'返回第一个字符的指针，查找多个字符'cde'返回最后一个字符指针位置
//    说明：返回首次出现c的位置的指针，减去原字符数组的指针位置，获取索引位置，如果s中不存在c则返回NULL
    char *chr = "chardemo";
    printf("find c index %ld\n", strchr(chr, 'd') - chr);
    printf("find c %c\n", chr[3]);

//    strstr字符串查找
//    原型：extern char *strstr(char *haystack, char *needle)
//    用法：#include <string.h>
//    功能：从字符串haystack中寻找needle第一次出现的位置（不比较结束符NULL)
//    说明：返回指向第一次出现needle位置的指针，如果没找到则返回NULL

    char *haystack = "I want go to Austria";
    char *needle = "Aus";//区分大小写，返回第一个字符的指针位置
    char *p = strstr(haystack, needle);
    printf("%s\n",p);
    printf("%ld\n", p - haystack);
}
