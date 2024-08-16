// ��
//ģʽƥ���㷨
//1.BFģʽƥ���㷨
//2.KMPģʽƥ���㷨

#include<stdio.h>
#include<string.h>
#include<windows.h>

int BF_match(const char *S, const char *T);
int KMP_match(const char *S, const char *T);
void getNext(const char *T, unsigned int next[]);



/**
 * BFģʽƥ���㷨�������ִ�T������S��һ�γ��ֵ��±�(-1��ʾƥ��ʧ��)
 * @param S ����
 * @param T �ִ�(ģʽ��)
 */
int BF_match(const char *S, const char *T){
    unsigned int S_len = strlen(S); // ��ȡ���ַ���S�ĳ���  
    unsigned int T_len = strlen(T); // ��ȡ���ַ���T�ĳ���  
    // ���TΪ�ջ���T�ĳ��ȴ���S�ĳ��ȣ����޷��ҵ�ƥ�䣬����-1  
    if(T_len == 0 || T_len > S_len){
        return -1;
    }
    unsigned int i = 0, j = 0; // ��ʼ������ָ�룬iָ��S�ĵ�ǰ�ַ���jָ��T�ĵ�ǰ�ַ�  
    // ��iû�г���S�ĳ�����jû�г���T�ĳ���ʱ������ѭ��  
    while(i < S_len && j < T_len){
        if(S[i] == T[j]){ // �����ǰ�ַ�ƥ��  
            i++; // �ƶ�S��ָ��  
            j++; // �ƶ�T��ָ��  
        }
        else{ // �����ǰ�ַ���ƥ��  
            i = i - j + 1; // i�˻ص���ƥ���ַ�֮ǰ��λ�õ���һ���ַ�����׼������ƥ��  
            j = 0; // T��ָ������Ϊ��ʼλ��  
        }
    }
    // ���j����T�ĳ��ȣ�˵���ҵ���ƥ�䣬����ƥ����ʼλ�õ�����  
    if(j == T_len){
        return i - T_len; // ����ƥ���Ӵ��������е���ʼ����  
    }
    // ���û���ҵ�ƥ�䣬����-1  
    return -1;
}



/**
 * KMPģʽƥ���㷨�������ִ�T������S��һ�γ��ֵ��±�(-1��ʾƥ��ʧ��)
 * @param S ����
 * @param T �ִ�(ģʽ��)
 */
int KMP_match(const char *S, const char *T){
    unsigned int S_len = strlen(S); // ��ȡ����S�ĳ���  
    unsigned int T_len = strlen(T); // ��ȡģʽ��T�ĳ���  
    if(T_len == 0 || T_len > S_len){ // ���ģʽ��Ϊ�ջ򳤶ȴ���������ֱ�ӷ���-1  
        return -1;
    }
    unsigned int *next = new unsigned int[T_len+1]; // ��̬����next���飬����ΪT_len+1  
    getNext(T, next); // ����getNext��������next����  
    unsigned int i = 0, j = 0; // ��ʼ������ָ�룬iָ������S��jָ��ģʽ��T  
    for(i = 0; i < S_len; i++){ // ��������S  
        while(j > 0 && S[i] != T[j]){ // ��j��Ϊ0�ҵ�ǰ�ַ���ƥ��ʱ������next�������j  
            j = next[j];
        }
        if(S[i] == T[j]){ // �����ǰ�ַ�ƥ�䣬��������ƥ��  
            j++;
        }
        if(j == T_len){ // ���j����T_len��˵���ҵ���������ƥ��  
            delete[] next; // �ͷ�next����ռ�õ��ڴ�  
            return i - j + 1; // ����ƥ�俪ʼ��λ�ã�ע�����������  
        }
    }
    delete[] next; // ���û���ҵ�ƥ�䣬�ͷ�next����ռ�õ��ڴ�  
    return -1; // ����-1��ʾƥ��ʧ��  
}

/**
 * KMPģʽƥ���㷨�����next����
 * @param T �ִ�(ģʽ��)
 * @param next next�����ָ�룬����ΪT_len+1
 * next�������ڴ洢ģʽ��T��ÿ��λ��֮ǰ������ǰ��׺�ĳ���+1
 */
void getNext(const char *T, unsigned int next[]){
    unsigned int T_len = strlen(T); // ��ȡģʽ��T�ĳ���  
    next[0] = 0; // next[0]����0����Ϊǰ׺Ϊ��  
    if(T_len > 1) next[1] = 0; // ���ģʽ�����ȴ���1��next[1]ҲΪ0����Ϊֻ��һ���ַ�û��ǰ��׺  
    unsigned int i = 2, j = 0; // ��ʼ������ָ�룬i���ڱ���ģʽ��T��j���ڼ�¼����ǰ��׺�ĳ���  
    for(i = 2; i <= T_len; i++){ // ע������i��2��ʼ����Ϊnext[0]��next[1]�Ѿ���ʼ��  
        while(j > 0 && T[i-1]!=T[j]){ // ��j��Ϊ0�ҵ�ǰ�ַ���ƥ��ʱ������next�������j  
            j = next[j];
        }
        if(T[i-1] == T[j]){ // �����ǰ�ַ�ƥ�䣬������ǰ��׺����+1  
            j++;
        }
        next[i] = j; // ����next[i]  
    }
}





int main(){
    char S[101], T[101];
    while(1){
        scanf("%s %s", S, T);
        printf("%d\n\n", KMP_match(S, T));
    }
    system("pause");
}