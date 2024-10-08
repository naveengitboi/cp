#include <bits/stdc++.h>
using namespace std;


struct Trie{
    Trie* child[26];
    int countPrefix = 0;
    int endsWith = 0;

    void put(char ch, Trie* node){
        child[ch-'a'] = node;
    }
    Trie* get(char ch){
        return child[ch-'a'];
    }
    bool containsKey(char ch){
        return child[ch-'a'] != NULL;
    }
    bool isEnd(){
        return (endsWith != 0);
    }
    void incrementEnd(){
        endsWith++;
    }
    void decrementEnd(){
        endsWith--;
    }
    void incrementPrefix(){
        countPrefix++;
    }
    void decrementPrefix(){
        countPrefix--;
    }
};

class TrieImplementClass{
private: Trie* root;
public:
    TrieImplementClass(){
        root = new Trie();
    }
    void insert(string word){
        Trie* node = root;
        for(int i = 0; i< word.length(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Trie());
            }
            node = node->get(word[i]);
            node->incrementPrefix();
        }
        node->incrementEnd();
    }

    int countWordsEqual(string word){
        Trie* node = root;
        for(int i = 0;i<word.length(); i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->endsWith;
    }

    int countWordsStartWith(string word){
        Trie* node = root;
        for(int i =0; i< word.length(); i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->countPrefix;
    }
    void erase(string word){
        Trie* node = root;
        for(int i = 0; i< word.length(); i++){
            node->decrementPrefix();
            node = node->get(word[i]);
        }
        node->decrementEnd();
    }
};
