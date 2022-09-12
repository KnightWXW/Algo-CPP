#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include "W:\Algo-CPP\Graph\Structure\Graph.cpp"

//      最短路径：
//          给定一幅 加权有向图 和 一个节点 node，
//          以 node 为 起点 的一颗 最短路径树 是图的 一幅子图，
//          它包含顶点 node 和从 node 可达的 所有顶点。
//          这颗有向树的 根节点为 node, 树的 每条路径 都是 有向图中的一条最短路径。

//      Dijkstra算法：
//          贪心：将一点加入集合Set，根据邻边更新其他邻点到该集合的距离。
//          找出最短距离，并将对应邻点加入集合Set。
//          重复以上步骤，加入集合Set外的顶点，直至加入所有点或者发现非联通。
//      时间复杂度：O(V^2)
//      空间复杂度：O(V)
//              V: 答案数组的长度

//      Dijkstra 求解：图中所有边的 权值 为 非负数

map<Node *, int> dijkstra(Node *node);
void printGraphNodeAndDistance(map<Node *, int> & ans);
Node *getMinDistanceWithOutSelectedNode(map<Node *, int> nodeMap, set<Node *> selectedNodeSet);

int main()
{
    // mat 给出 所有的边
    // mat[i][0] : 该边的权重 weight
    // mat[i][1] : 该边的 出发节点
    // mat[i][2] : 该边的 终止节点
    vector<vector<int>> mat{{10, 1, 2},
                            {3, 1, 3},
                            {20, 1, 4},
                            {2, 3, 2},
                            {5, 2, 4},
                            {15, 3, 5},
                            {11, 4, 5}};

    Graph *graph = CreateGraph(mat);
    map<Node *, int> ans = dijkstra(graph->nodes[1]);
    printf("(Dijkstra 算法) 单源最短路径 的 为：\n");
    printGraphNodeAndDistance(ans);
}

void printGraphNodeAndDistance(map<Node *, int> & ans)
{
    for (auto it = ans.begin(); it != ans.end(); it++)
    {
        printf("Value : %d , Distance : %d \n", it->first->value, it->second);
    }
    printf("\n");
}

map<Node *, int> dijkstra(Node *node)
{
    // nodeMap 存储 节点的当前最短路径：
    map<Node *, int> nodeMap;
    // selectedNodeSet 记录 已经确定最短路径的节点：
    set<Node *> selectedNodeSet;
    nodeMap[node] = 0;

    Node *minNode = getMinDistanceWithOutSelectedNode(nodeMap, selectedNodeSet);
    while (minNode != NULL)
    {
        int curDistance = nodeMap[minNode];
        for (auto e : minNode->edges)
        {
            Node *toNode = e->to;
            if (selectedNodeSet.find(toNode) == selectedNodeSet.end())
            {
                nodeMap[toNode] = curDistance + e->weight;
            }
            else
            {
                nodeMap[toNode] = min(curDistance + e->weight, nodeMap[toNode]);
            }
        }
        selectedNodeSet.insert(minNode);
        minNode = getMinDistanceWithOutSelectedNode(nodeMap, selectedNodeSet);
    }

    return nodeMap;
}

Node *getMinDistanceWithOutSelectedNode(map<Node *, int> nodeMap, set<Node *> selectedNodeSet)
{
    Node *minNode = NULL;
    int minDistance = INT_MAX;
    for (auto it = nodeMap.begin(); it != nodeMap.end(); it++)
    {
        Node *node = it->first;
        int distance = it->second;
        if (selectedNodeSet.find(node) == selectedNodeSet.end() && distance < minDistance)
        {
            minNode = node;
            minDistance = distance;
        }
    }
    return minNode;
}
