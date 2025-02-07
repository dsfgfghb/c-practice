#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> num;
    stack<char> op;
    string s;

    while (getline(cin, s)) {
        if (s.empty()) break;  

        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                int val = 0;
                while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
                    val = val * 10 + (s[i] - '0');
                    i++;
                }
                num.push(val);
                i--;  
            } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                while (!op.empty() && ((op.top() == '*' || op.top() == '/') || (s[i] == '+' || s[i] == '-'))) {
                    if (num.size() < 2) {
                        cerr << "Error: Not enough operands" << endl;
                        return 1;
                    }
                    int b = num.top(); num.pop();
                    int a = num.top(); num.pop();
                    char c = op.top(); op.pop();
                    switch (c) {
                        case '+': num.push(a + b); break;
                        case '-': num.push(a - b); break;
                        case '*': num.push(a * b); break;
                        case '/': 
                            if (b == 0) {
                                cerr << "Error: Division by zero" << endl;
                                return 1;
                            }
                            num.push(a / b); 
                            break;
                    }
                }
                op.push(s[i]);
            }
        }

        while (!op.empty()) {
            if (num.size() < 2) {
                cerr << "Error: Not enough operands" << endl;
                return 1;
            }
            int b = num.top(); num.pop();
            int a = num.top(); num.pop();
            char c = op.top(); op.pop();
            switch (c) {
                case '+': num.push(a + b); break;
                case '-': num.push(a - b); break;
                case '*': num.push(a * b); break;
                case '/': 
                    if (b == 0) {
                        cerr << "Error: Division by zero" << endl;
                        return 1;
                    }
                    num.push(a / b); 
                    break;
            }
        }

        if (num.size() != 1) {
            cerr << "Error: Invalid expression" << endl;
            return 1;
        }

        cout << num.top() << endl;
        num.pop();
    }

    return 0;
}