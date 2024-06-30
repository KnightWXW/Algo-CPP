#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;

//      Huawei: 基于日志的系统故障预测

//      某通讯设备系统定义了一系列系统事件，当事件发生时会将该事件ID记录到日志中，
//      该日志的数据全集称为原始时间序列。
//      根据经验，当某些特征事件出现时，预示着存在风险。
//      现给定一组原始事件序列 events (元素可以重复)，以及一个特征序列traits(元素不重复)。
//      请在events中从左往右按匹配规则找到一个匹配特征序列的最短连续子序列；
//      如果存在多个最短的，则返回最早匹配的连续子序列。
//      输入：原始事件序列 events  (元素可以重复)
//           特征序列 traits (元素不重复)
//      输出：一个连续子序列
//      样例1：
//          输入: {4, 8, 4, 3, 6, 6, 8}
//                {4, 6, 8}
//          输出: {4, 3, 6, 6, 8}
//      样例2：
//          输入: {2, 30, 4, 4, 6, 2, 2, 3, 4, 6, 6, 2, 4, 4, 6}
//                {2, 4, 6}
//          输出: {2, 3, 4, 6}

void printVecElement(vector<int> vec);

vector<int> MatchLogTrait_A(vector<int> events, vector<int> traits);
vector<int> MatchLogTrait_B(vector<int> events, vector<int> traits);

int main()
{
    vector<int> events1 = {4, 8, 4, 3, 6, 6, 8};
    vector<int> traits1 = {4, 6, 8};
    vector<int> ans11 = MatchLogTrait_A(events1, traits1);
    vector<int> ans12 = MatchLogTrait_B(events1, traits1);
    printf("events 数组为: \n");
    printVecElement(events1);
    printf("traits1 数组为: \n");
    printVecElement(traits1);
    printf("最早匹配的 连续子序列 数组为: \n");
    printVecElement(ans11); //{4, 3, 6, 6, 8}
    printVecElement(ans12); //{4, 3, 6, 6, 8}

    vector<int> events2 = {2, 30, 4, 4, 6, 2, 2, 3, 4, 6, 6, 2, 4, 4, 6};
    vector<int> traits2 = {2, 4, 6};
    vector<int> ans21 = MatchLogTrait_A(events2, traits2);
    vector<int> ans22 = MatchLogTrait_B(events2, traits2);
    printf("events 数组为: \n");
    printVecElement(events2);
    printf("traits1 数组为: \n");
    printVecElement(traits2); //  {2, 3, 4, 6}
    printf("最早匹配的 连续子序列 数组为: \n");
    printVecElement(ans21);
    printVecElement(ans22); //  {2, 3, 4, 6}
}

void printVecElement(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

// 双指针:
// Time: O(N ^ 2)
// Space: O(N)
vector<int> MatchLogTrait_A(vector<int> events, vector<int> traits)
{
    int l1 = events.size();
    int l2 = traits.size();
    vector<int> ans(events);
    vector<int> tem;
    int index = 0;
    int i = 0;
    unordered_map<int, int> hmap;
    while (i < l1)
    {
        index = 0;
        if (traits[index] != events[i])
        {
            i++;
            continue;
        }
        tem.clear();
        hmap.clear();
        for (int j = i; j < l1; j++)
        {
            if (events[j] == traits[index])
            {
                hmap[events[j]]++;
                index++;
            }
            if (hmap.size() == l2)
            {
                tem = vector<int>(events.begin() + i, events.begin() + j + 1);
                break;
            }
        }
        if (tem.size() < ans.size())
        {
            ans = tem;
        }
        i++;
    }
    return ans;
}

// 贪心:
// Time: O(N ^ 2)
// Space: O(N)
vector<int> MatchLogTrait_B(vector<int> events, vector<int> traits)
{
    int l1 = events.size();
    int l2 = traits.size();
    vector<int> arr(l1, 0);
    vector<int> ans;
    for (int k = 0; k < l1; k++)
    {
        for (int i = 0; i + k < l1; i++)
        {
            if (events[i + k] == traits[arr[i]])
            {
                arr[i]++;
                if (arr[i] == l2)
                {
                    ans = vector<int>(events.begin() + i, events.begin() + i + k + 1);
                    return ans;
                }
            }
        }
    }
    return ans;
}