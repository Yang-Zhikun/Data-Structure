//˫������(��ͷ�ڵ�)�����յ�����
//Doubly linked lists

#pragma once

template<typename T>
class D_LinkList{
private:
    struct node{//˫�������һ���ڵ�
        T data;//�����򣬴������
        node *prev;//ָ���򣬴��ǰ���ĵ�ַ
        node *next;//ָ���򣬴�ź�̵ĵ�ַ
    };

    node *head;//ͷָ��
    node *tail;//βָ��
    unsigned int length;//˫������ĳ���
    
    node* getNode(unsigned int i)const;//��ȡ˫�������i���ڵ��ָ��(i��1��ʼ��i=0ʱ����ͷָ��)

public:
    D_LinkList();//���캯��
    ~D_LinkList();//��������
    D_LinkList(const D_LinkList& obj);//�������캯��
    D_LinkList<T>& operator=(const D_LinkList& obj);//��ֵ�����

    void clear();//���˫������
    bool isEmpty()const{ return length==0; } //�ж�˫�������Ƿ�Ϊ��
    unsigned int getLength()const{ return length; }//��ȡ˫������ĳ���
    void traverse()const;//����˫������
    T get(unsigned int i)const;//��ȡ˫�������i���ڵ������(i��1��ʼ)
    void set(unsigned int i, T elem);//����i���ڵ����������Ϊelem(1<=i<=length)
    unsigned int find(T elem)const;//�������в���elem, ���ص�һ��elem���ֵ�λ��(����-1��ʾelem������)
    void insert(unsigned int i, T elem);//�ڵ�i���ڵ㴦��������elem(1 <= i <= length+1)
    void push_back(T elem){ insert(length+1, elem); }//��˫������ĩβ��������elem
    T remove(unsigned int i);//ɾ��˫�������i���ڵ�(i��1��ʼ)�������ظýڵ������
    T pop_back();//ɾ��˫������ĩβ�Ľڵ㣬�����ظýڵ������

    void push_arr_head(T arr[], unsigned int n);//ͷ�巨����˫������(nΪ���鳤��)
    void push_arr_tail(T arr[], unsigned int n);//β�巨����˫������(nΪ���鳤��)

    T getTailData();

    void reserve();//��ͷ�巨����˫������
};



#include"D_LinkList.cpp"