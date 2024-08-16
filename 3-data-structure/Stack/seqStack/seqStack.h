//˳��ջ��Static sequential stack
//�����Զ����ݣ�����󳤶ȹ̶�

#pragma once

template<typename T>
class seqStack{
private:
    T *data;//���ջ���ݵ��������ַ
    int top; // ջ��Ԫ�ص��±꣬== -1ʱ��ʾջ��
    int maxlen; // ջ��ջ����󳤶ȣ�������Ĵ�С

public:
    seqStack(const int init_len = 100);//���캯����init_len��ջ����󳤶�(����Ĵ�С)
    ~seqStack() { delete[] data; } //��������
    seqStack(const seqStack& obj);//�������캯��
    seqStack<T>& operator=(const seqStack& obj);//��ֵ�����

    void clear() { top = -1; } //���ջ
    bool isEmpty()const { return top == -1;} //�п�
    int getLength()const { return top+1; } //��ȡջ�����ݸ���
    void push(const T elem); //��ջ
    T pop(); //��ջ�������س�ջԪ��
    T get_top()const; //��ȡջ��Ԫ��
};


#include"seqStack.cpp"