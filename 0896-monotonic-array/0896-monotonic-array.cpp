class Solution {
public:
    bool accending( vector<int>& nums , int i ) {
        if( i+1 < nums.size() ) {
            if ( nums[i] <= nums[i+1] ) return accending( nums , i+1 ) ;
            else return false ;
        }
        else return true ;
    }
    bool decending( vector<int>& nums , int i ) {
        if( i+1 < nums.size() ) {
            if ( nums[i] >= nums[i+1] ) return decending(  nums , i+1 ) ;
            else return false ;
        }
        else return true ;
    }
    bool isMonotonic(vector<int>& nums) {
        if( accending( nums , 0 ) || decending( nums , 0 ) ) return true ;
        return false ;
    }
};