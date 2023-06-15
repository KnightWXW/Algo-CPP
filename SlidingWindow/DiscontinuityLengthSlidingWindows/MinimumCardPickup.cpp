#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <unordered_map>

using namespace std;

//      LeetCode 2260. 必须拿起的最小连续卡牌数

//      链接：https://leetcode.cn/problems/minimum-consecutive-cards-to-pick-up/

//      给你一个整数数组 cards ，其中 cards[i] 表示第 i 张卡牌的 值 。
//      如果两张卡牌的值相同，则认为这一对卡牌 匹配 。
//      返回你必须拿起的最小连续卡牌数，以使在拿起的卡牌中有一对匹配的卡牌。
//      如果无法得到一对匹配的卡牌，返回 -1 。
//      示例 1：
//          输入：cards = [3,4,2,3,4,7]
//          输出：4
//          解释：拿起卡牌 [3,4,2,3] 将会包含一对值为 3 的匹配卡牌。注意，拿起 [4,2,3,4] 也是最优方案。
//      示例 2：
//          输入：cards = [1,0,5,3]
//          输出：-1
//          解释：无法找出含一对匹配卡牌的一组连续卡牌。
//      提示：
//          1 <= cards.length <= 105
//          0 <= cards[i] <= 106

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

int MinimumCardPickup(vector<int> &cards);

int main()
{
    int n = generateRandomNum(0, 10);
    vector<int> vec = generateRandomVec(0, 10, n);
    printVecElement(vec);
    int ans = MinimumCardPickup(vec);
    printf("你必须拿起的最小连续卡牌数为 %d\n", ans);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
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

// 滑动窗口：
// Time: O(N)
// Space: O(N)
int MinimumCardPickup(vector<int> &cards)
{
    int l = cards.size();
    unordered_map<int, int> hmap;
    int left = 0;
    int right = 0;
    int ans = INT_MAX;
    while (right < l)
    {
        hmap[cards[right]]++;
        while (hmap[cards[right]] >= 2)
        {
            ans = min(ans, right - left + 1);
            hmap[cards[left]]--;
            left++;
        }
        right++;
    }
    return ans == INT_MAX ? -1 : ans;
}

// 哈希：
// Time: O(N)
// Space: O(N)
int MinimumCardPickup(vector<int> &cards)
{
    int l = cards.size();
    unordered_map<int, int> hmap;
    int ans = INT_MAX;
    for (int i = 0; i < l; i++)
    {
        if (hmap.count(cards[i]) > 0)
        {
            ans = min(ans, i - hmap[cards[i]] + 1);
        }
        hmap[cards[i]] = i;
    }
    return ans == INT_MAX ? -1 : ans;
}