#include <iostream>

using namespace std;

#include<iostream>
#include<string>
using namespace std;


/*
题目描述：
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数atoi()。

输入：
输入可能包含多个测试样例。
对于每个测试案例，输入为一个合法或者非法的字符串，代表一个整数n(1<= n<=18446744073709551617)。

输出：
对应每个测试案例，
若输入为一个格式合法的字符串(即恰好表示一个整数)，则输出这个整数；
若输入为一个合法的字符串，但中间出现了数字、+、-以外的特殊字符，则输出第一个特殊字符之前的整数；
若输入为一个格式非法的字符串，则输出0；
若输入的数格式合法，但超出INT_MIN或INT_MAX，如果为正数输出INT_MAX，如果为负数则输出INT_MIN .

样例输入：
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

样例输出：
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

注： 费马质数(Fermat number) F(n) = 2^(2^n) + 1，F(6)=18446744073709551617=2^64+1 (65位的数)，
9223372036854775807=2^63-1. 测试用例中的部分数来源于此。可以顺便记录转换后的长度newlen，
如果值越出[INT_MIN, INT_MAX](或 长度newlen超过11)，提前输出INT_MAX，如果为负数则输出INT_MIN.
*/

class Solution {
public:
    int myAtoi(string str)
    {
        if(str=="") return 0;  // str.length()==0 等价于 str==""，故条件不必写为if(str=="" || str.length()==0)
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
                    if(res> INT_MAX && sign==1) return INT_MAX;   // 当输入数超过INT_MAX或INT_MIN时，需及时退出，如果等计算完再返回，final会变为1(存储越界)
                    if(res< INT_MIN && sign==-1) return INT_MIN;
                    if(i+1<len && str[i+1]==' ') break;
                }
                else if(ch=='-' || ch=='+')
                {
                    if(ch=='-') sign=-1;
                    if(i+1<len && str[i+1]==' ') break;
                }
                else if(ch==' ') ;  // 开头的空格忽略掉
                else break;  // 输入不合法，退出循环
            }
            else return 0;  //符号数大于1 ，返回0
        }
        if(res>= INT_MIN && res <= INT_MAX) final=res*sign;
        else if(sign==1) final = INT_MAX;
            else if(sign==-1) final = INT_MIN;  // 如果越出整数边界，返回相应的值
        return final; // -2147483648[(signed int)0x80000000] ~ 2147483647(0x7FFFFFFF)
    }
};

// 以下为测试
int main()
{
    string str0; // str0.size() == 0; // 后面的半句：可写可不写，字符串默认初始化为空串
    string str1="1ab3";  // 应返回1
    string str2="18446744073709551617";
    string str3="- +899999 ";
    string str4="    010"; // 应返回10
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


/*牛客网中文版 AC代码：
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
                else if(ch=='+') ;  // 不处理，继续往后扫
                    else return 0;
        }
        return res*isPositive;
    }
};

*/
