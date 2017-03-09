#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
#define mp make_pair
int main() {
	int n, d, k;	cin >> n >> d >> k;
	vector<int> x(n);
	for (int i = 0; i < n; i++)	cin >> x[i];
	deque<pii> dq;
	dq.push_back(mp(x[0], 0));
	pair<int, int> ansp;
	int ansv = 0;
	for (int i = 1; i < n; i++) {
		while (dq.size() != 0 && dq.back() > mp(x[i], i))	dq.pop_back();
		dq.push_back(mp(x[i], i));
		while (i - dq.front().second > d)	dq.pop_front();
		if (x[i] - dq.front().first > ansv) {
			ansv = x[i] - dq.front().first;
			ansp = mp(dq.front().second, i);
		}
	}
	if (ansv <= 0) {
		cout << 0 << endl;
	}
	else {
		cout << (long long)ansv*k << endl;
		cout << ansp.first << " " << ansp.second << endl;
	}
	return 0;
}
