#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

//      LeetCode 135. 分发糖果

//      链接：https://leetcode.cn/problems/candy/

//      n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。
//      你需要按照以下要求，给这些孩子分发糖果：
//      每个孩子至少分配到 1 个糖果。
//      相邻两个孩子评分更高的孩子会获得更多的糖果。
//      请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。
//      示例 1：
//          输入：ratings = [1,0,2]
//          输出：5
//          解释：你可以分别给第一个、第二个、第三个孩子分发 2、1、2 颗糖果。
//      示例 2：
//          输入：ratings = [1,2,2]
//          输出：4
//          解释：你可以分别给第一个、第二个、第三个孩子分发 1、2、1 颗糖果。
//              第三个孩子只得到 1 颗糖果，这满足题面中的两个条件。
//      提示：
//          n == ratings.length
//          1 <= n <= 2 * 104
//          0 <= ratings[i] <= 2 * 104

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVec(vector<int> &vec);

int CandyDistribution(vector<int> &ratings);

int main()
{
    int n = generateRandomNum(1, 100);
    vector<int> vec = generateRandomVec(1, 300, n);
    printVec(vec);
    int ans = CandyDistribution(vec);
    printf("需要准备的 最少糖果数目为 %d。", ans);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

vector<int> generateRandomVec(int low, int high, int len)
{
    vector<int> vec;
    srand(time(0));
    for (int i = 0; i < len; i++)
    {
        int v = (rand() % (high - low + 1)) + low;
        vec.push_back(v);
    }
    return vec;
}

void printVec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int CandyDistribution(vector<int> &ratings)
{
    int l = ratings.size();
    int ans = 0;

    vector<int> leftArr(l, 1);
    for (int i = 1; i < l; i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            leftArr[i] = leftArr[i - 1] + 1;
        }
    }

    vector<int> rightArr(l, 1);
    for (int i = l - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
        {
            rightArr[i] = rightArr[i + 1] + 1;
        }
    }

    for (int i = 0; i < l; i++)
    {
        ans += max(leftArr[i], rightArr[i]);
    }
    return ans;
}