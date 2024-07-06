# Sorting-and-Searching-with-Different-Sort-Algorithms


## Project Overview
This project is an implementation of Homework 4 for the CS300 course at Sabancı University, Spring 2023-2024. The objective is to develop and compare various sorting and searching algorithms using an unsorted PhoneBook dataset. The project focuses on performance optimization and efficiency analysis of the implemented algorithms.

## Features
### Sorting Algorithms
The following sorting algorithms are implemented and compared:
- **Insertion Sort**
- **Quick Sort** (with median as pivot and insertion sort for small subarrays)
- **Merge Sort** (in-place, without auxiliary memory)
- **Heap Sort**

### Searching Algorithms
The following searching algorithms are implemented and compared:
- **Sequential Search**
- **Binary Search**

## How It Works
1. **Input Handling**: The program prompts the user to input a PhoneBook file and a query entry (full or partial contact name).
2. **Data Loading**: The PhoneBook data is loaded into multiple vectors for each sorting algorithm.
3. **Sorting**: Each vector is sorted using the specified sorting algorithms.
4. **Searching**: The sorted PhoneBook vectors are searched using the specified searching algorithms.
5. **Output**: The program displays the sorting and search times in nanoseconds and calculates speedups for both sorting and searching algorithms.

## Sample Usage
### Input
- `PhoneBook.txt`: Each line contains a Name, Surname, Telephone, and City.
- Search Query: A full or partial contact name.

### Output
- Sorting times and speedups
- Search times and speedups
- Search results for the provided query

## Example
```
Please enter the contact file name:
PhoneBook-sample1.txt
Please enter the word to be queried:
Mario

Sorting the vector copies
======================================
Quick Sort Time: 5044 Nanoseconds
Insertion Sort Time: 5663 Nanoseconds
Merge Sort Time: 8592 Nanoseconds
Heap Sort Time: 7514 Nanoseconds

Searching for Mario
======================================
MARIO does NOT exist in the dataset
Binary Search Time: 2094.18 Nanoseconds
Sequential Search Time: 5784.73 Nanoseconds

SpeedUp between Search Algorithms
======================================
(Sequential Search/ Binary Search) SpeedUp = 2.76229

SpeedUps between Sorting Algorithms
======================================
(Insertion Sort/ Quick Sort) SpeedUp = 1.12271
(Merge Sort / Quick Sort) SpeedUp = 1.70325
(Heap Sort / Quick Sort) SpeedUp = 1.48968
```

## Building and Running the Project
1. Clone the repository to your local machine.
2. Compile the project files:
   ```sh
   g++ -o sorting_searching main.cpp insertion_sort.cpp quick_sort.cpp merge_sort.cpp heap_sort.cpp sequential_search.cpp binary_search.cpp
   ```
3. Run the executable:
   ```sh
   ./sorting_searching
   ```

## Notes
- The Quick Sort algorithm uses the median as the pivot and switches to Insertion Sort for subarrays smaller than 10 elements.
- Merge Sort is implemented in-place, without using additional memory.
- The project includes both full name search and partial name search functionalities.
