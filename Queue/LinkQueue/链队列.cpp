#include<stdio.h>
#include<stdexcept>
using namespace std;

//链队列

template<typename T>
class LinkQueue{
private:
    struct node{ //链队列节点
        T data;
        node *next;
    };
    
    node *front; //链队列的队头指针
    node *rear;  //链队列的队尾指针
    unsigned int length; // 链队列的长度
    
public:
    LinkQueue() { front = rear = nullptr; length = 0; }
    ~LinkQueue() { clear(); }
    LinkQueue(const LinkQueue &obj);
    LinkQueue<T>& operator=(const LinkQueue &obj);
    
    void clear();
    unsigned int getLength()const { return length; }  // 获取链队列的长度
    bool empty()const { return length == 0; }  //判空
    void enQueue(const T elem); //入队，在队尾插入一个元素
    T deQueue(); // 出队，并返回出队的数据
    T get_front()const; //获取队头数据
};



template<typename T>//拷贝构造函数
LinkQueue<T>::LinkQueue(const LinkQueue &obj){
    node *newnode = new node;//新建一个节点作为首元节点
    newnode->data = obj.front->data;
    newnode->next = nullptr;
    front = newnode;//队头指针指向新节点
    rear = front;//队尾指针指向新节点
    for(node *p = obj.front->next; p!=nullptr; p = p->next){
        node *newnode;
        newnode->data = p->data;
        newnode->next = nullptr;
        rear->next = newnode;
        rear = newnode;
    }
    length = obj.length;
}

template<typename T>//赋值运算符
LinkQueue<T>& LinkQueue<T>::operator=(const LinkQueue &obj){
    if(*this!=obj){
        node *newnode = new node;//新建一个节点作为首元节点
        newnode->data = obj.front->data;
        newnode->next = nullptr;
        front = newnode;//队头指针指向新节点
        rear = front;//队尾指针指向新节点
        for(node *p = obj.front->next; p!=nullptr; p = p->next){
            node *newnode;
            newnode->data = p->data;
            newnode->next = nullptr;
            rear->next = newnode;
            rear = newnode;
        }
        length = obj.length;
    }
    return *this;
}

template<typename T>//清空链队列
void LinkQueue<T>::clear(){
    node *p, *tmp;
    p = front;
    while(p!=nullptr){
        tmp = p;
        p = p->next;
        delete tmp;
    }
    rear = front =nullptr;
    length = 0;
}

template<typename T>//入队，在队尾插入一个元素
void LinkQueue<T>::enQueue(const T elem){
    node *newnode = new node;
    newnode->data = elem;
    newnode->next = nullptr;
    //如果链队列为空，入队元素既是队头也是队尾
    if(empty()){
        front = rear = newnode;
        length++;
    }
    //链队列不为空
    else{
        rear->next = newnode;
        rear = newnode;
        length++;
    }
}

template<typename T>//出队，并返回队头元素
T LinkQueue<T>::deQueue(){
    if(empty()) throw std::out_of_range("队列为空");
    //删除队头元素
    node *p = front;
    T data = front->data;
    front = front->next;
    delete p;
    //如果出队后队列为空，就修改rear为nullptr
    if(front == nullptr) rear = nullptr;
    length--;
    return data;
}

template<typename T>//获取队头元素
T LinkQueue<T>::get_front()const{
    if(empty()) throw std::out_of_range("队列为空");
    return front->data;
}






int main(){
    LinkQueue<double> q;
    printf("length:%d, empty%d\n",q.getLength(), q.empty());
    for(int i=1;i<=100;i++){
        q.enQueue(3.999*i);
        printf("length:%d, empty:%d, get_front:%.6lf\n", q.getLength(),q.empty(),q.get_front());
    }
    for(int i=1;i<=100;i++){
        printf("deQueue:%.6lf, ", q.deQueue());
        printf("length:%d, empty:%d\n", q.getLength(),q.empty());
    }
    system("pause");
}