#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stack>

using namespace std;

//      LeetCode 84. 柱状图中最大的矩形

//      链接：https://leetcode.cn/problems/largest-rectangle-in-histogram/

//      给定 n 个非负整数，用来表示柱状图中各个柱子的高度。
//      每个柱子彼此相邻，且宽度为 1 。
//      求在该柱状图中，能够勾勒出来的矩形的最大面积。

//      示例 1:
//      输入：heights = [2,1,5,6,2,3]
//      输出：10
//      解释：最大的矩形为图中红色区域，面积为 10

//      示例 2：
//      输入： heights = [2,4]
//      输出： 4

//      提示：
//          1 <= heights.length <=105
//          0 <= heights[i] <= 104

void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);
int largestRectangleArea_A(vector<int> heights);
int largestRectangleArea_B(vector<int> heights);

int main()
{
    vector<int> vec = generateRandomVec(1, 10, 3);
    printVecElement(vec);
    int area_A = largestRectangleArea_A(vec);
    int area_B = largestRectangleArea_B(vec);
    printf("(单调栈-重复值)柱状图中矩形的最大面积为%d\n", area_A);
    printf("(单调栈-无重复值)柱状图中矩形的最大面积为%d\n", area_B);
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

// 单调栈(含重复值) ：
// Time: O(n)
// Space: O(n)
int largestRectangleArea_A(vector<int> heights)
{
    if (heights.size() <= 0)
    {
        return 0;
    }
    stack<vector<int>> stack;
    int area = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        while (!stack.empty() && heights[stack.top()[0]] > heights[i])
        {
            vector<int> tem = stack.top();
            stack.pop();
            int lessIndex = stack.empty() ? -1 : stack.top()[stack.top().size() - 1];
            int leftIndex = lessIndex;
            int rightIndex = i;
            area = max(area, (rightIndex - leftIndex - 1) * heights[tem[tem.size() - 1]]);
        }

        if (!stack.empty() && heights[stack.top()[0]] == heights[i])
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
        int leftIndex = lessIndex;
        int rightIndex = heights.size();
        area = max(area, (rightIndex - leftIndex - 1) * heights[tem[tem.size() - 1]]);
    }
    return area;
}

// 单调栈(不含重复值)：
// Time: O(n)
// Space: O(n)
int largestRectangleArea_B(vector<int> heights)
{
    if (heights.size() <= 0)
    {
        return 0;
    }
    stack<int> stack;
    int area = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        while (!stack.empty() && heights[stack.top()] >= heights[i])
        {
            int tem = stack.top();
            stack.pop();
            int lessIndex = stack.empty() ? -1 : stack.top();
            int leftIndex = lessIndex;
            int rightIndex = i;
            area = max(area, (rightIndex - leftIndex - 1) * heights[tem]);
        }
        stack.push(i);
    }

    while (!stack.empty())
    {
        int tem = stack.top();
        stack.pop();
        int lessIndex = stack.empty() ? -1 : stack.top();
        int leftIndex = lessIndex;
        int rightIndex = heights.size();
        area = max(area, (rightIndex - leftIndex - 1) * heights[tem]);
    }
    return area;
}