#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        vector<bool>vis(n,0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        int ans=0;
        pq.push({0,0});
        
        while(pq.size()){
            auto p=pq.top();
            pq.pop();
            int node=p.second;
            int wt=p.first;
            
            if(vis[node]) continue;
            vis[node]=1;
            ans+=wt;
            for(auto it:adj[node]){
                if(!vis[it[0]]) pq.push({it[1], it[0]});
            }
        }
        return ans;
    }
};