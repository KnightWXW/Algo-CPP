#include <stdio.h>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <numeric>
#include <stack>

using namespace std;

//      LeetCode 227. 基本计算器 II

//      链接：https://leetcode.cn/problems/basic-calculator-ii/

//      给你一个字符串表达式 s，请你实现一个基本计算器来计算并返回它的值。
//      整数除法仅保留整数部分。
//      你可以假设给定的表达式总是有效的。
//      所有中间结果将在 [-2 ^ 31, 2 ^ 31 - 1] 的 范围内。
//      注意：不允许使用任何将字符串作为数学表达式计算的内置函数，比如 eval()。
//      示例 1：
//          输入：s = "3+2*2"
//          输出：7
//      示例 2：
//          输入：s = " 3/2 "
//          输出：1
//      示例 3：
//          输入：s = " 3+5 / 2 "
//          输出：5
//      提示：
//          1 <= s.length <= 3 * 105
//          s 由整数和算符 ('+', '-', '*', '/') 组成，中间由一些空格隔开
//          s 表示一个 有效表达式
//          表达式中的所有整数都是非负整数，且在范围 [0, 2 ^ 31 - 1] 内
//          题目数据保证答案是一个 32-bit 整数

void printString(string s);

int CalculateComputer(string s);

int main()
{
    string s1 = "3+2*2";
    int ans1 = CalculateComputer(s1);
    printString(s1);
    printf("计算该表达式结果为 %d。\n", ans1);
    string s2 = " 3/2 ";
    int ans2 = CalculateComputer(s2);
    printString(s2);
    printf("计算该表达式结果为 %d。\n", ans2);
    string s3 = " 3+5 / 2 ";
    int ans3 = CalculateComputer(s3);
    printString(s3);
    printf("计算该表达式结果为 %d。\n", ans3);
}

void printString(string s)
{
    printf("%s\n", s.c_str());
}

// 手写栈
// Time: O(N)
// Space: O(N)
int CalculateComputer(string s)
{
    stack<int> stk;
    s = s + "+0";
    char operTag = '+';
    int num = 0;
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (isspace(s[i]))
        {
            continue;
        }
        else if (isdigit(s[i]))
        {
            num = num * 10 + (s[i] - '0');
        }
        else
        {
            if (operTag == '+')
            {
                stk.push(num);
            }
            else if (operTag == '-')
            {
                stk.push(-num);
            }
            else if (operTag == '*')
            {
                int tem = stk.top();
                stk.pop();
                stk.push(tem * num);
            }
            else if (operTag == '/')
            {
                int tem = stk.top();
                stk.pop();
                stk.push(tem / num);
            }
            operTag = s[i];
            num = 0;
        }
    }
    while (!stk.empty())
    {
        ans += stk.top();
        stk.pop();
    }
    return ans;
}