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
#include <map>
#include <unordered_set>
#include <unordered_map>

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

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#ifdef LOCAL_DEBUG
ifstream fin("input.txt");
ofstream fout("output.txt");
#else
#define fin cin
#define fout cout
#endif

int t;
ll h[100];
ll psum[100];

int main() {
    fin >> t;
    while (t--) {
        int n;
        fin >> n;
        F0R(i, n) fin >> h[i];
        psum[0] = h[0];
        F0R(i, n - 1) psum[i + 1] = psum[i] + h[i + 1];
        int sum = 0;
        bool inc = true;
        F0R(i, n) {
            sum += i;
            if (sum > psum[i]) inc = false;
        }
        if (inc) fout << "YES\n";
        else fout << "NO\n";
    }
}