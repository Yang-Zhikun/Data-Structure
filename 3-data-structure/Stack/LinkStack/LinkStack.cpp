#include"LinkStack.h"
#include<stdexcept>

/**
 * ���캯��
 */
template<typename T>
LinkStack<T>::LinkStack(){
    top = nullptr;
    length = 0;
}

/**
 * ��������
 */
template<typename T>
LinkStack<T>::~LinkStack(){
    clear();
}

/**
 * �������캯��
 */
template<typename T>
LinkStack<T>::LinkStack(const LinkStack & obj){
    top = nullptr;
    node *tail = top;//βָ��
    for(node *p = obj.top; p!=nullptr; p = p->next){
        node * newnode = new node;
        newnode->data = p->data;
        newnode->next = nullptr;
        tail->next = newnode;
        tail = newnode;
    }
}

/**
 * ��ֵ�����
 */
template<typename T>
LinkStack<T>& LinkStack<T>::operator=(const LinkStack & obj){
    if(*this!=obj){ // ��ֹ�Ը�ֵ
        top = nullptr;
        node *tail = top;//βָ��
        for(node *p = obj.top; p!=nullptr; p = p->next){
            node * newnode = new node;
            newnode->data = p->data;
            newnode->next = nullptr;
            tail->next = newnode;
            tail = newnode;
        }
    }
}

/**
 * ���ջ
 */
template<typename T>
void LinkStack<T>::clear(){
    node *p;
    while(top!=nullptr){
        p = top; // pָ��ǰ��ջ��Ԫ��
        top = top->next; // top����ƶ�
        delete p;
    }
    length = 0;
}

/**
 * ��ջ
 * @param elem ��ջ��Ԫ��
 */
template<typename T>
void LinkStack<T>::push(const T elem){
    node *newnode = new node;
    newnode->data = elem;
    newnode->next = top; // newnode��nextָ��ԭ����ջ��Ԫ��
    top = newnode; // topͷָ��ָ��newnode, newnode��Ϊ�µ�ջ��Ԫ��
    length++;
}

/**
 * ��ջ�������س�ջԪ��
 */
template<typename T>
T LinkStack<T>::pop(){
    if(top == nullptr)
        throw std::out_of_range("ջΪ��");
    T tmp = top->data;
    node *p = top;//�ݴ�ջ���ڵ�
    top= top->next;//topָ��ջ��Ԫ�صĺ�̣�������ƶ�
    delete p;
    length--;
    return tmp;
}

/**
 * ����ջ��Ԫ��
 */
template<typename T>
T LinkStack<T>::get_top() const{
    if(top == nullptr)
        throw std::out_of_range("ջΪ��");
    return top->data;
}