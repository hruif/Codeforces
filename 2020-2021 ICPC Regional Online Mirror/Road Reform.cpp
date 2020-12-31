#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <climits>

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

struct PathTo {
	int con;
	int s;
	PathTo() {}
	PathTo(int con, int s) {
		this->con = con;
		this->s = s;
	}
	bool operator<(const PathTo a) const {
		return s > a.s;
	}
};

int t;
bool checked[200000];
int par[200000];
int minedge[200000];
queue<int> nodes;
priority_queue<PathTo> he;
vector<vector<PathTo>> E;

int main() {
	cin >> t;
	while (t--) {
		memset(minedge, -1, sizeof(minedge));
		memset(par, -1, sizeof(par));
		memset(checked, false, sizeof(checked));
		E.clear();

		int n, m, k;
		cin >> n >> m >> k;
		E.resize(n);
		F0R(i, m) {
			int x, y, s;
			cin >> x >> y >> s;
			x--, y--;
			E[x].push_back(PathTo(y, s));
			E[y].push_back(PathTo(x, s));
		}

		F0R(i, n) minedge[i] = INT_MAX;
		he.push(PathTo(0, 0));
		while (!he.empty()) {
			int node = he.top().con;
			int dist = he.top().s;
			he.pop();

			checked[node] = true;
			F0R(i, E[node].size()) {
				PathTo nnode = E[node][i];
				if (!checked[nnode.con] && nnode.s < minedge[nnode.con]) {
					minedge[nnode.con] = nnode.s;
					he.push(nnode);
					par[nnode.con] = node;
				}
			}
		}


		//while (!he.empty()) {
		//	PathTo curnode = he.top();
		//	he.pop();
		//	if (checked[curnode.con]) continue;
		//	checked[curnode.con] = true;
		//	F0R(i, E[curnode.con].size()) {
		//		if (!checked[E[curnode.con][i].con]) {
		//			minedge[E[curnode.con][i].con] = E[curnode.con][i].s;
		//			he.push(E[curnode.con][i]);
		//		}
		//		if (minedge[E[curnode.con][i].con] > E[curnode.con][i].s) {
		//			minedge[E[curnode.con][i].con] = E[curnode.con][i].s;
		//		}
		//	}
		//}
		

		//while (!nodes.empty()) {
		//	int node = nodes.front();
		//	nodes.pop();
		//	F0R(i, E[node].size()) {
		//		PathTo& nnode = E[node][i];
		//		if (par[nnode.con] == node) continue;
		//		if (!checked[nnode.con]) {
		//			checked[nnode.con] = true;
		//			nodes.push(nnode.con);
		//			par[nnode.con] = node;
		//		}
		//		if (nnode.s < minedge[nnode.con] || minedge[nnode.con] == -1) {
		//			minedge[nnode.con] = nnode.s;
		//			par[nnode.con] = node;
		//		}
		//	}
		//}
		ll move = 0;
		F0R(i, n) {
			if (minedge[i] != INT_MAX && minedge[i] > k) move += minedge[i] - k;
		}
		if (move == 0) {
			int minchange = 1000000001;
			F0R(i, n) {
				F0R(j, E[i].size()) {
					if (abs(E[i][j].s - k) < minchange) {
						minchange = abs(E[i][j].s - k);
					}
				}
			}
			cout << minchange << '\n';
		}
		else cout << move << '\n';
	}
}