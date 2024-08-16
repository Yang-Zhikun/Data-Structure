//顺序栈，Static sequential stack
//不能自动扩容，定义后长度固定

#pragma once

template<typename T>
class seqStack{
private:
    T *data;//存放栈数据的数组基地址
    int top; // 栈顶元素的下标，== -1时表示栈空
    int maxlen; // 栈的栈的最大长度，即数组的大小

public:
    seqStack(const int init_len = 100);//构造函数，init_len是栈的最大长度(数组的大小)
    ~seqStack() { delete[] data; } //析构函数
    seqStack(const seqStack& obj);//拷贝构造函数
    seqStack<T>& operator=(const seqStack& obj);//赋值运算符

    void clear() { top = -1; } //清空栈
    bool isEmpty()const { return top == -1;} //判空
    int getLength()const { return top+1; } //获取栈的数据个数
    void push(const T elem); //入栈
    T pop(); //出栈，并返回出栈元素
    T get_top()const; //获取栈顶元素
};


#include"seqStack.cpp"