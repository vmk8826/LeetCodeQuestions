class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>>ret;
       // cout<<matrix.size()<<endl;
        
             
              for(int j=0;j<matrix[0].size();j++){
              ret.push_back(std::vector<int>());
            }
            

        for(int i=0;i<matrix.size();i++)
        {
              
              for(int j=0;j<matrix[i].size();j++){
              ret[j].push_back(matrix[i][j]);
            }
            
        }
        
        return ret;
    }
};