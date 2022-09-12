#include <stdio.h>
#include <string>
#include <vector>
#include <string.h>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <stack>

using namespace std;

//      LeetCode 547. 省份数量

//      链接：https://leetcode.cn/problems/number-of-provinces/

//      有 n 个城市，其中一些彼此相连，另一些没有相连。
//      如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，
//      那么城市 a 与城市 c 间接相连。
//      省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。
//      给你一个 n x n 的矩阵 isConnected ，
//      其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，
//      而 isConnected[i][j] = 0 表示二者不直接相连。
//      返回矩阵中 省份 的数量。

//      示例 1：
//      输入：isConnected = [[1,1,0],[1,1,0],[0,0,1]]
//      输出：2

//      示例 2：
//      输入：isConnected = [[1,0,0],[0,1,0],[0,0,1]]
//      输出：3

//      提示：
//          1 <= n <= 200
//          n == isConnected.length
//          n == isConnected[i].length
//          isConnected[i][j] 为 1 或 0
//          isConnected[i][i] == 1
//          isConnected[i][j] == isConnected[j][i]

int findCircleNumMap(vector<vector<int>> &isConnected);
int generateRandomNum(int low, int high);
void print2DVecElement(vector<vector<int>> vec);
vector<vector<int>> generateRandom2DVec(int low, int high, int row, int col);

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
class UnionFindOfMap
{
private:
    unordered_map<V, UnionFindNode> nodes;
    unordered_map<UnionFindNode, UnionFindNode> parentsMap;
    unordered_map<UnionFindNode, V> sizeMap;

public:
    // 构造函数：
    UnionFindOfMap(int n)
    {
        for (int i = 0; i < n; i++)
        {
            UnionFindNode node = new UnionFindNode(i);
            nodes.insert({i, node});
            parentsMap.insert({node, node});
            sizeMap.insert({node, 1});
        }
    }

    // 析构函数：
    ~UnionFindOfMap()
    {
        nodes.clear();
        parentsMap.clear();
        sizeMap.clear();
    }

    int findSet(int i)
    {
        stack<UnionFindNode> stack;
        UnionFindNode cur = nodes.find(i);
        while (parentsMap[cur] != cur)
        {
            stack.push(cur);
            cur = parentsMap[cur];
        }

        while (stack.empty() == false)
        {
            UnionFindNode tem = stack.top();
            parentsMap[tem] = cur;
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

        parentsMap.insert({minNode, maxNode});
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
    int n = generateRandomNum(1, 10);
    vector<vector<int>> isConnected = generateRandom2DVec(0, 1, n, n);
    print2DVecElement(isConnected);
    printf("矩阵中 省份 的数量 为 %d 个。", findCircleNumMap(isConnected));
}

int findCircleNumMap(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    UnionFindOfMap<int, UnionFindNode<int>> unionfind = UnionFindOfMap<int, UnionFindNode<int>>::UnionFindMap(n);
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

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

void print2DVecElement(vector<vector<int>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for(int j = 0 ; j < vec[0].size(); j++)
        {
            printf("%d\t", vec[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

vector<vector<int>> generateRandom2DVec(int low, int high, int row, int col)
{
    srand((int)time(0));
    vector<vector<int>> vec;
    for (int i = 0; i < row; i++)
    {
        vector<int> tem; 
        for( int j = 0 ; j < col ; j++){
            int v = (rand() % (high - low + 1)) + low;
            tem.push_back(v);
        }
        vec.push_back(tem);
    }
    return vec;
}