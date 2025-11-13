class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> sol(n,1);
        sol[0]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j])sol[i]=max(sol[i],sol[j]+1);
            }
        }
        int ans=1;
        for(int i : sol)ans=max(ans,i);
        return ans;
    }
};