#include<iostream>
using namespace std;
#include<bits/stdc++.h>
class Solution{
    // private:
    //     bool linearSearch(vector<int> arr,int num){
    //         for(int i = 0;i<arr.size();i++){
    //             if(arr[num] == arr[i]){
    //                 return true;
    //             }
    //         }
    //         return false;
    //     }
    // public:
    //     int longestConsecutive(vector<int> & nums){  // BruteForce approach
    //         if(nums.size() == 0) return 0;
    //         int n = nums.size();
    //         int longest = 1;
    //         for(int i =0;i<n;i++){
    //             int x = nums[i];
    //             int count = 0;

    //             while(linearSearch(nums,x+1) == true){
    //                 x  = x+1;
    //                 count+=1;
    //             }

    //             longest=max(count,longest);

    //         }
    //         return longest;
    //     }

    public:
        int longestConsecutive(vector<int> nums){
            int n = nums.size();
            if(n == 0){
                return 0;

            }
            sort(nums.begin(),nums.end());

            int longest = 0;
            int cnt = 0;
            int lastSmaller = INT_MIN;


            for(int i=0;i<n;i++){
                if(nums[i] -1 == lastSmaller){
                    lastSmaller = nums[i];
                    cnt++;
                }else if(nums[i] != lastSmaller){
                    cnt = 1;
                    lastSmaller = nums[i];
                }

                longest = max(cnt,longest);
            }
            return longest;

        }
};
int main(){
     vector<int> a = {100, 4, 200, 1, 3, 2};

    // Create an instance of the Solution class
    Solution solution;

    // Function call for longest consecutive sequence
    int ans = solution.longestConsecutive(a);
    cout << "The longest consecutive sequence is " << ans << "\n"; 
    return 0;
}