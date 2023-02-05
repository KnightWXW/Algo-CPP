#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//      LeetCode 17. 电话号码的字母组合

//      链接：https://leetcode.cn/problems/letter-combinations-of-a-phone-number/

//      给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
//      答案可以按 任意顺序 返回。
//      给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
//      示例 1：
//          输入：digits = "23"
//          输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
//      示例 2：
//          输入：digits = ""
//          输出：[]
//      示例 3：
//          输入：digits = "2"
//          输出：["a","b","c"]
//      提示：
//          0 <= digits.length <= 4
//          digits[i] 是范围 ['2', '9'] 的一个数字。

int generateRandomNum(int low, int high);
string generateRandomString(int n);
void printString(string s);
void printStringVecElement(vector<string> vec);

vector<string> LetterCombinations_A(string digits);
void DFSLetterCombinations_A(string digits, unordered_map<char, string> digitMap,
                           int index, vector<string> &ans, string &path);

int main()
{
    int n = generateRandomNum(0, 4);
    string str = generateRandomString(n);
    printf("数字的字符串为：");
    printString(str);
    vector<string> vec = LetterCombinations_A(str);
    printf("它能表示的字母组合：\n");
    printStringVecElement(vec);
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
    char arr[] = "23456789";
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

void printStringVecElement(vector<string> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%s\n", vec[i].c_str());
    }
    printf("\n");
}

vector<string> LetterCombinations_A(string digits)
{
    int l = digits.size();
    vector<string> ans;
    string path;
    if (l == 0 || digits == "")
    {
        return ans;
    }
    unordered_map<char, string> digitMap = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };
    DFSLetterCombinations_A(digits, digitMap, 0, ans, path);
    return ans;
}

void DFSLetterCombinations_A(string digits, unordered_map<char, string> digitMap,
                           int index, vector<string> &ans, string &path)
{
    if (index == digits.size())
    {
        ans.push_back(path);
        return;
    }
    string cur = digitMap[digits[index]];
    for (int i = 0; i < cur.size(); i++)
    {
        path.push_back(cur[i]);
        DFSLetterCombinations_A(digits, digitMap, index + 1, ans, path);
        path.pop_back();
    }
}