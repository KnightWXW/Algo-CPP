#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <numeric>
#include <algorithm>
#include <map>
#include <unordered_set>

using namespace std;

//      Huawei: 最大展厅人数

//      MWCS 展共有N个展厅，每个展厅的报名人数记于数组nums。
//      因疫情原因，所有展厅参展总人数上限为cnt
//      若报名人数之和大于cnt, 则需限制参展人数，
//      请计算单个展厅的最大参展人数 limit, 使得参展总人数不超过cnt,
//      参展限制规则为：
//          对于报名人数 不超过 limit 的展厅，凡报名即参展；
//          对于报名人数 超过 limit 的展厅，则均要求 limit 名人员参展；
//          若报名人数之和 小于等于 cnt, 此时不需要限制参展人数，请返回-1
//      请返回 limit 的最大值或 -1
//      示例一：
//          输入：
//              nums = [1,4,2,5,5,1,6]
//              cnt = 13
//          输出：2
//      示例二：
//          输入：
//              nums = [1,3,2,1]
//              cnt = 197
//          输出：-1
//      示例三：
//          输入：
//              nums = [1,1,]
//              cnt = 1
//          输出：0

int MaxNumOfExhibitionHalls(vector<int> nums, int cnt);



