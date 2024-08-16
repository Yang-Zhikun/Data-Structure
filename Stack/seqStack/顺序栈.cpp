//顺序栈，sequential stack
//不能自动扩容，定义后长度固定

#include<iostream>
#include<stdexcept>
using namespace std;


template<typename T>
class seqStack{
private:
    T *data;//存放栈数据的数组基地址
    int top; // 栈顶元素的下标，== -1时表示栈空
    int maxlen; // 栈的栈的最大长度，即数组的大小

public:
    seqStack(const int init_len = 100);//构造函数，init_len是栈的最大长度(数组的大小)
    ~seqStack(){ delete[] data; } //析构函数
    seqStack(const seqStack& obj);//拷贝构造函数
    seqStack<T>& operator=(const seqStack& obj);//赋值运算符

    void clear(){ top = -1; } //清空栈
    bool isEmpty()const{ return top == -1; } //判空
    int getLength()const{ return top+1; } //获取栈的数据个数
    void push(const T elem); //入栈
    T pop(); //出栈，并返回出栈元素
    T get_top()const; //获取栈顶元素
};




template<typename T>//构造函数
seqStack<T>::seqStack(const  int init_len){
    maxlen = init_len;
    data = new T[maxlen];
    top = -1;//初始为空栈
}

template<typename T>//拷贝构造函数
seqStack<T>::seqStack(const seqStack & obj){
    maxlen = obj.maxlen;
    data = new T[maxlen];//申请新内存
    //复制obj的数据
    for(int i = 0; i < obj.top+1; i++){
        data[i] = obj.data[i];
    }
    top = obj.top;
}

template<typename T>//赋值运算符
seqStack<T>& seqStack<T>::operator=(const seqStack & obj){
    if(*this!=obj){//防止自赋值
        maxlen = obj.maxLen;
        data = new T[maxlen];//申请新内存
        //复制obj的数据
        for(int i = 0; i<top+1; i++){
            data[i] = obj.data[i];
        }
        top = obj.top;
    }
    return *this;
}

template<typename T>//入栈
void seqStack<T>::push(const T elem){
    if(top+1 == maxlen)
        throw std::out_of_range("栈已满");
    data[top+1] = elem;
    top++;
}

template<typename T>//出栈，并返回出栈元素
T seqStack<T>::pop(){
    if(top == -1)
        throw std::out_of_range("栈为空");
    T tmp = data[top];//保存栈顶元素
    top--;
    return tmp;
}

template<typename T>//获取栈顶元素
T seqStack<T>::get_top() const{
    if(top == -1)
        throw std::out_of_range("栈为空");
    return data[top];
}





int main(){
    seqStack<char> stk(10);
    for(int i=1; i<=10; i++){
        char ch;
        cin>>ch;
        stk.push(ch);
        cout<<"length: "<<stk.getLength()<<endl;
        cout<<"isEmpty: "<<stk.isEmpty()<<endl;
        cout<<"top: "<<stk.get_top()<<endl<<endl;
    }
    for(int i=1; i<=10;i++){
        //stk.pop();
        cout<<"pop: "<<stk.pop();
        cout<<"length: "<<stk.getLength()<<endl;
        cout<<"isEmpty: "<<stk.isEmpty()<<endl;
        //cout<<"top: "<<stk.get_top()<<endl<<endl;
    }

    system("pause");
}