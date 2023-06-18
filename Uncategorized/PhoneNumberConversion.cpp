





//      Huawei: 电话号码转换

//      某语音翻译软件，需要实现如下中英文电话号码转换功能：
//      若输入的是英文数字单词或Double组成的电话号码，则输出对应的中文数字单词
//      若输入的是中文数字单词组成的电话号码，则输出对应的英文数字单词
//      若输入不合法，则输出字符串ERROR
//      中文数字，英文数字分别见下表：
//          中文数字单词：Yi Er San Si Wu Liu Qi Ba Jiu Ling
//          英文数字单词：One Two Three Four Five Six Seven Eight Nine Zero
//      说明：
//          1、输入若存在Double，其后必须跟随英文数字单词，代表两个该数字。
//              如输入DoubleSix，代表 SixSix
//          2、输入保证要么全中文，要么全英文（含Double）,
//              并且每个单词都是合法的英文的数字单词/中文数字单词/Double
//          3、输入不合法的场景，仅为Double后跟随的不是英文数字单词，如DoubleLiu非法。
//      输入:
//          一行仅有大小写字母组成的字符串，非空且长度不大于500
//      输出：
//          一个字符串，表示转换后的电话号码，若输入不合法输出ERROR
//      示例1：
//          输入
//              SixOneThreeOneDoubleZero
//          输出
//              LiuYiSanYiLingLing
//      示例2：
//          输入
//              YiLingSanSanJiu
//          输出
//              OneZeroThreeThreeNine
//      示例3：
//          输入
//              DoubleLiu
//          输出
//              ERROR

string PhoneNumberConversion(string phone);
