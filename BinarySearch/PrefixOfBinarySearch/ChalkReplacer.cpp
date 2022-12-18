#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

//      LeetCode 1894. 找到需要补充粉笔的学生编号

//      链接：https://leetcode.cn/problems/find-the-student-that-will-replace-the-chalk/

//      一个班级里有 n 个学生，编号为 0 到 n - 1 。
//      每个学生会依次回答问题，编号为 0 的学生先回答，然后是编号为 1 的学生，
//      以此类推，直到编号为 n - 1 的学生，然后老师会重复这个过程，
//      重新从编号为 0 的学生开始回答问题。
//      给你一个长度为 n 且下标从 0 开始的整数数组 chalk 和一个整数 k 。
//      一开始粉笔盒里总共有 k 支粉笔。
//      当编号为 i 的学生回答问题时，他会消耗 chalk[i] 支粉笔。
//      如果剩余粉笔数量 严格小于 chalk[i] ，那么学生 i 需要 补充 粉笔。
//      请你返回需要 补充 粉笔的学生 编号 。
//      示例 1：
//          输入：chalk = [5,1,5], k = 22
//          输出：0
//              解释：学生消耗粉笔情况如下：
//              - 编号为 0 的学生使用 5 支粉笔，然后 k = 17 。
//              - 编号为 1 的学生使用 1 支粉笔，然后 k = 16 。
//              - 编号为 2 的学生使用 5 支粉笔，然后 k = 11 。
//              - 编号为 0 的学生使用 5 支粉笔，然后 k = 6 。
//              - 编号为 1 的学生使用 1 支粉笔，然后 k = 5 。
//              - 编号为 2 的学生使用 5 支粉笔，然后 k = 0 。
//              编号为 0 的学生没有足够的粉笔，所以他需要补充粉笔。
//      示例 2：
//          输入：chalk = [3,4,1,2], k = 25
//          输出：1
//              解释：学生消耗粉笔情况如下：
//              - 编号为 0 的学生使用 3 支粉笔，然后 k = 22 。
//              - 编号为 1 的学生使用 4 支粉笔，然后 k = 18 。
//              - 编号为 2 的学生使用 1 支粉笔，然后 k = 17 。
//              - 编号为 3 的学生使用 2 支粉笔，然后 k = 15 。
//              - 编号为 0 的学生使用 3 支粉笔，然后 k = 12 。
//              - 编号为 1 的学生使用 4 支粉笔，然后 k = 8 。
//              - 编号为 2 的学生使用 1 支粉笔，然后 k = 7 。
//              - 编号为 3 的学生使用 2 支粉笔，然后 k = 5 。
//              - 编号为 0 的学生使用 3 支粉笔，然后 k = 2 。
//              编号为 1 的学生没有足够的粉笔，所以他需要补充粉笔。
//      提示：
//          chalk.length == n
//          1 <= n <= 105
//          1 <= chalk[i] <= 105
//          1 <= k <= 109

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVec(vector<int> &vec);

int ChalkReplacer(vector<int> &chalk, int k);

int main()
{
    int n = generateRandomNum(1, 30);
    vector<int> vec = generateRandomVec(1, 10, n);
    int h = generateRandomNum(vec.size(), 100);
    printVec(vec);
    int ans = ChalkReplacer(vec, h);
    printf("粉笔盒里总共有 %d 支粉笔。\n需要 补充 粉笔的学生 编号 为 %d", h, ans);
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
    printf("vector的元素依次为：");
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

// 前缀和 + 二分查找：
// Time: O(NlogN)
// Space: O(1)
int ChalkReplacer(vector<int> &chalk, int k)
{
    // 前缀和：
    int l = chalk.size();
    vector<long> preSum(l + 1, 0);
    for (int i = 1; i <= l; i++)
    {
        preSum[i] = preSum[i - 1] + chalk[i - 1];
    }
    k %= preSum[l];

    // 二分查找：
    // return upper_bound(preSum.begin(), preSum.end(), k) - preSum.begin() - 1;
    int left = 0;
    int right = l;
    int ans = 0;
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if (preSum[mid] > k)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans - 1;
}