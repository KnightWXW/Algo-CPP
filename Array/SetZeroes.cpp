#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

//      LeetCode 73. 矩阵置零

//      链接：https://leetcode.cn/problems/set-matrix-zeroes/

//      给定一个m x n的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0。
//      请使用 原地 算法。
//      示例 1：
//          输入：matrix = [[1,1,1],
//                          [1,0,1],
//                          [1,1,1]]
//          输出：[[1,0,1],
//                 [0,0,0],
//                 [1,0,1]]
//      示例 2：
//          输入：matrix = [[0,1,2,0],
//                          [3,4,5,2],
//                          [1,3,1,5]]
//          输出：[[0,0,0,0],
//                 [0,4,5,0],
//                 [1,0,3,1,0]]
//      提示：
//          m == matrix.length
//          n == matrix[0].length
//          1 <= m, n <= 200
//          -231 <= matrix[i][j] <= 231 - 1
//      进阶：
//          一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
//          一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
//          你能想出一个仅使用常量空间的解决方案吗？

int generateRandomNum(int low, int high);
void print2DVecElement(vector<vector<int>> vec);
vector<vector<int>> generateRandom2DVec(int low, int high, int row, int col);

vector<vector<int>> SetZeroes_A(vector<vector<int>> &matrix);
vector<vector<int>> SetZeroes_B(vector<vector<int>> &matrix);
vector<vector<int>> SetZeroes_C(vector<vector<int>> &matrix);

int main()
{
    int row = generateRandomNum(1, 10);
    int col = generateRandomNum(1, 10);
    vector<vector<int>> vec = generateRandom2DVec(0, 10, row, col);
    printf("数组元素为：\n");
    print2DVecElement(vec);
    vector<vector<int>> ans_A = SetZeroes_A(vec);
    vector<vector<int>> ans_B = SetZeroes_B(vec);
    vector<vector<int>> ans_C = SetZeroes_C(vec);
    printf("数组置零后为：\n");
    print2DVecElement(ans_A);
    print2DVecElement(ans_B);
    print2DVecElement(ans_C);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
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

vector<vector<int>> SetZeroes_A(vector<vector<int>> &matrix)
{
    vector<vector<int>> matrixVec(matrix);
    int row = matrixVec.size();
    int col = matrixVec[0].size();
    vector<int> vecRow(row, 1);
    vector<int> vecCol(col, 1);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrixVec[i][j] == 0)
            {
                vecRow[i] = 0;
                vecCol[j] = 0;
            }
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (vecRow[i] == 0 || vecCol[j] == 0)
            {
                matrixVec[i][j] = 0;
            }
        }
    }
    return matrixVec;
}

vector<vector<int>> SetZeroes_B(vector<vector<int>> &matrix)
{
    vector<vector<int>> matrixVec(matrix);
    int row = matrixVec.size();
    int col = matrixVec[0].size();
    bool flagRow = false;
    bool flagCol = false;
    for (int i = 0; i < col; i++)
    {
        if (matrixVec[0][i] == 0)
        {
            flagRow = true;
            break;
        }
    }
    for (int i = 0; i < row; i++)
    {
        if (matrixVec[i][0] == 0)
        {
            flagCol = true;
            break;
        }
    }
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (matrixVec[i][j] == 0)
            {
                matrixVec[0][j] = 0;
                matrixVec[i][0] = 0;
            }
        }
    }
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (matrixVec[0][j] == 0 || matrixVec[i][0] == 0)
            {
                matrixVec[i][j] = 0;
            }
        }
    }
    if (flagRow == true)
    {
        for (int i = 0; i < col; i++)
        {
            matrixVec[0][i] = 0;
        }
    }
    if (flagCol == true)
    {
        for (int i = 0; i < row; i++)
        {
            matrixVec[i][0] = 0;
        }
    }
    return matrixVec;
}

vector<vector<int>> SetZeroes_C(vector<vector<int>> &matrix)
{
    vector<vector<int>> matrixVec(matrix);
    int row = matrixVec.size();
    int col = matrixVec[0].size();
    bool flagRow = false;
    for (int i = 0; i < col; i++)
    {
        if (matrixVec[0][i] == 0)
        {
            flagRow = true;
            break;
        }
    }
    for (int i = 1; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrixVec[i][j] == 0)
            {
                matrixVec[0][j] = 0;
                matrixVec[i][0] = 0;
            }
        }
    }
    for (int i = 1; i < row; i++)
    {
        for (int j = col - 1; j >= 0 ; j--)
        {
            if (matrixVec[0][j] == 0 || matrixVec[i][0] == 0)
            {
                matrixVec[i][j] = 0;
            }
        }
    }
    if (flagRow == true)
    {
        for (int i = 0; i < col; i++)
        {
            matrixVec[0][i] = 0;
        }
    }
    return matrixVec;
}