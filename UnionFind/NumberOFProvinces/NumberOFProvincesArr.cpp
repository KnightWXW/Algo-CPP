#include <stdio.h>
#include <string>
#include <vector>
#include <string.h>
#include <ctime>
#include <cstdlib>

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

class UnionFindArr
{
private:
    int *parents;
    int *size;
    int *help;
    int sets;

public:
    // 构造函数：
    UnionFindArr(int n)
    {
        parents = new int[n];
        size = new int[n];
        help = new int[n];
        sets = n;

        for (int i = 0; i < n; i++)
        {
            parents[i] = i;
            size[i] = 1;
        }
    }

    // 析构函数：
    ~UnionFindArr()
    {
        free(parents);
        free(size);
        free(help);
    }

    int findSet(int i)
    {
        int index = 0;
        while (i != parents[i])
        {
            help[index++] = i;
            i = parents[i];
        }

        index -= 1;
        while (index >= 0)
        {
            parents[help[index]] = i;
            index--;
        }
        return i;
    }

    void unionSet(int i, int j)
    {
        int parentI = findSet(i);
        int parentJ = findSet(j);

        if (parentI != parentJ)
        {
            if (size[parentI] >= size[parentJ])
            {
                size[parentI] += size[parentJ];
                parents[parentJ] = parentI;
            }
            else
            {
                size[parentJ] += size[parentI];
                parents[parentI] = parentJ;
            }
            sets--;
        }
    }

    int numberofSets()
    {
        return sets;
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
    UnionFindArr unionfind = UnionFindArr(n);
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