#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

//      LeetCode 516. 最长回文子序列

//      链接：https://leetcode.cn/problems/longest-palindromic-subsequence/

//      给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
//      子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。

//      示例 1：
//      输入：s = "bbbab"
//      输出：4
//      解释：一个可能的最长回文子序列为 "bbbb" 。

//      示例 2：
//      输入：s = "cbbd"
//      输出：2
//      解释：一个可能的最长回文子序列为 "bb" 。

//      提示：
//          1 <= s.length <= 1000
//          s 仅由小写英文字母组成

int generateRandomNum(int low, int high);
string generateRandomString(int n);
void printString(string s);
int longestPalindromeSubsequence_A(string s);
int dfsLongestPalindromeSubsequence_A(string s, int start, int end);
int longestPalindromeSubsequence_B(string s);
int dfsLongestPalindromeSubsequence_B(string s, int start, int end, vector<vector<int>> arr);
int longestPalindromeSubsequence_C(string s);

int main()
{
    int n = generateRandomNum(0, 20);
    string s = generateRandomString(n);
    printString(s);
    printf("(暴力递归) 字符串 中 最长的回文子序列字符串 的 长度 为 %d\n", longestPalindromeSubsequence_A(s));
    printf("(记忆化搜索) 字符串 中 最长的回文子序列字符串 的 长度 为 %d\n", longestPalindromeSubsequence_B(s));
    printf("(动态规划) 字符串 中 最长的回文子序列字符串 的 长度 为 %d\n", longestPalindromeSubsequence_C(s));
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
    char arr[] = "abcdefghijklmnopqrstuvwxyz";
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

// 暴力递归:
// Time: O(2^N)
// Space: O(N)
int longestPalindromeSubsequence_A(string s)
{
    int l = s.size();
    if (l <= 0)
    {
        return 0;
    }
    return dfsLongestPalindromeSubsequence_A(s, 0, l - 1);
}

int dfsLongestPalindromeSubsequence_A(string s, int start, int end)
{
    if (start > end)
    {
        return 0;
    }
    if (start == end)
    {
        return 1;
    }
    int p1 = 0;
    int p2 = 0;
    if (s[start] == s[end])
    {
        p1 = dfsLongestPalindromeSubsequence_A(s, start + 1, end - 1) + 2;
        return p1;
    }
    else
    {
        p2 = max(dfsLongestPalindromeSubsequence_A(s, start + 1, end), dfsLongestPalindromeSubsequence_A(s, start, end - 1));
        return p2;
    }
}

// 记忆化搜索:
// Time: O(2^N)
// Space: O(N)
int longestPalindromeSubsequence_B(string s)
{
    int l = s.size();
    if (l <= 0)
    {
        return 0;
    }
    vector<vector<int>> arr(l, vector<int>(l, 0));
    return dfsLongestPalindromeSubsequence_B(s, 0, l - 1, arr);
}

int dfsLongestPalindromeSubsequence_B(string s, int start, int end, vector<vector<int>> arr)
{
    if (start > end)
    {
        return 0;
    }
    if (start == end)
    {
        arr[start][end] == 1;
        return 1;
    }

    if (arr[start][end] > 0)
    {
        return arr[start][end];
    }
    int p1 = 0;
    int p2 = 0;
    if (s[start] == s[end])
    {
        p1 = dfsLongestPalindromeSubsequence_B(s, start + 1, end - 1, arr) + 2;
        arr[start][end] = p1;
        return p1;
    }
    else
    {
        p2 = max(dfsLongestPalindromeSubsequence_B(s, start + 1, end, arr), dfsLongestPalindromeSubsequence_B(s, start, end - 1, arr));
        arr[start][end] = p2;
        return p2;
    }
}

// 动态规划：
// Time: O(N * N)
// Space: O(N * N)
int longestPalindromeSubsequence_C(string s)
{
    int l = s.size();
    if (l <= 0)
    {
        return 0;
    }
    vector<vector<int>> dp(l, vector<int>(l, 0));
    for (int i = 0; i < l; i++)
    {
        dp[i][i] = 1;
    }

    for (int i = l - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < l; j++)
        {
            if (s[i] == s[j])
            {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][l - 1];
}