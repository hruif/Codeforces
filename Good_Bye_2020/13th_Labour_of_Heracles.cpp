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

struct Node {
	ll w;
	int es;
	Node() {};
	Node(ll w, int es) {
		this->w = w;
		this->es = es;
	}
	bool operator<(const Node a) const {
		return w < a.w;
	}
};

int t;
ll vals[100000];
vector<Node> nodes;

int main() {
	cin >> t;
	while (t--) {
		nodes.clear();

		int n;
		cin >> n;
		nodes.resize(n, Node(0, 0));

		ll sum = 0;
		F0R(i, n) {
			cin >> nodes[i].w;
			sum += nodes[i].w;
		}
		F0R(i, n - 1) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			nodes[u].es++;
			nodes[v].es++;
		}
		sort(nodes.begin(), nodes.end());

		vals[0] = sum;
		int p = n - 1;
		F0R(i, n - 2) {
			while (p >= 0 && nodes[p].es == 1) {
				p--;
			}
			if (p >= 0) {
				nodes[p].es--;
				sum += nodes[p].w;
			}
			vals[i + 1] = sum;
		}

		F0R(i, n - 1) {
			if (i != 0) cout << ' ';
			cout << vals[i];
		}
		cout << '\n';
	}
}