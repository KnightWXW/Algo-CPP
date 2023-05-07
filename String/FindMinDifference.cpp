#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

//      LeetCode 539. 最小时间差

//      链接：https://leetcode.cn/problems/minimum-time-difference/

//      给定一个 24 小时制（小时:分钟 "HH:MM"）的时间列表，
//      找出列表中任意两个时间的最小时间差并以分钟数表示。
//      示例 1：
//          输入：timePoints = ["23:59","00:00"]
//          输出：1
//      示例 2：
//          输入：timePoints = ["00:00","23:59","00:00"]
//          输出：0
//      提示：
//          2 <= timePoints.length <= 2 * 104
//          timePoints[i] 格式为 "HH:MM"

int generateRandomNum(int low, int high);
void printString(string s);
void printStringVecElement(vector<string> vec);

int FindMinDifference(vector<string> &timePoints);

int main()
{
    printf("------------------------------------------------\n");
    vector<string> vec_A = {"23:59", "00:00"};
    printf("时间列表为：\n");
    printStringVecElement(vec_A);
    int ans_A = FindMinDifference(vec_A);
    printf("最小时间差为：%d \n", ans_A);
    printf("------------------------------------------------\n");
    vector<string> vec_B = {"00:00", "23:59", "00:00"};
    printf("时间列表为：\n");
    printStringVecElement(vec_B);
    int ans_B = FindMinDifference(vec_B);
    printf("最小时间差为：%d \n", ans_B);
    printf("------------------------------------------------\n");
    vector<string> vec_C = {"00:00", "17:29", "21:59", "11:30", "05:30", "00:10"};
    printf("时间列表为：\n");
    printStringVecElement(vec_C);
    int ans_C = FindMinDifference(vec_C);
    printf("最小时间差为：%d \n", ans_C);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

void printString(string s)
{
    printf("%s\n", s.c_str());
}

void printStringVecElement(vector<string> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%s\n", vec[i].c_str());
    }
    printf("\n");
}

int FindMinDifference(vector<string> &timePoints)
{
    int l = timePoints.size();
    int ans = INT_MAX;
    sort(timePoints.begin(), timePoints.end());
    string lastTime = to_string(atoi(timePoints[0].substr(0, 2).c_str()) + 24) + timePoints[0].substr(2, 3);
    timePoints.push_back(lastTime);
    for (int i = 0; i < l; i++)
    {
        int firstHour = atoi(timePoints[i].substr(0, 2).c_str());
        int firstMinute = atoi(timePoints[i].substr(3, 2).c_str());
        int secondHour = atoi(timePoints[i + 1].substr(0, 2).c_str());
        int secondMinute = atoi(timePoints[i + 1].substr(3, 2).c_str());
        int tem = (secondHour - firstHour) * 60 + (secondMinute - firstMinute);
        ans = min(tem, ans);
    }
    return ans;
}