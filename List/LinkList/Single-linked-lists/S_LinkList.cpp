#include"S_LinkList.h"
#include<iostream>
#include<stdexcept>
//#include<stdio.h>


template<typename T>//构造函数
S_LinkList<T>::S_LinkList(){
    head = new node;//给头指针分配内存
    head->data = 0;
    head->next = nullptr;//单链表的头指针的指针域为空
    tail = head;//尾指针指向头节点
    length = 0;//单链表的长度为空
}

template<typename T>//析构函数
S_LinkList<T>::~S_LinkList(){
    clear();//清空单链表
    delete head;//释放头节点
    //delete tail;释放尾节点是错的，因为clear()后tail指向head，不能重复释放同一内存
}

template<typename T>//拷贝构造函数
S_LinkList<T>::S_LinkList(const S_LinkList & obj){
    head = new node;//给头结点申请内存
    head->data = 0;
    head->next = nullptr;
    tail = head;//尾指针指向头节点
    //用尾插法复制obj的数据
    
    for(node* p = obj.head->next; p != nullptr; p = p->next){
        node* newnode = new node;
        //将newnode插入到单链表末尾
        newnode->data = p->data;
        newnode->next = nullptr;
        tail->next = newnode;
        tail = newnode;
    }
    length = obj.length;
}

template<typename T>//赋值运算符
S_LinkList<T>& S_LinkList<T>::operator=(const S_LinkList & obj){
    if(*this != obj){//防止自赋值
        head = new node;//给头结点申请内存
        head->data = 0;
        head->next = nullptr;
        tail = head;//尾指针指向头节点
        //用尾插法复制obj的数据
        
        for(node* p = obj.head->next; p != nullptr; p = p->next){
            node* newnode = new node;
            //将newnode插入到单链表末尾
            newnode->data = p->data;
            newnode->next = nullptr;
            tail->next = newnode;
            tail = newnode;
        }
        length = obj.length;
    }
    return *this;
}


template<typename T>//获取单链表第i个节点的指针(i从1开始，i=0时返回头指针)
typename S_LinkList<T>::node* S_LinkList<T>::getNode(unsigned int i)const{
    if(i==0)
        return head;
    //当不满足 0 <= i <= length 时返回空指针
    else if(i<0 || i>length){
        return nullptr;
    }
    node *p;
    unsigned int ii = 1;
    p = head->next;//ii = 1
    while(ii<i){
        p = p->next;
        ii++;
    }
    return p;
}




template<typename T>//清空单链表
void S_LinkList<T>::clear(){
    node *p;//p是工作指针，防止移动头指针，丢失链表
    node *tmp;//tmp是临时指针，指向要释放的节点
    p = head->next;//p指向首元节点
    while(p!=nullptr){
        tmp = p;//tmp指向p现在的节点
        p = p->next;//p向后移一个节点
        delete tmp;
    }
    head->next = nullptr;//头指针的指针域置为空
    tail = head;//单链表的尾指针指向头节点
    length = 0;//单链表的长度为0
}

template<typename T>//遍历单链表
void S_LinkList<T>::traverse()const{
    node *p;
    for(p = head->next; p!=nullptr; p = p->next){
        cout<< p->data <<" ";
    }
    cout<<'\n';
}

template<typename T>//获取单链表第i个节点的数据(i从1开始)
T S_LinkList<T>::get(unsigned int i)const{
    node *p = getNode(i);
    if(p==nullptr)
        throw std::out_of_range("传入的位序i不合法");
    else
        return p->data;
}

template<typename T>//将第i个节点的数据设置为elem(1<=i<=length)
void S_LinkList<T>::set(unsigned int i, T elem){
    if(i<1 || i > length)
        throw std::out_of_range("传入的位序i不合法");
    //找到第i个节点
    node *p = getNode(i);//前面已经检查过i，p不可能是nullptr
    p->data = elem;
}

template<typename T>//在链表中查找elem, 返回第一个elem出现的位置(返回-1表示不存在elem)
unsigned int S_LinkList<T>::find(T elem)const{
    if(length==0) return -1;
    const node *p;
    int i = 1;
    for(p = head->next; p!=nullptr; p = p->next){
        if(p->data == elem){
            return i;
        }
        i++;
    }
    return -1;
}

template<typename T>//在第i个节点处插入数据elem(1 <= i <= length+1)
void S_LinkList<T>::insert(unsigned int i, T elem){
    //检查i是否合法(i<=i<=length+1)
    if(i<1 || i>length+1)
        throw std::out_of_range("传入的位序i不合法");
    node *p = new node;//创建一个新节点
    p->data = elem;
    //找到第i-1个节点
    node *i1 = getNode(i-1);
    //将节点p插入到第i-1个节点后
    p->next = i1->next;
    i1->next = p;
    if(i == length+1){//插入到单链表末尾，要将尾指针tail指向p
        tail = p;
    }
    length++;//单链表长度加1
}

template<typename T>//删除单链表第i个节点(1<=i<=length)，并返回该节点的数据
T S_LinkList<T>::remove(unsigned int i){
    if(i<1 || i>length)
        throw std::out_of_range("传入的位序i不合法！");
    node* p = getNode(i-1);//先找到第i-1个节点
    node* pi = p->next;//第i个节点
    T tmp = pi->data; // 保存第i个节点的数据
    //删除第i个节点
    p->next = pi->next; // 将第i+1个节点(即pi->next)的地址赋值给第i-1个节点的指针域
    if(i == length){//删除单链表末尾的节点
        tail = p;//尾指针指向前一个节点
    }
    delete pi;//释放第i个节点的内存
    length--;//单链表长度减1
    return tmp;
}

template<typename T>//删除单链表末尾的节点，并返回该节点的数据
T S_LinkList<T>::pop_back(){
    node* p = getNode(length-1);//先找到第length-1个节点，即末尾节点的前一个节点
    T tmp = tail->data; // 保存第i个节点的数据
    //删除末尾节点
    p->next = nullptr; // 将末尾节点的前一个节点的指针域置为空
    delete tail;//释放末尾节点的内存
    tail = p;//尾指针指向前一个节点
    length--;//单链表长度减1
    return tmp;
}



template<typename T>//头插法创建单链表(n为数组长度)
void S_LinkList<T>::push_arr_head(T arr[], unsigned int n){
    node *p;
    for(unsigned int i=0; i<n; i++){
        p = new node;//创建一个新节点
        p->data = arr[i];
        //将节点p插入到头节点后
        p->next = head->next;
        head->next = p;
        //如果单链表为空(即尾指针指向头节点)，则p成为尾节点
        if(head==tail)
            tail = p;
    }
    length = length+n;//单链表长度加上数组长度
}

template<typename T>//尾插法创建单链表(n为数组长度)
void S_LinkList<T>::push_arr_tail(T arr[], unsigned int n){
    node *p;
    for(int i=0; i<n; i++){
        p = new node;//创建一个新节点
        p->data = arr[i];
        //将节点p插入到单链表末尾
        p->next = nullptr;
        tail->next = p;
        tail = p;
    }
    length = length+n;//单链表长度加上数组长度
}




template<typename T>
T S_LinkList<T>::getTailData(){
    return tail->data;
}

template<typename T>//用头插法逆置单链表
void S_LinkList<T>::reserve(){
    
}