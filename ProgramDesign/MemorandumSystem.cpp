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
//              例如命令为AddEvent(0, "a", 4, 2): 表示于日期0, 2, 4, 6 分别添加待办事项 "a"
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
//          输入：["MemoSystem", "AddEvent", "AddEvent", "RemoveEvent", "FinishEvent",
//                 "AddEvent", "AddEvent", "QueryTodo", "QueryTodo", "FinishEvent",
//                 "AddEvent"]
//             [[], [2, "save files", 1, 1], [2, "eat a burger", 1, 1], 
//              [2, "drink water"], [1, "drink water"], [0, "eat a burger", 5, 2], 
//              [2, "save files", 1, 1], [0, 4], [10, 11], [2, "eat a burger"], 
//              [2, "eat a burger", 1, 1]]
//          输出：[null, 1, 1, false, false, 4, 0, 
//                  ["eat a burger", "eat a burger", "save files", "eat a burger"],
//                  [], true, 0]

MemorandumSystem