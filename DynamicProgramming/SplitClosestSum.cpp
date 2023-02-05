#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//      给定一个正数数组arr，请把 arr 中所有的 元素 分成两个集合，
//      尽量让两个集合的累加和相近。
//      返回：两个集合的累加和 在最接近的情况下，较小集合的累加和。

void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);
int splitClosestSumWithLimit_A(vector<int> vec);
int dfsSplitClosestSumWithLimit_A(vector<int> vec, int index, int target);
int splitClosestSumWithLimit_B(vector<int> vec);
int dfsSplitClosestSumWithLimit_B(vector<int> vec, int index, int target, int ** arr);
int splitClosestSumWithLimit_C(vector<int> vec);
int splitClosestSumWithLimit_D(vector<int> vec);

int main()
{

    vector<int> vec = generateRandomVec(0,100,20);
    printVecElement(vec);
    printf("暴力递归：%d\n", splitClosestSumWithLimit_A(vec));
    printf("记忆化搜索：%d\n", splitClosestSumWithLimit_B(vec));
    printf("动态规划：%d\n", splitClosestSumWithLimit_C(vec));
    printf("动态规划(空间优化)：%d\n", splitClosestSumWithLimit_D(vec));
}

void printVecElement(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

vector<int> generateRandomVec(int low, int high, int len)
{
    srand((int)time(0));
    vector<int> vec;
    for (int i = 0; i < len; i++)
    {
        int v = (rand() % (high - low + 1)) + low;
        vec.push_back(v);
    }
    return vec;
}

// 暴力递归：
// Time: O(2^N)
// Space: O(N)
int splitClosestSumWithLimit_A(vector<int> vec)
{
    int sumAll = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        sumAll += vec[i];
    }
    return dfsSplitClosestSumWithLimit_A(vec, 0, sumAll >> 1);
}

int dfsSplitClosestSumWithLimit_A(vector<int> vec, int index, int target)
{
    if (index >= vec.size())
    {
        return 0;
    }
    int p1 = dfsSplitClosestSumWithLimit_A(vec, index + 1, target);
    int p2 = 0;
    if (vec[index] <= target)
    {
        p2 = vec[index] + dfsSplitClosestSumWithLimit_A(vec, index + 1, target - vec[index]);
    }
    return max(p1, p2);
}

// 记忆化搜索：
// Time: O(2^N)
// Space: O(N)
int splitClosestSumWithLimit_B(vector<int> vec)
{
    int sumAll = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        sumAll += vec[i];
    }

    int target = sumAll >> 1; 

    int ** arr;
    arr = new int*[vec.size() + 1];
    for (int i = 0; i < vec.size() + 1; i++){
        arr[i] = new int[target + 1];
        for (int j = 0 ; j < target + 1; j++){
            arr[i][j] = 0;
        }
    }
    
    int ans = dfsSplitClosestSumWithLimit_B(vec, 0, sumAll >> 1, arr);

    for (int i = 0; i < vec.size() + 1; i++){
        free(arr[i]);
    }

    free(arr);

    return ans;
}

int dfsSplitClosestSumWithLimit_B(vector<int> vec, int index, int target, int ** arr)
{
    if (index >= vec.size())
    {
        return 0;
    }
    if (arr[index][target] > 0) {
        return arr[index][target];
    }
    int p1 = dfsSplitClosestSumWithLimit_B(vec, index + 1, target, arr);
    int p2 = 0;
    if (vec[index] <= target)
    {
        p2 = vec[index] + dfsSplitClosestSumWithLimit_B(vec, index + 1, target - vec[index], arr);
    }
    arr[index][target] = max(p1, p2);
    return max(p1, p2);
}

// 动态规划：
// Time: O(M * N)
// Space: O(M * N)
int splitClosestSumWithLimit_C(vector<int> vec)
{
    int sumAll = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        sumAll += vec[i];
    }

    int target = sumAll >> 1; 

    int ** dp;
    dp = new int*[target + 1];
    for (int i = 0; i < target + 1; i++){
        dp[i] = new int[vec.size() + 1];
        for (int j = 0; j < vec.size() + 1; j++){
            dp[i][j] = 0;
        }
    }
    
    for (int index = vec.size() - 1; index >= 0; index--){
        for (int tem = 0; tem < target + 1; tem++){
            int p1 = dp[tem][index + 1];
            int p2 = 0;
            if (vec[index] <= tem)
            {
                p2 = vec[index] + dp[tem - vec[index]][index + 1];
            }
            dp[tem][index] = max(p1, p2);
        }
    }
    int ans = dp[target][0];

    for (int i = 0 ; i < target + 1; i++){
        free(dp[i]);
    }
    free(dp);

    return ans;
}

// 动态规划（空间优化）：
// Time: O(M * N)
// Space: O(M)
int splitClosestSumWithLimit_D(vector<int> vec)
{
    int sumAll = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        sumAll += vec[i];
    }

    int target = sumAll >> 1; 

    int * dp;
    dp = new int[target + 1];
   
    
    for (int index = vec.size() - 1; index >= 0; index--){
        for (int tem = 0; tem < target + 1; tem++){
            int p1 = dp[tem];
            int p2 = 0;
            if (vec[index] <= tem)
            {
                p2 = vec[index] + dp[tem - vec[index]];
            }
            dp[tem] = max(p1, p2);
        }
    }
    int ans = dp[target];

    free(dp);

    return ans;
}