#include"seqStack.h"
#include<stdexcept>

/**
 * 构造函数
 */
template<typename T>
seqStack<T>::seqStack(const  int init_len){
    maxlen = init_len;
    data = new T[maxlen];
    top = -1;//初始为空栈
}

/**
 * 拷贝构造函数
 */
template<typename T>
seqStack<T>::seqStack(const seqStack & obj){
    maxlen = obj.maxlen;
    data = new T[maxlen];//申请新内存
    //复制obj的数据
    for(int i = 0; i < obj.top+1; i++){
        data[i] = obj.data[i];
    }
    top = obj.top;
}

/**
 * 赋值运算符
 */
template<typename T>
seqStack<T>& seqStack<T>::operator=(const seqStack & obj){
    if(*this!=obj){//防止自赋值
        maxlen = obj.maxLen;
        data = new T[maxlen];//申请新内存
        //复制obj的数据
        for(int i = 0; i<top+1; i++){
            data[i] = obj.data[i];
        }
        top = obj.top;
    }
    return *this;
}

/**
 * 入栈
 * @param elem 入栈的元素
 */
template<typename T>
void seqStack<T>::push(const T elem){
    if(top+1 == maxlen)
        throw std::out_of_range("栈已满");
    data[top+1] = elem;
    top++;
}

/**
 * 出栈，并返回出栈元素
 */
template<typename T>
T seqStack<T>::pop(){
    if(top == -1)
        throw std::out_of_range("栈为空");
    T tmp = data[top];//保存栈顶元素
    top--;
    return tmp;
}

/**
 * 获取栈顶元素
 */
template<typename T>
T seqStack<T>::get_top() const{
    if(top == -1)
        throw std::out_of_range("栈为空");
    return data[top];
}
