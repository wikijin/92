#include <iostream>
#include <string>
#include <limits>
#include <stack>
#include <math.h>
using namespace std;

///calculate fuction
double cal(char op, double x, double y) {
    if (op == '+')
        return x + y;
    else if (op == '-')
        return y - x;
    else if (op == '*')
        return x * y;
    else
        return y / x;
}

///deal with the expression.

double calculator(string expression) {

   ///make two stacks ,one contains number, one contains operator


    stack<double> number;
    number.push(0.0);
    stack<char> op;
    int count = expression.length();
    int bracket_count = 0;
    for (int i = 0; i < count; ++i) {
        if (expression[i] == ' ')
            continue;


        ///deal with the number

        else if (expression[i] >= '0' && expression[i] <= '9') {
            string temp = "";
            while (i < count) {
                temp += expression[i];
                if (i < count - 1 && ((expression[i + 1] >= '0' && expression[i + 1] <= '9') || expression[i + 1] == '.'))
                    ++i;
                else
                    break;
            }

            ///deal with scientific notation


            double x = stod(temp);
            if (i < count - 1 && (expression[i + 1] == 'E' || expression[i + 1] == 'e')) {
                ++i;
                bool flag = true;
                if (i < count - 1 && (expression[i + 1] == '+' || expression[i + 1] == '-')) {
                    if (expression[i + 1] == '-')
                        flag = false;
                    ++i;
                }
                string base = "";
                while (i < count && (expression[i + 1] >= '0' && expression[i + 1] <= '9')) {
                    base = base + expression[++i];
                }
                if (flag)
                    x = x * (pow(10.0, stod(base)));
                else
                    x = x / (pow(10.0, stod(base)));
            }
            number.push(x);
        }

        ///deal with the weighted of operator
        else if (expression[i] == '+' || expression[i] == '-') {
            while (!op.empty() && (op.top() == '*' || op.top() == '/')) {
                char signal = op.top();
                op.pop();
                if (number.empty()) {
                    cout << "something is wrong !" << endl;
                    return (double) INT_MIN;
                }
                double x = number.top();
                number.pop();
                if (number.empty()) {
                    cout << "something is wrong !" << endl;
                    return (double) INT_MIN;
                }
                double y = number.top();
                number.pop();
                number.push(cal(signal, x, y));
            }
            op.push(expression[i]);
        }
        else if (expression[i] == '*' || expression[i] == '/') {
            op.push(expression[i]);
        }
        else if (expression[i] == '(') {
            op.push('(');
            bracket_count++;
        }
        else if (expression[i] == ')') {
            bracket_count--;
            while (!op.empty() && op.top() != '(') {
                char signal = op.top();
                op.pop();
                if (number.empty()) {
                    cout << "something is wrong !" << endl;
                    return (double) INT_MIN;
                }
                double x = number.top();
                number.pop();
                if (number.empty()) {
                    cout << "something is wrong !" << endl;
                    return (double) INT_MIN;
                }
                double y = number.top();
                number.pop();
                number.push(cal(signal, x, y));
            }
            if (op.empty()) {
                cout << "*****Missing ( " << endl;
                return (double) INT_MIN;
            } else {
                op.pop();
            }
        }
        else if (expression[i] == '=') {
            break;
        }
        else {
            cout << "*****Unexpected " << expression[i] << endl;
            return (double) INT_MIN;
        }
    }
    if (bracket_count > 0) {
        cout << "***** Missing )" << endl;
        return (double) INT_MIN;
    }
    if (bracket_count < 0) {
        cout << "***** Missing (" << endl;
        return (double) INT_MIN;
    }
    while (!op.empty()) {
        char signal = op.top();
        op.pop();
        if (number.empty()) {
            cout << "something is wrong !" << endl;
            return (double) INT_MIN;
        }
        double x = number.top();
        number.pop();
        if (number.empty()) {
            cout << "something is wrong !" << endl;
            return (double) INT_MIN;
        }
        double y = number.top();
        number.pop();
        number.push(cal(signal, x, y));
    }
    return number.top();
}

int main()
{
    string line;
    cout << "Expression? ";
    while (getline(cin, line))
    {
        if (line == ".") {
            cout << "done!" << endl;
            break;
        }

        double result = calculator(line);
        if (result != (double) INT_MIN)
            cout << result << endl;
        cout << "Expression? " ;
    }
    return 0;
}