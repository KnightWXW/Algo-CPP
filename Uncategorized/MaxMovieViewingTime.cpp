#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//      小红书 最长观影时间

//      一场电影开始和结束时间可以用一个小数组来表示 ["07:30","12:00"] 
//      已知有2000场电影开始和结束都在同一天，这一天从00:00开始到23:59结束 
//      一定要选3场完全不冲突的电影来观看，返回最大的观影时间 
//      如果无法选出3场完全不冲突的电影来观看，返回-1 

int MaxMovieViewingTime();