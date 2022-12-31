#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

//      题目描述:
//      在一个二维表格中，选择部分单元格后，对选中部分按不同列排序，没选中部分不变
//      详细说明：根据area的坐标，选中grid中的区域。
//      然后根据sortCols的数据对该区域按列升序排序。最后输入 grid。
//      给定一个二位数组，如：
//          [1, 2, 2, 3, 4]
//          [1, 2, 3, 7, 5]
//          [1, 1, 3, 5, 6]
//          [1, 4, 1, 6, 7]
//      随后给出两个点如： [2, 3, 4, 5]，
//      坐标分别为[2, 3] 和 [4, 5]，则这两个坐标限定的区域为：
//          [3, 7, 5]
//          [3, 5, 6]
//          [1, 6, 7]
//      最后给定需要进行排序的列，
//      如：[1, 2]，即需要按照选定区域的第一列和第二列进行排序，
//          先对第一列进行排序，按照从小到大的规则对行排序，
//          如果两者相等，则按照后面给出的列进行排序
//          （这里的排序顺序要严格按照给定列的顺序进行，
//          [1, 2]说明需要先排序第一列，再排序第二列）。
//      排序后的结果如下：
//          [1, 6, 7]
//          [3, 5, 6]
//          [3, 7, 5]
//      选定区域需要进行排序，未选定区域保持不变，因此最后输出的结果为
//          [1, 2, 2, 3, 4]
//          [1, 2, 1, 6, 7]
//          [1, 1, 3, 5, 6]
//          [1, 4, 3, 7, 5]

void print2DVecElement(vector<vector<int>> vec);
void printVecElement(vector<int> vec);

vector<vector<int>> SortTable(vector<vector<int>> &grid, vector<int> &area, vector<int> &sortCols);
vector<vector<int>> GetSortColsArr(vector<vector<int>> &grid, vector<int> &area, vector<int> &sortCols);
void AdjustArr(vector<vector<int>> &grid, vector<vector<int>> &ansArr, vector<int> &area, vector<int> &sortedArr);

int main()
{
    vector<vector<int>> grid = {{1, 2, 2, 3, 4}, {1, 2, 3, 7, 5}, {1, 1, 3, 5, 6}, {1, 4, 1, 6, 7}};
    printf("grid数组 为：\n");
    print2DVecElement(grid);
    vector<int> area = {2, 3, 4, 5};
    printf("area数组 为：\n");
    printVecElement(area);
    vector<int> sortCols = {1, 2};
    printf("sortCols数组 为：\n");
    printVecElement(sortCols);
    vector<vector<int>> ans = SortTable(grid, area, sortCols);
    printf("ans数组 为：\n");
    print2DVecElement(ans);
}

void printVecElement(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

void print2DVecElement(vector<vector<int>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            printf("%d\t", vec[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

vector<vector<int>> SortTable(vector<vector<int>> &grid, vector<int> &area, vector<int> &sortCols)
{
    int difM = area[0] - 1;
    int difN = area[1] - 1;
    vector<vector<int>> sortColsArr = GetSortColsArr(grid, area, sortCols);
    sort(sortColsArr.begin(), sortColsArr.end());
    vector<int> sortedArr(sortColsArr.size(), 0);
    for (int i = 0; i < sortColsArr.size(); i++)
    {
        sortedArr[i] = sortColsArr[i][sortColsArr[0].size() - 1];
    }
    vector<vector<int>> ansArr(grid);
    AdjustArr(grid, ansArr, area, sortedArr);
    return ansArr;
}

vector<vector<int>> GetSortColsArr(vector<vector<int>> &grid, vector<int> &area, vector<int> &sortCols)
{
    vector<vector<int>> sortColsArr(area[2] - area[0] + 1, vector<int>(sortCols.size() + 1, 0));
    int difM = area[0] - 1;
    int difN = area[1] - 1;
    for (int i = 0; i < sortColsArr.size(); i++)
    {
        for (int j = 0; j < sortColsArr[0].size() - 1; j++)
        {
            sortColsArr[i][j] = grid[i + difM][sortCols[j] - 1 + difN];
        }
        sortColsArr[i][sortColsArr[0].size() - 1] = i;
    }
    return sortColsArr;
}

void AdjustArr(vector<vector<int>> &grid, vector<vector<int>> &ansArr, vector<int> &area, vector<int> &sortedArr)
{
    int difM = area[0] - 1;
    int difN = area[1] - 1;
    for (int i = 0; i < area[2] - area[0] + 1; i++)
    {
        int orderedM = difM + sortedArr[i];
        for (int j = 0; j < area[3] - area[1] + 1; j++)
        {
            ansArr[i + difM][j + difN] = grid[orderedM][j + difN];
        }
    }
}