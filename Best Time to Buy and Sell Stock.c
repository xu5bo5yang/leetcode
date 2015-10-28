int maxProfit(int* prices, int pricesSize) {
    int low, profit;
    int i, j;
    low = prices[0];
    profit = 0;
    for (i=1; i<pricesSize; i++) {
        profit = profit > (prices[i]-low) ? profit:(prices[i]-low);
        low = low < prices[i] ? low:prices[i];
    }
    return profit;
}