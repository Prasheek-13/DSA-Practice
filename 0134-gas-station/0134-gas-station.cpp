class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int TotalGas = 0;
        int Totalcost = 0;
        for (int val : gas) {
            TotalGas += val;
        }
        for (int val : cost) {
            Totalcost += val;
        }
        if (TotalGas < Totalcost) {
            return -1;
        }
        int start = 0, currGas = 0;
        for (int i = 0; i < gas.size(); i++) {
            currGas += (gas[i] - cost[i]);
            if (currGas < 0) {
                start = i + 1;
                currGas = 0;
            }
        }
        return start;
    }
};