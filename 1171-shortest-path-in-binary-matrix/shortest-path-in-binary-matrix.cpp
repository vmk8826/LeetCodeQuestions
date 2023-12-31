class Solution {
public:
    int getDistance(int x,int y,vector<vector<int>>& grid){
        queue<pair<int,int>>qu;
        qu.push({x,y});
        int movx[8]={0,0,1,-1,-1,1,-1,1};
        int movy[8]={1,-1,0,0,-1,1,1,-1};
        vector<vector<int>>dis(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        dis[x][y]=1;
        while(!qu.empty()){
            int currx=qu.front().first;
            int curry=qu.front().second;
            qu.pop();
            for(int i=0;i<8;i++){
                int nx=currx+movx[i];
                int ny=curry+movy[i];
                if(nx>=0&&ny>=0&&nx<grid.size()&&ny<grid[0].size()&&!grid[nx][ny]&&
                dis[nx][ny]>dis[currx][curry]+1){
                    dis[nx][ny]=dis[currx][curry]+1;
                    qu.push({nx,ny});
                }
            }
        }
        return dis[grid.size()-1][grid[0].size()-1];
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]!=0)return -1;
        int ans= getDistance(0,0,grid);
        if(ans!=INT_MAX)return ans;
        return -1;
    }
};