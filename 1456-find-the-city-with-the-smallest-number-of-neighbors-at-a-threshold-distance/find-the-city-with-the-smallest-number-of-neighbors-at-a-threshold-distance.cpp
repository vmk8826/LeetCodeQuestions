// class Solution {
// public:
//     int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
//         vector<vector<int>>dis(n,vector<int>(n,1e5));

//         for(int i=0;i<edges.size();i++){
//             dis[edges[i][0]][edges[i][1]]=edges[i][2];
//             dis[edges[i][1]][edges[i][0]]=edges[i][2];
//         }

//         for(int i=0;i<n;i++)dis[i][i]=0;
        
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 for(int k=0;k<n;k++){
//                     if(dis[i][j]>dis[i][k]+dis[k][j]){
//                         dis[i][j]=dis[i][k]+dis[k][j];
//                     }
//                 }
//             }
//         }

//         // for(int i=0;i<n;i++){
//         //     for(int j=0;j<n;j++){
//         //         cout<<dis[i][j]<<",";
//         //     }
//         //     cout<<endl;
//         // }

//         int ans=-1;
//         int mini=INT_MAX;
//         for(int i=0;i<n;i++){
//             int cities=0;
//             for(int j=0;j<n;j++){
//                 if(dis[i][j]<=distanceThreshold){
//                     cities++;
//                 }
//             }
//             // cout<<i<<","<<cities<<endl;
//             if(mini>=cities){
//                 mini=cities;
//                 ans=i;
//             }
//         }
//         return ans;

//     }
// };
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int dist[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = i == j ? 0 : 10001;
            }
        }
        for (auto &e : edges) {
            dist[e[0]][e[1]] = dist[e[1]][e[0]] = e[2];
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int res = -1, resCount = INT_MAX;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if (count <= resCount) {
                resCount = count;
                res = i;
            }
        }
        return res;
    }
};