// @leet start
// leetcode impleemnt prefix trie 208 leetcode
#include <bits/stdc++.h>
using namespace std;
struct TrieNode{
    TrieNode* child[26];
    bool end = false;
    bool containsKey(char ch){
        return child[ch-'a'] != NULL;
    }
    void markEnd(){
        end = true;
    }
    bool isEnd(){
        return end;
    }
    void put(char ch, TrieNode* node){
        child[ch-'a'] = node;
    }
    TrieNode* get(char ch){
        return child[ch-'a'];
    }

};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(char &ch: word){
            if(!node->containsKey(ch)){
                node->put(ch, new TrieNode());
            }
            node = node->get(ch);
        }
        node->markEnd();
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(auto &ch : word){
            if(!node->containsKey(ch)){
                return false;
            }
            node = node->get(ch);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(auto &ch : prefix){
            if(!node->containsKey(ch)){
                return false;
            }
            node = node->get(ch);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @leet end
