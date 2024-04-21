#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

//      LeetCode 739. 每日温度

//      链接：https://leetcode.cn/problems/daily-temperatures/

//      给定一个整数数组 temperatures ，表示每天的温度，
//      返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。
//      如果气温在这之后都不会升高，请在该位置用 0 来代替。
//      示例 1:
//          输入: temperatures = [73,74,75,71,69,72,76,73]
//          输出: [1,1,4,2,1,1,0,0]
//      示例 2:
//          输入: temperatures = [30,40,50,60]
//          输出: [1,1,1,0]
//      示例 3:
//          输入: temperatures = [30,60,90]
//          输出: [1,1,0]
//      提示：
//          1 <= temperatures.length <= 105
//          30 <= temperatures[i] <= 100

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

vector<int> DailyTemperatures(vector<int> &temperatures);

int main()
{
    int n = generateRandomNum(1, 10);
    vector<int> vec = generateRandomVec(1, 100, n);
    printVecElement(vec);
    vector<int> ans_A = DailyTemperatures(vec);
    printf("下一个更高温度出现在几天后的数组为: \n");
    printVecElement(ans_A);
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

// 单调栈：
// Space: O(N)
// Time: O(1)
vector<int> DailyTemperatures(vector<int> &temperatures)
{
    int l = temperatures.size();
    stack<int> stk;
    vector<int> ans(l, 0);
    for (int i = 0; i < l; i++)
    {
        while (!stk.empty() && temperatures[stk.top()] < temperatures[i])
        {
            int tem = stk.top();
            ans[tem] = i - tem;
            stk.pop();
        }
        stk.push(i);
    }
    while (!stk.empty())
    {
        int tem = stk.top();
        ans[tem] = 0;
        stk.pop();
    }
    return ans;
}