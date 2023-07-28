#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <queue>

using namespace std;

//      LeetCode 1845. 座位预约管理系统

//      链接：https://leetcode.cn/problems/seat-reservation-manager/

//      请你设计一个管理 n 个座位预约的系统，座位编号从 1 到 n 。
//      请你实现 SeatManager 类：
//          SeatManager(int n) 初始化一个 SeatManager 对象，它管理从 1 到 n 编号的 n 个座位。
//              所有座位初始都是可预约的。
//          int reserve() 返回可以预约座位的 最小编号 ，此座位变为不可预约。
//          void unreserve(int seatNumber) 将给定编号 seatNumber 对应的座位变成可以预约。
//      示例 1：
//          输入：
//              ["SeatManager", "reserve", "reserve", "unreserve", "reserve",
//              "reserve", "reserve", "reserve", "unreserve"]
//              [[5], [], [], [2], [], [], [], [], [5]]
//          输出：
//              [null, 1, 2, null, 2, 3, 4, 5, null]
//          解释：
//              SeatManager seatManager = new SeatManager(5);
//                              初始化 SeatManager ，有 5 个座位。
//              seatManager.reserve();
//                              所有座位都可以预约，所以返回最小编号的座位，也就是 1 。
//              seatManager.reserve();
//                              可以预约的座位为 [2,3,4,5] ，返回最小编号的座位，也就是 2 。
//              seatManager.unreserve(2);
//                              将座位 2 变为可以预约，现在可预约的座位为 [2,3,4,5] 。
//              seatManager.reserve();
//                              可以预约的座位为 [2,3,4,5] ，返回最小编号的座位，也就是 2 。
//              seatManager.reserve();
//                              可以预约的座位为 [3,4,5] ，返回最小编号的座位，也就是 3 。
//              seatManager.reserve();
//                              可以预约的座位为 [4,5] ，返回最小编号的座位，也就是 4 。
//              seatManager.reserve();
//                              唯一可以预约的是座位 5 ，所以返回 5 。
//              seatManager.unreserve(5);
//                              将座位 5 变为可以预约，现在可预约的座位为 [5] 。
//      提示：
//          1 <= n <= 105
//          1 <= seatNumber <= n
//          每一次对 reserve 的调用，题目保证至少存在一个可以预约的座位。
//          每一次对 unreserve 的调用，题目保证 seatNumber 在调用函数前都是被预约状态。
//          对 reserve 和 unreserve 的调用 总共 不超过 105 次。

class SeatManager_A
{
public:
    vector<bool> seats;

    SeatManager_A(int n)
    {
        seats = vector<bool>(n, true);
    }

    int reserve()
    {
        for (int i = 0; i < seats.size(); i++)
        {
            if (seats[i] == true)
            {
                seats[i] = false;
                return i + 1;
            }
        }
        return -1;
    }

    void unreserve(int seatNumber)
    {
        seats[seatNumber - 1] = true;
    }
};

class SeatManager_B
{
public:
    priority_queue<int, vector<int>, greater<int>> seatspq;

    SeatManager_B(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            seatspq.push(i);
        }
    }

    int reserve()
    {
        int top = seatspq.top();
        seatspq.pop();
        return top;
    }

    void unreserve(int seatNumber)
    {
        seatspq.push(seatNumber);
    }
};

int main()
{
    SeatManager_A *seatManager_A = new SeatManager_A(5);
    int rA1 = seatManager_A->reserve();
    printf("预约结果为 %d\n", rA1);
    // 所有座位都可以预约，所以返回最小编号的座位，也就是 1 。
    int rA2 = seatManager_A->reserve();
    printf("预约结果为 %d\n", rA2);
    // 可以预约的座位为 [2,3,4,5] ，返回最小编号的座位，也就是 2 。
    seatManager_A->unreserve(2);
    // 将座位 2 变为可以预约，现在可预约的座位为 [2,3,4,5] 。
    int rA3 = seatManager_A->reserve();
    printf("预约结果为 %d\n", rA3);
    // 可以预约的座位为 [2,3,4,5] ，返回最小编号的座位，也就是 2 。
    int rA4 = seatManager_A->reserve();
    printf("预约结果为 %d\n", rA4);
    // 可以预约的座位为 [3,4,5] ，返回最小编号的座位，也就是 3 。
    int rA5 = seatManager_A->reserve();
    printf("预约结果为 %d\n", rA5);
    // 可以预约的座位为 [4,5] ，返回最小编号的座位，也就是 4 。
    int rA6 = seatManager_A->reserve();
    printf("预约结果为 %d\n", rA6);
    // 唯一可以预约的是座位 5 ，所以返回 5 。
    seatManager_A->unreserve(5);
    // 将座位 5 变为可以预约，现在可预约的座位为 [5] 。

    SeatManager_B *seatManager_B = new SeatManager_B(5);
    int rB1 = seatManager_B->reserve();
    printf("预约结果为 %d\n", rB1);
    // 所有座位都可以预约，所以返回最小编号的座位，也就是 1 。
    int rB2 = seatManager_B->reserve();
    printf("预约结果为 %d\n", rB2);
    // 可以预约的座位为 [2,3,4,5] ，返回最小编号的座位，也就是 2 。
    seatManager_B->unreserve(2);
    // 将座位 2 变为可以预约，现在可预约的座位为 [2,3,4,5] 。
    int rB3 = seatManager_B->reserve();
    printf("预约结果为 %d\n", rB3);
    // 可以预约的座位为 [2,3,4,5] ，返回最小编号的座位，也就是 2 。
    int rB4 = seatManager_B->reserve();
    printf("预约结果为 %d\n", rB4);
    // 可以预约的座位为 [3,4,5] ，返回最小编号的座位，也就是 3 。
    int rB5 = seatManager_B->reserve();
    printf("预约结果为 %d\n", rB5);
    // 可以预约的座位为 [4,5] ，返回最小编号的座位，也就是 4 。
    int rB6 = seatManager_B->reserve();
    printf("预约结果为 %d\n", rB6);
    // 唯一可以预约的是座位 5 ，所以返回 5 。
    seatManager_B->unreserve(5);
    // 将座位 5 变为可以预约，现在可预约的座位为 [5] 。
}
