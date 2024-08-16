//˳��ջ��sequential stack
//�����Զ����ݣ�����󳤶ȹ̶�

#include<iostream>
#include<stdexcept>
using namespace std;


template<typename T>
class seqStack{
private:
    T *data;//���ջ���ݵ��������ַ
    int top; // ջ��Ԫ�ص��±꣬== -1ʱ��ʾջ��
    int maxlen; // ջ��ջ����󳤶ȣ�������Ĵ�С

public:
    seqStack(const int init_len = 100);//���캯����init_len��ջ����󳤶�(����Ĵ�С)
    ~seqStack(){ delete[] data; } //��������
    seqStack(const seqStack& obj);//�������캯��
    seqStack<T>& operator=(const seqStack& obj);//��ֵ�����

    void clear(){ top = -1; } //���ջ
    bool isEmpty()const{ return top == -1; } //�п�
    int getLength()const{ return top+1; } //��ȡջ�����ݸ���
    void push(const T elem); //��ջ
    T pop(); //��ջ�������س�ջԪ��
    T get_top()const; //��ȡջ��Ԫ��
};




template<typename T>//���캯��
seqStack<T>::seqStack(const  int init_len){
    maxlen = init_len;
    data = new T[maxlen];
    top = -1;//��ʼΪ��ջ
}

template<typename T>//�������캯��
seqStack<T>::seqStack(const seqStack & obj){
    maxlen = obj.maxlen;
    data = new T[maxlen];//�������ڴ�
    //����obj������
    for(int i = 0; i < obj.top+1; i++){
        data[i] = obj.data[i];
    }
    top = obj.top;
}

template<typename T>//��ֵ�����
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

template<typename T>//��ջ
void seqStack<T>::push(const T elem){
    if(top+1 == maxlen)
        throw std::out_of_range("ջ����");
    data[top+1] = elem;
    top++;
}

template<typename T>//��ջ�������س�ջԪ��
T seqStack<T>::pop(){
    if(top == -1)
        throw std::out_of_range("ջΪ��");
    T tmp = data[top];//����ջ��Ԫ��
    top--;
    return tmp;
}

template<typename T>//��ȡջ��Ԫ��
T seqStack<T>::get_top() const{
    if(top == -1)
        throw std::out_of_range("ջΪ��");
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