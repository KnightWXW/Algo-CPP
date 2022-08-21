#include <stdio.h>
#include <string>
#include <vector>
#include <string.h>
#include <unordered_map>
#include <stack>

using namespace std;

int findCircleNumArr(vector<vector<int>> &isConnected);
void print2DVecElement(vector<vector<int>> vec);

template <class V>
class UnionFindNode
{
public:
    V value;
    UnionFindNode(V v)
    {
        value = v;
    };
    ~UnionFindNode(){};
};

template <class V, class UnionFindNode>
class UnionFindMap
{
private:
    unordered_map<V, UnionFindNode> nodes;
    unordered_map<UnionFindNode, UnionFindNode> parents;
    unordered_map<UnionFindNode, V> sizeMap;

public:
    // 构造函数：
    UnionFindMap(vector<V> vec)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            UnionFindNode node = new UnionFindNode(vec[i]);
            nodes.insert({vec[i], node});
            parents.insert({node, node});
            sizeMap.insert({node, 1});
        }
    }

    // 析构函数：
    ~UnionFindMap()
    {
        nodes.clear();
        parents.clear();
        sizeMap.clear();
    }

    int findSet(int i)
    {
        stack<UnionFindNode> stack;
        UnionFindNode cur = nodes.find(i);
        while (parents[cur] != cur)
        {
            stack.push(cur);
            cur = parents[cur];
        }

        while (stack.empty() == false)
        {
            UnionFindNode tem = stack.top();
            parents[tem] = cur;
            stack.pop();
        }
        return cur.value;
    }

    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j)
    {
        int parentI = findSet(i);
        int parentJ = findSet(j);
        UnionFindNode nodeParentI = nodes[parentI];
        UnionFindNode nodeParentJ = nodes[parentJ];
        int sizeI = sizeMap[nodeParentI];
        int sizeJ = sizeMap[nodeParentJ];

        UnionFindNode maxNode = nodeParentI;
        UnionFindNode minNode = nodeParentJ;

        if (sizeI < sizeJ)
        {
            maxNode = nodeParentJ;
            minNode = nodeParentI;
        }

        parents.insert({minNode, maxNode});
        sizeMap.insert({maxNode, sizeI + sizeJ});
        sizeMap.remove(minNode);
    }

    int numberofSets()
    {
        return sizeMap.size();
    }
};

int main()
{
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    print2DVecElement(isConnected);
    printf("矩阵中 省份 的数量 为 %d 个。", findCircleNumArr(isConnected));
}

int findCircleNumArr(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    UnionFind unionfind = new UnionFind(isConnected);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (isConnected[i][j] == 1)
            {
                unionfind.unionSet(i, j);
            }
        }
    }
    return unionfind.numberofSets();
}

void print2DVecElement(vector<vector<int>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[0].size(); j++)
        {
            printf("%d\t", vec[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}