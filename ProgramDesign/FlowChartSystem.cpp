#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//      Huawei: 流程图管理系统

//      请设计一个流程图管理系统，实现以下功能：
//          bool AddNode(int nodeId, int nodeType): 新增节点nodeId, 其类型为nodeType,
//              若节点nodeId不存在, 则节点添加成功并返回true, 否则直接返回false.
//              nodeType == 1: 中继节点，系统中任意其他节点(包括之后增加的节点)
//                              到nodeId均自动建立一条单向连接
//              nodeType == 0: 普通节点，其他节点到此节点的链接需要手动创建
//          bool AddConnection(int connectId, int startNodeId, int endNodeId):
//              手工创建一条编号为connectId的单向连接，起点为startNodeId, 终点为endNodeId,
//              若存在节点startNodeId和endNodeId, 且startNodeId != endNodeId,
//              同时不存在编号为connectId的链接，则添加成功并返回 true
//          bool RemoveConnection(int connectId): 移除手工创建的编号为connectId的链接。
//              若存在connectId的链接，则移除成功并返回true, 否则直接返回false。
//          bool RemoveNode(int nodeId): 移除成功节点并返回true, 否则直接返回false。
//          vector<int> Query(int nodeId): 查找以nodeId为起点的所有连接(含自动和手动创建)，
//              并返回这些链接的终点列表(对节点编号去重后再升序排序)，
//              若nodeId不存在或无连接，则返回 空列表[]。
//      示例1：
//      输入：
//          ["FlowChartSystem", "AddNode", "AddNode", "AddNode", "AddConnection",
//          "AddNode", "Query", "RemoveNode", "RemoveConnection"]
//          [[], [100, 0], [101, 0], [102, 1], [20, 100, 101], [105, 1],
//          [100], [101], [20]]
//      输出：
//          [null, true, true, true, true, true, [101, 102, 105], true, false]
//      示例2：
//      输入：
//          ["FlowChartSystem", "AddNode", "Query", "AddNode", "AddNode",
//          "AddNode", "AddNode", "Query", "AddConnection", "AddConnection",
//          "AddConnection", "Query", "RemoveConnection", "Query",
//          "RemoveNode", "RemoveNode"]
//          [[], [100, 0], [100], [101, 1], [102, 1], [101, 1], [103, 0], [103],
//          [20, 100, 102], [21, 101, 101], [10, 100, 102], [100], [20], [102],
//          [102], [102]]
//      输出：
//          [null, true, [], true, true, false, true, [101, 102], true, false,
//          true, [101, 102], true, [101], true, false]

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

void printVec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

class FlowChartSystem
{
public:
    FlowChartSystem()
    {
    }

    bool AddNode(int nodeId, int nodeType)
    {
    }

    bool AddConnection(int connectId, int startNodeId, int endNodeId)
    {
    }

    bool RemoveConnection(int connectId)
    {
    }

    bool RemoveNode(int nodeId)
    {
    }

    vector<int> Query(int nodeId)
    {
    }
};

int main()
{
    FlowChartSystem *flowChartSystem = new FlowChartSystem();
    bool a1 = flowChartSystem->AddNode(100, 0);
    printf("添加节点结果为 %d\n", a1);
    vector<int> q1 = flowChartSystem->Query(100);
    printf("查询节点结果为: \n");
    printVec(q1);
    bool a2 = flowChartSystem->AddNode(101, 1);
    printf("添加节点结果为 %d\n", a2);
    bool a3 = flowChartSystem->AddNode(102, 1);
    printf("添加节点结果为 %d\n", a3);
    bool a4 = flowChartSystem->AddNode(101, 1);
    printf("添加节点结果为 %d\n", a4);
    bool a5 = flowChartSystem->AddNode(103, 0);
    printf("添加节点结果为 %d\n", a5);
    vector<int> q2 = flowChartSystem->Query(103);
    printf("查询节点结果为: \n");
    printVec(q2);
    bool a6 = flowChartSystem->AddConnection(20, 100, 102);
    printf("添加连接结果为 %d\n", a6);
    bool a7 = flowChartSystem->AddConnection(21, 101, 101);
    printf("添加连接结果为 %d\n", a7);
    bool a8 = flowChartSystem->AddConnection(10, 100, 102);
    printf("添加连接结果为 %d\n", a8);
    vector<int> q3 = flowChartSystem->Query(100);
    printf("查询节点结果为: \n");
    printVec(q3);
    bool r1 = flowChartSystem->removeConnection(20);
    printf("删除连接结果为 %d\n", r1);
    vector<int> q4 = flowChartSystem->Query(102);
    printf("查询节点结果为: \n");
    printVec(q4);
    bool r2 = flowChartSystem->removeNode(102);
    printf("删除节点结果为 %d\n", r2);
    bool r3 = flowChartSystem->removeNode(102);
    printf("删除节点结果为 %d\n", r3);
}
