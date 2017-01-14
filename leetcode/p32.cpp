#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		int l = s.size();
		if (l == 0) return 0;
		int res = 0;
		vector<int> f(l);
		int i;
		f[0] = 0;
		for (i = 1; i < l; i++) {
			if (s[i] == '(')
				f[i] = 0;
			else {
				if (i-1-f[i-1] >= 0 && s[i-1-f[i-1]] == '(') {
					f[i] = f[i-1] + 2;
					if (i-f[i] >= 0)
						f[i] += f[i-f[i]];
					if (f[i] > res)
						res = f[i];
				}
				else
					f[i] = 0;
			}
		}
		return res;
	}
};

int main() {
	cout << Solution().longestValidParentheses("") << endl;
	return 0;
}
