#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// Convert prefix to postfix
string prefixToPostfix(string prefix) {
    stack<string> st;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (isalnum(ch)) {
            st.push(string(1, ch));
        } else {
            string a = st.top(); st.pop();
            string b = st.top(); st.pop();
            st.push(a + b + ch);
        }
    }
    return st.top();
}

// Evaluate postfix expression (NO range-based loop)
int evaluatePostfix(string postfix) {
    stack<int> st;
    for (int i = 0; i < postfix.length(); i++) {   // normal loop
        char ch = postfix[i];

        if (isdigit(ch)) {
            st.push(ch - '0');  // convert char to number
        } else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            switch (ch) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
            }
        }
    }
    return st.top();
}

int main() {
    string prefix;
    cout << "Enter prefix: ";
    cin >> prefix;

    string postfix = prefixToPostfix(prefix);
    cout << "Postfix = " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Evaluation Result = " << result << endl;

    return 0;
}
