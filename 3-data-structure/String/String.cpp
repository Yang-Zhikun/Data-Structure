// 串
//模式匹配算法
//1.BF模式匹配算法
//2.KMP模式匹配算法

#include<stdio.h>
#include<string.h>
#include<windows.h>

int BF_match(const char *S, const char *T);
int KMP_match(const char *S, const char *T);
void getNext(const char *T, unsigned int next[]);



/**
 * BF模式匹配算法，返回字串T在主串S第一次出现的下标(-1表示匹配失败)
 * @param S 主串
 * @param T 字串(模式串)
 */
int BF_match(const char *S, const char *T){
    unsigned int S_len = strlen(S); // 获取主字符串S的长度  
    unsigned int T_len = strlen(T); // 获取子字符串T的长度  
    // 如果T为空或者T的长度大于S的长度，则无法找到匹配，返回-1  
    if(T_len == 0 || T_len > S_len){
        return -1;
    }
    unsigned int i = 0, j = 0; // 初始化两个指针，i指向S的当前字符，j指向T的当前字符  
    // 当i没有超出S的长度且j没有超出T的长度时，继续循环  
    while(i < S_len && j < T_len){
        if(S[i] == T[j]){ // 如果当前字符匹配  
            i++; // 移动S的指针  
            j++; // 移动T的指针  
        }
        else{ // 如果当前字符不匹配  
            i = i - j + 1; // i退回到不匹配字符之前的位置的下一个字符，并准备重新匹配  
            j = 0; // T的指针重置为起始位置  
        }
    }
    // 如果j等于T的长度，说明找到了匹配，返回匹配起始位置的索引  
    if(j == T_len){
        return i - T_len; // 返回匹配子串在主串中的起始索引  
    }
    // 如果没有找到匹配，返回-1  
    return -1;
}



/**
 * KMP模式匹配算法，返回字串T在主串S第一次出现的下标(-1表示匹配失败)
 * @param S 主串
 * @param T 字串(模式串)
 */
int KMP_match(const char *S, const char *T){
    unsigned int S_len = strlen(S); // 获取主串S的长度  
    unsigned int T_len = strlen(T); // 获取模式串T的长度  
    if(T_len == 0 || T_len > S_len){ // 如果模式串为空或长度大于主串，直接返回-1  
        return -1;
    }
    unsigned int *next = new unsigned int[T_len+1]; // 动态分配next数组，长度为T_len+1  
    getNext(T, next); // 调用getNext函数计算next数组  
    unsigned int i = 0, j = 0; // 初始化两个指针，i指向主串S，j指向模式串T  
    for(i = 0; i < S_len; i++){ // 遍历主串S  
        while(j > 0 && S[i] != T[j]){ // 当j不为0且当前字符不匹配时，利用next数组回退j  
            j = next[j];
        }
        if(S[i] == T[j]){ // 如果当前字符匹配，则继续向后匹配  
            j++;
        }
        if(j == T_len){ // 如果j等于T_len，说明找到了完整的匹配  
            delete[] next; // 释放next数组占用的内存  
            return i - j + 1; // 返回匹配开始的位置（注意调整索引）  
        }
    }
    delete[] next; // 如果没有找到匹配，释放next数组占用的内存  
    return -1; // 返回-1表示匹配失败  
}

/**
 * KMP模式匹配算法：求解next数组
 * @param T 字串(模式串)
 * @param next next数组的指针，长度为T_len+1
 * next数组用于存储模式串T中每个位置之前的最长相等前后缀的长度+1
 */
void getNext(const char *T, unsigned int next[]){
    unsigned int T_len = strlen(T); // 获取模式串T的长度  
    next[0] = 0; // next[0]总是0，因为前缀为空  
    if(T_len > 1) next[1] = 0; // 如果模式串长度大于1，next[1]也为0，因为只有一个字符没有前后缀  
    unsigned int i = 2, j = 0; // 初始化两个指针，i用于遍历模式串T，j用于记录最长相等前后缀的长度  
    for(i = 2; i <= T_len; i++){ // 注意这里i从2开始，因为next[0]和next[1]已经初始化  
        while(j > 0 && T[i-1]!=T[j]){ // 当j不为0且当前字符不匹配时，利用next数组回退j  
            j = next[j];
        }
        if(T[i-1] == T[j]){ // 如果当前字符匹配，则最长相等前后缀长度+1  
            j++;
        }
        next[i] = j; // 更新next[i]  
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