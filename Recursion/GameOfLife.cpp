#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

//      LeetCode 289. 生命游戏

//      链接：https://leetcode.cn/problems/game-of-life/

//      根据 百度百科 ， 生命游戏 ，简称为 生命 ，
//      是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。
//      给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。
//      每个细胞都具有一个初始状态：1 即为 活细胞 （live），或 0 即为 死细胞（dead）。
//      每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：
//          如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
//          如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
//          如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
//          如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
//      下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。给你 m x n 网格面板 board 的当前状态，返回下一个状态。
//      示例 1：
//          输入：board = [[0,1,0],
//                         [0,0,1],
//                         [1,1,1],
//                         [0,0,0]]
//          输出：[[0,0,0],
//                 [1,0,1],
//                 [0,1,1],
//                 [0,1,0]]
//      示例 2：
//          输入：board = [[1,1],
//                        [1,0]]
//          输出：[[1,1],
//                [1,1]]
//      提示：
//          m == board.length
//          n == board[i].length
//          1 <= m, n <= 25
//          board[i][j] 为 0 或 1
//      进阶：
//          你可以使用原地算法解决本题吗？请注意，面板上所有格子需要同时被更新：
//          你不能先更新某些格子，然后使用它们的更新后的值再更新其他格子。
//          本题中，我们使用二维数组来表示面板。原则上，面板是无限的，
//          但当活细胞侵占了面板边界时会造成问题。你将如何解决这些问题？

int generateRandomNum(int low, int high);
void print2DVecElement(vector<vector<int>> vec);
vector<vector<int>> generateRandom2DVec(int low, int high, int row, int col);

int DigitLife(vector<vector<int>> &board, int i, int j);
int DFSGameOfLife(vector<vector<int>> &board, int i, int j);
void GameOfLife(vector<vector<int>> &board);

int main()
{
    int row = generateRandomNum(1, 10);
    int col = generateRandomNum(1, 10);
    vector<vector<int>> vec = generateRandom2DVec(0, 1, row, col);
    printf("数组元素原来为：\n");
    print2DVecElement(vec);
    GameOfLife(vec);
    printf("生命游戏后：\n");
    print2DVecElement(vec);
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

void GameOfLife(vector<vector<int>> &board)
{
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int cnt = DigitLife(board, i, j);
            if(cnt == 3 || (cnt == 2 && board[i][j] == 1)){
                board[i][j] |= 2;
            }
        }
    }

    for(int i = 0 ; i < m ; i++){
        for(int j = 0; j < n ; j++){
            board[i][j] >>= 1;
        }
    }
}

int DigitLife(vector<vector<int>> &board, int i, int j)
{
    return DFSGameOfLife(board, i - 1, j - 1) + DFSGameOfLife(board, i - 1, j) + DFSGameOfLife(board, i - 1, j + 1) + DFSGameOfLife(board, i, j - 1) + DFSGameOfLife(board, i, j + 1) + DFSGameOfLife(board, i + 1, j - 1) + DFSGameOfLife(board, i + 1, j) + DFSGameOfLife(board, i + 1, j + 1);
}

int DFSGameOfLife(vector<vector<int>> &board, int i, int j)
{
    int m = board.size();
    int n = board.size();
    if (i >= 0 && i < m && j >= 0 && j < n && board[i][j] == 1)
    {
        return 1;
    }
    return 0;
}