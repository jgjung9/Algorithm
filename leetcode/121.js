/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
  const maxCandidates = Array(prices.length);
  let max = prices[prices.length - 1];
  for (let i = prices.length - 1; i >= 0; i--) {
    max = Math.max(max, prices[i]);
    maxCandidates[i] = max;
  }
  let ans = 0;
  for (let i = 0; i < prices.length - 1; i++) {
    ans = Math.max(ans, maxCandidates[i + 1] - prices[i]);
  }
  return ans;
};

console.log(maxProfit([7, 6, 4, 3, 1]));
