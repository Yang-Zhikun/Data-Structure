#pragma once

/**
 * ����������ʾ�Ķ�����
 */
template<typename T>
class BinaryTree {
private:
    struct Node { // һ����������Ľڵ�
        T data; // ������
        Node* leftChild; // ָ�����ӵ�ָ��
        Node* rightChild; // ָ���Һ��ӵ�ָ��

        Node(): leftChild(nullptr), rightChild(nullptr) {}  // �޲ι���
        Node(T data, Node* leftChild=nullptr, Node* rightChild=nullptr): data(data), leftChild(leftChild), rightChild(rightChild) {}
    };

    Node* root;   // �������ĸ��ڵ��ָ��

    T* inputList; // �������У���Ŷ������ڵ����ݵ�һά����
    T nullFlag; //���������д���ڵ�Ϊ�յı�־
    unsigned int inputList_index; // �������������������е��±�

    //˽�г�Ա����
    void clear(Node* root);                     //���
    unsigned int height(Node* root)const;       //�������ĸ߶�
    unsigned int nodeNum(Node* root)const;      //�������Ľڵ�����
    unsigned int leafNum(Node* root)const;      //��������Ҷ����
    void preOrderTraverse(Node* root)const;     //ǰ�����
    void inOrderTraverse(Node* root)const;      //�������
    void postOrderTraverse(Node* root)const;    //�������
    void preCreatBinaryTree(Node* &root); //ǰ�򴴽�������

public:
    BinaryTree() {
        root = nullptr;    //�޲ι���
    }
    BinaryTree(T inputList[], T nullFlag);  //ǰ�򴴽�������
    ~BinaryTree() {
        clear();    //��������
    }
    BinaryTree(const BinaryTree& obj);  //�������캯��
    BinaryTree<T>& operator=(const BinaryTree& obj); //��ֵ�����

    //���г�Ա����
    void clear();                     //���
    bool isEmpty()const;              //�п�
    unsigned int height()const;       //�������ĸ߶�
    unsigned int nodeNum()const;      //�������Ľڵ�����
    unsigned int leafNum()const;      //��������Ҷ����
    void preOrderTraverse()const;     //ǰ�����
    void inOrderTraverse()const;      //�������
    void postOrderTraverse()const;    //�������
    void levelOrderTraverse()const;   //�������(������ȱ���)
    void preOrderTraverseWithStack()const;    //�ǵݹ鷽ʽʵ��ǰ�����
};

#include"BinaryTree.cpp"