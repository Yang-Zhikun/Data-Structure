//������(��ͷ���)
//Single-linked lists

#pragma once
using namespace std;

template<typename T>
class S_LinkList{
private:
    struct node{//һ��������ڵ�
        T data;//�����򣬴������
        node *next;//ָ���򣬴����һ���ڵ�ĵ�ַ
    };

    node *head;//�������ͷָ��
    node *tail;//�������βָ��
    unsigned int length;//������ĵ�ǰ����

    node* getNode(unsigned int i)const;//��ȡ�������i���ڵ��ָ��(i��1��ʼ��i=0ʱ����ͷָ��)

public:
    S_LinkList();//���캯��
    ~S_LinkList();//��������
    S_LinkList(const S_LinkList& obj);//�������캯��
    S_LinkList<T>& operator=(const S_LinkList &obj);//��ֵ�����
   
    void clear();//��յ�����
    bool isEmpty()const{ return length==0; } //�жϵ������Ƿ�Ϊ��
    unsigned int getLength()const{ return length; }//��ȡ������ĳ���
    void traverse()const;//����������
    T get(unsigned int i)const;//��ȡ�������i���ڵ������(i��1��ʼ)
    void set(unsigned int i, T elem);//����i���ڵ����������Ϊelem(1<=i<=length)
    unsigned int find(T elem)const;//�������в���elem, ���ص�һ��elem���ֵ�λ��(����-1��ʾ����-1��ʾelem������)
    void insert(unsigned int i, T elem);//�ڵ�i���ڵ㴦��������elem(1 <= i <= length+1)
    void push_back(T elem){ insert(length+1, elem); }//�ڵ�����ĩβ��������elem
    T remove(unsigned int i);//ɾ���������i���ڵ�(i��1��ʼ)�������ظýڵ������
    T pop_back();//ɾ��������ĩβ�Ľڵ㣬�����ظýڵ������

    void push_arr_head(T arr[], unsigned int n);//ͷ�巨����������(nΪ���鳤��)
    void push_arr_tail(T arr[], unsigned int n);//β�巨����������(nΪ���鳤��)

    T getTailData();

    void reserve();//��ͷ�巨���õ�����

};


#include"S_LinkList.cpp"