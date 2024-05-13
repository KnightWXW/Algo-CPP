#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stack>

using namespace std;

//      LeetCode 1504. 统计全 1 子矩形

//      链接：https://leetcode.cn/problems/count-submatrices-with-all-ones/

//      给你一个 m x n 的二进制矩阵 mat ，请你返回有多少个 子矩形 的元素全部都是 1 。

//      示例 1：
//          输入：mat = [[1,0,1],
//                      [1,1,0],
//                      [1,1,0]]
//          输出：13
//      解释：
//          有 6 个 1x1 的矩形。
//          有 2 个 1x2 的矩形。
//          有 3 个 2x1 的矩形。
//          有 1 个 2x2 的矩形。
//          有 1 个 3x1 的矩形。
//      矩形数目总共 = 6 + 2 + 3 + 1 + 1 = 13 。
//      示例 2：
//          输入：mat = [[0,1,1,0],
//                      [0,1,1,1],
//                      [1,1,1,0]]
//          输出：24
//      解释：
//          有 8 个 1x1 的子矩形。
//          有 5 个 1x2 的子矩形。
//          有 2 个 1x3 的子矩形。
//          有 4 个 2x1 的子矩形。
//          有 2 个 2x2 的子矩形。
//          有 2 个 3x1 的子矩形。
//          有 1 个 3x2 的子矩形。
//      矩形数目总共 = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24 。

//      提示：
//          1 <= m, n <= 150
//          mat[i][j] 仅包含 0 或 1

void print2DVecElement(vector<vector<int>> vec);
vector<vector<int>> generateRandom2DVec(int low, int high, int row, int col);
int numSubmat_A(vector<vector<int>> mat);
int numSubmat_B(vector<vector<int>> mat);
int numSubmat_C(vector<vector<int>> mat);
int countOnesOfRectangleArea_A(vector<int> heights);
int countOnesOfRectangleArea_B(vector<int> heights);
int countOnesOfRectangleArea_C(vector<int> heights);
int digitSum(int num);

int main()
{
    vector<vector<int>> vec = generateRandom2DVec(0, 1, 6, 4);
    print2DVecElement(vec);
    printf("矩阵中 子矩形 的元素全部都是 1 的个数为%d\n", numSubmat_A(vec));
    printf("矩阵中 子矩形 的元素全部都是 1 的个数为%d\n", numSubmat_B(vec));
    printf("矩阵中 子矩形 的元素全部都是 1 的个数为%d\n", numSubmat_C(vec));
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

vector<vector<int>> generateRandom2DVec(int low, int high, int row, int col)
{
    srand((int)time(0));
    vector<vector<int>> vec;
    for (int i = 0; i < row; i++)
    {
        vector<int> tem;
        for (int j = 0; j < col; j++)
        {
            int v = (rand() % (high - low + 1)) + low;
            tem.push_back(v);
        }
        vec.push_back(tem);
    }
    return vec;
}

// 单调栈 + 数组压缩：
// Time: O(m * n)
// Space: O(n)
int numSubmat_A(vector<vector<int>> mat)
{
    int row = mat.size(), col = mat[0].size();
    vector<int> heights(col, 0);
    int ones = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (mat[i][j] == 0)
            {
                heights[j] = 0;
            }
            else
            {
                heights[j] = heights[j] + 1;
            }
        }
        ones += countOnesOfRectangleArea_A(heights);
    }
    return ones;
}

// 单调栈 + 数组压缩：
// Time: O(m * n)
// Space: O(n)
int numSubmat_B(vector<vector<int>> mat)
{
    int row = mat.size(), col = mat[0].size();
    vector<int> heights(col, 0);
    int ones = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (mat[i][j] == 0)
            {
                heights[j] = 0;
            }
            else
            {
                heights[j] = heights[j] + 1;
            }
        }
        ones += countOnesOfRectangleArea_B(heights);
    }
    return ones;
}

// 手写 单调栈 + 数组压缩：
// Time: O(m * n)
// Space: O(n)
int numSubmat_C(vector<vector<int>> mat)
{
    int row = mat.size(), col = mat[0].size();
    vector<int> heights(col, 0);
    int ones = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (mat[i][j] == 0)
            {
                heights[j] = 0;
            }
            else
            {
                heights[j] = heights[j] + 1;
            }
        }
        ones += countOnesOfRectangleArea_C(heights);
    }
    return ones;
}

// 单调栈(含重复值)：
// Time: O(n)
// Space: O(n)
int countOnesOfRectangleArea_A(vector<int> heights)
{
    if (heights.size() <= 0)
    {
        return 0;
    }

    stack<vector<int>> stack;
    int ones = 0;

    for (int i = 0; i < heights.size(); i++)
    {
        while (!stack.empty() && heights[stack.top()[0]] > heights[i])
        {   
            vector<int> tem = stack.top();
            stack.pop();
            int lessIndex = stack.empty() ? -1 : stack.top()[stack.top().size() - 1];
            int leftIndex = lessIndex;
            int rightIndex = i;
            int num = rightIndex - leftIndex - 1;

            int largeVal = 0;
            if (leftIndex == -1){
                largeVal = max(0, heights[rightIndex]);
            }else{
                largeVal = max(heights[leftIndex], heights[rightIndex]);
            }
            ones += digitSum(num) * (heights[tem[tem.size() - 1]] - largeVal);
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
        int num = rightIndex - leftIndex - 1;

        int largeVal = 0;
        if (leftIndex != -1){
            largeVal = heights[leftIndex];
        }
        ones += digitSum(num) * (heights[tem[tem.size() - 1]] - largeVal);
    }
    return ones;
}

// 单调栈(不含重复值)：
// Time: O(n)
// Space: O(n)
int countOnesOfRectangleArea_B(vector<int> heights)
{
    if (heights.size() <= 0)
    {
        return 0;
    }

    int ones = 0;
    stack<int> stack;

    for (int i = 0; i < heights.size(); i++)
    {
        while (!stack.empty() && heights[stack.top()] >= heights[i])
        {
            int tem = stack.top();
            stack.pop();
            int lessIndex = stack.empty() ? -1 : stack.top();
            int leftIndex = lessIndex;
            int rightIndex = i;
            int num = rightIndex - leftIndex - 1;

            int largeVal = 0;
            if (leftIndex == -1){
                largeVal = max(0, heights[rightIndex]);
            }else{
                largeVal = max(heights[leftIndex], heights[rightIndex]);
            }
            ones += digitSum(num) * (heights[tem] - largeVal);
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
        int num = rightIndex - leftIndex - 1;

        int largeVal = 0;
        if (leftIndex != -1){
            largeVal = heights[leftIndex];
        }
        ones += digitSum(num) * (heights[tem] - largeVal);
    }
    return ones;
}


// 手写单调栈(不含重复值)：
// Time: O(n)
// Space: O(n)
int countOnesOfRectangleArea_C(vector<int> heights)
{
    if (heights.size() == 0)
    {
        return 0;
    }

    int ones = 0;
    vector<int> stack(heights.size(), 0);
    int index = -1;

    for (int i = 0; i < heights.size(); i++)
    {
        while (index != -1 && heights[stack[index]] >= heights[i])
        {
            int cur = stack[index--];
            if (heights[cur] > heights[i])
            {
                int left = index == -1 ? -1 : stack[index];
                int n = i - left - 1;
                int down = max(left == -1 ? 0 : heights[left], heights[i]);
                ones += (heights[cur] - down) * digitSum(n);
            }
        }
        stack[++index] = i;
    }
    while (index != -1)
    {
        int cur = stack[index--];
        int left = index == -1 ? -1 : stack[index];
        int n = heights.size() - left - 1;
        int down = left == -1 ? 0 : heights[left];
        ones += (heights[cur] - down) * digitSum(n);
    }
    return ones;
}

int digitSum(int num)
{
    return ((num + 1) * (num) >> 1);
}