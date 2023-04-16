#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <cstring>

using namespace std;

const int MAXN = 16;
const int INF = numeric_limits<int>::max();

int n, m;
int dist[MAXN][MAXN], memo[MAXN][1 << MAXN];

int tsp(int cur, int mask) {
    if (mask == (1 << n) - 1) {
        return dist[cur][0];
    }

    if (memo[cur][mask] != -1) {
        return memo[cur][mask];
    }

    int ans = INF;
    for (int i = 0; i < n; i++) {
        if (i != cur && !(mask & (1 << i))) {
            ans = min(ans, dist[cur][i] + tsp(i, mask | (1 << i)));
        }
    }

    return memo[cur][mask] = ans;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        dist[a][b] = w;
        dist[b][a] = w;
    }

    memset(memo, -1, sizeof(memo));
    int ans = tsp(0, 1);

    cout << "Shortest path length: " << ans << endl;

    return 0;
}