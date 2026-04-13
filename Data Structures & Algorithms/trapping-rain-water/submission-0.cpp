class Solution {
public:
    int trap(vector<int>& a) {
        int l=0,r=a.size()-1;
        int lmax=0,rmax=0,total=0;
        while(l<r){
            if(a[l]<=a[r]){
                if(lmax>a[l]) {
                    total+=lmax-a[l];
                l++;
                }
            else{
                lmax=a[l++];
            }
            }else{
                if(rmax>a[r]){
                    total+=rmax-a[r--];
                }else{
                    rmax=a[r--];
                }
            }
        }
        return total;
    }
};
