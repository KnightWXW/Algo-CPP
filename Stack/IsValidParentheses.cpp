#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <stack>

using namespace std;

//      LeetCode 20. 有效的括号

//      链接：https://leetcode.cn/problems/valid-parentheses/

//      给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
//      有效字符串需满足：
//          左括号必须用相同类型的右括号闭合。
//          左括号必须以正确的顺序闭合。
//          每个右括号都有一个对应的相同类型的左括号。
//      示例 1：
//          输入：s = "()"
//          输出：true
//      示例 2：
//          输入：s = "()[]{}"
//          输出：true
//      示例 3：
//          输入：s = "(]"
//          输出：false
//      提示：
//          1 <= s.length <= 104
//          s 仅由括号 '()[]{}' 组成

int generateRandomNum(int low, int high);
string generateRandomString(int n);
void printString(string s);
void printBool(bool b);

bool IsValidParentheses_A(string s);
bool IsValidParentheses_B(string s);

int main()
{
    int n = generateRandomNum(1, 10);
    string str = generateRandomString(n);
    printf("字符串为：\n");
    printString(str);
    bool ans_A = IsValidParentheses_A(str);
    bool ans_B = IsValidParentheses_B(str);
    printf("字符串是否有效：\n");
    printBool(ans_A);
    printBool(ans_B);
}

int generateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
    return (rand() % (high - low + 1)) + low;
}

string generateRandomString(int n)
{
    string str = "";
    srand((int)time(0));
    char arr[] = "(){}[]";
    for (int i = 0; i < n; i++)
    {
        int index = rand() % (sizeof(arr) - 1);
        str += arr[index];
    }
    return str;
}

void printString(string s)
{
    printf("%s\n", s.c_str());
}

void printStringVector(vector<string> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printString(vec[i]);
    }
}

void printBool(bool b)
{
    if (b == true)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
}

// 栈
// Time: O(N)
// Space: O(N)
bool IsValidParentheses_A(string str)
{
    int l = str.size();
    if ((l & 1) == 1)
    {
        return false;
    }
    stack<char> s;
    for (int i = 0; i < l; i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            s.push(str[i]);
        }
        else if (s.empty())
        {
            return false;
        }
        else if (str[i] == ']' && s.top() == '[')
        {
            s.pop();
        }
        else if (str[i] == '}' && s.top() == '{')
        {
            s.pop();
        }
        else if (str[i] == ')' && s.top() == '(')
        {
            s.pop();
        }
        else
        {
            return false;
        }
    }
    return s.empty();
}

// 手写栈
// Time: O(N)
// Space: O(N)
bool IsValidParentheses_B(string str)
{
    int l = str.size();
    if ((l & 1) == 1)
    {
        return false;
    }
    vector<char> sv;
    for (int i = 0; i < l; i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            sv.push_back(str[i]);
        }
        else if (sv.empty())
        {
            return false;
        }
        else if (str[i] == ']' && sv[sv.size() - 1] == '[')
        {
            sv.pop_back();
        }
        else if (str[i] == '}' && sv[sv.size() - 1] == '{')
        {
            sv.pop_back();
        }
        else if (str[i] == ')' && sv[sv.size() - 1] == '(')
        {
            sv.pop_back();
        }
        else
        {
            return false;
        }
    }
    return sv.empty();
}