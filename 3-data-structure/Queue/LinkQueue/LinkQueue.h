//链队列
#pragma once

template<typename T>
class LinkQueue{
private:
    struct node{ //链队列节点
        T data;
        node *next;
    };

    node *front; //链队列的队头指针
    node *rear;  //链队列的队尾指针
    unsigned int length; // 链队列的长度

public:
    LinkQueue(){ front = rear = nullptr; length = 0; }
    ~LinkQueue(){ clear(); }
    LinkQueue(const LinkQueue &obj);
    LinkQueue<T>& operator=(const LinkQueue &obj);

    void clear();
    unsigned int getLength()const{ return length; }  // 获取链队列的长度
    bool isEmpty()const{ return length == 0; }  //判空
    void enQueue(const T elem); //入队，在队尾插入一个元素
    T deQueue(); // 出队，并返回出队的数据
    T get_front()const; //获取队头数据
};

#include"LinkQueue.cpp"