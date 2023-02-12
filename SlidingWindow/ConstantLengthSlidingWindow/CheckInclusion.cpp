#include <stdio.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

using namespace std;

//      LeetCode 567. 字符串的排列

//      链接1 : https://leetcode.cn/problems/permutation-in-string/
//      链接2 : https://leetcode.cn/problems/MPnaiL/

//      给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的排列。
//      如果是，返回 true ；否则，返回 false 。
//      换句话说，s1 的排列之一是 s2 的 子串 。
//      示例 1：
//          输入：s1 = "ab" s2 = "eidbaooo"
//          输出：true
//          解释：s2 包含 s1 的排列之一 ("ba").
//      示例 2：
//          输入：s1= "ab" s2 = "eidboaoo"
//          输出：false
//      提示：
//          1 <= s1.length, s2.length <= 104
//          s1 和 s2 仅包含小写字母

int generateRandomNum(int low, int high);
string generateRandomStringS(int n);
string generateRandomStringT(int n);
void printString(string s);
void printBool(bool b);

bool CheckInclusion(string s1, string s2);

int main()
{
    int n2 = generateRandomNum(1, 30);
    string s2 = generateRandomStringS(n2);
    int n1 = generateRandomNum(1, n2);
    string s1 = generateRandomStringT(n1);
    int ans = CheckInclusion(s1, s2);
    printf("字符串s1: %s \n字符串s2: %s \ns2 是否包含 s1 的排列???\n", s1.c_str(), s2.c_str());
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
    char arr[] = "abcdef";
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

bool CheckInclusion(string s1, string s2)
{

    int l1 = s1.size();
    int l2 = s2.size();
    if (l1 > l2)
    {
        return false;
    }
    vector<int> arr1(26, 0);
    vector<int> arr2(26, 0);

    for (int i = 0; i < l1; i++)
    {
        arr1[s1[i] - 'a']++;
    }
    for (int i = 0; i < l1; i++)
    {
        arr2[s2[i] - 'a']++;
    }
    if (arr1 == arr2)
    {
        return true;
    }
    for (int i = 0; i < l2 - l1; i++)
    {
        arr2[s2[i] - 'a']--;
        arr2[s2[i + l1] - 'a']++;
        if (arr1 == arr2)
        {
            return true;
        }
    }
    return false;
}