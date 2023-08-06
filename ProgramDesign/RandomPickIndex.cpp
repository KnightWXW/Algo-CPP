#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//      LeetCode 398. 随机数索引

//      链接：https://leetcode.cn/problems/random-pick-index/

//      给你一个可能含有 重复元素 的整数数组 nums ，
//      请你随机输出给定的目标数字 target 的索引。
//      你可以假设给定的数字一定存在于数组中。
//      实现 Solution 类：
//          Solution(int[] nums):
//              用数组 nums 初始化对象。
//          int pick(int target):
//              从 nums 中选出一个满足 nums[i] == target 的随机索引 i 。
//              如果存在多个有效的索引，则每个索引的返回概率应当相等。
//      示例：
//          输入
//              ["Solution", "pick", "pick", "pick"]
//              [[[1, 2, 3, 3, 3]], [3], [1], [3]]
//          输出
//              [null, 4, 0, 2]
//          解释
//              Solution solution = new Solution([1, 2, 3, 3, 3]);
//              solution.pick(3); // 随机返回索引 2, 3 或者 4 之一。每个索引的返回概率应该相等。
//              solution.pick(1); // 返回 0 。因为只有 nums[0] 等于 1 。
//              solution.pick(3); // 随机返回索引 2, 3 或者 4 之一。每个索引的返回概率应该相等。
//          提示：
//              1 <= nums.length <= 2 * 104
//              -231 <= nums[i] <= 231 - 1
//              target 是 nums 中的一个整数
//              最多调用 pick 函数 104 次

// 哈希：
class RandomPickIndex_A
{
public:
    unordered_map<int, vector<int>> hmap;
    RandomPickIndex_A(vector<int> nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            hmap[nums[i]].push_back(i);
        }
    }
    int pick(int target)
    {
        vector<int> vec = hmap[target];
        return vec[rand() % vec.size()];
    }
};

// 水塘抽样
class RandomPickIndex_B
{
public:
    vector<int> pool;
    RandomPickIndex_B(vector<int> nums)
    {
        pool = vector<int>(nums);
    }
    int pick(int target)
    {
        int cnt = 0;
        int ans = 0;
        for(int i = 0; i < pool.size(); i++){
            if(pool[i] == target){
                cnt++;
                if (rand() % cnt == 0) {
                    ans = i;
                }
            }
        }
        return ans;
    }
};

int main()
{
    RandomPickIndex_A *randomPickIndex_A = new RandomPickIndex_A({1, 2, 3, 3, 3});
    int pa1 = randomPickIndex_A->pick(3); // 随机返回索引 2, 3 或者 4 之一。每个索引的返回概率应该相等。
    printf("选择的随机数索引为 %d\n", pa1);
    int pa2 = randomPickIndex_A->pick(1); // 返回 0 。因为只有 nums[0] 等于 1 。
    printf("选择的随机数索引为 %d\n", pa2);
    int pa3 = randomPickIndex_A->pick(3); // 随机返回索引 2, 3 或者 4 之一。每个索引的返回概率应该相等。
    printf("选择的随机数索引为 %d\n", pa3);

    RandomPickIndex_B *randomPickIndex_B = new RandomPickIndex_B({1, 2, 3, 3, 3});
    int pb1 = randomPickIndex_B->pick(3); // 随机返回索引 2, 3 或者 4 之一。每个索引的返回概率应该相等。
    printf("选择的随机数索引为 %d\n", pb1);
    int pb2 = randomPickIndex_B->pick(1); // 返回 0 。因为只有 nums[0] 等于 1 。
    printf("选择的随机数索引为 %d\n", pb2);
    int pb3 = randomPickIndex_B->pick(3); // 随机返回索引 2, 3 或者 4 之一。每个索引的返回概率应该相等。
    printf("选择的随机数索引为 %d\n", pb3);
}