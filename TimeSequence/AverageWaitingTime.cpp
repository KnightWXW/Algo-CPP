#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//      LeetCode 1701. 平均等待时间

//      链接：https://leetcode.cn/problems/average-waiting-time/

//      有一个餐厅，只有一位厨师。你有一个顾客数组 customers ，
//      其中 customers[i] = [arrivali, timei] ：
//          arrivali 是第 i 位顾客到达的时间，到达时间按 非递减 顺序排列。
//          timei 是给第 i 位顾客做菜需要的时间。
//      当一位顾客到达时，他将他的订单给厨师，厨师一旦空闲的时候就开始做这位顾客的菜。
//      每位顾客会一直等待到厨师完成他的订单。厨师同时只能做一个人的订单。
//      厨师会严格按照 订单给他的顺序 做菜。
//      请你返回所有顾客需要等待的 平均 时间。
//      与标准答案误差在 10-5 范围以内，都视为正确结果。
//      示例 1：
//          输入：customers = [[1,2],[2,5],[4,3]]
//          输出：5.00000
//          解释：
//          1) 第一位顾客在时刻 1 到达，厨师拿到他的订单并在时刻 1 立马开始做菜，并在时刻 3 完成，第一位顾客等待时间为 3 - 1 = 2 。
//          2) 第二位顾客在时刻 2 到达，厨师在时刻 3 开始为他做菜，并在时刻 8 完成，第二位顾客等待时间为 8 - 2 = 6 。
//          3) 第三位顾客在时刻 4 到达，厨师在时刻 8 开始为他做菜，并在时刻 11 完成，第三位顾客等待时间为 11 - 4 = 7 。
//          平均等待时间为 (2 + 6 + 7) / 3 = 5 。
//      示例 2：
//          输入：customers = [[5,2],[5,4],[10,3],[20,1]]
//          输出：3.25000
//          解释：
//          1) 第一位顾客在时刻 5 到达，厨师拿到他的订单并在时刻 5 立马开始做菜，并在时刻 7 完成，第一位顾客等待时间为 7 - 5 = 2 。
//          2) 第二位顾客在时刻 5 到达，厨师在时刻 7 开始为他做菜，并在时刻 11 完成，第二位顾客等待时间为 11 - 5 = 6 。
//          3) 第三位顾客在时刻 10 到达，厨师在时刻 11 开始为他做菜，并在时刻 14 完成，第三位顾客等待时间为 14 - 10 = 4 。
//          4) 第四位顾客在时刻 20 到达，厨师拿到他的订单并在时刻 20 立马开始做菜，并在时刻 21 完成，第四位顾客等待时间为 21 - 20 = 1 。
//          平均等待时间为 (2 + 6 + 4 + 1) / 4 = 3.25 。
//      提示：
//          1 <= customers.length <= 105
//          1 <= arrivali, timei <= 104
//          arrivali <= arrivali+1

double AverageWaitingTime(vector<vector<int>> &customers);

int main()
{
    vector<vector<int>> v1 = {{1, 2}, {2, 5}, {4, 3}};
    print2DVecElement(v1);
    double ans_A = AverageWaitingTime(v1);
    printf("所有顾客需要等待的 平均 时间 为 %f \n", ans_A);
    vector<vector<int>> v2 = {{5, 2}, {5, 4}, {10, 3}, {20, 1}};
    print2DVecElement(v2);
    double ans_B = AverageWaitingTime(v2);
    printf("所有顾客需要等待的 平均 时间 为 %f \n", ans_B);
}

void print2DVecElement(vector<vector<int>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for(int j = 0 ; j < vec[0].size(); j++)
        {
            printf("%d\t", vec[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

double AverageWaitingTime(vector<vector<int>> &customers)
{
    int l = customers.size();
    long long wait = 0;
    int time = customers[0][0];
    for (int i = 0; i < l; i++)
    {
        int arriveTime = customers[i][0];
        int costTime = customers[i][1];
        time = max(arriveTime, time) + costTime;
        wait += (time - arriveTime);
    }
    return wait * 1.0 / l;
}
