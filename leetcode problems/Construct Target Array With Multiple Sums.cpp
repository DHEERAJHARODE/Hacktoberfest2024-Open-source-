class Solution
{
public:
    bool isPossible(vector<int> &target)
    {

        // we try to reduce the elms of target to 1's

        // checkimg if only one elm is there.
        if (target.size() == 1)
            return target[0] == 1;

        // finding sum of whole arr
        long sum = 0;

        for (int i = 0; i < target.size(); i++)
        {
            sum += target[i];
        }

        // creating the max heap
        priority_queue<int> pq(target.begin(), target.end());

        // if top of heap becomes 1 loop terminates
        while (pq.top() != 1)
        {

            // finding largest and 2nd largest elm
            // 2nd largest will help us in finding multiplying factor
            long largest = pq.top();

            pq.pop();

            long largest_2 = pq.top();

            // sum of rest of elm
            long restArrSum = sum - largest;

            // calculating multiplying factor
            int n = max(1l, (largest - largest_2) / restArrSum); // 1 because factor should be at least 1

            // updating largest elm
            largest -= (restArrSum * n);

            pq.push(largest);

            sum = restArrSum + largest;

            // if largest becomes less than 1 we cant go back to arr with 1's
            if (largest < 1)
                return false;
        }

        return true;
    }
};