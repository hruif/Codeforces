#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <unordered_set>
#include <unordered_map>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vc = vector<char>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vvi = vector<vi>;
using vvpii = vector<vpii>;
using umii = unordered_map<int, int>;

#define FORI(i, a, b, p) for (int i = a; i < b; i += p)
#define FOR(i, a, b) FORI(i, a, b, 1)
#define FOR0(i,b) FOR(i, 0, b)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define RFOR0(i, a) RFOR(i, a, 0)

#define MOD 998244353

int n;
int arr[200000];
int numCount[101];
vvpii dels;
umii findDels;
int max;

bool notUnique(int l, int r) {
	int nCount[101];
	memset(nCount, 0, sizeof(nCount));
	FOR(i, l, r + 1) {
		nCount[arr[i]]++;
	}
	sort(nCount, nCount + 101);
	return nCount[100] == nCount[99];
}

bool subExist(int l, int r) {
	if (notUnique(l, r)) {
		return true;
	}

}

int main() {
	cin >> n;
	FOR0(i, n) {
		cin >> arr[i];
		numCount[arr[i]]++;
	}
	int high = 0, highNum;
	int secHigh = 0, secHighNum;
	FOR0(i, 101) {
		if (numCount[i] > high) {
			high = numCount[i];
			highNum = i;
		}
		else if (numCount[i] > secHigh) {
			secHigh = numCount[i];
			secHighNum = i;
		}
	}
	int seg = 0;
	FOR0(i, n) {
		if (arr[i] == highNum) {
			dels.push_back(vpii());
			for (auto j : findDels) {
				pii tmp(j.first, j.second);
				dels[seg].push_back(tmp);
			}
			seg++;
			findDels.clear();
		}
		else {
			findDels[arr[i]]++;
		}
	}
	dels.push_back(vpii());
	for (auto j : findDels) {
		pii tmp(j.first, j.second);
		dels[seg].push_back(tmp);
	}
	seg++;
	findDels.clear();

	if (subExist()) {
		cout << max << '\n';
	}
	else {
		cout << "0\n";
	}
}