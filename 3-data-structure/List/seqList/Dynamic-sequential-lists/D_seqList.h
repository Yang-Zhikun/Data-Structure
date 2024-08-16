//动态顺序表
//动态内存分配，可自动扩容

#pragma once

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


#include"D_seqList.cpp"