class Solution {
public:
    int getPrice(int start,int dst,vector<pair<int,int>>adj[],int n,int k){
        vector<int>price(n,INT_MAX);
        queue<pair<int,pair<int,int>>>pq;
        pq.push({0,{start,0}});
        price[start]=0;
        while(!pq.empty()){
            int curr=pq.front().second.first;
            int num=pq.front().first;
            int wei=pq.front().second.second;
            pq.pop();
            if(num>k)continue;
            for(auto it:adj[curr]){
                if(num<=k&&price[it.first]>price[curr]+it.second){
                    price[it.first]=wei+it.second;
                    pq.push({num+1,{it.first,price[it.first]}});
                }
            }
        }
        return price[dst];
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        int ans=getPrice(src,dst,adj,n,k);
        if(ans==INT_MAX)return -1;
        return ans;
    }
};