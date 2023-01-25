#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;

//      Huawei: 港口卸货

//      智能港口需实现一个卸货机制：有若干艘都装有 6 个集装箱的货轮即将到达港口，
//      所有货轮到达港口的时刻 t 记录于一维升序数组 time 中（非严格递增）。
//      港口有 num 个起重机，每个起重机每单位时间可完成一个集装箱的卸货。
//      若一艘货轮在时刻 t 到达港口：
//          如果在 t + limit 时刻前无法完成其所有集装箱的卸货，则该货轮无需卸货，
//          直接进入驳船区等待人工卸货；
//          否则尽早完成该艘货轮的卸货；一旦开始卸货，所用的起重机不允许被抢占。
//      请问有多少艘货轮需进入驳船区等待人工卸货。
//      注意： 货轮仅在到达港口后才可卸货；多个起重机可同时对一个货轮进行卸货工作。
//      示例 1：
//          输入：
//              num = 4
//              time = [1,1,3]
//              limit = 2
//          输出：1
//          解释：如下图所示
//              时刻 1 船 0 到，完成一艘货轮卸货的时刻为 3，未超过时间限制；
//              时刻 1 再到 船 1，完成这艘货轮的卸货需要到时刻 4，会超出 1+2 的时间限制，因此这一艘货轮需要进入驳船区；
//              时刻 3 到达 船 2，完成这艘货轮卸货的时刻为 5，未超过时间限制；
//              因此共有 1 艘货轮需要进入驳船区，返回 1。
//      示例 2：
//          输入：
//              num = 5
//              time = [1,2,2,3,3,4,5,5]
//              limit = 3
//          输出：3
//          解释：如下图所示，
//              时刻 1 到达 1 艘货轮，完成 船0 卸货的时刻为 3；
//              时刻 2 到达 2 艘货轮，完成 船1 卸货的时刻为 4，完成 船2 卸货的时刻为 5；
//              时刻 3 到达 2 艘货轮，完成 船3 卸货的时刻为 6；船4 无法在规定时间内完成卸货，因此需要进入驳船区；
//              时刻 4 到达 1 艘货轮，完成 船5 卸货的时刻为 7；
//              时刻 5 到达 2 艘货轮，完成任意一艘卸货的时刻都为 9，超过时间限制；因此 2 艘货轮均需进入驳船区；
//              因此共有 3 艘货轮需要进入驳船区，返回 3。
//      示例 3：
//          输入：
//              num = 20
//              time = [3,3,5,5,5,5,5,5]
//              imit = 2
//          输出：0
//      提示：
//          1 <= num <= 20
//          1 <= limit <= 100
//          1 <= time.length <= 1000
//          1 <= time[i] <= time[i+1] <= 10^4
//          非严格递增：对于数组arr，都有 arr[i] <= arr[i+1]。

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

int GetManualUnloadingNum_A(int num, const vector<int> &time, int limit);
int GetManualUnloadingNum_B(int num, const vector<int> &time, int limit);

int main()
{
    int n = generateRandomNum(1, 1000);
    vector<int> vec = generateRandomVec(1, 100, n);
    sort(vec.begin(), vec.end());
    int num = generateRandomNum(1, 20);
    int limit = generateRandomNum(1, 20);
    printVecElement(vec);
    int ans_A = GetManualUnloadingNum_A(num, vec, limit);
    int ans_B = GetManualUnloadingNum_B(num, vec, limit);
    printf("港口有 %d 个起重机, 限制时间为 %d ,\n", num, limit);
    printf("有 %d 艘货轮需进入驳船区等待人工卸货。\n", ans_A);
    printf("港口有 %d 个起重机, 限制时间为 %d ,\n", num, limit);
    printf("有 %d 艘货轮需进入驳船区等待人工卸货。\n", ans_B);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

void printVecElement(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

vector<int> generateRandomVec(int low, int high, int len)
{
    srand((int)time(0));
    vector<int> vec;
    for (int i = 0; i < len; i++)
    {
        int v = (rand() % (high - low + 1)) + low;
        vec.push_back(v);
    }
    return vec;
}

// 模拟：
// Time: O(N)
// Space: O(1)
int GetManualUnloadingNum_A(int num, const vector<int> &time, int limit)
{
    int l = time.size();
    const int CONTAINER_NUM = 6;
    int costTime = 0;        // 记录当前船舶 消耗时间
    int startTime = time[0]; // 记录当前船舶 开始时间
    int endTime = 0;         // 记录当前船舶 结束时间
    int extraFlag = 0;       // 记录 当前 是否重新开始
    int extraPos = 0;        // 记录 当前 偏移位置
    int preExtraPos = 0;     // 记录 之前 的 偏移位置，如果不进码头，就赋回原值。
    int ans = 0;
    for (int i = 0; i < l; i++)
    {
        if (startTime < time[i])
        {
            startTime = time[i];
            extraPos = 0;
        }
        preExtraPos = extraPos;
        costTime = (CONTAINER_NUM + extraPos) / num;
        extraPos = (CONTAINER_NUM + extraPos) % num;
        extraFlag = extraPos > 0 ? 1 : 0;
        endTime = startTime + costTime + extraFlag;
        if (endTime > time[i] + limit)
        {
            ans++;
            extraPos = preExtraPos;
        }
        else
        {
            startTime = endTime - extraFlag;
        }
    }
    return ans;
}

// 优先队列：
// Time: O(N)
// Space: O(N)
int GetManualUnloadingNum_B(int num, const vector<int> &time, int limit)
{
    int l = time.size();
    const int CONTAINER_NUM = 6;
    int ans = 0;
    // 优先队列：小根堆
    // Key: pq[0]: 集装箱被处理的时刻
    //      pq[1]: 起重机的编号
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for (int i = 0; i < num; i++)
    {
        pq.push({0, i});
    }

    for (int i = 0; i < l; i++)
    {
        int endTime = time[i] + limit;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> tempq = pq;
        int curGoods = 0;
        while (curGoods < CONTAINER_NUM)
        {
            auto top = pq.top();
            pq.pop();
            // 无法在规定时间处理该艘船的货物，回退数据
            if (top[0] >= endTime)
            {
                ans++;
                pq = tempq;
                break;
            }
            // 起重机从第一个开始处理，更正时间
            // 卸货时间不可能早于到达港口的时间
            else if (top[0] <= time[i])
            {
                pq.push({time[i] + 1, top[1]});
            }
            // 
            else
            {
                pq.push({top[0] + 1, top[1]});
            }
            curGoods++;
        }
    }
    return ans;
}