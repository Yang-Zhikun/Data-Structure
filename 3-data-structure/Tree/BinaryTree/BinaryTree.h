#pragma once

/**
 * 二叉链表法表示的二叉树
 */
template<typename T>
class BinaryTree {
private:
    struct Node { // 一个二叉链表的节点
        T data; // 数据域
        Node* leftChild; // 指向左孩子的指针
        Node* rightChild; // 指向右孩子的指针

        Node(): leftChild(nullptr), rightChild(nullptr) {}  // 无参构造
        Node(T data, Node* leftChild=nullptr, Node* rightChild=nullptr): data(data), leftChild(leftChild), rightChild(rightChild) {}
    };

    Node* root;   // 二叉树的根节点的指针

    T* inputList; // 输入序列：存放二叉树节点数据的一维数组
    T nullFlag; //输入序列中代表节点为空的标志
    unsigned int inputList_index; // 创建二叉树的输入序列的下标

    //私有成员函数
    void clear(Node* root);                     //清空
    unsigned int height(Node* root)const;       //二叉树的高度
    unsigned int nodeNum(Node* root)const;      //二叉树的节点总数
    unsigned int leafNum(Node* root)const;      //二叉树的叶子数
    void preOrderTraverse(Node* root)const;     //前序遍历
    void inOrderTraverse(Node* root)const;      //中序遍历
    void postOrderTraverse(Node* root)const;    //后序遍历
    void preCreatBinaryTree(Node* &root); //前序创建二叉树

public:
    BinaryTree() {
        root = nullptr;    //无参构造
    }
    BinaryTree(T inputList[], T nullFlag);  //前序创建二叉树
    ~BinaryTree() {
        clear();    //析构函数
    }
    BinaryTree(const BinaryTree& obj);  //拷贝构造函数
    BinaryTree<T>& operator=(const BinaryTree& obj); //赋值运算符

    //共有成员函数
    void clear();                     //清空
    bool isEmpty()const;              //判空
    unsigned int height()const;       //二叉树的高度
    unsigned int nodeNum()const;      //二叉树的节点总数
    unsigned int leafNum()const;      //二叉树的叶子数
    void preOrderTraverse()const;     //前序遍历
    void inOrderTraverse()const;      //中序遍历
    void postOrderTraverse()const;    //后序遍历
    void levelOrderTraverse()const;   //层序遍历(广度优先遍历)
    void preOrderTraverseWithStack()const;    //非递归方式实现前序遍历
};

#include"BinaryTree.cpp"