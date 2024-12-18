#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vc = vector<char>;
using pii = pair<int, int>;
using vpii = vector<pii>;

#define FORI(i, a, b, p) for (int i = a; i < b; i += p)
#define FOR(i, a, b) FORI(i, a, b, 1)
#define FOR0(i,b) FOR(i, 0, b)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define RFOR0(i, a) RFOR(i, a, 0)

#define MOD 998244353

int t;
char table[100][100];
int moves[30000][2];

void st(int x, int y, int& mc) {
	if (table[x][y] == '0') {
		table[x][y] = '1';
	}
	else {
		table[x][y] = '0';
	}
	moves[mc][0] = x + 1;
	moves[mc][1] = y + 1;
	mc++;
}

bool is1(int x, int y) {
	return table[x][y] == '1';
}

void processSquare(int i, int j, int& mc) {
	int count = 0;
	bool ij = is1(i, j);
	bool i1j = is1(i + 1, j);
 	bool ij1 = is1(i, j + 1);
	bool i1j1 = is1(i + 1, j + 1);
	if (ij) {
		count++;
	}
	if (i1j) {
		count++;
	}
	if (ij1) {
		count++;
	}
	if (i1j1) {
		count++;
	}

	if (count == 0) {
		return;
	}
	if (count == 4) {
		st(i, j, mc);
		st(i + 1, j, mc);
		st(i, j + 1, mc);
		count = 1;
	}
	ij = is1(i, j);
	i1j = is1(i + 1, j);
	ij1 = is1(i, j + 1);
	i1j1 = is1(i + 1, j + 1);
	if (count == 1) {
		if (ij) {
			st(i, j, mc);
			st(i + 1, j, mc);
			st(i, j + 1, mc);
		}
		else {
			st(i, j + 1, mc);
			st(i + 1, j, mc);
			st(i + 1, j + 1, mc);
		}
		count++;
	}
	ij = is1(i, j);
	i1j = is1(i + 1, j);
	ij1 = is1(i, j + 1);
	i1j1 = is1(i + 1, j + 1);
	if (count == 2) {
  		int n1c = 0;
		if (!ij || n1c == 0) {
			st(i, j, mc);
			if (ij) {
				n1c++;
			}
		}
		if (!i1j || n1c == 0) {
			st(i + 1, j, mc);
			if (i1j) {
				n1c++;
			}
		}
		if (!ij1 || n1c == 0) {
			st(i, j + 1, mc);
			if (ij1) {
				n1c++;
			}
		}
		if (!i1j1 || n1c == 0) {
			st(i + 1, j + 1, mc);
			if (i1j1) {
				n1c++;
			}
		}
		count++;
	}
	ij = is1(i, j);
	i1j = is1(i + 1, j);
	ij1 = is1(i, j + 1);
	i1j1 = is1(i + 1, j + 1);
	if (count == 3) {
		if (ij) {
			st(i, j, mc);
		}
		if (i1j) {
			st(i + 1, j, mc);
		}
		if (ij1) {
			st(i, j + 1, mc);
		}
		if (i1j1) {
			st(i + 1, j + 1, mc);
		}
	}
}

int main() {
	cin >> t;
	while (t--) {
		memset(moves, 0, sizeof(moves));
		int n, m;
		cin >> n >> m;
		FOR0(i, n) {
			cin >> table[i];
		}
		int mc = 0;
		FOR0(i, n - 1) {
			FOR0(j, n - 1) {
				int count = 0;
				bool ij = is1(i, j);
				bool i1j = is1(i + 1, j);
				bool ij1 = is1(i, j + 1);
				bool i1j1 = is1(i + 1, j + 1);
				if (ij) {
					count++;
				}
				if (i1j) {
					count++;
				}
				if (ij1) {
					count++;
				}
				if (i1j1) {
					count++;
				}
				if (count == 3) {
					processSquare(i, j, mc);
				}
			}
		}
		FOR0(i, n - 1) {
			FOR0(j, n - 1) {
				int count = 0;
				bool ij = is1(i, j);
				bool i1j = is1(i + 1, j);
				bool ij1 = is1(i, j + 1);
				bool i1j1 = is1(i + 1, j + 1);
				if (ij) {
					count++;
				}
				if (i1j) {
					count++;
				}
				if (ij1) {
					count++;
				}
				if (i1j1) {
					count++;
				}
				if (count == 2) {
					processSquare(i, j, mc);
				}
			}
		}
		FOR0(i, n - 1) {
			FOR0(j, n - 1) {
				int count = 0;
				bool ij = is1(i, j);
				bool i1j = is1(i + 1, j);
				bool ij1 = is1(i, j + 1);
				bool i1j1 = is1(i + 1, j + 1);
				if (ij) {
					count++;
				}
				if (i1j) {
					count++;
				}
				if (ij1) {
					count++;
				}
				if (i1j1) {
					count++;
				}
				if (count == 1) {
					processSquare(i, j, mc);
				}
			}
		}
		FOR0(i, n - 1) {
			FOR0(j, n - 1) {
				int count = 0;
				bool ij = is1(i, j);
				bool i1j = is1(i + 1, j);
				bool ij1 = is1(i, j + 1);
				bool i1j1 = is1(i + 1, j + 1);
				if (ij) {
					count++;
				}
				if (i1j) {
					count++;
				}
				if (ij1) {
					count++;
				}
				if (i1j1) {
					count++;
				}
				if (count == 4) {
					processSquare(i, j, mc);
				}
			}
		}
		bool nOdd = n % 2 == 1;
		bool mOdd = m % 2 == 1;
		if (nOdd) {
			FORI(i, 0, m - 1, 2) {
				processSquare(n - 2, i, mc);
			}
		}
		if (mOdd) {
			FORI(i, 0, n - 1, 2) {
				processSquare(i, m - 2, mc);
			}
		}
		if (nOdd && mOdd) {
			processSquare(n - 2, m - 2, mc);
		}
		cout << mc / 3 << '\n';
		FORI(i, 0, mc, 3) {
			cout << moves[i][0] << ' ' << moves[i][1];
			FOR(j, 1, 3) {
				cout << ' ' << moves[i + j][0] << ' ' << moves[i + j][1];
			}
			cout << '\n';
		}
	}
}