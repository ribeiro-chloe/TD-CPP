#include "searchingAlgorithm.h"
#include <cmath>

int SearchingAlgorithm::totalComparisons = 0;
int SearchingAlgorithm::totalSearch = 0;
double SearchingAlgorithm::averageComparisons = 0.0;


SearchingAlgorithm::SearchingAlgorithm(): numberComparaisons(0) {}

void SearchingAlgorithm::displaySearchResults(std::ostream& os, int res, int target){
    totalComparisons += numberComparaisons;
    totalSearch++;
    if (totalSearch > 0){
        averageComparisons = totalComparisons/totalSearch;
    }
    if(res != -1){
        os << "Élement trouvé à l'indice :" << res << "\n";
    }else{
        os << "Élément non trouvé\n";
    }
    os << "Comparaisons pour cette recherche:"<<numberComparaisons<<"\n";
    os << "Total des comparaisons:"<<totalComparisons<<"\n";
    os << "Total des recherches:"<<totalSearch<<"\n";
    os << "Moyenne des comparaisons:"<<averageComparisons<<"\n\n";
}


//LinearSearch

LinearSearch::LinearSearch() : SearchingAlgorithm(){}

int LinearSearch::search(const std::vector<int> vec, int target){
    numberComparaisons =0;
    for(int i = 0; i<vec.size(); i++){
        numberComparaisons++;
        if(vec[i]==target){
            return i;
        }
    }
    return -1;
}

//JumpSearch
JumpSearch::JumpSearch() : SearchingAlgorithm(){}

int JumpSearch::search(const std::vector<int> vec, int target){
    numberComparaisons = 0;
    int n = vec.size();
    if (n==0) return -1;

    int step = static_cast<int>(std::sqrt(n));
    int prev = 0;

    while (prev < n){
        numberComparaisons++;
        int current = std::min(step, n) -1;
        if(vec[current] >= target){
            break;
        }
        prev = step;
        step += static_cast<int>(std::sqrt(n));
        if (prev >= n) return -1;
    }

    while (prev < std::min(step,n)){
        numberComparaisons++;
        if(vec[prev]== target){
            return prev;
        }
        prev++;
    }
    return -1;
}

//BinarySearch
BinarySearch::BinarySearch() : SearchingAlgorithm(){}

int BinarySearch::search(const std::vector<int> vec, int target){
    numberComparaisons = 0;
    int left = 0;
    int right = vec.size() -1;

    while (left <= right){
        int mid = left + (right - left) / 2;
        numberComparaisons++;
        if(vec[mid] == target){
            return mid;
        }

        numberComparaisons++;
        if(vec[mid] < target){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return -1;
}