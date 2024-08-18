#include<stdio.h>
#include<iostream>
#include<stdexcept>
//˳�����(ѭ������) 


template<typename T>
class seqQueue{
private:
    T *data;
    unsigned int maxLen;//���ݵ���󳤶�
    unsigned int front; //�����±�
    unsigned int rear;  //��β�±�
    
    void resize();//����
    
public:
    seqQueue(unsigned int maxLen = 1); // ���캯�� maxLen�Ƕ��е���󳤶�
    ~seqQueue() { delete[] data; } // ��������
    seqQueue(const seqQueue<T> &obj); //�������캯��
    seqQueue<T>& operator=(const seqQueue &obj); // ��ֵ�����
    
    void clear(); // ��ն���
    bool isEmpty()const { return front==rear; } // �п�
    bool isFull()const { return (rear+1)%maxLen==front; } //����
    unsigned int getLength()const { return (rear-front+maxLen)%maxLen; } // ��ȡ���г���
    void enQueue(T elem); // ���
    T deQueue(); //���ӣ������ض�ͷԪ��
    T get_front()const; // ��ȡ��ͷԪ��
    
    void print() const; //��ӡ����(�Ӷ�ͷ����β)�����ڵ���
    unsigned int getMaxLen() const { return maxLen; }//���ض�����󳤶�
};

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




template<typename T>//���캯�� maxLen�Ƕ��е���󳤶�
seqQueue<T>::seqQueue(unsigned int maxLen){
    this->maxLen = maxLen;
    data = new T[maxLen];
    front = rear = 0; // ��ͷ�Ķ�β�±����
}

template<typename T>//�������캯��
seqQueue<T>::seqQueue(const seqQueue<T> &obj){
    data = new T[obj.maxLen];
    for(int i = 0; i<obj.maxLen; i++){
        data[i] = obj.data[i];
    }
    maxLen = obj.maxLen;
    front = obj.front;
    rear = obj.rear;
}

template<typename T>//��ֵ�����
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


template<typename T>//��ն���
void seqQueue<T>::clear(){
    front = rear = 0;
}

template<typename T>//���
void seqQueue<T>::enQueue(T elem){
    if(isFull()){
        resize();
    }
    data[rear] = elem; // ��elem�������ĩβ
    rear = (rear+1)%maxLen;
}

template<typename T> // ���ӣ������ض�ͷԪ��
T seqQueue<T>::deQueue(){
    if(isEmpty())
        throw std::out_of_range("����Ϊ��");
    T tmp = data[front];
    front = (front+1)%maxLen;
    return tmp;
}

template<typename T> // ���ض�ͷԪ��
T seqQueue<T>::get_front()const{
    if(isEmpty())
        throw std::out_of_range("����Ϊ��");
    return data[front];
}

template<typename T>
void seqQueue<T>::print()const {
    for(unsigned int i = front; i < rear; i = (i + 1) % maxLen){
        std::cout << data[i] << ' ';
    }
    std::cout<<'\n';
}


template<typename T>//����
void seqQueue<T>::resize() {
    unsigned int length = getLength();
    T *data2 = new T[length * 2]; //���������Ŀռ�
    //��ԭ��data�����ݸ��Ƶ�data2
    for(unsigned int i = 0; i < length; i++){
        data2[i] = data[(front + i) % maxLen]; //(front+1)%maxLen��ֹԽ��
    }
    //���³�Ա����
    front = 0;
    rear = length;
    delete[] data;
    data = data2;
    maxLen = maxLen * 2;
}





int main(){
    seqQueue<int> q;
    printf("isEmpty:%d, isFull:%d, length:%d, maxLen:%d\n", q.isEmpty(), q.isFull(), q.getLength(), q.getMaxLen());
    for(int i=1;i<=99;i++){
        q.enQueue(i);
        q.print();
        printf("isEmpty:%d, isFull:%d, length:%d, maxLen:%d, front:%d\n\n\n", q.isEmpty(), q.isFull(), q.getLength(), q.getMaxLen(), q.get_front());
        
    }
    for(int i=1;i<=99;i++){
        printf("deQueue: %d\n",q.deQueue());
        q.print();
        printf("isEmpty:%d, isFull:%d, length:%d, maxLen:%d,\n\n", q.isEmpty(), q.isFull(), q.getLength(), q.getMaxLen());
    }
}