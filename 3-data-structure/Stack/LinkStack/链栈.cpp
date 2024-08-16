#include<iostream>
#include<stdexcept>
using namespace std;


template<typename T>
class LinkStack{
private:
    struct node{
        T data;
        node *next;
    };

    node *top; // ջ��ָ�룬Ҳ��ͷָ��
    unsigned int length; // ��ջ�����ݸ���

public:
    LinkStack(); // ���캯��
    ~LinkStack(); // ��������
    LinkStack(const LinkStack& obj); // �������캯��
    LinkStack<T>& operator=(const LinkStack& obj); // ��ֵ�����

    void clear(); // ���ջ
    bool isEmpty() const{ return top==nullptr; } // �п�
    int getLength() const{ return length; } // ��ȡ��ջ���ݸ���
    void push(const T elem); // ��ջ
    T pop(); // ��ջ�������س�ջԪ��
    T get_top() const; // ����ջ��Ԫ��
};





template<typename T>//���캯��
LinkStack<T>::LinkStack(){
    top = nullptr;
    length = 0;
}

template<typename T>//��������
LinkStack<T>::~LinkStack(){
    clear();
}

template<typename T>//�������캯��
LinkStack<T>::LinkStack(const LinkStack & obj){
    top = nullptr;
    node *tail = top;//βָ��
    for(node *p = obj.top; p!=nullptr; p = p->next){
        node * newnode = new node;
        newnode->data = p->data;
        newnode->next = nullptr;
        tail->next = newnode;
        tail = newnode;
    }
}

template<typename T>//��ֵ�����
LinkStack<T>& LinkStack<T>::operator=(const LinkStack & obj){
    if(*this!=obj){ // ��ֹ�Ը�ֵ
        top = nullptr;
        node *tail = top;//βָ��
        for(node *p = obj.top; p!=nullptr; p = p->next){
            node * newnode = new node;
            newnode->data = p->data;
            newnode->next = nullptr;
            tail->next = newnode;
            tail = newnode;
        }
    }
}

template<typename T>//���ջ
void LinkStack<T>::clear(){
    node *p;
    while(top!=nullptr){
        p = top; // pָ��ǰ��ջ��Ԫ��
        top = top->next; // top����ƶ�
        delete p;
    }
    length = 0;
}

template<typename T>//��ջ
void LinkStack<T>::push(const T elem){
    node *newnode = new node;
    newnode->data = elem;
    newnode->next = top; // newnode��nextָ��ԭ����ջ��Ԫ��
    top = newnode; // topͷָ��ָ��newnode, newnode��Ϊ�µ�ջ��Ԫ��
    length++;
}

template<typename T>// ��ջ�������س�ջԪ��
T LinkStack<T>::pop(){
    if(top == nullptr)
        throw std::out_of_range("ջΪ��");
    T tmp = top->data;
    node *p = top;//�ݴ�ջ���ڵ�
    top= top->next;//topָ��ջ��Ԫ�صĺ�̣�������ƶ�
    delete p;
    length--;
    return tmp;
}

template<typename T>// ����ջ��Ԫ��
T LinkStack<T>::get_top() const{
    if(top == nullptr)
        throw std::out_of_range("ջΪ��");
    return top->data;
}









int main(){
    LinkStack<int> stk;
    //cout<<"get_top: "<<stk.get_top()<<endl;
    cout<<"length: "<<stk.getLength()<<endl;
    cout<<"isEmpty: "<<stk.isEmpty()<<endl<<endl;
    for(int i=1; i<=10; i++){
        stk.push(i);
        cout<<"get_top: "<<stk.get_top()<<endl;
        cout<<"length: "<<stk.getLength()<<endl;
        cout<<"isEmpty: "<<stk.isEmpty()<<endl<<endl;
    }
    cout<<"\n\n";
    for(int i = 1; i<=10; i++){
        cout<<"pop "<<stk.pop()<<endl;
        cout<<"length: "<<stk.getLength()<<endl;
        cout<<"isEmpty: "<<stk.isEmpty()<<endl<<endl;
    }
    stk.clear();
    cout<<"length: "<<stk.getLength()<<endl;
    cout<<"isEmpty: "<<stk.isEmpty()<<endl<<endl;
    system("pause");
}