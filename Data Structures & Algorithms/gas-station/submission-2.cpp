class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0,end=gas.size()-1,total=gas[end]-cost[end];
        while(start<end){
            if(total<0){
               end--;
               total+=gas[end]-cost[end];
            }
            else{
                total+=gas[start]-cost[start];
                start++;
            }
        }
        return total>=0?start:-1;
    }
};