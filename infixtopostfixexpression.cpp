#include <iostream>
#include <cstring>

using namespace std;

class Stack {
private:
    int top;
    int maxSize;
    char* stackArray;

public:
    Stack(int size) {
        top = -1;
        maxSize = size;
        stackArray = new char[maxSize];
    }

    void push(char value) {
        if (top < maxSize - 1) {
            stackArray[++top] = value;
        }
    }

    char pop() {
        if (top >= 0) {
            return stackArray[top--];
        }
        return '\0';
    }

    char peek() {
        if (top >= 0) {
            return stackArray[top];
        }
        return '\0';
    }

    bool isEmpty() {
        return top == -1;
    }
};

int getPrecedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    else if (op == '*' || op == '/') {
        return 2;
    }
    else if(op='^'){return 3;}
    return 0;
}

string infixToPostfix(string infix) {
    Stack stack(infix.length());
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            stack.push(ch);
        }
        else if (ch == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix += stack.pop();
            }
            stack.pop();
        }
        else {
            while (!stack.isEmpty() && getPrecedence(ch) <= getPrecedence(stack.peek())) {
                postfix += stack.pop();
            }
            stack.push(ch);
        }
    }

    while (!stack.isEmpty()) {
        postfix += stack.pop();
    }

    return postfix;
}

int main() {
    string infixExpression;
    cout << "Enter an infix expression: ";
    cin >> infixExpression;

    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;

    return 0;
}
