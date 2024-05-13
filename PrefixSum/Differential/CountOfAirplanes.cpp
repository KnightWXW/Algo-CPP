#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

//      LintCode 391 数飞机

//      链接：https://www.lintcode.com/problem/391/

//      给出飞机的起飞和降落时间的列表，用序列 interval 表示.
//      请计算出天上同时最多有多少架飞机？
//      如果多架飞机降落和起飞在同一时刻，我们认为降落有优先权。
//      样例 1:
//          输入: [[1, 10], [2, 3], [5, 8], [4, 7]]
//          输出: 3
//          解释:
//              第一架飞机在1时刻起飞, 10时刻降落.
//              第二架飞机在2时刻起飞, 3时刻降落.
//              第三架飞机在5时刻起飞, 8时刻降落.
//              第四架飞机在4时刻起飞, 7时刻降落.
//              在5时刻到6时刻之间, 天空中有三架飞机.
//      样例 2:
//          输入: [[1, 2], [2, 3], [3, 4]]
//          输出: 1
//          解释: 降落优先于起飞.

void print2DVecElement(vector<vector<int>> vec);

int CountOfAirplanes(vector<vector<int>> airplanes);

int main()
{
    vector<vector<int>> vec1 = {{1, 10}, {2, 3}, {5, 8}, {4, 7}};
    print2DVecElement(vec1);
    int ans1 = CountOfAirplanes(vec1);
    printf("天上同时最多有 %d 架飞机。\n", ans1);
    vector<vector<int>> vec2 = {{1, 2}, {2, 3}, {3, 4}};
    print2DVecElement(vec2);
    int ans2 = CountOfAirplanes(vec2);
    printf("天上同时最多有 %d 架飞机。\n", ans2);
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

// 差分：
// Time：O(N)
// Space: O(N)
int CountOfAirplanes(vector<vector<int>> airplanes)
{
    int l = airplanes.size();
    vector<vector<int>> arr(airplanes);
    int ans = 0;
    int start = INT_MAX;
    int end = INT_MIN;
    for (int i = 0; i < l; i++)
    {
        start = min(start, arr[i][0]);
        end = max(end, arr[i][1]);
    }
    vector<int> help(end - start + 1, 0);
    for (int i = 0; i < l; i++)
    {
        int starti = arr[i][0];
        int endi = arr[i][1];
        help[starti - start]++;
        help[endi - start]--;
    }
    for (int i = 0; i < help.size() - 1; i++)
    {
        help[i + 1] += help[i];
    }
    for(int i = 0; i < help.size(); i++)
    {
        ans = max(ans, help[i]);
    }
    return ans;
}