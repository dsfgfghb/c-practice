// #include <iostream>
// #include <stack>
// using namespace std;

// int main() {
//     stack<int> num;
//     stack<char> op;
//     string s;

//     while (getline(cin, s)) {
//         if (s.empty()) break;

//         for (int i = 0; i < s.length(); i++) {
//             if (s[i] >= '0' && s[i] <= '9') {
//                 int val = 0;
//                 while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
//                     val = val * 10 + (s[i] - '0');
//                     i++;
//                 }
//                 num.push(val);
//                 i--;
//             } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
//                 while (!op.empty() && ((op.top() == '*' || op.top() == '/') || (s[i] == '+' || s[i] == '-'))) {
//                     if (num.size() < 2) {
//                         cerr << "Error: Not enough operands" << endl;
//                         return 1;
//                     }
//                     int b = num.top(); num.pop();
//                     int a = num.top(); num.pop();
//                     char c = op.top(); op.pop();
//                     switch (c) {
//                         case '+': num.push(a + b); break;
//                         case '-': num.push(a - b); break;
//                         case '*': num.push(a * b); break;
//                         case '/':
//                             if (b == 0) {
//                                 cerr << "Error: Division by zero" << endl;
//                                 return 1;
//                             }
//                             num.push(a / b);
//                             break;
//                     }
//                 }
//                 op.push(s[i]);
//             }
//         }

//         while (!op.empty()) {
//             if (num.size() < 2) {
//                 cerr << "Error: Not enough operands" << endl;
//                 return 1;
//             }
//             int b = num.top(); num.pop();
//             int a = num.top(); num.pop();
//             char c = op.top(); op.pop();
//             switch (c) {
//                 case '+': num.push(a + b); break;
//                 case '-': num.push(a - b); break;
//                 case '*': num.push(a * b); break;
//                 case '/':
//                     if (b == 0) {
//                         cerr << "Error: Division by zero" << endl;
//                         return 1;
//                     }
//                     num.push(a / b);
//                     break;
//             }
//         }

//         if (num.size() != 1) {
//             cerr << "Error: Invalid expression" << endl;
//             return 1;
//         }

//         cout << num.top() << endl;
//         num.pop();
//     }

//     return 0;
// }
#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <algorithm> // for std::remove
#include <iomanip>   // for std::fixed and std::setprecision
using namespace std;

struct node
{
    double num;
    char op;
    bool flag;
};

string str;
stack<node> s;
map<char, int> op;
queue<node> q;

void Change()
{
    node temp;
    for (int i = 0; i < str.length();)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            temp.flag = true;
            temp.num = 0; // 初始化 num
            temp.op = '\0'; // 初始化 op
            temp.num = str[i++] - '0';
            while (i < str.length() && str[i] >= '0' && str[i] <= '9')
            {
                temp.num = temp.num * 10 + (str[i] - '0');
                i++;
            }
            q.push(temp); // 将数字节点推入队列
        }
        else if (str[i] == '(') // 处理左括号
        {
            temp.flag = false;
            temp.op = str[i];
            s.push(temp);
            i++;
        }
        else if (str[i] == ')') // 处理右括号
        {
            while (!s.empty() && s.top().op != '(')
            {
                q.push(s.top());
                s.pop();
            }
            if (!s.empty()) s.pop(); // 弹出左括号
            i++;
        }
        else
        {
            temp.flag = false;
            temp.op = str[i];
            while (!s.empty() && op[str[i]] <= op[s.top().op])
            {
                q.push(s.top());
                s.pop();
            }
            s.push(temp);
            i++;
        }
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

double Cal()
{
    double temp1, temp2;
    node cur, temp;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (cur.flag == true)
            s.push(cur);
        else
        {
            temp2 = s.top().num;
            s.pop();
            temp1 = s.top().num;
            s.pop();
            temp.flag = true;
            if (cur.op == '+')
                temp.num = temp1 + temp2;
            else if (cur.op == '-')
                temp.num = temp1 - temp2;
            else if (cur.op == '*')
                temp.num = temp1 * temp2;
            else if (cur.op == '/')
            {
                if (temp2 == 0)
                {
                    cerr << "Error: Division by zero" << endl;
                    return 0; // 返回错误值
                }
                temp.num = temp1 / temp2;
            }
            s.push(temp);
        }
    }
    return s.top().num;
}

int main()
{
    op['+'] = op['-'] = 1;
    op['*'] = op['/'] = 2;
    while (getline(cin, str), str != "0")
    {
        // 去除空格
        str.erase(remove(str.begin(), str.end(), ' '), str.end());
        while (!s.empty())
            s.pop();
        Change();
        double result = Cal();
        if (result != 0) // 如果结果不为错误值
        {
            cout << fixed << setprecision(2) << result << endl;
        }
    }
    return 0;
}