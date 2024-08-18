#include<stdio.h>
#include<iostream>
#include<stdexcept>
//顺序队列(循环队列) 


template<typename T>
class seqQueue{
private:
    T *data;
    unsigned int maxLen;//数据的最大长度
    unsigned int front; //队首下标
    unsigned int rear;  //队尾下标
    
    void resize();//扩容
    
public:
    seqQueue(unsigned int maxLen = 1); // 构造函数 maxLen是队列的最大长度
    ~seqQueue() { delete[] data; } // 析构函数
    seqQueue(const seqQueue<T> &obj); //拷贝构造函数
    seqQueue<T>& operator=(const seqQueue &obj); // 赋值运算符
    
    void clear(); // 清空队列
    bool isEmpty()const { return front==rear; } // 判空
    bool isFull()const { return (rear+1)%maxLen==front; } //判满
    unsigned int getLength()const { return (rear-front+maxLen)%maxLen; } // 获取队列长度
    void enQueue(T elem); // 入队
    T deQueue(); //出队，并返回队头元素
    T get_front()const; // 获取队头元素
    
    void print() const; //打印队列(从队头到队尾)，用于调试
    unsigned int getMaxLen() const { return maxLen; }//返回队列最大长度
};

//采用牺牲一个储存空间以判断队满
//约定front指向队首元素，rear指向队尾元素的后一个位置
/*判断队空的条件front==rear
/*判断队满的条件(rear+1)%maxLen==front
    *原因当rear的下一个是front时即是队满
    *如果rear+1小于maxLen时，(rear+1)%maxLen等于rear+1
    *如果rear+1大于maxLen时，(rear+1)%maxLen等于rear+1-maxLen
/*求队列长度：(rear-front+maxLen)%maxLen
    *原因rear-front即是队列长度
    *当rear-front小于0时，加上maxLen就是队列长度(小于等于maxLen)，模maxLen后是原数
    *当rear-front大于0时，就是队列长度，加上maxLen后又模去就是原数
/*入队：rear = (rear+1)%maxLen
    *原因：从队尾插入一个元素，rear向后移一位，%maxLen防止超过最大下标
/*出队：front = (front+1)%maxLen
    *原因：删除队头元素，front向后移一位，%maxLen防止超过最大下标
*/




template<typename T>//构造函数 maxLen是队列的最大长度
seqQueue<T>::seqQueue(unsigned int maxLen){
    this->maxLen = maxLen;
    data = new T[maxLen];
    front = rear = 0; // 队头的队尾下标相等
}

template<typename T>//拷贝构造函数
seqQueue<T>::seqQueue(const seqQueue<T> &obj){
    data = new T[obj.maxLen];
    for(int i = 0; i<obj.maxLen; i++){
        data[i] = obj.data[i];
    }
    maxLen = obj.maxLen;
    front = obj.front;
    rear = obj.rear;
}

template<typename T>//赋值运算符
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


template<typename T>//清空队列
void seqQueue<T>::clear(){
    front = rear = 0;
}

template<typename T>//入队
void seqQueue<T>::enQueue(T elem){
    if(isFull()){
        resize();
    }
    data[rear] = elem; // 将elem插入队列末尾
    rear = (rear+1)%maxLen;
}

template<typename T> // 出队，并返回队头元素
T seqQueue<T>::deQueue(){
    if(isEmpty())
        throw std::out_of_range("队列为空");
    T tmp = data[front];
    front = (front+1)%maxLen;
    return tmp;
}

template<typename T> // 返回队头元素
T seqQueue<T>::get_front()const{
    if(isEmpty())
        throw std::out_of_range("队列为空");
    return data[front];
}

template<typename T>
void seqQueue<T>::print()const {
    for(unsigned int i = front; i < rear; i = (i + 1) % maxLen){
        std::cout << data[i] << ' ';
    }
    std::cout<<'\n';
}


template<typename T>//扩容
void seqQueue<T>::resize() {
    unsigned int length = getLength();
    T *data2 = new T[length * 2]; //分配两倍的空间
    //将原来data的数据复制到data2
    for(unsigned int i = 0; i < length; i++){
        data2[i] = data[(front + i) % maxLen]; //(front+1)%maxLen防止越界
    }
    //更新成员变量
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