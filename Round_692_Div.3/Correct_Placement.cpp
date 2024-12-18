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
using vc = vector<char>;
using pii = pair<int, int>;
using vpii = vector<pii>;

#define FORI(i, a, b, p) for (int i = a; i < b; i += p)
#define FOR(i, a, b) FORI(i, a, b, 1)
#define F0R(i,b) FOR(i, 0, b)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 1

struct Person {
	int w, h, i;
	Person() {}
	Person(int w, int h) {
		this->w = w;
		this->h = h;
	}
	bool operator<(const Person a) const {
		return h < a.h;
	}
};

int t;
int sd[200000];
Person people[200000];
int mins[200000][2];
vi nextp;

bool sortws(Person a, Person b) {
	return a.w < b.w;
}

int main() {
	cin >> t;
	while (t--) {
		nextp.clear();

		int n;
		cin >> n;
		nextp.resize(n, -1);
		F0R(i, n) {
			cin >> people[i].h >> people[i].w;
			people[i].i = i;
		}
		sort(people, people + n);

		int minw = people[0].w, mini = 0;
		F0R(i, n) {
			if (people[i].w < minw) {
				minw = people[i].w;
				mini = i;
			}
			mins[i][0] = minw;
			mins[i][1] = mini;
		}
		F0R(i, n) sd[i] = people[i].h;
		RF0R(i, n - 1) {
			int p = lower_bound(sd, sd + n, people[i].h) - sd - 1;
			if (p < 0) break;
			if (mins[p][0] >= people[i].w) continue;
			nextp[people[i].i] = people[mins[p][1]].i;
		}
		sort(people, people + n, sortws);
		int minh = people[0].h;
		mini = 0;
		F0R(i, n) {
			if (people[i].h < minh) {
				minh = people[i].h;
				mini = i;
			}
			mins[i][0] = minh;
			mins[i][1] = mini;
		}
		F0R(i, n) sd[i] = people[i].w;
		RF0R(i, n - 1) {
			int p = lower_bound(sd, sd + n, people[i].h) - sd - 1;
			if (p < 0) continue;
			if (mins[p][0] >= people[i].w) continue;
			nextp[people[i].i] = people[mins[p][1]].i;
		}

		F0R(i, n) {
			if (i != 0) cout << ' ';
			cout << nextp[i] + (nextp[i] == -1 ? 0 : 1);
		}
		cout << '\n';
	}
}