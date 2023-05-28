#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//      LeetCode 33. 搜索旋转排序数组

//      链接：https://leetcode.cn/problems/search-in-rotated-sorted-array/

//      整数数组 nums 按升序排列，数组中的值 互不相同 。
//      在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了旋转，
//      使数组变为[nums[k],nums[k+1],...,nums[n-1],nums[0],nums[1],...,nums[k-1]]
//      （下标 从 0 开始 计数）。
//      例如，[0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。
//      给你 旋转后 的数组 nums 和一个整数 target，
//      如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
//      你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。
//      示例 1：
//          输入：nums = [4,5,6,7,0,1,2], target = 0
//          输出：4
//      示例 2：
//          输入：nums = [4,5,6,7,0,1,2], target = 3
//          输出：-1
//      示例 3：
//          输入：nums = [1], target = 0
//          输出：-1
//      提示：
//          1 <= nums.length <= 5000
//          -104 <= nums[i] <= 104
//          nums 中的每个值都 独一无二
//          题目数据保证 nums 在预先未知的某个下标上进行了旋转
//          -104 <= target <= 104

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVec(vector<int> &vec);

int SearchRotationSortArray1(vector<int>& nums, int target);

int main()
{
    int n = generateRandomNum(1, 20);
    vector<int> vec = generateRandomVec(1, 30, n);
    int target = vec[0];
    sort(vec.begin(), vec.end());
    int k = generateRandomNum(0, n);
    printVec(vec);
    vector<int> arr(n, 0);
    copy(vec.begin() + k, vec.end(), arr.begin());
    copy(vec.begin(), vec.begin() + k, arr.begin() + n - k);
    printVec(arr);
    int ans = SearchRotationSortArray1(arr, target);
    printf("数组 nums 中目标值 %d 的下标为 %d。", target, ans);
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

// 二分查找：
// Time: O(NlogN)
// Space: O(1)
int SearchRotationSortArray1(vector<int>& nums, int target){
    int l = nums.size();
    int left = 0;
    int right = l - 1;
    int mid = 0;
    while(left <= right){
        mid = left + ((right - left) >> 1);
        if(nums[mid] == target){
            return mid;
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
    return -1;
}