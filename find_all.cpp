#include <iostream>
#include <vector>
#include <iterator>
#include "gtest/gtest.h"
template <typename InputIterator, typename OutputIterator, typename Predicate>
OutputIterator find_all(InputIterator first, InputIterator last, OutputIterator output, Predicate pred)
{
    while (first != last)
    {
        if (pred(*first))
        {
            *output = first;
            ++output;
        }
        ++first;
    }

    return output;
}

TEST(FindAllAlgorithm, CheckIfCorrectIndicesReturned)
{
    std::vector<int> values{3, 4, 5, 4, 5, 6, 5, 8};
    std::vector<int> indexes{2, 4, 6};
    std::vector<std::vector<int>::iterator> matches;
    find_all(std::begin(values), std::end(values), std::back_inserter(matches), [](int i)
             { return i == 5; });
    std::vector<int> matchIndexes;
    [&matches, &values, &matchIndexes]()
    { for(auto it : matches) { matchIndexes.push_back(it - std::cbegin(values)); } }();
    EXPECT_EQ(matchIndexes, indexes);
}
