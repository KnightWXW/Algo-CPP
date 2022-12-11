#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//      LeetCode 605. 种花问题

//      链接：https://leetcode.cn/problems/can-place-flowers/

//      假设有一个很长的花坛，一部分地块种植了花，另一部分却没有。
//      可是，花不能种植在相邻的地块上，它们会争夺水源，两者都会死去。

//      给你一个整数数组 flowerbed 表示花坛，由若干 0 和 1 组成，
//      其中 0 表示没种植花，1 表示种植了花。另有一个数 n ，
//      能否在不打破种植规则的情况下种入 n 朵花？
//      能则返回 true ，不能则返回 false。

//      示例 1：
//          输入：flowerbed = [1,0,0,0,1], n = 1
//          输出：true
//      示例 2：
//          输入：flowerbed = [1,0,0,0,1], n = 2
//          输出：false
//      提示：
//          1 <= flowerbed.length <= 2 * 104
//          flowerbed[i] 为 0 或 1
//          flowerbed 中不存在相邻的两朵花
//          0 <= n <= flowerbed.length

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

bool CanPlaceFlowers(vector<int> &flowerbed, int n);
void printBool(bool b);

int main()
{
    int n = generateRandomNum(1, 30);
    int flowers = generateRandomNum(1, n / 2 + 1);
    vector<int> arr = generateRandomVec(0, 1, n);
    printf("arr数组 元素为: ");
    printVecElement(arr);
    bool ans = CanPlaceFlowers(arr, flowers);
    printf("能否在不打破种植规则的情况下种入 %d 朵花？？？\n", flowers);
    printBool(ans);
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

void printBool(bool b)
{
    if (b == true)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
}

// 贪心：
// Time: O(N)
// Space: O(1)
bool CanPlaceFlowers(vector<int> &flowerbed, int n)
{
    int l = flowerbed.size();
    int cnt = 0;
    for (int i = 0; i < l; i++)
    {
        if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == l - 1 || flowerbed[i + 1] == 0))
        {
            cnt++;
            flowerbed[i] = 1;
        }
    }
    return cnt >= n;
}