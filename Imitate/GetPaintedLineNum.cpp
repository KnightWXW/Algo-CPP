#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

//      Huawei: 贴瓷砖

//      美工想用瓷砖在墙上贴出一幅画，把墙面划分为若干大小相同的正方形小格，
//      可视墙面为 rows * cols 的二维矩阵，左上角格子位置为 [0, 0]
//      假定二维矩阵中的行与地面平行，列与地面垂直。
//      二维数组positions中的每个元素表示美工已经贴好的瓷砖所在位置，
//      现给出一组线段，记为二维数组lines中，线段仅与地面平行，垂直，或与地面呈45/135度角，
//      lines[i]的格式为[起点行下标，起点列下标，终点行下标，终点列下标]。
//      请判断lines中有多少条线段被已贴好瓷砖的格子完全覆盖，返回数量。
//      输入：rows = 3 cols = 4
//          lines = {{1, 1, 2, 2}, {2, 1, 0, 3}}
//          positions = {{0, 1}, {1, 1}, {2, 2}}
//      输出：1
//      输入：rows = 7 cols = 6
//          lines = {{3, 5, 0, 2}, {0, 3, 2, 3}, {4, 2, 6, 4}, {3, 1, 6, 4}}
//          positions = {{0, 1}, {2, 4}, {1, 3}, {3, 3}, {4, 2}, {5, 5}, {5, 3}, {6, 4}}
//      输出：1

void print2DVecElement(vector<vector<int>> vec);

int PaintCovered(int startX, int endX, int startY, int endY, vector<vector<int>> &boards);
int GetPaintedLineNum(int rows, int cols, vector<vector<int>> lines, vector<vector<int>> positions);

int main()
{
    int rows1 = 3;
    int cols1 = 4;
    vector<vector<int>> lines1 = {{1, 1, 2, 2}, {2, 1, 0, 3}};
    vector<vector<int>> positions1 = {{0, 1}, {1, 1}, {2, 2}};
    int ans_A = GetPaintedLineNum(rows1, cols1, lines1, positions1);
    print2DVecElement(lines1);
    print2DVecElement(positions1);
    printf("rows为%d, cols为%d, 有 %d 条线段被已贴好瓷砖的格子完全覆盖。\n", rows1, cols1, ans_A);
    int rows2 = 7;
    int cols2 = 6;
    vector<vector<int>> lines2 = {{3, 5, 0, 2}, {0, 3, 2, 3}, {4, 2, 6, 4}, {3, 1, 6, 4}};
    vector<vector<int>> positions2 = {{0, 1}, {2, 4}, {1, 3}, {3, 3}, {4, 2}, {5, 5}, {5, 3}, {6, 4}};
    int ans_B = GetPaintedLineNum(rows2, cols2, lines2, positions2);
    print2DVecElement(lines2);
    print2DVecElement(positions2);
    printf("rows为%d, cols为%d, 有 %d 条线段被已贴好瓷砖的格子完全覆盖。\n", rows2, cols2, ans_B);
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

int PaintCovered(int startX, int endX, int startY, int endY, vector<vector<int>> &boards)
{
    for (int i = startX, j = startY; i <= endX && j <= endY; i++, j++)
    {
        if (boards[i][j] == 0)
        {
            return 0;
        }
    }
    return 1;
}

int GetPaintedLineNum(int rows, int cols, vector<vector<int>> lines, vector<vector<int>> positions)
{
    int ans = 0;
    vector<vector<int>> boards(rows, vector<int>(cols, 0));
    for (int i = 0; i < positions.size(); i++)
    {
        boards[positions[i][0]][positions[i][1]] = 1;
    }
    for (int i = 0; i < lines.size(); i++)
    {
        int startX = min(lines[i][0], lines[i][2]);
        int endX = max(lines[i][0], lines[i][2]);
        int startY = min(lines[i][1], lines[i][3]);
        int endY = max(lines[i][1], lines[i][3]);
        ans += PaintCovered(startX, endX, startY, endY, boards);
    }
    return ans;
}