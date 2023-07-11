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

// int main()
// {
//     using my_container = std::vector<int>;
//     my_container values{3, 4, 5, 4, 5, 6, 5, 8};
//     std::vector<my_container::iterator> matches;
//     find_all(begin(values), end(values), std::back_inserter(matches), [](int i)
//              { return i == 5; });

//     std::cout << "Found " << matches.size() << " matches: " << std::endl;
//     for (const auto &it : matches)
//     {
//         std::cout << *it << " at position " << (it - cbegin(values)) << std::endl;
//     }
//     return 0;
// }

// Test code
// Initialize a vector container with some values containing 4 at 2 different placs
// after running the find_all algorithm we check the returned iteraor distances to be the specified indexes, report success and failure according to the same

// void find_all_test(std::string const &test_name, std::string const &text, std::pair<std::vector<int>, std::vector<int>> test_input)
// {
//     std::cout << "test: " << test_name << " result: ";
//     std::vector<std::vector<int>::iterator> matches;
//     find_all(std::begin(test_input.first), std::end(test_input.second), std::back_inserter(matches), [](int i)
//              { return i == 5; });
//     std::vector<int> matchIndexes;
//     [&matches, &test_input, &matchIndexes]()
//     { for(auto it : matches) { matchIndexes.push_back(it - std::cbegin(test_input.first)); } }();
//     if (matchIndexes == test_input.second)
//     {
//         std::cout << "Success\n";
//     }
//     else
//     {
//         std::cout << "Failure\n";
//     }
// }

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

// int main()
// {
//     std::vector<int> values{3, 4, 5, 4, 5, 6, 5, 8};
//     std::vector<int> indexes{2, 4, 6};
//     find_all_test("Find all algorithm", "find all index of a particular element", std::make_pair(values, indexes));
// }