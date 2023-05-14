#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

//      小红书：摸着石头过河

//      给定一个三元二维数组，[x, y, z]:
//          x 表示颜色, 0表示无色, 1表示红色, 2表示蓝色
//          y 表示石头变红色代价, z表示石头变蓝色代价
//      [0,4,7]: 0表示这里石头没有颜色，如果变红代价是4，如果变蓝代价是7
//      [1,X,X]: 1表示这里石头已经是红，而且不能改颜色，所以后两个数 X 无意义
//      [2,X,X]: 2表示这里石头已经是蓝，而且不能改颜色，所以后两个数 X 无意义
//      颜色只可能是0、1、2，代价一定>=0
//      给你一批这样的小数组，要求最后必须所有石头都有颜色，
//      且红色和蓝色一样多，返回最小代价
//      如果怎么都无法做到所有石头都有颜色、且红色和蓝色一样多，返回-1

void print2DVecElement(vector<vector<int>> vec);

int ColoredStone(vector<vector<int>> vec);

int main()
{
    vector<vector<int>> vec1 = {{1, 5, 3}, {2, 7, 9}, {0, 6, 4}, {0, 7, 9}, {0, 2, 1}, {0, 5, 9}};
    print2DVecElement(vec1);
    int ans1 = ColoredStone(vec1);
    printf("最小的变色代价为：%d\n", ans1); // 17
    vector<vector<int>> vec2 = {{0, 2, 4}, {0, 4, 1}};
    print2DVecElement(vec2);
    int ans2 = ColoredStone(vec2);
    printf("最小的变色代价为：%d\n", ans2); // 3
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

// arr[i][0] == 0: 按照 arr[i][1] - arr[i][2] 降序
// arr[i][0] != 0: 按照 arr[i][0] 升序
bool cmp(vector<int> a, vector<int> b)
{
    if (a[0] == 0 && b[0] == 0)
    {
        return (a[1] - a[2]) > (b[1] - b[2]);
    }
    else
    {
        return a[0] < b[0];
    }
}

int ColoredStone(vector<vector<int>> vec)
{
    vector<vector<int>> arr(vec);
    int l = arr.size();
    if ((l & 1) == 1)
    {
        return -1;
    }
    int blank = 0;
    int red = 0;
    int blue = 0;
    int cost = 0;
    sort(arr.begin(), arr.end(), cmp);
    for (int i = 0; i < l; i++)
    {
        if (arr[i][0] == 1)
        {
            red++;
        }
        else if (arr[i][0] == 2)
        {
            blue++;
        }
        else
        {
            blank++;
            cost += arr[i][1];
        }
    }
    if (red > (l >> 1) || blue > (l >> 1))
    {
        return -1;
    }
    int tem = blank - ((l >> 1) - red);
    for (int i = 0; i < tem; i++)
    {
        cost += arr[i][2] - arr[i][1];
    }
    return cost;
}