#include <iostream>
#include <vector>
#include <iterator>

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
int main()
{
    std::cout << "test: find all index of a particular element, result: ";
    std::vector<int> values{3, 4, 5, 4, 5, 6, 5, 8};
    std::vector<std::vector<int>::iterator> matches;
    find_all(std::begin(values), std::end(values), std::back_inserter(matches), [](int i)
             { return i == 5; });
    std::vector<int> matchIndexes;
    for (auto it : matches)
    {
        matchIndexes.push_back(it - std::cbegin(values));
    }
    if (matchIndexes == std::vector<int>{2, 4, 6})
    {
        std::cout << "Success\n";
    }
    else
    {
        std::cout << "Failure\n";
    }
}