#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include "W:\Algo-CPP\Graph\Structure\Graph.cpp"

//      生成树（spanning tree）是一个图的子图，它的定义如下:
//              它是一颗无根树
//              它包含原图的所有节点

//      当图中每条边都存在权重时,这时候我们从图中生成一棵树(n - 1 条边)时,
//      生成这棵树的总代价就是每条边的权重相加之和。

//      Prime算法：
//          贪心：将一点加入集合Set，根据邻边更新其他邻点到该集合的距离。
//          找出最短距离，并将对应邻点加入集合Set。
//          重复以上步骤，加入集合Set外的顶点，直至加入所有点或者发现非联通。
//      时间复杂度：O(V^2)
//      空间复杂度：O(V)
//              V: 节点 的 个数

//      适合 稠密图

vector<Edge *> dijkstra(Graph *graph);
void printGraphEdge(vector<Edge *> &vec);

int main()
{
    // mat 给出 所有的边
    // mat[i][0] : 该边的权重 weight
    // mat[i][1] : 该边的 出发节点
    // mat[i][2] : 该边的 终止节点
    vector<vector<int>> mat{{2, 1, 2},
                            {2, 2, 1},
                            {1, 2, 3},
                            {1, 3, 2},
                            {4, 1, 3},
                            {4, 3, 1},
                            {2, 2, 5},
                            {2, 5, 2},
                            {6, 3, 5},
                            {6, 5, 3},
                            {7, 1, 4},
                            {7, 4, 1},
                            {1, 3, 4},
                            {1, 4, 3}};

    Graph *graph = CreateGraph(mat);
    vector<Edge *> ans = dijkstra(graph);
    printf("(Prime 算法)最小生成树 的 所选边 为：\n");
    printGraphEdge(ans);
}

struct cmp
{
    bool operator()(Edge *e1, Edge *e2)
    {
        return e1->weight > e2->weight;
    }
};

vector<Edge *> dijkstra(Graph *graph)
{
    // 小根堆 存储 解锁的边：
    priority_queue<Edge *, vector<Edge *>, cmp> queue;
    // set 存储 解锁的点：
    set<Node*> edgeSet;
    // 存储 答案边：
    set<Edge*> resSet;

    for (auto it = graph->nodes.begin(); it != graph->nodes.end(); it++)
    {
        // curNode: 最开始的节点：
        Node *curNode = it->second;
        if (edgeSet.find(curNode) == edgeSet.end())
        {
            edgeSet.insert(curNode);
            for (auto e : curNode->edges)
            {
                queue.push(e);
            }

            while (!queue.empty())
            {
                Edge *e = queue.top();
                queue.pop();
                Node *toNode = e->to;
                if (edgeSet.find(toNode) == edgeSet.end())
                {
                    edgeSet.insert(toNode);
                    resSet.insert(e);
                    for (auto nextEdge : toNode->edges)
                    {
                        queue.push(nextEdge);
                    }
                }
            }
        }
        // 加入break 不预防森林
        // 不加break 预防森林
        // break;
    }

    vector<Edge *> ans(resSet.begin(), resSet.end());
    return ans;
}

void printGraphEdge(vector<Edge *> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("weight: %d ", vec[i]->weight);
        printf("from: %d ", vec[i]->from->value);
        printf("to: %d \n", vec[i]->to->value);
    }
    printf("\n");
}