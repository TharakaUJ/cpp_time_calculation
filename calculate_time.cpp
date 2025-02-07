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
    resultsFile << "TestCase,Function1,Function2,Function3\n";

    for (size_t i = 0; i < testCases.size(); ++i)
    {
        double time1 = benchmark(insersion_sort, testCases[i]);
        double time2 = benchmark(bubble_sort, testCases[i]);
        double time3 = benchmark(optimized_bubble_sort, testCases[i]);
        double time4 = benchmark(selection_sort, testCases[i]);

        resultsFile << i + 1 << "," << time1 << "," << time2 << "," << time3 << "\n";
        std::cout << "Test Case " << i + 1 << ": Function1=" << time1 << "s, Function2=" << time2 << "s, Function3=" << time3 << "s\n";
    }

    resultsFile.close();
    std::cout << "Results saved to results.csv" << std::endl;
    return 0;
}
