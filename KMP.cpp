#include <iostream>
#include <vector>
using namespace std;

vector<int> kmp_preprocess(string p) {
    int m = p.size();
    vector<int> pi(m, 0);
    int j = 0;
    for (int i=1; i<m; ++i) {
        while (j>0 && p[i]!=p[j]) {
            j = pi[j-1];
        }
        if (p[i]==p[j]) {
            pi[i] = ++j;
        } else {
            pi[i] = 0;
        }
    }
    return pi;
}

vector<int> kmp_match(string s, string p) {
    auto pi = kmp_preprocess(p);
    vector<int> ans;
    int n = s.size();
    int m = p.size();
    int j = 0;
    for (int i=0; i<n; ++i) {
        while (j>0 && s[i]!=p[j]) {
            j = pi[j-1];
        }
        if (s[i]==p[j]) {
            if (j==m-1) {
                ans.push_back(i-m+1);
                j = pi[j];
            } else {
                j += 1;
            }
        }
    }
    return ans;
}

int main()
{
    // matching p(attern) in s(tring)
    string s, p;
    getline(cin, s);
    getline(cin, p);
    
    // vector ans contains the starting indexes of each match
    // ans.size() is the number of matches
    auto ans = kmp_match(s, p);
    
    return 0;
}