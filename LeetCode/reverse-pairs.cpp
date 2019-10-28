#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
typedef long long int ll;
using namespace std;
using namespace __gnu_pbds;

typedef tree<float, null_type, less_equal<float>, rb_tree_tag, tree_order_statistics_node_update> pbds;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        pbds tree;
        int ans=0;
        unordered_map<ll,ll> mp;
        for(int i=0;i<nums.size();i++)
        {
            ll temp=nums[i];
            ans+=i-tree.order_of_key(2*temp);
            // cout<<nums[i]<<" "<<i-tree.order_of_key(nums[i])<<endl;
            // float temp=nums[i]/2;
            if(mp.find(2*nums[i])!=mp.end())
                ans-=mp[2*nums[i]];
            if(mp.find(nums[i])!=mp.end())
                {mp[nums[i]]+=1;}
            else
                mp[nums[i]]=1;
            tree.insert(temp);
        }
        return ans;
    }
};