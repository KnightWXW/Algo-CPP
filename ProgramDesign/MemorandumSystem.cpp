#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

//      Huawei: 备忘录系统

//      请设计一个备忘录系统，要求有以下功能：
//          int AddEvent(int startDate, String content, int num, int period):
//              自startDate开始(包含startDate),
//              添加num个以period为间隔周期待办事项content。
//              例如命令为AddEvent(0, "a", 4, 2):
//              表示于日期0, 2, 4, 6 分别添加待办事项 "a"
//              返回本次操作共计新增待办事项的数量，若部分日期已存在该事项，
//              无论该事项是否已经完成，这些日期不需添加该事项
//          bool FinishEvent(int date, String content):
//              将日期date上的content事项设置为已完成
//              若该日期上不存在此事项，或者该事项已经完成，返回false
//          bool RemoveEvent(int date, String content):
//              移除日期date上的content事项
//              若该日期上不存在此事项，返回 false;
//              若移除操作已完成，返回 true;
//          vector<string> QueryTodom(int startDate, int endDate):
//              查询从startDate 到 endDate 日期内所有未完成的content事项，
//              并将查询到的事项以字符串的形式按日期升序记于数组后返回，
//              若查询到相同日期的多条待办事项，按其字典序排列
//      示例 1：
//          输入：["MemoSystem", "AddEvent", "QueryTodo", "FinishEvent",
//                 "RemoveEvent"]
//             [[], [2, "eat a burger", 2, 3], [0, 5], [2, "eat a burger"],
//              [2, "eat a burger"]]
//          输出：[null, 2, ["eat a burger", "eat a burger"], true, true]
//      示例 2：
//          输入：["MemoSystem", "AddEvent", "AddEvent", "RemoveEvent",
//                 "FinishEvent","AddEvent", "AddEvent", "QueryTodo",
//                 "QueryTodo", "FinishEvent", "AddEvent"]
//             [[], [2, "save files", 1, 1], [2, "eat a burger", 1, 1],
//              [2, "drink water"], [1, "drink water"], [0, "eat a burger", 5, 2],
//              [2, "save files", 1, 1], [0, 4], [10, 11], [2, "eat a burger"],
//              [2, "eat a burger", 1, 1]]
//          输出：[null, 1, 1, false, false, 4, 0,
//                  ["eat a burger", "eat a burger", "save files", "eat a burger"],
//                  [], true, 0]

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

void printStringVecElement(vector<string> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%s\n", vec[i].c_str());
    }
    printf("\n");
}

class MemorandumSystem
{
public:
    map<int, map<string, bool>> hMap; // map<日期, map<内容, 状态>>

    int AddEvent(int startDate, string content, int num, int period)
    {
        int cnt = 0;
        for (int i = startDate; i < startDate + num * period; i += period)
        {
            if (hMap[i].find(content) == hMap[i].end())
            {
                hMap[i][content] = false;
                cnt++;
            }
        }
        return cnt;
    }

    bool FinishEvent(int date, string content)
    {
        if (hMap.find(date) == hMap.end() || hMap[date].find(content) == hMap[date].end() || hMap[date][content] == true)
        {
            return false;
        }
        hMap[date][content] = true;
        return true;
    }

    bool RemoveEvent(int date, string content)
    {
        if (hMap.find(date) == hMap.end() || hMap[date].find(content) == hMap[date].end())
        {
            return false;
        }
        hMap[date].erase(content);
        return true;
    }

    vector<string> QueryTodo(int startDate, int endDate)
    {
        vector<string> ans;
        for (int i = startDate; i <= endDate; i++)
        {
            for (auto it = hMap[i].begin(); it != hMap[i].end(); it++)
            {
                if (it->second == false)
                {
                    ans.push_back(it->first);
                }
            }
        }
        return ans;
    }
};

int main()
{
    MemorandumSystem *memorandumSystem = new MemorandumSystem();
    int a1 = memorandumSystem->AddEvent(2, "save files", 1, 1);
    printf("添加事项结果为 %d\n", a1);
    int a2 = memorandumSystem->AddEvent(2, "eat a burger", 1, 1);
    printf("添加事项结果为 %d\n", a2);
    bool r1 = memorandumSystem->RemoveEvent(2, "drink water");
    printf("删除事项结果为 \n");
    printBool(r1);
    bool f1 = memorandumSystem->FinishEvent(1, "drink water");
    printf("完成事项结果为 \n");
    printBool(f1);
    int a3 = memorandumSystem->AddEvent(0, "eat a burger", 5, 2);
    printf("添加事项结果为 %d\n", a3);
    int a4 = memorandumSystem->AddEvent(2, "save files", 1, 1);
    printf("添加事项结果为 %d\n", a4);
    vector<string> q1 = memorandumSystem->QueryTodo(0, 4);
    printf("查询事项结果为 \n");
    printStringVecElement(q1);
    vector<string> q2 = memorandumSystem->QueryTodo(10, 11);
    printf("查询事项结果为 \n");
    printStringVecElement(q2);
    int f2 = memorandumSystem->FinishEvent(2, "eat a burger");
    printf("完成事项结果为 \n");
    printBool(f2);
    int a5 = memorandumSystem->AddEvent(2, "eat a burger", 1, 1);
    printf("添加事项结果为 %d\n", a5);
}