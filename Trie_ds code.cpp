//Trie Data structure

#include <bits/stdc++.h>
using namespace std;

struct node {
    bool endmark;
    node *next_edge[26];
    node() {
        endmark = false;
        for (int i = 0; i < 26; i++) {
            next_edge[i] = NULL;
        }
    }
};

void insert_into_trie(string word, node *root) {
    node *current_node = root;
    int l = word.size();
    for (int i = 0; i < l; i++) {
        int idx = word[i] - 'a';
        if (current_node->next_edge[idx] == NULL) {
            current_node->next_edge[idx] = new node();
        }
        current_node = current_node->next_edge[idx];
    }
    current_node->endmark = 1;
}

bool search_in_trie(string word, node *root) {
    node *current_node = root;
    int l = word.size();
    for (int i = 0; i < l; i++) {
        int idx = word[i] - 'a';
        if (current_node->next_edge[idx] == NULL) {
            return false; 
        }
        current_node = current_node->next_edge[idx];
    }
    return current_node->endmark;
}

int main() {
    int n;
    string word;
    node *root = new node();
    
    cout << "Enter number of words to insert: ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cout << "Enter word " << (i + 1) << ": ";
        cin>>word;
        insert_into_trie(word, root);
    }
    cout << "Enter word to search: ";
    cin >> word;
    if (search_in_trie(word, root)) {
        cout << "Word found in the Trie!" << endl;
    } else {
        cout << "Word not found in the Trie." << endl;
    }
    
    return 0;
}
