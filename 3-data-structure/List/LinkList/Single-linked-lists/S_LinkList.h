//单链表(带头结点)
//Single-linked lists

#pragma once
using namespace std;

template<typename T>
class S_LinkList{
private:
    struct node{//一个单链表节点
        T data;//数据域，存放数据
        node *next;//指针域，存放下一个节点的地址
    };

    node *head;//单链表的头指针
    node *tail;//单链表的尾指针
    unsigned int length;//单链表的当前长度

    node* getNode(unsigned int i)const;//获取单链表第i个节点的指针(i从1开始，i=0时返回头指针)

public:
    S_LinkList();//构造函数
    ~S_LinkList();//析构函数
    S_LinkList(const S_LinkList& obj);//拷贝构造函数
    S_LinkList<T>& operator=(const S_LinkList &obj);//赋值运算符
   
    void clear();//清空单链表
    bool isEmpty()const{ return length==0; } //判断单链表是否为空
    unsigned int getLength()const{ return length; }//获取单链表的长度
    void traverse()const;//遍历单链表
    T get(unsigned int i)const;//获取单链表第i个节点的数据(i从1开始)
    void set(unsigned int i, T elem);//将第i个节点的数据设置为elem(1<=i<=length)
    unsigned int find(T elem)const;//在链表中查找elem, 返回第一个elem出现的位置(返回-1表示返回-1表示elem不存在)
    void insert(unsigned int i, T elem);//在第i个节点处插入数据elem(1 <= i <= length+1)
    void push_back(T elem){ insert(length+1, elem); }//在单链表末尾插入数据elem
    T remove(unsigned int i);//删除单链表第i个节点(i从1开始)，并返回该节点的数据
    T pop_back();//删除单链表末尾的节点，并返回该节点的数据

    void push_arr_head(T arr[], unsigned int n);//头插法创建单链表(n为数组长度)
    void push_arr_tail(T arr[], unsigned int n);//尾插法创建单链表(n为数组长度)

    T getTailData();

    void reserve();//用头插法逆置单链表

};


#include"S_LinkList.cpp"