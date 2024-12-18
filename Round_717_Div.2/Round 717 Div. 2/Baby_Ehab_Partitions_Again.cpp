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

int n;
int a[100];

int main() {
	cin >> n;
	F0R(i, n) cin >> a[i];
	set<int> s1, s2;
	s1.insert(0);
	int sum = 0;
	F0R(i, n) {
		int v = a[i];
		sum += v;
		for (auto j : s1) {
			s2.insert(i);
			s2.insert(i + v);
		}
		s1 = s2;
		s2.clear();
	}
	if (s1.find(sum / 2) != s1.end() && sum % 2 == 0) {
		cout << 0 << '\n';
	}
}