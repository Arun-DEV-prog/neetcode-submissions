class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      int n=nums.size();

      unordered_map<int,int>countMap;
       for(int num: nums){
          countMap[num]++;
       }

       vector<vector<int>>buckets(n +1);
        for(const auto& pair: countMap){
             int num=pair.first;
             int freq=pair.second;
             buckets[freq].push_back(num);
        }
        vector<int>result;
         for(int freq=n; freq>=1 && result.size()<k; freq--){
             for(int num: buckets[freq]){
                result.push_back(num);
                if(result.size()==k){
                     return result;
                }
             }
         }

         return result;
    }
};
