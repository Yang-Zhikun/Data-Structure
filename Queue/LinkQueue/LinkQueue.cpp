#include"LinkQueue.h"
#include<stdexcept>

/**
 * �������캯��
 */
template<typename T>
LinkQueue<T>::LinkQueue(const LinkQueue &obj){
    node *newnode = new node;//�½�һ���ڵ���Ϊ��Ԫ�ڵ�
    newnode->data = obj.front->data;
    newnode->next = nullptr;
    front = newnode;//��ͷָ��ָ���½ڵ�
    rear = front;//��βָ��ָ���½ڵ�
    for(node *p = obj.front->next; p!=nullptr; p = p->next){
        node *newnode;
        newnode->data = p->data;
        newnode->next = nullptr;
        rear->next = newnode;
        rear = newnode;
    }
    length = obj.length;
}

/**
 * ��ֵ�����
 */
template<typename T>
LinkQueue<T>& LinkQueue<T>::operator=(const LinkQueue &obj){
    if(*this!=obj){
        node *newnode = new node;//�½�һ���ڵ���Ϊ��Ԫ�ڵ�
        newnode->data = obj.front->data;
        newnode->next = nullptr;
        front = newnode;//��ͷָ��ָ���½ڵ�
        rear = front;//��βָ��ָ���½ڵ�
        for(node *p = obj.front->next; p!=nullptr; p = p->next){
            node *newnode;
            newnode->data = p->data;
            newnode->next = nullptr;
            rear->next = newnode;
            rear = newnode;
        }
        length = obj.length;
    }
    return *this;
}

/**
 * ���������
*/
template<typename T>
void LinkQueue<T>::clear(){
    node *p, *tmp;
    p = front;
    while(p!=nullptr){
        tmp = p;
        p = p->next;
        delete tmp;
    }
    rear = front =nullptr;
    length = 0;
}

/**
 * ��ӣ��ڶ�β����һ��Ԫ��
 */
template<typename T>
void LinkQueue<T>::enQueue(const T elem){
    node *newnode = new node;
    newnode->data = elem;
    newnode->next = nullptr;
    //���������Ϊ�գ����Ԫ�ؼ��Ƕ�ͷҲ�Ƕ�β
    if(isEmpty()){
        front = rear = newnode;
        length++;
    }
    //�����в�Ϊ��
    else{
        rear->next = newnode;
        rear = newnode;
        length++;
    }
}

/**
 * ���ӣ������ض�ͷԪ��
 */
template<typename T>
T LinkQueue<T>::deQueue(){
    if(isEmpty()) throw std::out_of_range("����Ϊ��");
    //ɾ����ͷԪ��
    node *p = front;
    T data = front->data;
    front = front->next;
    delete p;
    //������Ӻ����Ϊ�գ����޸�rearΪnullptr
    if(front == nullptr) rear = nullptr;
    length--;
    return data;
}

/**
 * ��ȡ��ͷԪ��
 */
template<typename T>
T LinkQueue<T>::get_front()const{
    if(isEmpty()) throw std::out_of_range("����Ϊ��");
    return front->data;
}