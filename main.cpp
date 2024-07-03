#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include "insertion_sort.h"
#include "quick_sort.h"
#include "merge_sort.h"
#include "heap_sort.h"
#include "searches.h"
#include <utility>
#include <chrono> // for std::chrono

using namespace std;

struct info {
    
    string name, fullname, fullinfo;
    
    info (string n = "", string s = "", string full = "")
    :  name(n), fullname(s), fullinfo(full){}
};
 

void copyVector(vector<info> & real, vector<info> & vec){

    for (int i = 0; i < real.size(); i++)
    {
        info newElement(real[i].name, real[i].fullname, real[i].fullinfo);
        vec.push_back(newElement);
    }
}

string toUpper(const string& str) {
    string result = str;
    for (char& c : result) {
        c = toupper(c);
    }
    return result;
}

int main() {

    vector<info> quick_sort, merge_sort, insert_sort, heap_sort, myvec;
    string file_name, query = "", line;
   
    cout << "Please enter the contact file name:" << endl;
    cin >> file_name;
    
    cout << "Please enter the word to be queried:" << endl;
    cin.ignore();
    getline(cin, query); // Read the entire line of input
    cout << endl;
    
    ifstream file;
    file.open(file_name);
    while (getline(file, line)) {
        
        istringstream iss(line);
        string name, surname, fullname, contact, city, fullinfo;
        
    // Extract name, surname
       iss >> name >> surname >> contact >> city ;
       fullname = name + " " + surname;
       fullinfo = toUpper(fullname) + " " + contact + " " + city;
       info lineinfo (name, toUpper(fullname), fullinfo);
       myvec.push_back(lineinfo);
    
    }
    
    copyVector(myvec, quick_sort);
    copyVector(myvec, merge_sort);
    copyVector(myvec, insert_sort);
    copyVector(myvec, heap_sort);
    
    // Get the current time before sorting
    auto start = std::chrono::high_resolution_clock::now();
    // Call your sorting function
    insertionSort(insert_sort);
    // Get the current time after sorting
    auto end = std::chrono::high_resolution_clock::now();
    // Calculate the duration
    std::chrono::duration<double, std::nano> insertionSortTime = (end - start);
    
    start = std::chrono::high_resolution_clock::now();
    heapsort(heap_sort);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> heapSortTime = (end - start);
    
    start = std::chrono::high_resolution_clock::now();
    quicksort(quick_sort);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> quickSortTime = (end - start);
    
    start = std::chrono::high_resolution_clock::now();
    mergeSort(merge_sort);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> mergeSortTime = (end - start);
 
    cout << "Sorting the vector copies" << endl;
    cout << "======================================" << endl;
    cout << "Quick Sort Time: " << quickSortTime.count() << " Nanoseconds" << endl;
    cout << "Insertion Sort Time: " << insertionSortTime.count() << " Nanoseconds" << endl;
    cout << "Merge Sort Time: " << mergeSortTime.count() << " Nanoseconds" << endl;
    cout << "Heap Sort Time: " << heapSortTime.count() << " Nanoseconds" << endl << endl;
    
    cout << "Searching for " << query << endl;
    cout << "======================================" << endl;
    vector<info> founded;
    
    int N = 100;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++){
        founded.clear();
        binarySearch(insert_sort, toUpper(query), founded);
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> binarySearchTime = (end - start)/ N;
    
    if(founded.size() != 0){
        for (int i = 0; i < founded.size(); i++){
            cout << founded[i].fullinfo << endl;
        }
    }
    
    else {
        cout << toUpper(query) << " does NOT exist in the dataset" << endl;
    }
    cout << "Binary Search Time: " << binarySearchTime << " Nanoseconds" << endl << endl;
    
    cout << "Search results for Sequential Search:" << endl;
    start = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < N; i++){
        founded.clear();
        sequentialSearch(insert_sort, toUpper(query), founded);
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> sequentailSearchTime = (end - start)/ N;
    
    if(founded.size() != 0){
        for (int i = 0; i < founded.size(); i++){
            cout << founded[i].fullinfo << endl;
        }
    }
    
    else {
        cout << toUpper(query) << " does NOT exist in the dataset" << endl;
    }
    
    cout << "Sequential Search Time: " << sequentailSearchTime << " Nanoseconds" << endl << endl;
    cout << "SpeedUp between Search Algorithms" << endl;
    cout << "======================================" << endl;
    cout << "(Sequential Search/ Binary Search) SpeedUp = " << sequentailSearchTime / binarySearchTime << endl;
    
    // Calculate speedups
    double insertionSpeedup = insertionSortTime.count() / quickSortTime.count();
    double mergeSpeedup = mergeSortTime.count() / quickSortTime.count();
    double heapSpeedup = heapSortTime.count() / quickSortTime.count() ;

    // Output speedups
    cout << endl;
    cout << "SpeedUps between Sorting Algorithms" << endl;
    cout << "====================================" << endl;
    cout << "(Insertion Sort/ Quick Sort) SpeedUp = " << insertionSpeedup << endl;
    cout << "(Merge Sort / Quick Sort) SpeedUp = " << mergeSpeedup << endl;
    cout << "(Heap Sort / Quick Sort) SpeedUp = " << heapSpeedup << endl;
    
    return 0;
}
