#include <iostream>
#include <stack>
#include <vector>
#include <cstdlib>

using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> s;

    for (const string& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();

            if (token == "+") s.push(operand1 + operand2);
            else if (token == "-") s.push(operand1 - operand2);
            else if (token == "*") s.push(operand1 * operand2);
            else if (token == "/") s.push(operand1 / operand2);
        }
        else {
            s.push(atoi(token.c_str()));
        }
    }

    return s.top();
}

int main() {
    // Example 1
    vector<string> tokens1 = { "2", "1", "+", "3", "*" };
    cout << "Example 1: " << evalRPN(tokens1) << endl;

    // Example 2
    vector<string> tokens2 = { "4", "13", "5", "/", "+" };
    cout << "Example 2: " << evalRPN(tokens2) << endl;

    // Example 3
    vector<string> tokens3 = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
    cout << "Example 3: " << evalRPN(tokens3) << endl;

    return 0;
}
