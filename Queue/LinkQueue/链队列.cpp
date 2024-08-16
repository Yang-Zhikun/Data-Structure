#include<stdio.h>
#include<stdexcept>
using namespace std;

//������

template<typename T>
class LinkQueue{
private:
    struct node{ //�����нڵ�
        T data;
        node *next;
    };
    
    node *front; //�����еĶ�ͷָ��
    node *rear;  //�����еĶ�βָ��
    unsigned int length; // �����еĳ���
    
public:
    LinkQueue() { front = rear = nullptr; length = 0; }
    ~LinkQueue() { clear(); }
    LinkQueue(const LinkQueue &obj);
    LinkQueue<T>& operator=(const LinkQueue &obj);
    
    void clear();
    unsigned int getLength()const { return length; }  // ��ȡ�����еĳ���
    bool empty()const { return length == 0; }  //�п�
    void enQueue(const T elem); //��ӣ��ڶ�β����һ��Ԫ��
    T deQueue(); // ���ӣ������س��ӵ�����
    T get_front()const; //��ȡ��ͷ����
};



template<typename T>//�������캯��
LinkQueue<T>::LinkQueue(const LinkQueue &obj){
    node *newnode = new node;//�½�һ���ڵ���Ϊ��Ԫ�ڵ�
    newnode->data = obj.front->data;
    newnode->next = nullptr;
    front = newnode;//��ͷָ��ָ���½ڵ�
    rear = front;//��βָ��ָ���½ڵ�
    for(node *p = obj.front->next; p!=nullptr; p = p->next){
        node *newnode;
        newnode->data = p->data;
        newnode->next = nullptr;
        rear->next = newnode;
        rear = newnode;
    }
    length = obj.length;
}

template<typename T>//��ֵ�����
LinkQueue<T>& LinkQueue<T>::operator=(const LinkQueue &obj){
    if(*this!=obj){
        node *newnode = new node;//�½�һ���ڵ���Ϊ��Ԫ�ڵ�
        newnode->data = obj.front->data;
        newnode->next = nullptr;
        front = newnode;//��ͷָ��ָ���½ڵ�
        rear = front;//��βָ��ָ���½ڵ�
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

template<typename T>//���������
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

template<typename T>//��ӣ��ڶ�β����һ��Ԫ��
void LinkQueue<T>::enQueue(const T elem){
    node *newnode = new node;
    newnode->data = elem;
    newnode->next = nullptr;
    //���������Ϊ�գ����Ԫ�ؼ��Ƕ�ͷҲ�Ƕ�β
    if(empty()){
        front = rear = newnode;
        length++;
    }
    //�����в�Ϊ��
    else{
        rear->next = newnode;
        rear = newnode;
        length++;
    }
}

template<typename T>//���ӣ������ض�ͷԪ��
T LinkQueue<T>::deQueue(){
    if(empty()) throw std::out_of_range("����Ϊ��");
    //ɾ����ͷԪ��
    node *p = front;
    T data = front->data;
    front = front->next;
    delete p;
    //������Ӻ����Ϊ�գ����޸�rearΪnullptr
    if(front == nullptr) rear = nullptr;
    length--;
    return data;
}

template<typename T>//��ȡ��ͷԪ��
T LinkQueue<T>::get_front()const{
    if(empty()) throw std::out_of_range("����Ϊ��");
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