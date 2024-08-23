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
    if (i == 0) {
        return; // ���ڵ㲻�õ���
    }
    unsigned int parent = getParent(i); // ��ȡ��ǰ�ڵ�ĸ��ڵ���±�
    T tmp = HeapArray[i]; // ���浱ǰ�ڵ㣬�������ֵ

    //�����ǰ�ڵ��и��ڵ��ұȸ��ڵ�С��������ϸ�����(���ڵ����Ƶ���ǰ�ڵ��λ��)
    while (i > 0 && tmp < HeapArray[parent]) {
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
    if (i >= size) {
        return; // Խ�粻�õ���(û���ӽڵ�)
    }
    unsigned int leftChild, rightChild, smallest;
    T tmp = HeapArray[i];
    //�����ǰ�ڵ����ӽڵ��ұ��ӽڵ��������³�����(�ӽڵ����Ƶ���ǰ�ڵ�)
    while (true) {
        leftChild = getLeftChild(i);
        rightChild = getRightChild(i);
        smallest = i; // ��ǰ�ڵ����С�ĺ��ӵ��±�

        //���ҵ�ǰ�ڵ����С�ĺ��ӣ�ȷ����С��Ԫ��������
        // ������ӱȵ�ǰ�ڵ�С���͸���smallest
        if (leftChild < size && HeapArray[leftChild] < tmp) {
            smallest = leftChild;
        }
        // ����Һ��ӱȵ�ǰ�ڵ�С���ұ����Ӹ�С���͸���smallest
        if (rightChild < size && HeapArray[rightChild] < tmp && HeapArray[rightChild] < HeapArray[leftChild]) {
            smallest = rightChild;
        }
        // ������������ifûִ��(smallestδ����)��˵����ǰ���κ�һ���ڵ㶼С����ֱ������
        if (i == smallest) {
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
    if (size <= 1) return; // ֻ��һ��Ԫ�ػ�û��Ԫ�أ�����Ҫ�ѻ�

    // �����һ����֧�ڵ�(���һ���ڵ�ĸ��ڵ�)��ʼ�����µ��Ͻ��жѻ�(�³�����)
    for (unsigned int i = getParent(size - 1); i >= 0; i--) {
        shiftDown(i);
        if (i == 0) break; // i����0ʱҪ����������ִ��i--�������
    }
}

/**
 * ��ȡ��С���ȶ��е����ݸ���
 */
template<typename T>
unsigned int MinHeap<T>::Size() const {
    return size;
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
    if (size == 0)
        throw std::out_of_range("��С��Ϊ��");
    return HeapArray[0];
}

/**
 * ɾ����������СԪ��(�Ѷ�Ԫ��)
 */
template<typename T>
T MinHeap<T>::pop() {
    if (size == 0)
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
    for (unsigned int i = 0; i < size; i++) {
        cout << HeapArray[i] << ' ';
    }
    cout << '\n';
}





/**
 * ��С���ȶ���
 */
template<typename T>
class Min_priority_queue {
protected:
    T* data;              // ������ݵ�����
    unsigned int maxLen;  // �������󳤶�

    MinHeap<T>* heap;      //��С��

    void resize(); // ����

public:
    Min_priority_queue(unsigned int maxLen = 1); // ���캯��
    ~Min_priority_queue() {
        delete[] data;
        delete heap;
    }

    unsigned int size()const; //��ȡ��С���ȶ��е����ݸ���
    bool isEmpty() const; //�п�
    void push(T elem); //������Ԫ��
    T getMin() const; //��ȡ��С�ѵ���СԪ��(��ͷԪ��)
    T pop(); //ɾ����������СԪ��(��ͷԪ��)

    void print() {
        heap->print();
    }
};


/**
 * ���캯��
*/
template<typename T>
Min_priority_queue<T>::Min_priority_queue(unsigned int maxLen) :maxLen(maxLen) {
    if (maxLen == 0) maxLen = 1;
    data = new T[maxLen];
    heap = new MinHeap<T>(data, 0); // �½���
}

/**
 * ��ȡ��С���ȶ��е����ݸ���
 */
template<typename T>
unsigned int Min_priority_queue<T>::size() const {
    return heap->Size();
}

/**
 * �п�
 */
template<typename T>
bool Min_priority_queue<T>::isEmpty() const {
    return heap->isEmpty();
}

/**
 * ���
 * @param elem ���Ԫ��
 */
template<typename T>
void Min_priority_queue<T>::push(T elem) {
    if (heap->Size() == maxLen - 1) {
        resize();
    }
    heap->push(elem);
}

/**
 * ��ȡ��СԪ��(��ͷԪ��)
 */
template<typename T>
T Min_priority_queue<T>::getMin() const {
    return heap->getMin();
}

/**
 * ɾ����������СԪ��(��ͷԪ��)
 */
template<typename T>
T Min_priority_queue<T>::pop() {
    return heap->pop();
}

/**
 * ����
 */
template<typename T>
void Min_priority_queue<T>::resize() {
    maxLen = maxLen * 2;
    T* data2 = new T[maxLen];
    unsigned int size = heap->Size();
    for (unsigned int i = 0; i < size; i++) {
        data2[i] = data[i];
    }
    delete[] data;
    data = data2;
    delete heap;
    heap = new MinHeap<T>(data, size);
}







int main() {
    srand(time(0));
    Min_priority_queue<int> q;
    for (int i = 0; i <= 100; i++) {
        int e = rand() % 100;
        cout << e << ' ';
        q.push(e);
    }
    cout << '\n';
    q.print();
    cout << '\n';
    while (!q.isEmpty()) {
        cout << q.pop() << endl;
    }
    system("pause");
}