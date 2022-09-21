#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

//      LeetCode: 252 会议室

//      链接：https://leetcode.cn/problems/meeting-rooms

//      给定一个会议时间安排的数组，每个会议时间都会包括开始和结束的时间 [[s1,e1],[s2,e2],...] (si < ei)，
//      请你判断一个人是否能够参加这里面的全部会议。

//      示例 1:
//          输入: [[0,30],[5,10],[15,20]]
//          输出: false

//      示例 2:
//          输入: [[7,10],[2,4]]
//          输出: true

void print2DVecElement(vector<vector<int>> vec);
bool canAttendMeeting(vector<vector<int>> &intervals);

int main()
{
    vector<vector<int>> intervals1 = {{0, 30}, {5, 10}, {15, 20}};
    print2DVecElement(intervals1);
    bool flag1 = canAttendMeeting(intervals1);
    if (flag1 == true)
    {
        printf("Yes.\n");
    }
    else
    {
        printf("No.\n");
    }

    vector<vector<int>> intervals2 = {{7, 10}, {2, 4}};
    print2DVecElement(intervals2);
    bool flag2 = canAttendMeeting(intervals2);
    if (flag2 == true)
    {
        printf("Yes.\n");
    }
    else
    {
        printf("No.\n");
    }
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
bool canAttendMeeting(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), [&](vector<int> vec1, vector<int> vec2)
         {
        if(vec1[0] == vec2[0]){
            return vec1[1] < vec2[1];
        }
        return vec1[0] < vec2[0]; });
    // sort(intervals.begin(), intervals.end());

    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] <= intervals[i - 1][1])
        {
            return false;
        }
    }
    return true;
}