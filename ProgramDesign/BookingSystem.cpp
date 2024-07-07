#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <numeric>
#include <algorithm>
#include <map>
#include <unordered_set>

using namespace std;

//      Huawei: 实验室预约系统

//      请你设计一个实验室预约系统BookingSystem,
//      每个实验室可以添加开放时段用于预约，且预约时段必须在开放时间内，
//      已被预约的时间不可再预约，实现以下功能：
//          AddLab(int labId, int startTime, int endTime):
//              增加编号为 labId 的实验室，并开放时段 (左闭右开)。
//              若系统中不存在该实验室，则将该实验室添加到系统中，
//                  并设置开放时段为[startTime, endTime], 返回true。
//              若系统中不存在该实验室，如果时段[startTime, endTime]
//                  与该实验室已有开放时段存在重叠，则不做操作并返回false
//                  否则，将该实验室新增开放时段[startTime, endTime], 并返回true
//          BookTime(int recordId, int fromTime, int toTime):
//              预约[fromTime, toTime]时段的实验室：
//              若存在一个或多个该时段的实验室可被预约，则预约其中最早到系统的实验室，
//              并占用该实验室的[startTime, endTime]时段，最后返回被预约的实验室编号。
//              若该时段没有可用的实验室，则返回-1：
//              注意：系统保证为每次预约分配全局唯一的recordId。
//          CancelBooking(int recordId):
//              取消系统中存在编号为recordId的预约
//              若系统中存在编号为recordId的预约且未被取消，
//              则取消预约并释放预约占用时间段资源，返回true。
//              否则不做任何操作，返回false。
//      示例：
//          输入：
//              ["BookingSystem", "AddLab", "AddLab", "AddLab",
//              "BookTime", "CancelBooking", "AddLab", "BookTime",
//              "BookTime", "CancelBooking"]
//              [[], [2, 8, 17], [2, 2, 10], [2, 17, 30], [1, 9, 28],
//              [1], [6, 1, 30], [13, 8, 27], [9, 26, 30], [10]]
//          输出：
//              [null, true, false, true, 2, true, true, 2, 6, false]

void printBool(bool b)
{
    if (b == true)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
}

class BookingSystem
{

    struct Lab
    {
        int labid;
        vector<pair<int, int>> times;
        Lab(int id)
        {
            this.id = labid;
        }
    };
    publc : vector<Lab> vec;
    map<int, vector<int>> hmap;

    int FindLabId(int labid)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i].labid == labid)
            {
                return i;
            }
        }
        return -1;
    }

    bool IsCross(pair<int, int> p, int fromTime, int toTime)
    {
        if (p.first >= toTime || p.second <= fromTime)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    void MergeBook(vector<pair<int, int>> vec)
    {
        sort(vec.begin(), vec.end(), [](pair<int, int> &a, pair<int, int> &b)
             { return a.first <= b.first; });
        for (auto it = vec.begin() + 1; it != vec.end();)
        {
            if (it->first == (it - 1)->second)
            {
                (it - 1)->second = it->second;
                vec.erase(it);
            }
            else
            {
                it++;
            }
        }
        return;
    }

    bool AddLab(int labId, int startTime, int endTime)
    {
    }

    int BookTime(int recordId, int fromTime, int toTime)
    {
    }

    bool CancelBooking(int recordId)
    {
    }
};

int main()
{
    BookSystem *bookSystem = new BookSystem();
    bool a1 = bookSystem->AddLib(2, 8, 17);
    printf("系统中添加 结果 为 :\n");
    printBool(a1);
    bool a2 = bookSystem->AddLib(2, 2, 10);
    printf("系统中添加 结果 为 :\n");
    printBool(a2);
    bool a3 = bookSystem->AddLib(2, 17, 30);
    printf("系统中添加 结果 为 :\n");
    printBool(a3);
    int b1 = bookSystem->BookTime(1, 9, 28);
    printf("系统中预约 结果 为 : %d\n", b1);
    bool c1 = bookSystem->CancelBooking(1);
    printf("系统中删除 结果 为 :\n");
    printBool(c1);
    bool a4 = bookSystem->AddLib(6, 1, 30);
    printf("系统中添加 结果 为 :\n");
    printBool(a4);
    int b2 = bookSystem->BookTime(13, 8, 27);
    printf("系统中预约 结果 为 : %d\n", b2);
    int b3 = bookSystem->BookTime(9, 26, 30);
    printf("系统中预约 结果 为 : %d\n", b3);
    bool c2 = bookSystem->CancelBooking(10);
    printf("系统中删除 结果 为 :\n");
    printBool(c2);
}
