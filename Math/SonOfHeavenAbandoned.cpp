#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

//      天弃之子

//      链接：https://www.nowcoder.com/questionTerminal/ba2b7b5d318c46dda811c644d9020de6

//      有一款游戏，过关的方式是按按钮。游戏一共有几关,每一关有a[i]个按钮,
//      其中只有唯一一个按钮是可以通关的,按下其他的按钮游戏就会失败。
//      好在这个游戏可以重来,而且由于设计者的疏忽,每一关的通关按钮是不变的,
//      所以你可以记住前几关的按钮,重来时就可以直接通关。
//      但是你的运气似乎用在了其他地方,你使用了最多的按按钮次数才成功通关。
//      求这个最多的按按钮次数吧!
//      输入一维数组a[i],表示每一关的按钮数
//          1 ≤ a[i] ≤ 10^5
//          1 ≤ a[i] 数组的长度 ≤ 10^5
//      输入    [1,1,4,5,1,4]
//      输出    49

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

long SonOfHeavenAbandoned(vector<int> buttons);

int main()
{
    int n = generateRandomNum(0, 30);
    vector<int> buttons = generateRandomVec(1, 20, n);
    printVecElement(buttons);
    long ans = SonOfHeavenAbandoned(buttons);
    printf("最多的按按钮次数 %d\n", ans);
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

// buttons[i] : 尝试 到正确按钮 通过 最少次数 为 buttons[i] - 1
// 每次走到 buttons[i] 需要 按 i + 1 次
// 加上最后完成成功通关 的 buttons.size() 次
long SonOfHeavenAbandoned(vector<int> buttons)
{
    long cnt = 0;
    for (int i = 0; i < buttons.size(); i++)
    {
        cnt += (i + 1) * (buttons[i] - 1);
    }
    cnt += buttons.size();
    return cnt;
}