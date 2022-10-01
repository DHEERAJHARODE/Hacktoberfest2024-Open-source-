// This file contains code template for trie data structure
#include <bits/stdc++.h>

using namespace std;

// node structure that stores node of a trie
struct node{
    int prefix;
    vector<string> wend;
    node *child[26];
    
    node(){
        prefix = 0;
        for(int i=0;i<26;i++) child[i] = NULL;
    } 
};

// trie structure
struct trie{
  node *root;
  trie(){
      root = new node;
  }  
};

// function to insert a string in a trie
void insert(string s,node *root){
    
    node *curr = root;
    for(int i=0;i<s.length();i++){
        int x = s[i] - 'a';
        curr->prefix++;
        if(curr->child[x]==NULL) curr->child[x] = new node;
        curr = curr->child[x];
    }
    curr->wend.push_back(s);
}

// function to search a string in a trie
bool search(string s,node *root){
    node *curr = root;
    
    for(int i=0;i<s.length();i++){
        int x = s[i] - 'a';
        curr->prefix++;
        if(curr->child[x]==NULL) return 0;
        curr = curr->child[x];
    }
    
    if(curr->wend.size() > 0 ) return 1;
    else return 0;
}

// function to delete a string in a trie
void delet(string s,node *root){
    node *curr = root;
    for(int i=0;i<s.length();i++){
        int x = s[i] - 'a';
        curr->prefix--;
        if(curr->child[x]==NULL) curr->child[x] = new node;
        curr = curr->child[x];
    }
    curr->wend.pop_back();
}