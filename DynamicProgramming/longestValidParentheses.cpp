#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

//      32. 最长有效括号

//      链接：https://leetcode.cn/problems/longest-valid-parentheses/

//      给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。

//      示例 1：
//      输入：s = "(()"
//      输出：2
//      解释：最长有效括号子串是 "()"
//      示例 2：
//      输入：s = ")()())"
//      输出：4
//      解释：最长有效括号子串是 "()()"
//      示例 3：

//      输入：s = ""
//      输出：0
 
//      提示：
//          0 <= s.length <= 3 * 104
//          s[i] 为 '(' 或 ')'

int generateRandomNum(int low, int high);
string generateRandomString(int n);
void printString(string s);

int main(){
    int n = generateRandomNum(0, 20);
    string s = generateRandomString(n);
    printString(s);
    
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
    char arr[] = "()";
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