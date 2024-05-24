#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <deque>

using namespace std;

//      Huawei: 园区电梯控制系统

//      某大楼有一部电梯，初始电梯内没有乘客，乘客出现顺序保存在数组passengers中，
//      passengers[i]格式为 from to，分别表示乘客所在的楼层和想去的楼层。
//      假设乘客按顺序一个一个出现，当前乘客passengers[i] 进入电梯且电梯关门后，
//      后一个乘客 passengers[i + 1] 立刻出现并等待
//      电梯搭载规则如下：
//          当电梯内无乘客时：立刻去接当前等待乘客
//          当电梯内有乘客时：将电梯内乘客都送到之前，电梯不会改变运行方向
//          若电梯经过当前等待乘客所在楼层，且运行方向与当前等待乘客想去的方向一致，
//          就会顺路搭载当前等待乘客
//          假设电梯能够携带的乘客数量没有限制，请计算电梯运送完最后一个乘客，
//          总共运行了多少层的距离
//      输入
//          首行两个整数num initFloor,分别表示乘客的个数和电梯初始所在的楼梯，
//              1 <= num <= 100, 1 <= initFloor <= 100
//          接下来num行表示passengers信息，passengers[i]格式为 from to，
//          分别表示乘客所在的楼层和想去的楼层，
//          1 <= from <= 100, 1 <= to <= 100, from != to
//      输出
//          一个整数，表示电梯总共运行了多少层的距离
//      示例 1:
//          输入：
//              3 50
//              12 66
//              15 27
//              26 83
//          输出: 109
//      示例 2:
//          输入：
//              4 50
//              50 10
//              40 20
//              30 100
//              30 100
//          输出: 270

void print2DVecElement(vector<vector<int>> vec);

int ElevatorControlSystem_A(int start, vector<vector<int>> passengers);
int ElevatorControlSystem_B(int start, vector<vector<int>> passengers);

int main()
{
    int start1 = 50;
    vector<vector<int>> vec1 = {{12, 66}, {15, 27}, {26, 83}};
    print2DVecElement(vec1);
    int ans_11 = ElevatorControlSystem_A(start1, vec1);
    printf("电梯总共运行了 %d 层\n", ans_11);
    int ans_12 = ElevatorControlSystem_B(start1, vec1);
    printf("电梯总共运行了 %d 层\n", ans_12);
    int start2 = 50;
    vector<vector<int>> vec2 = {{50, 10}, {40, 20}, {30, 100}, {30, 100}};
    print2DVecElement(vec2);
    int ans_21 = ElevatorControlSystem_A(start2, vec2);
    printf("电梯总共运行了 %d 层\n", ans_21);
    int ans_22 = ElevatorControlSystem_B(start2, vec2);
    printf("电梯总共运行了 %d 层\n", ans_22);
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

// 模拟电梯行进线路, 再统计计算：
// Time: O(N)
// Space: O(N)
int ElevatorControlSystem_A(int start, vector<vector<int>> passengers)
{
    int l = passengers.size();
    int preFloor = start;
    int direct = 0;
    int ans = 0;
    deque<vector<int>> dq;
    for (int i = 0; i < l; i++)
    {
        if (dq.empty())
        {
            dq.push_back(passengers[i]);
            continue;
        }
        vector<int> v = dq.back();
        dq.pop_back();
        direct = v[1] - v[0];
        if (((direct * (passengers[i][1] - passengers[i][0]) > 0)) &&
            ((direct * (passengers[i][0] - v[0]) > 0)))
        {
            v[1] = direct > 0 ? max(v[1], passengers[i][1]) : min(v[1], passengers[i][1]);
            dq.push_back(v);
        }
        else
        {
            dq.push_back(v);
            dq.push_back(passengers[i]);
        }
    }

    while (!dq.empty())
    {
        vector<int> v = dq.front();
        dq.pop_front();
        ans += abs(v[0] - preFloor) + abs(v[1] - v[0]);
        preFloor = v[1];
    }
    return ans;
}

// 模拟电梯行进线路, 并同时计算：
// Time: O(N)
// Space: O(1)
int ElevatorControlSystem_B(int start, vector<vector<int>> passengers)
{
    int l = passengers.size();
    int ans = abs(passengers[0][0] - start);
    int curFloor = passengers[0][0];
    int tarFloor = passengers[0][1];
    int direction = tarFloor - curFloor;
    for (int i = 1; i < l; i++)
    {
        // 同为上行
        if ((direction > 0) &&
            (passengers[i][0] > curFloor) &&
            (passengers[i][1] > passengers[i][0]))
        {
            tarFloor = max(tarFloor, passengers[i][1]);
        }
        // 同为下行
        else if ((direction < 0) &&
                 (passengers[i][0] < curFloor) &&
                 (passengers[i][1] < passengers[i][0]))
        {
            tarFloor = min(tarFloor, passengers[i][1]);
        }
        // 进行转向
        else
        {
            ans += abs(tarFloor - curFloor);
            curFloor = tarFloor;
            ans += abs(passengers[i][0] - curFloor);
            curFloor = passengers[i][0];
            tarFloor = passengers[i][1];
            direction = -direction;
        }
    }
    ans += abs(tarFloor - curFloor);
    return ans;
}