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

class Solution
{
	public:
    int spanningTree(int n, vector<vector<int>> edg[])
    {
        vector<pair<int,pair<int,int>>>adj;
        for(int i=0; i<n; i++){
            for(auto it:edg[i]){
                adj.push_back({it[1],{i,it[0]}});
            }
        }
        
        DisjointSet ds(n);
        sort(adj.begin(),adj.end());
        int ans=0;
        for(auto it:adj){
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            if(ds.findupar(v)!=ds.findupar(u)){ 
                ans+=wt;
                ds.uBySize(u,v);
            }
        }
        
        return ans;
    }
};