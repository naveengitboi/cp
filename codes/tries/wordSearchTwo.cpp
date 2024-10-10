// word search two leetcode 212
#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<char>> vvc ;
typedef vector<vector<int>> vvi;
int m, n, l;
struct TrieNode{
    TrieNode* child[26];
    bool end = false;
    string word = "";
    bool containsKey(char ch){
        return child[ch-'a'] != NULL;
    }
    void put(char ch, TrieNode* node){
        child[ch-'a'] = node;
    }
    TrieNode* get(char ch){
        return child[ch-'a'];
    }
    void markEnd(){
        end = true;
    }
    void removeEnd(){
        end = false;
    }
    bool isEnd(){
        return end;
    }
};
class Trie{
public: 
    TrieNode* root;
    vector<int> xDir = {0,1,0,-1};
    vector<int> yDir = {1,0,-1,0};
    Trie(){
        root = new TrieNode();
    }
    void insert(string& word){
        TrieNode* node = root;
        for(int i =0;i< word.length(); i++){
            char ch = word[i];
            if(!node->containsKey(ch)){
                node->put(ch, new TrieNode());
            }
            node = node->get(ch);
        }
        node->markEnd();
        node->word = word;
    }

    TrieNode* getNode(){
        TrieNode* node = root;
        return node;
    }

    void search(vvc& board,int i, int j, vector<string>& result, TrieNode* node){
        if(i >=m || j >=n || i<0 || j < 0){
            return;
        }
        char ch = board[i][j];
        if(ch == '@' || (!node->containsKey(ch))){
            return;
        }
        node = node->get(ch);
        if(node->isEnd()){
            result.push_back(node->word);
            node->removeEnd();
        }
        board[i][j] = '@';
        for(int p = 0; p< 4; p++){
            int xDelta = i + xDir[p];
            int yDelta = j + yDir[p];
            search(board, xDelta, yDelta, result,node);
        }
        board[i][j] = ch;
        return;
    }

};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        l = words.size();
        Trie* trie = new Trie();
        for(int i =0; i<l; i++){
            trie->insert(words[i]);
        }
        m = board.size();
        n = board[0].size();
        vector<string> result;
        TrieNode* node = trie->getNode();
        for(int i =0; i< m; i++){
            for(int j =0; j<n; j++){
                char ch = board[i][j];
                trie->search(board, i, j, result,node);
            }
        }
        return result;
    }
};
// @leet end
