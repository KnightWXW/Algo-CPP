#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

//      Huawei: 简易日志系统

//      在一个简易日志系统中，每条日志有唯一的 ID,
//      以及它的生成时间 timeStamp(ID 和 timeStamp均为正整数)。
//      根据给出的函数框架，请实现以下功能：
//          void Add(int id, int timeStamp):
//              增加一条新的日志记录，将这条日志记录存到系统中。
//          int Delete(int id):
//              在日志系统中尝试删除这个 ID 对应的日志记录。
//              如果该 日志ID 在系统中不存在，返回 -1；
//              否则删除这条日志，并返回 0。
//          int Query(int startTime, int endTime):
//              返回日志系统中生成时间 大于等于startTime 且 小于等于endTime 的日志数量
//              如果没有，请返回 0;
//      注：同一时间 可能 有 多条日志，函数定义以对应语言 的 右侧 实际框架 为准。
//      示例1：
//         输入：["LogSystem", "Add", "Add", "Add", "Query", "Delete",
//                  "Delete", "Query"]
//              [[], [1, 5], [2, 5], [3, 6], [5, 6], [2], [4], [5, 6]]
//         输出：[null, null, null, null, 3, 0, -1, 2]
//         解释：
//              第一个操作是初始化, 没有返回值
//              前三个Add操作加入了 ID 为 1,2,3 的日志，timeStamp 分别为 5,5,6
//              第一次Query操作查询timeStamp范围为[5,6]的日志数量，返回3;
//              第一次Delete操作删除了ID为2的日志，删除成功，返回0；
//              第二次Delete操作试图删除ID为4的日志，没有该日志，删除失败，返回-1；
//              最后一次Query操作查询timeStamp范围为[5,6]的日志数量，
//                  由于该范围中已经有一条日志被删除了，故返回2。

void printVec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

class LogSystem
{
public:
    LogSystem()
    {
    }

    map<int, int> hmap;

    void Add(int id, int timeStamp)
    {
        hmap[id] = timeStamp;
    }

    int Delete(int id)
    {
        if (hmap.find(id) == hmap.end())
        {
            return -1;
        }
        hmap.erase(id);
        return 0;
    }

    int Query(int startTime, int endTime)
    {
        int cntLog = 0;
        for (auto it = hmap.begin(); it != hmap.end(); it++)
        {
            int curId = it->first;
            int curStampTime = it->second;
            if (curStampTime >= startTime && curStampTime <= endTime)
            {
                cntLog++;
            }
        }
        return cntLog;
    }
};

int main()
{
    LogSystem *logSystem = new LogSystem();
    logSystem->Add(1, 5);
    logSystem->Add(2, 5);
    logSystem->Add(3, 6);
    int q1 = logSystem->Query(5, 6);
    printf("查询到的日志记录数量为 %d\n", q1);
    int d1 = logSystem->Delete(2);
    printf("删除日志结果为 %d\n", d1);
    int d2 = logSystem->Delete(4);
    printf("删除日志结果为 %d\n", d2);
    int q2 = logSystem->Query(5, 6);
    printf("查询到的日志记录数量为 %d\n", q2);
}