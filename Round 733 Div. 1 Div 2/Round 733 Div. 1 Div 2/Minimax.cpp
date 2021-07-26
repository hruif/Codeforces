#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
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

#define MOD 998244353

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int t;
string s;

int main() {
	cin >> t;
	while (t--) {
		cin >> s;
		vi lets(26, 0);
		F0R(i, sz(s)) lets[s[i] - 'a']++;
		string ans;
		int first = 0;
		F0R(i, 26) {
			if (lets[i] == 1) {
				ans.push_back(i + 'a');
				lets[i]--;
				F0R(j, 26) {
					F0R(k, lets[j]) ans.push_back(j + 'a');
				}
				break;
			}
		}
		if (ans.empty()) {
			F0R(i, 26) {
				if (lets[i] > 0) {
					if (lets[i] > 1) {
						ans.push_back(i + 'a');
						ans.push_back(i + 'a');
						lets[i] -= 2;

						int firstchar = -1, secondchar = -1, nchars = 0;
						for (int j = i + 1; j < 26; j++) {
							if (lets[j] > 0) {
								if (firstchar == -1) firstchar = j;
								else if (secondchar == -1) secondchar = j;
								nchars++;
							}
						}
						if (nchars >= 1) {
							if (sz(s) - lets[i] - 2 >= lets[i]) {
								F0R(k, lets[firstchar]) {
									ans.push_back(firstchar + 'a');
									if (lets[i] > 0) {
										ans.push_back(i + 'a');
										lets[i]--;
									}
								}
								FOR(j, firstchar + 1, 26) {
									F0R(k, lets[j]) {
										ans.push_back(j + 'a');
										if (lets[i] > 0) {
											ans.push_back(i + 'a');
											lets[i]--;
										}
									}
								}
								F0R(k, lets[i]) ans.push_back(i + 'a');
							}
							else {
								ans.pop_back();
								lets[i]++;

								if (nchars > 1) {
									ans.push_back(firstchar + 'a');
									lets[firstchar]--;

									F0R(k, lets[i]) ans.push_back(i + 'a');
									lets[i] = 0;

									ans.push_back(secondchar + 'a');
									lets[secondchar]--;

									FOR(j, i + 1, 26) {
										F0R(k, lets[j]) ans.push_back(j + 'a');
									}

								}
								else {
									F0R(k, lets[firstchar]) ans.push_back(firstchar + 'a');
									F0R(k, lets[i]) ans.push_back(i + 'a');
								}
							}

							{
								//ans.push_back(firstchar + 'a');
								//lets[firstchar]--;

								//F0R(k, lets[i]) ans.push_back(i + 'a');
								//lets[i] = 0;
								//ans.push_back(secondchar + 'a');
								//lets[secondchar]--;

								//FOR(j, i + 1, 26) {
								//	F0R(k, lets[j]) ans.push_back(j + 'a');
								//	lets[j] = 0;
								//}
							}
						}
						else {
							F0R(k, lets[i]) ans.push_back(i + 'a');
						}
					}
					else {
						ans.push_back(i + 'a');
						for (int j = i + 1; j < 26; j++) {
							for (int k = 0; k < lets[j]; k++) {
								ans.push_back(j + 'a');
							}
						}
					}

					break;
				}
			}
		}
		cout << ans << '\n';
	}
}