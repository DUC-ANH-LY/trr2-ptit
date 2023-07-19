#include <bits/stdc++.h>
using namespace std;
#define ll long long
void testcase()
{
	// For getting input from input.txt file
	freopen("input.txt", "r", stdin);

	// Printing the Output to output.txt file
	freopen("output.txt", "w", stdout);
}


int a[100][100], n, u;

vector<int> ec;


void euler(int a[100][100], int u = 1) {
	stack<int> st;
	st.push(u);
	while (!st.empty()) {
		int u = st.top();
		int check = 0;
		// check canh ke u
		for (int v = 1; v <= n; v++) {
			if (a[u][v] == 1) {
				st.push(v);
				a[u][v] = 0;
				a[v][u] = 0;
				check = 1;
				break;
			}
		}
		if (check == 0) {
			st.pop();
			ec.push_back(u);
		}
	}
	reverse(ec.begin(), ec.end());
	for (auto i : ec) cout << i << " ";
	cout << endl;

}
int main() {
	testcase();
	cin >> n >> u;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) cin >> a[i][j];

	euler(a);


}