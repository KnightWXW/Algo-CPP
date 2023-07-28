#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <numeric>
#include <algorithm>

using namespace std;

//      Huawei: 最大展厅人数

//      MWCS 展共有 N 个展厅，每个展厅的报名人数记于数组 nums。
//      因疫情原因，所有展厅参展总人数上限为 cnt
//      若报名人数之和大于 cnt, 则需限制参展人数，
//      请计算单个展厅的最大参展人数 limit, 使得参展总人数不超过 cnt,
//      参展限制规则为：
//          对于报名人数 不超过 limit 的展厅，凡报名即参展；
//          对于报名人数 超过 limit 的展厅，则均要求 limit 名人员参展；
//          若报名人数之和 小于等于 cnt, 此时不需要限制参展人数，请返回-1
//      请返回 limit 的最大值或 -1
//      示例一：
//          输入：
//              nums = [1,4,2,5,5,1,6]
//              cnt = 13
//          输出：2
//      示例二：
//          输入：
//              nums = [1,3,2,1]
//              cnt = 197
//          输出：-1
//      示例三：
//          输入：
//              nums = [1,1]
//              cnt = 1
//          输出：0
//      提示：
//          0 <= nums.size() <= 10^5
//          0 <= nums[i] <= 10^5
//          0 <= cnt <= 10^5

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

int MaxNumOfExhibitionHalls(vector<int> nums, int cnt);
bool JudgeMaxNumOfExhibitionHalls(vector<int> nums, int limit, int cnt);

int main()
{
    int n = generateRandomNum(1, 10);
    vector<int> nums = generateRandomVec(1, 100, n);
    int cnt = generateRandomNum(0, 1000);
    printf("arr数组 元素为: ");
    printVecElement(nums);
    int limit = MaxNumOfExhibitionHalls(nums, cnt);
    printf("单个展厅的最大参展人数 为 %d, 使得参展总人数不超过 %d\n", limit, cnt);
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

int MaxNumOfExhibitionHalls(vector<int> nums, int cnt)
{
    int l = nums.size();
    int sumAll = accumulate(nums.begin(), nums.end(), 0);
    if (sumAll <= cnt)
    {
        return -1;
    }
    int maxVal = *max_element(nums.begin(), nums.end());
    int left = 0;
    int right = maxVal + 1;
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if (JudgeMaxNumOfExhibitionHalls(nums, mid, cnt))
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

bool JudgeMaxNumOfExhibitionHalls(vector<int> nums, int limit, int cnt)
{
    int l = nums.size();
    int sum = 0;
    for (int i = 0; i < l; i++)
    {
        sum += min(nums[i], limit);
    }
    return sum <= cnt;
}
