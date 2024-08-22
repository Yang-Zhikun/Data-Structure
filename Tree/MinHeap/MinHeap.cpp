#include"minHeap.h"
#include<iostream>
#include<stdexcept>


/**
 * ��ȡ�±�Ϊi�Ľڵ�����ӵ��±�
 * @param i ��ǰ�ڵ���±�
 */
template<typename T>
unsigned int MinHeap<T>::getLeftChild(unsigned int i)const {
    return 2 * i + 1;
}

/**
 * ��ȡ�±�Ϊi�Ľڵ���Һ��ӵ��±�
 * @param i ��ǰ�ڵ���±�
 */
template<typename T>
unsigned int MinHeap<T>::getRightChild(unsigned int i)const {
    return 2 * i + 2;
}

/**
 * ��ȡ�±�Ϊi�Ľڵ�ĸ��ڵ���±�
 * @param i ��ǰ�ڵ���±�
 */
template<typename T>
unsigned int MinHeap<T>::getParent(unsigned int i)const {
    return (i - 1) / 2;
}


/**
 * ��С�ѵ��±�Ϊi��Ԫ�ؽ����ϸ�����
 * @param i ��ǰ�ڵ���±�
 */
template<typename T>
void MinHeap<T>::shiftUp(unsigned int i) {
    unsigned int parent = getParent(i); // ��ȡ��ǰ�ڵ�ĸ��ڵ���±�
    T tmp = HeapArray[i]; // ���浱ǰ�ڵ㣬�������ֵ

    //�����ǰ�ڵ��и��ڵ��ұȸ��ڵ�С��������ϸ�����(���ڵ����Ƶ���ǰ�ڵ��λ��)
    while(i > 0 && tmp < HeapArray[parent]) {
        HeapArray[i] = HeapArray[parent]; // ���ڵ����Ƶ���ǰ�ڵ�(�ӽڵ�)��λ��
        // �����±궼���ƣ�����ѭ��
        i = parent;
        parent = getParent(parent);
    }
    //���ֵ
    HeapArray[i] = tmp;
}

/**
 * ��С�ѵ��±�Ϊi��Ԫ�ؽ����³�����
 * @param i ��ǰ�ڵ���±�
 */
template<typename T>
void MinHeap<T>::shiftDown(unsigned int i) {
    unsigned int leftChild, rightChild, smallest;
    T tmp = HeapArray[i];
    //�����ǰ�ڵ����ӽڵ��ұ��ӽڵ��������³�����(�ӽڵ����Ƶ���ǰ�ڵ�)
    while(true) {
        leftChild = getLeftChild(i);
        rightChild = getRightChild(i);
        smallest = i; // ��ǰ�ڵ����С�ĺ��ӵ��±�

        //���ҵ�ǰ�ڵ����С�ĺ��ӣ�ȷ����С��Ԫ��������
        // ������ӱȵ�ǰ�ڵ�С���͸���smallest
        if(leftChild < size && HeapArray[leftChild] < tmp) {
            smallest = leftChild;
        }
        // ����Һ��ӱȵ�ǰ�ڵ�С���ұ����Ӹ�С���͸���smallest
        if(rightChild < size && HeapArray[rightChild] < tmp && HeapArray[rightChild] < HeapArray[leftChild]) {
            smallest = rightChild;
        }
        // ������������ifûִ��(smallestδ����)��˵����ǰ���κ�һ���ڵ㶼С����ֱ������
        if(i == smallest) {
            break;
        }
        //��������³�����(��С�ĺ������Ƶ���ǰ�ڵ��λ��)
        HeapArray[i] = HeapArray[smallest];
        //�±����ƣ�����ѭ��
        i = smallest;
    }
    // ���ֵ
    HeapArray[i] = tmp;
}


/**
 * ������С��
 * @param array ���ѻ�������
 * @param n ���������ݸ���(�����������󳤶�)
 */
template<typename T>
MinHeap<T>::MinHeap(T array[], unsigned int n) {
    this->HeapArray = array;
    this->size = n;
    // �����һ����֧�ڵ�(���һ���ڵ�ĸ��ڵ�)��ʼ�����µ��Ͻ��жѻ�(�³�����)
    for(unsigned int i = getParent(size - 1); i >= 0; i--) {
        shiftDown(i);
        if(i == 0) break; // i����0ʱҪ����������ִ��i--�������
    }
}

/**
 * ��С���Ƿ�Ϊ��
 */
template<typename T>
bool MinHeap<T>::isEmpty()const {
    return size == 0;
}

/**
 * ������Ԫ�ء�������Ԫ��ǰ��ȷ�����ᳬ���������󳤶�
 * @param elem ���������Ԫ��
 */
template<typename T>
void MinHeap<T>::push(T elem) {
    HeapArray[size] = elem; // ������ĩβ������Ԫ��
    size++;
    shiftUp(size - 1); // ���²����Ԫ�ؽ����ϸ�����
}

/**
 * ��ȡ��С�ѵ���СԪ��(�Ѷ�Ԫ��)
 */
template<typename T>
T MinHeap<T>::getMin()const {
    if(size == 0)
        throw std::out_of_range("��С��Ϊ��");
    return HeapArray[0];
}

/**
 * ɾ����������СԪ��(�Ѷ�Ԫ��)
 */
template<typename T>
T MinHeap<T>::pop() {
    if(size == 0)
        throw std::out_of_range("��С��Ϊ��");
    T tmp = HeapArray[0]; // ����Ѷ�Ԫ��
    HeapArray[0] = HeapArray[size - 1]; // ����������һ��Ԫ�ز����Ѷ�
    size--;
    shiftDown(0); // ���²����Ѷ���Ԫ�ؽ����³�����
    return tmp;
}

/**
 * ��ӡ��С��
 */
template<typename T>
void MinHeap<T>::print()const {
    for(unsigned int i = 0; i < size; i++) {
        cout << HeapArray[i] << ' ';
    }
    cout<<'\n';
}