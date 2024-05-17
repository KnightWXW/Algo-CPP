#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//      LeetCode 36. 有效的数独

//      链接：https://leetcode.cn/problems/valid-sudoku/

//      请你判断一个 9 x 9 的数独是否有效。
//      只需要 根据以下规则 ，验证已经填入的数字是否有效即可。
//          数字 1-9 在每一行只能出现一次。
//          数字 1-9 在每一列只能出现一次。
//          数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
//      注意：
//          一个有效的数独（部分已被填充）不一定是可解的。
//          只需要根据以上规则，验证已经填入的数字是否有效即可。
//          空白格用 '.' 表示。
//      示例 1：
//          输入：board =
//              [["5","3",".",".","7",".",".",".","."]
//              ,["6",".",".","1","9","5",".",".","."]
//              ,[".","9","8",".",".",".",".","6","."]
//              ,["8",".",".",".","6",".",".",".","3"]
//              ,["4",".",".","8",".","3",".",".","1"]
//              ,["7",".",".",".","2",".",".",".","6"]
//              ,[".","6",".",".",".",".","2","8","."]
//              ,[".",".",".","4","1","9",".",".","5"]
//              ,[".",".",".",".","8",".",".","7","9"]]
//          输出：true
//      示例 2：
//          输入：board =
//              [["8","3",".",".","7",".",".",".","."]
//              ,["6",".",".","1","9","5",".",".","."]
//              ,[".","9","8",".",".",".",".","6","."]
//              ,["8",".",".",".","6",".",".",".","3"]
//              ,["4",".",".","8",".","3",".",".","1"]
//              ,["7",".",".",".","2",".",".",".","6"]
//              ,[".","6",".",".",".",".","2","8","."]
//              ,[".",".",".","4","1","9",".",".","5"]
//              ,[".",".",".",".","8",".",".","7","9"]]
//          输出：false
//          解释：除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1相同。
//               但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。
//      提示：
//          board.length == 9
//          board[i].length == 9
//          board[i][j] 是一位数字（1-9）或者 '.'

void print2DStringVecElement(vector<vector<string>> vec);
void printBool(bool b);

bool IsValidSudoku(vector<vector<string>> &board);

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
    bool ans1 = IsValidSudoku(vec1);
    printf("判断一个 本数独 是否有效: \n");
    print2DStringVecElement(vec1);
    printBool(ans1);
    vector<vector<string>> vec2 = {{"8", "3", ".", ".", "7", ".", ".", ".", "."},
                                   {"6", ".", ".", "1", "9", "5", ".", ".", "."},
                                   {".", "9", "8", ".", ".", ".", ".", "6", "."},
                                   {"8", ".", ".", ".", "6", ".", ".", ".", "3"},
                                   {"4", ".", ".", "8", ".", "3", ".", ".", "1"},
                                   {"7", ".", ".", ".", "2", ".", ".", ".", "6"},
                                   {".", "6", ".", ".", ".", ".", "2", "8", "."},
                                   {".", ".", ".", "4", "1", "9", ".", ".", "5"},
                                   {".", ".", ".", ".", "8", ".", ".", "7", "9"}};
    bool ans2 = IsValidSudoku(vec2);
    printf("判断一个 本数独 是否有效: \n");
    print2DStringVecElement(vec2);
    printBool(ans2);
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

bool IsValidSudoku(vector<vector<string>> &board)
{
    const int NINE = board.size();
    const int THREE = 3;
    vector<vector<bool>> rowFlag(NINE, vector<bool>(NINE + 1, 0));
    vector<vector<bool>> colFlag(NINE, vector<bool>(NINE + 1, 0));
    vector<vector<bool>> basketFlag(NINE, vector<bool>(NINE + 1, 0));
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
            if (rowFlag[i][cur] == true || colFlag[j][cur] == true || basketFlag[index][cur] == true)
            {
                return false;
            }
            rowFlag[i][cur] = true;
            colFlag[j][cur] = true;
            basketFlag[index][cur] = true;
        }
    }
    return true;
}