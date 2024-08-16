#pragma once
//哈夫曼树 Huffman Tree

/**
 * 哈夫曼树
 */
template <typename T>
class HuffmanTree {
protected:
    struct HuffmanTreeNode {  // 哈夫曼树节点
        T data;                      // 节点数据
        unsigned int weight;         // 节点权值
        unsigned int leftChild;      // 左孩子节点的位序
        unsigned int rightChild;     // 右孩子节点的位序
        unsigned int parent;         // 父节点的位序
    };

    struct HuffmanCode { // 哈夫曼编码
        T data;
        unsigned int code;
    };
        
            unsigned int size;//字符个数

public:
};

#include "HuffmanTree.cpp"
