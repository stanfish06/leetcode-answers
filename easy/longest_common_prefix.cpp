#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string com_prefix = "";
        int pos = 0;
        int n_strs = strs.size();
        while(true) {
            // do not check str[i] == '\0', as accessing element beyond its size is a undefined behavior
            if (pos == strs[0].size()) break;
            char char_check = strs[0][pos];
            bool ok = true;
            for (int i = 1; i < n_strs; i++) { 
                if (pos == strs[i].size() || strs[i][pos] != char_check) {
                    ok = false;
                    break;
                };
            }
            if (!ok) break;
            com_prefix.append(1, char_check);
            pos++;
        }
        return com_prefix;
    }
};
