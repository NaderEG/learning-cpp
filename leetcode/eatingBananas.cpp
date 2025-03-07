

class Solution {
public:
    bool isValidSpeed(vector<int> piles, int k, int h) {
        int time = 0;
        for (int num : piles) {
            time += std::ceil(num/k);
        }
        return time <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int x = 1;
        for (int num_bananas : piles) {
            if (num_bananas > x) {
                x = num_bananas;
            }
        }

        vector<int> possible_speeds;
        for (int i = 1; i <= x; i++) {
            possible_speeds.push_back(i);
        }

        int left = 0;
        int right = possible_speeds.size()-1;
        int mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (isValidSpeed(piles, possible_speeds[mid], h)) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return possible_speeds[mid];
    }
};
