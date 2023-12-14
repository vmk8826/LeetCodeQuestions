class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<pair<int,int>>column,row;
        for(int i=0;i<grid.size();i++){
            int one=0,zero=0;
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)one++;
                else zero++;
            }
            row.push_back({one,zero});
        }
        for(int i=0;i<grid[0].size();i++){
            int one=0,zero=0;
            for(int j=0;j<grid.size();j++){
                if(grid[j][i]==1)one++;
                else zero++;
            }
            column.push_back({one,zero});
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                grid[i][j]=row[i].first+column[j].first-row[i].second-column[j].second;
            }
        }
        return grid;
    }
};