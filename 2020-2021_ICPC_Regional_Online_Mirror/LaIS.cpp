#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vc = vector<char>;
using pii = pair<int, int>;
using vpii = vector<pii>;

#define FORI(i, a, b, p) for (int i = a; i < b; i += p)
#define FOR(i, a, b) FORI(i, a, b, 1)
#define F0R(i,b) FOR(i, 0, b)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 1

int t;
vi a;
vi st;

void setst(int n) {
	int stn = 1;
	while (stn < n) stn *= 2;
	st.resize(stn * 2, 0);
}

void setmax(int k, int x) {
	int stn = st.size() / 2;
	k += stn;

	st[k] = max(st[k], x);
	for (k /= 2; k >= 1; k /= 2) {
		st[k] = max(st[k * 2], st[k * 2 + 1]);
	}
}

int findmax(int b) {
	int stn = st.size() / 2;
	
	int a = stn;
	b += stn;
	int m = 0;
	while (a <= b) {
		if (a % 2 == 1) m = max(m, st[a++]);
		if (b % 2 == 0) m = max(m, st[b--]);
		a /= 2;
		b /= 2;
	}
	return m;
}

int main() {
	cin >> t;
	while (t--) {
		a.clear();
		st.clear();

		int n;
		cin >> n;
		a.resize(n);
		F0R(i, n) {
			cin >> a[i];
			a[i]--;
		}
		setst(n);

		stack<int> low;
		F0R(i, n) {
			int m = max(findmax(a[i]) + 1, i == 0 ? 1 : 2);
			setmax(a[i], m);
			while (!low.empty()) {
				int l = low.top();
				if (l > a[i]) break;
				low.pop();
				if (l == a[i]) continue;
				setmax(l, st[l + st.size() / 2] + 1);
			}
			low.push(a[i]);
		}
		int stn = st.size() / 2;
		int m = 0;
		F0R(i, n) {
			m = max(m, st[i + stn]);
		}
		cout << m << '\n';
	}
}