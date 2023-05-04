#include "Sequence.h"
#include "Sequence.cpp"
#include <iostream>
#include <cassert>

int main()
{
    // Default Constructor
    Sequence s; // empty

    // For empty sequence
    assert(s.size() == 0);                // test size
    assert(s.empty() == true);            // test empty
    assert(s.remove("madeUpThing") == 0); // nothing to remove
    assert(s.set(0, "set") == false);     // nothing to set

    ItemType str;
    assert(s.get(0, str) == false); // nothing to get

    // test inserts
    assert(s.insert(0, "Now index 0") == 0);
    assert(s.insert("Now index 0") == 0);
    assert(s.insert("now index 2") == 2);

    // test find
    assert(s.find("Now index 0") == 0);
    assert(s.find("random") == -1);

    // test swap and get
    Sequence s2;
    s2.insert("newSeq");
    s.swap(s2);
    std::string get;
    assert(s.get(0, get) == true);
    assert(get == "newSeq");

    Sequence sub1;
    sub1.insert(0, "0");
    sub1.insert(1, "1");
    sub1.insert(2, "0");
    sub1.insert(3, "1");
    sub1.insert(4, "2");
    Sequence sub2;
    sub2.insert(0, "0");
    sub2.insert(1, "1");
    sub2.insert(2, "2");

    // test subsequence
    assert(subsequence(sub1, sub2) == 2);

    // test concatReverse
    Sequence result;
    ItemType resultFirstELement;
    concatReverse(sub1,sub2,result);
    result.get(0,resultFirstELement);
    assert(resultFirstELement=="2");

    // Copy Constructor
    Sequence copied = sub2;
    ItemType firstCopied;
    copied.get(0,firstCopied);
    assert(firstCopied == "0");

    // Assignment Operator
    result = copied;
    ItemType firstResult;
    result.get(0,firstResult);
    assert(firstResult == "0");

    std::cout << "passed all test cases" << std::endl;
}
