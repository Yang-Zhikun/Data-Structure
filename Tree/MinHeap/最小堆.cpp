#include<iostream>
#include<stdio.h>
#include<stdexcept>
#include<time.h>
using namespace std;

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



/**
 * 获取下标为i的节点的左孩子的下标
 * @param i 当前节点的下标
 */
template<typename T>
unsigned int MinHeap<T>::getLeftChild(unsigned int i)const {
    return 2 * i + 1;
}

/**
 * 获取下标为i的节点的右孩子的下标
 * @param i 当前节点的下标
 */
template<typename T>
unsigned int MinHeap<T>::getRightChild(unsigned int i)const {
    return 2 * i + 2;
}

/**
 * 获取下标为i的节点的父节点的下标
 * @param i 当前节点的下标
 */
template<typename T>
unsigned int MinHeap<T>::getParent(unsigned int i)const {
    return (i - 1) / 2;
}


/**
 * 最小堆的下标为i的元素进行上浮调整
 * @param i 当前节点的下标
 */
template<typename T>
void MinHeap<T>::shiftUp(unsigned int i) {
    unsigned int parent = getParent(i); // 获取当前节点的父节点的下标
    T tmp = HeapArray[i]; // 保存当前节点，用于最后赋值

    //如果当前节点有父节点且比父节点小，则进行上浮调整(父节点下移到当前节点的位置)
    while(i > 0 && tmp < HeapArray[parent]) {
        HeapArray[i] = HeapArray[parent]; // 父节点下移到当前节点(子节点)的位置
        // 两个下标都上移，继续循环
        i = parent;
        parent = getParent(parent);
    }
    //最后赋值
    HeapArray[i] = tmp;
}

/**
 * 最小堆的下标为i的元素进行下沉调整
 * @param i 当前节点的下标
 */
template<typename T>
void MinHeap<T>::shiftDown(unsigned int i) {
    unsigned int leftChild, rightChild, smallest;
    T tmp = HeapArray[i];
    //如果当前节点有子节点且比子节点大，则进行下沉调整(子节点上移到当前节点)
    while(true) {
        leftChild = getLeftChild(i);
        rightChild = getRightChild(i);
        smallest = i; // 当前节点的最小的孩子的下标

        //查找当前节点的最小的孩子，确保最小的元素在上面
        // 如果左孩子比当前节点小，就更新smallest
        if(leftChild < size && HeapArray[leftChild] < tmp) {
            smallest = leftChild;
            
            // 如果右孩子比左孩子更小(已满足比当前节点小)，就更新smallest
            if(rightChild < size && HeapArray[rightChild] < HeapArray[leftChild]) {
                smallest = rightChild;
            }
        }

        // 如果上面的if没执行(smallest未更改)，说明当前比任何一个节点都小，就直接跳出
        if(i == smallest) {
            break;
        }
        //否则进行下沉调整(最小的孩子上移到当前节点的位置)
        HeapArray[i] = HeapArray[smallest];
        //下标下移，继续循环
        i = smallest;
    }
    // 最后赋值
    HeapArray[i] = tmp;
}


/**
 * 构造最小堆
 * @param array 待堆化的数组
 * @param n 数组中数据个数(不是数组的最大长度)
 */
template<typename T>
MinHeap<T>::MinHeap(T array[], unsigned int n) {
    this->HeapArray = array;
    this->size = n;
    // 从最后一个分支节点(最后一个节点的父节点)开始，从下到上进行堆化(下沉调整)
    for(unsigned int i = getParent(size - 1); i >= 0; i--) {
        shiftDown(i);
        if(i == 0) break; // i等于0时要跳出，否则执行i--，会出错
    }
}

/**
 * 最小堆是否为空
 */
template<typename T>
bool MinHeap<T>::isEmpty()const {
    return size == 0;
}

/**
 * 插入新元素。插入新元素前请确保不会超过数组的最大长度
 * @param elem 待插入的新元素
 */
template<typename T>
void MinHeap<T>::push(T elem) {
    HeapArray[size] = elem; // 在数组末尾插入新元素
    size++;
    shiftUp(size - 1); // 对新插入的元素进行上浮调整
}

/**
 * 获取最小堆的最小元素(堆顶元素)
 */
template<typename T>
T MinHeap<T>::getMin()const {
    if(size == 0)
        throw std::out_of_range("最小堆为空");
    return HeapArray[0];
}

/**
 * 删除并返回最小元素(堆顶元素)
 */
template<typename T>
T MinHeap<T>::pop() {
    if(size == 0)
        throw std::out_of_range("最小堆为空");
    T tmp = HeapArray[0]; // 保存堆顶元素
    HeapArray[0] = HeapArray[size - 1]; // 将数组的最后一个元素补到堆顶
    size--;
    shiftDown(0); // 将新补到堆顶的元素进行下沉调整
    return tmp;
}

/**
 * 打印最小堆
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