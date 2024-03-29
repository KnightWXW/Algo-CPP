#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//      LeetCode 81. 搜索旋转排序数组 II

//      链接：https://leetcode.cn/problems/search-in-rotated-sorted-array-ii/

//      已知存在一个按非降序排列的整数数组 nums ，数组中的值不必互不相同。
//      在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行旋转，
//      使数组变为 [nums[k],nums[k+1],...,nums[n-1],nums[0],nums[1],...,nums[k-1]]
//      （下标 从 0 开始 计数）。
//      例如， [0,1,2,4,4,4,5,6,6,7] 在下标 5 处经旋转后可能变为 [4,5,6,6,7,0,1,2,4,4] 。
//      给你 旋转后 的数组 nums 和一个整数 target ，
//      请你编写一个函数来判断给定的目标值是否存在于数组中。
//      如果 nums 中存在这个目标值 target ，则返回 true ，否则返回 false 。
//      你必须尽可能减少整个操作步骤。
//      示例 1：
//          输入：nums = [2,5,6,0,0,1,2], target = 0
//          输出：true
//      示例 2：
//          输入：nums = [2,5,6,0,0,1,2], target = 3
//          输出：false
//      提示：
//          1 <= nums.length <= 5000
//          -104 <= nums[i] <= 104
//          题目数据保证 nums 在预先未知的某个下标上进行了旋转
//          -104 <= target <= 104
 

// 进阶：

// 这是 搜索旋转排序数组 的延伸题目，本题中的 nums  可能包含重复元素。
// 这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVec(vector<int> &vec);
void printBool(bool b);

bool SearchRotationSortArray2(vector<int>& nums, int target);

int main()
{
    int n = generateRandomNum(1, 20);
    vector<int> vec = generateRandomVec(1, 50, n);
    sort(vec.begin(), vec.end());
    int k = generateRandomNum(0, n);
    printVec(vec);
    vector<int> arr(n, 0);
    copy(vec.begin() + k, vec.end(), arr.begin());
    copy(vec.begin(), vec.begin() + k, arr.begin() + n - k);
    printVec(arr);
    int target = generateRandomNum(1, 49);
    bool ans = SearchRotationSortArray2(arr, target);
    printf("数组 nums 中能否找到目标值 %d。\n", target);
    printBool(ans);
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

void printBool(bool b)
{
    if (b == true)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
}

// 二分查找：
// Time: O(NlogN)
// Space: O(1)
bool SearchRotationSortArray2(vector<int>& nums, int target){
    int l = nums.size();
    int left = 0;
    int right = l - 1;
    int mid = 0;
    while(left <= right){
        mid = left + ((right - left) >> 1);
        if(nums[mid] == target){
            return true;
        }
        if(nums[left] == nums[mid] && nums[right] == nums[mid]){
            while(left != mid && nums[left] == nums[mid]){
                left++;
            }
            if(left == mid){
                left = mid + 1;
                continue;
            }
        }
        if(nums[left] != nums[mid]){
            if(nums[left] < nums[mid]){
                if(nums[left] <= target && target < nums[mid]){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }else{
                if(nums[mid] < target && target <= nums[right]){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
        }else{
            if(nums[mid] < nums[right]){
                if(nums[mid] < target && target <= nums[right]){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }else{
                if(nums[left] <= target && target < nums[right]){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
        }
    }
    return false;
}