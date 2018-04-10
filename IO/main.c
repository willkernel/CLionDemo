//_CRT_SECURE_NO_WARNINGS用于Visual Studio2013编译去掉警告
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

//读写二进制文件
//计算机的文件存储在物理上都是二进制，文本文件和二进制之分，其实是一个人为的逻辑之分。
//C读写文本文件与二进制文件的差别仅仅体现在回车换行符：
//1.写文本时，每遇到一个'\n'，会将其转换成'\r\n'(回车换行)。
//2.读文本时，每遇到一个'\r\n'，会将其转换成'\n'。
//3.但是读写二进制文件的时候并不会做以上转换

void crypt(char *filePath, char *crpyptFilePath) {

    //打开文件，返回文件的指针
    FILE *f_read = fopen(filePath, "r");
    FILE *f_write = fopen(crpyptFilePath, "w");

    //文件是否成功打开
    if (f_read == NULL || f_write == NULL) {
        printf("文件打开失败");
        return;
    }

    int ch;//一次读取一个字符，每一个字符都是一个数据，用int来表示
    //EOF End Of File = -1
    while ((ch = fgetc(f_read)) != EOF) {
        fputc(ch ^ 12, f_write);//用异或运算进行加密
    }

    //关闭文件
    fclose(f_read);
    fclose(f_write);
}

void decrypt(char *crpyptFilePath, char *filePath) {

    //打开文件，返回文件的指针
    FILE *f_read = fopen(crpyptFilePath, "r");
    FILE *f_write = fopen(filePath, "w");

    //文件是否成功打开
    if (f_read == NULL || f_write == NULL) {
        printf("文件打开失败");
        return;
    }

    int ch;//一次读取一个字符，每一个字符都是一个数据，用int来表示
    //EOF End Of File = -1
    while ((ch = fgetc(f_read)) != EOF) {
        fputc(ch ^ 12, f_write);//用异或运算进行解密
    }

    //关闭文件
    fclose(f_read);
    fclose(f_write);
}

//二进制文件加解密
//读取二进制文件中的数据时，一个一个字符读取
//密码：password
void cryptPassword(char *normal_path, char *crypt_path, char *password) {
    //打开文件
    FILE *normal_fp = fopen(normal_path, "rb");
    FILE *crypt_fp = fopen(crypt_path, "wb");
    //一次读取一个字符
    int ch;
    int i = 0; //循环使用密码中的字母进行异或运算
    int pwd_len = strlen(password); //密码的长度
    while ((ch = fgetc(normal_fp)) != EOF) { //End of File
        //写入（异或运算）
        fputc(ch ^ password[i % pwd_len], crypt_fp);
        i++;
    }
    //关闭
    fclose(crypt_fp);
    fclose(normal_fp);
}

void decryptPassword(char normal_path[], char crypt_path[], char password[]) {
    //打开文件
    FILE *crypt_fp = fopen(normal_path, "rb");
    FILE *normal_fp = fopen(crypt_path, "wb");
    //一次读取一个字符
    int ch;
    int i = 0; //循环使用密码中的字母进行异或运算
    int pwd_len = strlen(password); //密码的长度
    while ((ch = fgetc(crypt_fp)) != EOF) { //End of File
        //写入（异或运算）
        fputc(ch ^ password[i % pwd_len], normal_fp);
        i++;
    }
    //关闭
    fclose(crypt_fp);
    fclose(normal_fp);
}


void main() {
    //file path
    char *path = "E:\\CLion\\IO\\test.txt";
    char *path_new = "E:\\CLion\\IO\\test_new.txt";
    printf("char* size %d\n", sizeof(char *));
    printf("int size %d\n", sizeof(int));
    printf("int* size %d\n", sizeof(int *));
    //open file
    FILE *f_read = fopen(path, "r");
    FILE *f_write = fopen(path_new, "w");

    //file open success/fail
    if (f_read == NULL || f_write == NULL) {
        printf("file open fail");
        return;
    }

//    //读取文件
    char buff[50];
    while (fgets(buff, 50, f_read)) {
        fputs(buff, f_write);
    }

    //关闭文件
    fclose(f_read);
    fclose(f_write);

//    注意：
//    缓冲区用int类型的数组
//    文件读写模式后面加上b代表读写二进制文件

    char *photo = "E:\\CLion\\IO\\photo.jpg";
    char *photo_new = "E:\\CLion\\IO\\photo_new.jpg";

    //    b代表是二进制文件 ，复制图片
    FILE *photo_read = fopen(photo, "r");
    FILE *photo_write = fopen(photo_new, "w");

    if (photo_read == NULL || photo_write == NULL) {
        printf("file open fail");
        return;
    }

    //类似于多线程下载的概念，首先将文件长度按N段分，然后将每段文件读取并写入到相应的临时文件
    //seek到文件的结尾，0L代表向前偏移几个字节
    fseek(photo_read, 0L, SEEK_END);
    //返回当前的文件指针相对于文件开头的位移量
    long seek = ftell(photo_read);
    printf("seek %ld\n", seek);

    //缓冲区，注意，读写二进制文件的时候，是用int类型的缓冲区
    char photoBuff[100];
    //每次读取的长度 50*4=200字节
    int len = 0;
    while ((len = fread(photoBuff, sizeof(int), 100, photo_read) != 0)) {
        //写文件
        fwrite(photoBuff, sizeof(int), len, photo_write);
    }


    fclose(photo_read);
    fclose(photo_write);


//    文件加密、解密
//    用简单的异或运算进行加密，解密的话就是一个逆过程
//    规则：1^1=0, 0^0=0, 1^0=1, 0^1=1 同为0，不同为1
    char *src = "E:\\CLion\\IO\\src.txt";
    char *dst = "E:\\CLion\\IO\\dst.txt";
    char *dec = "E:\\CLion\\IO\\dec.txt";
    char *decPWD = "E:\\CLion\\IO\\decPWD.txt";
    crypt(src, dst);

    //文件解密decrpypt，是一个逆过程，注意先把原来的文件删除
    decrypt(dst, dec);

//    二进制文件加密解密
    cryptPassword(src, dst, "abcdef");
    decryptPassword(dst, decPWD, "abcdef");
}

