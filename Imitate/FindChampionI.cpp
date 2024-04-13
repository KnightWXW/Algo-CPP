#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

//      LeetCode 2923. 找到冠军 I

//      链接：https://leetcode.cn/problems/find-champion-i/

//      一场比赛中共有 n 支队伍，按从 0 到  n - 1 编号。
//      给你一个下标从 0 开始、大小为 n * n 的二维布尔矩阵 grid 。
//      对于满足 0 <= i, j <= n - 1 且 i != j 的所有 i, j ：
//      如果 grid[i][j] == 1，那么 i 队比 j 队 强 ；否则，j 队比 i 队 强 。
//      在这场比赛中，如果不存在某支强于 a 队的队伍，则认为 a 队将会是 冠军 。
//      返回这场比赛中将会成为冠军的队伍。
//      示例 1：
//          输入：grid = [[0,1],[0,0]]
//          输出：0
//          解释：比赛中有两支队伍。
//              grid[0][1] == 1 表示 0 队比 1 队强。所以 0 队是冠军。
//      示例 2：
//          输入：grid = [[0,0,1],[1,0,1],[0,0,0]]
//          输出：1
//          解释：比赛中有三支队伍。
//              grid[1][0] == 1 表示 1 队比 0 队强。
//              grid[1][2] == 1 表示 1 队比 2 队强。
//              所以 1 队是冠军。
//      提示：
//          n == grid.length
//          n == grid[i].length
//          2 <= n <= 100
//          grid[i][j] 的值为 0 或 1
//          对于所有 i， grid[i][i] 等于 0.
//          对于满足 i != j 的所有 i, j ，grid[i][j] != grid[j][i] 均成立
//          生成的输入满足：如果 a 队比 b 队强，b 队比 c 队强，那么 a 队比 c 队强

void print2DVecElement(vector<vector<int>> vec);

int FindChampionI_A(vector<vector<int>> &grid);
int FindChampionI_B(vector<vector<int>> &grid);

int main()
{
    vector<vector<int>> grid_A = {{0, 1}, {0, 0}};
    print2DVecElement(grid_A);
    int ans_A1 = FindChampionI_A(grid_A);
    int ans_A2 = FindChampionI_B(grid_A);
    printf("成为冠军的队伍 为 %d 。\n", ans_A1);
    printf("成为冠军的队伍 为 %d 。\n", ans_A2);
    vector<vector<int>> grid_B = {{0, 0, 1}, {1, 0, 1}, {0, 0, 0}};
    print2DVecElement(grid_B);
    int ans_B1 = FindChampionI_A(grid_B);
    int ans_B2 = FindChampionI_B(grid_B);
    printf("成为冠军的队伍 为 %d 。\n", ans_B2);
    printf("成为冠军的队伍 为 %d 。\n", ans_B2);
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

// Time: O(N2)
// Space: O(1)
int FindChampionI_A(vector<vector<int>> &grid)
{
    int l = grid.size();
    bool flag = false;
    for (int j = 0; j < l; j++)
    {
        flag = false;
        for (int i = 0; i < l; i++)
        {
            if (grid[i][j] == 1)
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            return j;
        }
    }
    return -1;
}

// Time: O(N)
// Space: O(1)
int FindChampionI_B(vector<vector<int>> &grid)
{
    int l = grid.size();
    int champ = 0;
    for(int i = 1; i < l; i++)
    {
        if(grid[i][champ] == 1){
            champ = i;
        }
    }
    return champ;
}