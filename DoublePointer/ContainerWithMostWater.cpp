#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//      LeetCode 11. 盛最多水的容器

//      链接：https://leetcode.cn/problems/container-with-most-water/

//      给定一个长度为 n 的整数数组 height。
//      有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i])。
//      找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
//      返回容器可以储存的最大水量。
//      说明：你不能倾斜容器。

//      示例 1：
//          输入：[1,8,6,2,5,4,8,3,7]
//          输出：49
//          解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
//      示例 2：
//          输入：height = [1,1]
//          输出：1
//      提示：
//          n == height.length
//          2 <= n <= 105
//          0 <= height[i] <= 104

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

int ContainerWithMostWater(vector<int> &height);

int main()
{
    int n = generateRandomNum(1, 30);
    vector<int> vec = generateRandomVec(0, 20, n);
    printVecElement(vec);
    int ans = ContainerWithMostWater(vec);
    printf("容器 可以储存的最大水量为 %d。\n", ans);
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

// 对撞双指针：
// Time: O(N)
// Space: O(1)
int ContainerWithMostWater(vector<int> &height)
{
    int l = height.size();
    int left = 0;
    int right = l - 1;
    int ans = 0;
    while (left < right)
    {
        int minVal = min(height[left], height[right]);
        ans = max(ans, minVal * (right - left));
        if (height[left] <= height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return ans;
}