class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;

        int l=0;
        int r=height.size()-1;
        int leftMx=height[l];
        int rightMx=height[r];

        int totalWater=0;

         while(l<r){
             if(leftMx < rightMx){
                 l++;
                 leftMx=max(leftMx, height[l]);
                 totalWater +=leftMx - height[l];
             }else{
                r--;
                 rightMx= max(rightMx, height[r]);
                 totalWater +=rightMx - height[r];
             }
         }
         return totalWater;
    }
};
