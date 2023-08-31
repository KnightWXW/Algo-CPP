#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//      LeetCode 1020. 飞地的数量

//      链接：https://leetcode.cn/problems/number-of-enclaves/

//      给你一个大小为 m x n 的二进制矩阵 grid ，
//      其中 0 表示一个海洋单元格、1 表示一个陆地单元格。
//      一次 移动 是指从一个陆地单元格走到另一个相邻（上、下、左、右）
//      的陆地单元格或跨过 grid 的边界。
//      返回网格中 无法 在任意次数的移动中离开网格边界的陆地单元格的数量。
//      示例 1：
//          输入：grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
//          输出：3
//          解释：有三个 1 被 0 包围。一个 1 没有被包围，因为它在边界上。
//      示例 2：
//          输入：grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
//          输出：0
//          解释：所有 1 都在边界上或可以到达边界。
//      提示：
//          m == grid.length
//          n == grid[i].length
//          1 <= m, n <= 500
//          grid[i][j] 的值为 0 或 1

void print2DVecElement(vector<vector<int>> vec);
vector<vector<int>> generateRandom2DVec(int low, int high, int row, int col);

int NumEnclaves(vector<vector<int>> &grid);

int main()
{
    int m = generateRandomNum(1, 10);
    int n = generateRandomNum(1, 9);
    vector<vector<int>> vec = generateRandom2DVec(0, 1, m, n);
    printf("原数组为：\n");
    print2DVecElement(vec);
    int ans = NumEnclaves(vec);
    printf("网格中 无法 在任意次数的移动中离开网格边界的陆地单元格的数量为：%d\n", ans);
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
        for (int j = 0; j < vec[i].size(); j++)
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

int NumEnclaves(vector<vector<int>> &grid)
{

}