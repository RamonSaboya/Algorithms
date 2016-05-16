#include <bits/stdc++.h>
using namespace std;
#define pb push_back
stack<int> kosaraju;
stack<int> stck;
vector<int> adj[101];
vector<int> adj_inv[101];
bool mark[101];
int n = 7;
void dfs(int i) {
	printf("\nVisitando vértice: %d", i);
	mark[i] = true;
	for(int c = 0; c < adj[i].size(); c++) {
		if(!mark[adj[i][c]]) {
			printf(" -> chamando DFS para %d", adj[i][c]);
			stck.push(adj[i][c]);
			dfs(stck.top());
			stck.pop();
		}
	}
	kosaraju.push(i);
	printf(" -> voltando");
}
void invert() {
	for(int c = 1; c <= n; c++) for(int d = 0; d < adj[c].size(); d++) adj_inv[adj[c][d]].pb(c);
}
int main() {
	memset(mark, false, sizeof(mark));
	adj[1].pb(4);adj[1].pb(5);
	adj[2].pb(3);
	adj[3].pb(7);adj[3].pb(4);
	adj[4].pb(2);
	adj[5].pb(3);
	adj[6].pb(1);
	for(int c = 1; c <= n; c++) {
		if(!mark[c]) dfs(c);
	}
	puts("");
	invert();
	puts("");
	memset(mark, false, sizeof(mark));
	for(int c = 1; c <= n; c++) {
		int top = kosaraju.top();
		while(mark[top]) {
			kosaraju.pop();
			if(kosaraju.empty()) return 0;
			top = kosaraju.top();
		}
		mark[top] = true;
		printf("(%d", top);
		int ntop = top;
		for(int d = 0; d < adj_inv[ntop].size(); d++) {
			if(!mark[adj_inv[ntop][d]]) {
				mark[adj_inv[ntop][d]] = true;
				printf(", %d", adj_inv[ntop][d]);
				ntop = adj_inv[ntop][d];
				d = -1;
			}
		}
		printf(")\n");
	}
	return 0;
}
