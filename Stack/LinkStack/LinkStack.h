//链栈，Linked stack
//不带头节点

#pragma once

template<typename T>
class LinkStack{
private:
    struct node{
        T data;
        node *next;
    };

    node *top; // 栈顶指针，也是头指针
    unsigned int length; // 链栈中数据个数
    
public:
    LinkStack(); // 构造函数
    ~LinkStack(); // 析构函数
    LinkStack(const LinkStack& obj); // 拷贝构造函数
    LinkStack<T>& operator=(const LinkStack& obj); // 赋值运算符

    void clear(); // 清空栈
    bool isEmpty() const { return top==nullptr; } // 判空
    int getLength() const { return length; } // 获取链栈数据个数
    void push(const T elem); // 入栈
    T pop(); // 出栈，并返回出栈元素
    T get_top() const; // 返回栈顶元素
};



#include"LinkStack.cpp"