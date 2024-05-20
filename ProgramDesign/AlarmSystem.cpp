#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;

//      Huawei: 简易闹钟系统

//      请给新款儿童手表设计一个简易闹钟系统。实现如下功能：
//          bool AddAlarm(int id, int hour, int minute, vector<int> weekdays, int typeId):
//              新建一个编号 id 的闹钟, 若不存在 编号为 id 的闹钟，则添加该闹钟，
//              响铃时间为 hour:minute, 周期为 weekdays, 闹钟分类为 typeId, 并返回true
//              若已经存在编号为id的闹钟，直接返回false
//              weekdays[i] 表示每周的重复日，如 weekdays = {1, 4, 7} 表示每周一，四，日
//              typeId 为闹钟分类, 0: study, 1: exercise, 2: game
//          bool DeleteAlarm(int id): 删除编号为 id 的闹钟。
//              若存在则删除该闹钟并返回true，否则直接返回false
//          vector<int> QueryAlarm(int weekday, int hour, int startMinute, int endMinute):
//              查询指定筛选条件的闹钟，并按排序条件返回闹钟编号的列表。
//              若无符合条件的闹钟，返回空数组[]
//              筛选条件：
//                  查询每周 weekday,
//                  时段为 startMinute ~ endMinute 会响起的闹钟(起止时间均包含在内)：
//              排序条件：
//                  先按响铃时间的先后顺序排序；
//                  如果响铃时间相同，则按照闹钟分类的值从小到大排序；
//                  若闹钟分类也相同，则闹钟编号小的排在前面。

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

void printVecElement(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

class AlarmSystem
{
public:
    // unordered_map<id, tuple<weekdays, hour, minute, typeId>>
    unordered_map<int, tuple<vector<int>, int, int, int>> hmap;

    AlarmSystem()
    {
    }

    bool AddAlarm(int id, vector<int> weekdays, int hour, int minute, int typeId)
    {
        if (hmap.find(id) != hmap.end())
        {
            return false;
        }
        hmap[id] = make_tuple(weekdays, hour, minute, typeId);
        return true;
    }

    bool DeleteAlarm(int id)
    {
        if (hmap.find(id) == hmap.end())
        {
            return false;
        }
        hmap.erase(id);
        return true;
    }

    vector<int> QueryAlarm(int weekday, int hour, int startMinute, int endMinute)
    {
        vector<int> ans;
        vector<vector<int>> clockVec;
        for (auto it = hmap.begin(); it != hmap.end(); it++)
        {
            vector<int> tem = get<0>(it->second);
            for (int i = 0; i < tem.size(); i++)
            {
                if (tem[i] == weekday && get<1>(it->second) == hour && get<2>(it->second) >= startMinute && get<2>(it->second) <= endMinute)
                {
                    clockVec.push_back({it->first, get<2>(it->second), get<3>(it->second)});
                }
            }
        }
        sort(clockVec.begin(), clockVec.end(), [&](vector<int> v1, vector<int> v2)
             {
            if(v1[1] == v2[1]){
                if(v1[2] == v2[2]){
                    return v1[0] < v2[0] ;
                }else{
                    return v1[2] < v2[2] ;
                }
            }else{
                return v1[1] < v2[1];
            } });
        for (int i = 0; i < clockVec.size(); i++)
        {
            ans.push_back(clockVec[i][0]);
        }
        return ans;
    }
};

int main()
{
    AlarmSystem *alarmSystem1 = new AlarmSystem();
    bool a11 = alarmSystem1->AddAlarm(1, {1, 2, 3}, 1, 15, 2);
    printf("新增闹钟结果为：\n");
    printBool(a11); // true
    bool a12 = alarmSystem1->AddAlarm(1, {3, 4}, 1, 30, 2);
    printf("新增闹钟结果为：\n");
    printBool(a12); // false
    bool a13 = alarmSystem1->AddAlarm(3, {3, 5}, 1, 10, 0);
    printf("新增闹钟结果为：\n");
    printBool(a13); // true
    bool a14 = alarmSystem1->DeleteAlarm(4);
    printf("删除闹钟结果为：\n");
    printBool(a14); // true
    bool a15 = alarmSystem1->AddAlarm(7, {3, 6}, 1, 10, 1);
    printf("新增闹钟结果为：\n");
    printBool(a15); // true
    vector<int> q11 = alarmSystem1->QueryAlarm(3, 1, 5, 20);
    printf("查询闹钟结果为：\n");
    printVecElement(q11);
}