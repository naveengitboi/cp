// @leet start 3093 longest common suffix
#include <bits/stdc++.h>
using namespace std;
#define vs vector<string>
class Solution {
public:
    struct TrieNode{
        int idx;
        TrieNode* child[26];
        bool containsKey(char ch){
            return child[ch-'a'] != NULL;
        }
        TrieNode* get(char ch){
            return child[ch-'a'];
        }
        void put(char ch, TrieNode* node){
            child[ch-'a'] = node;
        }
    };
    TrieNode* getNode(int j){
        TrieNode* temp = new TrieNode();
        temp->idx = j;
        for(int i = 0; i<26; i++){
            temp->child[i] = NULL;
        }

        return temp;
    }
    void insert(vs& wordsContainer, TrieNode* root, int i){
        string word = wordsContainer[i];
        int l = word.length();
        for(int j = l-1; j>=0; j--) {
            char ch = word[j];
            int chIdx = ch-'a';
            if(root->child[chIdx] == NULL){
                root->child[chIdx] = getNode(i);
            }
            root = root->child[chIdx];
            if(wordsContainer[root->idx].length() > l){
                root->idx = i; 
            }
        }
    }
    int search(string& word, TrieNode* root){
        int l = word.length();
        int resultIdx= root->idx;
        for(int j = l-1; j >=0; j--){
            char ch = word[j];
            int chIdx = ch-'a';
            root = root->child[chIdx];
            if(root == NULL){
                return resultIdx;
            }
            resultIdx = root->idx;
        }
        return resultIdx;
    }
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        TrieNode* root = getNode(0);
        int m = wordsContainer.size();
        int n = wordsQuery.size();
        vector<int> result(n);
        for(int i =0;i< m; i++){
            int idx = root->idx;
            if(wordsContainer[idx].length() > wordsContainer[i].length()){
                root->idx = i;
            }
            insert(wordsContainer, root, i);
        }

        for(int i = 0;i< n;i++){
            result[i] = search(wordsQuery[i], root);
        }

        return result;
    }
};
// @leet end
