#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//      LeetCode 2671. 频率跟踪器

//      链接: https://leetcode.cn/problems/frequency-tracker/

//      请你设计并实现一个能够对其中的值进行跟踪的数据结构，并支持对频率相关查询进行应答。
//      实现 FrequencyTracker 类：
//          FrequencyTracker()：
//              使用一个空数组初始化 FrequencyTracker 对象。
//          void add(int number)：
//              添加一个 number 到数据结构中。
//          void deleteOne(int number)：
//              从数据结构中删除一个 number 。数据结构 可能不包含 number ，
//              在这种情况下不删除任何内容。
//          bool hasFrequency(int frequency):
//              如果数据结构中存在出现 frequency 次的数字，则返回 true，否则返回 false。
//      示例 1：
//          输入
//              ["FrequencyTracker", "add", "add", "hasFrequency"]
//              [[], [3], [3], [2]]
//          输出
//              [null, null, null, true]
//          解释
//              FrequencyTracker frequencyTracker = new FrequencyTracker();
//              frequencyTracker.add(3); // 数据结构现在包含 [3]
//              frequencyTracker.add(3); // 数据结构现在包含 [3, 3]
//              frequencyTracker.hasFrequency(2); // 返回 true ，因为 3 出现 2 次
//      示例 2：
//          输入
//              ["FrequencyTracker", "add", "deleteOne", "hasFrequency"]
//              [[], [1], [1], [1]]
//          输出
//              [null, null, null, false]
//          解释
//              FrequencyTracker frequencyTracker = new FrequencyTracker();
//              frequencyTracker.add(1); // 数据结构现在包含 [1]
//              frequencyTracker.deleteOne(1); // 数据结构现在为空 []
//              frequencyTracker.hasFrequency(1); // 返回 false ，因为数据结构为空
//      示例 3：
//          输入
//              ["FrequencyTracker", "hasFrequency", "add", "hasFrequency"]
//              [[], [2], [3], [1]]
//          输出
//              [null, false, null, true]
//          解释
//              FrequencyTracker frequencyTracker = new FrequencyTracker();
//              frequencyTracker.hasFrequency(2); // 返回 false ，因为数据结构为空
//              frequencyTracker.add(3); // 数据结构现在包含 [3]
//              frequencyTracker.hasFrequency(1); // 返回 true ，因为 3 出现 1 次
//      提示：
//          1 <= number <= 105
//          1 <= frequency <= 105
//          最多调用 add、deleteOne 和 hasFrequency 共计 2 * 105 次

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

// 单哈希(超时)：
class FrequencyTracker_A
{
public:
    unordered_map<int, int> hmap;
    FrequencyTracker_A()
    {
    }

    void add(int number)
    {
        hmap[number]++;
    }

    void deleteOne(int number)
    {
        if (hmap.find(number) == hmap.end())
        {
            return;
        }
        hmap[number]--;
        if (hmap[number] == 0)
        {
            hmap.erase(number);
        }
        return;
    }

    bool hasFrequency(int frequency)
    {
        for (auto it = hmap.begin(); it != hmap.end(); it++)
        {
            if (it->second == frequency)
            {
                return true;
            }
        }
        return false;
    }
};

// 双哈希：
class FrequencyTracker_B
{
public:
    unordered_map<int, int> cntMap;
    unordered_map<int, int> freqMap;
    FrequencyTracker_B()
    {
    }

    void add(int number)
    {
        int freq = cntMap[number];
        cntMap[number]++;
        freqMap[freq]--;
        freqMap[freq + 1]++;
        if (freqMap[freq] == 0)
        {
            freqMap.erase(freq);
        }
    }

    void deleteOne(int number)
    {
        if (cntMap.find(number) == cntMap.end())
        {
            return;
        }
        int freq = cntMap[number];
        cntMap[number]--;
        freqMap[freq]--;
        freqMap[freq - 1]++;
        if (cntMap[number] == 0)
        {
            cntMap.erase(number);
        }
        return;
    }

    bool hasFrequency(int frequency)
    {
        return freqMap[frequency];
    }
};

int main()
{
    FrequencyTracker_A *frequencyTracker_A = new FrequencyTracker_A();
    frequencyTracker_A->add(1);                     // 数据结构现在包含 [1]
    frequencyTracker_A->deleteOne(1);               // 数据结构现在为空 []
    bool ha1 = frequencyTracker_A->hasFrequency(1); // 返回 false ，因为数据结构为空
    printf("数据结构中是否存在出现 frequency 次的数字：\n");
    printBool(ha1);
    FrequencyTracker_B *frequencyTracker_B = new FrequencyTracker_B();
    frequencyTracker_B->add(1);                     // 数据结构现在包含 [1]
    frequencyTracker_B->deleteOne(1);               // 数据结构现在为空 []
    bool hb1 = frequencyTracker_B->hasFrequency(1); // 返回 false ，因为数据结构为空
    printf("数据结构中是否存在出现 frequency 次的数字：\n");
    printBool(hb1);
}