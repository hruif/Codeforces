#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <climits>
#include <array>

using namespace std;
using ll = long long;
using str = string;

using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vb = vector<bool>;
using vc = vector<char>;
using vstr = vector<string>;
using pii = pair<int, int>;
using vpii = vector<pii>;

#define sz(x) (int)(x.size())
#define rsz resize
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define pb push_back
#define eb emplace_back

#define lb lower_bound
#define ub upper_bound

// for loops
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define F0R(i, b) FOR(i, 0, b)
#define F1R(i, b) FOR(i, 1, b)
#define F0R2(i, j, a, b) F0R(i, a) F0R(j, b)
#define RFOR(i, a, b) for (int i = a - 1; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD (ll)(1e9 + 7)

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int t;
ll n, a, b, c;
vector<int> cnt;
string s;

void set_cnt() {
	// converts s into int array with the number of 1's and 0's in each group

	cnt.clear();
	vector<int> cnt0, cnt1;
	// separates them into groups of 0's or 1's
	for (int i = 0; i < n; i++) {
		int p = i;
		while (p < n && s[p] == s[i]) p++;
		if (s[i] == s[0]) cnt0.push_back(p - i);
		else cnt1.push_back(p - i);
		i = p - 1;
	}
	int g0 = -1, gb = -1;
	if (s[0] == '0') {
		g0 = cnt0[0];
		cnt0.erase(cnt0.begin());
	}
	if (s.back() == '0') {
		if (s[0] == '0' && cnt0.size() > 0) {
			gb = cnt0.back();
			cnt0.pop_back();
		}
		else if (s[0] == '1') {
			gb = cnt1.back();
			cnt1.pop_back();
		}
	}
	// sorts so I deal with smallest groups first
	sort(cnt0.begin(), cnt0.end());
	sort(cnt1.begin(), cnt1.end());
	if (g0 > -1) cnt0.insert(cnt0.begin(), g0);
	if (gb > -1) {
		if (s[0] == '0') cnt0.push_back(gb);
		else cnt1.push_back(gb);
	}

	for (int i = 0; i < min(cnt0.size(), cnt1.size()); i++) {
		cnt.push_back(cnt0[i]);
		cnt.push_back(cnt1[i]);
	}
	if (cnt0.size() > cnt1.size()) 
		cnt.push_back(cnt0.back()); 

	// ensures that cnt[i % 2 = 0] is always a group of 0's and cnt[i % 2 = 1] is always a group of 1's
	if (s.back() == '1') cnt.push_back(0);
	reverse(cnt.begin(), cnt.end());
}

bool process_evens(int& oi, int& z1i, int& z2i, ll& ans) {
	if (z1i > 0) { // if there exists a "101" 
		// ("if" instead of "while" because there should never appear more than one "101" at a time)
		// processes proceeding "11" operation as well

		ans += b - c; // add to answer
		cnt[z1i - 1] += cnt[z1i + 1] - 1; // add ones from right group to left group

		// change oi accordingly
		if (oi == z1i + 1) oi = z1i - 1;
		if (cnt[z1i - 1] >= 2) oi = max(oi, z1i - 1); 

		// delete zero and one groups
		cnt.erase(cnt.begin() + z1i + 1); 
		cnt.erase(cnt.begin() + z1i);

		z1i = 0; // reset z1i
	}
	if (z2i < 0) { // if no more groups of two or more 0's 

		// at this point there are no "101"s either (those are processed above), so I check for "01..." or "...10"
		// if b <= c or there are no more groups of two or more 1's, never optimal
		if (b <= c || oi < 0) return false;

		// if it is either "01..." or "...10" then continue, otherwise return
		if (cnt[0] > 0) {
			cnt[0]--;
			ans -= c;
		}
		else if (cnt.size() % 2 && cnt.back() > 0) {
			cnt.back()--;
			ans -= c;
		}
		else return false;
	}
	else { // there is a group of two or more 0's

		cnt[z2i]--; // subtract from group
		ans += a; // add to answer
		if (cnt[z2i] < 2) { // if the group is now smaller than two

			// set z1i if z2i is valid
			if (b > c && z2i < cnt.size() - 1 && z2i > 0) // b must be > c and z1i can't be beginning or end
				z1i = z2i; 

			// go to next group of two or more 0's
			while (z2i >= 0 && cnt[z2i] < 2) z2i -= 2; 
		}
	}
	return true;
}

bool bt;
void solve() {
	if (t == 9999) cin >> a >> b >> c;
	else cin >> n >> a >> b >> c;
	ll init = 0;
	cin >> s;
	if (b > c) { // if b > c, first turn 101's to 1's
		string act = "";
		for (int i = 0; i < n; i++) {
			// skip and add score if reached "101" - else add to string
			if (i > 0 && i < n - 1 && s[i] == '0' && s[i - 1] == s[i + 1] && s[i - 1] == '1') {
				init += b - c;
				i++;
			}
			else act.push_back(s[i]);
		}
		s = act;
		n = act.size();
	}
	ll ans[2] = { 0, 0 }; // 0 - first remove 1, 1 - first remove 0


	for (int ans_p = 0; ans_p < 2; ans_p++) {
		set_cnt();

		int cn = cnt.size();
		int oi = -1, // last index with group of two or more 1's
			z1i = -1, // index of 0 in "101"
			z2i = -1;  // last index with group of two or more 0's

		// sets oi and z2i (z1i will always be -1 due to preprocessing)
		for (int i = 1; i < cn; i += 2)
			if (cnt[i] >= 2)
				oi = i;
		for (int i = 0; i < cn; i += 2)
			if (cnt[i] >= 2)
				z2i = i;

		// for case where I remove a 0 first
		if (ans_p == 1)
			if (!process_evens(oi, z1i, z2i, ans[ans_p])) break;

		while (oi >= 0) { // while there is group of two or more 1's
			cnt[oi]--; // decrease group
			ans[ans_p] += b; // add to answer

			// go to next group two or more 1's
			while (oi >= 0 && cnt[oi] < 2) oi -= 2;

			if (!process_evens(oi, z1i, z2i, ans[ans_p])) break;
		}
	}

	if (true) cout << max(ans[0], ans[1]) + init << '\n';
	else if (10000 - t == 7791) {
		cout << 1 << '\n';
		cout << n << ' ' << a << ' ' << b << ' ' << c << '\n';
		cout << s << '\n';
	}
}

int main() {
	fast_cin();

	cin >> t;
	if (t == 10000) {
		cin >> n;
		if (n == 5) bt = true;
	}
	while (t--)
		solve();
}