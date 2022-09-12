#include <stdio.h>
#include <vector>
#include <queue>
#include <set>
#include "W:\Algo-CPP\Graph\Structure\Graph.cpp"

void bfs(Node* node);

int main()
{
    // mat 给出 所有的边
    // mat[i][0] : 该边的权重 weight
    // mat[i][1] : 该边的 出发节点
    // mat[i][2] : 该边的 终止节点
    vector<vector<int>> mat{{1, 1, 2},
                            {1, 2, 1},
                            {1, 1, 3},
                            {1, 1, 5},
                            {1, 2, 4},
                            {1, 4, 5}};
    //      3     5
    //      ^   ^   ^
    //      |  /     \
    //      | /       \
    //      1<--->2---->4
    Graph *graph = CreateGraph(mat);
    // BFS 广度优先遍历
    bfs(graph->nodes[1]);
    bfs(graph->nodes[2]);
}

// BFS:宽度(广度)优先遍历
// Time: O(N + E)       (N: Node数目  E：Edge数目)
// Space: O(N)          (N: Node数目)
// 使用 set 来 去重，防止环路
void bfs(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    queue<Node *> queue;
    set<Node *> set;

    queue.push(node);
    set.insert(node);
    while (!queue.empty())
    {
        Node *cur = queue.front();
        queue.pop();
        printf("%d  ", cur->value);
        for (auto next : cur->nexts)
        {
            if (set.find(next) == set.end())
            {
                queue.push(next);
                set.insert(next);
            }
        }
    }
    printf("\n");
}