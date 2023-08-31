#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

//      Huawei: 绘图系统

//      实现一个绘图系统DrawingSystem，初始化图纸为 n * n 的一张画布：
//          void Change(int paintType): 有三个绘图方式：
//              普通(0), 中心对称(1), 对称(2)
//              普通(0): 画正常直线
//              中心对称(1): 根据中心对称同时绘画两条直线
//              对称(2): 根据垂直中心轴同时画出两条线
//              题目保证画的都是直线，且都在范围内：
//          void Paint(int row1, int col1, int row2, int col2, int color):
//              画的时候回标记颜色，如 1,2,3....
//              同一个地方当前的颜色会覆盖之前的颜色
//          void Revert(): 实现撤销功能，
//              撤销为撤销上一次Paint操作，且可能存在多次Paint
//          int Count(int color): 统计当前图案中对应color的数量

class DrawingSystem
{
public:
    int mode;
    int id;
    int number;
    vector<vector<int>> board;
    map<int, vector<vector<int>>> drawList;

    DrawingSystem(int num)
    {
        mode = 0;
        id = 0;
        number = num;
        board = vector<vector<int>>(number, vector<int>(number, 0));
    }

    void Change(int paintType)
    {
        mode = paintType;
    }

    void PaintLine(int row1, int col1, int row2, int col2, int color)
    {
        int minRow = min(row1, row2);
        int maxRow = max(row1, row2);
        int minCol = min(col1, col2);
        int maxCol = max(col1, col2);
        for (int i = minRow; i <= maxRow; i++)
        {
            for (int j = minCol; j <= maxCol; j++)
            {
                board[i][j] = color;
            }
        }
        return;
    }

    void Paint(int row1, int col1, int row2, int col2, int color)
    {
        if (mode == 0)
        {
            PaintLine(row1, col1, row2, col2, color);
        }
        else if (mode == 1)
        {
            PaintLine(row1, col1, row2, col2, color);
            PaintLine(row1, number - 1 - col1, row2, number - 1 - col2, color);
        }
        else if (mode == 2)
        {
            PaintLine(row1, col1, row2, col2, color);
            PaintLine(number - 1 - row1, number - 1 - col1, number - 1 - row2, number - 1 - col2, color);
        }
        drawList[id] = board;
        id++;
    }

    void Revert()
    {
        board = vector<vector<int>>(drawList[id - 2]);
        drawList.erase(id - 1);
        id--;
    }

    int Count(int color)
    {
        int cnt = 0;
        if (drawList.size() == 0)
        {
            return cnt;
        }
        for (int i = 0; i < number; i++)
        {
            for (int j = 0; j < number; j++)
            {
                cnt += (board[i][j] == color ? 1 : 0);
            }
        }
        return cnt;
    }
};

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

int main()
{
    DrawingSystem *drawingSystem = new DrawingSystem(4);
    drawingSystem->Paint(0, 1, 2, 1, 2);
    print2DVecElement(drawingSystem->board);
    drawingSystem->Change(2);
    drawingSystem->Paint(1, 2, 1, 3, 3);
    print2DVecElement(drawingSystem->board);
    int c1 = drawingSystem->Count(2); // 2
    printf("当前图案中对应color的数量为 %d \n", c1);
    drawingSystem->Revert();
    print2DVecElement(drawingSystem->board);
    int c2 = drawingSystem->Count(2); // 3
    print2DVecElement(drawingSystem->board);
    printf("当前图案中对应color的数量为 %d \n", c2);
}