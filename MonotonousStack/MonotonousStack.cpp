#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stack>

using namespace std;

//      单调栈，顾名思义就是栈内元素单调按照递增(递减)顺序排列的栈。
//      单调递增栈：单调递增栈 就是 从栈底到栈顶 数据是 从大到小
//      单调递减栈：单调递减栈 就是 从栈底到栈顶 数据是 从小到大

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
void print2DVecElement(vector<vector<int>> vec);
vector<int> generateRandomVec(int low, int high, int len);
vector<vector<int>> monotonousStack_NoRepeat(vector<int> arr1);
vector<vector<int>> monotonousStack_HasRepeat(vector<int> arr2);

int main()
{
    vector<int> arr1 = {3, 2, 1, 7, 5, 4, 9, 8, 6, 0};
    printVecElement(arr1);
    vector<vector<int>> ans1 = monotonousStack_NoRepeat(arr1);
    print2DVecElement(ans1);

    vector<int> arr2 = generateRandomVec(-10, 10, 10);
    printVecElement(arr2);
    vector<vector<int>> ans2 = monotonousStack_HasRepeat(arr2);
    print2DVecElement(ans2);
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

// 要求：数组中没有重复值
// 单调栈：
// Time: O(n)
// Space: O(n)
vector<vector<int>> monotonousStack_NoRepeat(vector<int> arr1)
{
    // stack 中 存储位置索引：
    stack<int> stack;
    // ans 中 存储 arr1[i] 左侧与右侧 的 第一个较小元素的位置索引：
    vector<vector<int>> ans(arr1.size(), vector<int>(2, 0));
    for (int i = 0; i < arr1.size(); i++)
    {
        while (!stack.empty() && arr1[stack.top()] > arr1[i])
        {
            int tem = stack.top();
            stack.pop();
            int lessIndex = stack.empty() ? -1 : stack.top();
            ans[tem][0] = lessIndex;
            ans[tem][1] = i;
        }
        stack.push(i);
    }

    // 清空栈内元素：
    while (!stack.empty())
    {
        int tem = stack.top();
        stack.pop();
        int lessIndex = stack.empty() ? -1 : stack.top();
        ans[tem][0] = lessIndex;
        ans[tem][1] = arr1.size();
    }

    return ans;
}

// 要求：数组中可以有重复值
// 单调栈：
// Time: O(n)
// Space: O(n)
vector<vector<int>> monotonousStack_HasRepeat(vector<int> arr2)
{
    // stack 中 存储位置索引：
    stack<vector<int>> stack;
    // ans 中 存储 arr1[i] 左侧与右侧 的 第一个较小元素的位置索引：
    vector<vector<int>> ans(arr2.size(), vector<int>(2, 0));
    for (int i = 0; i < arr2.size(); i++)
    {
        while (!stack.empty() && arr2[stack.top()[0]] > arr2[i])
        {
            vector<int> tem = stack.top();
            stack.pop();
            int lessIndex = stack.empty() ? -1 : stack.top()[stack.top().size() - 1];
            for(int j = 0; j < tem.size(); j++){
                ans[tem[j]][0] = lessIndex;
                ans[tem[j]][1] = i;
            }
        }

        if (!stack.empty() && arr2[stack.top()[0]] == arr2[i])
        {
            stack.top().push_back(i);
        }
        else
        {
            vector<int> tem = {i};
            stack.push(tem);
        }
    }

    // 清空栈内元素：
    while (!stack.empty())
    {
        vector<int> tem = stack.top();
        stack.pop();
        int lessIndex = stack.empty() ? -1 : stack.top()[stack.top().size() - 1];
        for(int j = 0; j < tem.size(); j++){
            ans[tem[j]][0] = lessIndex;
            ans[tem[j]][1] = arr2.size();
        }
    }

    return ans;
}