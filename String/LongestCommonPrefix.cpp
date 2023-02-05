#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>     

using namespace std;

//      LeetCode 14. 最长公共前缀

//      链接：https://leetcode.cn/problems/longest-common-prefix/

//      编写一个函数来查找字符串数组中的最长公共前缀。
//      如果不存在公共前缀，返回空字符串 ""。
//      示例 1：
//          输入：strs = ["flower","flow","flight"]
//          输出："fl"
//      示例 2：
//          输入：strs = ["dog","racecar","car"]
//          输出：""
//          解释：输入不存在公共前缀。
//      提示：
//          1 <= strs.length <= 200
//          0 <= strs[i].length <= 200
//          strs[i] 仅由小写英文字母组成

int generateRandomNum(int low, int high);
string generateRandomString(int n);
vector<string> generateRandomStringVector(int n, int low, int high);
void printString(string s);
void printStringVector(vector<string> vec);

string LongestCommonPrefix_A(vector<string> &strs);
string LongestCommonPrefix_B(vector<string> &strs);

int main()
{
    srand((int)time(0));
    int n = generateRandomNum(2, 4);
    vector<string> strs = generateRandomStringVector(n, 1, 10);
    printStringVector(strs);
    string ans_A = LongestCommonPrefix_A(strs);
    string ans_B = LongestCommonPrefix_B(strs);
    printf("字符串数组中的最长公共前缀为：\n");
    printString(ans_A);
    printString(ans_B);
}

int generateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
    return (rand() % (high - low + 1)) + low;
}

void generateRandomString(int n, string &str)
{
    char arr[] = "ab";
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

// 纵向比较：
// Time: O(N * M)
// Space: O(1)
string LongestCommonPrefix_A(vector<string> &strs)
{
    char cur = ' ';
    for (int j = 0; j < strs[0].size(); j++)
    {
        cur = strs[0][j];
        for (int i = 1; i < strs.size(); i++)
        {
            if (j >= strs[i].size() || strs[i][j] != cur)
            {
                return strs[0].substr(0, j);
            }
        }
    }
    return strs[0];
}

// 横向比较：
// Time: O(N * M)
// Space: O(1)
string LongestCommonPrefix_B(vector<string> &strs)
{
    int l = strs.size();
    if (l == 0)
    {
        return "";
    }
    string cur = strs[0];
    int ans = INT_MAX;
    for(int i = 0; i < l; i++){
        int index = 0;
        while(index < strs[i].size() && index < cur.size()){
            if(strs[i][index] != cur[index]){
                break;
            }
            index++;
        }
        ans = min(ans, index);
        if(ans == 0){
            return "";
        }
    }
    return strs[0].substr(0, ans);
}