#include <iostream>
#include <string>
using namespace std;

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return -1;
}

string infixToPostfix(string infix) {
    char stack[100];
    int top = -1;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            stack[++top] = c;
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix += stack[top--];
            }
            top--;
        } else {
            while (top != -1 && precedence(c) <= precedence(stack[top])) {
                postfix += stack[top--];
            }
            stack[++top] = c;
        }
    }

    while (top != -1) {
        postfix += stack[top--];
    }

    return postfix;
}

int main() {
    string infix = "((A+B)-C*(D/E))+F";
    cout << "Postfix expression: " << infixToPostfix(infix) << endl;
    return 0;
}
