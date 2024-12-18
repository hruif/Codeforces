//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <utility>
//#include <string.h>
//#include <algorithm>
//#include <math.h>
//#include <string>
//#include <unordered_set>
//#include <unordered_map>
//
//using namespace std;
//using ll = long long;
//using vi = vector<int>;
//using vll = vector<ll>;
//using vc = vector<char>;
//using pii = pair<int, int>;
//using vpii = vector<pii>;
//
//#define FORI(i, a, b, p) for (int i = a; i < b; i += p)
//#define FOR(i, a, b) FORI(i, a, b, 1)
//#define F0R(i,b) FOR(i, 0, b)
//#define RFOR(i, a, b) for (int i = a; i >= b; i--)
//#define RF0R(i, a) RFOR(i, a, 0)
//
//#define MOD 1
//
//struct sp {
//	int d;
//	int k;
//	sp() {}
//	sp(int d, int k) {
//		this->d = d;
//		this->k = k;
//	}
//	bool operator<(const sp a) const {
//		if (k == a.k) return d < a.d;
//		return k < a.k;
//	}
//};
//
//int n, m;
//ll as[200000];
//ll ks[200000];
//sp ns[200000];
//
//int main() {
//	cin >> n >> m;
//	F0R(i, n) cin >> as[i];
//	F0R(i, m) cin >> ks[i];
//
//	ll sum = 0;
//	F0R(i, n) {
//		sum += as[i];
//		ll nk = sum / (i + 1);
//		if (sum % (i + 1) == 0) nk--;
//		ns[i] = sp(i, nk);
//	}
//	sort(ns, ns + n);
//
//	int p = 0;
//	F0R(i, m) {
//		while (p < n && ks[i] > ns[p].k) {
//			p++;
//		}
//		if (p == n) cout << "0 ";
//		else cout << n - ns[p].d - 1 << ' ';
//	}
//}