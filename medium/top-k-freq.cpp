#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;

class Compare {
public:
  bool operator()(pair<int, int>* a, pair<int, int>* b) {
	return a->second < b->second;
  }    
};
class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
	unordered_map<int, pair<int, int>> lookup;
	priority_queue<pair<int, int>*, vector<pair<int, int>*>, Compare> topk;
	for (auto num : nums) {
	  if (!lookup.contains(num)) {
		lookup[num] = {num, 1};
	  } else {
		lookup[num].second++;
	  }
	}
	for (auto &[num, num_ct] : lookup) {
	  topk.push(&num_ct);
	}
	vector<int> result;
	for (int i = 0; i < k; i++) {
	  result.push_back(topk.top()->first);
	  topk.pop();
	}
	return result;
  }
};

int main() {
  Solution sol;
  vector<int> test = {-1,1,4,-4,3,5,4,-2,3,-1};
  vector<int> result = sol.topKFrequent(test, 2);
  for (auto num : result) {
	cout << num << endl;
  }
}
