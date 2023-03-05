#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//      LeetCode 118. 杨辉三角

//      链接：https://leetcode.cn/problems/pascals-triangle/

//      给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
//      在「杨辉三角」中，每个数是它左上方和右上方的数的和。
//      示例 1:
//          输入: numRows = 5
//          输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
//      示例 2:
//          输入: numRows = 1
//          输出: [[1]]
//      提示:
//          1 <= numRows <= 30

int generateRandomNum(int low, int high);
void print2DVecElement(vector<vector<int>> vec);

vector<vector<int>> PascalsTriangle(int numRows);

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