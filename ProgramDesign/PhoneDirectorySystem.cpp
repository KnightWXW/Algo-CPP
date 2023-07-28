#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <map>

using namespace std;

//      LeetCode 379 电话目录管理系统

//      链接：https://leetcode-cn.com/problems/design-phone-directory/

//      设计一个电话目录管理系统，让它支持以下功能：
//          int get(): 分配给用户一个未被使用的电话号码，获取失败请返回 -1
//          bool check(int number): 检查指定的电话号码是否被使用
//          void release(int number): 释放掉一个电话号码，使其能够重新被分配
//      示例
//          // 初始化电话目录，包括 3 个电话号码：0，1 和 2。
//          PhoneDirectory directory = new PhoneDirectory(3);
//          // 可以返回任意未分配的号码，这里我们假设它返回 0。
//          directory.get();
//          // 假设，函数返回 1。
//          directory.get();
//          // 号码 2 未分配，所以返回为 true。
//          directory.check(2);
//          // 返回 2，分配后，只剩一个号码未被分配。
//          directory.get();
//          // 此时，号码 2 已经被分配，所以返回 false。
//          directory.check(2);
//          // 释放号码 2，将该号码变回未分配状态。
//          directory.release(2);
//          // 号码 2 现在是未分配状态，所以返回 true。
//          directory.check(2);

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

class PhoneDirectorySystem
{
public:
    int maxNum;
    vector<bool> phoneDir;

    PhoneDirectorySystem(int maxNumbers)
    {
        maxNum = maxNumbers;
        phoneDir = vector<bool>(maxNumbers, true);
    }

    int Get()
    {
        int ans = -1;
        for (int i = 0; i < maxNum; i++)
        {
            if (phoneDir[i] == true)
            {
                phoneDir[i] = false;
                return i;
            }
        }
        return ans;
    }

    bool Check(int number)
    {
        return phoneDir[number];
    }

    void Release(int number)
    {
        phoneDir[number] = true;
    }
};

int main()
{
    PhoneDirectorySystem *phoneDirectorySystem = new PhoneDirectorySystem(3);
    int g1 = phoneDirectorySystem->Get();
    printf("获取结果 为: %d\n", g1);
    int g2 = phoneDirectorySystem->Get();
    printf("获取结果 为: %d\n", g2);
    bool c1 = phoneDirectorySystem->Check(2);
    printf("检查结果 为:\n");
    printBool(c1);
    int g3 = phoneDirectorySystem->Get();
    printf("获取结果 为: %d\n", g3);
    bool c2 = phoneDirectorySystem->Check(2);
    printf("检查结果 为:\n");
    printBool(c2);
    phoneDirectorySystem->Release(2);
    bool c3 = phoneDirectorySystem->Check(2);
    printf("检查结果 为:\n");
    printBool(c3);
}
