//˳��� Dynamic sequential lists
//��̬�ڴ���䣬���Զ�����

#include<iostream>
#include <stdexcept> // ����std::out_of_range��std::invalid_argument
using namespace std; 

template<typename T>
class D_seqList{
private:
    T *data;//������ݵ��׵�ַ
    unsigned int length;//��ǰ˳��������ݸ���
    unsigned int maxLen;//����

    void resize();//˳�����ʱ����

public:
    D_seqList();//���캯��
    D_seqList(const D_seqList &sl);//�������캯��
    D_seqList<T>& operator=(const D_seqList &sl);//��ֵ�����
    ~D_seqList(){ delete[] data; }//��������

    unsigned int getLength()const{ return length; }//��ȡ��length
    void clear(){ length=0; };//���˳���
    bool isEmpty()const{ return length==0; }//�ж�˳����Ƿ�Ϊ��
    void traverse()const;//����˳���
    T operator[] (unsigned int i)const;//�����[]����ȡ˳���λ��i������(0<=i<length)
    T& operator[] (unsigned int i);//�����[]������˳���λ��i�����ݵ�����(0<=i<length)
    void set(unsigned int i, T elem){ this->operator[](i) = elem; }//��˳���λ��Ϊi��Ԫ�ص�ֵ��Ϊelem(0<=i<length)
    T get(unsigned int i)const{ return operator[](i); }//��ȡ˳���λ��i������(0<=i<length)
    void insert(unsigned int i, T elem);//��˳���λ��i������һ������(0<=i<=length)
    void push_back(T elem){ insert(length, elem); }//��˳���ĩβ����һ������
    void remove(unsigned int i);//ɾ��˳���λ��i������(0<=i<length)
    void pop_back(){ remove(length-1); }//ɾ��˳���ĩβ��һ������
    void reserve();//����˳���
};





template<typename T>//���캯��
D_seqList<T>::D_seqList(){
    data = new T[2];
    if(!data){//�ڴ����ʧ��
        throw std::bad_alloc();
        return;
    }
    length = 0;
    maxLen = 2;//��ʼʱ����Ϊ2
}


template<typename T>//�������캯��
D_seqList<T>::D_seqList(const D_seqList<T> &sl): maxLen(sl.maxLen), length(sl.length){
    // ��̬�����ڴ�  
    data = new T[maxLen];
    // ����ڴ�����Ƿ�ʧ��  
    if(!data){
        // �׳��쳣��ʹ�ñ�׼�쳣����  
        throw std::bad_alloc();
    }
    // ��sl�����ݸ��Ƶ��¶���  
    for(int i = 0; i < length; i++){
        data[i] = sl.data[i];
    }
}


template<typename T>//��ֵ�����
D_seqList<T>& D_seqList<T>::operator=(const D_seqList<T> &sl){
/*
�ڵĸ�ֵ�����ʵ���У���ͼͨ�����ÿ������캯������ֵ�������ǲ���ȷ�ġ������� *this = D_seqList(sl);
��ᵼ�����޵ݹ飬��Ϊ��ֵ����������ڸ�ֵ�����б����ã����������е����˿������캯����
    �ù��캯�����ջ᳢�Ե��ø�ֵ���������������κ���Դ��Ҫ������
Ӧ��ֱ���ڸ�ֵ������ڲ���������������Ǵ�����ʱ����    */

    if(this != &sl){ // ��ֹ�Ը�ֵ  
        T* newData = new T[sl.maxLen];
        if(!newData){
            throw std::bad_alloc();
        }
        // ��������  
        for(int i = 0; i < sl.length; i++){
            newData[i] = sl.data[i];
        }
        // �ͷž��ڴ�  
        delete[] data;
        // ���³�Ա����  
        data = newData;
        length = sl.length;
        maxLen = sl.maxLen;
    }
    return *this;
}



template<typename T>//˳�����ʱ����
void D_seqList<T>::resize(){
    T* newData = new T[maxLen * 2];
    if(!newData){
        throw std::bad_alloc();
    }
    // ��������  
    for(int i = 0; i < length; i++){
        newData[i] = data[i];
    }
    // �ͷž��ڴ�  
    delete[] data;
    // ���³�Ա����  
    data = newData;
    maxLen *= 2;
}




template<typename T>//����˳���
void D_seqList<T>::traverse()const{
    for(int i=0; i<length; i++){
        cout<<data[i]<<" ";
    }
    cout<<"\n";
}



template<typename T>//�����[]����ȡ˳���λ��i������(0<=i<length)
T D_seqList<T>::operator[] (unsigned int i)const{
    if(i>=length || i<0){
        throw std::out_of_range("�����λ��i����ȷ");
    }
    else{
        return data[i];
    }
}

template<typename T>//�����[]������˳���λ��i�����ݵ�����(0<=i<length)
T& D_seqList<T>::operator[](unsigned int i){
    if(i>=length || i<0){
        throw std::out_of_range("�����λ��i����ȷ");
    }
    else{
        return data[i];
    }
}

template<typename T>//��˳���λ��i������һ������(0<=i<=length)
void D_seqList<T>::insert(unsigned int i, T elem){
    if(i>length ||i<0){//�����λ�ò��Ϸ�
        throw std::out_of_range("�����λ��i����ȷ");
    }
    if(i==length){//i==length��ʾ���뵽˳����ĩβ
        try{
            resize();//��������
        }
        catch(std::bad_alloc()){
            throw "��������ʧ�ܣ�";
        }
    }
    //��λ��i������ݶ�����һ��λ��
    for(int j=length; j>i; j--){
        data[j] = data[j-1];
    }
    data[i] = elem;//��������
    length++;//˳����ȼ�1
}


template<typename T>//ɾ��˳���λ��i������(0<=i<length)
void D_seqList<T>::remove(unsigned int i){
    if(i>=length || i<0){
        throw std::out_of_range("�����λ��i����ȷ");
    }
    //��Ҫɾ�������ݺ��������ȫ��ǰ��һ��λ�ã�����Ҫɾ��������
    for(int j=i; j<length-1; j++){
        data[j] = data[j+1];
    }
    length--;//˳����ȼ�1
}

template<typename T>//����˳���
void D_seqList<T>::reserve(){
    if(length == 0)
        return;
    //���������м�������ǽ���
    T tmp;
    int i=0, j=length-1;//ͷ��β��������ָ��
    while(i<j){
        //����i,j��ָ����
        tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
        //��������ָ�����м��ƶ�
        i++;
        j--;
    }
}








int main(){
    D_seqList<int> L;
    for(int i=1; i<=3; i++){
        L.push_back(i);
    }
    L.traverse();
    L.reserve();
    L.traverse();
    system("pause");
}