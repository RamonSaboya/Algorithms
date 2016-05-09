#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpi;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
#define s1(x) scanf("%d", &(x))
#define s2(x, y) scanf("%d %d", &(x), &(y))
#define s3(x, y, z) scanf("%d %d %d", &(x), &(y), &(z))
#define sd1(x) int (x); scanf("%d", &(x))
#define sd2(x, y) int (x), (y); scanf("%d %d", &(x), &(y))
#define sd3(x, y, z) int (x), (y), (z); scanf("%d %d %d", &(x), &(y), &(z))
#define sc(x) scanf("%c", &(x))
#define sl(x) scanf("%lld", &(x))
#define sf(x) scanf("%lf", &(x))
#define ss(x) scanf("%s", (x))
#define sa1(a, x) fa(i, 0, x) scanf("%d", &a[i])
#define sa2(a, x, y) fa(i, 0, (x) * (y)) scanf("%d", &a[0][i])
#define fa(a, x, y) for(int (a) = (x); (a) < (y); (a)++)
#define fd(a, x, y) for(int (a) = (x); (a) <= (y); (a)--)
#define foreach(it, c) for(typeof((c).begin()) (it) = (c).begin(); (it) != (c).end(); (it)++)
#define all(c) (c).begin(), (c).end()
#define contains(x, c) (find(all(c), x) != (c).end())
#define mcontains(x, c) ((c).find(x) != (c).end())
#define fill(x, v) memset((x), (v), sizeof(x))
#define asz(x) ((int) (sizeof(x)/sizeof((x)[0])))
#define sorta(a) sort(a, (a) + asz(a))
#define sortd(a) sort(a, (a) + asz(a), greater<int>())
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))
#define abs(x) ((x) < 0 ? (-x) : (x))
#define in(i, l, r) ((l) < (i) && (i) < (r))
#define linr(i, l, r) ((l) <= (i) && (i) <= (r))
#define lin(i, l, r) ((l) <= (i) && (i) < (r))
#define inr(i, l, r)  ((l) < (i) && (i) <= (r))
#define cti(c) (c - '0')
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define strs stringstream
#define X first
#define Y second
int current = 1;
vi table[27];
inline void grow() {
	fa(i, 0, 26) table[i].pb(-1);
	table[26].pb(0);
}
void insert(string str, int last = 0, int c = 0) {
	if(c == str.size()) {
		table[26][last]++;
		return;
	}
	if(table[str[c] - 'a'][last] == -1) {
		grow();
		table[str[c] - 'a'][last] = current++;
		last = current - 1;
	} else {
		last = table[str[c] - 'a'][last];
	}
	insert(str, last, c + 1);
}
int count(string str, int last = 0, int c = 0) {
	if(c == str.size()) {
		return table[26][last];
	}
	if(table[str[c] - 'a'][last] == -1) {
		return 0;
	} else {
		return count(str, table[str[c] - 'a'][last], c + 1);
	}
}
bool contains_str(string str) {
	return count(str) > 0;
}
void print_table() {
	int c = 0;
	printf("|    | ");
	fa(i, 0, 26) printf(" %c | ", i + 'A');
	printf(" # |\n");
	fa(y, 0, current) {
		fa(i, 0, 28) {
			if(!i) {
				printf("| %02d | ", c++);
			} else if(i != 27) {
				printf("%02d | ", table[i - 1][y]);
			} else {
				printf("%02d |", table[26][y]);
			}
		}
		printf("\n");
	}
	printf("\n");
}
int main() {
	grow();
	insert("joaogay");
	insert("joaobixa");
	insert("joaobixa");
	insert("joaobixa");
	insert("joao");
	insert("joao");
	print_table();
	return 0;
}
