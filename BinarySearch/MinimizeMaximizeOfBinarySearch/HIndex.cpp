#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//      LeetCode 274. H 指数

//      链接：https://leetcode.cn/problems/h-index/

//      给你一个整数数组 citations，
//      其中 citations[i] 表示研究者的第 i 篇论文被引用的次数。
//      计算并返回该研究者的 h 指数。
//      根据维基百科上 h 指数的定义：h 代表“高引用次数”，
//      一名科研人员的 h指数是指他（她）的（n 篇论文中）
//      总共有 h 篇论文分别被引用了至少 h 次。
//      且其余的 n - h 篇论文每篇被引用次数 不超过 h 次。
//      如果 h 有多种可能的值，h 指数 是其中最大的那个。
//      示例 1：
//          输入：citations = [3,0,6,1,5]
//          输出：3
//          解释：给定数组表示研究者总共有 5 篇论文，
//              每篇论文相应的被引用了 3, 0, 6, 1, 5 次。
//              由于研究者有 3 篇论文每篇 至少 被引用了 3 次，
//              其余两篇论文每篇被引用 不多于 3 次，所以她的 h 指数是 3。
//      示例 2：
//          输入：citations = [1,3,1]
//          输出：1
//      提示：
//          n == citations.length
//          1 <= n <= 5000
//          0 <= citations[i] <= 1000

int generateRandomNum(int low, int high);
void printVecElement(vector<int> &vec);
vector<int> generateRandomVec(int low, int high, int len);

bool JudgeHIndexI(vector<int> &citation, int h);
int HIndexI_A(vector<int> &citations);
int HIndexI_B(vector<int> &citations);
int HIndexI_C(vector<int> &citations);
int HIndexI_D(vector<int> &citations);

int main()
{
    int n = generateRandomNum(1, 20);
    vector<int> vec = generateRandomVec(0, 100, n);
    printVecElement(vec);
    int ans_A = HIndexI_A(vec);
    int ans_B = HIndexI_B(vec);
    int ans_C = HIndexI_C(vec);
    int ans_D = HIndexI_D(vec);
    printf("该科研人员的 h指数 是 %d\n", ans_A);
    printf("该科研人员的 h指数 是 %d\n", ans_B);
    printf("该科研人员的 h指数 是 %d\n", ans_C);
    printf("该科研人员的 h指数 是 %d\n", ans_D);
}

int generateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
    return (rand() % (high - low + 1)) + low;
}

void printVecElement(vector<int> &vec)
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

// 二分查找：
// Time: O(NlogN)
// Space: O(N)
int HIndexI_A(vector<int> &citations)
{
    vector<int> arr(citations);
    sort(arr.begin(), arr.end());
    int l = arr.size();
    int left = 0;
    int right = l - 1;
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if (arr[mid] >= l - mid)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return l - left;
}

// 二分查找：
// Time: O(NlogN)
// Space: O(N)
int HIndexI_B(vector<int> &citations)
{
    vector<int> arr(citations);
    int l = arr.size();
    int left = 0;
    int right = l;
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if (JudgeHIndexI(arr, mid))
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return right;
}

bool JudgeHIndexI(vector<int> &citation, int h)
{
    int cnt = 0;
    for (int i = 0; i < citation.size(); i++)
    {
        if (citation[i] >= h)
        {
            cnt++;
        }
    }
    return cnt >= h;
}

// 排序：
// Time: O(NlogN)
// Space: O(N)
int HIndexI_C(vector<int> &citations)
{
    vector<int> arr(citations);
    sort(arr.begin(), arr.end());
    int h = 0;
    int index = arr.size() - 1;
    while (index >= 0 && arr[index] > h)
    {
        h++;
        index--;
    }
    return h;
}

// 计数排序：
// Time: O(NlogN)
// Space: O(N)
int HIndexI_D(vector<int> &citations)
{
    vector<int> arr(citations);
    int l = arr.size();
    vector<int> cnt(l + 1, 0);
    int h = 0;
    for (int i = 0; i < l; i++)
    {
        if (arr[i] >= l)
        {
            cnt[l]++;
        }
        else
        {
            cnt[arr[i]]++;
        }
    }
    for (int i = l; i >= 0; i--)
    {
        h += cnt[i];
        if (h >= i)
        {
            return i;
        }
    }
    return 0;
}