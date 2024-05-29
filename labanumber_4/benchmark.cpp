#include <iostream>
#include <chrono>
#include "binary_tree.cpp"
#include <algorithm>
#include <vector>
#include <random>

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

std::ostream& operator<<(std::ostream& os, const std::chrono::milliseconds& ms) {
    os << ms.count() << "ms";
    return os;
}

// Оператор вывода для std::vector
template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i < vec.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

milliseconds measure_insertion(unsigned pow) {
    BinaryTree<int> tree;
    std::vector<int> v;
    for (unsigned i = 0; i < pow; ++i) {
        v.push_back(i);
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(v.begin(), v.end(), g);

    auto t1 = high_resolution_clock::now();
    for (unsigned i = 0; i < pow; ++i) {
        tree.insert(v[i]);
    }
    auto t2 = high_resolution_clock::now();
    auto ms_int = duration_cast<milliseconds>(t2 - t1);
    return ms_int;
}

milliseconds measure_searching(unsigned pow) {
    BinaryTree<int> tree;
    std::vector<int> v;
    milliseconds ms_max = milliseconds::zero();

    for (unsigned i = 0; i < pow; ++i) {
        v.push_back(i);
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(v.begin(), v.end(), g);

    for (unsigned i = 0; i < pow; ++i) {
        tree.insert(v[i]);
    }

    for (unsigned i = 0; i < pow; ++i) {
        auto t1 = high_resolution_clock::now();
        tree.contains(tree.GetRoot(), i);
        auto t2 = high_resolution_clock::now();
        ms_max = std::max(ms_max, duration_cast<milliseconds>(t2 - t1));
    }

    return ms_max;
}

int main() {
    std::vector<int> pows = {10000, 100000, 1000000, 10000000};
    std::vector<milliseconds> insertion_times; 
    std::vector<milliseconds> contains_time;

    for (unsigned pow : pows) {
        insertion_times.push_back(measure_insertion(pow));
        contains_time.push_back(measure_searching(pow));
    }

    for (size_t i = 0; i < pows.size(); ++i) {
        std::cout << "Elems: " << pows[i] << " Insertion time: " << insertion_times[i] << " Searching max time: " << contains_time[i] << std::endl;
    }

    return 0;
}
