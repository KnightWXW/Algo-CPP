


//      LintCode 964 食物集合

//      链接：https://www.lintcode.com/problem/964/

//      给定一个长度为n个二元组数组lunch表示午餐食物集合，
//      其中lunch[i][0]表示第i种食物的热量，lunch[i][1]表示第i种食物的美味程度
//      再给定一个长度为m个二元组数组dinner表示晚餐食物集合，
//      其中dinner[i][0]表示第i种食物的热量，dinner[i][1]表示第i种食物的美味程度
//      请你在午餐集合和晚餐集合各自选取至多一个食物，在满足总的美味程度不小于T的前提下，
//      返回摄入最少的热量和。

//      1≤n,m≤10 
//      1≤lunch[i][0],lunch[i][1],dinner[i][0],dinner[i][1]≤10 5
 
//      如果不能满足条件则返回'-1'(不包括空格)
//      样例
//          输入:[[10,10],[20,20]]
//              [[20,30],[30,30]]
//              40
//      输出:30
//      解释:可以选出吃午餐的第0个食物和晚餐的第0个食物，
//          美味程度为40，摄入热量为30


int GetMinCalories(vector<vector<int>> &lunch, vector<vector<int>> &dinner, int t) 
