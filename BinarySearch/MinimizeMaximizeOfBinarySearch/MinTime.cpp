#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//      LeetCode LCP 12. 小张刷题计划

//      链接：https://leetcode.cn/problems/xiao-zhang-shua-ti-ji-hua/

//      为了提高自己的代码能力，小张制定了 LeetCode 刷题计划，
//      他选中了 LeetCode 题库中的 n 道题，编号从 0 到 n-1，
//      并计划在 m 天内按照题目编号顺序刷完所有的题目
//      （注意，小张不能用多天完成同一题）。
//      在小张刷题计划中，小张需要用 time[i] 的时间完成编号 i 的题目。
//      此外，小张还可以使用场外求助功能，
//      通过询问他的好朋友小杨题目的解法，可以省去该题的做题时间。
//      为了防止“小张刷题计划”变成“小杨刷题计划”，小张每天最多使用一次求助。
//      我们定义 m 天中做题时间最多的一天耗时为 T（小杨完成的题目不计入做题总时间）。
//      请你帮小张求出最小的 T是多少。
//      示例 1：
//          输入：time = [1,2,3,3], m = 2
//          输出：3
//          解释：第一天小张完成前三题，其中第三题找小杨帮忙；
//               第二天完成第四题，并且找小杨帮忙。
//               这样做题时间最多的一天花费了 3 的时间，并且这个值是最小的。
//      示例 2：
//          输入：time = [999,999,999], m = 4
//          输出：0
//          解释：在前三天中，小张每天求助小杨一次，
//                这样他可以在三天内完成所有的题目并不花任何时间。
//      限制：
//          1 <= time.length <= 10^5
//          1 <= time[i] <= 10000
//          1 <= m <= 1000

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVec(vector<int> &vec);

int MinTime(vector<int> &time, int m);
bool JudgeMinTime(vector<int> &time, int m, int cur);

int main()
{
    int n = generateRandomNum(1, 20);
    vector<int> vec = generateRandomVec(1, 20, n);
    int m = generateRandomNum(1, n / 2 + 1);
    printVec(vec);
    int ans = MinTime(vec, m);
    printf("在 %d 天中做题时间最多的一天耗时为 T。最小的 T 是 %d。", m, ans);
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

// 二分查找：
// Time: O(NlogN)
// Space: O(1)
int MinTime(vector<int> &time, int m)
{
    int l = time.size();
    int sum = accumulate(time.begin(), time.end(), 0);
    int left = 0;
    int right = sum;
    int ans = 0;
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if (JudgeMinTime(time, m, mid))
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}

bool JudgeMinTime(vector<int> &time, int m, int cur)
{
    int l = time.size();
    int curMax = 0;
    int day = 1;
    int sum = 0;
    for (int i = 0; i < l; i++)
    {
        sum += time[i];
        curMax = max(curMax, time[i]);
        if (sum - curMax > cur)
        {
            day++;
            curMax = time[i];
            sum = time[i];
        }
    }
    return day <= m;
}