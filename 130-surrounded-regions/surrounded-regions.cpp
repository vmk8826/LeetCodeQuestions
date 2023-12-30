class Solution {
public:
    void markBoundary(int x,int y,vector<vector<char>>&mat){
        // cout<<x<<","<<y<<endl;
        queue<pair<int,int>>qu;
        mat[x][y]='-';
        qu.push({x,y});
        vector<int>mov={0,-1,0,1,0};
        while(!qu.empty()){
            pair<int,int>curr=qu.front();
            qu.pop();
            for(int i=0;i<mov.size()-1;i++){
                int nx=curr.first+mov[i];
                int ny=curr.second+mov[i+1];
                if(nx>=0&&ny>=0&&nx<mat.size()&&ny<mat[0].size()&&mat[nx][ny]=='O'){
                    qu.push({nx,ny});
                    mat[nx][ny]='-';
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<char>>mat=board;
        for(int i=0;i<mat[0].size();i++){
            if(board[0][i]=='O')markBoundary(0,i,mat);
            if(board[board.size()-1][i]=='O')markBoundary(board.size()-1,i,mat);
        }
        for(int i=0;i<mat.size();i++){
            if(board[i][0]=='O')markBoundary(i,0,mat);
            if(board[i][mat[0].size()-1]=='O')markBoundary(i,mat[0].size()-1,mat);
        }
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]=='O')mat[i][j]='X';
                if(mat[i][j]=='-')mat[i][j]='O';
            }
        }
        board=mat;
        return;
    }
};