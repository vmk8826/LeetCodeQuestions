class Solution {
public:
    int getDistance(int x,int y,vector<vector<int>>& grid){
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>qu;
        qu.push({0,{x,y}});
        int movx[4]={0,0,1,-1};
        int movy[4]={1,-1,0,0};
        vector<vector<int>>dis(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        dis[x][y]=0;
        while(!qu.empty()){
            int currx=qu.top().second.first;
            int curry=qu.top().second.second;
            int wei=qu.top().first;
            if(currx==grid.size()-1&&curry==grid[0].size()-1)return wei;
            qu.pop();
            for(int i=0;i<4;i++){
                int nx=currx+movx[i];
                int ny=curry+movy[i];
                if(nx>=0&&ny>=0&&nx<grid.size()&&ny<grid[0].size()&&
                    dis[nx][ny]>max(wei,abs(grid[currx][curry]-grid[nx][ny]))){
                    dis[nx][ny]=max(wei,abs(grid[currx][curry]-grid[nx][ny]));
                    qu.push({dis[nx][ny],{nx,ny}});
                }
            }
        }
        return dis[grid.size()-1][grid[0].size()-1];
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        return getDistance(0,0,heights);
    }
};