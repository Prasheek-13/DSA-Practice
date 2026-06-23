class Solution {
public:
    double angleClock(int hour, int minutes) {
        float hourangle = (hour % 12) * 30 + (minutes) * 0.5;
        int minangle = minutes * 6;
        float difference = hourangle - minangle;
        if (difference < 0) {
            difference = -1 * difference;
        }
        float ans = 0;
        ans = min(360 - difference, difference);
        return ans;
    }
};