#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//      LeetCode 1870. 准时到达的列车最小时速

//      链接：https://leetcode.cn/problems/minimum-speed-to-arrive-on-time/

//      给你一个浮点数 hour ，表示你到达办公室可用的总通勤时间。
//      要到达办公室，你必须按给定次序乘坐 n 趟列车。
//      另给你一个长度为 n 的整数数组 dist，
//      其中 dist[i] 表示第 i 趟列车的行驶距离（单位是千米）。
//      每趟列车均只能在整点发车，所以你可能需要在两趟列车之间等待一段时间。
//      例如，第 1 趟列车需要 1.5 小时，那你必须再等待 0.5 小时，
//      搭乘在第 2 小时发车的第 2 趟列车。
//      返回能满足你准时到达办公室所要求全部列车的 最小正整数 时速（单位：千米每小时），
//      如果无法准时到达，则返回 -1。
//      生成的测试用例保证答案不超过 107，且 hour 的 小数点后最多存在两位数字。
//      示例 1：
//          输入：dist = [1,3,2], hour = 6
//          输出：1
//          解释：速度为 1 时：
//              - 第 1 趟列车运行需要 1/1 = 1 小时。
//              - 由于是在整数时间到达，可以立即换乘在第 1 小时发车的列车。
//                  第 2 趟列车运行需要 3/1 = 3 小时。
//              - 由于是在整数时间到达，可以立即换乘在第 4 小时发车的列车。
//                  第 3 趟列车运行需要 2/1 = 2 小时。
//              - 你将会恰好在第 6 小时到达。
//      示例 2：
//          输入：dist = [1,3,2], hour = 2.7
//          输出：3
//          解释：速度为 3 时：
//              - 第 1 趟列车运行需要 1/3 = 0.33333 小时。
//              - 由于不是在整数时间到达，故需要等待至第 1 小时才能搭乘列车。
//                  第 2 趟列车运行需要 3/3 = 1 小时。
//              - 由于是在整数时间到达，可以立即换乘在第 2 小时发车的列车。
//                  第 3 趟列车运行需要 2/3 = 0.66667 小时。
//              - 你将会在第 2.66667 小时到达。
//      示例 3：
//          输入：dist = [1,3,2], hour = 1.9
//          输出：-1
//          解释：不可能准时到达，因为第 3 趟列车最早是在第 2 小时发车。
//      提示：
//          n == dist.length
//          1 <= n <= 105
//          1 <= dist[i] <= 105
//          1 <= hour <= 109
//          hours 中，小数点后最多存在两位数字

int generateRandomNum(int low, int high);
double generateRandomNumDouble(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVec(vector<int> &vec);

int MinSpeedOnTime(vector<int> &dist, double hour);
bool JudgeMinSpeedOnTime(vector<int> &dist, double hour, int speed);

int main()
{
    int n = generateRandomNum(1, 20);
    vector<int> vec = generateRandomVec(1, 10, n);
    int sumAll = accumulate(vec.begin(), vec.end(), 0);
    double hour = generateRandomNumDouble(1, sumAll / 2 + 1);
    printVec(vec);
    int ans = MinSpeedOnTime(vec, hour);
    printf("到达办公室可用的总通勤时间为 %lf,\n满足你准时到达办公室所要求全部列车的 最小正整数 时速为 %d。", hour, ans);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

double generateRandomNumDouble(int low, int high)
{
    srand((int)time(0));
    double ran = (rand() % (high * 100 - low * 100 + 1) + low * 100) / 100.0;
    return ran;
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
    printf("vector的元素依次为: ");
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

// 二分查找：
// Time: O(NlogN)
// Space: O(1)
int MinSpeedOnTime(vector<int> &dist, double hour)
{
    int l = dist.size();
    int maxSpeed = *max_element(dist.begin(), dist.end()) * 100;
    int left = 1;
    int right = maxSpeed + 1;
    int ans = -1;
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if (JudgeMinSpeedOnTime(dist, hour, mid))
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

bool JudgeMinSpeedOnTime(vector<int> &dist, double hour, int speed)
{
    int l = dist.size();
    double sumTime = 0;
    for (int i = 0; i < dist.size() - 1; i++)
    {
        int tem = dist[i] / speed;
        if (dist[i] % speed != 0)
        {
            tem++;
        }
        sumTime += double(tem);
    }
    double endTime = dist[l - 1] * 1.0 / speed;
    sumTime += endTime;
    return sumTime <= hour;
}