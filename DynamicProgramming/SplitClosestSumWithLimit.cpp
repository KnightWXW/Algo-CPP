#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>

using namespace std;

//      给定一个正数数组arr，请把 arr 中所有的数分成两个集合。
//      如果arr长度为偶数，两个集合 包含数的个数 要一样多。
//      如果arr长度为奇数，两个集合 包含数的个数 必须 只差一个。
//      请尽量让 两个集合 的 累加和 接近。
//      返回最接近的情况下，较小集合 的 累加和。

void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);
int DigitSum(vector<int> vec);
int splitClosestSumWithLimit_A_A(vector<int> vec);
int dfsSplitClosestSumWithLimit_A_A(vector<int> vec, int index, int cnt, int target);
int splitClosestSumWithLimit_A_B(vector<int> vec);
int dfsSplitClosestSumWithLimit_A_B(vector<int> vec, int index, int cnt, int target);
int splitClosestSumWithLimit_B_A(vector<int> vec);
int dfsSplitClosestSumWithLimit_B_A(vector<int> vec, int index, int cnt, int target, unordered_map<string,int> map);
int splitClosestSumWithLimit_B_B(vector<int> vec);
int dfsSplitClosestSumWithLimit_B_B(vector<int> vec, int index, int cnt, int target, int ***arr);
int splitClosestSumWithLimit_C(vector<int> vec);

int main()
{
    vector<int> vec = generateRandomVec(0, 10, 20);
    int sumAll = DigitSum(vec);
    printVecElement(vec);
    printf("数组元素的累加和为：%d\n", sumAll);
    printf("暴力递归(一)：%d\n", splitClosestSumWithLimit_A_A(vec));
    printf("暴力递归(二)：%d\n", splitClosestSumWithLimit_A_B(vec));
    printf("记忆化搜索(map存储)：%d\n", splitClosestSumWithLimit_B_A(vec));
    printf("记忆化搜索(数组存储)：%d\n", splitClosestSumWithLimit_B_B(vec));
    printf("动态规划：%d\n", splitClosestSumWithLimit_C(vec));
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

int DigitSum(vector<int> vec)
{
    int sum = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        sum += vec[i];
    }
    return sum;
}

// 暴力递归(一)：
// Time: O(2^N)
// Space: O(N)
int splitClosestSumWithLimit_A_A(vector<int> vec)
{
    int sumAll = DigitSum(vec);

    int cnt = vec.size() >> 1;
    int target = sumAll >> 1;

    if ((vec.size() & 1) == 0)
    {
        return dfsSplitClosestSumWithLimit_A_A(vec, 0, cnt, target);
    }
    else
    {
        return max(dfsSplitClosestSumWithLimit_A_A(vec, 0, cnt, target),
                   dfsSplitClosestSumWithLimit_A_A(vec, 0, cnt + 1, target));
    }
}

int dfsSplitClosestSumWithLimit_A_A(vector<int> vec, int index, int cnt, int target)
{
    if (cnt <= 0)
    {
        return 0;
    }
    if (index >= vec.size())
    {
        return 0;
    }

    // 选择1：不选择当前元素 vec[index]
    int p1 = dfsSplitClosestSumWithLimit_A_A(vec, index + 1, cnt, target);

    // 选择2：选择当前元素 vec[index]
    int p2 = 0;
    if (vec[index] <= target)
    {
        p2 = vec[index] + dfsSplitClosestSumWithLimit_A_A(vec, index + 1, cnt - 1, target - vec[index]);
    }

    return max(p1, p2);
}

// 暴力递归(二)：
// Time: O(2^N)
// Space: O(N)
int splitClosestSumWithLimit_A_B(vector<int> vec)
{
    int sumAll = DigitSum(vec);

    int target = sumAll >> 1;
    int cnt = vec.size() >> 1;

    if ((vec.size() & 1) == 0)
    {
        return dfsSplitClosestSumWithLimit_A_B(vec, 0, cnt, target);
    }
    else
    {
        return max(dfsSplitClosestSumWithLimit_A_B(vec, 0, cnt, target),
                   dfsSplitClosestSumWithLimit_A_B(vec, 0, cnt + 1, target));
    }
}

int dfsSplitClosestSumWithLimit_A_B(vector<int> vec, int index, int cnt, int target)
{
    if (index == vec.size())
    {
        if (cnt == 0)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }

    // 选择1：不选择当前元素 vec[index]
    int p1 = dfsSplitClosestSumWithLimit_A_B(vec, index + 1, cnt, target);

    // 选择2：选择当前元素 vec[index]
    int p2 = -1;
    int flag = -1;
    if (vec[index] <= target)
    {
        flag = dfsSplitClosestSumWithLimit_A_B(vec, index + 1, cnt - 1, target - vec[index]);
    }
    if (flag != -1)
    {
        p2 = vec[index] + flag;
    }

    return max(p1, p2);
}

// 记忆化搜索(map存储)：
// Time: O(2^N)
// Space: O(N)
int splitClosestSumWithLimit_B_A(vector<int> vec)
{
    int sumAll = DigitSum(vec);

    int cntAll = (vec.size() + 1) / 2;
    int cnt = vec.size() / 2;
    int target = sumAll / 2;

    unordered_map<string,int> map;

    int ans = 0;
    if ((vec.size() & 1) == 0)
    {
        ans = dfsSplitClosestSumWithLimit_B_A(vec, 0, cnt, target, map);
    }
    else
    {
        ans = max(dfsSplitClosestSumWithLimit_B_A(vec, 0, cnt, target, map),
                  dfsSplitClosestSumWithLimit_B_A(vec, 0, cnt + 1, target, map));
    }

    return ans;
}

int dfsSplitClosestSumWithLimit_B_A(vector<int> vec, int index, int cnt, int target, unordered_map<string,int> map)
{
    string key = to_string(index) + "_" + to_string(cnt) + "_" + to_string(target);
    if (index == vec.size())
    {
        if (cnt == 0)
        {
            map[key] = 0;
            return 0;
        }
        else
        {
            return -1;
        }
    }
    if (map.count(key))
    {
        return map[key];
    }

    // 选择1：不选择当前元素 vec[index]
    int p1 = dfsSplitClosestSumWithLimit_B_A(vec, index + 1, cnt, target, map);

    // 选择2：选择当前元素 vec[index]
    int p2 = -1;
    int flag = -1;
    if (vec[index] <= target)
    {
        flag = dfsSplitClosestSumWithLimit_B_A(vec, index + 1, cnt - 1, target - vec[index], map);
    }
    if (flag != -1)
    {
        p2 = flag + vec[index];
    }

    map[key] = max(p1,p2);

    return max(p1, p2);
}


// 记忆化搜索(数组存储)：
// Time: O(2^N)
// Space: O(N)
int splitClosestSumWithLimit_B_B(vector<int> vec)
{
    int sumAll = DigitSum(vec);

    int cntAll = (vec.size() + 1) / 2;
    int cnt = vec.size() / 2;
    int target = sumAll / 2;

    int ***arr;
    arr = new int **[vec.size() + 1];
    for (int i = 0; i < vec.size() + 1; i++)
    {
        arr[i] = new int *[cntAll + 1];
        for (int j = 0; j < cntAll + 1; j++)
        {
            arr[i][j] = new int[target + 1];
            for (int t = 0; t < target + 1; t++)
            {
                arr[i][j][t] = -1;
            }
        }
    }

    int ans = 0;
    if ((vec.size() & 1) == 0)
    {
        ans = dfsSplitClosestSumWithLimit_B_B(vec, 0, cnt, target, arr);
    }
    else
    {
        ans = max(dfsSplitClosestSumWithLimit_B_B(vec, 0, cnt, target, arr),
                  dfsSplitClosestSumWithLimit_B_B(vec, 0, cnt + 1, target, arr));
    }

    for (int i = 0; i < vec.size() + 1; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return ans;
}

int dfsSplitClosestSumWithLimit_B_B(vector<int> vec, int index, int cnt, int target, int ***arr)
{
    if (index == vec.size())
    {
        if (cnt == 0)
        {
            arr[index][cnt][target] = 0;
            return 0;
        }
        else
        {
            return -1;
        }
    }
    if (arr[index][cnt][target] >= 0)
    {
        return arr[index][cnt][target];
    }

    // 选择1：不选择当前元素 vec[index]
    int p1 = dfsSplitClosestSumWithLimit_B_B(vec, index + 1, cnt, target, arr);

    // 选择2：选择当前元素 vec[index]
    int p2 = -1;
    int flag = -1;
    if (vec[index] <= target)
    {
        flag = dfsSplitClosestSumWithLimit_B_B(vec, index + 1, cnt - 1, target - vec[index], arr);
    }
    if (flag != -1)
    {
        p2 = flag + vec[index];
    }

    arr[index][cnt][target] = max(p1, p2);

    return max(p1, p2);
}

// 动态规划：
// Time: O(M * N)
// Space: O(M * N)
int splitClosestSumWithLimit_C(vector<int> vec)
{
    int sumAll = DigitSum(vec);

    int cntAll = (vec.size() + 1) >> 1;
    int cnt = vec.size() >> 1;
    int target = sumAll >> 1;

    int ***dp;
    dp = new int **[vec.size() + 1];
    for (int i = 0; i < vec.size() + 1; i++)
    {
        dp[i] = new int *[cntAll + 1];
        for (int j = 0; j < cntAll + 1; j++)
        {
            dp[i][j] = new int[target + 1];
        }
    }

    for (int i = 0; i < target + 1; i++)
    {
        dp[vec.size()][0][i] = 0;
    }

    for (int index = vec.size() - 1; index >= 0; index--)
    {
        for (int k = 0; k < cntAll + 1; k++)
        {
            for (int t = 0; t < target + 1; t++)
            {
                int p1 = dp[index + 1][k][t];

                int p2 = -1;
                int flag = -1;
                if (k - 1 >= 0 && vec[index] <= t)
                {
                    flag = dp[index + 1][k - 1][t - vec[index]];
                }
                if (flag != -1)
                {
                    p2 = vec[index] + flag;
                }

                dp[index][k][t] = max(p1, p2);
            }
        }
    }

    int ans = 0;
    if ((vec.size() & 1) == 0)
    {
        ans = dp[0][cnt][target];
    }
    else
    {
        ans = max(dp[0][cnt][target], dp[0][cnt + 1][target]);
    }

    for (int i = 0; i < vec.size() + 1; i++)
    {
        free(dp[i]);
    }
    free(dp);

    return ans;
}