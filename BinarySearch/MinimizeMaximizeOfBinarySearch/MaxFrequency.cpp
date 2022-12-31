#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

//      LeetCode 1838. 最高频元素的频数

//      链接：https://leetcode.cn/problems/frequency-of-the-most-frequent-element/

//      元素的 频数 是该元素在一个数组中出现的次数。
//      给你一个整数数组 nums 和一个整数 k 。
//      在一步操作中，你可以选择 nums 的一个下标，并将该下标对应元素的值增加 1 。
//      执行最多 k 次操作后，返回数组中最高频元素的 最大可能频数 。
//      示例 1：
//          输入：nums = [1,2,4], k = 5
//          输出：3
//          解释：对第一个元素执行 3 次递增操作，对第二个元素执 2 次递增操作，此时 nums = [4,4,4] 。
//          4 是数组中最高频元素，频数是 3 。
//      示例 2：
//          输入：nums = [1,4,8,13], k = 5
//          输出：2
//          解释：存在多种最优解决方案：
//              - 对第一个元素执行 3 次递增操作，此时 nums = [4,4,8,13] 。4 是数组中最高频元素，频数是 2 。
//              - 对第二个元素执行 4 次递增操作，此时 nums = [1,8,8,13] 。8 是数组中最高频元素，频数是 2 。
//              - 对第三个元素执行 5 次递增操作，此时 nums = [1,4,13,13] 。13 是数组中最高频元素，频数是 2 。
//      示例 3：
//          输入：nums = [3,9,6], k = 2
//          输出：1
//      提示：
//          1 <= nums.length <= 105
//          1 <= nums[i] <= 105
//          1 <= k <= 105

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

int main()
{
    int n = generateRandomNum(1, 10);
    vector<int> arr = generateRandomVec(1, 5, n);
    printf("arr数组 元素为: ");
    printVecElement(arr);
    int ans = LongestWPI(arr);
    printf("工作时间表中「表现良好时间段」的最大长度 %d。\n", ans);
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