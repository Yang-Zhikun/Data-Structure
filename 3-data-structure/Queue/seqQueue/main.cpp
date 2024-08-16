#include"seqQueue.h"
#include<stdio.h>

int main(){
    seqQueue<int> q;
    for(int i=1;i<=99;i++){
        q.enQueue(i);
        printf("isEmpty:%d, isFull:%d, length:%d, front:%d\n", q.isEmpty(), q.isFull(), q.getLength(), q.get_front());

    }
    for(int i=1;i<=99;i++){
        printf("deQueue: %d, ", q.deQueue());
        printf("isEmpty:%d, isFull:%d, length:%d\n", q.isEmpty(), q.isFull(), q.getLength());
    }
    system("pause");
}