// @leet start
// leet code replace word 648 question
#include <bits/stdc++.h>
#include <sstream>
#include <string>
using namespace std;
class Solution {
public:
    struct trieNode{
        trieNode* child[26];
        bool end = false;
        bool containsKey(char ch){
            return child[ch-'a'] != NULL;
        }
        void put(char ch, trieNode* node){
            child[ch-'a'] = node;
        }
        trieNode* get(char ch){
            return child[ch-'a'];
        }
        void markEnd(){
            end = true;
        }
        bool isEnd(){
            return end;
        }
    };
    void insert(string& word, trieNode* node){
        for(int i =0; i<word.length(); i++){
            char ch = word[i];
            if(!node->containsKey(ch)){
                node->put(ch, new trieNode());
            }
            node = node->get(ch);
        }
        node->markEnd();
    }
    string searchWord(string& word, trieNode* node){
        for(int i =0; i<word.size(); i++){
            char ch = word[i];
            if(!node->containsKey(ch)){
                return word;
            }
            node = node->get(ch);
            if(node->isEnd()){
                return word.substr(0, i+1);
            }
        }
        return word;
    }
    string replaceWords(vector<string>& dict, string sent) {
        trieNode* root = new trieNode();
        for(int i = 0; i<dict.size(); i++){
            insert(dict[i], root);
        }

        stringstream ss(sent);
        string word;
        string result;
        while(getline(ss, word, ' ')){
            result += searchWord(word, root) + " ";
        }
        result.pop_back();
        return result;
    }
};
// @leet end
