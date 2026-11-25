class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         if(nums1.size()> nums2.size()){
             return findMedianSortedArrays(nums2, nums1);
         }
         
         int m=nums1.size();
         int n=nums2.size();

         int total=m+n;
         int half=(total + 1)/2;

         int low=0;
         int high=m;

         while(low<=high){
             int i=low + (high - low)/2;
             int j= half - i;

             int aLeft=(i==0) ? INT_MIN : nums1[i-1];
             int aRight=(i==m) ? INT_MAX: nums1[i];

             int bLeft=(j==0) ? INT_MIN : nums2[j -1];
             int bRight=(j==n) ? INT_MAX: nums2[j];

             if(aLeft <= bRight && bLeft <=aRight){
                if (total % 2 == 1) {
    return max(aLeft, bLeft);
}

                 long long leftMax=max(aLeft,bLeft);
                 long long rightMin=min(aRight,bRight);
                 
                 return (leftMax + rightMin)/2.0;
             }
             else if(aLeft > bRight){
                 high= i - 1;
             }else{
                 low = i + 1;
             }


         }
           return 0.0;
    }
};
