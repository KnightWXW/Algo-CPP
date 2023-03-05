#include <ctime>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <algorithm>

using namespace std;

//      LeetCode 130. 被围绕的区域

//      链接：https://leetcode.cn/problems/surrounded-regions/

//      给你一个 m x n 的矩阵 board，由若干字符 'X' 和 'O'，
//      找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
//      示例 1：
//          输入：board = [["X","X","X","X"],
//                          ["X","O","O","X"],
//                          ["X","X","O","X"],
//                          ["X","O","X","X"]]
//          输出：[["X","X","X","X"],
//                  ["X","X","X","X"],
//                  ["X","X","X","X"],
//                  ["X","O","X","X"]]
//          解释：被围绕的区间不会存在于边界上，
//              换句话说，任何边界上的 'O' 都不会被填充为 'X'。 
//              任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。
//              如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
//      示例 2：
//          输入：board = [["X"]]
//          输出：[["X"]]
//      提示：
//          m == board.length
//          n == board[i].length
//          1 <= m, n <= 200
//          board[i][j] 为 'X' 或 'O'

int generateRandomNum(int low, int high);
void print2DVecElement(vector<vector<int>> vec);
vector<vector<int>> generateRandom2DVec(int low, int high, int row, int col);

vector<vector<int>> SurroundedRegions_A(vector<vector<int>>& board);

int main()
{
    int row = generateRandomNum(1, 10);
    int col = generateRandomNum(1, 10);
    vector<vector<int>> vec = generateRandom2DVec(0, 1, row, col);
    printf("数组元素为：\n");
    print2DVecElement(vec);
    vector<vector<int>> ans = SurroundedRegions_A(vec);
    printf("清除被围绕的区域后, 数组为：\n");
    print2DVecElement(ans);
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

vector<vector<int>> SurroundedRegions_A(vector<vector<int>>& board)
{
    vector<vector<int>> arr(board);
    int m = arrd.size();
    int n = board[0].size();
    
}

