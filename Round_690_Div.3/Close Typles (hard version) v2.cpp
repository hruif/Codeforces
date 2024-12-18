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
//#define MOD 998244353
//
//int t;
//vector<int> ff;
//unordered_map<int, int> found;
//
//int main() {
//	cin >> t;
//	while (t--) {
//		found.clear();
//		ff.clear();
//
//		int n, m, k;
//		cin >> n >> m >> k;
//		F0R(i, n) {
//			int v;
//			cin >> v;
//			found[v]++;
//		}
//		ll total = 0;
//		ll s1 = 0;
//		F0R(i, k + 1) {
//			s1 += found[i];
//		}
//		for (int i = 1; i <= n; i++) {
//			s1 -= found[i - 1];
//			s1 += found[i + k];
//			ll v1 = s1 - 1;
//			ll tttl = 1;
//			if (v1 >= 1) {
//				int r = v1 < found[i] ? v1 : found[i];
//				F0R(j, r) {
//					tttl *= v1 + 1;
//					v1--;
//				}
//				tttl %= MOD;
//			}
//			tttl /= (m + 1) * m / 2;
//			total += tttl;
//		}
//		cout << total << '\n';
//	}
//}