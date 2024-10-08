#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode* child[2];
    bool containsKey(int bit){
        return (child[bit] != NULL);
    }
    void put(int bit, TrieNode* node){
        child[bit] = node;
    }

    TrieNode* get(int bit){
        return child[bit];
    }
};


class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    void insert(int num){
        TrieNode* node = root;
        for(int i = 31; i>=0; i--){
            int bit = (num>>i)&1;
            if(!node->containsKey(bit)){
                node->put(bit, new TrieNode());
            }
            node = node->get(bit);
        }
    }
    int getMax(int num){
        TrieNode* node = root;
        int maxi = 0;
        for(int i =31; i>= 0; i--){
            int bit = ((num>>i)&1);
            if(node->containsKey(1-bit)){
                maxi = maxi | (1<<i);
                node = node->get(1-bit);
            }else{
                node = node->get(bit);
            }
        }
        return maxi;
    }
};


int maxXOR(vector<int>& nums1, vector<int>& nums2){
    int ans = 0;
    Trie* trie;
    for(int i =0; i< nums1.size(); i++){
        trie->insert(nums1[i]);
    }
    for(int i =0; i< nums2.size(); i++){
        int maxi = trie->getMax(nums2[i]);
        ans = max(maxi, ans);
    }

    return ans;
}
