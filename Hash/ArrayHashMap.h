/**
 * @brief 基于数组的哈希表，采用链式地址法解决冲突
 */
#pragma once
#include <vector>

template<typename T>
class ArrayHashMap {
private:
    class HashNode {
        int key; 
        T val;
    };

    vector<

public:
    ArrayHashMap(); // 构造函数
    ~ArrayHashMap(); // 析构函数


    T get(int key);
    void put(int key, T val);
    void remove(int key);
    

};