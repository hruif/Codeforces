#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
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

struct customer {
	int ind;
	int p;
	customer() {}
	customer(int ind, int p) {
		this->ind = ind;
		this->p = p;
	}
	bool operator<(const customer a) const{
		if (p == a.p) return ind > a.ind;
		return p < a.p;
	}
};

int q;
set<customer> prices;
bool served[500001];
int so[500001];

int main() {
	cin >> q;
	int customers = 0;
	int nexttoserve = 1;
	int ns = 0;
	F0R(i, q) {
		int query;
		cin >> query;
		if (query == 1) {
			int p;
			cin >> p;
			customers++;
			prices.insert(customer(customers, p));
		}
		if (query == 2) {
			while (served[nexttoserve]) nexttoserve++;
			served[nexttoserve] = true;
			so[ns++] = nexttoserve;
		}
		if (query == 3) {
			customer bestcust = *prices.crbegin();
			while (served[bestcust.ind]) {
				prices.erase(prices.find(bestcust));
				bestcust = *prices.crbegin();
			}
			served[bestcust.ind] = true;
			so[ns++] = bestcust.ind;
			prices.erase(prices.find(bestcust));
		}
	}
	F0R(i, ns) {
		if (i > 0) cout << ' ';
		cout << so[i];
	}
	cout << '\n';
}