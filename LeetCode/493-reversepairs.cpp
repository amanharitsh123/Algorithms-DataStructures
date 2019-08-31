// Simon St James (ssjgz) - 2019-08-28 (Copied from CodeChef Discuss) 
// Link: https://discuss.codechef.com/t/reverse-pairs/36222/2?u=tux_anonymous
// #define SUBMISSION
#define BRUTE_FORCE
#ifdef SUBMISSION 
#undef BRUTE_FORCE
#define NDEBUG
#endif
#include <iostream>
#include <vector>
#include <algorithm>

#include <cassert>

#include <sys/time.h> // TODO - this is only for random testcase generation.  Remove it when you don't need new random testcases!

using namespace std;

template <typename T>
T read()
{
    T toRead;
    cin >> toRead;
    assert(cin);
    return toRead;
}

// Typical SegmentTree - you can find similar implementations all over the place :)
class SegmentTree
{
    public:
        SegmentTree() = default; // Default Constructure
        SegmentTree(int maxId)
            : m_maxId{maxId},
            m_numElements{2 * maxId},
            m_elements(m_numElements + 1)
            {
            }

        void addValueAt(int pos, int value)
        {
            const auto n = m_numElements;
            auto elements = m_elements.data();
            pos = pos + 1; // Make 1-relative.
            while(pos <= n)
            {
                elements[pos] += value;
                assert(elements[pos] >= 0);
                pos += (pos & (pos * -1));
            }
        }

        // Find the number in the given range (inclusive) in O(log2(maxId)).
        int numInRange(int start, int end) const
        {
            start++; // Make 1-relative.  start and end are inclusive.
            end++;
            int sum = 0;
            auto elements = m_elements.data();
            while(end > 0)
            {
                sum += elements[end];
                end -= (end & (end*-1));
            }
            start--;
            while(start > 0)
            {
                sum -= elements[start];
                start -= (start & (start*-1));
            }
            return sum;
        }
    private:
        int m_maxId;
        int m_numElements;
        vector<int> m_elements;

};

int64_t solveBruteForce(const vector<int>& nums)
{
    int64_t result = 0;
    const int n = nums.size();

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < j; i++)
        {
            if (nums[i] > 2 * nums[j])
                result++;
        }
    }

    return result;
}

int64_t solveOptimised(const vector<int>& nums)
{
    int64_t result = 0;
    const int n = nums.size();
    SegmentTree segmentTree(n + 1);

    struct ValueAndIndex
    {
        int value = -1;
        int index = -1;
    };
    vector<ValueAndIndex> numsAndIndicesDecreasing;
    for (int i = 0; i < n; i++)
    {
        numsAndIndicesDecreasing.push_back({nums[i], i});
    }
    sort(numsAndIndicesDecreasing.begin(), numsAndIndicesDecreasing.end(), [](const auto& lhs, const auto& rhs) 
            {
                if (lhs.value != rhs.value)
                    return lhs.value > rhs.value;
                return lhs.index < rhs.index;
            }); // Use of lambda Functions

    struct TwiceValueAndIndex
    {
        int twiceValue = -1;
        int index = -1;
    };
    vector<TwiceValueAndIndex> twiceValuesAndIndicesIncreasing;
    for (int i = 0; i < n; i++)
    {
        twiceValuesAndIndicesIncreasing.push_back({2 * nums[i], i});
    }
    sort(twiceValuesAndIndicesIncreasing.begin(), twiceValuesAndIndicesIncreasing.end(), [](const auto& lhs, const auto& rhs) 
            {
                if (lhs.twiceValue != rhs.twiceValue)
                    return lhs.twiceValue < rhs.twiceValue;
                return lhs.index < rhs.index;
            });

    for (const auto valueAndIndex : numsAndIndicesDecreasing) // Picking max value
    {
        while (!twiceValuesAndIndicesIncreasing.empty() && twiceValuesAndIndicesIncreasing.back().twiceValue >= valueAndIndex.value) 
        {
            // The set of things we've added to the SegmentTree so far is precisely the set of indices i such that 
            // nums[i] > twiceValuesAndIndicesIncreasing.back().value -
            // now we can find the contribution for j == twiceValuesAndIndicesIncreasing.back().index.
            result += segmentTree.numInRange(0, twiceValuesAndIndicesIncreasing.back().index - 1);
            // We're done with this index j, now.
            twiceValuesAndIndicesIncreasing.pop_back();
        }

        segmentTree.addValueAt(valueAndIndex.index, 1);
    }

    return result;
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    if (argc == 2 && string(argv[1]) == "--test")
    {
        // Generate random testcase.
        struct timeval time;
        gettimeofday(&time,NULL);
        srand((time.tv_sec * 1000) + (time.tv_usec / 1000));

        const int N = rand() % 100 + 1;
        const int maxA = rand() % 1000 + 1;

        cout << N << endl;
        for (int i = 0; i < N; i++)
        {
            cout << ((rand() % maxA)) << " " << endl;
        }

        return 0;
    }

    const int N = read<int>();

    vector<int> nums(N);
    for (auto& x : nums)
    {
        x = read<int>();
    }


#ifdef BRUTE_FORCE
    const auto solutionBruteForce = solveBruteForce(nums);
    cout << "solutionBruteForce: " << solutionBruteForce << endl;
    const auto solutionOptimised = solveOptimised(nums);
    cout << "solutionOptimised: " << solutionOptimised << endl;

    assert(solutionOptimised == solutionBruteForce);
#else
    const auto solutionOptimised = solveOptimised();
    cout << solutionOptimised << endl;
#endif

    assert(cin);
}