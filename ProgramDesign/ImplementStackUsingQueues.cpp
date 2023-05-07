#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//      LeetCode 225. 用队列实现栈

//      链接：https://leetcode.cn/problems/implement-stack-using-queues/

//      请你仅使用两个队列实现一个后入先出（LIFO）的栈，
//      并支持普通栈的全部四种操作（push、top、pop 和 empty）。
//      实现 MyStack 类：
//          void push(int x) 将元素 x 压入栈顶。
//          int pop() 移除并返回栈顶元素。
//          int top() 返回栈顶元素。
//          boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
//      注意：
//          你只能使用队列的基本操作
//          —— 也就是 push to back、peek/pop from front、size 和 is empty 这些操作。
//          你所使用的语言也许不支持队列。
//          你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 ,
//          只要是标准的队列操作即可。
//      示例：
//          输入：
//              ["MyStack", "push", "push", "top", "pop", "empty"]
//              [[], [1], [2], [], [], []]
//          输出：
//              [null, null, null, 2, 2, false]
//      解释：
//          MyStack myStack = new MyStack();
//          myStack.push(1);
//          myStack.push(2);
//          myStack.top(); // 返回 2
//          myStack.pop(); // 返回 2
//          myStack.empty(); // 返回 False
//      提示：
//          1 <= x <= 9
//          最多调用100 次 push、pop、top 和 empty
//          每次调用 pop 和 top 都保证栈不为空
//      进阶：你能否仅用一个队列来实现栈。

void printVal(int val)
{
    printf("%d\n", val);
}

void printBool(bool b)
{
    if (b == true)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
}

class MyStack1
{
public:
    
    queue<int> q1;
    queue<int> q2;

    MyStack1()
    {

    }

    void push(int x)
    {
        q1.push(x);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        swap(q1, q2);
    }

    int pop()
    {
        int top = q2.front();
        q2.pop();
        return top;
    }

    int top()
    {
        int top = q2.front();
        return top;
    }

    bool empty()
    {
        return q2.empty();
    }
};

class MyStack2
{
public:

    queue<int> q;

    MyStack2()
    {
    }

    void push(int x)
    {
        int size = q.size();
        q.push(x);
        for(int i = 0; i < size; i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int top = q.front();
        q.pop();
        return top;
    }

    int top()
    {
        int top = q.front();
        return top;
    }

    bool empty()
    {
        return q.empty();
    }
};

int main()
{
    MyStack1 *myStack1 = new MyStack1();
    myStack1->push(1);
    myStack1->push(2);
    int top11 = myStack1->top(); // 返回 2
    printVal(top11);
    myStack1->pop();             // 返回 2
    bool b11 = myStack1->empty(); // 返回 False
    printBool(b11);

    MyStack2 *myStack2 = new MyStack2();
    myStack2->push(1);
    myStack2->push(2);
    int top21 = myStack2->top(); // 返回 2
    printVal(top21);
    myStack2->pop();             // 返回 2
    bool b21 = myStack2->empty(); // 返回 False
    printBool(b21);
}