#include <stdio.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

using namespace std;

//      LeetCode 3. 无重复字符的最长子串

//      链接 1 ：https://leetcode.cn/problems/longest-substring-without-repeating-characters/
//      链接 2 : https://leetcode.cn/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/  

//      给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
//      示例 1:
//      输入: s = "abcabcbb"
//      输出: 3
//      解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
//      示例 2:
//      输入: s = "bbbbb"
//      输出: 1
//      解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
//      示例 3:
//      输入: s = "pwwkew"
//      输出: 3
//      解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//            请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
//      提示：
//          0 <= s.length <= 5 * 104
//          s 由英文字母、数字、符号和空格组成

int generateRandomNum(int low, int high);
string generateRandomString(int n);
void printString(string s);

int LengthOfLongestSubstring(string s);

int main()
{
    int n = generateRandomNum(0, 20);
    string s = generateRandomString(n);
    printString(s);
    int ans = LengthOfLongestSubstring(s);
    printf("不含有重复字符的 最长子串 的长度 %d\n", ans);
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
    char arr[] = "abcdef";
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
int LengthOfLongestSubstring(string s)
{
    int l = s.size();
    int left = 0;
    int right = 0;
    int ans = 0;
    unordered_map<char, int> hmap;

    while (right < l)
    {
        hmap[s[right]]++;
        while (hmap[s[right]] > 1)
        {
            hmap[s[left]]--;
            if (hmap[s[left]] == 0)
            {
                hmap.erase(s[left]);
            }
            left++;
        }
        ans = max(right - left + 1, ans);
        right++;
    }
    return ans;
}