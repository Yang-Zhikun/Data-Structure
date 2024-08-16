//双向链表(带头节点)，参照单链表
//Doubly linked lists

#pragma once

template<typename T>
class D_LinkList{
private:
    struct node{//双向链表的一个节点
        T data;//数据域，存放数据
        node *prev;//指针域，存放前驱的地址
        node *next;//指针域，存放后继的地址
    };

    node *head;//头指针
    node *tail;//尾指针
    unsigned int length;//双向链表的长度
    
    node* getNode(unsigned int i)const;//获取双向链表第i个节点的指针(i从1开始，i=0时返回头指针)

public:
    D_LinkList();//构造函数
    ~D_LinkList();//析构函数
    D_LinkList(const D_LinkList& obj);//拷贝构造函数
    D_LinkList<T>& operator=(const D_LinkList& obj);//赋值运算符

    void clear();//清空双向链表
    bool isEmpty()const{ return length==0; } //判断双向链表是否为空
    unsigned int getLength()const{ return length; }//获取双向链表的长度
    void traverse()const;//遍历双向链表
    T get(unsigned int i)const;//获取双向链表第i个节点的数据(i从1开始)
    void set(unsigned int i, T elem);//将第i个节点的数据设置为elem(1<=i<=length)
    unsigned int find(T elem)const;//在链表中查找elem, 返回第一个elem出现的位置(返回-1表示elem不存在)
    void insert(unsigned int i, T elem);//在第i个节点处插入数据elem(1 <= i <= length+1)
    void push_back(T elem){ insert(length+1, elem); }//在双向链表末尾插入数据elem
    T remove(unsigned int i);//删除双向链表第i个节点(i从1开始)，并返回该节点的数据
    T pop_back();//删除双向链表末尾的节点，并返回该节点的数据

    void push_arr_head(T arr[], unsigned int n);//头插法创建双向链表(n为数组长度)
    void push_arr_tail(T arr[], unsigned int n);//尾插法创建双向链表(n为数组长度)

    T getTailData();

    void reserve();//用头插法逆置双向链表
};



#include"D_LinkList.cpp"