//˳�����(ѭ������) Sequential queue
#pragma once

template<typename T>
class seqQueue{
private:
    T *data;
    unsigned int maxLen;//���ݵ���󳤶�
    unsigned int front; //�����±�
    unsigned int rear;  //��β�±�

public:
    seqQueue(unsigned int maxLen = 100); // ���캯�� maxLen�Ƕ��е���󳤶�
    ~seqQueue(){ delete[] data; } // ��������
    seqQueue(const seqQueue<T> &obj); //�������캯��
    seqQueue<T>& operator=(const seqQueue &obj); // ��ֵ�����

    void clear(); // ��ն���
    bool isEmpty()const{ return front==rear; } // �п�
    bool isFull()const{ return (rear+1)%maxLen==front; } //����
    unsigned int getLength()const{ return (rear-front+maxLen)%maxLen; } // ��ȡ���г���
    void enQueue(T elem); // ���
    T deQueue(); //���ӣ������ض�ͷԪ��
    T get_front()const; // ��ȡ��ͷԪ��
};

#include"seqQueue.cpp"

//��������һ������ռ����ж϶���
//Լ��frontָ�����Ԫ�أ�rearָ���βԪ�صĺ�һ��λ��
/*�ж϶ӿյ�����front==rear
/*�ж϶���������(rear+1)%maxLen==front
    *ԭ��rear����һ����frontʱ���Ƕ���
    *���rear+1С��maxLenʱ��(rear+1)%maxLen����rear+1
    *���rear+1����maxLenʱ��(rear+1)%maxLen����rear+1-maxLen
/*����г��ȣ�(rear-front+maxLen)%maxLen
    *ԭ��rear-front���Ƕ��г���
    *��rear-frontС��0ʱ������maxLen���Ƕ��г���(С�ڵ���maxLen)��ģmaxLen����ԭ��
    *��rear-front����0ʱ�����Ƕ��г��ȣ�����maxLen����ģȥ����ԭ��
/*��ӣ�rear = (rear+1)%maxLen
    *ԭ�򣺴Ӷ�β����һ��Ԫ�أ�rear�����һλ��%maxLen��ֹ��������±�
/*���ӣ�front = (front+1)%maxLen
    *ԭ��ɾ����ͷԪ�أ�front�����һλ��%maxLen��ֹ��������±�
*/