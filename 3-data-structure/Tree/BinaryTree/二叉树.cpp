//��������ʵ�ֵĶ�����
#include<iostream>
#include<stdio.h>
#include<queue>
#include<stack>
using namespace std;

template<typename T>
class BinaryTree {
private:
    struct Node { // һ����������Ľڵ�
        T data; // ������
        Node* leftChild; // ָ�����ӵ�ָ��
        Node* rightChild; // ָ���Һ��ӵ�ָ��

        Node() : leftChild(nullptr), rightChild(nullptr) {}  // �޲ι���
        Node(T data, Node* leftChild = nullptr, Node* rightChild = nullptr) : data(data), leftChild(leftChild), rightChild(rightChild) {}
    };

    Node* root;   // �������ĸ��ڵ��ָ��

    T* inputList;
    T nullFlag;
    unsigned int inputList_index; // �������������������е��±�

    //˽�г�Ա����
    void clear(Node* root);                     //���
    unsigned int height(Node* root)const;       //�������ĸ߶�
    unsigned int nodeNum(Node* root)const;      //�������Ľڵ�����
    unsigned int leafNum(Node* root)const;      //��������Ҷ����
    void preOrderTraverse(Node* root)const;     //ǰ�����
    void inOrderTraverse(Node* root)const;      //�������
    void postOrderTraverse(Node* root)const;    //�������
    void preCreatBinaryTree(Node*& root); //ǰ�򴴽�������

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
    unsigned int nodeNum()const;         //�������Ľڵ�����
    unsigned int leafNum()const;      //��������Ҷ����
    void preOrderTraverse()const;     //ǰ�����
    void inOrderTraverse()const;      //�������
    void postOrderTraverse()const;    //�������
    void levelOrderTraverse()const;   //�������(������ȱ���)
    void preOrderTraverseWithStack()const;    //�ǵݹ鷽ʽʵ��ǰ�����
    void inOrderTraverseWithStack()const;    //�ǵݹ鷽ʽʵ���������
    void postOrderTraverseWithStack()const;   //�ǵݹ鷽ʽʵ�ֺ������
};


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
    root = nullptr;
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

/**
 * ǰ�򴴽�������
 */
template<typename T>
void preCreatBinaryTree(T inputList[], T nullFlag){
    this->inputList = inputList;
    this->nullFlag = nullFlag;
    this->inputList_index = 0;
    preCreatBinaryTree(root);
}


///////////////////˽�г�Ա����/////////////////////////////////////

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
    printf("delete\n");
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
}

/**
 * �������
 * @param root �������ĸ��ڵ�
*/
template<typename T>
void BinaryTree<T>::inOrderTraverse(Node* root)const {
    if (root == nullptr) return; //������ڵ�Ϊ�վͽ���
    inOrderTraverse(root->leftChild); // ����������
    cout << root->data << ' '; //���ʵ�ǰ�ڵ�
    inOrderTraverse(root->rightChild);  // ����������
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

/**
 * �ǵݹ鷽ʽʵ���������
 */
template<typename T>
void BinaryTree<T>::inOrderTraverseWithStack() const {
    Node* root = this->root;
    stack<Node*> s;
    while (true) {
        if (root != nullptr) { //�����ǰ�ڵ㲻Ϊ�գ��򽫵�ǰ�ڵ���ջ
            s.push(root);
            root = root->leftChild;
        }
        else if (!s.empty()) { //���ջ��Ϊ�գ����ջһ���ڵ�
            root = s.top();
            cout << root->data << ' ';
            s.pop();
            root = root->rightChild;
        }
        else break;
    }
    cout << "\n";
}






int main() {
    char inputList[] = "ABDJ**K**EG**L**C*FH**I**";
    /*
               A
             /   \
            B      C
          /  \      \
         D    E      F
        / \  / \    / \
       J   K G  L   H   I
    */
    BinaryTree<char> tree(inputList, '*');
    cout << "ǰ�������";
    tree.preOrderTraverse();
    cout << "�ǵݹ�ǰ��";
    tree.preOrderTraverseWithStack();
    cout << "�ǵݹ��";
    tree.postOrderTraverseWithStack();
    cout << "���������";
    tree.postOrderTraverse();
    cout << "���������";
    tree.inOrderTraverse();
    cout << "�ǵݹ��У�";
    tree.inOrderTraverseWithStack();
    cout << "���������";
    tree.levelOrderTraverse();
    printf("isEmpty: %d\n", tree.isEmpty());
    printf("�߶ȣ�%d\n", tree.height());
    printf("�ڵ�������%d\n", tree.nodeNum());
    printf("Ҷ������%d\n\n", tree.leafNum());

    BinaryTree<char> tree2 = tree;
    tree.clear();
    cout << "ǰ�������";
    tree2.preOrderTraverse();
    cout << "���������";
    tree2.postOrderTraverse();
    cout << "���������";
    tree2.inOrderTraverse();
    cout << "���������";
    tree2.levelOrderTraverse();
    printf("isEmpty: %d\n", tree2.isEmpty());
    printf("�߶ȣ�%d\n", tree2.height());
    printf("�ڵ�������%d\n", tree2.nodeNum());
    printf("Ҷ������%d\n", tree2.leafNum());

    system("pause");
}