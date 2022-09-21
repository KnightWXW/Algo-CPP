#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//      LeetCode 1326. 灌溉花园的最少水龙头数目

//      链接：https://leetcode.cn/problems/minimum-number-of-taps-to-open-to-water-a-garden/

//      在 x 轴上有一个一维的花园。花园长度为 n，从点 0 开始，到点 n 结束。
//      花园里总共有 n + 1 个水龙头，分别位于 [0, 1, ..., n] 。
//      给你一个整数 n 和一个长度为 n + 1 的整数数组 ranges ，
//      其中 ranges[i] （下标从 0 开始）表示：
//      如果打开点 i 处的水龙头，可以灌溉的区域为 [i -  ranges[i], i + ranges[i]] 。
//      请你返回可以灌溉整个花园的 最少水龙头数目 。
//      如果花园始终存在无法灌溉到的地方，请你返回 -1 。

//      示例 1：
//      输入：n = 5, ranges = [3,4,1,1,0,0]
//      输出：1
//          解释：
//          点 0 处的水龙头可以灌溉区间 [-3,3]
//          点 1 处的水龙头可以灌溉区间 [-3,5]
//          点 2 处的水龙头可以灌溉区间 [1,3]
//          点 3 处的水龙头可以灌溉区间 [2,4]
//          点 4 处的水龙头可以灌溉区间 [4,4]
//          点 5 处的水龙头可以灌溉区间 [5,5]
//      只需要打开点 1 处的水龙头即可灌溉整个花园 [0,5] 。

//      示例 2：
//      输入：n = 3, ranges = [0,0,0,0]
//      输出：-1
//      解释：即使打开所有水龙头，你也无法灌溉整个花园。

//      提示：

//          1 <= n <= 104
//          ranges.length == n + 1
//          0 <= ranges[i] <= 100

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

int minTaps(int n, vector<int> &ranges);

int main()
{
    int l = generateRandomNum(1, 20);
    vector<int> arr = generateRandomVec(0, 10, l);
    printf("arr数组 元素为: ");
    printVecElement(arr);
    printf("灌溉 长度为 %d 的整个花园的 最少水龙头数目 %d。\n", l - 1, minTaps(l - 1, arr));
}

int generateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
    return (rand() % (high - low + 1)) + low;
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

// 贪心：
//      1、arr 存储 当前位置 能到达的最远位置
//      2、转化 为 跳跃问题II
// Time: O(N)
// Space: O(N)
int minTaps(int n, vector<int> &ranges)
{
    vector<int> arr(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        int left = max(i - ranges[i], 0);
        int right = min(i + ranges[i], n);
        arr[left] = max(arr[left], right);
    }

    int end = 0;
    int maxPos = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        maxPos = max(maxPos, arr[i]);
        if (i == end)
        {
            if (maxPos <= i)
            {
                return -1;
            }
            end = maxPos;
            cnt++;
        }
    }
    return cnt;
}