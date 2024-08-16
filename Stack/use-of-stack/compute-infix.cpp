/*��׺���ʽ��ֵ
*���裺������ɨ����׺���ʽinfix������ÿ��infix[i]��
    *���1��
        *���infix[i]�������ַ�����ƴ������ѹ��������ջopnd
    *���2
        *(1)���infix[i]���ȼ����������ջoptr��ջ�����������infix[i]��ջ
        *(2)���infix[i]���ȼ����������ջoptr��ջ�����������
            ����optrջ�������������������ջopnd����������������
            ��������󣬽��ѹ��������ջopnd�����ظ��Ƚϣ�ֱ���������1����ִ�����1
*
*             ����������ȼ���(��ֵԽ�����ȼ�Խ��)
*�����         =    (    *,/    +,-    )
*ջ�����ȼ�     0    1     5     3      6
*ջ�����ȼ�     0    6     4     2      1

*��ͬ�������ջ��������ȼ���ͬ��ԭ��Ҫ���������μ��㣬�ȼ���ջ�ڵĲż���ջ���
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include"..\\LinkStack\\LinkStack.h"


/***************************************��������************************************************************************/
double compute_infix(const char *infix); // ������׺���ʽ

double spellNum(const char *str, short &i);//ƴ�����������ַ�ƴ�����ֲ����ء�iΪ��ǰɨ�赽��infix���ַ��±꣬ƴ������i��Ӧ����
short priorInSatck(char in); // ���������in��ջ�ڵ����ȼ�(�����ȼ���)
short priorOutSatck(char out); // ���������out��ջ������ȼ�(�����ȼ���)
double operate(double a, double b, char operation); // ���һ�����㣬��a��b����operation����

void infix_to_postfix(const char *infix, char *postfix); // ����׺���ʽinfixת��Ϊ��׺���ʽ����ŵ�postfix
double compute_postfix(const char *postfix); // �����׺���ʽ



/************************************��������***************************************************************************/

// ������׺���ʽ
double compute_infix(const char *infix){
    LinkStack<char> optr; // �����ջ
    LinkStack<double> opnd; // ������ջ
    optr.clear();
    opnd.clear();
    optr.push('='); // ��'='ѹ�������ջ����Ϊ��������ı�־
    //������ɨ����׺���ʽinfix
    short i = 0; 
    while(infix[i]!='\0'){
        if(infix[i]>='0' && infix[i]<='9'){
            //infix[i]�������ַ���ƴ������ѹ��opnd
            double num = spellNum(infix, i);
            opnd.push(num);
            //spellNum()�����Ѿ�i++��
        }
        else{
            //���infix[i]����������ȱȽ�infix[i]��optrջ������������ȼ�
            char optr_top = optr.get_top();
            short p_in = priorInSatck(optr_top);
            short p_out = priorOutSatck(infix[i]);
            if(p_out > p_in){
                //���infix[i]���ȼ����������ջoptr��ջ�����������infix[i]��ջ���������ɨ��
                optr.push(infix[i]);
                i++;
            }
            else if(p_out < p_in){
                /*���infix[i]���ȼ����������ջoptr��ջ�����������
                    ����optrջ�������������������ջopnd����������������
                    ��������󣬽��ѹ��������ջopnd�����ظ��Ƚ�ֱ��infix[i]���ȼ�����optr��ջ�������*/
                char operation = optr.pop();
                double b = opnd.pop();
                double a = opnd.pop();
                double ret = operate(a, b, operation);
                opnd.push(ret);
            }
            else{ // p_out == p_in ,ֻ������������ǵȺŻ�������������
                if(infix[i] == '='){
                    optr.pop(); // �����Ⱥ�
                    break;
                }
                else{
                    //infix[i]�������ţ�optrջ���������������
                    optr.pop(); // ����������
                    i++; //����������һ���ַ�
                }
            }
        }
    }
    double result = opnd.pop();
    if(opnd.isEmpty()==false){
        //������ջ���ж�����֤�����ʽ����
        throw "�������׺���ʽ����(compute_infix)";
    }
    else{
        return result;
    }
}



//ƴ�����������ַ�ƴ�����ֲ����ء�iΪ��ǰɨ�赽��infix���ַ��±꣬ƴ������i��Ӧ����
double spellNum(const char *str, short &i){
    double num1=0, num2=0;//�ֱ𴢴��������ֺ�С������
    //������������
    while(str[i]>='0' && str[i]<='9'){
        num1 = num1*10 + (str[i]-'0'); // num1��10�൱�������ƶ�һ����λ��Ȼ���ټ��ϸ�λ(infix[i]-'0')
        i++;
    }
    if(str[i] == '.'){
        i++; // �������С���㣬������������С������
    }
    //����С������
    short exp=-1;
    while(str[i]>='0' && str[i]<='9'){
        num2 = num2 + (str[i]-'0')*pow(10, exp);
        i++;
        exp--;
    }
    //���ؽ��
    return num1+num2;
}


// ���������in��ջ�ڵ����ȼ�(�����ȼ���)
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

// ���������out��ջ������ȼ�(�����ȼ���)
short priorOutSatck(char out){
    switch(out){
    case '=': return 0; break;
    case '(': return 6; break;
    case '*':
    case '/': return 4; break;
    case '+':
    case '-': return 2; break;
    case ')': return 1; break;
    default: throw "�������׺���ʽ����(priorOutSatck)";
    }
}

// ���һ�����㣬��a��b����operation����
double operate(double a, double b, char operation){
    switch(operation){
        case '+': return a+b; break;
        case '-': return a-b; break;
        case '*': return a*b; break;
        case '/':
            if(fabs(b)<=1e-18)
                throw "���ڳ���Ϊ0";
            else{
                return a/b; break;
            }
    }
}


// ����׺���ʽinfixת��Ϊ��׺���ʽ����ŵ�postfix
void infix_to_postfix(const char * infix, char * postfix){
/*����׺���ʽת��Ϊ��׺���ʽ
*׼��һ�������ջoptr��������ɨ����׺���ʽ������ÿһ��infix[i]
    *���1����������ֻ�С�����ֱ��д���׺���ʽpostfix
    *���2�������������������ȼ�����optrջ�����������infix[i]��ջ
    *���3�������������������ȼ�����optrջ����������򵯳�optrջ���������
           д�뵽postfix�����ظ��������̣�ֱ��infix[i]���ȼ�����optrջ�������
    *���4������������ţ���infix[i]��ջ
    *���5������������ţ��򵯳�optrջ���������д��postfix��ֱ������������
*/
    LinkStack<char> optr; // �����ջ
    optr.push('=');  // optr��ѹ��һ���Ⱥţ���Ϊ������־
    short i = 0,  j = 0; // i,j �ֱ���infix��postfix���±�

    while(infix[i]!='\0'){
        if((infix[i]>='0' && infix[i]<='9') || infix[i]=='.'){
            //��������ֻ�С�����ֱ��д���׺���ʽpostfix
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else{
            postfix[j] = ' '; // ����һ���ո��Էָ���׺���ʽ�ĸ�������
            j++; // ����ո��j����һλ
            
            char optr_top = optr.get_top(); //��ȡoptrջ������������ȼ�
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
            else{ // p_out == p_in ,ֻ������������ǵȺŻ�������������
                if(infix[i] == '='){
                    optr.pop(); // �����Ⱥ�
                    postfix[j] = '='; // д��Ⱥ�
                    break;
                }
                else{
                    //infix[i]�������ţ�optrջ���������������
                    optr.pop(); // ����������
                    i++; //����������һ���ַ�
                }
            }
        }
    }
    postfix[j] = '\0'; // д��\0�����ַ���
}

// �����׺���ʽ
double compute_postfix(const char * postfix){
/*�����׺���ʽ
*׼��һ��������ջopnd��������ɨ���׺���ʽpostfix
    *���postfix[i]�������ַ�����ƴ������ѹ��opndջ
    *���postfix[i]����������ʹ�opnd�е����������������㣬���ѹ��opnd
*/
    LinkStack<double> opnd; // ������ջ
    short i = 0;
    while(postfix[i]!='\0'){
        if(postfix[i]>='0' && postfix[i]<='9'){
            double num = spellNum(postfix, i);
            opnd.push(num);
        }
        else if(postfix[i] == ' '){
            // �ǿո������
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
        throw "��׺���ʽ����";
    }
    return result;
}








int main(){
    while(true){
        double equa;
        char str[101];
        printf("������׺���ʽ��");
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
        printf("��׺���ʽ: %s\n", postfix);
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