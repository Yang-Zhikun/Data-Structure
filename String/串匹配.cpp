#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<chrono>
//��ʱ��
class Timer {
private:
    std::chrono::high_resolution_clock::time_point  start_time;//��ʼʱ��
    std::chrono::high_resolution_clock::time_point  end_time;//��ֹʱ��

public:
    void start() { //��ʼ��ʱ(��¼��ʼʱ��)
        start_time = std::chrono::high_resolution_clock::now();
    }
    void end() { //ֹͣ��ʱ(��¼����ʱ��)
        end_time = std::chrono::high_resolution_clock::now();
    }
    double duration() { // ������ʱ��(ms)
        auto duration = end_time - start_time;
        return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    }
};


/**
BFģʽƥ���㷨����������S�е�һ�γ����Ӵ�T���±�(-1ƥ��ʧ��)
*@param S ����
*@param T �Ӵ�
*/
int BF_match(const char *S, const char *T);

/**
KMPģʽƥ���㷨������Ӵ���next����
*@param T �Ӵ�
*@param next[] next�����ָ�룬����Ϊ(strlen(T)+1)
*/
void getNext(const char *T, unsigned short next[]);

/**
KMPģʽƥ���㷨����������S�е�һ�γ����Ӵ�T���±�(-1ƥ��ʧ��)
*@param S ����
*@param T �Ӵ�
*/
int KMP_match(const char *S, const char *T);



/**
*BFƥ���㷨����������S�е�һ�γ����Ӵ�T���±�(-1ƥ��ʧ��)
*@param S ����
*@param T �Ӵ�(ģʽ��)
*�㷨˼·��
*��Ŀ�괮S�ĵ�1���ַ���ʼ����ģʽ��T�ĵ�1���ַ��Ƚ�
    *�����(S[i]==T[i])��ֱ�ָ��������ָ��i,j����һλ(i++, j++)
    *�������(S[i]!=T[i])��������Sָ��i���ݵ��ϴαȽϵ���ʼλ�õĺ�һλ(i-j+1)��
     �Ӵ�Tָ��j���ݵ���һ���ַ�(j=0)���������бȽ�
        *i���ݵ�i-j+1��ԭ���������Ѿ��ɹ�ƥ����j���ַ�������i-j�����ϴαȽϵ���ʼλ�ã���+1���Ǻ�һλ
**ʱ�临�Ӷȣ�
    *��ã�O(T_len)
    *���O(T_len * S_len)
*/
int BF_match(const char *S, const char *T) {
    unsigned short S_len = strlen(S);
    unsigned short T_len = strlen(T);
    if(S_len < T_len) return -1; //�������Ӵ��̣�ƥ��ʧ��
    unsigned short i = 0, j = 0;
    while(i<S_len && j<T_len) {
        if(S[i] == T[j]) { // ��Ӧ�ַ���ȣ�ָ�����
            i++;
            j++;
        }
        else { //��Ӧ�ַ�����ȣ�i���ݵ�i-j+1��j��0��ʼ
            i = i - j + 1;
            j = 0;
        }
    }
    if(j != T_len) { // j��ָ��T��ĩβ(S�����굫Tû������)��˵��ƥ��ʧ��
        return -1;
    }
    else {
        return i - T_len;//ƥ��ɹ���T��S�е�һ�γ��ֵ��±�Ϊi-T_len
    }
}




void getNext(const char *T, unsigned short next[]) {
    // ��ʼ��next�����ǰ����Ԫ��Ϊ0����Ϊģʽ����ǰ�����ַ������������ƥ��ǰ׺��׺
    // ����˵������Ϊ0��1���Ӵ���nextֵ����0
    next[0] = next[1] = 0;

    // i���ڱ���ģʽ��T(��ʾ��ƥ��ǰ׺����һλ��)���ӵ������ַ���ʼ������Ϊ2��
    unsigned short i = 2;
    // j������ģʽ��T�л���(��ʾ���ƥ��ǰ׺�Ӵ�����һλ�ã�Ҳ�����ƥ��ǰ׺�Ӵ��ĳ���)��Ѱ��������ǰ��׺
    // ��ʼʱ��jΪ0����ʾ��û�п�ʼƥ���κ�ǰ׺���׺
    unsigned short j = 0;

    // ����ģʽ��T���ӵ������ַ���ʼ
    for (i = 2; i <= strlen(T); i++) {
        // ��j����0�ҵ�ǰ�ַ�T[i-1]��T[j]��ƥ��ʱ
        // ʹ��next�������j��ֱ���ҵ�һ��ƥ���λ�û�j��Ϊ0
        while (j > 0 && T[i - 1] != T[j]) {
            j = next[j];
        }

        // �����ǰ�ַ�T[i-1]��T[j]ƥ��
        // �����jΪj+1����ʾ�����ҵ���һ�����������ǰ��׺�������ƥ�䣩
        if (T[i - 1] == T[j]) {
            j++;
        }

        // ��j��ֵ������ǰ����ǰ��׺�ĳ��ȣ�����next[i]
        next[i] = j;

        // ע�⣺while��if�������ܵ���λ��
        // ������ôj�ĵ���(if��)���ڻ���(while��)֮ǰ��������ᵼ���߼�����
        // ������˵�����T[i-1]��T[j]��ƥ�䣬�������ڼ��ƥ��֮ǰ�͵�����j��
        // ��ô���Ǿʹ����ʹ��next������л��ݵĻ��ᣬ�Ӷ��޷���ȷ�ع���next����
    }
}

int KMP_match(const char *S, const char *T) {
    unsigned short S_len = strlen(S);
    unsigned short T_len = strlen(T);
    // ��̬����next����ռ�
    unsigned short *next = new unsigned short[T_len + 1];
    // ����ģʽ��T��next����
    getNext(T, next);
    unsigned short i = 0, j = 0;
    // �����ı���S
    for(i = 0; i < S_len; i++) {
        // ��j����0�ҵ�ǰ�ַ���ƥ��ʱ������next�������
        while(j > 0 && S[i] != T[j]) {
            j = next[j];
        }
        // �����ǰ�ַ�ƥ�䣬��ͬʱ�ƶ�i��j
        if(S[i] == T[j]) {
            j++;
        }
        // ���j����T_len��˵���ҵ���ƥ�䣬����ƥ�俪ʼ��λ��
        if(j == T_len) {
            delete [] next;
            // ע�⣺���ص���ƥ����S�е���ʼ�����������Ҫi-j+1
            return i-j+1;
        }
    }
    delete [] next;
    // ���û���ҵ�ƥ�䣬����-1
    return -1;
}




int main() {
    //srand(114514);
    long s_len = 10000;
    {
        char *S = new char[s_len+3];
        char T[1001];
        /*scanf("%s %s", S, T);
        printf("\n%d\n", KMP_match(S, T));*/
        for(int i=0; i<s_len; i++) {
            S[i] = '0';
        }
        //printf("%s", S);
        S[s_len] = '1';
        S[s_len+1] = '\0';
        scanf("%s", T);
        Timer timer;
        timer.start();
        printf("%d", BF_match(S, T));
        timer.end();
        printf("   BF: %lf\n", timer.duration());

        timer.start();
        printf("%d", KMP_match(S, T));
        timer.end();
        printf("   KMP: %lf\n", timer.duration());

        delete[]S;
    }

}