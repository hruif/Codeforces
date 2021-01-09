#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>

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

struct seg {
	double x1, y1;
	double x2, y2;
	seg() {};
	seg(double x1, double y1, double x2, double y2) {
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;	
	}
};

int n, H;
double xs[100000], ys[100000];


int main() {
	cin >> n >> H;
	F0R(i, n) cin >> xs[i] >> ys[i];

	stack<seg> segs;
	double x1 = xs[0], y1 = ys[0];
	F0R(i, n - 1) {
		double x2 = xs[i + 1], y2 = ys[i + 1];
		segs.push(seg(x1, y1, x2, y2));

		seg ts = segs.top();
		double ydif = ys[n - 1] + H - ts.y2, xdif = xs[n - 1] - ts.x2;
		double b = ts.y2 - (ts.x2 * ydif / xdif);
		double simy = ts.x1 * ydif / xdif + b;
		if (simy <= ts.y1) continue;
		else segs.pop();
		ts = segs.top();
		simy = ts.x2 * ydif / xdif + b;
		while (simy > ts.y2) {
			int 
		}

		x1 = x2, y1 = y2;
	}
}