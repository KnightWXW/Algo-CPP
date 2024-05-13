#include <stdio.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

using namespace std;

//      LeetCode 340  至多包含 K 个不同字符的最长子串

//      链接：https://leetcode-cn.com/problems/longest-substring-with-at-most-k-distinct-characters

//      给定一个字符串 s ，找出 至多 包含 k 个不同字符的最长子串 T。
//      示例 1:
//      输入: s = “eceba”, k = 2
//      输出: 3
//          解释: 则 T 为 “ece”，所以长度为 3。
//      示例 2:
//      输入: s = “aa”, k = 1
//      输出: 2
//      解释: 则 T 为 “aa”，所以长度为 2。

int generateRandomNum(int low, int high);
string generateRandomString(int n);
void printString(string s);

int LengthOfLongestSubstringKDistinct_A(string s, int k);
int LengthOfLongestSubstringKDistinct_B(string s, int k);

int main()
{
    int n = generateRandomNum(1, 30);
    string s = generateRandomString(n);
    int k = generateRandomNum(1, n);
    int ans_A = LengthOfLongestSubstringKDistinct_A(s, k);
    int ans_B = LengthOfLongestSubstringKDistinct_B(s, k);
    printf("%s 中 至多 包含 %d 个不同字符的最长子串 的长度 为 %d\n", s.c_str(), k, ans_A);
    printf("%s 中 至多 包含 %d 个不同字符的最长子串 的长度 为 %d\n", s.c_str(), k, ans_B);
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
    char arr[] = "abcdefgh";
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
// Map: Key: 字符  Value: 字符出现的次数
int LengthOfLongestSubstringKDistinct_A(string s, int k)
{
    int l = s.size();
    int left = 0;
    int right = 0;
    int ans = 0;
    unordered_map<char, int> hmap;

    while (right < l)
    {
        hmap[s[right]]++;
        while(hmap.size() > k){
            hmap[s[left]]--;
            if(hmap[s[left]] == 0){
                hmap.erase(s[left]);
            }
            left++;
        }
        ans = max(ans, right - left + 1);
        right++;
    }
    return ans;
}

// 滑动窗口：
// Time: O(n)
// Space: O(n)
// Map: Key: 字符  Value: 字符上一次出现的索引位置
int LengthOfLongestSubstringKDistinct_B(string s, int k)
{
    int l = s.size();
    int left = 0;
    int right = 0;
    int ans = 0;
    unordered_map<char, int> hmap;

    while (right < l)
    {
        hmap[s[right]] = right;
        while(hmap.size() > k){
            if(hmap[s[left]] == left){
                hmap.erase(s[left]);
            }
            left++;
        }
        ans = max(ans, right - left + 1);
        right++;
    }
    return ans;
}