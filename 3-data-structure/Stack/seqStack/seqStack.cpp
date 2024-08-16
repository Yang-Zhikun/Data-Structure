#include"seqStack.h"
#include<stdexcept>

/**
 * ���캯��
 */
template<typename T>
seqStack<T>::seqStack(const  int init_len){
    maxlen = init_len;
    data = new T[maxlen];
    top = -1;//��ʼΪ��ջ
}

/**
 * �������캯��
 */
template<typename T>
seqStack<T>::seqStack(const seqStack & obj){
    maxlen = obj.maxlen;
    data = new T[maxlen];//�������ڴ�
    //����obj������
    for(int i = 0; i < obj.top+1; i++){
        data[i] = obj.data[i];
    }
    top = obj.top;
}

/**
 * ��ֵ�����
 */
template<typename T>
seqStack<T>& seqStack<T>::operator=(const seqStack & obj){
    if(*this!=obj){//��ֹ�Ը�ֵ
        maxlen = obj.maxLen;
        data = new T[maxlen];//�������ڴ�
        //����obj������
        for(int i = 0; i<top+1; i++){
            data[i] = obj.data[i];
        }
        top = obj.top;
    }
    return *this;
}

/**
 * ��ջ
 * @param elem ��ջ��Ԫ��
 */
template<typename T>
void seqStack<T>::push(const T elem){
    if(top+1 == maxlen)
        throw std::out_of_range("ջ����");
    data[top+1] = elem;
    top++;
}

/**
 * ��ջ�������س�ջԪ��
 */
template<typename T>
T seqStack<T>::pop(){
    if(top == -1)
        throw std::out_of_range("ջΪ��");
    T tmp = data[top];//����ջ��Ԫ��
    top--;
    return tmp;
}

/**
 * ��ȡջ��Ԫ��
 */
template<typename T>
T seqStack<T>::get_top() const{
    if(top == -1)
        throw std::out_of_range("ջΪ��");
    return data[top];
}
