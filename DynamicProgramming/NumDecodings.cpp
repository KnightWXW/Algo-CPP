#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

//      LeetCode 91. 解码方法

//      链接: https://leetcode.cn/problems/decode-ways/

//      一条包含字母 A-Z 的消息通过以下映射进行了 编码 ：
//      'A' -> "1"
//      'B' -> "2"
//          ...
//      'Z' -> "26"
//      要 解码 已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）。
//      例如，"11106" 可以映射为："AAJF" ，将消息分组为 (1 1 10 6)
//                              "KJF" ，将消息分组为 (11 10 6)
//      注意，消息不能分组为  (1 11 06) ，因为 "06" 不能映射为 "F" ，这是由于 "6" 和 "06" 在映射中并不等价。

//      给你一个只含数字的 非空 字符串 s ，请计算并返回 解码 方法的 总数 。

//      题目数据保证答案肯定是一个 32 位 的整数。

//      示例 1：
//          输入：s = "12"
//          输出：2
//          解释：它可以解码为 "AB"（1 2）或者 "L"（12）。

//      示例 2：
//          输入：s = "226"
//          输出：3
//          解释：它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。

//      示例 3：
//          输入：s = "0"
//          输出：0
//          解释：没有字符映射到以 0 开头的数字。
//          含有 0 的有效映射是 'J' -> "10" 和 'T'-> "20" 。
//          由于没有字符，因此没有有效的方法对此进行解码，因为所有数字都需要映射。

//      提示：
//          1 <= s.length <= 100
//          s 只包含数字，并且可能包含前导零。

int generateRandomNum(int low, int high);
string generateRandomString(int n);
void printString(string s);
int numDecoding_A(string s);
int dfsNumDecoding_A(string s, int i, int l);
int numDecoding_B(string s);
int dfsNumDecoding_B(string s, int i, int l, vector<int> arr);
int numDecoding_C(string s);
int numDecoding_D(string s);

int main()
{
    int n = generateRandomNum(0, 20);
    string s = generateRandomString(n);
    printString(s);
    printf("(暴力递归) 字符串 解码 方法 的 总数 为 %d\n", numDecoding_A(s));
    printf("(记忆化搜索) 字符串 解码 方法 的 总数 为 %d\n", numDecoding_B(s));
    printf("(动态规划<自右向左>) 字符串 解码 方法 的 总数 为 %d\n", numDecoding_C(s));
    printf("(动态规划<自左向右>) 字符串 解码 方法 的 总数 为 %d\n", numDecoding_D(s));
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
    char arr[] = "0123456789";
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
int numDecoding_A(string s)
{
    int l = s.size();
    if (l <= 0)
    {
        return 0;
    }
    return dfsNumDecoding_A(s, 0, l);
}

int dfsNumDecoding_A(string s, int i, int l)
{
    // 遍历到最后，满足条件，是 一条 合适的路径：
    if (i == l)
    {
        return 1;
    }
    // 当前的位置 为 ‘0’，说明 之前的选择 有问题：
    if (s[i] == '0')
    {
        return 0;
    }
    // 只 向后 遍历 一个字符:
    // 之前 判断 保证了 s[i] != '0'
    int path = dfsNumDecoding_A(s, i + 1, l);
    if (i + 1 < l && ((s[i + 1] - '0') * 10 + (s[i + 2] - '0') <= 26))
    {
        path += dfsNumDecoding_A(s, i + 2, l);
    }

    return path;
}

// 记忆化搜索:
// Time: O(2^N)
// Space: O(N)
int numDecoding_B(string s)
{
    int l = s.size();
    if (l <= 0)
    {
        return 0;
    }
    vector<int> arr(l + 1, 0);
    return dfsNumDecoding_B(s, 0, l, arr);
}

int dfsNumDecoding_B(string s, int i, int l, vector<int> arr)
{
    // 遍历到最后，满足条件，是 一条 合适的路径：
    if (i == l)
    {
        arr[l] = 1;
        return 1;
    }
    // 当前的位置 为 ‘0’，说明 之前的选择 有问题：
    if (s[i] == '0')
    {
        return 0;
    }

    if (arr[i] > 0)
    {
        return arr[i];
    }

    // 只 向后 遍历 一个字符:
    // 之前 判断 保证了 s[i] != '0'
    int path = dfsNumDecoding_B(s, i + 1, l, arr);
    if (i + 1 < l && ((s[i + 1] - '0') * 10 + (s[i + 2] - '0') <= 26))
    {
        path += dfsNumDecoding_B(s, i + 2, l, arr);
    }
    arr[i] = path;
    return path;
}

// 动态规划(自右往左):
// Time: O(N)
// Space: O(N)
int numDecoding_C(string s)
{
    int l = s.size();
    if (l <= 0)
    {
        return 0;
    }
    vector<int> dp(l + 1, 0);
    dp[l] = 1;
    for (int i = l - 1; i >= 0; i--)
    {
        if (s[i] != '0')
        {
            // 只 向后 遍历 一个字符:
            // 之前 判断 保证了 s[i] != '0'
            int path = dp[i + 1];
            if (i + 1 < l && ((s[i + 1] - '0') * 10 + (s[i + 2] - '0') <= 26))
            {
                path += dp[i + 2];
            }
            dp[i] = path;
        }
    }
    return dp[0];
}

// 动态规划(自左往右):
// Time: O(N)
// Space: O(N)
int numDecoding_D(string s)
{
    int l = s.size();
    if (l <= 0)
    {
        return 0;
    }
    vector<int> dp(l + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= l; i++)
    {
        if (s[i] != '0')
        {
            // 只 向后 遍历 一个字符:
            // 之前 判断 保证了 s[i] != '0'
            int path = dp[i - 1];
            if (i - 2 >= 0 && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26))
            {
                path += dp[i - 2];
            }
            dp[i] = path;
        }
    }
    return dp[l];
}