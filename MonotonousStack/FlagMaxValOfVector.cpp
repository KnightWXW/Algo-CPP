#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stack>

using namespace std;

//      给定一个只包含正数的数组arr(arr[i] > 0)，arr中任何一个子数组sub，
//      一定都可以算出flag值为多少？
//      flag == (sub 的累加和 ) × (sub 子数组中的 最小值)
//      那么所有子数组中，这个 flag值 最大是多少？

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
void print2DVecElement(vector<vector<int>> vec);
vector<int> generateRandomVec(int low, int high, int len);
int flagMaxValOfVector_A(vector<int> vec);
int flagMaxValOfVector_B(vector<int> vec);
int flagMaxValOfVector_C(vector<int> vec);

int main()
{
    vector<int> vec = generateRandomVec(1, 10, 10);
    printVecElement(vec);
    printf("(单调栈-重复值)数组中Flag的最大值为%d\n", flagMaxValOfVector_A(vec));
    printf("(单调栈-无重复值)数组中Flag的最大值为%d\n", flagMaxValOfVector_B(vec));
    printf("(暴力循环)数组中Flag的最大值为%d\n", flagMaxValOfVector_C(vec));
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

void print2DVecElement(vector<vector<int>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[0].size(); j++)
        {
            printf("%d\t", vec[i][j]);
        }
        printf("\n");
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

// 单调栈(含重复值) + 前缀和：
// Time: O(n)
// Space: O(n)
int flagMaxValOfVector_A(vector<int> vec)
{
    if (vec.size() <= 0)
    {
        return 0;
    }
    vector<int> preSum(vec.size(), 0);
    preSum[0] = vec[0];
    for (int i = 1; i < preSum.size(); i++)
    {
        preSum[i] = preSum[i - 1] + vec[i];
    }

    stack<vector<int>> stack;
    int ans = INT_MIN;

    for (int i = 0; i < vec.size(); i++)
    {
        while (!stack.empty() && vec[stack.top()[0]] > vec[i])
        {
            vector<int> tem = stack.top();
            stack.pop();
            int lessIndex = stack.empty() ? -1 : stack.top()[stack.top().size() - 1];
            for (int j = 0; j < tem.size(); j++)
            {
                int leftIndex = lessIndex;
                int rightIndex = i;
                if (leftIndex == -1)
                {
                    ans = max(ans, (preSum[rightIndex - 1]) * vec[tem[tem.size() - 1]]);
                }
                else
                {
                    ans = max(ans, (preSum[rightIndex - 1] - preSum[leftIndex]) * vec[tem[tem.size() - 1]]);
                }
            }
        }
        if (!stack.empty() && vec[stack.top()[0]] == vec[i])
        {
            stack.top().push_back(i);
        }
        else
        {
            vector<int> tem = {i};
            stack.push(tem);
        }
    }

    while (!stack.empty())
    {
        vector<int> tem = stack.top();
        stack.pop();
        int lessIndex = stack.empty() ? -1 : stack.top()[stack.top().size() - 1];
        for (int j = 0; j < tem.size(); j++)
        {
            int leftIndex = lessIndex;
            int rightIndex = vec.size();
            if (leftIndex == -1)
            {
                ans = max(ans, (preSum[rightIndex - 1]) * vec[tem[tem.size() - 1]]);
            }
            else
            {
                ans = max(ans, (preSum[rightIndex - 1] - preSum[leftIndex]) * vec[tem[tem.size() - 1]]);
            }
        }
    }
    return ans;
}

// 单调栈(不含重复值) + 前缀和：
// Time: O(n)
// Space: O(n)
int flagMaxValOfVector_B(vector<int> vec)
{
    if (vec.size() <= 0)
    {
        return 0;
    }
    vector<int> preSum(vec.size(), 0);
    preSum[0] = vec[0];
    for (int i = 1; i < preSum.size(); i++)
    {
        preSum[i] = preSum[i - 1] + vec[i];
    }

    stack<int> stack;
    int ans = INT_MIN;

    for (int i = 0; i < vec.size(); i++)
    {
        while (!stack.empty() && vec[stack.top()] >= vec[i])
        {
            int tem = stack.top();
            stack.pop();
            int lessIndex = stack.empty() ? -1 : stack.top();
            int leftIndex = lessIndex;
            int rightIndex = i;
            if (leftIndex == -1)
            {
                ans = max(ans, (preSum[rightIndex - 1]) * vec[tem]);
            }
            else
            {
                ans = max(ans, (preSum[rightIndex - 1] - preSum[leftIndex]) * vec[tem]);
            }
        }
        stack.push(i);
    }

    while (!stack.empty())
    {
        int tem = stack.top();
        stack.pop();
        int lessIndex = stack.empty() ? -1 : stack.top();
        int leftIndex = lessIndex;
        int rightIndex = vec.size();
        if (leftIndex == -1)
        {
            ans = max(ans, (preSum[rightIndex - 1]) * vec[tem]);
        }
        else
        {
            ans = max(ans, (preSum[rightIndex - 1] - preSum[leftIndex]) * vec[tem]);
        }
    }
    return ans;
}

// 暴力循环：
// Time: O(n ^ 3)
// Space: O(n)
int flagMaxValOfVector_C(vector<int> vec)
{
    if (vec.size() <= 0)
    {
        return 0;
    }
    int ans = INT_MIN;
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = i; j < vec.size(); j++)
        {
            int tem = INT_MAX;
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                tem = min(tem, vec[k]);
                sum += vec[k];
            }
            ans = max(ans, tem * sum);
        }
    }
    return ans;
}