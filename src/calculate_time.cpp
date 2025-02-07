#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <chrono>

// Functions
#include "optimizedBubble.h"
#include "bubble.h"
#include "selection.h"
#include "insersion.h"

// Function to read test cases from a file
std::vector<std::vector<int>> readTestCases(const std::string &filename)
{
    std::vector<std::vector<int>> testCases;
    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return {};
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::vector<int> testCase;
        std::stringstream ss(line);
        int num;
        while (ss >> num)
        {
            testCase.push_back(num);
        }
        testCases.push_back(testCase);
    }
    return testCases;
}

// Function to convert a space-separated string into a vector<int>
std::vector<int> stringToVector(const std::string &input)
{
    std::vector<int> numbers;
    std::stringstream ss(input);
    int num;
    while (ss >> num)
    {
        numbers.push_back(num);
    }
    return numbers;
}

// Function to measure execution time
template <typename Func>
double benchmark(Func func, const std::vector<int> &data)
{
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> dataCopy = data; // FIXED: Directly copy data
    func(dataCopy);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();
}

// Main function
int main()
{
    std::string filename = "input.txt";
    std::vector<std::vector<int>> testCases = readTestCases(filename);

    if (testCases.empty())
    {
        return 1; // Exit if no test cases
    }

    std::ofstream resultsFile("results.csv");
    resultsFile << "TestCase,insersion_sort,bubble_sort,optimized_bubble_sort,selection_sort\n";

    for (size_t i = 0; i < testCases.size(); ++i)
    {
        std::vector<int> testCase = testCases[i];
        int length = testCase.size();
        double time1 = benchmark(insersion_sort, testCases[i]);
        double time2 = benchmark(bubble_sort, testCases[i]);
        double time3 = benchmark(optimized_bubble_sort, testCases[i]);
        double time4 = benchmark(selection_sort, testCases[i]);

        resultsFile << length << "," << time1 << "," << time2 << "," << time3 << "," << time4 << "\n";
        std::cout << "Test Case " << i + 1 << ": insersion_sort=" << time1 << "s, bubble_sort=" << time2 << "s, optimized_bubble_sort=" << time3 << "s, selection_sort=" << time4 << "s\n";
    }

    resultsFile.close();
    std::cout << "Results saved to results.csv" << std::endl;
    return 0;
}
