//顺序队列(循环队列) Sequential queue
#pragma once

template<typename T>
class seqQueue{
private:
    T *data;
    unsigned int maxLen;//数据的最大长度
    unsigned int front; //队首下标
    unsigned int rear;  //队尾下标

public:
    seqQueue(unsigned int maxLen = 100); // 构造函数 maxLen是队列的最大长度
    ~seqQueue(){ delete[] data; } // 析构函数
    seqQueue(const seqQueue<T> &obj); //拷贝构造函数
    seqQueue<T>& operator=(const seqQueue &obj); // 赋值运算符

    void clear(); // 清空队列
    bool isEmpty()const{ return front==rear; } // 判空
    bool isFull()const{ return (rear+1)%maxLen==front; } //判满
    unsigned int getLength()const{ return (rear-front+maxLen)%maxLen; } // 获取队列长度
    void enQueue(T elem); // 入队
    T deQueue(); //出队，并返回队头元素
    T get_front()const; // 获取队头元素
};

#include"seqQueue.cpp"

//采用牺牲一个储存空间以判断队满
//约定front指向队首元素，rear指向队尾元素的后一个位置
/*判断队空的条件front==rear
/*判断队满的条件(rear+1)%maxLen==front
    *原因当rear的下一个是front时即是队满
    *如果rear+1小于maxLen时，(rear+1)%maxLen等于rear+1
    *如果rear+1大于maxLen时，(rear+1)%maxLen等于rear+1-maxLen
/*求队列长度：(rear-front+maxLen)%maxLen
    *原因rear-front即是队列长度
    *当rear-front小于0时，加上maxLen就是队列长度(小于等于maxLen)，模maxLen后是原数
    *当rear-front大于0时，就是队列长度，加上maxLen后又模去就是原数
/*入队：rear = (rear+1)%maxLen
    *原因：从队尾插入一个元素，rear向后移一位，%maxLen防止超过最大下标
/*出队：front = (front+1)%maxLen
    *原因：删除队头元素，front向后移一位，%maxLen防止超过最大下标
*/