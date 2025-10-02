class Solution {
public:
    int precedence(char o) {
        if (o == '*' || o == '/')
            return 2;
        if (o == '+' || o == '-')
            return 1;
        return 0;
    }
    int apply(int a, int b, char o) {
        if (o == '*')
            return a * b;
        if (o == '/')
            return a / b;
        if (o == '+')
            return a + b;
        if (o == '-')
            return a - b;
        return 0;
    }
    int calculate(string s) {
        // infix to postfix
        bool expectingOperand = true;
        int i;
        stack<char> o;
        int n = s.length();
        string p;
        for (i = 0; i < n; i++) {
            if (s[i] == ' ' || s[i] == '"')
                continue;
            if (isdigit(s[i])) {
                string number_str; // string for the whole int
                while (i < n && isdigit(s[i])) {
                    number_str += s[i];
                    i++;
                }
                p += number_str + ' '; // add the int
                i--;
                expectingOperand = false; // exp op
            } else if (s[i] == '(') {
                o.push(s[i]);
                expectingOperand = true; // exp int
            } else if (s[i] == ')') {
                while (!o.empty() && o.top() != '(') {
                    p += o.top();
                    p += ' ';
                    o.pop();
                }
                if (!o.empty())
                    o.pop();              // pop the )
                expectingOperand = false; // exp op

            } else {
                if (s[i] == '-' && expectingOperand) {
                    p += "0 ";
                }
                while (!o.empty() && precedence(o.top()) >= precedence(s[i])) {
                    p += o.top();
                    p += ' ';
                    o.pop();
                }
                o.push(s[i]);
                expectingOperand = true;
            }
        }
        while (!o.empty()) {
            p += o.top();
            p += ' ';
            o.pop();
        }
        stack<int> stk;
        stringstream ss(p);
        string token;
        while (ss >> token) {
            if (isdigit(token[0]) || (token[0] == '-' && token.length() > 1)) {
                stk.push(stoi(token));
            } else {
                if (stk.size() < 2) {
                    return 0;
                }
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                stk.push(apply(a, b, token[0]));
            }
        }
        return stk.top();
    }
};
