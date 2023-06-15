#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_set>

using namespace std;

//      LeetCode 888. 公平的糖果交换

//      链接：https://leetcode.cn/problems/fair-candy-swap/submissions/

//      爱丽丝和鲍勃拥有不同总数量的糖果。
//      给你两个数组 aliceSizes 和 bobSizes，
//      aliceSizes[i] 是爱丽丝拥有的第 i 盒糖果中的糖果数量，
//      bobSizes[j] 是鲍勃拥有的第 j 盒糖果中的糖果数量。
//      两人想要互相交换一盒糖果，这样在交换之后，他们就可以拥有相同总数量的糖果。
//      一个人拥有的糖果总数量是他们每盒糖果数量的总和。
//      返回一个整数数组 answer，其中 answer[0] 是爱丽丝必须交换的糖果盒中的糖果的数目，
//      answer[1] 是鲍勃必须交换的糖果盒中的糖果的数目。
//      如果存在多个答案，你可以返回其中 任何一个。
//      题目测试用例保证存在与输入对应的答案。
//      示例 1：
//          输入：aliceSizes = [1,1], bobSizes = [2,2]
//          输出：[1,2]
//      示例 2：
//          输入：aliceSizes = [1,2], bobSizes = [2,3]
//          输出：[1,2]
//      示例 3：
//          输入：aliceSizes = [2], bobSizes = [1,3]
//          输出：[2,3]
//      示例 4：
//          输入：aliceSizes = [1,2,5], bobSizes = [2,4]
//          输出：[5,4]
//      提示：
//          1 <= aliceSizes.length, bobSizes.length <= 104
//          1 <= aliceSizes[i], bobSizes[j] <= 105
//          爱丽丝和鲍勃的糖果总数量不同。
//          题目数据保证对于给定的输入至少存在一个有效答案。

int generateRandomNum(int low, int high);
vector<int> generateRandomVecA(int low, int high, int len);
vector<int> generateRandomVecB(int low, int high, int len);
void printVecElement(vector<int> vec);

vector<int> FairCandySwap(vector<int> &aliceSizes, vector<int> &bobSizes);

int main()
{
    int n1 = generateRandomNum(1, 20);
    vector<int> aliceSizes = generateRandomVecA(1, 100, n1);
    printf("aliceSizes数组 元素为: \n");
    printVecElement(aliceSizes);
    int n2 = generateRandomNum(1, 21);
    vector<int> bobSizes = generateRandomVecB(1, 100, n2);
    printf("bobSizes数组 元素为: \n");
    printVecElement(bobSizes);
    vector<int> ans = FairCandySwap(aliceSizes, bobSizes);
    printf("ans数组 元素为：\n");
    printVecElement(ans);
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

vector<int> generateRandomVecA(int low, int high, int len)
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

vector<int> generateRandomVecB(int low, int high, int len)
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

vector<int> FairCandySwap(vector<int> &aliceSizes, vector<int> &bobSizes)
{
    int sumA = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
    int sumB = accumulate(bobSizes.begin(), bobSizes.end(), 0);
    int dif = (sumA - sumB) >> 1;
    vector<int> ans;
    unordered_set<int> hset(aliceSizes.begin(), aliceSizes.end());
    for (auto &b : bobSizes)
    {
        int a = b + dif;
        if (hset.count(a) > 0)
        {
            ans = vector<int>{a, b};
            break;
        }
    }
    if (ans.empty())
    {
        return {-1, -1};
    }
    else
    {
        return ans;
    }
}
