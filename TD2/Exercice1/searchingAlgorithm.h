#ifndef SearchingAlgorithm_h
#define SearchingAlgorithm_h
#include <iostream>
#include <vector>

class SearchingAlgorithm{
    protected:
        int numberComparaisons;
        
    public:
        static int totalComparisons;
        static int totalSearch;
        static double averageComparisons;
        //Défaut
        SearchingAlgorithm();

        virtual int search(const std::vector<int> vec, int target) = 0;
        void displaySearchResults(std::ostream& os, int res, int target);


};

//algo
class LinearSearch : public SearchingAlgorithm { 
    public:
        LinearSearch();
        int search(const std::vector<int> vec, int target) override;

};

class JumpSearch : public SearchingAlgorithm {
    public:
        JumpSearch();
        int search(const std::vector<int> vec, int target) override;

};

class BinarySearch : public SearchingAlgorithm {
    public:
        BinarySearch();
        int search(const std::vector<int> vec, int target) override;

};


#endif