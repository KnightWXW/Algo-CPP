#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

//      LeetCode 1146. 快照数组

//      链接：https://leetcode.cn/problems/snapshot-array/

//      实现支持下列接口的「快照数组」- SnapshotArray：
//          SnapshotArray(int length):
//              初始化一个与指定长度相等的 类数组 的数据结构。
//              初始时，每个元素都等于 0。
//          void set(index, val):
//              会将指定索引 index 处的元素设置为 val。
//          int snap():
//              获取该数组的快照，并返回快照的编号 snap_id（快照号是调用 snap() 的总次数减去 1）。
//          int get(index, snap_id):
//              根据指定的 snap_id 选择快照，并返回该快照指定索引 index 的值。
//      示例：
//          输入：["SnapshotArray","set","snap","set","get"]
//                  [[3],[0,5],[],[0,6],[0,0]]
//          输出：[null,null,0,null,5]
//          解释：
//              SnapshotArray snapshotArr = new SnapshotArray(3); // 初始化一个长度为 3 的快照数组
//              snapshotArr.set(0,5);  // 令 array[0] = 5
//              snapshotArr.snap();  // 获取快照，返回 snap_id = 0
//              snapshotArr.set(0,6);
//              snapshotArr.get(0,0);  // 获取 snap_id = 0 的快照中 array[0] 的值，返回 5
//      提示：
//          1 <= length <= 50000
//          题目最多进行50000 次set，snap，和 get的调用 。
//          0 <= index < length
//          0 <= snap_id < 我们调用 snap() 的总次数
//          0 <= val <= 10^9

// 哈希：超时
class SnapshotArray_A
{
public:
    int snapId;
    vector<int> vec;
    vector<vector<int>> hVec;
    SnapshotArray_A(int length)
    {
        vec = vector<int>(length, 0);
        snapId = 0;
    }

    void set(int index, int val)
    {
        vec[index] = val;
    }

    int snap()
    {
        hVec.push_back(vec);
        snapId++;
        return snapId - 1;
    }

    int get(int index, int snap_id)
    {
        return hVec[snap_id][index];
    }
};

// 哈希 + 二分查找：
class SnapshotArray_B
{
public:
    int snapId;
    vector<map<int, int>> hVec;
    SnapshotArray_B(int length)
    {
        snapId = 0;
        hVec = vector<map<int, int>>(length);
        for(int i = 0; i < length; i++){
            hVec[i][0] = 0;
        }
    }

    void set(int index, int val)
    {
        hVec[index][snapId] = val;
    }

    int snap()
    {
        snapId++;
        return snapId - 1;
    }

    int get(int index, int snap_id)
    {
        auto tem = hVec[index].upper_bound(snap_id);
        tem--;
        return tem->second;
    }
};

int main()
{
    SnapshotArray_A *snapshotArr_A = new SnapshotArray_A(3); // 初始化一个长度为 3 的快照数组
    snapshotArr_A->set(0, 5);                                // 令 array[0] = 5
    int sa1 = snapshotArr_A->snap();                         // 获取快照，返回 snap_id = 0
    printf("该数组的快照为 %d\n", sa1);
    snapshotArr_A->set(0, 6);
    int ga1 = snapshotArr_A->get(0, 0); // 获取 snap_id = 0 的快照中 array[0] 的值，返回 5
    printf("快照 指定索引 的值为 %d\n", ga1);

    SnapshotArray_B *snapshotArr_B = new SnapshotArray_B(3); // 初始化一个长度为 3 的快照数组
    snapshotArr_B->set(0, 5);                                // 令 array[0] = 5
    int sb1 = snapshotArr_B->snap();                         // 获取快照，返回 snap_id = 0
    printf("该数组的快照为 %d\n", sb1);
    snapshotArr_B->set(0, 6);
    int gb1 = snapshotArr_B->get(0, 0); // 获取 snap_id = 0 的快照中 array[0] 的值，返回 5
    printf("快照 指定索引 的值为 %d\n", gb1);
}