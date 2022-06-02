// Leetcode#1011
class Solution {
public:

    bool isAlloc(vector<int>& weights, int capacity, int days)
    {
        int alloc_days = 0, alloc_weights = 0, n = weights.size();

        for(int i = 0; i < n; i++)
        {
            if(alloc_weights + weights[i] > capacity)
            {
                alloc_days++;
                alloc_weights = weights[i];

                if(alloc_weights > capacity)
                    return false;
            }
            else
                alloc_weights += weights[i];
        }

        if(alloc_days < days)
            return true;

        return false;
    }

    int shipWithinDays(vector<int>& weights, int days)
    {
        int low = *min_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low <= high)
        {
            int mid = (low + high) >> 1;

            if(isAlloc(weights, mid, days))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};
