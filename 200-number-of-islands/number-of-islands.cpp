class Solution {
public:
    void markZero(int x,int y,vector<vector<char>>& grid){
        queue<pair<int,int>>qu;
        qu.push({x,y});
        grid[x][y]='0';
        vector<int>movx={0,0,1,-1};
        vector<int>movy={1,-1,0,0};
        while(!qu.empty()){
            pair<int,int>curr=qu.front();
            qu.pop();
            
            for(int i=0;i<movx.size();i++){
                int nx=curr.first+movx[i];
                int ny=curr.second+movy[i];
                if(nx>=0&&ny>=0&&nx<grid.size()
                &&ny<grid[0].size()&&grid[nx][ny]=='1'){
                    // cout<<nx<<","<<ny<<" ";
                    grid[nx][ny]='0';
                    qu.push({nx,ny});
                }
                    
            }
            // cout<<endl;
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        vector<vector<char>>grid1=grid;
        for(int i=0;i<grid1.size();i++){
            for(int j=0;j<grid1[0].size();j++){
                if(grid1[i][j]=='1'){
                    cout<<i<<","<<j<<endl;
                    ans++;
                    markZero(i,j,grid1);
                }
            }
        }
        return ans;
    }
};