#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

//      LeetCode 318. 最大单词长度乘积

//      链接：https://leetcode.cn/problems/maximum-product-of-word-lengths/

//      给你一个字符串数组 words ，找出并返回 length(words[i]) * length(words[j]) 的最大值，
//      并且这两个单词不含有公共字母。如果不存在这样的两个单词，返回 0 。
//      示例 1：
//          输入：words = ["abcw","baz","foo","bar","xtfn","abcdef"]
//          输出：16
//          解释：这两个单词为 "abcw", "xtfn"。
//      示例 2：
//          输入：words = ["a","ab","abc","d","cd","bcd","abcd"]
//          输出：4
//          解释：这两个单词为 "ab", "cd"。
//      示例 3：
//          输入：words = ["a","aa","aaa","aaaa"]
//          输出：0
//          解释：不存在这样的两个单词。
//      提示：
//          2 <= words.length <= 1000
//          1 <= words[i].length <= 1000
//          words[i] 仅包含小写字母

int generateRandomNum(int low, int high);
string generateRandomString(int n);
vector<string> generateRandomStringVector(int n, int low, int high);
void printString(string s);
void printStringVector(vector<string> vec);

int MaxWordsProduct(vector<string> &words);

int main()
{
    srand((int)time(0));
    int n = generateRandomNum(1, 10);
    vector<string> strs = generateRandomStringVector(n, 1, 10);
    printStringVector(strs);
    int ans_A = MaxWordsProduct(strs);
    printf("最大单词长度乘积为：%d\n", ans_A);
}

int generateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
    return (rand() % (high - low + 1)) + low;
}

void generateRandomString(int n, string &str)
{
    char arr[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < n; i++)
    {
        int index = rand() % (sizeof(arr) - 1);
        str += arr[index];
    }
}

vector<string> generateRandomStringVector(int n, int low, int high)
{
    vector<string> vec;
    srand((int)time(0));
    for (int i = 0; i < n; i++)
    {
        string tem = "";
        int l = (rand() % (high - low + 1)) + low;
        generateRandomString(l, tem);
        vec.push_back(tem);
    }
    return vec;
}

void printString(string s)
{
    printf("%s\n", s.c_str());
}

void printStringVector(vector<string> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printString(vec[i]);
    }
}

// 位运算：
// Time: O(N^2)
// Space: O(N)
int MaxWordsProduct(vector<string> &words)
{
    int l = words.size();
    vector<int> cntArr(l, 0);
    for (int i = 0; i < words.size(); i++)
    {
        string tem = words[i];
        for (int j = 0; j < tem.size(); j++)
        {
            cntArr[i] |= (1 << (tem[j] - 'a'));
        }
    }
    int ans = 0;
    for (int i = 0; i < l; i++)
    {
        for (int j = i + 1; j < l; j++)
        {
            if ((cntArr[i] & cntArr[j]) == 0)
            {
                ans = max(ans, int(words[i].size() * words[j].size()));
            }
        }
    }
    return ans;
}