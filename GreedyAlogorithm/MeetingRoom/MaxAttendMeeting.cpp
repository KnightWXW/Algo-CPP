#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

//      一些项目要占用一个会议室宣讲，会议室不能同时容纳两个项目的宣讲，
//      给你每一个项目开始的时间和结束的时间 你来安排宣讲的日程，
//      要求会议室进行的宣讲的场次最多，返回最多的宣讲场次。

void print2DVecElement(vector<vector<int>> vec);
int maxAttendMeeting(vector<vector<int>> &intervals);

int main()
{
    vector<vector<int>> intervals1 = {{1, 5}, {1, 2}, {2, 8}, {3, 6}, {3, 10}};
    print2DVecElement(intervals1);
    int meeting1 = maxAttendMeeting(intervals1);
    printf("最多的宣讲场次为 %d。\n", meeting1);

    vector<vector<int>> intervals2 = {{0, 30}, {5, 10}, {15, 20}, {10, 18}, {20, 25}};
    print2DVecElement(intervals2);
    int meeting2 = maxAttendMeeting(intervals2);
    printf("最多的宣讲场次为 %d。\n", meeting2);
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

// 贪心算法：
// Time: O(NlogN)
// Space: O(N)
int maxAttendMeeting(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), [](vector<int> vec1, vector<int> vec2)
         { return vec1[1] < vec2[1]; });

    int time = 0;
    int cnt = 0;
    for (int i = 0; i < intervals.size(); i++)
    {
        if (time <= intervals[i][0])
        {
            time = intervals[i][1];
            cnt++;
        }
    }
    return cnt;
}