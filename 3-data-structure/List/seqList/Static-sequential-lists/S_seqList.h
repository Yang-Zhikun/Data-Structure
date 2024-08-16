//��̬˳���, Static sequential list
//�����Զ����ݣ��������̶�

#pragma once

const int MAXLEN = 100;    //��̬˳��������

template<typename T>
class S_seqList{
private:
    T data[MAXLEN];//������ݵ��׵�ַ
    unsigned int length;//��ǰ˳��������ݸ���

public:
    S_seqList();//���캯��
    S_seqList(const S_seqList& obj);//�������캯��
    S_seqList<T>& operator=(const S_seqList& obj);//��ֵ�����

    unsigned int getLength()const{ return length; }//��ȡ��length
    void clear(){ length = 0; };//���˳���
    bool isEmpty()const{ return length==0; }//�ж�˳����Ƿ�Ϊ��
    void traverse()const;//����˳���
    T operator[] (const unsigned int i)const;//�����[]����ȡ˳���λ��i������(0<=i<length)
    T& operator[] (const unsigned int i);//�����[]������˳���λ��i�����ݵ�����(0<=i<length)
    void set(const unsigned int i, const T elem){ this->operator[](i) = elem; }//��˳���λ��Ϊi��Ԫ�ص�ֵ��Ϊelem(0<=i<length)
    T get(const unsigned int i)const{ return operator[](i); }//��ȡ˳���λ��i������(0<=i<length)
    void insert(const unsigned int i, const T elem);//��˳���λ��i������һ������(0<=i<=length)
    void push_back(const T elem){ insert(length, elem); }//��˳���ĩβ����һ������
    void remove(const unsigned int i);//ɾ��˳���λ��i������(0<=i<length)
    void pop_back(){ remove(length-1); }//ɾ��˳���ĩβ��һ������
    void reserve();//����˳���
};


#include "S_seqList.cpp"