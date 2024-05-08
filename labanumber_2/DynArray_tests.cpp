#include <iostream>
#include <cassert>
#include "DynArray.cpp"

void TestsForConcat(){
    DynArray<int> DAR;
    DynArray<int> DS2;

    DAR.Concat(&DS2);
    assert(DAR.get_size() == 0);
    DAR.push_back(0);
    DAR.push_back(1);
    assert(DAR.get_size() == 2 );
    assert(DAR.get(0) == 0);
    assert(DAR.get(1) == 1);
    DS2.push_back(2);
    DS2.push_back(3);
    DAR.Concat(&DS2);
    assert(DAR.get_size() == 4);
    assert(DAR.get(0) == 0);
    assert(DAR.get(1) == 1);
    assert(DAR.get(2) == 2);
    assert(DAR.get(3) == 3);
}

void TestsForPopBackFront(){
    DynArray<int> DAR;
    DAR.pop_back();
    DAR.pop_front();
  
    assert(DAR.get_size() == 0);
   
    DAR.push_back(1);
    DAR.pop_back();
    assert(DAR.get_size() == 0);

    DAR.push_back(1);
    DAR.pop_front();
    assert(DAR.get_size() == 0);

    DAR.push_back(0);
    DAR.push_back(1);
    DAR.push_back(2);
    DAR.push_back(3);
    DAR.pop_back();
    DAR.pop_front();
    assert(DAR.get_size() == 2);
    assert(DAR.get(0) == 1);
    assert(DAR.get(1) == 2);
}

void insert_and_insertAt_tests(){
    DynArray<int> DAR;

    DAR.push_back(0);
    DAR.push_back(1);
    DAR.push_back(2);
    DAR.insertAt(-1, 1);
    assert(DAR.get_size() == 3);
    assert(DAR.get(1) == -1);
    DAR.insert(7, 1);
    assert(DAR.get_size() == 4);
    assert(DAR.get(1) == 7);

}

void Push_back_and_push_forward_tests(){
    DynArray<int> DAR;
    DAR.push_back(0);
    assert(DAR.get_size() == 1);
    assert(DAR.get(0) == 0);
    DAR.push_forward(-1);
    assert(DAR.get_size() == 2);
    assert(DAR.get(0) == -1);
    assert(DAR.get(1) == 0);
    
}

void TestsForImmutableDynArray(){

    ImmutableDynArray<int> dar11;
    
    dar11 = dar11.push_back(1);
    dar11 = dar11.push_back(2);
    dar11 = dar11.push_forward(0);
    assert(dar11.get_size() == 3);
    assert(dar11.get(0) == 0);
    assert(dar11.get(1) == 1);
    assert(dar11.get(2) == 2);

    ImmutableDynArray<int> dar22 = dar11.push_back(3);

    assert(dar11.get_size() == 3);
    assert(dar22.get_size() == 4);
    assert(dar22.get(0) == 0);
    assert(dar22.get(1) == 1);
    assert(dar22.get(2) == 2);
    assert(dar22.get(3) == 3);

    
    

}

int main(){
    TestsForConcat();
    TestsForPopBackFront();
    insert_and_insertAt_tests();
    Push_back_and_push_forward_tests();
    TestsForImmutableDynArray();

    std::cout << "\n All tests passed!!!!!\n\n";


    return 0;
}