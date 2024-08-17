#include<iostream>
#include<vector>
using namespace std;

/**
 * 最小堆
 */
template<typename T>
class MinHeap {
protected:
    vector<T> HeapArray; //存放最小堆的数组(下标从0开始)
    
    unsigned int getLeftChild(unsigned int i) const; //获取位序为i的节点的左孩子的下标
    unsigned int getRightChild(unsigned int i) const; //获取位序为i的节点的右孩子的下标
    unsigned int getParent(unsigned int i) const; //获取位序为i的节点的父节点的下标
    
    void shiftUp();   //最小堆的上浮调整
    void shiftDown(); //最小堆的下沉调整
    
    void buildHeap(); //构建最小堆
    
public:
    MinHeap(T array[] = nullptr, unsigned int n = 0);  //构造函数
    MinHeap(const MinHeap& obj); //拷贝构造函数
    MinHeap<T>& operator=(const MinHeap& obj); //赋值运算符
    
    bool isEmpty() const; //判空
    void insert(const T elem); //插入新元素
    void getMin() const; //获取最小堆的最小元素(堆顶元素)
    void remove(); //删除并返回最小元素
};



int main(){
    
}