#include"LinkQueue.h"
#include<stdexcept>

/**
 * 拷贝构造函数
 */
template<typename T>
LinkQueue<T>::LinkQueue(const LinkQueue &obj){
    node *newnode = new node;//新建一个节点作为首元节点
    newnode->data = obj.front->data;
    newnode->next = nullptr;
    front = newnode;//队头指针指向新节点
    rear = front;//队尾指针指向新节点
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
 * 赋值运算符
 */
template<typename T>
LinkQueue<T>& LinkQueue<T>::operator=(const LinkQueue &obj){
    if(*this!=obj){
        node *newnode = new node;//新建一个节点作为首元节点
        newnode->data = obj.front->data;
        newnode->next = nullptr;
        front = newnode;//队头指针指向新节点
        rear = front;//队尾指针指向新节点
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
 * 清空链队列
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
 * 入队，在队尾插入一个元素
 */
template<typename T>
void LinkQueue<T>::enQueue(const T elem){
    node *newnode = new node;
    newnode->data = elem;
    newnode->next = nullptr;
    //如果链队列为空，入队元素既是队头也是队尾
    if(isEmpty()){
        front = rear = newnode;
        length++;
    }
    //链队列不为空
    else{
        rear->next = newnode;
        rear = newnode;
        length++;
    }
}

/**
 * 出队，并返回队头元素
 */
template<typename T>
T LinkQueue<T>::deQueue(){
    if(isEmpty()) throw std::out_of_range("队列为空");
    //删除队头元素
    node *p = front;
    T data = front->data;
    front = front->next;
    delete p;
    //如果出队后队列为空，就修改rear为nullptr
    if(front == nullptr) rear = nullptr;
    length--;
    return data;
}

/**
 * 获取队头元素
 */
template<typename T>
T LinkQueue<T>::get_front()const{
    if(isEmpty()) throw std::out_of_range("队列为空");
    return front->data;
}