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

//      Kruskal算法：
//          贪心：将图中的每个 edge 按照 权重大小 进行排序，
//          每次从边集中取出 权重最小 且 两个顶点都不在 同一个集合 的 边 加入 生成树 中
//          注意：如果这两个顶点都在同一集合内，说明已经通过其他边相连，
//          因此如果将这个边添加到生成树中，那么就会形成环！
//          重复直至所有边被处理过。

//          可以通过 并查集 实现。

//      时间复杂度：O(ElogE)  [边的排序]
//      空间复杂度：O(n)      [并查集]

//      适合 稀疏图

vector<Edge *> kruskal(Graph *graph);
void printGraphEdge(vector<Edge *> &vec);

template <typename data>
class UnionFind
{
public:
    map<data, data> parentsMap;
    map<data, int> sizeMap;

    UnionFind(vector<data> vec)
    {
        parentsMap.clear();
        sizeMap.clear();
        for (int i = 0; i < vec.size(); i++)
        {
            parentsMap[vec[i]] = vec[i];
            sizeMap[vec[i]] = 1;
        }
    }

    data findSet(data x)
    {
        stack<data> stack;
        while (parentsMap[x] != x)
        {
            stack.push(x);
            x = parentsMap[x];
        }

        while (!stack.empty())
        {
            data tem = stack.top();
            parentsMap[tem] = x;
            stack.pop();
        }
        return x;
    }

    void unionSet(data x, data y)
    {
        data parentX = findSet(x);
        data parentY = findSet(y);

        if (parentX != parentY)
        {
            int sizeX = sizeMap[parentX];
            int sizeY = sizeMap[parentY];
            if (sizeX > sizeY)
            {
                parentsMap[parentY] = parentX;
                sizeMap[parentX] = sizeX + sizeY;
                sizeMap.erase(parentY);
            }
            else
            {
                parentsMap[parentX] = parentY;
                sizeMap[parentY] = sizeY + sizeX;
                sizeMap.erase(parentX);
            }
        }
    }

    bool isSameSet(data x, data y)
    {
        return findSet(x) == findSet(y);
    }
};

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
    vector<Edge *> ans = kruskal(graph);
    printf("(Kruskal 算法)最小生成树 的 所选边 为：\n");
    printGraphEdge(ans);
}

struct cmp
{
    bool operator()(Edge *e1, Edge *e2)
    {
        return e1->weight > e2->weight;
    }
};

vector<Edge *> kruskal(Graph *graph)
{
    vector<Node *> vec;
    for (auto it = graph->nodes.begin(); it != graph->nodes.end(); it++)
    {
        vec.push_back(it->second);
    }
    UnionFind<Node *> unionfind = UnionFind<Node *>(vec);
    priority_queue<Edge *, vector<Edge *>, cmp> queue;
    
    for (auto e : graph->edges)
    {
        queue.push(e);
    }
    set<Edge *> set;

    while (!queue.empty())
    {
        Edge *e = queue.top();
        queue.pop();
        if (!unionfind.isSameSet(e->from, e->to))
        {
            set.insert(e);
            unionfind.unionSet(e->from, e->to);
        }
    }

    vector<Edge *> ans(set.begin(), set.end());
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