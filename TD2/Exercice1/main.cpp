#include "searchingAlgorithm.h"
#include <iostream>
#include <vector>

int main(){

    //VEcteur trié uniquement
    std::vector<int> numbers = {2,5,7,12,16,23,38,56,74,91};

    int target1 = 23;
    int target2 = 17;

    std::cout << "Test Linear search:\n";
    LinearSearch linear;
    int res1 = linear.search(numbers, target1);
    linear.displaySearchResults(std::cout, res1, target1);
    std::cout << "Test Linear search avec élément absent:\n";
    int res2 = linear.search(numbers, target2);
    linear.displaySearchResults(std::cout, res2, target2);

    std::cout << "Test Jump search:\n";
    JumpSearch jump;
    int res3 = jump.search(numbers, target1);
    jump.displaySearchResults(std::cout, res3, target1);
    std::cout << "Test Jump search avec élément absent:\n";
    int res4 = jump.search(numbers, target2);
    jump.displaySearchResults(std::cout, res4, target2);

    std::cout << "Test Binary search:\n";
    BinarySearch binary;
    int res5 = binary.search(numbers, target1);
    binary.displaySearchResults(std::cout, res5, target1);
    std::cout << "Test Binary search avec élément absent:\n";
    int res6 = binary.search(numbers, target2);
    binary.displaySearchResults(std::cout, res6, target2);
};