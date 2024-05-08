#include <iostream>
#include "Sequence.cpp"
#include <cassert>

void Concat_Tests_For_both(){
    ArraySequence<int> AS1;
    ArraySequence<int> AS2;
    Sequence<int>* res = AS1.Concat(&AS2);
    assert(res->GetLength() == 0);

    AS1.Append(0);
    res = AS1.Concat(&AS2);
    assert(res->GetLength() == 1);
    assert(res->Get(0) == 0);
    res->pop_back();
    AS2.Append(1);
    res = AS1.Concat(&AS2);
    assert(res->GetLength() == 2);
    assert(res->Get(0) == 0);
    assert(res->Get(1) == 1);


    ListSequence<int> LS1;
    ListSequence<int> LS2;
    Sequence<int>* res1 = LS1.Concat(&LS2);
    
    assert(res1->GetLength() == 0);

    LS1.Append(0);
    res1 = LS1.Concat(&LS2);
    assert(res1->GetLength() == 1);
    assert(res1->Get(0) == 0);
    res1->pop_back();
    LS2.Append(1);
    res1 = LS1.Concat(&LS2);
    assert(res1->GetLength() == 2);
    assert(res1->Get(0) == 0);
    assert(res1->Get(1) == 1);
    
}

void AS_subSeq_tests(){
    ArraySequence<int> AS;
    AS.Append(0);
    AS.Append(1);
    AS.Append(2);
    AS.Append(3);
    Sequence<int>* subAS = AS.SubSeq(1,1);
    assert(subAS->GetLength() == 1);
    assert(subAS->Get(0) == 1);

    subAS->pop_back();

    subAS = AS.SubSeq(1,2);
    assert(subAS->GetLength() == 2);
    assert(subAS->Get(0) == 1);
    assert(subAS->Get(1) == 2);
}

void LS_subSeq_tests(){
    ListSequence<int> LS;
    LS.Append(0);
    LS.Append(1);
    LS.Append(2);
    LS.Append(3);
    Sequence<int>* subLS = LS.SubSeq(1,1);
    assert(subLS->GetLength() == 1);
    assert(subLS->Get(0) == 1);

    subLS->pop_back();

    subLS = LS.SubSeq(1,2);
    assert(subLS->GetLength() == 2);
    assert(subLS->Get(0) == 1);
    assert(subLS->Get(1) == 2);
}

int main(){
    Concat_Tests_For_both();
    AS_subSeq_tests();
    LS_subSeq_tests();
}