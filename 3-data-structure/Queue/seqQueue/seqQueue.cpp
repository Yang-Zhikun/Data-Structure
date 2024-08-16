#include"seqQueue.h"
#include<stdexcept>


/**
 * 构造函数
 * @param maxLen 队列的最大长度
 */
template<typename T>
seqQueue<T>::seqQueue(unsigned int maxLen){
    this->maxLen = maxLen;
    data = new T[maxLen];
    front = rear = 0; // 队头的队尾下标相等
}

/**
 * 拷贝构造函数
 */
template<typename T>
seqQueue<T>::seqQueue(const seqQueue<T> &obj){
    data = new T[obj.maxLen];
    for(int i = 0; i<obj.maxLen; i++){
        data[i] = obj.data[i];
    }
    maxLen = obj.maxLen;
    front = obj.front;
    rear = obj.rear;
}

/**
 * 赋值运算符
 */
template<typename T>
seqQueue<T>& seqQueue<T>::operator=(const seqQueue& obj){
    if(*this!=obj){ // 防止自赋值
        data = new T[obj.maxLen];
        for(int i = 0; i<maxLen; i++){
            data[i] = obj.data[i];
        }
        maxLen = obj.maxLen;
        front = obj.front;
        rear = obj.rear;
    }
    return *this;
}

/**
 * 清空队列
 */
template<typename T>
void seqQueue<T>::clear(){
    front = rear = 0;
}

/**
 * 入队
 * @param elem 入队元素
 */
template<typename T>
void seqQueue<T>::enQueue(T elem){
    if(isFull()){
        printf("出问题");
        throw std::out_of_range("队列已满");
    }
    data[rear] = elem; // 将elem插入队列末尾
    rear = (rear+1)%maxLen;
}

/**
 * 出队，并返回队头元素
 */
template<typename T>
T seqQueue<T>::deQueue(){
    if(isEmpty())
        throw std::out_of_range("队列为空");
    T tmp = data[front];
    front = (front+1)%maxLen;
    return tmp;
}

/**
 * 返回队头元素
 */
template<typename T>
T seqQueue<T>::get_front()const{
    if(isEmpty())
        throw std::out_of_range("队列为空");
    return data[front];
}