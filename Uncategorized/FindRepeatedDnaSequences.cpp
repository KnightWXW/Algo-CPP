#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//      LeetCode 187. 重复的DNA序列

//      链接：https://leetcode.cn/problems/repeated-dna-sequences/

//      DNA序列 由一系列核苷酸组成，缩写为 'A', 'C', 'G' 和 'T'.。
//      例如，"ACGAATTCCG" 是一个 DNA序列 。
//      在研究 DNA 时，识别 DNA 中的重复序列非常有用。
//      给定一个表示 DNA序列 的字符串 s ，返回所有在 DNA 分子中出现不止一次的 长度为 10 的序列(子字符串)。你可以按 任意顺序 返回答案。
//      示例 1：
//          输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
//          输出：["AAAAACCCCC","CCCCCAAAAA"]
//      示例 2：
//          输入：s = "AAAAAAAAAAAAA"
//          输出：["AAAAAAAAAA"]
//      提示：
//          0 <= s.length <= 105
//          s[i]=='A'、'C'、'G' or 'T'

vector<string> FindRepeatedDnaSequences(string s);

int generateRandomNum(int low, int high);
string generateRandomString(int n);
vector<string> generateRandomStringVector(int n, int low, int high);
void printString(string s);
void printStringVecElement(vector<string> vec);

int GatheringFiveBlessings(vector<string> vec);

int main()
{
    int n = generateRandomNum(1, 10);
    vector<string> strs = generateRandomStringVector(n, 5, 5);
    printStringVecElement(strs);
    int ans_A = GatheringFiveBlessings(strs);
    printf("该团队最多能凑齐 %d 套五福。\n", ans_A);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

void generateRandomString(int n, string &str)
{
    char arr[] = "ACGT";
    for (int i = 0; i < n; i++)
    {
        int index = rand() % (sizeof(arr) - 1);
        str += arr[index];
    }
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