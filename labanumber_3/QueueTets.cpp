#include <iostream>
#include <cassert>
#include "BinaryHeap.cpp"

void testPushAndPop() {
    PriorityQueue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(15);
    assert(pq.size() == 3);
    assert(pq.pop() == 20);
    assert(pq.pop() == 15);
    assert(pq.pop() == 10);
    assert(pq.size() == 0);
    std::cout << "success" << std::endl;
}

void testChangePriority() {
    PriorityQueue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(15);
    pq.changePriority(0, 5); 
    assert(pq.pop() == 15);
    assert(pq.pop() == 10);
    assert(pq.pop() == 5);
    std::cout << "success" << std::endl;
}

void testEmpty() {
    PriorityQueue<int> pq;
    assert(pq.empty() == true);
    pq.push(10);
    assert(pq.empty() == false);
    pq.pop();
    assert(pq.empty() == true);
    std::cout << "success" << std::endl;
}

void testSize() {
    PriorityQueue<int> pq;
    assert(pq.size() == 0);
    pq.push(10);
    pq.push(20);
    assert(pq.size() == 2);
    pq.pop();
    assert(pq.size() == 1);
    pq.pop();
    assert(pq.size() == 0);
    std::cout << "success" << std::endl;
}
/*
void testPrint() {
    PriorityQueue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(15);
    pq.print(); 
    std::cout << "success" << std::endl;
}
*/

int main() {
    testPushAndPop();
    testChangePriority();
    testEmpty();
    testSize();
    //testPrint();
    std::cout << "All tests passed" << std::endl;
    return 0;
}
