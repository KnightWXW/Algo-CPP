#include <stdio.h>
#include <string>
#include <vector>
#include <string.h>
#include <unordered_map>
#include <stack>

using namespace std;

int findCircleNumArr(vector<vector<int>> &isConnected);
void print2DVecElement(vector<vector<int>> vec);

template <class data>
class UnionFindOfMap
{
private:
    unordered_map<data, data> parentsMap;
    unordered_map<data, data> sizeMap;

public:
    // 构造函数：
    UnionFindOfMap(vector<data> vec)
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

    bool isSameSet(int x, int y)
    {
        return findSet(x) == findSet(y);
    }

    void unionSet(int x, int y)
    {
        int parentX = findSet(x);
        int parentY = findSet(y);

        if (parentX != parentY)
        {
            if (sizeMap[parentX] > sizeMap[parentY])
            {
                parentsMap[parentY] = parentX;
                sizeMap[parentX] += sizeMap[parentY];
                sizeMap.erase(parentY);
            }
            else
            {
                parentsMap[parentX] = parentY;
                sizeMap[parentY] += sizeMap[parentX];
                sizeMap.erase(parentX);
            }
        }
    }

    int numberofSets()
    {
        return sizeMap.size();
    }
};

// int main()
// {
//     vector<vector<int>> isConnected = {1, 5, 3};
//     print2DVecElement(isConnected);
//     printf("矩阵中 省份 的数量 为 %d 个。", findCircleNumArr(isConnected));
// }