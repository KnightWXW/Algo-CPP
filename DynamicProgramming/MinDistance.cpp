#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//      LeetCode 72. 编辑距离

//      链接：https://leetcode.cn/problems/edit-distance/

//      给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数 。
//      你可以对一个单词进行如下三种操作：
//          插入一个字符
//          删除一个字符
//          替换一个字符
//      示例 1：
//          输入：word1 = "horse", word2 = "ros"
//      输出：3
//      解释：
//          horse -> rorse (将 'h' 替换为 'r')
//          rorse -> rose (删除 'r')
//          rose -> ros (删除 'e')
//      示例 2：
//          输入：word1 = "intention", word2 = "execution"
//      输出：5
//      解释：
//          intention -> inention (删除 't')
//          inention -> enention (将 'i' 替换为 'e')
//          enention -> exention (将 'n' 替换为 'x')
//          exention -> exection (将 'n' 替换为 'c')
//          exection -> execution (插入 'u')
//      提示：
//          0 <= word1.length, word2.length <= 500
//          word1 和 word2 由小写英文字母组成

int generateRandomNum(int low, int high);
string generateRandomString(int n);
void printString(string s);
void printBool(bool b);

int MinDistance_A(string word1, string word2);
int MinDistance_B(string word1, string word2);
int MinDistance_C(string word1, string word2);


int main()
{
    int ns = generateRandomNum(1, 10);
    string s = generateRandomString(ns);
    int nt = generateRandomNum(1, 9);
    string t = generateRandomStringT(nt);
    bool ans_A = MinDistance_A(s, t);
    bool ans_B = MinDistance_B(s, t);
    bool ans_C = MinDistance_C(s, t);
    printf("字符串s: %s \n字符串t: %s \n", s.c_str(), t.c_str());
    printf("它们的编辑距离为 %d\n", ans_A); 
    printf("它们的编辑距离为 %d\n", ans_B); 
    printf("它们的编辑距离为 %d\n", ans_C); 
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