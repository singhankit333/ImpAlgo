////find longest increasing subsequence in an array
////Time Complexity O(nlogn)
////Space Complexity O(n)


int findCeil(vector<int> &tail, int num){
    int l=0, r=tail.size()-1;
    while(l <= r) {
        int m = (l+r)/2;
        if(tail[m]==num) return m;
        else if(tail[m] < num) l = m+1;
        else r = m-1;
    }
    return l;
}

int lengthOfLIS(vector<int> &nums) {
    int n=nums.size();
    vector<int> tail = {nums[0]};
    for(int i=1; i<n; i++){
        if(nums[i] > tail.back()) tail.push_back(nums[i]);
        else tail[findCeil(tail, nums[i])] = nums[i];
    }
    return tail.size();
}
