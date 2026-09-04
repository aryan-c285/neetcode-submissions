class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         int p = 1;
         int c= 0;
         for(auto i : nums){
            if (i== 0) c++;
            else{
                p*= i;
            }
         }
        vector <int> ans;
         for(auto i : nums){
            if (c> 1){
                ans.push_back(0);
            }else if(c==1){
                i==0?ans.push_back(p):ans.push_back(0);
            }else{
            ans.push_back(p/i);

            }
         }
         return ans;
    }
};
