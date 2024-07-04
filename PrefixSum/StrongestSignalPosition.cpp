#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//      Huawei: 最强信号位置

//      有若干个信号塔，沿东西方向排列成一条直线，位置从 0 开始，
//      信号塔可以向东或者向西方向发射信号，信号强度是1个信号单位，
//      假设信号塔发射的信号不会衰减，
//      现给出N组信号塔的位置和信号发射的方向。
//      计算直线上的哪个位置信号最强。

void print2DVecElement(vector<vector<int>> vec);
void printVecElement(vector<int> vec);

int StrongestSignalPosition(vector<vector<int>> arr);

int main()
{
    vector<vector<int>> vec1 = {{1, 1}, {3, -1}, {4, 1}, {6, -1}, {7, 1}, {9, -1}};
    print2DVecElement(vec1);
    int ans1 = StrongestSignalPosition(vec1);
    printf("信号最强的位置是 %d\n", ans1);

    vector<vector<int>> vec2 = {{1, -1}, {3, -1}, {4, 1}, {6, -1}, {7, 1}, {9, 1}};
    print2DVecElement(vec2);
    int ans2 = StrongestSignalPosition(vec2);
    printf("信号最强的位置是 %d\n", ans2);
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

void printVecElement(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

// 前缀和：
// Time: O(N)
// Space: O(N)
int StrongestSignalPosition(vector<vector<int>> arr)
{
    int l = arr.size();
    int ans = 0;
    int maxPos = 0;
    int tag = 0;
    for (int i = 0; i < l; i++)
    {
        maxPos = max(maxPos, arr[i][0]);
    }
    vector<int> flag = vector<int>(maxPos + 1, 0);
    vector<int> vec = vector<int>(maxPos + 1, 0);
    for (int i = 0; i < l; i++)
    {
        if (arr[i][1] == 1)
        {
            flag[arr[i][0]] = 1;
        }
        else
        {
            flag[arr[i][0]] = -1;
        }
    }
    // 东向
    tag = flag[0];
    vec[0] = tag;
    for (int i = 1; i <= maxPos; i++)
    {
        if (flag[i] == 1)
        {
            tag++;
        }
        vec[i] = tag;
    }
    // 西向
    tag = flag[maxPos] == -1 ? -1 : 0;
    vec[maxPos] += tag;
    for (int i = maxPos - 1; i >= 0; i--)
    {
        if (flag[i] == -1)
        {
            tag--;
        }
        vec[i] += tag;
    }
    for (int i = 0; i <= maxPos; i++)
    {
        ans = max(abs(vec[i]), ans);
    }
    return ans;
}