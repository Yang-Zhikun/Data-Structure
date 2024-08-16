//������(��ͷ���)

#include<iostream>
#include<stdexcept>
using namespace std;

template<typename T>
class LinkList{
private:
    struct node{//һ��������ڵ�
        T data;//�����򣬴������
        node *next;//ָ���򣬴����һ���ڵ�ĵ�ַ
    };

    node *head;//�������ͷָ��
    node *tail;//�������βָ��
    unsigned int length;//������ĵ�ǰ����

    node* getNode(const unsigned int i)const;//��ȡ�������i���ڵ��ָ��(i��1��ʼ��i=0ʱ����ͷָ��)

public:
    LinkList();//���캯��
    ~LinkList();//��������
    LinkList(const LinkList& obj);//�������캯��
    LinkList<T>& operator=(const LinkList &obj);//��ֵ�����

    void clear();//��յ�����
    bool isEmpty()const{ return length==0; } //�жϵ������Ƿ�Ϊ��
    unsigned int getLength()const{ return length; }//��ȡ������ĳ���
    void traverse()const;//����������
    T get(const unsigned int i)const;//��ȡ�������i���ڵ������(i��1��ʼ)
    void set(const unsigned int i, const T elem);//����i���ڵ����������Ϊelem(1<=i<=length)
    unsigned int find(const T elem)const;//�������в���elem, ���ص�һ��elem���ֵ�λ��(����-1��ʾ)
    void insert(const unsigned int i, const T elem);//�ڵ�i���ڵ㴦��������elem(1 <= i <= length+1)
    void push_back(const T elem){ insert(length+1, elem); }//�ڵ�����ĩβ��������elem
    T remove(const unsigned int i);//ɾ���������i���ڵ�(i��1��ʼ)�������ظýڵ������
    T pop_back() { return remove(length); }//ɾ��������ĩβ�Ľڵ㣬�����ظýڵ������

    void push_arr_head(T arr[], const unsigned int n);//ͷ�巨����������(nΪ���鳤��)
    void push_arr_tail(T arr[], const unsigned int n);//β�巨����������(nΪ���鳤��)

    T getTailData();


};





template<typename T>//���캯��
LinkList<T>::LinkList(){
    head = new node;//��ͷָ������ڴ�
    head->data = 0;
    head->next = nullptr;//�������ͷָ���ָ����Ϊ��
    tail = head;//βָ��ָ��ͷ�ڵ�
    length = 0;//������ĳ���Ϊ��
}

template<typename T>//��������
LinkList<T>::~LinkList(){
    clear();//��յ�����
    delete head;//�ͷ�ͷ�ڵ�
    //delete tail;�ͷ�β�ڵ��Ǵ�ģ���Ϊclear()��tailָ��head�������ظ��ͷ�ͬһ�ڴ�
}

template<typename T>//�������캯��
LinkList<T>::LinkList(const LinkList & obj){
    head = new node;//��ͷ��������ڴ�
    head->data = 0;
    head->next = nullptr;
    tail = head;//βָ��ָ��ͷ�ڵ�
    if(obj.length == 0){
        length = 0;
        return;
    }
    //��β�巨����obj������
    node* p = obj.head->next;
    for(; p != nullptr; p = p->next){
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
LinkList<T>& LinkList<T>::operator=(const LinkList &obj){
    if(*this == obj) return;//��ֹ�Ը�ֵ
    head = new node;//��ͷ��������ڴ�
    head->data = 0;
    head->next = nullptr;
    tail = head;//βָ��ָ��ͷ�ڵ�
    if(obj.length == 0){
        length = 0;
        return;
    }
    //��β�巨����obj������
    node* p = obj.head->next;
    for(; p != nullptr; p = p->next){
        node* newnode = new node;
        //��newnode���뵽������ĩβ
        newnode->data = p->data;
        newnode->next = nullptr;
        tail->next = newnode;
        tail = newnode;
    }
    length = obj.length;
    return *this;
}


template<typename T>//��ȡ�������i���ڵ��ָ��(1<=i<=length)
typename LinkList<T>::node* LinkList<T>::getNode(unsigned int i)const{
    //�������� 1 <= i <= length ʱ���ؿ�ָ��
    if(i<1 || i>length){
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
void LinkList<T>::clear(){
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
void LinkList<T>::traverse()const{
    node *p;
    for(p = head->next; p!=nullptr; p = p->next){
        cout<< p->data <<" ";
    }
    cout<<'\n';
}

template<typename T>//��ȡ�������i���ڵ������(i��1��ʼ)
T LinkList<T>::get(unsigned int i)const{
    node *p = getNode(i);
    if(p==nullptr)
        throw std::out_of_range("�����λ��i���Ϸ�");
    else
        return p->data;
}

template<typename T>//����i���ڵ����������Ϊelem(1<=i<=length)
void LinkList<T>::set(unsigned int i, T elem){
    if(i<1 || i > length)
        throw std::out_of_range("�����λ��i���Ϸ�");
    //�ҵ���i���ڵ�
    node *p = getNode(i);//ǰ���Ѿ�����i��p��������nullptr
    p->data = elem;
}

template<typename T>//�������в���elem, ���ص�һ��elem���ֵ�λ��(����-1��ʾ������elem)
unsigned int LinkList<T>::find(T elem)const{
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
void LinkList<T>::insert(unsigned int i, T elem){
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
T LinkList<T>::remove(unsigned int i){
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


template<typename T>//ͷ�巨����������(nΪ���鳤��)
void LinkList<T>::push_arr_head(T arr[], unsigned int n){
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
void LinkList<T>::push_arr_tail(T arr[], unsigned int n){
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
T LinkList<T>::getTailData(){
    return tail->data;
}






int main(){
    LinkList<int> L;
    /*int a[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    L.push_arr_tail(a, 10);
    L.traverse();
    L.push_back(6666);*/
    L.traverse();
    cout<<"length: "<<L.getLength()<<endl;
    cout<<"TailData: "<<L.getTailData()<<endl<<endl;

    LinkList<int> l2=L;
    l2.traverse();
    cout<<"length: "<<l2.getLength()<<endl;
    cout<<"tailData: "<<l2.getTailData()<<endl;
    

    system("pause");
}