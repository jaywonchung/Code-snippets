#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Aho {
    struct Node {
        Node() {
            pi = -1;
            valid = false;
            for (int i=0; i<26; ++i) {
                children[i] = -1;
            }
        }
        int pi;
        bool valid;
        int children[26];
    };
    Aho() {
        root = init();
    }
    int init() {
        trie.push_back(Node());
        return (int)trie.size()-1;
    }
    void add(int node, string& s, int index) {
        if (index==s.size()) {
            trie[node].valid = true;
            return;
        }
        int c = s[index]-'A';
        if (trie[node].children[c]==-1) {
            int next = init();
            trie[node].children[c] = next;
        }
        add(trie[node].children[c], s, index+1);
    }
    void add(string& s) {
        add(root, s, 0);
    }
    void connect() {
        queue<int> q;
        q.push(root); trie[root].pi = root;
        while (!q.empty()) {
            int now = q.front(); q.pop();
            for (int i=0; i<26; ++i) {
                int next = trie[now].children[i];
                if (next==-1) continue;
                if (now==root) {
                    trie[next].pi = root;
                } else {
                    int x = trie[now].pi;
                    while (x!=root && trie[x].children[i]==-1) {
                        x = trie[x].pi;
                    }
                    if (trie[x].children[i]!=-1) {
                        x = trie[x].children[i];
                    }
                    trie[next].pi = x;
                }
                int pi = trie[next].pi;
                trie[next].valid |= trie[pi].valid;
                q.push(next);
            }
        }
    }
    int find(string& s) {
        int node = root;
        int ans = 0;
        for (char _c : s) {
            int c = _c-'A';
            while (node!=root && trie[node].children[c]==-1) {
                node = trie[node].pi;
            }
            if (trie[node].children[c]!=-1) {
                node = trie[node].children[c];
            }
            if (trie[node].valid) {
                ans += 1;
            }
        }
        return ans;
    }
    int root;
    vector<Node> trie;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // create Aho-corasick trie and add pattern strings to it
    // this version assumes that the strings only contain uppercase alphabets
    Aho trie;
    int n; cin >> n;
    for (int i=0; i<n; ++i) {
        string p; cin >> p;
        trie.add(p);
    }
    
    // find pi for each prefix
    trie.connect();
    
    // find(s) returns the number of pattern matches in s
    string s; cin >> s;
    cout << trie.find(s) << '\n';
    
    return 0;
}