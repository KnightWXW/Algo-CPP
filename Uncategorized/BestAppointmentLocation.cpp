#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//      LeetCode 296 最佳的碰头地点

//      链接：https://leetcode.cn/problems/best-meeting-point

//      给你一个 m x n 的二进制网格 grid ，
//      其中 1 表示某个朋友的家所处的位置。返回 最小的 总行走距离 。
//      总行走距离 是朋友们家到碰头地点的距离之和。
//      我们将使用 曼哈顿距离 来计算，
//      其中 distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y| 。
//      示例 1：
//          输入: grid = [[1,0,0,0,1],[0,0,0,0,0],[0,0,1,0,0]]
//          输出: 6
//          解释: 给定的三个人分别住在(0,0)，(0,4) 和 (2,2):
//          (0,2) 是一个最佳的碰面点，其总行走距离为 2 + 2 + 2 = 6，
//          最小，因此返回 6。
//      示例 2:
//          输入: grid = [[1,1]]
//          输出: 1
//      提示:
//          m == grid.length
//          n == grid[i].length
//          1 <= m, n <= 200
//          grid[i][j] == 0 or 1.
//          grid 中 至少 有两个朋友

void print2DVecElement(vector<vector<int>> vec);
vector<vector<int>> generateRandom2DVec(int low, int high, int row, int col);
vector<vector<int>> snakePrint(vector<vector<int>> vec);

int BestAppointmentLocation(vector<vector<int>>& grid);

int main()
{
    vector<vector<int>> vec = generateRandom2DVec(0, 20, 3, 3);
    printf("原数组为：\n");
    print2DVecElement(vec);
    vector<vector<int>> ans = snakePrint(vec);
    printf("蛇形打印数组为：\n");
    print2DVecElement(ans);
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