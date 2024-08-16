#include "S_seqList.h"
int main(){
    S_seqList<double> l;
    l.traverse();
    cout<<"length: "<<l.getLength()<<endl;
    cout<<"isEmpty: "<<l.isEmpty()<<endl;
    l.push_back(0.1);
    l.traverse();
    cout<<"length: "<<l.getLength()<<endl;
    cout<<"isEmpty: "<<l.isEmpty()<<endl;

    l.clear();
    for(int i = 1; i<=100; i++){
        l.push_back(i*0.2);
    }
    l.traverse();
    cout<<"length: "<<l.getLength()<<endl;
    cout<<"isEmpty: "<<l.isEmpty()<<endl;
    l.pop_back();
    l.traverse();
    cout<<"length: "<<l.getLength()<<endl;
    cout<<"isEmpty: "<<l.isEmpty()<<endl;
    l.reserve();
    l.traverse();
    cout<<"length: "<<l.getLength()<<endl;
    cout<<"isEmpty: "<<l.isEmpty()<<endl;


    system("pause");
}