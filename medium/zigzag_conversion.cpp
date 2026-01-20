#include<string>
#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<int> last_bag(numRows, 0);
        vector<int> last_bag_cumsum(last_bag.size());
        string str_out = s;
        int bag_size = numRows > 1 ? (2 * numRows - 2) : 1;
        int n_bags = s.size() / bag_size; 
        int n_remains = s.size() - bag_size * n_bags;
        for (int i = 0; i < n_remains; i++) {
            int i_row = -1;
            if (i < numRows) {
                i_row = i;
            } else {
                i_row = numRows - (i - numRows + 2);
            }
            last_bag[i_row]++;
        }
        partial_sum(last_bag.begin(), last_bag.end(), last_bag_cumsum.begin());

        // process full bags
        for (int i = 0; i < (n_bags + 1); i++) {
            int i_start = i * bag_size;
            if (i_start >= s.size()) {
                continue;
            }
            for (int j = 0; j < bag_size; j++) {
                int i_row = -1;
                int i_char = i_start + j;
                if (i_char >= s.size()) {
                    break;
                }
                // vertical
                if (j < numRows) {
                    i_row = j;
                } else {
                    i_row = numRows - (j - numRows + 2);
                }
                int last_bag_incre = i_row > 0 ? last_bag_cumsum[i_row - 1] : 0;
                // handle last partial bag
                int i_pos = 2 * max(i_row - 1, 0) * n_bags + last_bag_incre + min(i_row, 1) * n_bags + (2 * (i_row > 0 && i_row < (numRows - 1)) + (i_row == 0 || i_row == (numRows - 1))) * i + (j >= numRows);
                str_out[i_pos] = s[i_char];
            }
        }
        return str_out;
    }
};

// Alternative solution (do not use map<int, string>, map is less efficient then vector in this case)
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        vector<string> rows(min(numRows, (int)s.size()));
        int curRow = 0;
        bool goingDown = false;
        
        for (char c : s) {
            rows[curRow] += c;
            
            if (curRow == 0 || curRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            curRow += goingDown ? 1 : -1;
        }
        
        string result;
        for (string& row : rows) {
            result += row;
        }
        
        return result;
    }
};
