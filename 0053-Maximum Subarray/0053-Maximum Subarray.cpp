//brute force 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                maxi=max(maxi,sum);

                
            }
        }
        return maxi;
    }
};

//optimal
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current=nums[0];
        int maxi= nums[0];

        for(int i=1;i<nums.size();i++){
            current=max(nums[i],nums[i]+current);
            maxi=max(maxi,current);
        }
        return maxi;
        
    }
};
