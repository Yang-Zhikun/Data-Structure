#include"minHeap.h"
#include<vector>

/**
 * 获取位序为i的节点的左孩子的下标
 * @param i 位序为i节点下标
 */
template<typename T>
unsigned int MinHeap<T>::getLeftChild(unsigned int i) const {
    return 2 * i + 1; //左孩子下标为2*i+1
}

/**
 * 获取位序为i的节点的右孩子的下标
 * @param i 位序为i节点下标
 */
template<typename T>
unsigned int MinHeap<T>::getRightChild(unsigned int i) const {
    return 2 * i + 2; //右孩子下标为2*i+2
}

/**
 * 获取位序为i的节点的父节点的下标
 * @param i 位序为i节点下标
 */
template<typename T>
unsigned int MinHeap<T>::getParent(unsigned int i) const {
    return (i - 1) / 2; //父节点下标为(i-1)/2 (向下取整)
}


/**
 * 最小堆的最后一个元素进行上浮调整
 */
template<typename T>
void MinHeap<T>::shiftUp() {
    unsigned int child = HeapArray.size() - 1; // 最后一个元素的下标
    unsigned int parent = getParent(child); // 最后一个元素的父节点下标
    T tmp = HeapArray[child]; // 保存最后一个元素的值，用于最后的赋值

    // 如何当前节点小于父节点，则进行上浮调整(父节点下移到子节点的位置)
    while(child > 0 && tmp < HeapArray[parent]){
        HeapArray[child] = HeapArray[parent]; // 父节点下移到子节点的位置
        child = parent; // 更新child下标定位到父节点
        parent = getParent(parent); // 更新parent下标定位到其父节点
    }
    // 最后把最后一个元素的值赋值到父节点下标的位置
    HeapArray[child] = tmp;
}

/**
 * 最小堆的堆顶元素进行下沉调整
 */
template<typename T>
void MinHeap<T>::shiftDown() {

}



/**
 * 构建最小堆
 * @param array 初始化最小堆的数组
 * @param n 数组长度
 */
template<typename T>
void MinHeap<T>::buildHeap(T array[], unsigned int n) {
    //把arrry的数据放到HeapArray中，并对每一个父节点进行下沉操作
    for (unsigned int i = 0; i < n; ++i) {
        HeapArray.push_back(array[i]);
        shiftDown();
    }
}