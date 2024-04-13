#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <queue>

using namespace std;

//      LeetCode 2558. 从数量最多的堆取走礼物

//      链接：https://leetcode.cn/problems/take-gifts-from-the-richest-pile/

//      给你一个整数数组 gifts ，表示各堆礼物的数量。每一秒，你需要执行以下操作：
//      选择礼物数量最多的那一堆。
//      如果不止一堆都符合礼物数量最多，从中选择任一堆即可。
//      选中的那一堆留下平方根数量的礼物（向下取整），取走其他的礼物。
//      返回在 k 秒后剩下的礼物数量。
//      示例 1：
//          输入：gifts = [25,64,9,4,100], k = 4
//          输出：29
//          解释：
//              按下述方式取走礼物：
//              - 在第一秒，选中最后一堆，剩下 10 个礼物。
//              - 接着第二秒选中第二堆礼物，剩下 8 个礼物。
//              - 然后选中第一堆礼物，剩下 5 个礼物。
//              - 最后，再次选中最后一堆礼物，剩下 3 个礼物。
//              最后剩下的礼物数量分别是 [5,8,9,4,3] ，所以，剩下礼物的总数量是 29 。
//      示例 2：
//          输入：gifts = [1,1,1,1], k = 4
//          输出：4
//          解释：
//              在本例中，不管选中哪一堆礼物，都必须剩下 1 个礼物。
//              也就是说，你无法获取任一堆中的礼物。
//              所以，剩下礼物的总数量是 4 。
//      提示：
//          1 <= gifts.length <= 103
//          1 <= gifts[i] <= 109
//          1 <= k <= 103

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

long long PickGifts(vector<int> &gifts, int k);

int main()
{
    int n = generateRandomNum(0, 20);
    int k = generateRandomNum(0, 10);
    vector<int> arr = generateRandomVec(0, 100, n);
    printVecElement(arr);
    long long ans_A = PickGifts(arr, k);
    printf("在 %d 秒后剩下的礼物数量: %llu\n", k, ans_A);
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

// 大根堆：
// Time: O(NlogN)
// Space: O(1)
long long PickGifts(vector<int> &gifts, int k)
{
    int l = gifts.size();
    long long sum = 0;
    priority_queue<int, vector<int>, less<int>> pq;
    for (int i = 0; i < l; i++)
    {
        pq.push(gifts[i]);
    }
    while (!pq.empty() && k > 0)
    {
        int tem = sqrt(pq.top());
        pq.pop();
        pq.push(tem);
        k--;
    }
    while (!pq.empty())
    {
        int tem = pq.top();
        sum += tem;
        pq.pop();
    }
    return sum;
}