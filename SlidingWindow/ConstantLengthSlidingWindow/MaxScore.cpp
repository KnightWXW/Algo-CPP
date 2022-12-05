#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <numeric>

using namespace std;

//      LeetCode 1423. 可获得的最大点数

//      链接：https://leetcode.cn/problems/maximum-points-you-can-obtain-from-cards/

//      几张卡牌 排成一行，每张卡牌都有一个对应的点数。
//      点数由整数数组 cardPoints 给出。
//      每次行动，你可以从行的开头或者末尾拿一张卡牌，最终你必须正好拿 k 张卡牌。
//      你的点数就是你拿到手中的所有卡牌的点数之和。
//      给你一个整数数组 cardPoints 和整数 k，请你返回可以获得的最大点数。

//      示例 1：
//          输入：cardPoints = [1,2,3,4,5,6,1], k = 3
//          输出：12
//          解释：第一次行动，不管拿哪张牌，你的点数总是 1 。但是，先拿最右边的卡牌将会最大化你的可获得点数。最优策略是拿右边的三张牌，最终点数为 1 + 6 + 5 = 12 。
//      示例 2：
//          输入：cardPoints = [2,2,2], k = 2
//          输出：4
//          解释：无论你拿起哪两张卡牌，可获得的点数总是 4 。
//      示例 3：
//          输入：cardPoints = [9,7,7,9,7,7,9], k = 7
//          输出：55
//          解释：你必须拿起所有卡牌，可以获得的点数为所有卡牌的点数之和。
//      示例 4：
//          输入：cardPoints = [1,1000,1], k = 1
//          输出：1
//          解释：你无法拿到中间那张卡牌，所以可以获得的最大点数为 1 。
//      示例 5：
//          输入：cardPoints = [1,79,80,1,1,1,200,1], k = 3
//          输出：202
//      提示：
//          1 <= cardPoints.length <= 10^5
//          1 <= cardPoints[i] <= 10^4
//          1 <= k <= cardPoints.length

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

int MaxScore(vector<int> &cardPoints, int k);

int main()
{
    int n = generateRandomNum(1, 20);
    vector<int> vec = generateRandomVec(0, 20, n);
    int k = generateRandomNum(1, n);
    printVecElement(vec);
    int ans = MaxScore(vec, k);
    printf("拿 %d 张卡牌, 可以获得的最大点数为 %d\n", k, ans);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
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

// 从开头和末尾拿 k 张卡牌，所以最后剩下的必然是连续的 n−k 张卡牌。
// 通过求出剩余卡牌点数之和的最小值，从而求出拿走卡牌点数之和的最大值。
int MaxScore(vector<int> &cardPoints, int k)
{
    int l = cardPoints.size();
    int sum = 0;
    int ans = INT_MAX;
    int sumAll = accumulate(cardPoints.begin(), cardPoints.end(),0);
    for(int i = 0; i < l - k; i++){
        sum += cardPoints[i];
    }
    ans = min(ans, sum);
    for(int i = 0; i < k; i++){
        sum -= cardPoints[i];
        sum += cardPoints[i + l - k];
        ans = min(ans, sum);
    }
    return sumAll - ans;
}