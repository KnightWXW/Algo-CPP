#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

//      剑指 Offer 29. 顺时针打印矩阵

//      链接：https://leetcode.cn/problems/rotate-image

//      输入一个矩阵，按照 从外向里 以顺时针 的顺序 依次打印出每一个数字。
//      示例 1：
//          输入：matrix = [[1,2,3],
//                          [4,5,6],
//                          [7,8,9]]
//          输出：[1,2,3,6,9,8,7,4,5]
//      示例 2：
//          输入：matrix = [[1,2,3,4],
//                          [5,6,7,8],
//                          [9,10,11,12]]
//          输出：[1,2,3,4,8,12,11,10,9,5,6,7]
//      限制：
//          0 <= matrix.length <= 100
//          0 <= matrix[i].length <= 100

void print2DVecElement(vector<vector<int>> vec);
vector<vector<int>> generateRandom2DVec(int low, int high, int row, int col);
void spiralOrderPrint(vector<vector<int>> vec);
void spiralPrint(vector<vector<int>> vec, int x1, int y1, int x2, int y2);

int main()
{
    vector<vector<int>> vec = generateRandom2DVec(0, 9, 4, 6);
    print2DVecElement(vec);
    spiralOrderPrint(vec);
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

// 按圈 打印：
// Time: O(m * n)
// Space: O(1)
void spiralOrderPrint(vector<vector<int>> vec)
{
    printf("顺时针打印矩阵的结果为：\n");
    int row1 = 0, col1 = 0;
    int row2 = vec.size() - 1, col2 = vec[0].size() - 1;
    while (row1 <= row2 && col1 <= col2)
    {
        spiralPrint(vec, row1++, col1++, row2--, col2--);
    }
}

void spiralPrint(vector<vector<int>> vec, int row1, int col1, int row2, int col2)
{
    // 情况1：只剩下一行元素：
    if (row1 == row2)
    {
        for (int j = col1; j <= col2; j++)
        {
            printf("%d  ", vec[row1][j]);
        }
    }
    // 情况2：只剩下一列元素：
    else if (col1 == col2)
    {
        for (int i = row1; i <= row2; i++)
        {
            printf("%d  ", vec[i][col1]);
        }
    }
    // 情况3：剩下多行多列元素：
    else
    {
        int curRow = row1, curCol = col1;
        while (curCol != col2)
        {
            printf("%d  ", vec[row1][curCol++]);
        }
        while (curRow != row2)
        {
            printf("%d  ", vec[curRow++][col2]);
        }
        while (curCol != col1)
        {
            printf("%d  ", vec[row2][curCol--]);
        }
        while (curRow != row1)
        {
            printf("%d  ", vec[curRow--][col1]);
        }
    }
}