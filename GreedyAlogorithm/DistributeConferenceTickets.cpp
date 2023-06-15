#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//      Huawei: 分发大会门票

//      HC大会门票数量有限，组织者在前台分发门票，
//      并把每轮分发门票的时间点按时间先后顺序记录在数组distribute。
//      每轮有num张门票供分发，具体分发规则如下：
//          每位同事在分发时间点（含分发时间）之前到达才能领票
//          先到先得，一人一票，本轮余票作废
//          本轮没有拿到票的会等到下一轮派发，直到拿到票或者所有门票分发完毕
//      每位同事预计到达时间按时间先后顺序记录在数组arrive中，
//      假设你也想去参加大会，请问什么时候去保证可以拿到票？
//      示例1：
//          输入：distribute = {11, 20}
//              num = 2
//              arrive = {11,12,15,15,15}
//          输出：14
//      示例2：
//          输入：distribute = {13, 20}
//              num = 3
//              arrive = {11,11,11,12,16,17,18}
//          输出：15
//      提示：1 <= distriute.size() <= 10^3 distribute升序
//          1 <= distriute[i] <= 10^5 
//          1 <= num <= 100 
//          1 < arrive.size() <= 10^5 arrive升序
//          1 <= arrive[i] <= 10^5 

int DistributeConferenceTickets(vector<int> distribute, int num, vector<int> arrive);