#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//      LeetCode 677. 键值映射

//      链接：https://leetcode.cn/problems/map-sum-pairs/

//      设计一个 map ，满足以下几点:
//      字符串表示键，整数表示值
//      返回具有前缀等于给定字符串的键的值的总和
//      实现一个 MapSum 类：
//      MapSum() 初始化 MapSum 对象
//          void insert(String key, int val):
//              插入 key-val 键值对，字符串表示键 key ，整数表示值 val 。
//              如果键 key 已经存在，那么原来的键值对 key-value 将被替代成新的键值对。
//          int sum(string prefix):
//              返回所有以该前缀 prefix 开头的键 key 的值的总和。
//      示例 1：
//          输入：
//              ["MapSum", "insert", "sum", "insert", "sum"]
//              [[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
//          输出：
//              [null, null, 3, null, 5]
//      解释：
//          MapSum mapSum = new MapSum();
//          mapSum.insert("apple", 3);
//          mapSum.sum("ap");           // 返回 3 (apple = 3)
//          mapSum.insert("app", 2);
//          mapSum.sum("ap");           // 返回 5 (apple + app = 3 + 2 = 5)
//      提示：
//          1 <= key.length, prefix.length <= 50
//          key 和 prefix 仅由小写英文字母组成
//          1 <= val <= 1000
//          最多调用 50 次 insert 和 sum

class MapSum
{
public:
    unordered_map<string, int> hmap;
    MapSum()
    {
    }
    void insert(string key, int val)
    {
        hmap[key] = val;
    }

    int sum(string prefix)
    {
        int sum = 0;
        for (auto it = hmap.begin(); it != hmap.end(); it++)
        {
            string key = it->first;
            if (key.substr(0, prefix.size()) == prefix)
            {
                sum += it->second;
            }
        }
        return sum;
    }
};

int main()
{
    MapSum *mapSum = new MapSum();
    mapSum->insert("apple", 3);
    int s1 = mapSum->sum("ap"); // 返回 3 (apple = 3)
    printf("以该前缀开头的键值的总和为 %d\n", s1);
    mapSum->insert("app", 2);
    int s2 = mapSum->sum("ap"); // 返回 5 (apple + app = 3 + 2 = 5)
    printf("以该前缀开头的键值的总和为 %d\n", s2);
}