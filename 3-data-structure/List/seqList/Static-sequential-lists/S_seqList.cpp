#include"S_seqList.h"
#include<iostream>
#include<stdexcept>
using namespace std;


template<typename T>
//���캯��
S_seqList<T>::S_seqList(){
    length = 0;
}

template<typename T>
//�������캯��
S_seqList<T>::S_seqList(const S_seqList& obj){
    for(int i=0; i < obj.length; i++){
        data[i] = obj.data[i];
    }
    length = obj.length;
}

template<typename T>
//��ֵ�����
S_seqList<T>& S_seqList<T>::operator=(const S_seqList & obj){
    if(*this!=obj){//��ֹ�Ը�ֵ
        for(int i=0; i < obj.length; i++){
            data[i] = obj.data[i];
        }
        length = obj.length;
    }
    return *this;
}

template<typename T>
//����˳���
void S_seqList<T>::traverse() const{
    for(int i=0; i<length; i++){
        cout<<data[i]<<' ';
    }
    cout<<'\n';
}

template<typename T>
//�����[]����ȡ˳���λ��i������(0<=i<length)
T S_seqList<T>::operator[](const unsigned int i) const{
    if(i>=length || i<0){
        throw std::out_of_range("�����λ��i����ȷ");
    }
    else{
        return data[i];
    }
}

template<typename T>
//�����[]������˳���λ��i�����ݵ�����(0<=i<length)
T& S_seqList<T>::operator[](const unsigned int i){
    if(i>=length || i<0){
        throw std::out_of_range("�����λ��i����ȷ");
    }
    else{
        return data[i];
    }
}

template<typename T>
//��˳���λ��i������һ������(0<=i<=length)
void S_seqList<T>::insert(const unsigned int i, const T elem){
    if(length == MAXLEN)
        throw std::out_of_range("˳�������");
    else if(i<0 || i>length)
        throw std::out_of_range("�����λ��i���Ϸ�");
    else{}
    //��λ��i������ݶ�����һ��λ��
    for(int j = length; j>i; j--){
        data[j] = data[j-1];
    }
    data[i] = elem;//��������
    length++;//˳����ȼ�1
}

template<typename T>
//ɾ��˳���λ��i������(0<=i<length)
void S_seqList<T>::remove(const unsigned int i){
    if(i>=length || i<0)
        throw std::out_of_range("�����λ��i����ȷ");
    //��Ҫɾ�������ݺ��������ȫ��ǰ��һ��λ�ã�����Ҫɾ��������
    for(int j=i; j<length-1; j++){
        data[j] = data[j+1];
    }
    length--;//˳����ȼ�1
}

template<typename T>
//����˳���
void S_seqList<T>::reserve(){
    if(length == 0)
        return;
    //���������м�������ǽ���
    T tmp;
    int i=0, j=length-1;//ͷ��β��������ָ��
    while(i<j){
        //����i,j��ָ����
        tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
        //��������ָ�����м��ƶ�
        i++;
        j--;
    }
}
