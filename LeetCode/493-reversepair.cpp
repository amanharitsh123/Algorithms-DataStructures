#include<iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
// typedef 
struct BIT{
    vector<int> nums;
    BIT(int size) : nums(size){}
    int lowbit(int x) { return x & -x; }
    void update(int x, int cnt){
        while (x < nums.size()) {
            nums[x] += cnt;
            x += lowbit(x);
        }
    }
    
    int query(int x) {
        int sum = 0;
        while(x > 0) {
            sum += nums[x];
            x -= lowbit(x);
        }
        return sum;
    }
};

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        // Copy array
        vector<long long> copy;
        for(auto x:nums) {
            copy.push_back(x);
            copy.push_back(2*(long long)x+1);
        }
        sort(copy.begin(),copy.end());
        int ans=0;
        BIT bit(copy.size() + 10);
        for(int i = nums.size()-1; i >= 0; --i){
            int r1=upper_bound(copy.begin(),copy.end(),(long long)nums[i])-copy.begin()+1;
            int r2=upper_bound(copy.begin(),copy.end(),2*(long long)nums[i])-copy.begin()+1;
            ans += bit.query(r1-1);
            bit.update(r2, 1);
        }
        return ans;

    }
};