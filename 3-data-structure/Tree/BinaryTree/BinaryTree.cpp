#include"BinaryTree.h"
#include<iostream>
#include<stdio.h>
#include<queue>
#include<stack>
using namespace std;

///////////////////共有成员函数/////////////////////////////////////

/**
 * 根据输入序列前序创建二叉树
 * @param inputList 输入序列：存放二叉树节点数据的一维数组
 * @param nullFlag 输入序列中代表节点为空的标志
*/
template<typename T>
BinaryTree<T>::BinaryTree(T inputList[], T nullFlag) {
    this->inputList = inputList;
    this->nullFlag = nullFlag;
    inputList_index = 0; // 创建二叉树的输入序列的下标从0开始
    preCreatBinaryTree(root);
}

/**
 * 拷贝构造函数
 * @param obj 被拷贝的二叉树
*/
template<typename T>
BinaryTree<T>::BinaryTree(const BinaryTree& obj) {
    this->inputList = obj.inputList;
    this->nullFlag = obj.nullFlag;
    inputList_index = 0;
    preCreatBinaryTree(root);
}

/**
 * 赋值运算符
 * @param obj 被赋值的二叉树
*/
template<typename T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree& obj) {
    if (*this != obj) {
        this->inputList = obj.inputList;
        this->nullFlag = obj.nullFlag;
        inputList_index = 0;
        preCreatBinaryTree(root);
    }
    return *this;
}

/**
 * 清空二叉树
*/
template<typename T>
void BinaryTree<T>::clear() {
    clear(root);
    root = nullptr; //root置空，防止野指针
}

/**
 * 判断二叉树是否为空
*/
template<typename T>
bool BinaryTree<T>::isEmpty()const {
    return root == nullptr;
}

/**
 * 获取二叉树的高度
*/
template<typename T>
unsigned int BinaryTree<T>::height()const {
    return height(root);
}

/**
 * 获取二叉树节点总数
*/
template<typename T>
unsigned int BinaryTree<T>::nodeNum()const {
    return nodeNum(root);
}

/**
 * 获取二叉树叶子节点数
*/
template<typename T>
unsigned int BinaryTree<T>::leafNum()const {
    return leafNum(root);
}

/**
 * 前序遍历
*/
template<typename T>
void BinaryTree<T>::preOrderTraverse()const {
    preOrderTraverse(root);
    cout << '\n';
}

/**
 * 中序遍历
*/
template<typename T>
void BinaryTree<T>::inOrderTraverse()const {
    inOrderTraverse(root);
    cout << '\n';
}

/**
 * 后序遍历
*/
template<typename T>
void BinaryTree<T>::postOrderTraverse()const {
    postOrderTraverse(root);
    cout << '\n';
}

/**
 * 层序遍历(广度优先遍历)
*/
template<typename T>
void BinaryTree<T>::levelOrderTraverse()const {
    if (root == nullptr) return; //根节点为空，无法遍历
    queue<Node*> que; // 初始化队列，存放节点的指针
    que.push(root); // 根节点入队
    while (!que.empty()) {
        Node* p = que.front(); //取队首元素
        que.pop();//出队
        cout << p->data << ' '; //访问当前节点的数据
        if (p->leftChild != nullptr)
            que.push(p->leftChild); // 如果当前节点有左孩子，则左子树入队
        if (p->rightChild != nullptr)
            que.push(p->rightChild);  // 如果当前节点有右孩子，则右子树入队
    }
    cout << '\n';
}

/**
 * 非递归方式实现前序遍历
*/
template<typename T>
// 前序遍历非递归实现
void BinaryTree<T>::preOrderTraverseWithStack()const {
    if (root == nullptr) return; // 如果根节点为空，则直接返回

    stack<Node*> stk; // 创建一个栈来存储节点
    stk.push(root); // 将根节点压入栈

    while (!stk.empty()) { // 当栈不为空时循环
        Node* node = stk.top(); // 取出栈顶元素
        stk.pop(); // 弹出栈顶元素

        // 访问节点
        cout << node->data << " ";

        // 注意压栈顺序，先右后左，保证左子树先被遍历(栈后进先出的特性)
        if (node->rightChild != nullptr) {
            stk.push(node->rightChild);
        }
        if (node->leftChild != nullptr) {
            stk.push(node->leftChild);
        }
    }
    cout << '\n';
}



//////////////////////私有成员函数/////////////////////////////////////

/**
 * 清空二叉树
 * @param root 二叉树的根节点
*/
template<typename T>
void BinaryTree<T>::clear(Node* root) {
    if (root == nullptr) return;  //如果根节点为空就结束
    if (root->leftChild != nullptr)
        clear(root->leftChild); //左子树非空，清空左子树
    if (root->rightChild != nullptr)
        clear(root->rightChild); //右子树非空，清空右子树
    delete root; //删除根节点
    root = nullptr;
}

/**
 * 二叉树的高度
 * @param root 二叉树的根节点
*/
template<typename T>
unsigned int BinaryTree<T>::height(Node* root)const {
    if (root == nullptr) return 0; //根节点为空就结束
    //否则返回1(当前根节点)加上左右子树高度的较大者
    return 1 + max(height(root->leftChild), height(root->rightChild));
}

/**
 * 二叉树的节点总数
 * @param root 二叉树的根节点
*/
template<typename T>
unsigned int BinaryTree<T>::nodeNum(Node* root)const {
    if (root == nullptr) return 0; //如果根节点为空就结束
    //否则返回1(当前根节点)+左右子树的节点总数
    return 1 + nodeNum(root->leftChild) + nodeNum(root->rightChild);
}

/**
 * 二叉树的叶子数
 * @param root 二叉树的根节点
*/
template<typename T>
unsigned int BinaryTree<T>::leafNum(Node* root)const {
    if (root == nullptr) return 0;//如果根节点为空就结束
    if (root->leftChild == nullptr && root->rightChild == nullptr)
        return 1;  //如果当前节点没有左右孩子则该节点是叶子节点，返回1
    else //如果当前节点不是终端节点(叶子)就返回左右子树的叶子节点之和
        return leafNum(root->leftChild) + leafNum(root->rightChild);
}

/**
 * 前序遍历
 * @param root 二叉树的根节点
*/
template<typename T>
void BinaryTree<T>::preOrderTraverse(Node* root)const {
    if (root == nullptr) return; //如果根节点为空就结束
    cout << root->data << ' '; //访问当前节点
    preOrderTraverse(root->leftChild); // 遍历左子树
    preOrderTraverse(root->rightChild);  // 遍历右子树

    /**
     * 另一种前序遍历的写法
     */
    /*
    while (root != nullptr) {
        cout << root->data << " "; //访问当前节点
        preOrderTraverse(root->leftChild); // 遍历左子树
        root = root->rightChild; // 切换到右子树进行遍历
    }
    */
}

/**
 * 中序遍历
 * @param root 二叉树的根节点
*/
template<typename T>
void BinaryTree<T>::inOrderTraverse(Node* root)const {
    /*if (root == nullptr) return; //如果根节点为空就结束
    inOrderTraverse(root->leftChild); // 遍历左子树
    cout << root->data << ' '; //访问当前节点
    inOrderTraverse(root->rightChild);  // 遍历右子树*/

    /**
     * 另一种中序遍历的写法
     */

    while (root != nullptr) {
        inOrderTraverse(root->leftChild); // 遍历左子树
        cout << root->data << " "; //访问当前节点
        root = root->rightChild; // 切换到右子树进行遍历
    }

}

/**
 * 后序遍历
 * @param root 二叉树的根节点
*/
template<typename T>
void BinaryTree<T>::postOrderTraverse(Node* root)const {
    if (root == nullptr) return; //如果根节点为空就结束
    postOrderTraverse(root->leftChild); // 遍历左子树
    postOrderTraverse(root->rightChild);  // 遍历右子树
    cout << root->data << ' '; //访问当前节点
}

/**
 * 根据输入序列前序创建二叉树
 * @param inputList 输入序列：存放二叉树节点数据的一维数组
 * @param nullFlag 输入序列中代表节点为空的标志
 * @param root 二叉树的根节点
*/
template<typename T>
void BinaryTree<T>::preCreatBinaryTree(Node*& root) {
    T data = inputList[inputList_index];
    inputList_index++;
    if (data == nullFlag) { //输入的数据为空，创建空节点
        root = nullptr;
        return;
    }
    root = new Node(data);
    preCreatBinaryTree(root->leftChild); // 递归创建左子树
    preCreatBinaryTree(root->rightChild); // 递归创建右子树
}
