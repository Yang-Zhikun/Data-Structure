#include"LinkStack.h"
#include<iostream>
using namespace std;
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