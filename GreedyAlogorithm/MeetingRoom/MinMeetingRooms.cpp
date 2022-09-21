#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//      LeetCode: 253 会议室 II

//      链接：https://leetcode.cn/problems/meeting-rooms-ii/

//      给定一个会议时间安排的数组，
//      每个会议时间都会包括开始和结束的时间 [[s1,e1],[s2,e2],…] (si < ei)，
//      为避免会议冲突，同时要考虑充分利用会议室资源，
//      请你计算至少需要多少间会议室，才能满足这些会议安排。

//      示例：
//      输入: [[0, 30],[5, 10],[15, 20]]
//      输出: 2

//      输入: [[7,10],[2,4]]
//      输出: 1

void print2DVecElement(vector<vector<int>> vec);
int minMeetingRooms(vector<vector<int>> &intervals);

int main()
{
    vector<vector<int>> intervals1 = {{0, 30}, {5, 10}, {15, 20}};
    print2DVecElement(intervals1);
    int ans1 = minMeetingRooms(intervals1);
    printf("至少需要 %d 间会议室 。\n", ans1);

    vector<vector<int>> intervals2 = {{7, 10}, {2, 4}};
    print2DVecElement(intervals2);
    int ans2 = minMeetingRooms(intervals2);
    printf("至少需要 %d 间会议室 。\n", ans2);
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
}

struct cmp
{
    bool operator()(int a, int b)
    {
        return a < b;
    }
};

// 贪心算法：
// Time: O(NlogN)
// Space: O(N)
int minMeetingRooms(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), [&](vector<int> vec1, vector<int> vec2)
        {
        if(vec1[1] == vec2[1]){
            return vec1[0] < vec2[0];
        }
        return vec1[1] < vec2[1]; });
    priority_queue<int, vector<int>, cmp> pq;

    pq.push(intervals[0][1]);

    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] >= pq.top())
        {
            pq.pop();
        }
        pq.push(intervals[i][1]);
    }
    return pq.size();
}