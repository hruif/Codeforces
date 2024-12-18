#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
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

#define MOD 998244353

struct El { // element
	int val;
	int ind;

	bool operator<(const El a) const { // sort smallest val to largest val
		if (val == a.val) { // if same val sort smallest ind to largest ind
			return ind < a.ind;
		}
		return val < a.val;
	}

	El() {}
	El(int val, int ind) {
		this->val = val;
		this->ind = ind;
	}
};

int t;
int a[200000];
El s[200000];

int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i]; // read into array
			s[i] = El(a[i], i); // read into elements array
		}
		sort(s, s + n); // sort elements array

		int p = n - 1; // pointer
		int cnt = 0; // count how many of a value
		int l = 1000000001;
		int r = -1;

		int maxval = s[p].val; // maxval in segs 1 & 3
		int minval = 1000000001; // minval in seg 2

		// separate case for maxval of array because l and r not set yet
		{
			while (s[p].val == maxval && p >= 0) { // count num of maxval
				cnt++;
				p--;
			}
			if (cnt >= 3) { // if 3 or more then yes
				l = min(l, s[p + 2].ind);
				r = max(r, s[p + 2].ind);
				cout << "YES"
					<< '\n' << l // x
					<< ' ' << r - l + 1 // y
					<< ' ' << n - (r + 1) // z
					<< '\n';
				continue;
			}

			for (int i = p + 1; s[i].val == maxval && i < n; i++) { // set l and r
				l = min(l, s[i].ind);
				r = max(r, s[i].ind);
			}

			for (int i = l; i <= r; i++) { // find minval of seg 2
				minval = min(minval, a[i]);
			}
		}

		cnt = 0;
		
		bool found = false; // if found valid partitioning
		while (true) {
			if (l <= 0 || r >= n - 1) { // break if no seg 1 or seg 2
				break;
			}

			maxval = s[p].val;

			// if (min val in seg 2) > (max in seg 1 & 3)
			if (maxval < minval) {
				cnt = 0;
				int tl = 0;
				int tr = 0;

				// check how many maxvals in seg 1 & in seg 2
				while (s[p].val == maxval && p >= 0) { 
					if (s[p].ind < l) {
						tl++;
					}
					if (s[p].ind > r) {
						tr++;
					}
					p--;
				}

				// check if can form valid partitioning with maxval
				{
					if (a[l - 1] == maxval && tl >= 2 && tr >= 1) {
						found = true;
						l--;
					}
					if (a[r + 1] == maxval && tr >= 2 && tl >= 1) {
						found = true;
						r++;
					}
				}

				if (found) {
					cout << "YES"
						<< '\n' << l
						<< ' ' << r - l + 1
						<< ' ' << n - (r + 1)
						<< '\n';
					break;
				}

				// update minval and l & r
				{
					for (int i = p + 1; s[i].val == maxval && i < n; i++) { // for all maxvals
						// change minval if smaller val found in l - r
						for (int j = s[i].ind; j < l; j++) {
							minval = min(minval, a[j]);
						}
						for (int j = r + 1; j <= s[i].ind; j++) {
							minval = min(minval, a[j]);
						}

						// change l & r to fit searched vals
						l = min(l, s[i].ind);
						r = max(r, s[i].ind);
					}
				}
			}

			// find one past minval in array while updating l and r
			{
				while (s[p].val >= minval && p >= 0) {
					if (s[p].val == minval) { // count minval if equals
						cnt++;
					}
					else {
						cnt = 0;

						// update minval and l & r
						{
							// change minval if smaller val found in l - r
							for (int i = s[p].ind; i < l; i++) {
								if (a[i] < minval) {
									minval = a[i];
								}
							}
							for (int i = r + 1; i <= s[p].ind; i++) {
								if (a[i] < minval) {
									minval = a[i];
								}
							}

							// change l & r to fit searched vals
							l = min(l, s[p].ind);
							r = max(r, s[p].ind);
						}
					}

					p--; // decrement p to search through array
				}
			}
			// at this point, p points to one past minval in array and 
			// cnt is how many of minval is in array

			if (cnt >= 3) {
				bool seg1;
				bool seg2;

				// check that at least one of minval is in seg1 and one in seg2
				{
					seg1 = false;
					seg2 = false;
					for (int i = p + 1; s[i].val == minval && i < n; i++) {
						if (s[i].ind < l) {
							seg1 = true;
						}
						if (s[i].ind > r) {
							seg2 = true;
						}
					}
				}

				if (seg1 && seg2) {
					cout << "YES"
						<< '\n' << l
						<< ' ' << r - l + 1
						<< ' ' << n - (r + 1)
						<< '\n';
					found = true;
					break;
				}
			}

			if (p <= 0) {
				break;
			}

			// update minval and l & r
			{
				for (int j = p + 1; s[j].val == minval && j < n; j++) {
					for (int i = s[j].ind; i < l; i++) {
						if (a[i] < minval) {
							minval = a[i];
						}
					}
					for (int i = r + 1; i <= s[j].ind; i++) {
						if (a[i] < minval) {
							minval = a[i];
						}
					}

					l = min(l, s[j].ind);
					r = max(r, s[j].ind);
				}
			}
		}
		if (!found) {
			cout << "NO\n";
		}
	}
}