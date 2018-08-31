#include <iostream>
#include <vector>
using namespace std;

struct Trie {
    struct Node {
        Node() {
            valid = false;
            for (int i=0; i<26; ++i) {
                children[i] = -1;
            }
        }
        bool valid;
        int children[26];
    };
    Trie() {
        root = init();
    }
    int init() {
        trie.push_back(Node());
        return trie.size()-1;
    }
    void add(int node, string& s, int index) {
        if (index==s.size()) {
            trie[node].valid = true;
            return;
        }
        int c = s[index]-'a';
        if (trie[node].children[c]==-1) {
            int next = init();
            trie[node].children[c] = next;
        }
        add(trie[node].children[c], s, index+1);
    }
    void add(string& s) {
        add(root, s, 0);
    }
    bool find(int node, string& s, int index) {
        if (node==-1) return false;
        if (index==s.size()) return trie[node].valid;
        return find(trie[node].children[s[index]-'a'], s, index+1);
    }
    bool find(string& s) {
        return find(root, s, 0);
    }
    int root;
    vector<Node> trie;
};

int main()
{
    Trie trie;
    
    // add string to trie
    trie.add("string");
    
    // search for string in trie
    bool found = trie.find("string");
    
    return 0;
}