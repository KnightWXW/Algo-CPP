#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//      LeetCode 22. 括号生成

//      链接：https://leetcode.cn/problems/generate-parentheses/

//      数字 n 代表生成括号的对数，
//      请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
//      示例 1：
//      输入：n = 3
//      输出：["((()))","(()())","(())()","()(())","()()()"]
//      示例 2：
//      输入：n = 1
//      输出：["()"]
//      提示：1 <= n <= 8

int generateRandomNum(int low, int high);
void printString(string s);
void printStringVecElement(vector<string> vec);

vector<string> GenerateParenthesis_A(int n);
void DFSGenerateParenthesis_A(string path, vector<string> &ans, int n, int leftCnt, int rightCnt);
vector<string> GenerateParenthesis_B(int n);
void DFSGenerateParenthesis_B(string path, vector<string> &ans, int n, int leftCnt, int rightCnt);

int main()
{
    int n = generateRandomNum(1, 8);
    vector<string> ans_A = GenerateParenthesis_A(n);
    vector<string> ans_B = GenerateParenthesis_B(n);
    printf("目标值 %d 能够生成所有可能的并且 有效的 括号组合为：\n", n);
    printf("------------------------------------------------\n");
    printStringVecElement(ans_A);
    printf("------------------------------------------------\n");
    printStringVecElement(ans_B);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
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

vector<string> GenerateParenthesis_A(int n)
{
    vector<string> ans;
    string path = "";
    DFSGenerateParenthesis_A(path, ans, n, 0, 0);
    return ans;
}

void DFSGenerateParenthesis_A(string path, vector<string> &ans, int n, int leftCnt, int rightCnt)
{
    // 左右括号都生成完，收集结果
    if (n == leftCnt && n == rightCnt)
    {
        ans.push_back(path);
        return;
    }
    // 左右括号超出数量 或 右括号比左括号多，直接返回
    if (leftCnt < rightCnt || leftCnt > n || rightCnt > n)
    {
        return;
    }
    DFSGenerateParenthesis_A(path + "(", ans, n, leftCnt + 1, rightCnt);
    DFSGenerateParenthesis_A(path + ")", ans, n, leftCnt, rightCnt + 1);
}

vector<string> GenerateParenthesis_B(int n){
    vector<string> ans;
    string path = "";
    DFSGenerateParenthesis_B(path, ans, n, 0, 0);
    return ans;
}
void DFSGenerateParenthesis_B(string path, vector<string> &ans, int n, int leftCnt, int rightCnt){
    // 左右括号都生成完，收集结果
    if (n == leftCnt && n == rightCnt)
    {
        ans.push_back(path);
        return;
    }
    // 左右括号超出数量 或 右括号比左括号多，直接返回
    if (leftCnt < rightCnt || leftCnt > n || rightCnt > n)
    {
        return;
    }
    if(leftCnt < n){
        path.push_back('(');
        DFSGenerateParenthesis_B(path, ans, n, leftCnt + 1, rightCnt);
        path.pop_back();
    }
    if(rightCnt < n){
        path.push_back(')');
        DFSGenerateParenthesis_B(path, ans, n, leftCnt, rightCnt + 1);
        path.pop_back();
    }
}