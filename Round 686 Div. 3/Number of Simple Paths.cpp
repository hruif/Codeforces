#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
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

#define MOD 998244353

int t;
vector<int> connected[200000];
vector<int> treesizes;

int parents[200000];
bool visited[200000];
vector<int> cycle;
bool foundCycle = false;
void findCycle(int p) {
	cycle.push_back(p); // assume is part of cycle
	if (visited[p]) { // check if closes cycle
		foundCycle = true;
		return;
	}

	visited[p] = true; // mark as visited

	for (int i = 0; i < connected[p].size(); i++) { // look at all connected nodes
		int next = connected[p][i];
		if (next == parents[p]) { // cannot go go back to parent node
			continue;
		}

		parents[next] = p; // set parent
		findCycle(next); // find cycle with p in it

		if (foundCycle) { // returns if found cycle
			return;
		}
	}

	cycle.pop_back(); // is not part of cycle - would have return earlier if was
}

int findtreesize(int p) {
	int size = 1; // size = 1 for current node
	visited[p] = true;

	for (int i = 0; i < connected[p].size(); i++) {
		int next = connected[p][i];
		if (!visited[next]) {
			size += findtreesize(next);
		}
	}
	return size;
}

int main() {
	cin >> t; // test cases
	while (t--) { // loop through test cases
		ll total = 0; // total number of simple paths

		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			a--; // decrement because arrays used are 0-indexed
			b--;
			connected[a].push_back(b); // paths are bidirectional
			connected[b].push_back(a);
		}

		memset(parents, -1, sizeof(parents));
		memset(visited, false, sizeof(visited));
		foundCycle = false;
		findCycle(0); // find cycle 

		while (cycle[0] != cycle.back()) { // while first element in array not equal to start of cycle
			cycle.erase(cycle.begin()); // erase first element of array
		}
		cycle.pop_back(); // erase last element because first element is the same

		int cs = cycle.size();

		memset(visited, false, sizeof(visited));
		for (int i = 0; i < cs; i++) { // set nodes in cycle to visited so tree search doesn't look into cycle
			visited[cycle[i]] = true;
		}
		for (int i = 0; i < cs; i++) {
			visited[cycle[i]] = false; // set to-be-searched node to unvisited to count in tree
			treesizes.push_back(findtreesize(cycle[i])); // find tree size and add to vector
		}

		

		for (int i = 0; i < cs; i++) {
			ll ts = treesizes[i];
			total += ts * (ts - 1) / 2;
			total += ts * (n - ts);
		}
		cout << total << '\n';
		for (int i = 0; i < n; i++) {
			connected[i].clear();
		}
		treesizes.clear();
		cycle.clear();
	}
}