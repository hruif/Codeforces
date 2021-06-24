#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vb = vector<bool>;
using vc = vector<char>;
using pii = pair<int, int>;
using vpii = vector<pii>;

#define FORI(i, a, b, p) for (int i = a; i < b; i += p)
#define FOR(i, a, b) FORI(i, a, b, 1)
#define F0R(i,b) FOR(i, 0, b)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 1

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int t;

int gcf(int a, int b) {
	if (a % b == 0) return b;
	return gcf(b, a % b);
}

int main() {
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		map<pii, int> st;
		int cnt = 0;
		int maxl = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'D') cnt++;
			int tot = i + 1;
			int g = gcf(cnt, tot);
			cout << ++st[{cnt / g, tot / g}] << ' ';
		}
		cout << '\n';
	}
}