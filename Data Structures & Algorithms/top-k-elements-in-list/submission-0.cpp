class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> mpp;
        for(auto it: nums){
            mpp[it]++;
        }
        vector <int> ans;
        for (int i= 0; i< k; i++){
            int mf = 0;
            int me = 0;
            for (auto it : mpp){
                if (it.second > mf){
                    mf = it.second;
                    me= it.first;
                }
            }
            mpp.erase(me);
            ans.push_back(me);
        }
        return ans;
    }
};
