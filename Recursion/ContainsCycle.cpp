#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//      LeetCode 1559. 二维网格图中探测环

//      链接：https://leetcode.cn/problems/detect-cycles-in-2d-grid/

//      给你一个二维字符网格数组 grid ，大小为 m x n，
//      你需要检查 grid 中是否存在 相同值 形成的环。
//      一个环是一条开始和结束于同一个格子的长度 大于等于 4 的路径。
//      对于一个给定的格子，你可以移动到它上、下、左、右四个方向相邻的格子之一，
//      可以移动的前提是这两个格子有 相同的值 。
//      同时，你也不能回到上一次移动时所在的格子。
//      比方说，环  (1, 1) -> (1, 2) -> (1, 1) 是不合法的，
//      因为从 (1, 2) 移动到 (1, 1) 回到了上一次移动时的格子。
//      如果 grid 中有相同值形成的环，请你返回 true，否则返回 false 。
//      示例 1：
//          输入：grid = [["a","a","a","a"],
//                       ["a","b","b","a"],
//                       ["a","b","b","a"],
//                       ["a","a","a","a"]]
//          输出：true
//          解释：如下图所示，有 2 个用不同颜色标出来的环：
//      示例 2：
//          输入：grid = [["c","c","c","a"],
//                        ["c","d","c","c"],
//                        ["c","c","e","c"],
//                        ["f","c","c","c"]]
//          输出：true
//          解释：如下图所示，只有高亮所示的一个合法环：
//      示例 3：
//          输入：grid = [["a","b","b"],
//                        ["b","z","b"],
//                        ["b","b","a"]]
//          输出：false
//      提示：
//          m == grid.length
//          n == grid[i].length
//          1 <= m <= 500
//          1 <= n <= 500
//          grid 只包含小写英文字母。

void print2DStringVecElement(vector<vector<string>> vec);
void printBool(bool b);

bool ContainsCycle(vector<vector<string>> &grid);
void DfsContainsCycle(vector<vector<string>> &grid, bool &isHooped, int preI, int preJ, int i, int j, vector<vector<bool>> &flag);

int main()
{
    vector<vector<string>> vec1 = {{"a", "a", "a", "a"},
                                   {"a", "b", "b", "a"},
                                   {"a", "b", "b", "a"},
                                   {"a", "a", "a", "a"}};
    printf("本数组 为: \n");
    print2DStringVecElement(vec1);
    bool ans1 = ContainsCycle(vec1);
    printf("本数组中 是否 有相同值形成的环: \n");
    printBool(ans1);
    vector<vector<string>> vec2 = {{"c", "c", "c", "a"},
                                   {"c", "d", "c", "c"},
                                   {"c", "c", "e", "c"},
                                   {"f", "c", "c", "c"}};
    printf("本数组 为: \n");
    print2DStringVecElement(vec2);
    bool ans2 = ContainsCycle(vec2);
    printf("本数组中 是否 有相同值形成的环: \n");
    printBool(ans2);
    vector<vector<string>> vec3 = {{"a", "b", "b"},
                                   {"b", "z", "b"},
                                   {"b", "b", "a"}};
    printf("本数组 为: \n");
    print2DStringVecElement(vec3);
    bool ans3 = ContainsCycle(vec3);
    printf("本数组中 是否 有相同值形成的环: \n");
    printBool(ans3);
}

void print2DStringVecElement(vector<vector<string>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[0].size(); j++)
        {
            printf("%s\t", vec[i][j].c_str());
        }
        printf("\n");
    }
    printf("\n");
}

void printBool(bool b)
{
    if (b == true)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
}

bool ContainsCycle(vector<vector<string>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    bool isHooped = false;
    if (m == 0 || n == 0)
    {
        return false;
    }
    vector<vector<bool>> flag(m, vector<bool>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!flag[i][j])
            {
                DfsContainsCycle(grid, isHooped, -1, -1, i, j, flag);
                if(isHooped){
                    return true;
                }
            }
        }
    }
    return false;
}

void DfsContainsCycle(vector<vector<string>> &grid, bool &isHooped, int preI, int preJ, int i, int j, vector<vector<bool>> &flag)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<int> dirI = {1, -1, 0, 0};
    vector<int> dirJ = {0, 0, 1, -1};
    flag[i][j] = true;
    for (int k = 0; k < 4; k++)
    {
        int nextI = i + dirI[k];
        int nextJ = j + dirJ[k];
        if(nextI == preI && nextJ == preJ){
            continue;
        }
        if (nextI >= 0 && nextJ >= 0 && nextI < m && nextJ < n && grid[i][j] == grid[nextI][nextJ])
        {
            if (flag[nextI][nextJ])
            {
                isHooped = true;
                return;
            }
            DfsContainsCycle(grid, isHooped, i, j, nextI, nextJ, flag);
        }
    }
    return;
}