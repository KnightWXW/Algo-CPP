#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//      LeetCode 2342. 数位和相等数对的最大和

//      链接：https://leetcode.cn/problems/max-sum-of-a-pair-with-equal-sum-of-digits/

//      给你一个下标从 0 开始的数组 nums，数组中的元素都是 正 整数。
//      请你选出两个下标 i 和 j（i != j），且 nums[i] 的数位和 与 nums[j] 的数位和相等。
//      请你找出所有满足条件的下标 i 和 j，找出并返回 nums[i] + nums[j] 可以得到的 最大值 。
//      示例 1：
//          输入：nums = [18,43,36,13,7]
//          输出：54
//          解释：满足条件的数对 (i, j) 为：
//              - (0, 2) ，两个数字的数位和都是 9 ，相加得到 18 + 36 = 54 。
//              - (1, 4) ，两个数字的数位和都是 7 ，相加得到 43 + 7 = 50 。
//          所以可以获得的最大和是 54 。
//      示例 2：
//          输入：nums = [10,12,19,14]
//          输出：-1
//          解释：不存在满足条件的数对，返回 -1 。

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

int MaximumSum_A(vector<int> &arr);
int MaximumSum_B(vector<int> &arr);

int main()
{
    int n = generateRandomNum(1, 10);
    vector<int> arr = generateRandomVec(0, 1000, n);
    int ans_A = MaximumSum_A(arr);
    int ans_B = MaximumSum_B(arr);
    printf("arr数组 元素为: ");
    printVecElement(arr);
    printf("数组中数位和相等数对的最大和为 %d\n", ans_A);
    printf("数组中数位和相等数对的最大和为 %d\n", ans_B);
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

int DigitSum(int num)
{
    int tem = num;
    int sum = 0;
    while (tem != 0)
    {
        sum += tem % 10;
        tem /= 10;
    }
    return sum;
}

int MaximumSum_A(vector<int> &arr)
{
    vector<int> nums(arr);
    int l = nums.size();
    sort(nums.begin(), nums.end());
    unordered_map<int, vector<int>> hmap;
    for (int i = 0; i < l; i++)
    {
        int sumBits = DigitSum(nums[i]);
        hmap[sumBits].push_back(nums[i]);
    }

    int ans = -1;
    for (auto it = hmap.begin(); it != hmap.end(); it++)
    {
        vector<int> tem = it->second;
        int lTem = tem.size();
        if (lTem >= 2)
        {
            ans = max(ans, tem[lTem - 1] + tem[lTem - 2]);
        }
    }
    return ans;
}

int MaximumSum_B(vector<int> &arr)
{
    vector<int> nums(arr);
    int l = nums.size();
    unordered_map<int, int> hmap;
    int ans = -1;
    for (int i = 0; i < l; i++)
    {
        int sumBits = DigitSum(nums[i]);
        if (hmap.find(sumBits) != hmap.end())
        {
            ans = max(ans, nums[i] + hmap[sumBits]);
        }
        hmap[sumBits] = max(hmap[sumBits], nums[i]);
    }
    return ans;
}