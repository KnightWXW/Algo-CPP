#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//      LeetCode 37. 解数独

//      链接：https://leetcode.cn/problems/sudoku-solver/

//      编写一个程序，通过填充空格来解决数独问题。
//      数独的解法需 遵循如下规则：
//          数字 1-9 在每一行只能出现一次。
//          数字 1-9 在每一列只能出现一次。
//          数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
//          数独部分空格内已填入了数字，空白格用 '.' 表示。
//      示例 1：
//          输入：board = [["5","3",".",".","7",".",".",".","."],
//                          ["6",".",".","1","9","5",".",".","."],
//                          [".","9","8",".",".",".",".","6","."],
//                          ["8",".",".",".","6",".",".",".","3"],
//                          ["4",".",".","8",".","3",".",".","1"],
//                          ["7",".",".",".","2",".",".",".","6"],
//                          [".","6",".",".",".",".","2","8","."],
//                          [".",".",".","4","1","9",".",".","5"],
//                          [".",".",".",".","8",".",".","7","9"]]
//          输出：[["5","3","4","6","7","8","9","1","2"],
//                  ["6","7","2","1","9","5","3","4","8"],
//                  ["1","9","8","3","4","2","5","6","7"],
//                  ["8","5","9","7","6","1","4","2","3"],
//                  ["4","2","6","8","5","3","7","9","1"],
//                  ["7","1","3","9","2","4","8","5","6"],
//                  ["9","6","1","5","3","7","2","8","4"],
//                  ["2","8","7","4","1","9","6","3","5"],
//                  ["3","4","5","2","8","6","1","7","9"]]
//          解释：输入的数独如上图所示，唯一有效的解决方案如下所示：
//      提示：
//          board.length == 9
//          board[i].length == 9
//          board[i][j] 是一位数字或者 '.'
//          题目数据 保证 输入数独仅有一个解

void print2DStringVecElement(vector<vector<string>> vec);

void SolveSudoku(vector<vector<string>> &board);
void InitSudoku(vector<vector<string>> &board, vector<vector<bool>> &rowFlag, vector<vector<bool>> &colFlag, vector<vector<bool>> &basketFlag);
bool DigitSudoku(vector<vector<string>> &board, int i, int j, vector<vector<bool>> &rowFlag, vector<vector<bool>> &colFlag, vector<vector<bool>> &basketFlag);

int main()
{
    vector<vector<string>> vec1 = {{"5", "3", ".", ".", "7", ".", ".", ".", "."},
                                   {"6", ".", ".", "1", "9", "5", ".", ".", "."},
                                   {".", "9", "8", ".", ".", ".", ".", "6", "."},
                                   {"8", ".", ".", ".", "6", ".", ".", ".", "3"},
                                   {"4", ".", ".", "8", ".", "3", ".", ".", "1"},
                                   {"7", ".", ".", ".", "2", ".", ".", ".", "6"},
                                   {".", "6", ".", ".", ".", ".", "2", "8", "."},
                                   {".", ".", ".", "4", "1", "9", ".", ".", "5"},
                                   {".", ".", ".", ".", "8", ".", ".", "7", "9"}};
    printf("本数独 为: \n");
    print2DStringVecElement(vec1);
    SolveSudoku(vec1);
    printf("本数独 解答后为: \n");
    print2DStringVecElement(vec1);
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

void SolveSudoku(vector<vector<string>> &board)
{
    const int NINE = board.size();
    const int THREE = 3;
    vector<vector<bool>> rowFlag(NINE, vector<bool>(NINE + 1, 0));
    vector<vector<bool>> colFlag(NINE, vector<bool>(NINE + 1, 0));
    vector<vector<bool>> basketFlag(NINE, vector<bool>(NINE + 1, 0));
    InitSudoku(board, rowFlag, colFlag, basketFlag);
    DigitSudoku(board, 0, 0, rowFlag, colFlag, basketFlag);
}

// 初始化 数独 相关数组:
void InitSudoku(vector<vector<string>> &board, vector<vector<bool>> &rowFlag, vector<vector<bool>> &colFlag, vector<vector<bool>> &basketFlag)
{
    const int NINE = board.size();
    const int THREE = 3;
    for (int i = 0; i < NINE; i++)
    {
        for (int j = 0; j < NINE; j++)
        {
            if (board[i][j] == ".")
            {
                continue;
            }
            int cur = atoi(board[i][j].c_str());
            int index = i / THREE * THREE + j / THREE;
            rowFlag[i][cur] = true;
            colFlag[j][cur] = true;
            basketFlag[index][cur] = true;
        }
    }
    return;
}

// 暴力 解数独：
bool DigitSudoku(vector<vector<string>> &board, int i, int j, vector<vector<bool>> &rowFlag, vector<vector<bool>> &colFlag, vector<vector<bool>> &basketFlag)
{
    const int NINE = board.size();
    const int THREE = 3;
    if (i == NINE)
    {
        return true;
    }
    int nextI = j == (NINE - 1) ? i + 1 : i;
    int nextJ = j == (NINE - 1) ? 0 : j + 1;
    int index = i / THREE * THREE + j / THREE;
    if (board[i][j] != ".")
    {
        return DigitSudoku(board, nextI, nextJ, rowFlag, colFlag, basketFlag);
    }
    for (int k = 1; k <= NINE; k++)
    {
        if (rowFlag[i][k] == true || colFlag[j][k] == true || basketFlag[index][k] == true)
        {
            continue;
        }
        rowFlag[i][k] = true;
        colFlag[j][k] = true;
        basketFlag[index][k] = true;
        board[i][j] = to_string(k);
        bool ans = DigitSudoku(board, nextI, nextJ, rowFlag, colFlag, basketFlag);
        if (ans == true)
        {
            return true;
        }
        rowFlag[i][k] = false;
        colFlag[j][k] = false;
        basketFlag[index][k] = false;
        board[i][j] = ".";
    }
    return false;
}