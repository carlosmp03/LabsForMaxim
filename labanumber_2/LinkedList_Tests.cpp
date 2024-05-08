#include <iostream>
#include <cassert>
#include "LinkedList.cpp"

void Tests_For_Append_And_Prepend(){
    LinkedList<int> LS;
    Node<int>* nd0 = new Node<int>(0);
    Node<int>* nd1 = new Node<int>(1);

    LS.prepend(nd0->elem);
    assert(LS.getSize() == 1);
    assert(LS.get(0) == 0);
    LS.append(nd1->elem);
    assert(LS.getSize() == 2);
    assert(LS.get(1) == 1);

}

void insertionTests(){
    LinkedList<int> LS;
    LS.append(0);
    LS.append(1);
    LS.append(2);
    LS.insertAt(1, -1);
    assert(LS.getSize() == 3);
    assert(LS.get(1) == -1);
    LS.insert(3, 3);
    assert(LS.getSize() == 4);
    assert(LS.get(3) == 3);
}

void ConcatTests(){
    LinkedList<int> LS1;
    LinkedList<int> LS2;
    LS1.Concat(&LS2);
    assert(LS1.getSize() == 0);
    LS2.append(0);
    LS1.Concat(&LS2);
    assert(LS1.getSize() == 1);
    assert(LS1.get(0) == 0);
    LS1.pop_back();
    LS2.pop_back();
    LS1.append(0);
    LS2.append(1);
    LS1.Concat(&LS2);
    assert(LS1.getSize() == 2);
    assert(LS1.get(0) == 0);
    assert(LS1.get(1) == 1); 
}

void ImmutableConcatTests(){
    LinkedList<int> LS1;
    LinkedList<int> LS2;
    LinkedList<int>* RESLS = LS1.ImmutableConcat(&LS2);
    assert(RESLS->getSize() == 0);
    LS1.append(0);
    LS1.append(1);
    LS2.append(2);
    LS2.append(3);
    RESLS = LS1.ImmutableConcat(&LS2);
    assert(RESLS->getSize() == 4);
    assert(RESLS->get(0) == 0);
    assert(RESLS->get(1) == 1);
    assert(RESLS->get(2) == 2);
    assert(RESLS->get(3) == 3);
}

void ImmutableAppend(){
    LinkedList<int> LS;
    
    LS.append(0);
    LS.append(1);
    LinkedList<int> * ILS = LS.ImmutableAppend(2);
    assert(LS.getSize() == 2);
    assert(LS.get(0) == 0);
    assert(LS.get(1) == 1);

    assert(ILS->getSize() == 3);
    assert(ILS->get(0) == 0);
    assert(ILS->get(1) == 1);
    assert(ILS->get(2) == 2);

}

void ImmutabblePrepend(){
    LinkedList<int> LS;
    LinkedList<int>* ILS;

    LS.append(0);
    LS.append(1);
    ILS = LS.ImmutablePrepend(-1);
    assert(LS.getSize() == 2);
    assert(LS.get(0) == 0);
    assert(LS.get(1) == 1);

    assert(ILS->getSize() == 3);
    assert(ILS->get(0) == -1);
    assert(ILS->get(1) == 0);
    assert(ILS->get(2) == 1);


}

void SubSeqTests(){
    LinkedList<int> LS;
    for (int i = 0 ; i < 5; i++){
        LS.append(i);
    }
    LinkedList<int>* subLS=  LS.GetSubList(1,2);
    assert(subLS->getSize() == 2);
    assert(subLS->get(0) == 1);
    assert(subLS->get(1) == 2);

}

int main(){
    Tests_For_Append_And_Prepend();
    insertionTests();
    ImmutableConcatTests();
    ConcatTests();
    SubSeqTests();
    ImmutableAppend();
    ImmutabblePrepend();
    std::cout << "\nAll tests passed!!!\n\n";
    return 0;
}

