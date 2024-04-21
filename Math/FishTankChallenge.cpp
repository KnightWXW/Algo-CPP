


//      Huawei: 鱼缸难题

//      最近小华买了 N 条鱼，小华想买一些鱼缸去装他们，
//      商店有两种鱼缸：
//          第一种：每个鱼缸价格是C1元，可以装N1条鱼
//          第二种：每个鱼缸价格是C2元，可以装N2条鱼
//      小华想把所有的鱼都养在买的那些鱼缸里，
//      而且每个鱼缸都要装满鱼，
//      小华很难计算出两种鱼缸各买多少个最实惠(总花费最小)，
//      请你使用程序帮小华计算出最实惠方案。
//      输入：
//          共三行:
//              整数 N
//              C1 N1 
//              C2 N2
//              所有数范围 [1, 2000000000]
//      输出：
//          每个用例占一行，对于不存在解的情况输出Failed
//          (即不能满足所有的鱼都装在鱼缸中且每个鱼缸都装满)
//          否则，请输出两个整数M1, M2
//          (表示第一种鱼缸买M1个，第二种鱼缸买M2个，保证是唯一解)
//      输入样例1：
//          43
//          1 3
//          2 4
//      输出样例1：
//          13 1

int FishTankChallenge(int fishes, int c1, int n1, int c2, int n2);
