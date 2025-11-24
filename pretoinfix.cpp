#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string prefixToInfix(string prefix) {
    stack<string> s;

    // Scan from right to left
    for (int i = prefix.size() - 1; i >= 0; i--) {
        char ch = prefix[i];

        // If operand, push as string
        if (!isOperator(ch)) {
            s.push(string(1, ch));
        }
        else {
            // Pop two operands
            string op1 = s.top(); 
            s.pop();
            string op2 = s.top(); 
            s.pop();

            // Form infix expression
            string expr = "(" + op1 + " " + ch + " " + op2 + ")";

            // Push back to stack
            s.push(expr);
        }
    }
    return s.top();
}

int main() {
    string prefix;
    cout << "Enter Prefix Expression: ";
    cin >> prefix;

    string infix = prefixToInfix(prefix);
    cout << "Infix Expression: " << infix << endl;
    return 0;
}
