#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode* child[26];
    bool containsKey(char ch){
        return (child[ch-'a'] != NULL);
    }
    void put(char ch, TrieNode* node){
        child[ch-'a'] = node;
    }
    TrieNode* get(char ch){
        return child[ch-'a'];
    }
};


class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    int insert(string &word){
        TrieNode* node = root;
        int count = 0;
        for(int i= 0; i< word.size(); i++){
            char ch = word[i];
            if(!node->containsKey(ch)){
                count++;
                node->put(ch, new TrieNode());
            }
            node = node->get(ch);
        }
        return count;
    }
};


int countDistinct(string &word){
    int ans = 0;
    Trie trie;
    for(int i = 0; i< word.size(); i++){
        string temp;
        for(int j = 0; j< word.size(); j++){
            temp+=word[j];
        }
        ans += trie.insert(temp);
    }
    return ans;
}
