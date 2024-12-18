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
//		int n;
//		cin >> n;
//		F0R(i, n) {
//			int v;
//			cin >> v;
//			found[v]++;
//		}
//		ll total = 0;
//		for (auto i : found) ff.push_back(i.first);
//		for (int i = 0; i < ff.size(); i++) {
//			int val = ff[i];
//			int s1 = found[val] + found[val + 1] + found[val + 2];
//			ll v1 = s1 - 2;
//			if (v1 >= 1) {
//				F0R(i, found[val]) {
//					total += (v1 * (v1 + 1)) / 2;
//					v1--;
//				}
//			}
//		}
//		cout << total << '\n';
//	}
//}