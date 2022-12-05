#include <stdio.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

using namespace std;

//      LeetCode 76. 最小覆盖子串

//      链接1：https://leetcode.cn/problems/minimum-window-substring/
//      链接2：https://leetcode.cn/problems/M1oyTv/

//      给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。
//      如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
//      注意：

//      对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
//      如果 s 中存在这样的子串，我们保证它是唯一的答案。

//      示例 1：
//          输入：s = "ADOBECODEBANC", t = "ABC"
//          输出："BANC"
//      示例 2：
//          输入：s = "a", t = "a"
//          输出："a"
//      示例 3
//          输入: s = "a", t = "aa"
//          输出: ""
//      解释: t 中两个字符 'a' 均应包含在 s 的子串中，
//      因此没有符合条件的子字符串，返回空字符串。
//      提示：
//          1 <= s.length, t.length <= 105
//          s 和 t 由英文字母组成

int generateRandomNum(int low, int high);
string generateRandomStringS(int n);
string generateRandomStringT(int n);
void printString(string s);

string MinWindowSubString(string s, string t);

int main()
{
    int ns = generateRandomNum(1, 10);
    string s = generateRandomStringS(ns);
    int nt = generateRandomNum(1, ns);
    string t = generateRandomStringT(nt);
    string ans = MinWindowSubString(s, t);
    printf("%s 中涵盖 %s 所有字符的最小子串 为 %s\n", s.c_str(), t.c_str(), ans.c_str());
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
    char arr[] = "abcABC";
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
    char arr[] = "abcABC";
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

// 滑动窗口：
// Time: O(n)
// Space: O(n)
string MinWindowSubString(string s, string t)
{
    int l = s.size();
    unordered_map<char, int> smap, tmap;
    int left = 0;
    int right = 0;
    int cnt = 0;
    string ans("");

    for (int i = 0; i < t.size(); i++)
    {
        tmap[t[i]]++;
    }

    while (right < l)
    {
        smap[s[right]]++;
        if (smap[s[right]] <= tmap[s[right]])
        {
            cnt++;
        }
        while (smap[s[left]] > tmap[s[left]])
        {
            smap[s[left]]--;
            left++;
        }
        if (cnt == t.size())
        {
            if (ans == "" || right - left + 1 < ans.size())
            {
                ans = s.substr(left, right - left + 1);
            }
        }
        right++;
    }

    return ans;
}