class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> locations;
        locations.resize(1002, 0);
        
        for (int i = 0; i < trips.size(); i++) {
            locations[trips[i][1] + 1] += trips[i][0];
            locations[trips[i][2] + 1] -= trips[i][0];
        }
        for (int i = 1; i < locations.size(); i++) {
            locations[i] = locations[i - 1] + locations[i];
            if (locations[i] > capacity) {
                return false;
            }
        }
        
        return true;
        
    }
};
