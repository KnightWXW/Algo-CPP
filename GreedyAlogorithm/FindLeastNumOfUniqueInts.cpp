#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//      LeetCode 1481. 不同整数的最少数目

//      链接：https://leetcode.cn/problems/least-number-of-unique-integers-after-k-removals/

//      给你一个整数数组 arr 和一个整数 k 。现需要从数组中恰好移除 k 个元素，
//      请找出移除后数组中不同整数的最少数目。

//      示例 1：
//      输入：arr = [5,5,4], k = 1
//      输出：1
//      解释：移除 1 个 4 ，数组中只剩下 5 一种整数。
//      示例 2：

//      输入：arr = [4,3,1,1,3,3,2], k = 3
//      输出：2
//      解释：先移除 4、2 ，然后再移除两个 1 中的任意 1 个或者三个 3 中的任意 1 个，最后剩下 1 和 3 两种整数。
 

//      提示：

//      1 <= arr.length <= 10^5
//      1 <= arr[i] <= 10^9
//      0 <= k <= arr.length

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

int FindLeastNumOfUniqueInts(vector<int> arr, int k);

int main()
{
    int n = generateRandomNum(0, 10);
    vector<int> arr = generateRandomVec(1, 5, n);
    int k = generateRandomNum(0, n);
    printf("arr数组 元素为: ");
    printVecElement(arr);
    printf("移除%d个元素 后 数组中 不同整数 的 最少数目为%d。\n", k, FindLeastNumOfUniqueInts(arr, k));
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

// 贪心：
// Time: O(NlogN)
// Space: O(N)
int FindLeastNumOfUniqueInts(vector<int> arr, int k)
{
    unordered_map<int, int> hashMap;
    for (auto v : arr)
    {
        hashMap[v]++;
    }

    vector<int> cntArr;
    for(auto it : hashMap){
        cntArr.push_back(it.second);
    }

    sort(cntArr.begin(), cntArr.end());
    int i = 0;
    for(; i < cntArr.size(); i++){
        if(cntArr[i] <= k){
            k -= cntArr[i];
        }else{
            break;
        }
    }
    return cntArr.size() - i;
}