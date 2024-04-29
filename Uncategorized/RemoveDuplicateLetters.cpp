#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

//      LeetCode 316. 去除重复字母

//      链接1：https://leetcode.cn/problems/remove-duplicate-letters/
//      链接2：https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters

//      给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。
//      需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
//      示例 1：
//          输入：s = "bcabc"
//          输出："abc"
//      示例 2：
//          输入：s = "cbacdcbc"
//          输出："acdb"
//      提示：
//          1 <= s.length <= 104
//          s 由小写英文字母组成

int generateRandomNum(int low, int high);
string generateRandomString(int n);
void printString(string s);

string RemoveDuplicateLetters(string s);

int main()
{
    int n = generateRandomNum(1, 30);
    string s = generateRandomString(n);
    string ans = RemoveDuplicateLetters(s);
    printf("去除字符串中重复的字母后的字符串为: \n");
    printString(ans);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

void generateRandomString(int n, string &str)
{
    char arr[] = "abcdef";
    for (int i = 0; i < n; i++)
    {
        int index = rand() % (sizeof(arr) - 1);
        str += arr[index];
    }
}

void printString(string s)
{
    printf("%s\n", s.c_str());
}

string RemoveDuplicateLetters(string s)
{
    int l = s.size();
}