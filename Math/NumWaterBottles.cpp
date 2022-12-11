#include <stdio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

//      LeetCode 1518. 换水问题

//      链接：https://leetcode.cn/problems/water-bottles/

//      超市正在促销，你可以用 numExchange 个空水瓶从超市兑换一瓶水。
//      最开始，你一共购入了 numBottles 瓶水。
//      如果喝掉了水瓶中的水，那么水瓶就会变成空的。
//      给你两个整数 numBottles 和 numExchange，返回你 最多 可以喝到多少瓶水。
//      示例 1：
//          输入：numBottles = 9, numExchange = 3
//          输出：13
//          解释：你可以用 3 个空瓶兑换 1 瓶水。
//          所以最多能喝到 9 + 3 + 1 = 13 瓶水。
//      示例 2：
//          输入：numBottles = 15, numExchange = 4
//          输出：19
//          解释：你可以用 4 个空瓶兑换 1 瓶水。
//          所以最多能喝到 15 + 3 + 1 = 19 瓶水。
//      提示：
//          1 <= numBottles <= 100
//          2 <= numExchange <= 100

int generateRandomNum(int low, int high);

int NumWaterBottles_A(int numBottles, int numExchange);
int NumWaterBottles_B(int numBottles, int numExchange);

int main()
{
    int numBottles = generateRandomNum(1, 100);
    int numExchange = generateRandomNum(1, numBottles);
    int ans_A = NumWaterBottles_A(numBottles, numExchange);
    int ans_B = NumWaterBottles_B(numBottles, numExchange);
    printf("购入了 %d 瓶水, 用 %d 个空水瓶兑换一瓶水, \n最多 可以喝到 %d 瓶水\n", numBottles, numExchange, ans_A);
    printf("购入了 %d 瓶水, 用 %d 个空水瓶兑换一瓶水, \n最多 可以喝到 %d 瓶水\n", numBottles, numExchange, ans_B);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

// 模拟
// Time: O(b/e)
// Space: O(1)
int NumWaterBottles_A(int numBottles, int numExchange)
{
    int bottles = numBottles;
    int drunkBottles = bottles;
    while (bottles >= numExchange)
    {
        int exchangeCnt = bottles / numExchange;
        bottles -= numExchange * exchangeCnt;
        bottles += exchangeCnt;
        drunkBottles += exchangeCnt;
    }
    return drunkBottles;
}

// 数学
// Time: O(1)
// Space: O(1)
int NumWaterBottles_B(int numBottles, int numExchange)
{
    if (numBottles >= numExchange)
    {
        return (numBottles - numExchange) / (numExchange - 1) + 1 + numBottles;
    }
    else
    {
        return numBottles;
    }
}
