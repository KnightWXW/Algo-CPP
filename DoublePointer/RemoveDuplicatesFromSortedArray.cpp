#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//      LeetCode 26. 删除有序数组中的重复项

//      链接：https://leetcode.cn/problems/remove-duplicates-from-sorted-array/

//      给你一个 升序排列 的数组 nums ，请你 原地 删除重复出现的元素，
//      使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。
//      由于在某些语言中不能改变数组的长度，所以必须将结果放在数组nums的第一部分。
//      更规范地说，如果在删除重复项之后有 k 个元素，
//      那么 nums 的前 k 个元素应该保存最终结果。
//      将最终结果插入 nums 的前 k 个位置后返回 k 。
//      不要使用额外的空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
//      判题标准:
//          系统会用下面的代码来测试你的题解:
//          int[] nums = [...]; // 输入数组
//          int[] expectedNums = [...]; // 长度正确的期望答案
//          int k = removeDuplicates(nums); // 调用
//          assert k == expectedNums.length;
//          for (int i = 0; i < k; i++) {
//              assert nums[i] == expectedNums[i];
//          }
//          如果所有断言都通过，那么您的题解将被 通过。
//      示例 1：
//          输入：nums = [1,1,2]
//          输出：2, nums = [1,2,_]
//          解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。
//          不需要考虑数组中超出新长度后面的元素。
//      示例 2：
//          输入：nums = [0,0,1,1,1,2,2,3,3,4]
//          输出：5, nums = [0,1,2,3,4]
//          解释：函数应该返回新的长度 5，并且原数组 nums 的前五个元素被修改为0, 1, 2, 3, 4 
//               不需要考虑数组中超出新长度后面的元素。
//      提示：
//          1 <= nums.length <= 3 * 104
//          -104 <= nums[i] <= 104
//          nums 已按 升序 排列

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVec(vector<int> &vec);
void print2DVecElement(vector<vector<int>> vec);

int RemoveDuplicatesFromSortedArray(vector<int>& nums);

int main()
{
    int n = generateRandomNum(1, 30);
    vector<int> vec = generateRandomVec(0, 5, n);
    sort(vec.begin(), vec.end());
    printVec(vec);
    int ans = RemoveDuplicatesFromSortedArray(vec);
    printf("删除重复出现的元素后数组的新长度为 %d。\n", ans);
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

// 双指针：
// Time: O(N)
// Space: O(1)
int RemoveDuplicatesFromSortedArray(vector<int>& nums){
    int l = nums.size();
    if(l == 0 || l == 1){
        return l;
    }
    int left = 0;
    int right = 1;
    while(right < l){
        if(nums[right] != nums[left]){
            nums[left + 1] = nums[right];
            left++;
        }
        right++;
    }
    return left + 1;
}


