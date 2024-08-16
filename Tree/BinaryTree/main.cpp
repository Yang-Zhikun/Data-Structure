#include"BinaryTree.h"
#include<iostream>
using namespace std;

int main(){
    int inputList[] = {1,2,4,7,0,0,8,0,0,5,9,0,0,10,0,0,3,0,6,11,0,0,12,0,0};
    //"ABDJ**K**EG**L**C*FH**I**";
    /*
               1
             /   \
            2      3
          /  \      \
         4    5      6
        / \  / \    / \
       7   8 9  10  11 12
    */
    BinaryTree<int> tree(inputList, 0);
    cout << "ǰ�������";
    tree.preOrderTraverse();
    cout << "�ǵݹ�ǰ��";
    tree.preOrderTraverseWithStack();
    cout << "���������";
    tree.postOrderTraverse();
    cout << "���������";
    tree.inOrderTraverse();
    cout << "���������";
    tree.levelOrderTraverse();
    printf("isEmpty: %d\n", tree.isEmpty());
    printf("�߶ȣ�%d\n", tree.height());
    printf("�ڵ�������%d\n", tree.nodeNum());
    printf("Ҷ������%d\n\n", tree.leafNum());

    tree.clear();
    cout << "ǰ�������";
    tree.preOrderTraverse();
    cout << "�ǵݹ�ǰ��";
    tree.preOrderTraverseWithStack();
    cout << "���������";
    tree.postOrderTraverse();
    cout << "���������";
    tree.inOrderTraverse();
    cout << "���������";
    tree.levelOrderTraverse();
    printf("isEmpty: %d\n", tree.isEmpty());
    printf("�߶ȣ�%d\n", tree.height());
    printf("�ڵ�������%d\n", tree.nodeNum());
    printf("Ҷ������%d\n\n", tree.leafNum());


    system("pause");
}