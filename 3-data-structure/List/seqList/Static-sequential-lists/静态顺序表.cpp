#include<iostream>
#include<stdexcept>
using namespace std;


const int MAXLEN = 100;    //静态顺序表的最大表长

template<typename T>
class S_seqList{
private:
    T data[MAXLEN];//存放数据的首地址
    unsigned int length;//当前顺序表中数据个数

public:
    S_seqList(){ length = 0; } //构造函数
    S_seqList(const S_seqList& obj);//拷贝构造函数
    S_seqList<T>& operator=(const S_seqList& obj);//赋值运算符

    unsigned int getLength()const{ return length; }//获取表长length
    void clear(){ length = 0; };//清空顺序表
    bool isEmpty()const{ return length==0; }//判断顺序表是否为空
    void traverse()const;//遍历顺序表
    T operator[] (const unsigned int i)const;//运算符[]：获取顺序表位序i的数据(0<=i<length)
    T& operator[] (const unsigned int i);//运算符[]：返回顺序表位序i的数据的引用(0<=i<length)
    void set(const unsigned int i, const T elem){ this->operator[](i) = elem; }//将顺序表位序为i的元素的值改为elem(0<=i<length)
    T get(const unsigned int i)const{ return operator[](i); }//获取顺序表位序i的数据(0<=i<length)
    void insert(const unsigned int i, const T elem);//在顺序表位序i处插入一个数据(0<=i<=length)
    void push_back(const T elem){ insert(length, elem); }//在顺序表末尾插入一个数据
    void remove(const unsigned int i);//删除顺序表位序i上数据(0<=i<length)
    void pop_back(){ remove(length-1); }//删除顺序表末尾的一个数据
    void reserve();//逆置顺序表
};




template<typename T>////拷贝构造函数
S_seqList<T>::S_seqList(const S_seqList& obj){
    for(int i=0; i < obj.length; i++){
        data[i] = obj.data[i];
    }
    length = obj.length;
}

template<typename T>
S_seqList<T>& S_seqList<T>::operator=(const S_seqList & obj){
    if(*this!=obj){//防止自赋值
        for(int i=0; i < obj.length; i++){
            data[i] = obj.data[i];
        }
        length = obj.length;
    }
    return *this;
}

template<typename T>//遍历顺序表
void S_seqList<T>::traverse() const{
    for(int i=0; i<length; i++){
        cout<<data[i]<<' ';
    }
    cout<<'\n';
}

template<typename T>//运算符[]：获取顺序表位序i的数据(0<=i<length)
T S_seqList<T>::operator[](const unsigned int i) const{
    if(i>=length || i<0){
        throw std::out_of_range("传入的位序i不正确");
    }
    else{
        return data[i];
    }
}

template<typename T>//运算符[]：返回顺序表位序i的数据的引用(0<=i<length)
T& S_seqList<T>::operator[](const unsigned int i){
    if(i>=length || i<0){
        throw std::out_of_range("传入的位序i不正确");
    }
    else{
        return data[i];
    }
}

template<typename T>//在顺序表位序i处插入一个数据(0<=i<=length)
void S_seqList<T>::insert(const unsigned int i, const T elem){
    if(length == MAXLEN)
        throw std::out_of_range("顺序表已满");
    else if(i<0 || i>length)
        throw std::out_of_range("传入的位序i不合法");
    else{}
    //将位序i后的数据都后移一个位置
    for(int j = length; j>i; j--){
        data[j] = data[j-1];
    }
    data[i] = elem;//插入数据
    length++;//顺序表长度加1
}

template<typename T>//删除顺序表位序i上数据(0<=i<length)
void S_seqList<T>::remove(const unsigned int i){
    if(i>=length || i<0)
        throw std::out_of_range("传入的位序i不正确");
    //将要删除的数据后面的数据全部前移一个位置，覆盖要删除的数据
    for(int j=i; j<length-1; j++){
        data[j] = data[j+1];
    }
    length--;//顺序表长度减1
}

template<typename T>//逆置顺序表
void S_seqList<T>::reserve(){
    if(length == 0)
        return;
    //从两端向中间进行三角交换
    T tmp;
    int i=0, j=length-1;//头、尾两个工作指针
    while(i<j){
        //交换i,j所指的数
        tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
        //两个工作指针向中间移动
        i++;
        j--;
    }
}






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