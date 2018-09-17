#include <cstdio>
#include <vector>
using namespace std;

const int MAX_NUM = 1e6;  // range of element value
int cnt[MAX_NUM];

void uni(vector<int>& v) {
    vector<int> tmp = v;
    v.clear();
    for (int p : tmp) {
        ++cnt[p];
    }
    for (int p : tmp) {
        if (--cnt[p] == 0) {
            v.push_back(p);
        }
    }
}

int main()
{
    // n = number of elements
    int n; scanf("%d", &n);
    
    // initial vector v
    vector<int> v(n);
    for (int i=0; i<n; ++i) {
        scanf("%d", &v[i]);
    }
    
    // (inline) remove duplicates from v, only leaving the last one => uni
    vector<int> uni;
    for (int p : v) {
        ++cnt[p];
    }
    for (int p : v) {
        if (--cnt[p] == 0) {
            uni.push_back(p);
        }
    }
    
    // (function) remove duplicates from v, only leaving the last one => v
    uni(v);
    
    // print vector
    for (int p : v) {
        printf("%d\n", p);
    }
    
    return 0;
}