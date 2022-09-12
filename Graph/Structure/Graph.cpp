#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stdlib.h>

using namespace std;

// 类声明：
class Node;
class Edge;
class Graph;

// 函数声明：
Graph *CreateGraph(vector<vector<int>> matrix);

class Node
{
public:
    int value;            // 该点的值
    int in;               // 入度：多少个边 指向 此结点
    int out;              // 出度：此结点 指向 多少条边
    vector<Node *> nexts; // 从此结点出发 可得到的 邻居结点
    vector<Edge *> edges; // 从此结点出发，发散出边的集合

    Node(int val)
    {
        value = val;
        in = 0;
        out = 0;
    }
};

class Edge
{
public:
    int weight; // 该边的权重值
    Node *from; // 该边的出发节点
    Node *to;   // 该边的终止节点
    Edge();
    Edge(int weightVal, Node *fromNode, Node *toNode)
    {
        weight = weightVal;
        from = fromNode;
        to = toNode;
    }
};

class Graph
{
public:
    map<int, Node *> nodes; // 节点序号和结点的映射集合
    set<Edge *> edges;      // 边的集合
};

// 图 的 接口函数：
// mat 给出 所有的边
// mat[i][0] : 该边的权重 weight
// mat[i][1] : 该边的 出发节点
// mat[i][2] : 该边的 终止节点
Graph *CreateGraph(vector<vector<int>> mat)
{
    Graph *graph = new Graph();
    for (int i = 0; i < mat.size(); i++)
    {
        int weight = mat[i][0];
        int from = mat[i][1];
        int to = mat[i][2];
        if (graph->nodes.find(from) == graph->nodes.end())
        {
            graph->nodes[from] = new Node(from);
        }

        if (graph->nodes.find(to) == graph->nodes.end())
        {
            graph->nodes[to] = new Node(to);
        }

        Node *fromNode = graph->nodes[from];
        Node *toNode = graph->nodes[to];

        Edge *newEdge = new Edge(weight, fromNode, toNode);
        fromNode->nexts.push_back(toNode);
        fromNode->out++;
        fromNode->edges.push_back(newEdge);
        toNode->in++;
        graph->edges.insert(newEdge);
    }
    return graph;
}