#include <stdio.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

using namespace std;

//      LeetCode 161 相隔为 1 的编辑距离

//      链接: https://leetcode.cn/problems/one-edit-distance/

//      给定两个字符串 s 和 t ，如果它们的编辑距离为 1 ，则返回 true ，否则返回 false 。
//      字符串 s 和字符串 t 之间满足编辑距离等于 1 有三种可能的情形：
//          往 s 中插入 恰好一个 字符得到 t
//          从 s 中删除 恰好一个 字符得到 t
//          在 s 中用 一个不同的字符 替换 恰好一个 字符得到 t
//      示例 1：
//          输入: s = “ab”, t = “acb”
//          输出: true
//          解释: 可以将 ‘c’ 插入字符串 s 来得到 t。
//      示例 2:
//          输入: s = “cab”, t = “ad”
//          输出: false
//          解释: 无法通过 1 步操作使 s 变为 t。
//      提示:
//          0 <= s.length, t.length <= 104
//          s 和 t 由小写字母，大写字母和数字组成

int generateRandomNum(int low, int high);
string generateRandomStringS(int n);
string generateRandomStringT(int n);
void printString(string s);
void printBool(bool b);

bool OneEditDistance(string s, string t);

int main()
{
    int ns = generateRandomNum(1, 10);
    string s = generateRandomStringS(ns);
    int nt = generateRandomNum(1, 10);
    string t = generateRandomStringT(nt);
    bool ans = OneEditDistance(s, t);
    printf("字符串s: %s \n字符串t: %s \n它们的编辑距离为: \n", s.c_str(), t.c_str());
    printBool(ans);
}

int generateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
    return (rand() % (high - low + 1)) + low;
}

string generateRandomStringS(int n)
{
    string str = "";
    srand((int)time(0));
    char arr[] = "abc";
    for (int i = 0; i < n; i++)
    {
        int index = rand() % (sizeof(arr) - 1);
        str += arr[index];
    }
    return str;
}

string generateRandomStringT(int n)
{
    string str = "";
    srand((int)time(0) + 1);
    char arr[] = "abc";
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

bool OneEditDistance(string s, string t)
{
    int l1 = s.length();
    int l2 = t.length();
    if (abs(l1 - l2) > 1)
    {
        return false;
    }
    if (l1 > l2)
    {
        return OneEditDistance(t, s);
    }
    int left = 0;
    int rightS = l1 - 1;
    int rightT = l2 - 1;
    while (left <= rightS)
    {
        if (s[left] != t[left] && s[rightS] != t[rightT])
        {
            break;
        }
        if (s[left] == t[left])
        {
            left++;
        }
        if (s[rightS] == t[rightT])
        {
            rightS--;
            rightT--;
        }
    }
    if (l1 == l2)
    {
        return left == rightS;
    }
    else
    {
        return left > rightS;
    }
}