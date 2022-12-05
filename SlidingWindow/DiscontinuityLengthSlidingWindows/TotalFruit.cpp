#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>

using namespace std;

//      LeetCode 904. 水果成篮

//      链接：https://leetcode.cn/problems/fruit-into-baskets/

//      你正在探访一家农场，农场 从左到右 种植了一排果树。
//      这些树用一个整数数组 fruits 表示，其中 fruits[i] 是第 i 棵树上的水果 种类。

//      你想要尽可能多地收集水果。然而，农场的主人设定了一些严格的规矩，你必须按照要求采摘水果：

//      你只有 两个 篮子，并且每个篮子只能装 单一类型 的水果。
//      每个篮子能够装的水果总量没有限制。
//      你可以选择任意一棵树开始采摘，你必须从 每棵 树（包括开始采摘的树）上 恰好摘一个水果 。
//      采摘的水果应当符合篮子中的水果类型。每采摘一次，你将会向右移动到下一棵树，并继续采摘。
//      一旦你走到某棵树前，但水果不符合篮子的水果类型，那么就必须停止采摘。
//      给你一个整数数组 fruits ，返回你可以收集的水果的 最大 数目。

//      示例 1：
//          输入：fruits = [1,2,1]
//          输出：3
//          解释：可以采摘全部 3 棵树。

//      示例 2：
//          输入：fruits = [0,1,2,2]
//          输出：3
//          解释：可以采摘 [1,2,2] 这三棵树。
//          如果从第一棵树开始采摘，则只能采摘 [0,1] 这两棵树。

//      示例 3：
//          输入：fruits = [1,2,3,2,2]
//          输出：4
//          解释：可以采摘 [2,3,2,2] 这四棵树。
//          如果从第一棵树开始采摘，则只能采摘 [1,2] 这两棵树。

//      示例 4：
//          输入：fruits = [3,3,3,1,2,1,1,2,3,3,4]
//          输出：5
//          解释：可以采摘 [1,2,1,1,2] 这五棵树。

//      提示：
//          1 <= fruits.length <= 105
//          0 <= fruits[i] < fruits.length

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

int totalFruit_A(vector<int> &fruits);
int totalFruit_B(vector<int> &fruits);

int main()
{
    int n = generateRandomNum(0, 30);
    vector<int> arr = generateRandomVec(0, 5, n);
    printf("arr数组 元素为: ");
    printVecElement(arr);
    int ans_A = totalFruit_A(arr);
    printf("可以收集的水果的 最大 数目 %d\n", ans_A);
    int ans_B = totalFruit_B(arr);
    printf("可以收集的水果的 最大 数目 %d\n", ans_B);
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

// map: key: 元素  value: 元素出现次数
int totalFruit_A(vector<int> &fruits)
{
    unordered_map<int, int> fmap;
    int ans = 0;
    int left = 0;
    int right = 0;

    while (right < fruits.size())
    {
        fmap[fruits[right]]++;
        while (fmap.size() > 2)
        {
            fmap[fruits[left]]--;
            if (fmap[fruits[left]] == 0)
            {
                fmap.erase(fruits[left]);
            }
            left++;
        }
        ans = max(ans, right - left + 1);
        right++;
    }
    return ans;
}

// map: key: 元素  value: 元素最后出现位置
int totalFruit_B(vector<int> &fruits)
{
    unordered_map<int, int> fmap;
    int ans = 0;
    int left = 0;
    int right = 0;

    while (right < fruits.size())
    {
        fmap[fruits[right]] = right;
        while (fmap.size() > 2)
        {
            int tem = fruits.size();
            for (auto it = fmap.begin(); it != fmap.end(); it++)
            {
                tem = min(it->second, tem);
            }
            fmap.erase(fruits[tem]);
            left = tem;
            left++;
        }
        ans = max(ans, right - left + 1);
        right++;
    }
    return ans;
}