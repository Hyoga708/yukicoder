#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
	ll n, k;	cin >> n >> k;
	vector<int> a(n), pos(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];	a[i]--;
		pos[a[i]] = i;
	}
	ll need = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != i) {
			need++;
			swap(a[i], a[pos[i]]);
			swap(pos[a[i]], pos[a[pos[i]]]);
		}
	}
	if (need > k)	cout << "NO" << endl;
	else if ((k - need) % 2 == 0)	cout << "YES" << endl;
	else	cout << "NO" << endl;
	return 0;
}
