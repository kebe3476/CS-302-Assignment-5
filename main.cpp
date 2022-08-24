/*
CS 302 Assignment 5

Name: Keith Beauvais, 5005338658, CS 302 Assignment 5
*/
#include "binTree.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

int main()
{
    std::string filename, redApple;
    std::vector<bool> apples;
    std::ifstream infile;
    
    std::cout << "Enter apple tree file: ";
    std::cin >> filename;

    infile.open(filename);

    infile >> redApple;

    while (!infile.eof())
    {
        apples.push_back( redApple == "True" ? true : false );

        infile >> redApple;
    }

    infile.close();

    binTree appleTree(apples);
    //appleTree.preOrder();


    std::cout << "Minimum Time Needed: " << appleTree.minTime() << std::endl;


    return 0;
}