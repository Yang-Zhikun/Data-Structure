#pragma once
//�������� Huffman Tree

/**
 * ��������
 */
template <typename T>
class HuffmanTree {
protected:
    struct HuffmanTreeNode {  // ���������ڵ�
        T data;                      // �ڵ�����
        unsigned int weight;         // �ڵ�Ȩֵ
        unsigned int leftChild;      // ���ӽڵ��λ��
        unsigned int rightChild;     // �Һ��ӽڵ��λ��
        unsigned int parent;         // ���ڵ��λ��
    };

    struct HuffmanCode { // ����������
        T data;
        unsigned int code;
    };
        
            unsigned int size;//�ַ�����

public:
};

#include "HuffmanTree.cpp"
