#include<iostream>
#include<stdio.h>
#include<stdexcept>
#include<time.h>
using namespace std;

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
    MinHeap(T array[] = nullptr, unsigned int n = 0);  //������С��

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
            
            // ����Һ��ӱ����Ӹ�С(������ȵ�ǰ�ڵ�С)���͸���smallest
            if(rightChild < size && HeapArray[rightChild] < HeapArray[leftChild]) {
                smallest = rightChild;
            }
        }

        // ��������ifûִ��(smallestδ����)��˵����ǰ���κ�һ���ڵ㶼С����ֱ������
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





int main() {
    int arr[200];
    srand(time(0));
    for(int i=0;i<=10;i++){
        arr[i] = rand()%10;
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
    MinHeap<int> heap(arr, 11);
    heap.print();
    while(!heap.isEmpty()){
        cout<<heap.pop()<<endl;
    }
    system("pause");
}