#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
  vector<int>rank, parent, size;
  DisjointSet(int n){
    rank.resize(n+1,0);
    parent.resize(n+1);
    size.resize(n+1,1);
    for(int i=0; i<=n; i++) parent[i]=i;
  }
 
 
  int findupar(int node){
    if(parent[node]==node) return node;
    return parent[node]=findupar(parent[node]);
  }
 
 
  void uByRank(int u, int v){
    int upu=findupar(u);
    int upv=findupar(v);
    if(upu==upv) return;
    else if(rank[upu]<rank[upv]) parent[upu]=upv;
    else if(rank[upv]<rank[upu]) parent[upv]=upu;
 
    else{
      parent[upu]=upv;
      rank[upv]++;
    }
  }
 
  void uBySize(int u, int v){
    int upu=findupar(u);
    int upv=findupar(v);
    if(size[upu]<size[upv]){
      parent[upu]=upv;
      size[upv]+=size[upu];
    }
    else{
      parent[upv]=upu;
      size[upu]+=size[upv];
    }
  }
};