//顺序表 Dynamic sequential lists
//动态内存分配，可自动扩容

#include<iostream>
#include <stdexcept> // 包含std::out_of_range和std::invalid_argument
using namespace std; 

template<typename T>
class D_seqList{
private:
    T *data;//存放数据的首地址
    unsigned int length;//当前顺序表中数据个数
    unsigned int maxLen;//最大表长

    void resize();//顺序表满时扩容

public:
    D_seqList();//构造函数
    D_seqList(const D_seqList &sl);//拷贝构造函数
    D_seqList<T>& operator=(const D_seqList &sl);//赋值运算符
    ~D_seqList(){ delete[] data; }//析构函数

    unsigned int getLength()const{ return length; }//获取表长length
    void clear(){ length=0; };//清空顺序表
    bool isEmpty()const{ return length==0; }//判断顺序表是否为空
    void traverse()const;//遍历顺序表
    T operator[] (unsigned int i)const;//运算符[]：获取顺序表位序i的数据(0<=i<length)
    T& operator[] (unsigned int i);//运算符[]：返回顺序表位序i的数据的引用(0<=i<length)
    void set(unsigned int i, T elem){ this->operator[](i) = elem; }//将顺序表位序为i的元素的值改为elem(0<=i<length)
    T get(unsigned int i)const{ return operator[](i); }//获取顺序表位序i的数据(0<=i<length)
    void insert(unsigned int i, T elem);//在顺序表位序i处插入一个数据(0<=i<=length)
    void push_back(T elem){ insert(length, elem); }//在顺序表末尾插入一个数据
    void remove(unsigned int i);//删除顺序表位序i上数据(0<=i<length)
    void pop_back(){ remove(length-1); }//删除顺序表末尾的一个数据
    void reserve();//逆置顺序表
};





template<typename T>//构造函数
D_seqList<T>::D_seqList(){
    data = new T[2];
    if(!data){//内存分配失败
        throw std::bad_alloc();
        return;
    }
    length = 0;
    maxLen = 2;//初始时最大表长为2
}


template<typename T>//拷贝构造函数
D_seqList<T>::D_seqList(const D_seqList<T> &sl): maxLen(sl.maxLen), length(sl.length){
    // 动态分配内存  
    data = new T[maxLen];
    // 检查内存分配是否失败  
    if(!data){
        // 抛出异常，使用标准异常类型  
        throw std::bad_alloc();
    }
    // 将sl的数据复制到新对象  
    for(int i = 0; i < length; i++){
        data[i] = sl.data[i];
    }
}


template<typename T>//赋值运算符
D_seqList<T>& D_seqList<T>::operator=(const D_seqList<T> &sl){
/*
在的赋值运算符实现中，试图通过调用拷贝构造函数来赋值，但这是不正确的。不能用 *this = D_seqList(sl);
这会导致无限递归，因为赋值运算符本身在赋值过程中被调用，而又在其中调用了拷贝构造函数，
    该构造函数最终会尝试调用赋值运算符（如果它有任何资源需要管理）。
应该直接在赋值运算符内部进行深拷贝，而不是创建临时对象。    */

    if(this != &sl){ // 防止自赋值  
        T* newData = new T[sl.maxLen];
        if(!newData){
            throw std::bad_alloc();
        }
        // 复制数据  
        for(int i = 0; i < sl.length; i++){
            newData[i] = sl.data[i];
        }
        // 释放旧内存  
        delete[] data;
        // 更新成员变量  
        data = newData;
        length = sl.length;
        maxLen = sl.maxLen;
    }
    return *this;
}



template<typename T>//顺序表满时扩容
void D_seqList<T>::resize(){
    T* newData = new T[maxLen * 2];
    if(!newData){
        throw std::bad_alloc();
    }
    // 复制数据  
    for(int i = 0; i < length; i++){
        newData[i] = data[i];
    }
    // 释放旧内存  
    delete[] data;
    // 更新成员变量  
    data = newData;
    maxLen *= 2;
}




template<typename T>//遍历顺序表
void D_seqList<T>::traverse()const{
    for(int i=0; i<length; i++){
        cout<<data[i]<<" ";
    }
    cout<<"\n";
}



template<typename T>//运算符[]：获取顺序表位序i的数据(0<=i<length)
T D_seqList<T>::operator[] (unsigned int i)const{
    if(i>=length || i<0){
        throw std::out_of_range("传入的位序i不正确");
    }
    else{
        return data[i];
    }
}

template<typename T>//运算符[]：返回顺序表位序i的数据的引用(0<=i<length)
T& D_seqList<T>::operator[](unsigned int i){
    if(i>=length || i<0){
        throw std::out_of_range("传入的位序i不正确");
    }
    else{
        return data[i];
    }
}

template<typename T>//在顺序表位序i处插入一个数据(0<=i<=length)
void D_seqList<T>::insert(unsigned int i, T elem){
    if(i>length ||i<0){//插入的位置不合法
        throw std::out_of_range("传入的位序i不正确");
    }
    if(i==length){//i==length表示插入到顺序表的末尾
        try{
            resize();//表满扩容
        }
        catch(std::bad_alloc()){
            throw "插入数据失败！";
        }
    }
    //将位序i后的数据都后移一个位置
    for(int j=length; j>i; j--){
        data[j] = data[j-1];
    }
    data[i] = elem;//插入数据
    length++;//顺序表长度加1
}


template<typename T>//删除顺序表位序i上数据(0<=i<length)
void D_seqList<T>::remove(unsigned int i){
    if(i>=length || i<0){
        throw std::out_of_range("传入的位序i不正确");
    }
    //将要删除的数据后面的数据全部前移一个位置，覆盖要删除的数据
    for(int j=i; j<length-1; j++){
        data[j] = data[j+1];
    }
    length--;//顺序表长度减1
}

template<typename T>//逆置顺序表
void D_seqList<T>::reserve(){
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
    D_seqList<int> L;
    for(int i=1; i<=3; i++){
        L.push_back(i);
    }
    L.traverse();
    L.reserve();
    L.traverse();
    system("pause");
}