class Solution {
public:
    int mod=1e9+7;
    int kConcatenationMaxSum(vector<int>& arr, int k) {

        long long sum=accumulate(arr.begin(),arr.end(),0);
        long long rig=0,mrig=0,lef=0,mlef=0;

        for(int i=0;i<arr.size();i++){
            rig+=arr[i];
            mrig=max(mrig,rig);
        }
        for(int i=arr.size()-1;i>=0;i--){
            lef+=arr[i];
            mlef=max(mlef,lef);
        }
        
        if(k==1)return max(mlef%mod,mrig%mod);
        if(k==2)return (mlef%mod+mrig%mod)%mod;

        if(sum<0){
            int sum=0,maxSum=0;
            int siz=arr.size();
            for(int i=0;i<siz;i++){
                arr.push_back(arr[i]);
            }
            for(int i=0;i<arr.size();i++){
                maxSum=max(sum,maxSum);
                sum=sum+arr[i];
                if(sum<0)sum=0;
            }
            return maxSum%mod;
        }

        long long ans = (mlef%mod+mrig%mod+
                            ((k-2)%mod*sum%mod)%mod)%mod;

        return ans;
    }
};