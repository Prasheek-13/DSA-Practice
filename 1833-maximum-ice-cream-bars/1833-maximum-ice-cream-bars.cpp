class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int count = 0;
        int n = costs.size();
        int sum = 0;
        int oldcoins = coins;
        for (int i = 0; i < costs.size(); i++) {
            coins = coins - costs[i];
            count++;
            sum = sum + costs[i];
            if (coins < 0) {
                coins = coins + costs[i];
                count--;
                return count;
            }
        }
        if (coins == 0 || sum <= oldcoins) {
            return count;
        }
        return 0;
    }
};