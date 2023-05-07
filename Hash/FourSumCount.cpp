#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//      LeetCode 454. 四数相加 II

//      链接：https://leetcode.cn/problems/4sum-ii/

//      给你四个整数数组 nums1、nums2、nums3 和 nums4 ，
//      数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：
//          0 <= i, j, k, l < n
//          nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
//      示例 1：
//          输入：nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
//          输出：2
//          解释：
//              两个元组如下：
//              1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] 
//                  = 1 + (-2) + (-1) + 2 = 0
//              2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] 
//                  = 2 + (-1) + (-1) + 0 = 0
//      示例 2：
//          输入：nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
//          输出：1
//      提示：
//          n == nums1.length
//          n == nums2.length
//          n == nums3.length
//          n == nums4.length
//          1 <= n <= 200
//          -228 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 228

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVec(vector<int> &vec);

int FourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4);

int main()
{
    int n = generateRandomNum(1, 30);
    vector<int> vec1 = generateRandomVec(-99, 99, n);
    printVec(vec1);
    vector<int> vec2 = generateRandomVec(-100, 100, n);
    printVec(vec2);
    vector<int> vec3 = generateRandomVec(-101, 101, n);
    printVec(vec3);
    vector<int> vec4 = generateRandomVec(-102, 102, n);
    printVec(vec4);
    int ans = FourSumCount(vec1, vec2, vec3, vec4);
    printf("计算有 %d 个元组 (i, j, k, l) 能满足要求。\n", ans);
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
    printf("vector的元素依次为：");
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int FourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
{
    unordered_map<int, int> hmap;
    for(int i = 0; i < nums1.size(); i++){
        for(int j = 0; j < nums2.size(); j++){
            hmap[nums1[i] + nums2[j]]++;
        }
    }

    int ans = 0;
    for(int i = 0; i < nums3.size(); i++){
        for(int j = 0; j < nums4.size(); j++){
            int tem = -(nums3[i] + nums4[j]);
            if(hmap[tem] > 0){
                ans += hmap[tem];
            }
        }
    }
    return ans;
}