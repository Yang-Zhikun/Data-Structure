#include"seqStack.h"
#include<iostream>
using namespace std;
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