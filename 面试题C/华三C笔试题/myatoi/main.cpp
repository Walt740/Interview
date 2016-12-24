#include <iostream>

using namespace std;

#include<iostream>
#include<string>
using namespace std;


/*
��Ŀ������
��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯��atoi()��

���룺
������ܰ����������������
����ÿ�����԰���������Ϊһ���Ϸ����߷Ƿ����ַ���������һ������n(1<= n<=18446744073709551617)��

�����
��Ӧÿ�����԰�����
������Ϊһ����ʽ�Ϸ����ַ���(��ǡ�ñ�ʾһ������)����������������
������Ϊһ���Ϸ����ַ��������м���������֡�+��-����������ַ����������һ�������ַ�֮ǰ��������
������Ϊһ����ʽ�Ƿ����ַ����������0��
�����������ʽ�Ϸ���������INT_MIN��INT_MAX�����Ϊ�������INT_MAX�����Ϊ���������INT_MIN .

�������룺
"+8"
"1314"
"-123456"
"1ab3"
"    010";
"13  456"
"-66666666666"
"9223372036854775807"
"18446744073709551617"
"- +899999"
"   - 321"
"   +0 123"

���������
8
1314
-123456
1
10
13
-2147483648
2147483647
2147483647
0
0
0

ע�� ��������(Fermat number) F(n) = 2^(2^n) + 1��F(6)=18446744073709551617=2^64+1 (65λ����)��
9223372036854775807=2^63-1. ���������еĲ�������Դ�ڴˡ�����˳���¼ת����ĳ���newlen��
���ֵԽ��[INT_MIN, INT_MAX](�� ����newlen����11)����ǰ���INT_MAX�����Ϊ���������INT_MIN.
*/

class Solution {
public:
    int myAtoi(string str)
    {
        if(str=="") return 0;  // str.length()==0 �ȼ��� str==""������������дΪif(str=="" || str.length()==0)
        long long final, res=0;
        int len=str.length();
        int sign=1;
        int sign_count=0;
        for(int i=0; i<len; i++)
        {
            char ch=str[i];
            if(ch=='-' || ch=='+') sign_count++;
            if(sign_count<=1)
            {
                if(ch<='9' && ch>='0')
                {
                    res = res*10+ch-'0';
                    if(res> INT_MAX && sign==1) return INT_MAX;   // ������������INT_MAX��INT_MINʱ���輰ʱ�˳�������ȼ������ٷ��أ�final���Ϊ1(�洢Խ��)
                    if(res< INT_MIN && sign==-1) return INT_MIN;
                    if(i+1<len && str[i+1]==' ') break;
                }
                else if(ch=='-' || ch=='+')
                {
                    if(ch=='-') sign=-1;
                    if(i+1<len && str[i+1]==' ') break;
                }
                else if(ch==' ') ;  // ��ͷ�Ŀո���Ե�
                else break;  // ���벻�Ϸ����˳�ѭ��
            }
            else return 0;  //����������1 ������0
        }
        if(res>= INT_MIN && res <= INT_MAX) final=res*sign;
        else if(sign==1) final = INT_MAX;
            else if(sign==-1) final = INT_MIN;  // ���Խ�������߽磬������Ӧ��ֵ
        return final; // -2147483648[(signed int)0x80000000] ~ 2147483647(0x7FFFFFFF)
    }
};

// ����Ϊ����
int main()
{
    string str0; // str0.size() == 0; // ����İ�䣺��д�ɲ�д���ַ���Ĭ�ϳ�ʼ��Ϊ�մ�
    string str1="1ab3";  // Ӧ����1
    string str2="18446744073709551617";
    string str3="- +899999 ";
    string str4="    010"; // Ӧ����10
    string str5="   +0 123";
    string str6="13  456"; // 123
    string str7="   - 321";

    Solution sol;
    cout<<sol.myAtoi(str0)<<endl;
    cout<<sol.myAtoi(str1)<<endl;
    cout<<sol.myAtoi(str2)<<endl;
    cout<<sol.myAtoi(str3)<<endl;
    cout<<sol.myAtoi(str4)<<endl;
    cout<<sol.myAtoi(str5)<<endl;
    cout<<sol.myAtoi(str6)<<endl;
    cout<<sol.myAtoi(str7)<<endl;
    return 0;
}


/*ţ�������İ� AC���룺
class Solution {
public:
    int StrToInt(string str)
    {
        if(str=="") return 0;
        long long res=0;
        int len=str.length();
        int isPositive=1;

        for(int i=0; i<len; i++)
        {
            char ch=str[i];
            if(ch<='9' && ch>='0')  res = res*10+ch-'0';
            else if(ch=='-') isPositive=-1;
                else if(ch=='+') ;  // ��������������ɨ
                    else return 0;
        }
        return res*isPositive;
    }
};

*/
