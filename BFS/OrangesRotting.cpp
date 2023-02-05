#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//      LeetCode994. 腐烂的橘子

//      链接：https://leetcode.cn/problems/rotting-oranges/

//      在给定的 m x n 网格 grid 中，每个单元格可以有以下三个值之一：
//          值 0 代表空单元格；
//          值 1 代表新鲜橘子；
//          值 2 代表腐烂的橘子。
//      每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。
//      返回 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。
//      示例 1：
//          输入：grid = [[2,1,1],[1,1,0],[0,1,1]]
//          输出：4
//      示例 2：
//          输入：grid = [[2,1,1],[0,1,1],[1,0,1]]
//          输出：-1
//          解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个正向上。
//      示例 3：
//          输入：grid = [[0,2]]
//          输出：0
//          解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。
//      提示：
//          m == grid.length
//          n == grid[i].length
//          1 <= m, n <= 10
//          grid[i][j] 仅为 0、1 或 2

int generateRandomNum(int low, int high);
vector<vector<int>> generateRandom2DVec(int low, int high, int row, int col);
void print2DVecElement(vector<vector<int>> vec);

int OrangesRotting(vector<vector<int>> &grid);

int main()
{
    int row = generateRandomNum(1, 5);
    int col = generateRandomNum(1, 5);
    vector<vector<int>> grid = generateRandom2DVec(0, 2, row, col);
    print2DVecElement(grid);
    int ans = OrangesRotting(grid);
    printf("单元格中没有新鲜橘子为止所必须经过的最小分钟数为 %d。", ans);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
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

// BDS:
// Time: O(M * N)
// Space: O(M * N)
int OrangesRotting(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int fresh = 0;
    int rot = 0;
    int minutes = -1;
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                fresh++;
            }
            else if (grid[i][j] == 2)
            {
                q.push(make_pair(i, j));
                rot++;
            }
        }
    }
    if (fresh == 0)
    {
        return 0;
    }
    if (rot == 0)
    {
        return -1;
    }
    while (!q.empty())
    {
        int l = q.size();
        for (int i = 0; i < l; i++)
        {
            int x = q.front().first;
            int y = q.front().second;

            if (x + 1 < m)
            {
                if (grid[x + 1][y] == 1)
                {
                    grid[x + 1][y] = 2;
                    fresh--;
                    q.push(make_pair(x + 1, y));
                }
            }
            if (x - 1 >= 0)
            {
                if (grid[x - 1][y] == 1)
                {
                    grid[x - 1][y] = 2;
                    fresh--;
                    q.push(make_pair(x - 1, y));
                }
            }
            if (y + 1 < n)
            {
                if (grid[x][y + 1] == 1)
                {
                    grid[x][y + 1] = 2;
                    fresh--;
                    q.push(make_pair(x, y + 1));
                }
            }
            if (y - 1 >= 0)
            {
                if (grid[x][y - 1] == 1)
                {
                    grid[x][y - 1] = 2;
                    fresh--;
                    q.push(make_pair(x, y - 1));
                }
            }
            q.pop();
        }
        minutes++;
    }
    if (fresh == 0)
    {
        return minutes;
    }
    else
    {
        return -1;
    }
}