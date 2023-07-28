#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

//      Huawei: 运动手环设计

//      设计运动手环功能如下:
//          Pedometer(int target):
//              初始化每天(天数从 0 开始)的目标步数为target。
//          void SetTarget(int date, int target):
//              重设每天的目标为target,
//              次日生效, 即从 date + 1 起生效,
//              但不会修改 date 及 之前的目标步数
//              同一天多次重设目标步数，以最后一次为准
//          int Record(int date, int steps):
//              在第 data 天记录 steps 运动步数，
//              返回这一天已累计的步数
//          int GetMaxCompleteDays(int date):
//              根据已有记录，返回截止date(含), 达标的最长天数
//              达标：某天的累积步数大于等于当天的目标步数
//          输入保证 setTarget、Record、GetMaxCompleteDays Date参数按顺序递增
//      提示：
//          2 <= setTarget, record, getMaxCompleteDays 累计操作数 <= 10^3
//          1 <= target <= 10^5
//          0 <= date <= 365
//          1 <= steps <= 10^5
//      示例：
//          输入：
//              ["Pedometer", "Record", "Record", "Record", "SetTarget",
//              "Record", "Record", "Record", "Record",
//              "GetMaxCompleteDays", "SetTarget", "Record", "SetTarget",
//              "Record", "Record", "AddLab", "GetMaxCompleteDays"]
//              [[1000], [13, 600], [13, 500], [20, 600], [20, 500], [20, 700],
//              [21, 300], [22, 700], [23, 1200], [25], [30, 4000],
//              [30, 1500], [30, 2000], [31, 2200], [32, 3000], [32]]
//          输出：
//              [null, 600, 1100, 600, null, 1300, 300, 700, 1200, 2, null, 1500,
//              null, 2200, 3000, 3]

#define YEAR_DAYS_NUM 365
class Pedometer
{
public:
    vector<int> targetArr; // 存储目标步数数组
    vector<int> stepsArr;  // 存储当前步数数组

    Pedometer(int target)
    {
        targetArr = vector<int>(YEAR_DAYS_NUM + 1, target);
        stepsArr = vector<int>(YEAR_DAYS_NUM + 1, 0);
    }

    void SetTarget(int date, int target)
    {
        for (int i = date + 1; i < YEAR_DAYS_NUM + 1; i++)
        {
            targetArr[i] = target;
        }
        return;
    }

    int Record(int date, int steps)
    {
        stepsArr[date] += steps;
        return stepsArr[date];
    }

    int GetMaxCompleteDays(int date)
    {
        int days = 0;
        int maxDays = 0;
        for (int i = 1; i <= date; i++)
        {
            if (targetArr[i] <= stepsArr[i])
            {
                days++;
                maxDays = max(days, maxDays);
            }
            else
            {
                days = 0;
            }
        }
        return maxDays;
    }
};

int main()
{
    Pedometer *pedometer = new Pedometer(1000);
    int r1 = pedometer->Record(13, 600);
    printf("这一天已累计的步数 为 %d:\n", r1);
    int r2 = pedometer->Record(13, 500);
    printf("这一天已累计的步数 为 %d:\n", r2);
    int r3 = pedometer->Record(20, 600);
    printf("这一天已累计的步数 为 %d:\n", r3);
    pedometer->SetTarget(20, 500);
    int r4 = pedometer->Record(20, 700);
    printf("这一天已累计的步数 为 %d:\n", r4);
    int r5 = pedometer->Record(21, 300);
    printf("这一天已累计的步数 为 %d:\n", r5);
    int r6 = pedometer->Record(22, 700);
    printf("这一天已累计的步数 为 %d:\n", r6);
    int r7 = pedometer->Record(23, 1200);
    printf("这一天已累计的步数 为 %d:\n", r7);
    int g1 = pedometer->GetMaxCompleteDays(25);
    printf("达标的最长天数 为 %d:\n", g1);
    pedometer->SetTarget(30, 4000);
    int r8 = pedometer->Record(30, 1500);
    printf("这一天已累计的步数 为 %d:\n", r8);
    pedometer->SetTarget(30, 2000);
    int r9 = pedometer->Record(31, 2200);
    printf("这一天已累计的步数 为 %d:\n", r9);
    int r10 = pedometer->Record(32, 3000);
    printf("这一天已累计的步数 为 %d:\n", r10);
    int g2 = pedometer->GetMaxCompleteDays(32);
    printf("达标的最长天数 为 %d:\n", g2);
}
