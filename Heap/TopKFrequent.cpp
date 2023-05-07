#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

//      LeetCode 347. 前 K 个高频元素

//      链接：https://leetcode.cn/problems/top-k-frequent-elements/

//      给你一个整数数组 nums 和一个整数 k，请你返回其中出现频率前 k 高的元素。
//      你可以按 任意顺序 返回答案。
//      示例 1:
//          输入: nums = [1,1,1,2,2,3], k = 2
//          输出: [1,2]
//      示例 2:
//          输入: nums = [1], k = 1
//          输出: [1]
//      提示：
//          1 <= nums.length <= 105
//          k 的取值范围是 [1, 数组中不相同的元素的个数]
//          题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的
//      进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。

int generateRandomNum(int low, int high);
void printVecElement(vector<int> &vec);
vector<int> generateRandomVec(int low, int high, int len);

vector<int> TopKFrequent(vector<int> &nums, int k);

int main()
{
    int n = generateRandomNum(5, 50);
    vector<int> vec = generateRandomVec(0, 10, n);
    int k = generateRandomNum(1, n / 5);
    printVecElement(vec);
    printf("其中出现频率前 %d 高的元素：\n", k);
    vector<int> ans = TopKFrequent(vec, k);
    printVecElement(ans);
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

void printVecElement(vector<int> &vec)
{
    printf("vector的元素依次为：");
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

vector<int> TopKFrequent(vector<int> &nums, int k)
{
    int l = nums.size();
    unordered_map<int, int> hmap;
    for (int i = 0; i < l; i++)
    {
        hmap[nums[i]]++;
    }
    priority_queue<pair<int, int>> pq;
    for (auto it = hmap.begin(); it != hmap.end(); it++)
    {
        pq.push(make_pair(it->second, it->first));
    }
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        int tem = pq.top().second;
        ans.push_back(tem);
        pq.pop();
    }
    return ans;
}