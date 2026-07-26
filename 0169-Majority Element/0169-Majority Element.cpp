class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>freq;
        int max=INT_MIN;
        int value=INT_MIN;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        for(auto it:freq){
            if(it.second>max){
                max=it.second;
                value=it.first;
            }
        }
        return value;     //not optimal 
        
        
    }
};

//optimal

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int can=0;

        for(auto num:nums){
            if(count==0){
                can=num;
            }
            if(can==num){
                count++;
            }
            else{
                count--;
            }
        }
        return can;
    }
};// cancel each element out if differs
