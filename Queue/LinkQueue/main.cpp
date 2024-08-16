#include"LinkQueue.h"
#include<stdio.h>

int main(){
    LinkQueue<double> q;
    printf("length:%d, empty%d\n", q.getLength(), q.isEmpty());
    for(int i=1;i<=100;i++){
        q.enQueue(3.999*i);
        printf("length:%d, empty:%d, get_front:%.6lf\n", q.getLength(), q.isEmpty(), q.get_front());
    }
    for(int i=1;i<=100;i++){
        printf("deQueue:%.6lf, ", q.deQueue());
        printf("length:%d, empty:%d\n", q.getLength(), q.isEmpty());
    }
    system("pause");
}