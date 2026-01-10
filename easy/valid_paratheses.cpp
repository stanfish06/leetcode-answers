#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> buf;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                buf.push(s[i]);
            } else {
                if (buf.empty()) {
                    return false;
                }
                char c = buf.top();
                if (s[i] == ')') {
                    if (c != '(') {
                        return false;
                    }
                } else if (s[i] == ']') {
                    if (c != '[') {
                        return false;
                    }
                } else {
                    if (c != '{') {
                        return false;
                    }
                }
                buf.pop();
            }
        }
        if (!buf.empty()) {
            return false;
        }
        return true;
    }
};
