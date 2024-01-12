class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr=0;
        for(int i=0;i<nums.size();i++){
            xr=xr^nums[i];
        }
        int num1=xr,num2=xr,setb=0;
        while(!(xr&(1<<setb))){
            setb++;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]&(1<<setb)){
                num1=num1^(nums[i]);
            }
            else{
                num2=num2^nums[i];
            }
        }
        return {num1,num2};
    }
};