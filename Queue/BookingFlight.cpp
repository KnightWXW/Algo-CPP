#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <deque>

using namespace std;

//      Huawei: 预定往返机票

//      有个工程师出差支持某项目，要求找到最便宜的往返机票价格。
//      给定两个数组：表示去程的连续N天机票价格 go；表示返程的连续N天机票价格 back
//      给定一个 最大支撑天数maxDays 和 最小支撑天数minDays
//      表示这次出差最多支持maxDays, 最少支持minDays,
//      支撑天数 = 返程时间 - 出发时间。
//      示例1：
//          输入：  {10, 9, 1, 3, 5, 7, 3, 8, 6, 8}
//                  {9, 4, 3, 7, 2, 7, 2, 6, 1, 6}
//                  9
//                  3
//          输出:   2
//      示例2：
//          输入：  {10, 9, 1, 3, 5, 7, 3, 8, 6, 8}
//                  {9, 4, 3, 7, 2, 7, 2, 6, 1, 6}
//                  5
//                  3
//          输出:   3

void printVecElement(vector<int> vec);

void DequePush(deque<int>& dq, int val);
void DequePop(deque<int>& dq, int val);
int BookingFlight_A(vector<int> go, vector<int> back, int maxDays, int minDays);
int BookingFlight_B(vector<int> go, vector<int> back, int maxDays, int minDays);

int main()
{
    vector<int> go1 = {10, 9, 1, 3, 5, 7, 3, 8, 6, 8};
    vector<int> back1 = {9, 4, 3, 7, 2, 7, 2, 6, 1, 6};
    int maxDays1 = 9;
    int minDays1 = 3;
    int ans_A1 = BookingFlight_A(go1, back1, maxDays1, minDays1);
    int ans_B1 = BookingFlight_B(go1, back1, maxDays1, minDays1);
    printVecElement(go1);
    printVecElement(back1);
    printf("出差最多支持%d天, 最少支持%d天时, 最便宜的往返机票价格为 %d\n", maxDays1, minDays1, ans_A1);
    printf("出差最多支持%d天, 最少支持%d天时, 最便宜的往返机票价格为 %d\n", maxDays1, minDays1, ans_B1);

    vector<int> go2 = {10, 9, 1, 3, 5, 7, 3, 8, 6, 8};
    vector<int> back2 = {9, 4, 3, 7, 2, 7, 2, 6, 1, 6};
    int maxDays2 = 5;
    int minDays2 = 3;
    int ans_A2 = BookingFlight_A(go2, back2, maxDays2, minDays2);
    int ans_B2 = BookingFlight_B(go2, back2, maxDays2, minDays2);
    printVecElement(go2);
    printVecElement(back2);
    printf("出差最多支持%d天, 最少支持%d天时, 最便宜的往返机票价格为 %d\n", maxDays2, minDays2, ans_A2);
    printf("出差最多支持%d天, 最少支持%d天时, 最便宜的往返机票价格为 %d\n", maxDays2, minDays2, ans_B2);
}

void printVecElement(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

// 双循环：
// Time：O(N2)
// Space：O(1)
int BookingFlight_A(vector<int> go, vector<int> back, int maxDays, int minDays)
{
    int l = go.size();
    int ans = INT_MAX;
    for (int i = 0; i < l; i++)
    {
        for (int j = i + minDays; j < min(i + maxDays, l); j++)
        {
            ans = min(ans, go[i] + back[j]);
        }
    }
    return ans;
}

void DequePush(deque<int>& dq, int val)
{
    while (!dq.empty() && dq.back() > val)
    {
        dq.pop_back();
    }
    dq.push_back(val);
    return;
}

void DequePop(deque<int>& dq, int val)
{
    if (dq.front() == val)
    {
        dq.pop_front();
    }
    return;
}
// 单调队列：
// Time: O(N)
// Space: O(N)
int BookingFlight_B(vector<int> go, vector<int> back, int maxDays, int minDays)
{
    int l = go.size();
    deque<int> dq;
    queue<int> q;
    for (int i = minDays; i <= maxDays; i++)
    {
        q.push(back[i]);
        DequePush(dq, back[i]);
    }
    int ans = go[0] + dq.front();
    for (int i = 1; i < l - maxDays; i++)
    {
        int index = i + maxDays;
        // 队列出队
        int tem = q.front();
        q.pop();
        DequePop(dq, tem);
        // 队列入队
        q.push(back[index]);
        DequePush(dq, back[index]);
        ans = min(ans, go[i] + dq.front());
    }
    for (int i = l - maxDays; i < l - minDays; i++)
    {
        DequePop(dq, back[i + minDays - 1]);
        ans = min(ans, go[i] + dq.front());
    }
    return ans;
}