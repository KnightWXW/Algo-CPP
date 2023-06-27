





//      Huawei: 二进制差异数

//      对于任意两个正整数A和B，定义它们之间的差异值和相似值：
//      差异值：A、 B转换成二进制后，对于二进制的每一位，对应位置的bit值不相同则为1，否则为0；
//      相似值：A、B转换成二进制后，对于二进制的每一位， 对应位置的bit值都为1则为1，否则为0；
//      现在有n个正整数A0到A(n-1) ，问有多少(i， j) (0<=kj<n)，Ai和Aj的差异值大于相似值。
//      假设A=5, B=3；则A的二进制表示101； B的二进制表示011；
//      则A与B的差异值二进制为110；相似值二进制为001；
//      A与B的差异值十进制等于6，相似值十进制等于1，满足条件。
//      输入输出
//          输入
//              一个n接下来个正整数
//          输出
//              满足差异值大于相似值的对数
//      样例1
//          输入
//              4
//              4352
//          输出：
//              4
//          说明：
//              4: 满足条件的分别是(0,1)(0,3)(1,2)(2,3)，共4对。

int BinaryDiffNum(int a, int b);