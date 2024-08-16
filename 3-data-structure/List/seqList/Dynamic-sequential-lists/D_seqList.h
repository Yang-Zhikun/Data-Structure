//��̬˳���
//��̬�ڴ���䣬���Զ�����

#pragma once

template<typename T>
class D_seqList{
private:
    T *data;//������ݵ��׵�ַ
    unsigned int length;//��ǰ˳��������ݸ���
    unsigned int maxLen;//����

    void resize();//˳�����ʱ����

public:
    D_seqList();//���캯��
    D_seqList(const D_seqList &sl);//�������캯��
    D_seqList<T>& operator=(const D_seqList &sl);//��ֵ�����
    ~D_seqList(){ delete[] data; }//��������

    unsigned int getLength()const{ return length; }//��ȡ��length
    void clear(){ length=0; };//���˳���
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


#include"D_seqList.cpp"