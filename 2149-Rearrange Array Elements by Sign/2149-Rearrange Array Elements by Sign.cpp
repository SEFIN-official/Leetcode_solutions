//brute force
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;
        vector<int>result;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                pos.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }
    for(int i=0;i<nums.size()/2;i++){
        result.push_back(pos[i]);
        result.push_back(neg[i]);
        
    }
    return result;
        
    }
};
//optimal
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n);
        int odd=0;
        int even=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                res[odd]=nums[i];
                odd+=2;
            }
            else{
                res[even]=nums[i];
                even+=2;
            }

        }
        return res;
        
        
    }
};
