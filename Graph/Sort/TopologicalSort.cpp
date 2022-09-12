#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include "W:\Algo-CPP\Graph\Structure\Graph.cpp"

void printGraphNode(vector<Node *> &vec);
vector<Node *>  topologicalSort(Graph *graph);

int main()
{
    // mat 给出 所有的边
    // mat[i][0] : 该边的权重 weight
    // mat[i][1] : 该边的 出发节点
    // mat[i][2] : 该边的 终止节点
    vector<vector<int>> mat{{1, 1, 2},
                            {1, 2, 3},
                            {1, 3, 4},
                            {1, 5, 2},
                            {1, 5, 3},
                            {1, 2, 4}};
    //      1--->2-->3---->4  +  2---4 
    //          ^   ^
    //         /  /    
    //        / /       
    //        5     
    Graph *graph = CreateGraph(mat);
    vector<Node *> ans = topologicalSort(graph); 
    printf("该 图结构 的 拓扑排序 为：\n");
    printGraphNode(ans);   // 1 5 2 3 4 或 5 1 2 3 4
}

void printGraphNode(vector<Node *> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]->value);
    }
    printf("\n");
}

// 拓扑排序：
// 拓扑排序一定存在于 有向无环图
// 有环 就没有 拓扑排序
// 
vector<Node *> topologicalSort(Graph *graph)
{
    map<Node *, int> inMap;       // 存储节点与该节点的入度
    queue<Node *> queue;          // 存储入度为 0 的 节点
    vector<Node *> ans;
    for (auto it = graph->nodes.begin(); it != graph->nodes.end(); it++)
    {
        Node *curNode = it->second;
        inMap[curNode] = curNode->in;
        if (curNode->in == 0)
        {
            queue.push(curNode);
        }
    }

    while (!queue.empty())
    {
        Node *cur = queue.front();
        queue.pop();
        ans.push_back(cur);
        for (Node *next : cur->nexts)
        {
            inMap[next]--;
            if (inMap[next] == 0)
            {
                queue.push(next);
            }
        }
    }
    return ans;
}