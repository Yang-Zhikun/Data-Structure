#include"D_seqList.h"
using namespace std;
int main(){
    D_seqList<double> sl;
    sl.push_back(0.8);
    sl.traverse();
    sl.push_back(9.4);
    sl.traverse();
    sl.insert(2, 5.88);
    sl.traverse();
    sl[2] = 0.77;
    sl.traverse();
    cout<<"length: "<<sl.getLength()<<endl;
    cout<<"elem 1: "<<sl[1]<<endl;
    cout<<"elem 2: "<<sl[2]<<endl;
    sl.set(1, 11.3);
    sl.traverse();
    cout<<"length: "<<sl.getLength()<<endl<<endl<<endl;


    D_seqList<double> L(sl);
    L = sl;
    L.traverse();

    L.reserve();
    L.traverse();

    system("pause");
}