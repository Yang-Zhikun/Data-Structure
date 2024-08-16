//������
#pragma once

template<typename T>
class LinkQueue{
private:
    struct node{ //�����нڵ�
        T data;
        node *next;
    };

    node *front; //�����еĶ�ͷָ��
    node *rear;  //�����еĶ�βָ��
    unsigned int length; // �����еĳ���

public:
    LinkQueue(){ front = rear = nullptr; length = 0; }
    ~LinkQueue(){ clear(); }
    LinkQueue(const LinkQueue &obj);
    LinkQueue<T>& operator=(const LinkQueue &obj);

    void clear();
    unsigned int getLength()const{ return length; }  // ��ȡ�����еĳ���
    bool isEmpty()const{ return length == 0; }  //�п�
    void enQueue(const T elem); //��ӣ��ڶ�β����һ��Ԫ��
    T deQueue(); // ���ӣ������س��ӵ�����
    T get_front()const; //��ȡ��ͷ����
};

#include"LinkQueue.cpp"