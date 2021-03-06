#include <iostream>
#include <chrono>
#include <random>
#include <ctime>
#include <1. Combinatoric Algorithms/Sort Algorithms/MergeSort.h>
#include "2. Data Compression Algorithms/Without Data Loss/BurrowsWheelerTransform.h"
#define compress
#define DATACOMP


using namespace std::chrono;

template <class T>
void sort(T *start, T *end){
    mergeSort(start, end);
}

int main() {
#ifdef DATACOMP
    std::string c = "ABACABA";
    std::cout << "str: " << c << '\n';

    std::string coded = BWT(c);
    std::cout << "compressed: " << coded << '\n';

    std::string decoded = BWTdecode(coded);
    std::cout << "decompressed: " << decoded << '\n';
#elif SORT
#ifndef TEST

    int mas[] = {55, 10, 5, -23, 11, 0, 30, 12, 14, 0, 0, 563, 5467, 234, 12, 654};

    sort(&mas[0], &mas[( sizeof(mas) / sizeof(mas[1]) ) - 1]);

    for (auto a : mas) {
        std::cout << a << " ";
    }
    std::cout << "\n end \n ";

#else
    // random generator
    std::mt19937 gen(time(nullptr));
    std::uniform_int_distribution<int> uid(INT32_MIN, INT32_MAX);

    // mas with random keys generator
    int unsorted_mas[100000];
    for(auto &item : unsorted_mas)
        item = gen();

    // test with time counter
    auto start = steady_clock::now();

    sort(&unsorted_mas[0], &unsorted_mas[99999]);

    auto end = steady_clock::now();
    auto elapsed = duration_cast<milliseconds>(end - start);

    std::cout << "\n\n Sort ended - 10k keys: \n"
             << "  Elapsed time: " << elapsed.count() << " ms\n";
#endif
#endif

    return 0;
}