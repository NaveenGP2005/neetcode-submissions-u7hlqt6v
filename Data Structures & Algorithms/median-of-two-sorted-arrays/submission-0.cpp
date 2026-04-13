class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1=a.size(),n2=b.size(),i=0,j=0,el1=-1,el2=-1,cnt=0;
        int n=n1+n2;
        int idx1=n/2;
        int idx2=idx1-1;
        while(i<n1&&j<n2){
            if(a[i]<b[j]){
                if(cnt==idx1) el1=a[i];
                if(cnt==idx2) el2=a[i];
                cnt++,i++;
            }else{
                if(cnt==idx1) el1=b[j];
                if(cnt==idx2) el2=b[j];
                cnt++,j++;
            }
        }

        while(i<n1){
            if(cnt==idx1) el1=a[i];
                if(cnt==idx2) el2=a[i];
                cnt++,i++;
        }
        while(j<n2){
            if(cnt==idx1) el1=b[j];
                if(cnt==idx2) el2=b[j];
                cnt++,j++;
        }

        if(n%2==1) return el1;
        return (double)((double)(el1+el2))/2.0;
    }
};
