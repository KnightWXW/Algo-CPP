#include <stdio.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

using namespace std;

//      LeetCode 395. 至少有 K 个重复字符的最长子串

//      给你一个字符串 s 和一个整数 k ，请你找出 s 中的最长子串，
//      要求该子串中的每一字符出现次数都不少于 k 。返回这一子串的长度。
//      示例 1：
//          输入：s = "aaabb", k = 3
//          输出：3
//          解释：最长子串为 "aaa" ，其中 'a' 重复了 3 次。
//      示例 2：
//          输入：s = "ababbc", k = 2
//          输出：5
//          解释：最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。
//      提示：
//          1 <= s.length <= 104
//          s 仅由小写英文字母组成
//          1 <= k <= 105

int generateRandomNum(int low, int high);
string generateRandomString(int n);
void printString(string s);

int LongestSubstring(string s, int k);

int main()
{
    int n = generateRandomNum(1, 30);
    string s = generateRandomString(n);
    int k = generateRandomNum(1, n / 5 + 1);
    int ans = LongestSubstring(s, k);
    printf("%s 中 每一字符出现次数都不少于 %d 次的 最长子串 的长度 为 %d\n", s.c_str(), k, ans);
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
    char arr[] = "abcde";
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

int LongestSubstring(string s, int k)
{
    int l = s.size();
    int ans = 0;

    for (int i = 0; i < 26; i++)
    {
        int left = 0;
        int right = 0;
        int cntAll = 0;
        int cntLess = 0;
        vector<int> cntArr(26);
        while (right < l)
        {
            cntArr[s[right] - 'a']++;
            if (cntArr[s[right] - 'a'] == 1)
            {
                cntAll++;
                cntLess++;
            }
            if (cntArr[s[right] - 'a'] == k)
            {
                cntLess--;
            }
            while (cntAll > i)
            {
                cntArr[s[left] - 'a']--;
                if (cntArr[s[left] - 'a'] == 0)
                {
                    cntAll--;
                    cntLess--;
                }
                if (cntArr[s[left] - 'a'] == k - 1)
                {
                    cntLess++;
                }
                left++;
            }
            if (cntLess == 0)
            {
                ans = max(ans, right - left + 1);
            }
            right++;
        }
    }
    return ans;
}