class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        double siz=arr.size();
        int twentyFive=((double)siz*0.25)+1;
        // cout<<twentyFive; 
        int i=1,prev=arr[0],currCount=1;
        while(i<arr.size()){
            if(currCount>=twentyFive)return prev;
            if(arr[i]==prev){
                currCount++;
            }
            else{
                prev=arr[i];
                currCount =1;
            }
            i++;
        }
        return prev;
    }
};