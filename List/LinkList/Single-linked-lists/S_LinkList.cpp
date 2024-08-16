#include"S_LinkList.h"
#include<iostream>
#include<stdexcept>
//#include<stdio.h>


template<typename T>//���캯��
S_LinkList<T>::S_LinkList(){
    head = new node;//��ͷָ������ڴ�
    head->data = 0;
    head->next = nullptr;//�������ͷָ���ָ����Ϊ��
    tail = head;//βָ��ָ��ͷ�ڵ�
    length = 0;//������ĳ���Ϊ��
}

template<typename T>//��������
S_LinkList<T>::~S_LinkList(){
    clear();//��յ�����
    delete head;//�ͷ�ͷ�ڵ�
    //delete tail;�ͷ�β�ڵ��Ǵ�ģ���Ϊclear()��tailָ��head�������ظ��ͷ�ͬһ�ڴ�
}

template<typename T>//�������캯��
S_LinkList<T>::S_LinkList(const S_LinkList & obj){
    head = new node;//��ͷ��������ڴ�
    head->data = 0;
    head->next = nullptr;
    tail = head;//βָ��ָ��ͷ�ڵ�
    //��β�巨����obj������
    
    for(node* p = obj.head->next; p != nullptr; p = p->next){
        node* newnode = new node;
        //��newnode���뵽������ĩβ
        newnode->data = p->data;
        newnode->next = nullptr;
        tail->next = newnode;
        tail = newnode;
    }
    length = obj.length;
}

template<typename T>//��ֵ�����
S_LinkList<T>& S_LinkList<T>::operator=(const S_LinkList & obj){
    if(*this != obj){//��ֹ�Ը�ֵ
        head = new node;//��ͷ��������ڴ�
        head->data = 0;
        head->next = nullptr;
        tail = head;//βָ��ָ��ͷ�ڵ�
        //��β�巨����obj������
        
        for(node* p = obj.head->next; p != nullptr; p = p->next){
            node* newnode = new node;
            //��newnode���뵽������ĩβ
            newnode->data = p->data;
            newnode->next = nullptr;
            tail->next = newnode;
            tail = newnode;
        }
        length = obj.length;
    }
    return *this;
}


template<typename T>//��ȡ�������i���ڵ��ָ��(i��1��ʼ��i=0ʱ����ͷָ��)
typename S_LinkList<T>::node* S_LinkList<T>::getNode(unsigned int i)const{
    if(i==0)
        return head;
    //�������� 0 <= i <= length ʱ���ؿ�ָ��
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




template<typename T>//��յ�����
void S_LinkList<T>::clear(){
    node *p;//p�ǹ���ָ�룬��ֹ�ƶ�ͷָ�룬��ʧ����
    node *tmp;//tmp����ʱָ�룬ָ��Ҫ�ͷŵĽڵ�
    p = head->next;//pָ����Ԫ�ڵ�
    while(p!=nullptr){
        tmp = p;//tmpָ��p���ڵĽڵ�
        p = p->next;//p�����һ���ڵ�
        delete tmp;
    }
    head->next = nullptr;//ͷָ���ָ������Ϊ��
    tail = head;//�������βָ��ָ��ͷ�ڵ�
    length = 0;//������ĳ���Ϊ0
}

template<typename T>//����������
void S_LinkList<T>::traverse()const{
    node *p;
    for(p = head->next; p!=nullptr; p = p->next){
        cout<< p->data <<" ";
    }
    cout<<'\n';
}

template<typename T>//��ȡ�������i���ڵ������(i��1��ʼ)
T S_LinkList<T>::get(unsigned int i)const{
    node *p = getNode(i);
    if(p==nullptr)
        throw std::out_of_range("�����λ��i���Ϸ�");
    else
        return p->data;
}

template<typename T>//����i���ڵ����������Ϊelem(1<=i<=length)
void S_LinkList<T>::set(unsigned int i, T elem){
    if(i<1 || i > length)
        throw std::out_of_range("�����λ��i���Ϸ�");
    //�ҵ���i���ڵ�
    node *p = getNode(i);//ǰ���Ѿ�����i��p��������nullptr
    p->data = elem;
}

template<typename T>//�������в���elem, ���ص�һ��elem���ֵ�λ��(����-1��ʾ������elem)
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

template<typename T>//�ڵ�i���ڵ㴦��������elem(1 <= i <= length+1)
void S_LinkList<T>::insert(unsigned int i, T elem){
    //���i�Ƿ�Ϸ�(i<=i<=length+1)
    if(i<1 || i>length+1)
        throw std::out_of_range("�����λ��i���Ϸ�");
    node *p = new node;//����һ���½ڵ�
    p->data = elem;
    //�ҵ���i-1���ڵ�
    node *i1 = getNode(i-1);
    //���ڵ�p���뵽��i-1���ڵ��
    p->next = i1->next;
    i1->next = p;
    if(i == length+1){//���뵽������ĩβ��Ҫ��βָ��tailָ��p
        tail = p;
    }
    length++;//�������ȼ�1
}

template<typename T>//ɾ���������i���ڵ�(1<=i<=length)�������ظýڵ������
T S_LinkList<T>::remove(unsigned int i){
    if(i<1 || i>length)
        throw std::out_of_range("�����λ��i���Ϸ���");
    node* p = getNode(i-1);//���ҵ���i-1���ڵ�
    node* pi = p->next;//��i���ڵ�
    T tmp = pi->data; // �����i���ڵ������
    //ɾ����i���ڵ�
    p->next = pi->next; // ����i+1���ڵ�(��pi->next)�ĵ�ַ��ֵ����i-1���ڵ��ָ����
    if(i == length){//ɾ��������ĩβ�Ľڵ�
        tail = p;//βָ��ָ��ǰһ���ڵ�
    }
    delete pi;//�ͷŵ�i���ڵ���ڴ�
    length--;//�������ȼ�1
    return tmp;
}

template<typename T>//ɾ��������ĩβ�Ľڵ㣬�����ظýڵ������
T S_LinkList<T>::pop_back(){
    node* p = getNode(length-1);//���ҵ���length-1���ڵ㣬��ĩβ�ڵ��ǰһ���ڵ�
    T tmp = tail->data; // �����i���ڵ������
    //ɾ��ĩβ�ڵ�
    p->next = nullptr; // ��ĩβ�ڵ��ǰһ���ڵ��ָ������Ϊ��
    delete tail;//�ͷ�ĩβ�ڵ���ڴ�
    tail = p;//βָ��ָ��ǰһ���ڵ�
    length--;//�������ȼ�1
    return tmp;
}



template<typename T>//ͷ�巨����������(nΪ���鳤��)
void S_LinkList<T>::push_arr_head(T arr[], unsigned int n){
    node *p;
    for(unsigned int i=0; i<n; i++){
        p = new node;//����һ���½ڵ�
        p->data = arr[i];
        //���ڵ�p���뵽ͷ�ڵ��
        p->next = head->next;
        head->next = p;
        //���������Ϊ��(��βָ��ָ��ͷ�ڵ�)����p��Ϊβ�ڵ�
        if(head==tail)
            tail = p;
    }
    length = length+n;//�������ȼ������鳤��
}

template<typename T>//β�巨����������(nΪ���鳤��)
void S_LinkList<T>::push_arr_tail(T arr[], unsigned int n){
    node *p;
    for(int i=0; i<n; i++){
        p = new node;//����һ���½ڵ�
        p->data = arr[i];
        //���ڵ�p���뵽������ĩβ
        p->next = nullptr;
        tail->next = p;
        tail = p;
    }
    length = length+n;//�������ȼ������鳤��
}




template<typename T>
T S_LinkList<T>::getTailData(){
    return tail->data;
}

template<typename T>//��ͷ�巨���õ�����
void S_LinkList<T>::reserve(){
    
}