#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int src){
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        vector<int>d(n,1e9);
        vector<int>ans(n);
        
        pq.push({0,src});
        d[src]=0;
        
        while(pq.size()){
            int node=pq.top().second;
            int dis=pq.top().first;
            pq.pop();
            
            for(auto it:adj[node]){
                if(dis+it[1]<d[it[0]]){ 
                    d[it[0]]=dis+it[1];
                    pq.push({d[it[0]], it[0]});
                }
            }
        }
        return d;
        
    }
};