#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

//      面试题 17.18. 最短超串

//      链接：https://leetcode.cn/problems/shortest-supersequence-lcci/

//      假设你有两个数组，一个长一个短，短的元素均不相同。
//      找到长数组中包含短数组所有的元素的最短子数组，其出现顺序无关紧要。
//      返回最短子数组的左端点和右端点，如有多个满足条件的子数组，返回左端点最小的一个。
//      若不存在，返回空数组。
//      示例 1:
//          输入:
//              big = [7,5,9,0,2,1,3,5,7,9,1,1,5,8,8,9,7]
//              small = [1,5,9]
//              输出: [7,10]
//      示例 2:
//          输入:
//              big = [1,2,3]
//              small = [4]
//          输出: []
//      提示：
//          big.length <= 100000
//          1 <= small.length <= 100000

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVec(vector<int> &vec);

vector<int> ShortestSeq(vector<int> &big, vector<int> &small);

int main()
{
    int n1 = generateRandomNum(11, 30);
    int n2 = generateRandomNum(1, 10);
    vector<int> big = generateRandomVec(0, 10, n1);
    vector<int> small = generateRandomVec(0, 9, n2);
    printVec(big);
    printVec(small);
    vector<int> ans = ShortestSeq(big, small);
    printf("最短子数组的 左端点 和 右端点 为：\n");
    printVec(ans);
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

void printVec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

vector<int> ShortestSeq(vector<int> &big, vector<int> &small)
{
    int n1 = big.size();
    int n2 = small.size();
    int len = INT_MAX;
    vector<int> ans;
    int left = 0;
    int right = 0;
    unordered_set<int> hset(small.begin(), small.end());
    unordered_map<int, int> hmap;
    while (right < n1)
    {
        if (hset.count(big[right]))
        {
            hmap[big[right]]++;
        }
        while (hmap.size() == hset.size())
        {
            if (right - left < len)
            {
                len = right - left;
                ans = vector<int>{left, right};
            }
            if (hset.count(big[left]) > 0)
            {
                if (hmap[big[left]] > 1)
                {
                    hmap[big[left]]--;
                }
                else
                {
                    hmap.erase(big[left]);
                }
            }
            left++;
        }
        right++;
    }
    return ans;
}