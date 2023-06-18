#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

//      Huawei: 文件权限管理系统

//      请你设计一个文件权限管理系统，实现以下功能：
//      int DirPermSystem(vector<int> path, vector<int> statuses):
//          初始化文件目录树及其初始状态
//          path[i]下标表示目录编号，值表示其上一级目录的编号
//              (根目录编号是 0, path[0]固定位 -1)
//              statuses[i]表示目录i的初始状态，所有用户均可以访问(无论是否授权)
//          1表示[公开]状态，所有用户均可以访问，无论是否授权
//          2表示[加密]状态，仅拥有权限用户均可以访问；
//      void ChangeStatus(int dirId, int status):
//          修改目录dirId的状态为status(不涉及子目录)
//      void GrantRight(int userId, int dirId):
//          授予用户userId对目录dirId持有[目录树权限]
//          持有对dirId的[目录树权限]后，
//          代表该用户可以访问dirId及其所有子目录(包含直接子目录,子目录的子目录等)
//          即使加密的目录也可以访问
//          注意：重复授予同一用户对目录dirId的[目录树权限]权限，只保留最后一次
//      bool RemoveRight(int userId, int dirId):
//          移除用户userId对目录dirId所持有的[目录树权限]。
//          若授予过，则移除对这个目录的授权，并返回true
//          否则不做处理，返回false
//      bool QueryRight(int userId, int dirId):
//          查询用户userId是否可以访问目录dirId,
//          是返回true, 否则返回false
//      int QueryNum(int userId):
//          查询用户userId所有可访问的目录数量。
//          注意：输入用例保证函数中的dirId已存在
//      示例1：
//          输入：
//          ["DirPermSystem", "GrantRight", "GrantRight", "ChangeStatus",
//              "GrantRight", "GrantRight", "QueryNum", "RemoveRight",
//              "QueryRight", "ChangeStatus", "GrantRight", "RemoveRight",
//              "QueryNum", "GrantRight", "ChangeStatus", "RemoveRight",
//              "QueryNum", "ChangeStatus", "RemoveRight", "QueryNum"]
//          [[-1, 2, 0, 6, 6, 0, 0, 2, 3], [2, 1, 2, 2, 2, 1, 1, 2, 1], [105, 6]
//          [103, 3], [8, 2], [105, 3], [103, 6], [105], [101, 6], [103, 3],
//          [6, 2], [105, 6], [103, 6], [103], [105, 2], [2, 1], [105, 3], [105]
//          [6, 2], [105, 6], [105]]
//          输出：
//          [null, null, null, null, null, null, 6, false, true, null, null,
//           4, null, null, true, 8, null, true, 4]

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

class DirPermSystem
{
public:
    vector<int> pathVec;
    vector<int> statusVec;
    unordered_map<int, unordered_set<int>> grantMap;

    DirPermSystem(vector<int> path, vector<int> statuses)
    {
        pathVec = vector<int>(path);
        statusVec = vector<int>(statuses);
    }

    void ChangeStatus(int dirId, int status)
    {
        statusVec[dirId] = status;
    }

    void GrantRight(int userId, int dirId)
    {
        grantMap[userId].insert(dirId);
    }

    bool RemoveRight(int userId, int dirId)
    {
        if (grantMap[userId].erase(dirId))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool QueryRight(int userId, int dirId)
    {
        // 如果该文件 公开，所有人都可以看：
        if (statusVec[dirId] == 1)
        {
            return true;
        }
        // 如果该文件 加密，一直 往根目录 搜索：
        int cur = dirId;
        while (cur != -1)
        {
            if (grantMap[userId].count(cur))
            {
                return true;
            }
            cur = pathVec[cur];
        }
        return false;
    }

    int QueryNum(int userId)
    {
        int cnt = 0;
        for (int i = 0; i < pathVec.size(); i++)
        {
            if (QueryRight(userId, i))
            {
                cnt++;
            }
        }
        return cnt;
    }
};

int main()
{
    vector<int> path = {-1, 2, 0, 6, 6, 0, 0, 2, 3};
    vector<int> statuses = {2, 1, 2, 2, 2, 1, 1, 2, 1};
    DirPermSystem *dirPermSystem = new DirPermSystem(path, statuses);
    dirPermSystem->GrantRight(105, 6);
    dirPermSystem->GrantRight(103, 3);
    dirPermSystem->ChangeStatus(8, 2);
    dirPermSystem->GrantRight(105, 3);
    dirPermSystem->GrantRight(103, 6);
    int q1 = dirPermSystem->QueryNum(105);
    printf("该用户所有可访问的目录数量为 %d\n", q1);
    bool r1 = dirPermSystem->RemoveRight(101, 6);
    printf("删除所持有的[目录树权限]结果为:\n");
    printBool(r1);
    bool q2 = dirPermSystem->QueryRight(103, 3);
    printf("查询所持有的[目录树权限]结果为:\n");
    printBool(q2);
    dirPermSystem->ChangeStatus(6, 2);
    dirPermSystem->GrantRight(105, 6);
    bool r2 = dirPermSystem->RemoveRight(103, 6);
    printf("删除所持有的[目录树权限]结果为:\n");
    printBool(r2);
    int q3 = dirPermSystem->QueryNum(103);
    printf("该用户所有可访问的目录数量为 %d\n", q3);
    dirPermSystem->GrantRight(105, 2);
    dirPermSystem->ChangeStatus(2, 1);
    bool r3 = dirPermSystem->RemoveRight(105, 3);
    printf("删除所持有的[目录树权限]结果为:\n");
    printBool(r3);
    int q4 = dirPermSystem->QueryNum(105);
    printf("该用户所有可访问的目录数量为 %d\n", q4);
    dirPermSystem->ChangeStatus(6, 2);
    bool r4 = dirPermSystem->RemoveRight(105, 6);
    printf("删除所持有的[目录树权限]结果为:\n");
    printBool(r4);
    int q5 = dirPermSystem->QueryNum(105);
    printf("该用户所有可访问的目录数量为 %d\n", q5);
}