#include "D_LinkList.h"
#include<iostream>
using namespace std;

template<typename T>//构造函数
D_LinkList<T>::D_LinkList(){
    head = new node;
    head->data = 0;
    head->prev = nullptr;
    head->next = nullptr;
    tail = head;
    length = 0;
}

template<typename T>//析构函数
D_LinkList<T>::~D_LinkList(){
    clear();
    delete head;
}

template<typename T>//拷贝构造函数
D_LinkList<T>::D_LinkList(const D_LinkList & obj){
    head = new node;
    head->data = 0;
    head->prev = nullptr;
    head->next = nullptr;
    tail = head;
    for(node* p = obj.head->next; p!=nullptr; p = p->next){
        node *newnode = new node;
        newnode->data = p->data;
        newnode->next = nullptr;
        tail->next = newnode;
        tail = newnode;
    }
    length = obj.length;
}

template<typename T>
D_LinkList<T>& D_LinkList<T>::operator=(const D_LinkList & obj){
    if(*this!=obj){//防止自赋值
        head = new node;
        head->data = 0;
        head->prev = nullptr;
        head->next = nullptr;
        tail = head;
        for(node* p = obj.head->next; p!=nullptr; p = p->next){
            node *newnode = new node;
            newnode->data = p->data;
            newnode->next = nullptr;
            tail->next = newnode;
            tail = newnode;
        }
        length = obj.length;
    }
    return *this;
}
