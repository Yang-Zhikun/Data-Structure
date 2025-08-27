/**
 * @brief 基于数组的哈希表，采用链式地址法(动态数组代替链表)解决冲突
 * @details key为整数类型，val为模板类型 
 *         哈希表的每个桶都是一个动态数组，用于存储键值对。
 *         当哈希表的负载因子(键值对数量/桶数量)超过一定阈值时，进行扩容操作，将桶数量扩大为原来的extendRatio倍，并重新哈希所有键值对。
 */
#pragma once
#include <vector>

template<typename T>
class ArrayHashMap {
private:
    class Pair{
        int key; 
        T val;
    };

    vector<vector<Pair>> buckets; // 桶数组，储存键值对数组
    int size; // 哈希表大小(键值对数量)
    int capacity; // 哈希表容量(桶数量)
    int extendRatio; // 扩容倍数

    int hashFunc(int key); // 哈希函数



public:
    ArrayHashMap(); // 构造函数
    ~ArrayHashMap(); // 析构函数


    T get(int key);
    void put(int key, T val);
    void remove(int key);
    

};



#include "ArrayHashMap.cpp"