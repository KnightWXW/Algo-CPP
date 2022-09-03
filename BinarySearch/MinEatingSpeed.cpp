#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//      875. 爱吃香蕉的珂珂

//      链接：https://leetcode.cn/problems/koko-eating-bananas/

//      珂珂喜欢吃香蕉。这里有 n 堆香蕉，第 i 堆中有 piles[i] 根香蕉。
//      警卫已经离开了，将在 h 小时后回来。
//      珂珂可以决定她吃香蕉的速度 k （单位：根/小时）。
//      每个小时，她将会选择一堆香蕉，从中吃掉 k 根。
//      如果这堆香蕉少于 k 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。  
//      珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。
//      返回她可以在 h 小时内吃掉所有香蕉的最小速度 k（k 为整数）。

//      示例 1：
//      输入：piles = [3,6,7,11], h = 8
//      输出：4

//      示例 2：
//      输入：piles = [30,11,23,4,20], h = 5
//      输出：30

//      示例 3：
//      输入：piles = [30,11,23,4,20], h = 6
//      输出：23
 
//      提示：
//          1 <= piles.length <= 104
//          piles.length <= h <= 109
//          1 <= piles[i] <= 109

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVec(vector<int> &vec);

int main(){
    vector<int> vec = generateRandomVec(1, 109, 100);
    int h = generateRandomNum(vec.size(), 109);
    printVec(vec);
    printf("珂珂在 %d 小时内吃掉所有香蕉的最小速度 k 为 %d", h, vec);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

vector<int> generateRandomVec(int low, int high, int len)
{
    vector<int> vec;
    srand(time(0));
    for (int i = 0; i < len; i++)
    {
        int v = (rand() % (high - low + 1)) + low;
        vec.push_back(v);
    }
    return vec;
}

void printVec(vector<int> &vec)
{
    printf("vector的元素依次为：");
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int minEatingSpeed(vector<int> piles, int h) {

}