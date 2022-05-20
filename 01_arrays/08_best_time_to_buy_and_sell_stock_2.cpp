// problem link:- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

/*
brute using recursion we have two optins either we can buy the stock or sell the stock
but if we buy the stock at any day then we must sell it. we cant purchase two stocks at same time

we need to have some variable to say that yes we have bought the stock

better -> use memoization

optimal-> if present day price is greater than previous day price add it to maxprofit
*/

class Solution{
public:
    int f(int ind, int buy, vector<int>& prices, int n, vector<vector<int>>& dp){

        if(ind == n){
            return 0;
        }

        if(dp[ind][buy] != -1){
            return dp[ind][buy];
        }

        int profit=0;
        if(buy){
            profit += max(-prices[ind] + f(ind+1, 0, prices, n, dp), 0 + f(ind+1, 1, prices, n, dp));
        }
        else{
            profit += max(prices[ind] + f(ind+1, 1, prices, n, dp), 0 + f(ind+1, 0, prices, n, dp));
        }

        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices){

        int n=prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        // 1-> represents you can buy the stock
        return f(0, 1, prices, n, dp);
    }
}

//optimal -> tc -> O(n) sc-> O(1);

class Solution{
public:
    int maxProfit(vector<int>& prices){

        int maxiumProfit=0;

        for(int i=1; i<prices.size(); i++){

            if(prices[i] > prices[i-1]){
                maxiumProfit += prices[i] - prices[i-1];
            }
        }

        return maxiumProfit;
    }
}