#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
int solve(string s) {
	if (s.size() < 3)	return 0;
	int ret = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0')	continue;
		for (int j = i + 1; j < s.size(); j++) {
			if (s[i] == s[j])	continue;
			for (int k = j + 1; k < s.size(); k++) {
				if (s[j] != s[k])	continue;
				int add = 100 * (s[i] - '0') + 11 * (s[j] - '0');
				string t = s;
				t.erase(t.begin() + k);	t.erase(t.begin() + j);	t.erase(t.begin() + i);
				ret = max(ret, add + solve(t));
			}
		}
	}
	return ret;
}
int main() {
	string s;	 cin >> s;
	cout << solve(s) << endl;
}
