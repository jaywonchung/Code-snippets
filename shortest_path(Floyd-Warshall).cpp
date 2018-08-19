#include <iostream>
using namespace std;

int d[100][100];
const int inf = 1e9;

int main()
{
    int n, m; scanf("%d %d", &n, &m);
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (i==j) continue;
            d[i][j] = inf;
        }
    }
    for (int i=0; i<m; ++i) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        d[a-1][b-1] = min(d[a-1][b-1], c);
    }
    
    for (int k=0; k<n; ++k) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            printf("%d%c", d[i][j]>=inf?0:d[i][j], " \n"[j==n-1]);
        }
    }
    
    return 0;
}