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

    node *top; // 栈顶指针，也是头指针
    unsigned int length; // 链栈中数据个数

public:
    LinkStack(); // 构造函数
    ~LinkStack(); // 析构函数
    LinkStack(const LinkStack& obj); // 拷贝构造函数
    LinkStack<T>& operator=(const LinkStack& obj); // 赋值运算符

    void clear(); // 清空栈
    bool isEmpty() const{ return top==nullptr; } // 判空
    int getLength() const{ return length; } // 获取链栈数据个数
    void push(const T elem); // 入栈
    T pop(); // 出栈，并返回出栈元素
    T get_top() const; // 返回栈顶元素
};





template<typename T>//构造函数
LinkStack<T>::LinkStack(){
    top = nullptr;
    length = 0;
}

template<typename T>//析构函数
LinkStack<T>::~LinkStack(){
    clear();
}

template<typename T>//拷贝构造函数
LinkStack<T>::LinkStack(const LinkStack & obj){
    top = nullptr;
    node *tail = top;//尾指针
    for(node *p = obj.top; p!=nullptr; p = p->next){
        node * newnode = new node;
        newnode->data = p->data;
        newnode->next = nullptr;
        tail->next = newnode;
        tail = newnode;
    }
}

template<typename T>//赋值运算符
LinkStack<T>& LinkStack<T>::operator=(const LinkStack & obj){
    if(*this!=obj){ // 防止自赋值
        top = nullptr;
        node *tail = top;//尾指针
        for(node *p = obj.top; p!=nullptr; p = p->next){
            node * newnode = new node;
            newnode->data = p->data;
            newnode->next = nullptr;
            tail->next = newnode;
            tail = newnode;
        }
    }
}

template<typename T>//清空栈
void LinkStack<T>::clear(){
    node *p;
    while(top!=nullptr){
        p = top; // p指向当前的栈顶元素
        top = top->next; // top向后移动
        delete p;
    }
    length = 0;
}

template<typename T>//入栈
void LinkStack<T>::push(const T elem){
    node *newnode = new node;
    newnode->data = elem;
    newnode->next = top; // newnode的next指向原来的栈顶元素
    top = newnode; // top头指针指向newnode, newnode成为新的栈顶元素
    length++;
}

template<typename T>// 出栈，并返回出栈元素
T LinkStack<T>::pop(){
    if(top == nullptr)
        throw std::out_of_range("栈为空");
    T tmp = top->data;
    node *p = top;//暂存栈顶节点
    top= top->next;//top指向栈顶元素的后继，即向后移动
    delete p;
    length--;
    return tmp;
}

template<typename T>// 返回栈顶元素
T LinkStack<T>::get_top() const{
    if(top == nullptr)
        throw std::out_of_range("栈为空");
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