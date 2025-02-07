#include "stdio.h"
#include "stdlib.h"
#include <chrono>

#include <iostream>
#include <fstream>
#include <sstream>

void processInput(std::istream &input)
{
    std::string line;
    while (std::getline(input, line))
    {
        std::cout << line << std::endl;
    }
}

void readFileAndFeed(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    // Feed file content into the processInput function
    processInput(file);
}

int main()
{
    std::string filename = "input.txt"; // Change this to your file path
    readFileAndFeed(filename);

    return 0;
}
