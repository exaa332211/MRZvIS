#include "classes/headers/BinDigit.h"
#include <iostream>
//BinDigit::POSITIVE, BinDigit::NEGATIVE   -  Are BinDigit's constants, mean sign
//^^^ USE IT TO GIVE A SIGN TO A BINARY DIGIT OBJECT (! Not BinDigit(-10) !) ^^^

int main()
{

    std::vector<int> firstVector, secondVector;
    int processingTime;
    std::string input;

    std::cout << "vector 1, n - stop" << std::endl;
    while (true)
    {
        std::cin >> input;
        if (input == "n" || input.empty())
            break;

        int var = atoi(input.c_str());
        if ((var > 127) || (var < -127))
        {
            std::cout << "Число должно быть -127 ≤ x ≤ 127";
            continue;
        }
        firstVector.push_back(var);
    }

    std::cout << "vector 2" << std::endl;
    while (true)
    {
        std::cin >> input;
        if (input == "n")
            break;

        int var = atoi(input.c_str());
        if ((var > 127) || (var < -127))
        {
            std::cout << "Число должно быть -127 ≤ x ≤ 127";
            continue;
        }

        secondVector.push_back(var);
    }

    if (secondVector.size() != firstVector.size())
        exit(1);

    std::cout << "processingTime" << std::endl;
    std::cin >> processingTime;

    BinDigit bin(20, BinDigit::POSITIVE);
    BinDigit another(17, BinDigit::POSITIVE);
    BinDigit rez(0, BinDigit::POSITIVE);
    std::vector<BinDigit> first, second;
    for (int i = 0; i < firstVector.size(); i++)
    {
        BinDigit bin(firstVector[i], firstVector[i] > 0 ? BinDigit::POSITIVE : BinDigit::NEGATIVE);
        first.push_back(bin);
        BinDigit another(secondVector[i], secondVector[i] > 0 ? BinDigit::POSITIVE : BinDigit::NEGATIVE);
        second.push_back(another);
    }
    rez.start(first, second);
}
