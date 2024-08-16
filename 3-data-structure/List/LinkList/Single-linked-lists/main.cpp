#include"S_LinkList.h"
using namespace std;
int main(){
    S_LinkList<int> L;
    int a[]={1,2,3,4,5,6,7,8,9,0};
    L.push_arr_head(a, 10);
    L.traverse();
    cout<<"length: "<<L.getLength()<<endl;
    cout<<"tailData: "<<L.getTailData()<<endl;
    L.push_arr_head(a, 10);
    L.traverse();
    cout<<"length: "<<L.getLength()<<endl;
    cout<<"tailData: "<<L.getTailData()<<endl;

    S_LinkList<int> l2=L;
    l2.traverse();
    cout<<"length: "<<l2.getLength()<<endl;
    cout<<"TailData: "<<l2.getTailData()<<endl<<endl;

    system("pause");
}