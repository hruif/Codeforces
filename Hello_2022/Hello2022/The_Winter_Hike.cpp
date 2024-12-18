#include <iostream>
#include <algorithm>

using namespace std;

int t;
long long c[500][500];

int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n * 2; i++)
			for (int j = 0; j < n * 2; j++)
				cin >> c[i][j];

		long long ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				ans += c[i][j] + c[i + n][j + n];
		ans += min({ c[0][n], c[0][n * 2 - 1], c[n - 1][n], c[n - 1][n * 2 - 1], 
			c[n][0], c[n][n - 1], c[n * 2 - 1][0], c[n * 2 - 1][n - 1] });
		cout << ans << '\n';
	}
}