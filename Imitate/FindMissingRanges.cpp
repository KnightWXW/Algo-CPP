#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//      LeetCode 163 缺失的区间

//      链接：https://leetcode.cn/problems/missing-ranges/

//      给定一个有序无重复的数组nums和两个整数lower和upper，
//      返回 [lower,upper] 上所有缺失的数字段
//      示例1:
//          nums = [0,1,3,50,75], lower = 0, upper = 99
//          输出:["2","4->49","51->74","76->99"]
//      示例2:
//          nums = [], lower = 1, upper = 1
//          输出: ["1"]
//      示例3:
//          nums = [], lower = -3, upper = -1
//          输出： ["-3->-1"]
//      示例4:
//          nums = [-1], lower = -1, upper = -1
//          输出: []
//      示例5:
//          nums = [-1], lower = -2, upper = -1
//          输出: ["-2"]

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);
void printString(string s);
void printStringVecElement(vector<string> vec);

vector<string> FindMissingRanges(vector<int> &nums, int lower, int upper);
string AddMissingRanges(int left, int right);

int main()
{
    int n = generateRandomNum(1, 10);
    vector<int> vec = generateRandomVec(-100, 100, n);
    sort(vec.begin(), vec.end());
    printVecElement(vec);
    int lower = generateRandomNum(-200, 1);
    int upper = generateRandomNum(1, 200);
    vector<string> ans = FindMissingRanges(vec, lower, upper);
    printf("[%d, %d]所有缺失的数字段为：\n", lower, upper);
    printStringVecElement(ans);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

void printVecElement(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

vector<int> generateRandomVec(int low, int high, int len)
{
    srand((int)time(0));
    vector<int> vec;
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

vector<string> FindMissingRanges(vector<int> &nums, int lower, int upper)
{
    vector<string> ans;
    int l = nums.size();
    for (int i = 0; i < l; i++)
    {
        int tem = nums[i];
        if (tem > lower)
        {
            ans.push_back(AddMissingRanges(lower, tem - 1));
        }
        if (tem == upper)
        {
            return ans;
        }
        lower = tem + 1;
    }
    if (lower <= upper)
    {
        ans.push_back(AddMissingRanges(lower, upper));
    }
    return ans;
}

string AddMissingRanges(int left, int right)
{
    string leftStr = to_string(left);
    string rightStr = "";
    if (right > left)
    {
        rightStr = "->" + to_string(right);
    }
    return leftStr + rightStr;
}