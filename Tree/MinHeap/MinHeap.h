#pragma once

/**
 * 最小堆
 */
template<typename T>
class MinHeap {
protected:
    T* HeapArray; // 指向存放最小堆的数组的指针
    unsigned int size; // 数组数据个数

    unsigned int getLeftChild(unsigned int i) const; //获取下标为i的节点的左孩子的下标
    unsigned int getRightChild(unsigned int i) const; //获取下标为i的节点的右孩子的下标
    unsigned int getParent(unsigned int i) const; //获取下标为i的节点的父节点的下标

    void shiftUp(unsigned int i);   //最小堆的下标为i的元素进行上浮调整
    void shiftDown(unsigned int i); //最小堆的下标为i的元素进行下沉调整

public:
    MinHeap(T array[] = nullptr, unsigned int n = 0);  //构造最小堆

    bool isEmpty() const; //判空
    void push(T elem); //插入新元素
    T getMin() const; //获取最小堆的最小元素(堆顶元素)
    T pop(); //删除并返回最小元素(堆顶元素)

    void print()const; //打印最小堆
};


/**
 * 对于下标为i的节点：
 * 左孩子下标 2 * i + 1           //左孩子在i的下一层+1
 * 右孩子下标 2 * i + 2           //右孩子是左孩子+1
 * 父节点下标 (i - 1) / 2 (取整)   //逆运算
 *            0
 *           /  \
 *          1    2
 *         / \  / \
 *        3  4  5  6
 */




#include"minHeap.cpp"
