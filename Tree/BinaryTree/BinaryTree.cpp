#include"BinaryTree.h"
#include<iostream>
#include<stdio.h>
#include<queue>
#include<stack>
using namespace std;

///////////////////���г�Ա����/////////////////////////////////////

/**
 * ������������ǰ�򴴽�������
 * @param inputList �������У���Ŷ������ڵ����ݵ�һά����
 * @param nullFlag ���������д���ڵ�Ϊ�յı�־
*/
template<typename T>
BinaryTree<T>::BinaryTree(T inputList[], T nullFlag) {
    this->inputList = inputList;
    this->nullFlag = nullFlag;
    inputList_index = 0; // �������������������е��±��0��ʼ
    preCreatBinaryTree(root);
}

/**
 * �������캯��
 * @param obj �������Ķ�����
*/
template<typename T>
BinaryTree<T>::BinaryTree(const BinaryTree& obj) {
    this->inputList = obj.inputList;
    this->nullFlag = obj.nullFlag;
    inputList_index = 0;
    preCreatBinaryTree(root);
}

/**
 * ��ֵ�����
 * @param obj ����ֵ�Ķ�����
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
 * ��ն�����
*/
template<typename T>
void BinaryTree<T>::clear() {
    clear(root);
    root = nullptr; //root�ÿգ���ֹҰָ��
}

/**
 * �ж϶������Ƿ�Ϊ��
*/
template<typename T>
bool BinaryTree<T>::isEmpty()const {
    return root == nullptr;
}

/**
 * ��ȡ�������ĸ߶�
*/
template<typename T>
unsigned int BinaryTree<T>::height()const {
    return height(root);
}

/**
 * ��ȡ�������ڵ�����
*/
template<typename T>
unsigned int BinaryTree<T>::nodeNum()const {
    return nodeNum(root);
}

/**
 * ��ȡ������Ҷ�ӽڵ���
*/
template<typename T>
unsigned int BinaryTree<T>::leafNum()const {
    return leafNum(root);
}

/**
 * ǰ�����
*/
template<typename T>
void BinaryTree<T>::preOrderTraverse()const {
    preOrderTraverse(root);
    cout << '\n';
}

/**
 * �������
*/
template<typename T>
void BinaryTree<T>::inOrderTraverse()const {
    inOrderTraverse(root);
    cout << '\n';
}

/**
 * �������
*/
template<typename T>
void BinaryTree<T>::postOrderTraverse()const {
    postOrderTraverse(root);
    cout << '\n';
}

/**
 * �������(������ȱ���)
*/
template<typename T>
void BinaryTree<T>::levelOrderTraverse()const {
    if (root == nullptr) return; //���ڵ�Ϊ�գ��޷�����
    queue<Node*> que; // ��ʼ�����У���Žڵ��ָ��
    que.push(root); // ���ڵ����
    while (!que.empty()) {
        Node* p = que.front(); //ȡ����Ԫ��
        que.pop();//����
        cout << p->data << ' '; //���ʵ�ǰ�ڵ������
        if (p->leftChild != nullptr)
            que.push(p->leftChild); // �����ǰ�ڵ������ӣ������������
        if (p->rightChild != nullptr)
            que.push(p->rightChild);  // �����ǰ�ڵ����Һ��ӣ������������
    }
    cout << '\n';
}

/**
 * �ǵݹ鷽ʽʵ��ǰ�����
*/
template<typename T>
// ǰ������ǵݹ�ʵ��
void BinaryTree<T>::preOrderTraverseWithStack()const {
    if (root == nullptr) return; // ������ڵ�Ϊ�գ���ֱ�ӷ���

    stack<Node*> stk; // ����һ��ջ���洢�ڵ�
    stk.push(root); // �����ڵ�ѹ��ջ

    while (!stk.empty()) { // ��ջ��Ϊ��ʱѭ��
        Node* node = stk.top(); // ȡ��ջ��Ԫ��
        stk.pop(); // ����ջ��Ԫ��

        // ���ʽڵ�
        cout << node->data << " ";

        // ע��ѹջ˳�����Һ��󣬱�֤�������ȱ�����(ջ����ȳ�������)
        if (node->rightChild != nullptr) {
            stk.push(node->rightChild);
        }
        if (node->leftChild != nullptr) {
            stk.push(node->leftChild);
        }
    }
    cout << '\n';
}



//////////////////////˽�г�Ա����/////////////////////////////////////

/**
 * ��ն�����
 * @param root �������ĸ��ڵ�
*/
template<typename T>
void BinaryTree<T>::clear(Node* root) {
    if (root == nullptr) return;  //������ڵ�Ϊ�վͽ���
    if (root->leftChild != nullptr)
        clear(root->leftChild); //�������ǿգ����������
    if (root->rightChild != nullptr)
        clear(root->rightChild); //�������ǿգ����������
    delete root; //ɾ�����ڵ�
    root = nullptr;
}

/**
 * �������ĸ߶�
 * @param root �������ĸ��ڵ�
*/
template<typename T>
unsigned int BinaryTree<T>::height(Node* root)const {
    if (root == nullptr) return 0; //���ڵ�Ϊ�վͽ���
    //���򷵻�1(��ǰ���ڵ�)�������������߶ȵĽϴ���
    return 1 + max(height(root->leftChild), height(root->rightChild));
}

/**
 * �������Ľڵ�����
 * @param root �������ĸ��ڵ�
*/
template<typename T>
unsigned int BinaryTree<T>::nodeNum(Node* root)const {
    if (root == nullptr) return 0; //������ڵ�Ϊ�վͽ���
    //���򷵻�1(��ǰ���ڵ�)+���������Ľڵ�����
    return 1 + nodeNum(root->leftChild) + nodeNum(root->rightChild);
}

/**
 * ��������Ҷ����
 * @param root �������ĸ��ڵ�
*/
template<typename T>
unsigned int BinaryTree<T>::leafNum(Node* root)const {
    if (root == nullptr) return 0;//������ڵ�Ϊ�վͽ���
    if (root->leftChild == nullptr && root->rightChild == nullptr)
        return 1;  //�����ǰ�ڵ�û�����Һ�����ýڵ���Ҷ�ӽڵ㣬����1
    else //�����ǰ�ڵ㲻���ն˽ڵ�(Ҷ��)�ͷ�������������Ҷ�ӽڵ�֮��
        return leafNum(root->leftChild) + leafNum(root->rightChild);
}

/**
 * ǰ�����
 * @param root �������ĸ��ڵ�
*/
template<typename T>
void BinaryTree<T>::preOrderTraverse(Node* root)const {
    if (root == nullptr) return; //������ڵ�Ϊ�վͽ���
    cout << root->data << ' '; //���ʵ�ǰ�ڵ�
    preOrderTraverse(root->leftChild); // ����������
    preOrderTraverse(root->rightChild);  // ����������

    /**
     * ��һ��ǰ�������д��
     */
    /*
    while (root != nullptr) {
        cout << root->data << " "; //���ʵ�ǰ�ڵ�
        preOrderTraverse(root->leftChild); // ����������
        root = root->rightChild; // �л������������б���
    }
    */
}

/**
 * �������
 * @param root �������ĸ��ڵ�
*/
template<typename T>
void BinaryTree<T>::inOrderTraverse(Node* root)const {
    /*if (root == nullptr) return; //������ڵ�Ϊ�վͽ���
    inOrderTraverse(root->leftChild); // ����������
    cout << root->data << ' '; //���ʵ�ǰ�ڵ�
    inOrderTraverse(root->rightChild);  // ����������*/

    /**
     * ��һ�����������д��
     */

    while (root != nullptr) {
        inOrderTraverse(root->leftChild); // ����������
        cout << root->data << " "; //���ʵ�ǰ�ڵ�
        root = root->rightChild; // �л������������б���
    }

}

/**
 * �������
 * @param root �������ĸ��ڵ�
*/
template<typename T>
void BinaryTree<T>::postOrderTraverse(Node* root)const {
    if (root == nullptr) return; //������ڵ�Ϊ�վͽ���
    postOrderTraverse(root->leftChild); // ����������
    postOrderTraverse(root->rightChild);  // ����������
    cout << root->data << ' '; //���ʵ�ǰ�ڵ�
}

/**
 * ������������ǰ�򴴽�������
 * @param inputList �������У���Ŷ������ڵ����ݵ�һά����
 * @param nullFlag ���������д���ڵ�Ϊ�յı�־
 * @param root �������ĸ��ڵ�
*/
template<typename T>
void BinaryTree<T>::preCreatBinaryTree(Node*& root) {
    T data = inputList[inputList_index];
    inputList_index++;
    if (data == nullFlag) { //���������Ϊ�գ������սڵ�
        root = nullptr;
        return;
    }
    root = new Node(data);
    preCreatBinaryTree(root->leftChild); // �ݹ鴴��������
    preCreatBinaryTree(root->rightChild); // �ݹ鴴��������
}
