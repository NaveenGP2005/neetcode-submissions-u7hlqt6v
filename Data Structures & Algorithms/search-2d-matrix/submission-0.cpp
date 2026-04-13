class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int n=a.size(),m=a[0].size();
        int l=0,r=n*m-1;
        while(l<=r){
            int mid=l+(r-l)/2;
                int row=mid/m,col=mid%m;
            if(a[row][col]==target) return 1;
            else if(a[row][col]>target) r--;
            else l++;
        }
        return 0;
    }
};
