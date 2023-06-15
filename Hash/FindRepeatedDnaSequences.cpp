#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

//      LeetCode 187. 重复的DNA序列

//      链接：https://leetcode.cn/problems/repeated-dna-sequences/

//      DNA序列 由一系列核苷酸组成，缩写为 'A', 'C', 'G' 和 'T'。
//      例如，"ACGAATTCCG" 是一个 DNA序列 。
//      在研究 DNA 时，识别 DNA 中的重复序列非常有用。
//      给定一个表示 DNA序列 的字符串 s，
//      返回所有在 DNA 分子中出现不止一次的 长度为 10 的序列(子字符串)。
//      你可以按 任意顺序 返回答案。
//      示例 1：
//          输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
//          输出：["AAAAACCCCC","CCCCCAAAAA"]
//      示例 2：
//          输入：s = "AAAAAAAAAAAAA"
//          输出：["AAAAAAAAAA"]
//      提示：
//          0 <= s.length <= 105
//          s[i]=='A'、'C'、'G' or 'T'

int generateRandomNum(int low, int high);
string generateRandomString(int n);
void printString(string s);
void printStringVecElement(vector<string> vec);

vector<string> FindRepeatedDnaSequences(string s);

int main()
{
    int n = generateRandomNum(1, 500);
    string s = generateRandomString(n);
    printString(s);
    vector<string> ans_A = FindRepeatedDnaSequences(s);
    printf("所有在 DNA 分子中出现不止一次的 长度为 10 的序列(子字符串)为：\n");
    printStringVecElement(ans_A);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

string generateRandomString(int n)
{
    char arr[] = "ACGT";
    string str = "";
    for (int i = 0; i < n; i++)
    {
        int index = rand() % (sizeof(arr) - 1);
        str += arr[index];
    }
    return str;
}

vector<int> generateRandomVec(int low, int high, int len)
{
    vector<int> vec;
    srand(time(0));
    for (int i = 0; i < len; i++)
    {
        int v = (rand() % (high - low + 1)) + low;
        vec.push_back(v);
    }
    return vec;
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

// 哈希表
// Time: O(N * L)
// Space: O(N * L)
vector<string> FindRepeatedDnaSequences(string s)
{
    const int DNA_LEN = 10;
    vector<string> ans;
    int l = s.size();
    unordered_map<string, int> hmap;
    if (l < 10)
    {
        return ans;
    }
    for (int i = 0; i <= l - DNA_LEN; i++)
    {
        string tem = s.substr(i, DNA_LEN);
        hmap[tem]++;
    }
    for (auto it = hmap.begin(); it != hmap.end(); it++)
    {
        if (it->second > 1)
        {
            ans.push_back(it->first);
        }
    }
    return ans;
}