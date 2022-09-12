#include <stdio.h>
#include <vector>
#include <stack>
#include "W:\Algo-CPP\Graph\Structure\Graph.cpp"

void dfs(Node* node);

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
    dfs(graph->nodes[1]);
    dfs(graph->nodes[2]);
}

// DFS: 深度优先遍历
// Time: O(N + E)       (N: Node数目  E：Edge数目)
// Space: O(N)          (N: Node数目)
// 使用 set 来 去重，防止环路:
// stack中 存放的是 当前遍历 的 路径：
void dfs(Node *node)
{
    if(node == NULL){
        return ;
    }
    stack<Node *> stack;
    set<Node *> set;
    stack.push(node);
    set.insert(node);
    printf("%d ", node->value);

    while (!stack.empty())
    {
        Node *cur = stack.top();
        stack.pop();
        for (Node* tem : cur->nexts)
        {
            if (set.find(tem) == set.end())
            {
                stack.push(cur);
                stack.push(tem);
                set.insert(tem);
                printf("%d ", tem->value);
                break;
            }
        }
    }
    printf("\n");
}