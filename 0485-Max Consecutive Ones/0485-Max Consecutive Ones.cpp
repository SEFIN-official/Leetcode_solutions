class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int maxe=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
                maxe=max(maxe,count);
            }
            else{
                count=0;
            }

        }
        return maxe;
        
    }
};
