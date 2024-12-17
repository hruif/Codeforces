
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
int a[200000];
int sa[200000];
map<ll, int> cnts;
vi dp;
vll psum;

int main() {
    while (t--) {
        int n;
        fin >> n;
        F0R(i, n) fin >> a[i];
        F0R(i, n) sa[i] = a[i];
        F0R(i, n) cnts[a[i]]++;
        sort(sa, sa + n);
        dp[0] = n;
        FOR(i, 1, n + 1) {
            dp[i] = dp[i - 1] - 
        }  
        int bestans = n;
        F0R(i, n) {

        }
    }
}