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
#include <cstdlib>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vb = vector<bool>;
using vc = vector<char>;
using pii = pair<int, int>;
using vpii = vector<pii>;

#define FORI(i, a, b, p) for (int i = a; i < b; i += p)
#define FOR(i, a, b) FORI(i, a, b, 1)
#define F0R(i,b) FOR(i, 0, b)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 1
#define RAND_MAX 1000000000000000000

int main() {
	ofstream fout("strangedef.in");
	fout << "100000\n";
	for (int i = 0; i < 100000; i++) {
		fout << "3\n" << rand() % 1000000 + 1
			<< ' ' << rand() % 1000000 + 1
			<< ' ' << rand() % 1000000 + 1 << '\n';
		fout << "3\n" << rand() % RAND_MAX
			<< '\n' << rand() % RAND_MAX
			<< '\n' << rand() % RAND_MAX << '\n';
	}
}