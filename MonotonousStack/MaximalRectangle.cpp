#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stack>

using namespace std;

//      LeetCode 85. 最大矩形
//      链接：https://leetcode.cn/problems/maximal-rectangle/
//      给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，
//      找出只包含 1 的最大矩形，并返回其面积。

//      示例 1：
//      输入：matrix = [["1","0","1","0","0"],
//                      ["1","0","1","1","1"],
//                      ["1","1","1","1","1"],
//                      ["1","0","0","1","0"]]
//      输出：6

//      示例 2：
//      输入：matrix = []
//      输出：0

//      示例 3：
//      输入：matrix = [["0"]]
//      输出：0

//      示例 4：
//      输入：matrix = [["1"]]
//      输出：1

//      示例 5：
//      输入：matrix = [["0","0"]]
//      输出：0

//      提示：
//          rows == matrix.length
//          cols == matrix[0].length
//          1 <= row, cols <= 200
//          matrix[i][j] 为 '0' 或 '1'

void print2DVecElement(vector<vector<int>> vec);
vector<vector<int>> generateRandom2DVec(int low, int high, int row, int col);
int maximalRectangle_A(vector<vector<int>> vec);
int largestRectangleArea_A(vector<int> heights);
int largestRectangleArea_B(vector<int> heights);

int main()
{
    vector<vector<int>> vec = generateRandom2DVec(0, 1, 5, 6);
    print2DVecElement(vec);
    int area_A = maximalRectangle_A(vec);
    printf("最大矩形的面积为 %d\n", area_A);
    //printf("(单调栈-无重复值)最大矩形的面积为 %d\n", area_B);
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
        for( int j = 0 ; j < col ; j++){
            int v = (rand() % (high - low + 1)) + low;
            tem.push_back(v);
        }
        vec.push_back(tem);
    }
    return vec;
}

// 转换成 直方图中的 最大矩形 问题：
// 分别以 vec数组 第 i 行的元素 作为压缩数组 最底层的一行元素
// 如果 vec[i][j] == 0： heights[j] == 0
// 如果 vec[i][j] != 0： heights[j] ++

// 单调栈 + 数组压缩：
// Time: O(m * n)
// Space: O(n)
int maximalRectangle_A(vector<vector<int>> vec){
    int row = vec.size(), col = vec[0].size();
    vector<int> heights (col, 0);
    int area = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if (vec[i][j] == 0){
                heights[j] = 0;
            }else{
                heights[j]++;
            }
        }
        area = max(area, largestRectangleArea_B(heights));
        // area = max(area, largestRectangleArea_A(heights));
    }
    return area;
}

// 单调栈(含重复值)：
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

