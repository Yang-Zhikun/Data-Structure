/*中缀表达式求值
*步骤：从左到右扫描中缀表达式infix，对于每个infix[i]：
    *情况1：
        *如果infix[i]数数字字符，就拼成数字压入运算数栈opnd
    *情况2
        *(1)如果infix[i]优先级高于运算符栈optr的栈顶运算符，则infix[i]入栈
        *(2)如果infix[i]优先级低于运算符栈optr的栈顶运算符，则
            弹出optr栈顶运算符，并从运算数栈opnd弹出两个运算数，
            进行运算后，结果压入运算数栈opnd，再重复比较，直到遇到情况1，并执行情况1
*
*             运算符的优先级表(数值越大优先级越高)
*运算符         =    (    *,/    +,-    )
*栈内优先级     0    1     5     3      6
*栈外优先级     0    6     4     2      1

*相同运算符在栈内外的优先级不同的原因：要从左到右依次计算，先计算栈内的才计算栈外的
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include"..\\LinkStack\\LinkStack.h"


/***************************************函数声明************************************************************************/
double compute_infix(const char *infix); // 计算中缀表达式

double spellNum(const char *str, short &i);//拼数，将数字字符拼成数字并返回。i为当前扫描到的infix的字符下标，拼完数后i相应后移
short priorInSatck(char in); // 返回运算符in在栈内的优先级(见优先级表)
short priorOutSatck(char out); // 返回运算符out在栈外的优先级(见优先级表)
double operate(double a, double b, char operation); // 完成一次运算，将a与b进行operation运算

void infix_to_postfix(const char *infix, char *postfix); // 将中缀表达式infix转换为后缀表达式，存放到postfix
double compute_postfix(const char *postfix); // 计算后缀表达式



/************************************函数定义***************************************************************************/

// 计算中缀表达式
double compute_infix(const char *infix){
    LinkStack<char> optr; // 运算符栈
    LinkStack<double> opnd; // 运算数栈
    optr.clear();
    opnd.clear();
    optr.push('='); // 将'='压入运算符栈，作为运算结束的标志
    //从左到右扫描中缀表达式infix
    short i = 0; 
    while(infix[i]!='\0'){
        if(infix[i]>='0' && infix[i]<='9'){
            //infix[i]是数字字符就拼成数字压入opnd
            double num = spellNum(infix, i);
            opnd.push(num);
            //spellNum()里面已经i++了
        }
        else{
            //如果infix[i]是运算符，先比较infix[i]与optr栈顶运算符的优先级
            char optr_top = optr.get_top();
            short p_in = priorInSatck(optr_top);
            short p_out = priorOutSatck(infix[i]);
            if(p_out > p_in){
                //如果infix[i]优先级高于运算符栈optr的栈顶运算符，则infix[i]入栈，继续向后扫描
                optr.push(infix[i]);
                i++;
            }
            else if(p_out < p_in){
                /*如果infix[i]优先级低于运算符栈optr的栈顶运算符，则
                    弹出optr栈顶运算符，并从运算数栈opnd弹出两个运算数，
                    进行运算后，结果压入运算数栈opnd，再重复比较直到infix[i]优先级高于optr的栈顶运算符*/
                char operation = optr.pop();
                double b = opnd.pop();
                double a = opnd.pop();
                double ret = operate(a, b, operation);
                opnd.push(ret);
            }
            else{ // p_out == p_in ,只有两种情况，是等号或者是左右括号
                if(infix[i] == '='){
                    optr.pop(); // 弹出等号
                    break;
                }
                else{
                    //infix[i]是右括号，optr栈顶运算符是左括号
                    optr.pop(); // 弹出左括号
                    i++; //继续处理下一个字符
                }
            }
        }
    }
    double result = opnd.pop();
    if(opnd.isEmpty()==false){
        //运算数栈还有东西，证明表达式有误
        throw "输入的中缀表达式有误(compute_infix)";
    }
    else{
        return result;
    }
}



//拼数，将数字字符拼成数字并返回。i为当前扫描到的infix的字符下标，拼完数后i相应后移
double spellNum(const char *str, short &i){
    double num1=0, num2=0;//分别储存整数部分和小数部分
    //处理整数部分
    while(str[i]>='0' && str[i]<='9'){
        num1 = num1*10 + (str[i]-'0'); // num1乘10相当于向左移动一个数位，然后再加上个位(infix[i]-'0')
        i++;
    }
    if(str[i] == '.'){
        i++; // 如果遇到小数点，就跳过，处理小数部分
    }
    //处理小数部分
    short exp=-1;
    while(str[i]>='0' && str[i]<='9'){
        num2 = num2 + (str[i]-'0')*pow(10, exp);
        i++;
        exp--;
    }
    //返回结果
    return num1+num2;
}


// 返回运算符in在栈内的优先级(见优先级表)
short priorInSatck(char in){
    switch(in){
    case '=': return 0; break;
    case '(': return 1; break;
    case '*':
    case '/': return 5; break;
    case '+':
    case '-': return 3; break;
    case ')': return 6; break;
    }
}

// 返回运算符out在栈外的优先级(见优先级表)
short priorOutSatck(char out){
    switch(out){
    case '=': return 0; break;
    case '(': return 6; break;
    case '*':
    case '/': return 4; break;
    case '+':
    case '-': return 2; break;
    case ')': return 1; break;
    default: throw "输入的中缀表达式有误(priorOutSatck)";
    }
}

// 完成一次运算，将a与b进行operation运算
double operate(double a, double b, char operation){
    switch(operation){
        case '+': return a+b; break;
        case '-': return a-b; break;
        case '*': return a*b; break;
        case '/':
            if(fabs(b)<=1e-18)
                throw "存在除数为0";
            else{
                return a/b; break;
            }
    }
}


// 将中缀表达式infix转换为后缀表达式，存放到postfix
void infix_to_postfix(const char * infix, char * postfix){
/*将中缀表达式转换为后缀表达式
*准备一个运算符栈optr，从左到右扫描中缀表达式，对于每一个infix[i]
    *情况1：如果是数字或小数点就直接写入后缀表达式postfix
    *情况2：如果是运算符，且优先级高于optr栈顶运算符，则infix[i]入栈
    *情况3：如果是运算符，且优先级低于optr栈顶运算符，则弹出optr栈顶运算符，
           写入到postfix，再重复上述过程，直到infix[i]优先级高于optr栈顶运算符
    *情况4：如果是左括号，则infix[i]入栈
    *情况5：如果是右括号，则弹出optr栈顶运算符，写入postfix，直到遇到左括号
*/
    LinkStack<char> optr; // 运算符栈
    optr.push('=');  // optr先压入一个等号，作为结束标志
    short i = 0,  j = 0; // i,j 分别是infix和postfix的下标

    while(infix[i]!='\0'){
        if((infix[i]>='0' && infix[i]<='9') || infix[i]=='.'){
            //如果是数字或小数点就直接写入后缀表达式postfix
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else{
            postfix[j] = ' '; // 插入一个空格以分隔后缀表达式的各个部分
            j++; // 插入空格后j后移一位
            
            char optr_top = optr.get_top(); //获取optr栈顶运算符的优先级
            short p_out = priorOutSatck(infix[i]);
            short p_in = priorInSatck(optr_top);
            if(p_out > p_in){
                optr.push(infix[i]);
                i++;
            }
            else if(p_out < p_in){
                char operation = optr.pop();
                postfix[j] = operation;
                j++;
            }
            else{ // p_out == p_in ,只有两种情况，是等号或者是左右括号
                if(infix[i] == '='){
                    optr.pop(); // 弹出等号
                    postfix[j] = '='; // 写入等号
                    break;
                }
                else{
                    //infix[i]是右括号，optr栈顶运算符是左括号
                    optr.pop(); // 弹出左括号
                    i++; //继续处理下一个字符
                }
            }
        }
    }
    postfix[j] = '\0'; // 写入\0结束字符串
}

// 计算后缀表达式
double compute_postfix(const char * postfix){
/*计算后缀表达式
*准备一个运算数栈opnd，从左到右扫描后缀表达式postfix
    *如果postfix[i]是数字字符，就拼成数字压入opnd栈
    *如果postfix[i]是运算符，就从opnd中弹出两个数进行运算，结果压入opnd
*/
    LinkStack<double> opnd; // 运算数栈
    short i = 0;
    while(postfix[i]!='\0'){
        if(postfix[i]>='0' && postfix[i]<='9'){
            double num = spellNum(postfix, i);
            opnd.push(num);
        }
        else if(postfix[i] == ' '){
            // 是空格就跳过
            i++;
            continue;
        }
        else{
            double b = opnd.pop();
            double a = opnd.pop();
            double ret = operate(a, b, postfix[i]);
            opnd.push(ret);
            i++;
        }
    }
    double result = opnd.pop();
    if(opnd.isEmpty()==false){
        throw "后缀表达式有误";
    }
    return result;
}








int main(){
    while(true){
        double equa;
        char str[101];
        printf("输入中缀表达式：");
        scanf("%s", str);
        short len = strlen(str);
        str[len] = '=';
        str[len+1] = '\0';
        try{
            equa = compute_infix(str);
            printf("=%.10lf\n\n\n", equa);
        }
        catch(const char *err){
            printf("%s\n", err);
            //system("pause");
        }
        
        char postfix[101];
        infix_to_postfix(str, postfix);
        printf("后缀表达式: %s\n", postfix);
        try{
            equa = compute_postfix(postfix);
            printf("%.10lf\n\n\n", equa);
        }
        catch(const char *err){
            printf("%s\n", err);
            system("pause");
        }
        //system("pause");
    }
}