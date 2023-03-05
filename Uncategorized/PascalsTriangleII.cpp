#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//      LeetCode 119. 杨辉三角 II

//      链接：https://leetcode.cn/problems/pascals-triangle-ii/
    
//      给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。
//      在「杨辉三角」中，每个数是它左上方和右上方的数的和。
//      示例 1:

//          输入: rowIndex = 3
//          输出: [1,3,3,1]
//      示例 2:
//          输入: rowIndex = 0
//          输出: [1]
//      示例 3:
//          输入: rowIndex = 1
//          输出: [1,1]
//      提示:
//          0 <= rowIndex <= 33
//      进阶：
//          你可以优化你的算法到 O(rowIndex) 空间复杂度吗？

int generateRandomNum(int low, int high);
void print2DVecElement(vector<vector<int>> vec);

vector<vector<int>> PascalsTriangleII(int numRows);

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