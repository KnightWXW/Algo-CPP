#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//      给定一个 有序数组arr，代表坐落在X轴上的点，
//      给定一个正数K，代表绳子的长度，返回绳子最多压中几个点？ 
//      即使绳子边缘处盖住点也算盖住 

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVec(vector<int> &vec);

int NumberofPointsCoveredbyRope(vector<int> vec, int K);

int main()
{
    int n = generateRandomNum(1, 30);
    vector<int> vec = generateRandomVec(1, 100, n);
    sort(vec.begin(), vec.end());
    int K = generateRandomNum(1, 2 * n);
    printVec(vec);
    int ans = TeemoAttacking(vec, maxOperations);
    printf("中毒持续时间的为 %d。艾希处于中毒状态的 总秒数为 %d ", duration, ans);
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

int NumberofPointsCoveredbyRope(vector<int> vec, int K){
    int l = vec.size();
}