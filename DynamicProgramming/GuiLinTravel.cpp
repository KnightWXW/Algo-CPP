#include <stdio.h>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <numeric>

using namespace std;

//      Huawei: 桂林旅游

//      桂林市在阳朔边开辟了若干个旅游景点。一个游船俱乐部在这些景点都设置了游船出租站。
//      游客可在这些游船出租站出租游船，并在下游的任何一个游船出租站归还游船，
//      从一个游船出租站到下游的游船出租站间的租金明码标价。
//      你的任务是为游客计算从起点到终点间最少租船费用。
//      输入：
//          n: 上游到下游有n个游船出租站
//          接下来 n 行：
//          从第 i (0 <= i <= n - 1)站到 j (i + 1 <= j <= n - 1)站的游船租金
//      输出：
//          游客从起点到终点间最少租船费用
//      输入样例1：
//          3
//          0 2 3 6
//          0 0 1 3
//          0 0 0 2
//          0 0 0 0
//      输出样例1：
//          5
//      输入样例2：
//          4
//          0 1 2 3 4
//          0 0 1 2 3
//          0 0 0 1 2
//          0 0 0 0 1
//          0 0 0 0 0
//      输出样例1：
//          4

void print2DVecElement(vector<vector<int>> vec);

int GuiLinTravel(vector<vector<int>> vec);

int main()
{
    vector<vector<int>> vec1 = {{0, 2, 3, 6},
                                {0, 0, 1, 3},
                                {0, 0, 0, 2},
                                {0, 0, 0, 0}};
    print2DVecElement(vec1);
    int ans1 = GuiLinTravel(vec1);
    printf("游客从起点到终点间最少租船费用为 %d\n", ans1);

    vector<vector<int>> vec2 = {{0, 1, 2, 3, 4},
                                {0, 0, 1, 2, 3},
                                {0, 0, 0, 1, 2},
                                {0, 0, 0, 0, 1},
                                {0, 0, 0, 0, 0}};
    print2DVecElement(vec2);
    int ans2 = GuiLinTravel(vec2);
    printf("游客从起点到终点间最少租船费用为 %d\n", ans2);
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

// 动态规划：
// Time: O(M * N)
// Space: O(1)
int GuiLinTravel(vector<vector<int>> vec)
{
    int l = vec.size();
    vector<vector<int>> arr(vec);
    int ans = INT_MAX;
    for (int i = 1; i < l; i++)
    {
        for (int j = i + 1; j < l; j++)
        {
            arr[i][j] += arr[i - 1][i];
        }
    }
    for (int i = 0; i < l - 1; i++)
    {
        ans = min(ans, arr[i][l - 1]);
    }
    return ans;
}