class Solution {
public:
    bool check(vector<int>& nums) {
        int breakp=-1;
        if(nums.size()<=1){
            return true;
        }

        for(int i=0;i<=nums.size()-2;i++){
            if(nums[i]>nums[i+1]){
                breakp=i;
                break;
            }
        }
        if(breakp==-1){
            return true;
        }
       
         for(int i=breakp+1;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                return false;
            }
        }
        if(nums[0]>=nums[nums.size()-1]){
            return true;
        }
        else{
            return false;
        }

        
        
    }
};
