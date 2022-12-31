#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// 自定义排序：按 二维数组元素大小 按自定义的 列顺序 降序排列

vector<vector<int>> generateRandom2DVec(int low, int high, int row, int col);
void print2DVecElement(vector<vector<int>> vec);
void printPairVecElement(vector<pair<int, vector<int>>> arr);

bool cmp2DVec(pair<int, vector<int>> &p1, pair<int, vector<int>> &p2);

int main()
{
    vector<vector<int>> vec_A = generateRandom2DVec(0, 10, 5, 5);
    vector<vector<int>> vec_B;
    vec_B.assign(vec_A.begin(), vec_A.end());

    // 数组处理：
    vector<pair<int, vector<int>>> arr_A;
    for (int i = 0; i < vec_A.size(); i++)
    {
        arr_A.push_back(make_pair(i, vec_A[i]));
    }
    vector<pair<int, vector<int>>> arr_B;
    arr_B.assign(arr_A.begin(), arr_A.end());

    printf("数组未排序 前为：\n");
    print2DVecElement(vec_A);
    print2DVecElement(vec_B);
    printPairVecElement(arr_A);
    printPairVecElement(arr_B);

    // 排序：
    // 自定义比较器：
    sort(arr_A.begin(), arr_A.end(), cmp2DVec);
    // lambda表达式：
    sort(arr_B.begin(), arr_B.end(), [](pair<int, vector<int>> &p1, pair<int, vector<int>> &p2)
         {
            if(p1.second == p2.second){
                return p1.first < p2.first;
            }
            return p1.second > p2.second; });

    printf("自定义排序 后为：\n");
    printPairVecElement(arr_A);
    printPairVecElement(arr_B);
}

vector<vector<int>> generateRandom2DVec(int low, int high, int row, int col)
{
    srand((int)time(0));
    vector<vector<int>> vec;
    for (int i = 0; i < row; i++)
    {
        vector<int> tem;
        for (int j = 0; j < col; j++)
        {
            int v = (rand() % (high - low + 1)) + low;
            tem.push_back(v);
        }
        vec.push_back(tem);
    }
    return vec;
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

void printPairVecElement(vector<pair<int, vector<int>>> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        printf("%d : ", arr[i].first);
        for (int j = 0; j < arr[0].second.size(); j++)
        {
            printf("%d\t", arr[i].second[j]);
        }
        printf("\n");
    }
    printf("\n");
}

// 2D数组 从大到小排序：
bool cmp2DVec(pair<int, vector<int>> &p1, pair<int, vector<int>> &p2)
{
    if (p1.second == p2.second)
    {
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}