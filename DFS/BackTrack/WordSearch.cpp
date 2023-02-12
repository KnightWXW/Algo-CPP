#include <ctime>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <algorithm>

using namespace std;

//      LeetCode 79. 单词搜索

//      链接1 ：https://leetcode.cn/problems/word-search/
//      链接2 ：https://leetcode.cn/problems/ju-zhen-zhong-de-lu-jing-lcof/

//      给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。
//      如果 word 存在于网格中，返回 true ；否则，返回 false 。
//      单词必须按照字母顺序，通过相邻的单元格内的字母构成，
//      其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
//      同一个单元格内的字母不允许被重复使用。
//      示例 1：
//          输入：board = [["A","B","C","E"],
//                          ["S","F","C","S"],
//                          ["A","D","E","E"]],
//               word = "ABCCED"
//          输出：true
//      示例 2：
//          输入：board = [["A","B","C","E"],
//                         ["S","F","C","S"],
//                         ["A","D","E","E"]],
//               word = "SEE"
//          输出：true
//      示例 3：
//          输入：board = [["A","B","C","E"],
//                         ["S","F","C","S"],
//                         ["A","D","E","E"]],
//               word = "ABCB"
//          输出：false
//      提示：
//          m == board.length
//          n = board[i].length
//          1 <= m, n <= 6
//          1 <= word.length <= 15
//          board 和 word 仅由大小写英文字母组成

void printString(string s);
void print2DStringVecElement(vector<vector<string>> vec);
void printBool(bool b);

bool WordSearch(vector<vector<string>> &board, string word);
bool DFSWordSearch(vector<vector<string>> &board, string word, int i, int j, int index);

int main()
{
    vector<vector<string>> board = {{"A", "B", "C", "E"},
                                      {"S", "F", "C", "S"},
                                      {"A", "D", "E", "E"}};
                                      print2DStringVecElement(board);
    string word_A = "ABCCED";
    printString(word_A);
    bool ans_A = WordSearch(board, word_A);
    printf("word 是否存在于网格中： ");
    printBool(ans_A);

    string word_B = "SEE";
    printString(word_B);
    bool ans_B = WordSearch(board, word_B);
    printf("word 是否存在于网格中： ");
    printBool(ans_B);

    string word_C = "ABCB";
    printString(word_C);
    bool ans_C = WordSearch(board, word_C);
    printf("word 是否存在于网格中： ");
    printBool(ans_C);
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

void printString(string s)
{
    printf("%s\n", s.c_str());
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

bool WordSearch(vector<vector<string>> &board, string word)
{
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (DFSWordSearch(board, word, i, j, 0))
            {
                return true;
            }
        }
    }
    return false;
}

bool DFSWordSearch(vector<vector<string>> &board, string word, int i, int j, int index)
{
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
    {
        return false;
    }
    if (board[i][j][0] != word[index])
    {
        return false;
    }
    if (index == word.size() - 1)
    {
        return true;
    }
    string cur = board[i][j];
    board[i][j] = "&";
    bool flag1 = DFSWordSearch(board, word, i - 1, j, index + 1);
    bool flag2 = DFSWordSearch(board, word, i + 1, j, index + 1);
    bool flag3 = DFSWordSearch(board, word, i, j - 1, index + 1);
    bool flag4 = DFSWordSearch(board, word, i, j + 1, index + 1);
    board[i][j] = cur;
    return flag1 || flag2 || flag3 || flag4;
}