class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size() , i = 0;
        if(n <= 2) return false;

        while(i < n -1 && arr[i] < arr[i + 1]){
            i++;
        }
        if(i == n -1 || i == 0){
            return false;
        }

        while( i < n - 1 && arr[i] > arr[i + 1]){
            i++;
        }
        if(i == n - 1){
            return true;
        }
        else{
            return false;
        }

    }
};