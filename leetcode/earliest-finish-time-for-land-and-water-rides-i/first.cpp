class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        vector<pair<int, int>> land;
        vector<pair<int, int>> water;

        for (int i = 0; i < landStartTime.size(); i++) {
            land.push_back(
                {landStartTime[i], landStartTime[i] + landDuration[i]});
        }

        for (int i = 0; i < waterStartTime.size(); i++) {
            water.push_back(
                {waterStartTime[i], waterStartTime[i] + waterDuration[i]});
        }

        int min_land_end = (*min_element(land.begin(), land.end(), [](auto& a, auto& b) {
            return a.second < b.second;
        })).second;

        int min_water_end = (*min_element(water.begin(), water.end(), [](auto& a, auto& b) {
            return a.second < b.second;
        })).second;

        int i = 0;

        int min_end = INT_MAX;

        // assume water comes first
        while (i < land.size()) {
            min_end = min(min_end, max(min_water_end, landStartTime[i]) + landDuration[i]);
            i++;
        }

        i = 0;

        // assume land comes first
        while (i < water.size()) {
            min_end = min(min_end, max(min_land_end, waterStartTime[i]) + waterDuration[i]);
            i++;
        }

        return min_end;
    }
};