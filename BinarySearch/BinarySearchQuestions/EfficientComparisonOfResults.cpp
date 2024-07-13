#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;

//      Huawei: 结果高效对比

//      终端某产品的车间工人位置视作一个矩阵，记为二维数组scores
//      scores[row][col]代表此位置工人的该月的完成件数
//      每位工人都想计算同行同列中一共多少人比自己完成件数多，
//      最后把计算结果记录在一个新的二维数组的对应位置上，返回该二维数组。
//      示例1：
//          输入：scores = [[10, 20], [30, 10]]
//          输出：[[2, 0], [0, 2]]

int generateRandomNum(int low, int high);
void print2DVecElement(vector<vector<int>> vec);
vector<vector<int>> generateRandom2DVec(int low, int high, int row, int col);

int BinarySearchEfficientComparison(vector<int> arr, int num);
vector<vector<int>> EfficientComparisonOfResults(vector<vector<int>> scores);

int main()
{
    int row = generateRandomNum(1, 10);
    vector<vector<int>> vec = generateRandom2DVec(1, 100, row, row);
    printf("二维数组元素为：\n");
    print2DVecElement(vec);
    vector<vector<int>> ans_A = EfficientComparisonOfResults(vec);
    printf("结果二维数组为：\n");
    print2DVecElement(ans_A);
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
        for (int j = 0; j < vec[0].size(); j++)
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
        for (int j = 0; j < col; j++)
        {
            int v = (rand() % (high - low + 1)) + low;
            tem.push_back(v);
        }
        vec.push_back(tem);
    }
    return vec;
}

// 二分：查找数组中 >= num 的元素个数
// Time：O(logN)
// Space：O(1)
int BinarySearchEfficientComparison(vector<int> arr, int num)
{
    int l = arr.size();
    int left = 0;
    int right = l - 1;
    int ans = 0;
    sort(arr.begin(), arr.end());
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if (arr[mid] > num)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    if (left >= arr.size())
    {
        return -1;
    }
    return left;
}

vector<vector<int>> EfficientComparisonOfResults(vector<vector<int>> scores)
{
    int l = scores.size();
    vector<vector<int>> ans(l, vector<int>(l, 0));
    for (int i = 0; i < l; i++)
    {
        vector<int> arr = scores[i];
        for (int j = 0; j < l; j++)
        {
            int index = BinarySearchEfficientComparison(arr, scores[i][j]);
            int cnt = l - index;
            if (index == -1)
            {
                cnt = 0;
            }
            ans[i][j] += cnt;
        }
    }

    for (int j = 0; j < l; j++)
    {
        vector<int> arr(l, 0);
        for (int i = 0; i < l; i++)
        {
            arr[i] = scores[i][j];
        }
        for (int i = 0; i < l; i++)
        {
            int index = BinarySearchEfficientComparison(arr, scores[i][j]);
            int cnt = l - index;
            if (index == -1)
            {
                cnt = 0;
            }
            ans[i][j] += cnt;
        }
    }
    return ans;
}