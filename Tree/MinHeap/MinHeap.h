#pragma once

/**
 * ��С��
 */
template<typename T>
class MinHeap {
protected:
    T* HeapArray; // ָ������С�ѵ������ָ��
    unsigned int size; // �������ݸ���

    unsigned int getLeftChild(unsigned int i) const; //��ȡ�±�Ϊi�Ľڵ�����ӵ��±�
    unsigned int getRightChild(unsigned int i) const; //��ȡ�±�Ϊi�Ľڵ���Һ��ӵ��±�
    unsigned int getParent(unsigned int i) const; //��ȡ�±�Ϊi�Ľڵ�ĸ��ڵ���±�

    void shiftUp(unsigned int i);   //��С�ѵ��±�Ϊi��Ԫ�ؽ����ϸ�����
    void shiftDown(unsigned int i); //��С�ѵ��±�Ϊi��Ԫ�ؽ����³�����

public:
    MinHeap(T array[], unsigned int n = 0);  //������С��

    unsigned int Size() const; //��ȡ���ݸ���
    bool isEmpty() const; //�п�
    void push(T elem); //������Ԫ��
    T getMin() const; //��ȡ��С�ѵ���СԪ��(�Ѷ�Ԫ��)
    T pop(); //ɾ����������СԪ��(�Ѷ�Ԫ��)

    void print()const; //��ӡ��С��
};


/**
 * �����±�Ϊi�Ľڵ㣺
 * �����±� 2 * i + 1           //������i����һ��+1
 * �Һ����±� 2 * i + 2           //�Һ���������+1
 * ���ڵ��±� (i - 1) / 2 (ȡ��)   //������
 *            0
 *           /  \
 *          1    2
 *         / \  / \
 *        3  4  5  6
 */




#include"minHeap.cpp"
