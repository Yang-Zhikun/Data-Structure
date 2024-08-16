#include"seqQueue.h"
#include<stdexcept>


/**
 * ���캯��
 * @param maxLen ���е���󳤶�
 */
template<typename T>
seqQueue<T>::seqQueue(unsigned int maxLen){
    this->maxLen = maxLen;
    data = new T[maxLen];
    front = rear = 0; // ��ͷ�Ķ�β�±����
}

/**
 * �������캯��
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
 * ��ֵ�����
 */
template<typename T>
seqQueue<T>& seqQueue<T>::operator=(const seqQueue& obj){
    if(*this!=obj){ // ��ֹ�Ը�ֵ
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
 * ��ն���
 */
template<typename T>
void seqQueue<T>::clear(){
    front = rear = 0;
}

/**
 * ���
 * @param elem ���Ԫ��
 */
template<typename T>
void seqQueue<T>::enQueue(T elem){
    if(isFull()){
        printf("������");
        throw std::out_of_range("��������");
    }
    data[rear] = elem; // ��elem�������ĩβ
    rear = (rear+1)%maxLen;
}

/**
 * ���ӣ������ض�ͷԪ��
 */
template<typename T>
T seqQueue<T>::deQueue(){
    if(isEmpty())
        throw std::out_of_range("����Ϊ��");
    T tmp = data[front];
    front = (front+1)%maxLen;
    return tmp;
}

/**
 * ���ض�ͷԪ��
 */
template<typename T>
T seqQueue<T>::get_front()const{
    if(isEmpty())
        throw std::out_of_range("����Ϊ��");
    return data[front];
}