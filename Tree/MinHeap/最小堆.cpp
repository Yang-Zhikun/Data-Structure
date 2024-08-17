#include<iostream>
#include<vector>
using namespace std;

/**
 * ��С��
 */
template<typename T>
class MinHeap {
protected:
    vector<T> HeapArray; //�����С�ѵ�����(�±��0��ʼ)
    
    unsigned int getLeftChild(unsigned int i) const; //��ȡλ��Ϊi�Ľڵ�����ӵ��±�
    unsigned int getRightChild(unsigned int i) const; //��ȡλ��Ϊi�Ľڵ���Һ��ӵ��±�
    unsigned int getParent(unsigned int i) const; //��ȡλ��Ϊi�Ľڵ�ĸ��ڵ���±�
    
    void shiftUp();   //��С�ѵ��ϸ�����
    void shiftDown(); //��С�ѵ��³�����
    
    void buildHeap(); //������С��
    
public:
    MinHeap(T array[] = nullptr, unsigned int n = 0);  //���캯��
    MinHeap(const MinHeap& obj); //�������캯��
    MinHeap<T>& operator=(const MinHeap& obj); //��ֵ�����
    
    bool isEmpty() const; //�п�
    void insert(const T elem); //������Ԫ��
    void getMin() const; //��ȡ��С�ѵ���СԪ��(�Ѷ�Ԫ��)
    void remove(); //ɾ����������СԪ��
};



int main(){
    
}