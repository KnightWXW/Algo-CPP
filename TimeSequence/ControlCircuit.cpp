#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//      实验室对一个设备进行通断性测试，实验室可以操纵开关进行通断，有两种情况：
//      当开关 1 断开，或开关2, 3均被断开，设备不工作
//      当开关 1 闭合，且开关2和开关3至少有一个闭合时，设备工作
//              --------||-----/ 1-----------
//              |                           |
//              |                           |
//              |                           |
//              |           ----/ 2----     |
//              |           |         |     |
//              -----X-----------------------
//                          |         |
//                          ----/ 3----
//      初始时，3个开关的状态均为断开;
//      现给定实验员操控记录的数组records, records[i] = [time, switchId],
//      表示在时刻 time 更改了开关 switchId 的状态。
//      开关 switchId 仅为 1,2,3, 状态是从断开变为闭合，或从闭合变成断开。
//      测试中为了避免设备过热，若开关在时刻 time 闭合,
//      且在[time, time + limit] 闭合内未接收到指令,
//      则：在时刻 time + limit 该开关自动变为断开；
//      若此时恰好收到指令，则该开关再次变为闭合
//      请返回完成最后一次操作，且所有开关状态变为断开后，设备的累计工作时长。
//      示例1：
//          输入：
//              records = {{0, 1}, {1, 3}, {2, 2}, {3, 3}, {4, 1}, {4, 3}};
//              limit = 3
//          输出: 5
//      示例1：
//          输入：
//              records = {{3, 3}, {4, 1}, {5, 2}, {6, 1}, {7, 3}, {8, 1}, {11, 3}};
//              limit = 4
//          输出: 6

void print2DVecElement(vector<vector<int>> vec);
int ControlCircuit(vector<vector<int>> records, int limit);

int main()
{
    vector<vector<int>> v1 = {{0, 1}, {1, 3}, {2, 2}, {3, 3}, {4, 1}, {4, 3}};
    int limit1 = 3;
    int ans1 = ControlCircuit(v1, limit1);
    print2DVecElement(v1);
    printf("limit = %d 时, 设备的累计工作时长为 %d\n", limit1, ans1);
    vector<vector<int>> v2 = {{3, 3}, {4, 1}, {5, 2}, {6, 1}, {7, 3}, {8, 1}, {11, 3}};
    int limit2 = 4;
    int ans2 = ControlCircuit(v2, limit2);
    print2DVecElement(v2);
    printf("limit = %d 时, 设备的累计工作时长为 %d\n", limit2, ans2);
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

int ControlCircuit(vector<vector<int>> records, int limit)
{
    int l = records.size();
    int ans = 0;
    int index = 0;
    int startTime = records[0][0];
    int endTime = records[l - 1][0] + limit;
    vector<int> time(3, 0);
    for (int i = startTime; i <= endTime; i++)
    {
        if (time[0] > 0 && (time[1] > 0 || time[2] > 0))
        {
            ans++;
        }
        time[0]--;
        time[1]--;
        time[2]--;
        while (index < l && records[index][0] == i)
        {
            int j = records[index][1] - 1;
            time[j] = (time[j] > 0) ? 0 : limit;
            index++;
        }
    }
    return ans;
}