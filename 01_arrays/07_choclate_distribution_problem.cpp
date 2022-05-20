// problem link:- https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1/

/*
brute :- pick the m comninations and find min in them

optimal -> O(nlogn + n-m)
1. we want to select choclates such that we can get min and max easily
2. so sort the array
3. iterate till n-m 
4. find min in window using arr[i] and max in window using arr[i+m-1]
5. find gap using maxw - minw and find min among them
*/

class Solution{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m){

        long long ans = INT_MAX;

        for(long long i=0; i<=n-m; i++){

            long long minw = a[i];
            long long maxw = a[i+m-1];

            long long gap = maxw - minw;

            ans = min(ans, gap);
        }

        return ans;
    }
}