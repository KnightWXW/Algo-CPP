#include <stdio.h>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

int findCircleNumMap(vector<vector<int>> &isConnected);
void print2DVecElement(vector<vector<int>> vec);

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
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
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