#include"minHeap.h"
#include<vector>

/**
 * ��ȡλ��Ϊi�Ľڵ�����ӵ��±�
 * @param i λ��Ϊi�ڵ��±�
 */
template<typename T>
unsigned int MinHeap<T>::getLeftChild(unsigned int i) const {
    return 2 * i + 1; //�����±�Ϊ2*i+1
}

/**
 * ��ȡλ��Ϊi�Ľڵ���Һ��ӵ��±�
 * @param i λ��Ϊi�ڵ��±�
 */
template<typename T>
unsigned int MinHeap<T>::getRightChild(unsigned int i) const {
    return 2 * i + 2; //�Һ����±�Ϊ2*i+2
}

/**
 * ��ȡλ��Ϊi�Ľڵ�ĸ��ڵ���±�
 * @param i λ��Ϊi�ڵ��±�
 */
template<typename T>
unsigned int MinHeap<T>::getParent(unsigned int i) const {
    return (i - 1) / 2; //���ڵ��±�Ϊ(i-1)/2 (����ȡ��)
}


/**
 * ��С�ѵ����һ��Ԫ�ؽ����ϸ�����
 */
template<typename T>
void MinHeap<T>::shiftUp() {
    unsigned int child = HeapArray.size() - 1; // ���һ��Ԫ�ص��±�
    unsigned int parent = getParent(child); // ���һ��Ԫ�صĸ��ڵ��±�
    T tmp = HeapArray[child]; // �������һ��Ԫ�ص�ֵ���������ĸ�ֵ

    // ��ε�ǰ�ڵ�С�ڸ��ڵ㣬������ϸ�����(���ڵ����Ƶ��ӽڵ��λ��)
    while(child > 0 && tmp < HeapArray[parent]){
        HeapArray[child] = HeapArray[parent]; // ���ڵ����Ƶ��ӽڵ��λ��
        child = parent; // ����child�±궨λ�����ڵ�
        parent = getParent(parent); // ����parent�±궨λ���丸�ڵ�
    }
    // �������һ��Ԫ�ص�ֵ��ֵ�����ڵ��±��λ��
    HeapArray[child] = tmp;
}

/**
 * ��С�ѵĶѶ�Ԫ�ؽ����³�����
 */
template<typename T>
void MinHeap<T>::shiftDown() {

}



/**
 * ������С��
 * @param array ��ʼ����С�ѵ�����
 * @param n ���鳤��
 */
template<typename T>
void MinHeap<T>::buildHeap(T array[], unsigned int n) {
    //��arrry�����ݷŵ�HeapArray�У�����ÿһ�����ڵ�����³�����
    for (unsigned int i = 0; i < n; ++i) {
        HeapArray.push_back(array[i]);
        shiftDown();
    }
}