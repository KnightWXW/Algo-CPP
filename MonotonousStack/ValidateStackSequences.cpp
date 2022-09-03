#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <stack>

using namespace std;

//      946. 验证栈序列
//      给定 pushed 和 popped 两个序列，每个序列中的 值都不重复，
//      只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop 操作序列的结果时，返回 true；
//      否则，返回 false 。

//      示例 1：
//      输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
//      输出：true
//      解释：我们可以按以下顺序执行：
//      push(1), push(2), push(3), push(4), pop() -> 4,
//      push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

//      示例 2：
//      输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
//      输出：false
//      解释：1 不能在 2 之前弹出。

//      提示：
//          1 <= pushed.length <= 1000
//          0 <= pushed[i] <= 1000
//          pushed 的所有元素 互不相同
//          popped.length == pushed.length
//          popped 是 pushed 的一个排列

void printVecElement(vector<int> vec);
bool validateStackSequences(vector<int> &pushed, vector<int> &popped);

int main()
{
    vector<int> pushed = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printVecElement(pushed);

    vector<int> popped;
    popped.assign(pushed.begin(), pushed.end());
    random_shuffle(popped.begin(), popped.end());
    printVecElement(popped);

    if (validateStackSequences(pushed, popped) == true)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
}

bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    stack<int> stack;
    int l = pushed.size();
    int index = 0;
    for (int i = 0; i < l; i++)
    {
        while (!stack.empty() && stack.top() == popped[index])
        {
            stack.pop();
            index++;
        }
        stack.push(pushed[i]);
    }

    while (!stack.empty() && stack.top() == popped[index])
    {
        stack.pop();
        index++;
    }

    return index == l;
}

void printVecElement(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}
