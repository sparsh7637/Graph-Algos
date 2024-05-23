#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void bfs(vector<bool>&vis, int node, vector<vector<int>>& adj){
        queue<int>q;
        q.push(node);
        vis[node]=1;
        while(q.size()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
    }
};

