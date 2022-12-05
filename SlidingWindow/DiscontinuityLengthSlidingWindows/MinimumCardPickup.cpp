#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>

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

int MinimumCardPickup(vector<int>& cards);

int main()
{
    int n = generateRandomNum(0, 30);
    vector<int> vec = generateRandomVec(0, 20, n);
    int sum = accumulate(vec.begin(), vec.end(), 0);
    int target = generateRandomNum(0, sum);
    printVecElement(vec);
    int ans = MinSubArrayLen(target, vec);
    printf("满足其和 ≥ %d 的长度最小的 连续子数组长度为 %d\n", target, ans);
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

int MinimumCardPickup(vector<int>& cards){
    
}