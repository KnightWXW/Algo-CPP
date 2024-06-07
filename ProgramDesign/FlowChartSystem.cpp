#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>

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
    unordered_map<int, int> nodeMap;
    // unordered_map<nodeId, nodeType>
    unordered_map<int, pair<int, int>> connectMap;
    // unordered_map<connectId, pair<startNodeId, endNodeIdnodeId>>

    FlowChartSystem()
    {
    }

    bool AddNode(int nodeId, int nodeType)
    {
        if (nodeMap.find(nodeId) != nodeMap.end())
        {
            return false;
        }
        nodeMap[nodeId] = nodeType;
        return true;
    }

    bool AddConnection(int connectId, int startNodeId, int endNodeId)
    {
        if (connectMap.find(connectId) != connectMap.end())
        {
            return false;
        }
        if (nodeMap.find(startNodeId) == nodeMap.end() || nodeMap.find(endNodeId) == nodeMap.end() || startNodeId == endNodeId)
        {
            return false;
        }
        connectMap[connectId] = make_pair(startNodeId, endNodeId);
        return true;
    }

    bool RemoveConnection(int connectId)
    {
        if (connectMap.find(connectId) == connectMap.end())
        {
            return false;
        }
        connectMap.erase(connectId);
        return true;
    }

    bool RemoveNode(int nodeId)
    {
        if (nodeMap.find(nodeId) == nodeMap.end())
        {
            return false;
        }
        nodeMap.erase(nodeId);
        vector<int> connArray;
        for (auto it = connectMap.begin(); it != connectMap.end(); it++)
        {
            if (get<0>(it->second) == nodeId || get<1>(it->second) == nodeId)
            {
                connArray.push_back(it->first);
            }
        }
        for (int i = 0; i < connArray.size(); i++)
        {
            connectMap.erase(connArray[i]);
        }
        return true;
    }

    vector<int> Query(int nodeId)
    {
        vector<int> ans;
        for (auto it = nodeMap.begin(); it != nodeMap.end(); it++)
        {
            if (it->first != nodeId && it->second == 1)
            {
                ans.push_back(it->first);
            }
        }
        for (auto it = connectMap.begin(); it != connectMap.end(); it++)
        {
            if (get<0>(it->second) == nodeId)
            {
                ans.push_back(get<1>(it->second));
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};

int main()
{
    FlowChartSystem *flowChartSystem = new FlowChartSystem();
    bool a1 = flowChartSystem->AddNode(100, 0);
    printf("添加节点结果为\n");
    printBool(a1);
    vector<int> q1 = flowChartSystem->Query(100);
    printf("查询节点结果为: \n");
    printVec(q1);
    bool a2 = flowChartSystem->AddNode(101, 1);
    printf("添加节点结果为\n");
    printBool(a2);
    bool a3 = flowChartSystem->AddNode(102, 1);
    printf("添加节点结果为\n");
    printBool(a3);
    bool a4 = flowChartSystem->AddNode(101, 1);
    printf("添加节点结果为\n");
    printBool(a4);
    bool a5 = flowChartSystem->AddNode(103, 0);
    printf("添加节点结果为\n");
    printBool(a5);
    vector<int> q2 = flowChartSystem->Query(103);
    printf("查询节点结果为: \n");
    printVec(q2);
    bool a6 = flowChartSystem->AddConnection(20, 100, 102);
    printf("添加链接结果为\n");
    printBool(a6);
    bool a7 = flowChartSystem->AddConnection(21, 101, 101);
    printf("添加链接结果为\n");
    printBool(a7);
    bool a8 = flowChartSystem->AddConnection(10, 100, 102);
    printf("添加链接结果为\n");
    printBool(a8);
    vector<int> q3 = flowChartSystem->Query(100);
    printf("查询节点结果为: \n");
    printVec(q3);
    bool r1 = flowChartSystem->RemoveConnection(20);
    printf("删除节点结果为\n");
    printBool(r1);
    vector<int> q4 = flowChartSystem->Query(102);
    printf("查询节点结果为: \n");
    printVec(q4);
    bool r2 = flowChartSystem->RemoveNode(102);
    printf("删除点结果为\n");
    printBool(r2);
    bool r3 = flowChartSystem->RemoveNode(102);
    printf("删除节点结果为\n");
    printBool(r3);
}
