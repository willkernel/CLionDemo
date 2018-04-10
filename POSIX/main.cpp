#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "pthread.h"
#include <Windows.h>
//一个相当于Java的run方法
void *start_fun1(void* arg){

    //得到线程创建的参数
    char* no = (char*)arg;
    int i = 0;
    for (; i < 10; i++){
        printf("%s thread : %d \n", no, i);
        if (i == 5){
            //线程自杀，需要返回参数
            pthread_exit((void*)2);
            //线程他杀
            //pthread_cancel()
        }
    }

    //run方法执行完，线程结束，返回
    return (void*)1;
}

int i = 0;

//一个相当于Java的run方法
void *start_fun2(void* arg){

    //得到线程创建的参数
    char* no = (char*)arg;
    for (; i < 10; i++){
        Sleep(10);
        printf("%s thread : %d \n", no, i);
    }
    i = 0;

    //run方法执行完，线程结束，返回
    return (void*)1;
}
//互斥锁
pthread_mutex_t m;
//一个相当于Java的run方法
//在代码中：
//我们通过pthread_mutex_init初始化了一把互斥锁，最后通过pthread_mutex_destroy进行销毁。
//在线程执行的时候，我们可以通过pthread_mutex_lock、pthread_mutex_unlock进行加锁和解锁。
//使用互斥锁可以解决线程死锁（ABBA）的问题
void *start_fun3(void* arg){

    //加锁
    pthread_mutex_lock(&m);

    //得到线程创建的参数
    char* no = (char*)arg;
    for (; i < 10; i++){
        Sleep(10);
        printf("%s thread : %d \n", no, i);
    }
    i = 0;

    //解锁
    pthread_mutex_unlock(&m);

    //run方法执行完，线程结束，返回
    return (void*)1;
}


//互斥锁是先让一个线程做完，然后另外一个线程做
//还有一种情况就是，一个线程先执行，生产，然后另外一个线程就会去消费
//其实视频解码的绘制使用的就是生产者--消费者的模式
//图片的下载显示也是基于这种模式。比如说我们生产者生成的产品，
//放到一个队列里面，当生产者生产出产品的时候就会发送信号通知消费者去消费，
//例如RTMP推流的时候，我们本地采集音视频的时候就需要一种队列，
// 因为本地的压缩比网络上传要快，使用这一种模式，就需要条件变量
//模拟产品队列
int productNum = 0;
//互斥锁
pthread_mutex_t l;
//条件变量
pthread_cond_t c;
void *produce(void* arg){

    char* no = (char*)arg;

    for (;;){
        //加锁
        pthread_mutex_lock(&m);

        //生产者生产产品
        productNum++;
        printf("%s生产产品：%d\n", no, productNum);
        //通知消费者进行消费
        pthread_cond_signal(&c);

        //解锁
        pthread_mutex_unlock(&m);

        Sleep(100);
    }
    return (void*)1;
}
void *comsume(void* arg){

    char* no = (char*)arg;

    for (;;){
        pthread_mutex_lock(&m);
        //使用while是为了防止惊群效应唤醒条件变量
        while (productNum == 0){
            //1.没有产品可以消费，等待生产者生产，即等待条件变量被唤醒
            //2.释放互斥锁，使得其他消费者可以进来等待
            //3.被唤醒的时候，解除阻塞，重新申请获得互斥锁，保证只有一个消费者消费
            pthread_cond_wait(&c, &m);
        }
        productNum--;
        printf("%s消费者消费产品：%d\n", no, productNum);
        pthread_mutex_unlock(&m);
        Sleep(1000);
    }
    return (void*)1;
}

#define NUM_PRODUCER 2
#define NUM_COMSUMER 2
pthread_t threads[NUM_PRODUCER + NUM_COMSUMER];
//在代码中：
//
//通过pthread_create创建线程，需要传入一个函数指针，相当于Java线程中的run方法。然后还需要传参，参数可以在run方法中取出。
//线程被创建以后，就会执行“run”方法，该方法中可以拿到线程创建的参数，可以自杀掉线程。线程的结束需要参数。
//可以通过pthread_join方法等待线程结束，并且可获取线程结束的参数
int main(){

    printf("main thread\n");

    pthread_t thread;
    //创建线程，指定run方法，并且可以传入参数，在run方法的arg中可以取出
    pthread_create(&thread, NULL, start_fun1, (void *) "no");

    void* r_val;
    //等待线程结束，获取线程返回参数
    pthread_join(thread, &r_val);
    printf("return value : %d", (int)r_val);

    printf("---");

    pthread_t thread1;
    pthread_t thread2;
    //创建线程，指定run方法，并且可以传入参数，在run方法的arg中可以取出
    pthread_create(&thread1, NULL, start_fun2, (void *) "no1");
    pthread_create(&thread2, NULL, start_fun2, (void *) "no2");

    void* r_val1;
    void* r_val2;
    //等待线程结束，获取线程返回参数
    pthread_join(thread1, &r_val1);
    pthread_join(thread2, &r_val2);
    printf("return value : %d\n", (int)r_val1);
    printf("return value : %d\n", (int)r_val2);
//    打印的结果
//    no2 thread : 0
//    no1 thread : 0
//    no2 thread : 2
//    no1 thread : 2
//    no1 thread : 4
//    no2 thread : 4
//    no1 thread : 5
//    return value : 2
//    return value : 2
//    可见，两个线程是并行执行的。i变量同时被两个线程访问
//    但是我们现在要求线程1先执行完，然后才到线程2执行，
//    那么两个线程i的所有情况都会被打印出来

    //初始化互斥锁
    pthread_mutex_init(&m, NULL);

    pthread_t thread3;
    pthread_t thread4;
    //创建线程，指定run方法，并且可以传入参数，在run方法的arg中可以取出
    pthread_create(&thread1, NULL, start_fun3, (void *) "no1");
    pthread_create(&thread2, NULL, start_fun3, (void *) "no2");

    void* r_val3;
    void* r_val4;
    //等待线程结束，获取线程返回参数
    pthread_join(thread1, &r_val3);
    pthread_join(thread2, &r_val4);
    printf("return value : %d\n", (int)r_val3);
    printf("return value : %d\n", (int)r_val4);

    //销毁互斥锁
    pthread_mutex_destroy(&m);

//    输出的结果
//    no1 thread : 0
//    no1 thread : 1
//    no1 thread : 2
//    no1 thread : 3
//    no1 thread : 4
//    no1 thread : 5
//    no1 thread : 6
//    no1 thread : 7
//    no1 thread : 8
//    no1 thread : 9
//    no2 thread : 0
//    no2 thread : 1
//    no2 thread : 2
//    no2 thread : 3
//    no2 thread : 4
//    no2 thread : 5
//    no2 thread : 6
//    no2 thread : 7
//    no2 thread : 8
//    no2 thread : 9
//    return value : 1
//    return value : 1



    //初始化互斥锁
    pthread_mutex_init(&l, NULL);
    //初始化条件变量
    pthread_cond_init(&c, NULL);

    pthread_t thread_producer;
    pthread_t thread_comsumer;
    //创建线程，指定run方法，并且可以传入参数，在run方法的arg中可以取出
    pthread_create(&thread_producer, NULL, produce, (void *) "producer");
    pthread_create(&thread_comsumer, NULL, comsume, (void *) "comsumer");

    //等待线程结束，获取线程返回参数
    pthread_join(thread_producer, NULL);
    pthread_join(thread_comsumer, NULL);

    //销毁互斥锁
    pthread_mutex_destroy(&l);
    //销毁条件变量
    pthread_cond_destroy(&c);
//    输出的结果如下：
//    main thread
//    producer生产产品：1
//    comsumer消费者消费产品：0
//    producer生产产品：1
//    producer生产产品：2
//    producer生产产品：3
//    producer生产产品：4
//    producer生产产品：5
//    producer生产产品：6
//    producer生产产品：7
//    producer生产产品：8
//    producer生产产品：9
//    comsumer消费者消费产品：8
//    producer生产产品：9
//    producer生产产品：10
//    producer生产产品：11
//    producer生产产品：12
//    producer生产产品：13
//    producer生产产品：14
//    producer生产产品：15
//    producer生产产品：16
//    producer生产产品：17
//    comsumer消费者消费产品：16

//    上面是只有一个生产者和一个消费者的示例代码
//    一般开说，生产者和消费者都会有多个。这里我们通过线程数组的方式来实现
    //创建生产者线程
    for (i = 0; i < NUM_PRODUCER; i++){
        pthread_create(&threads[i], NULL, produce, (void*)i);
    }


    //创建消费者线程
    for (i = 0; i < NUM_COMSUMER; i++){
        pthread_create(&threads[NUM_PRODUCER + i], NULL, comsume, (void*)i);
    }

    //等待线程结束，获取线程返回参数
    for (i = 0; i < NUM_PRODUCER + NUM_COMSUMER; i++){
        pthread_join(threads[i], NULL);
    }

    return 0;
}