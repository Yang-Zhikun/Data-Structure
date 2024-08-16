#include"LinkStack.h"
#include<stdexcept>

/**
 * 构造函数
 */
template<typename T>
LinkStack<T>::LinkStack(){
    top = nullptr;
    length = 0;
}

/**
 * 析构函数
 */
template<typename T>
LinkStack<T>::~LinkStack(){
    clear();
}

/**
 * 拷贝构造函数
 */
template<typename T>
LinkStack<T>::LinkStack(const LinkStack & obj){
    top = nullptr;
    node *tail = top;//尾指针
    for(node *p = obj.top; p!=nullptr; p = p->next){
        node * newnode = new node;
        newnode->data = p->data;
        newnode->next = nullptr;
        tail->next = newnode;
        tail = newnode;
    }
}

/**
 * 赋值运算符
 */
template<typename T>
LinkStack<T>& LinkStack<T>::operator=(const LinkStack & obj){
    if(*this!=obj){ // 防止自赋值
        top = nullptr;
        node *tail = top;//尾指针
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
 * 清空栈
 */
template<typename T>
void LinkStack<T>::clear(){
    node *p;
    while(top!=nullptr){
        p = top; // p指向当前的栈顶元素
        top = top->next; // top向后移动
        delete p;
    }
    length = 0;
}

/**
 * 入栈
 * @param elem 入栈的元素
 */
template<typename T>
void LinkStack<T>::push(const T elem){
    node *newnode = new node;
    newnode->data = elem;
    newnode->next = top; // newnode的next指向原来的栈顶元素
    top = newnode; // top头指针指向newnode, newnode成为新的栈顶元素
    length++;
}

/**
 * 出栈，并返回出栈元素
 */
template<typename T>
T LinkStack<T>::pop(){
    if(top == nullptr)
        throw std::out_of_range("栈为空");
    T tmp = top->data;
    node *p = top;//暂存栈顶节点
    top= top->next;//top指向栈顶元素的后继，即向后移动
    delete p;
    length--;
    return tmp;
}

/**
 * 返回栈顶元素
 */
template<typename T>
T LinkStack<T>::get_top() const{
    if(top == nullptr)
        throw std::out_of_range("栈为空");
    return top->data;
}