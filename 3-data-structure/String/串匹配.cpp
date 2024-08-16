#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<chrono>
//计时器
class Timer {
private:
    std::chrono::high_resolution_clock::time_point  start_time;//起始时间
    std::chrono::high_resolution_clock::time_point  end_time;//终止时间

public:
    void start() { //开始计时(记录开始时间)
        start_time = std::chrono::high_resolution_clock::now();
    }
    void end() { //停止计时(记录结束时间)
        end_time = std::chrono::high_resolution_clock::now();
    }
    double duration() { // 经过的时间(ms)
        auto duration = end_time - start_time;
        return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    }
};


/**
BF模式匹配算法，返回主串S中第一次出现子串T的下标(-1匹配失败)
*@param S 主串
*@param T 子串
*/
int BF_match(const char *S, const char *T);

/**
KMP模式匹配算法中求解子串的next数组
*@param T 子串
*@param next[] next数组的指针，长度为(strlen(T)+1)
*/
void getNext(const char *T, unsigned short next[]);

/**
KMP模式匹配算法，返回主串S中第一次出现子串T的下标(-1匹配失败)
*@param S 主串
*@param T 子串
*/
int KMP_match(const char *S, const char *T);



/**
*BF匹配算法，返回主串S中第一次出现子串T的下标(-1匹配失败)
*@param S 主串
*@param T 子串(模式串)
*算法思路：
*从目标串S的第1个字符开始，和模式串T的第1个字符比较
    *若相等(S[i]==T[i])则分别指向两串的指针i,j后移一位(i++, j++)
    *若不相等(S[i]!=T[i])，则主串S指针i回溯到上次比较的起始位置的后一位(i-j+1)，
     子串T指针j回溯到第一个字符(j=0)，继续进行比较
        *i回溯到i-j+1的原因：两个串已经成功匹配了j个字符，所以i-j就是上次比较的起始位置，再+1就是后一位
**时间复杂度：
    *最好：O(T_len)
    *最坏：O(T_len * S_len)
*/
int BF_match(const char *S, const char *T) {
    unsigned short S_len = strlen(S);
    unsigned short T_len = strlen(T);
    if(S_len < T_len) return -1; //主串比子串短，匹配失败
    unsigned short i = 0, j = 0;
    while(i<S_len && j<T_len) {
        if(S[i] == T[j]) { // 对应字符相等，指针后移
            i++;
            j++;
        }
        else { //对应字符不相等，i回溯到i-j+1，j从0开始
            i = i - j + 1;
            j = 0;
        }
    }
    if(j != T_len) { // j不指向T的末尾(S遍历完但T没遍历完)，说明匹配失败
        return -1;
    }
    else {
        return i - T_len;//匹配成功，T在S中第一次出现的下标为i-T_len
    }
}




void getNext(const char *T, unsigned short next[]) {
    // 初始化next数组的前两个元素为0，因为模式串的前两个字符不可能有最长可匹配前缀后缀
    // 或者说，长度为0和1的子串的next值总是0
    next[0] = next[1] = 0;

    // i用于遍历模式串T(表示已匹配前缀的下一位置)，从第三个字符开始（索引为2）
    unsigned short i = 2;
    // j用于在模式串T中回溯(表示最长可匹配前缀子串的下一位置，也是最长可匹配前缀子串的长度)，寻找最长的相等前后缀
    // 初始时，j为0，表示还没有开始匹配任何前缀或后缀
    unsigned short j = 0;

    // 遍历模式串T，从第三个字符开始
    for (i = 2; i <= strlen(T); i++) {
        // 当j大于0且当前字符T[i-1]与T[j]不匹配时
        // 使用next数组回溯j，直到找到一个匹配的位置或j变为0
        while (j > 0 && T[i - 1] != T[j]) {
            j = next[j];
        }

        // 如果当前字符T[i-1]与T[j]匹配
        // 则更新j为j+1，表示我们找到了一个更长的相等前后缀（或继续匹配）
        if (T[i - 1] == T[j]) {
            j++;
        }

        // 将j的值（即当前最长相等前后缀的长度）存入next[i]
        next[i] = j;

        // 注意：while和if操作不能调换位置
        // 否则那么j的递增(if里)将在回溯(while里)之前发生，这会导致逻辑错误。
        // 具体来说，如果T[i-1]与T[j]不匹配，但我们在检查匹配之前就递增了j，
        // 那么我们就错过了使用next数组进行回溯的机会，从而无法正确地构建next数组
    }
}

int KMP_match(const char *S, const char *T) {
    unsigned short S_len = strlen(S);
    unsigned short T_len = strlen(T);
    // 动态分配next数组空间
    unsigned short *next = new unsigned short[T_len + 1];
    // 计算模式串T的next数组
    getNext(T, next);
    unsigned short i = 0, j = 0;
    // 遍历文本串S
    for(i = 0; i < S_len; i++) {
        // 当j大于0且当前字符不匹配时，利用next数组回溯
        while(j > 0 && S[i] != T[j]) {
            j = next[j];
        }
        // 如果当前字符匹配，则同时移动i和j
        if(S[i] == T[j]) {
            j++;
        }
        // 如果j等于T_len，说明找到了匹配，返回匹配开始的位置
        if(j == T_len) {
            delete [] next;
            // 注意：返回的是匹配在S中的起始索引，因此需要i-j+1
            return i-j+1;
        }
    }
    delete [] next;
    // 如果没有找到匹配，返回-1
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