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
    cout << "前序遍历：";
    tree.preOrderTraverse();
    cout << "非递归前：";
    tree.preOrderTraverseWithStack();
    cout << "后序遍历：";
    tree.postOrderTraverse();
    cout << "中序遍历：";
    tree.inOrderTraverse();
    cout << "层序遍历：";
    tree.levelOrderTraverse();
    printf("isEmpty: %d\n", tree.isEmpty());
    printf("高度：%d\n", tree.height());
    printf("节点总数：%d\n", tree.nodeNum());
    printf("叶子数：%d\n\n", tree.leafNum());

    tree.clear();
    cout << "前序遍历：";
    tree.preOrderTraverse();
    cout << "非递归前：";
    tree.preOrderTraverseWithStack();
    cout << "后序遍历：";
    tree.postOrderTraverse();
    cout << "中序遍历：";
    tree.inOrderTraverse();
    cout << "层序遍历：";
    tree.levelOrderTraverse();
    printf("isEmpty: %d\n", tree.isEmpty());
    printf("高度：%d\n", tree.height());
    printf("节点总数：%d\n", tree.nodeNum());
    printf("叶子数：%d\n\n", tree.leafNum());


    system("pause");
}