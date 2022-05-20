// problem link:- https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

/*
brute force:- use two loops and check the max profit

best solution:-
1. to get the best solution we need to buy at minimum price and sell it to maximum price
2. at starting we can assume I bought at 0th day
3. then from index 1 we can calculate the profit if it is greater than the curr profit we can update it
4. at the same time we can update the min price from which we can actually bought the stock
*/

class Solution{
public:
    int maxProfit(vector<int>& prices){

        int maximumProfit=0;

        int minimumPrice = prices[0];

        for(int i=1; i<prices.size(); i++){

            int curProfit = prices[i] - minimumPrice;
            maximumProfit = max(maximumProfit, curProfit);
            minimumPrice = min(minimumPrice, prices[i]);
        }

        return maximumProfit;
    }
}