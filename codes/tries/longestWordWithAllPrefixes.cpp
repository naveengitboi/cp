//code studio or coding ninja

#include <bits/stdc++.h>
using namespace std;


struct Node{
    Node* child[26];
    bool end = false;

    bool containsKey(char ch){
        return (child[ch-'a'] != NULL);
    }

    void markEnd(){
        end = true;
    }
    Node* get(char ch){
        return child[ch-'a'];
    } 
    void put(char ch, Node* node){
        child[ch-'a'] = node;
    }

    bool isEnd(){
        return end;
    }
};

class Trie{
public:
    Node* root;
    Trie(){
        root = new Node();
    }

    void insert(string& word){
        Node* node = root;
        for(int i = 0; i< word.size(); i++){
            char ch = word[i];
            if(!node->containsKey(ch)){
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->markEnd();
    }
    bool checkIfPrefExist(string word){
        Node* node = root;
        for(int i = 0; i< word.length(); i++){
            char ch = word[i];
            if(node->containsKey(ch)){
                if(!node->isEnd()){
                    return false;
                }
                node = node->get(ch);
            }else{
                return false;
            }
        }
        return true;
    }
};


string completeString(int n, vector<string>& a){
    Trie* trie;
    for(auto &it: a){
        trie->insert(it);
    }
    string longestStr = "";
    for(auto &it: a){
        if(trie->checkIfPrefExist(it)){
            if(it.length() > longestStr.length()){
                longestStr = it;
            }
            else if(it.length() == longestStr.length()){
                if(it < longestStr){
                    longestStr = it;
                }
            }
        }
    }

    if(longestStr == ""){
        return "None";
    }
}














