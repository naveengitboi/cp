#include <bits/stdc++.h>
using namespace std;
struct Trie{
    Trie *child[26];
    bool end = false;

    bool containsKey(char ch){
        return child[ch-'a'] != NULL;
    }
    void setEnd(){
        end = true;
    };
    void put(char ch, Trie* node){
        child[ch-'a'] = node;
    }

    Trie* get(char ch){
        return child[ch - 'a'];
    }
    bool isEnd(){
        return end;
    }
};


//implementing trie()


class TrieClass{
private: Trie* root;
public:
    TrieClass(){
       root = new Trie();
    }
    
    //inserting

    void insert(string word){
        Trie* node = root;
        for(int i = 0; i < word.length(); i++){
            if(!node->containsKey(word[i])){
                //create a referece trie node
                node->put(word[i], new Trie());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word){
        Trie* node = root;
        for(int i = 0; i< word.length(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string word){
        Trie* node = root;
        for(int i = 0; i< word.length(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return true;
    }

};
