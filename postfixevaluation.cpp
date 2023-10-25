#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int evaluatePostfix(string expression) {
    stack<int> stack;
    int n = expression.length();

    for (int i = 0; i < n; i++) {
        char c = expression[i];

        if (isdigit(c)) {
            stack.push(c - '0'); // Convert character to integer
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (stack.size() < 2) {
                cout << "Invalid postfix expression" << endl;
                return -1;
            }

            int operand2 = stack.top();
            stack.pop();
            int operand1 = stack.top();
            stack.pop();

            switch (c) {
                case '+':
                    stack.push(operand1 + operand2);
                    break;
                case '-':
                    stack.push(operand1 - operand2);
                    break;
                case '*':
                    stack.push(operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        cout << "Division by zero error" << endl;
                        return -1;
                    }
                    stack.push(operand1 / operand2);
                    break;
            }
        }
    }

    if (stack.size() == 1) {
        return stack.top();
    } else {
        cout << "Invalid postfix expression" << endl;
        return -1;
    }
}

int main() {
    string postfixExpression = "42*5+";
    int result = evaluatePostfix(postfixExpression);

    if (result != -1) {
        cout << "Result of postfix expression '" << postfixExpression << "' is: " << result << endl;
    }

  
  return 0;
}
