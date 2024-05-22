#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    vector<int> bellman_ford(int n, vector<vector<int>>& edges, int s) {
        vector<int>dis(n,1e8);
        dis[s]=0;
        
        for(int i=0; i<n; i++){
            for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int d=it[2];
                if(dis[u]!=1e8 and dis[u]+d<dis[v]) dis[v]=dis[u]+d;
            }
        }
        
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int d=it[2];
            if(dis[u]!=1e8 and dis[u]+d<dis[v]) return {-1};
        }
        
        return dis;
    }
};