//��ջ��Linked stack
//����ͷ�ڵ�

#pragma once

template<typename T>
class LinkStack{
private:
    struct node{
        T data;
        node *next;
    };

    node *top; // ջ��ָ�룬Ҳ��ͷָ��
    unsigned int length; // ��ջ�����ݸ���
    
public:
    LinkStack(); // ���캯��
    ~LinkStack(); // ��������
    LinkStack(const LinkStack& obj); // �������캯��
    LinkStack<T>& operator=(const LinkStack& obj); // ��ֵ�����

    void clear(); // ���ջ
    bool isEmpty() const { return top==nullptr; } // �п�
    int getLength() const { return length; } // ��ȡ��ջ���ݸ���
    void push(const T elem); // ��ջ
    T pop(); // ��ջ�������س�ջԪ��
    T get_top() const; // ����ջ��Ԫ��
};



#include"LinkStack.cpp"