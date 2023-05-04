# CS32Project2

## SPEC
Programming Assignment 2
Double Time
Link Link
Time due: 11:00 PM Tuesday, April 25

Homework 1 gave you extensive experience with the Sequence type using both arrays and dynamically-allocated arrays. In this project, you will re-write the implementation of the Sequence type to employ a doubly-linked list rather than an array. You must not use arrays. You will also implement a couple of algorithms that operate on sequences.

Implement Sequence yet again
Consider the Sequence interface from problem 2 of Homework 1:

using ItemType = TheTypeOfElementGoesHere;

class Sequence
{
  public:
    Sequence();
    bool empty() const;
    int size() const;
    int insert(int pos, const ItemType& value);
    int insert(const ItemType& value);
    bool erase(int pos);
    int remove(const ItemType& value);
    bool get(int pos, ItemType& value) const;
    bool set(int pos, const ItemType& value);
    int find(const ItemType& value) const;
    void swap(Sequence& other);
};
In problem 3 of Homework 1, you implemented this interface using an array. For this project, implement this Sequence interface using a doubly-linked list. (You must not use the list class template from the C++ library.)

For the array implementation of problem 3 of Homework 1, since you declared no destructor, copy constructor, or assignment operator, the compiler wrote them for you, and they did the right thing. For this linked list implementation, if you let the compiler write the destructor, copy constructor, and assignment operator, they will do the wrong thing, so you will have to declare and implement these public member functions as well:

Destructor
When a Sequence is destroyed, the nodes in the linked list must be deallocated.
Copy constructor
When a brand new Sequence is created as a copy of an existing Sequence, enough new nodes must be allocated to hold a duplicate of the original list.
Assignment operator
When an existing Sequence (the left-hand side) is assigned the value of another Sequence (the right-hand side), the result must be that the left-hand side object is a duplicate of the right-hand side object, with no memory leak of list nodes (i.e. no list node from the old value of the left-hand side should be still allocated yet inaccessible).
Notice that there is now no a priori limit on the maximum number of items in the Sequence (so the one-argument form of insert should never return −1). Notice also that, as in Homework 1, if a Sequence has a size of n, then the values of the first parameter to get for which that function retrieves an item (that was previously inserted by a call to one of the insert member functions) and returns true are 0, 1, 2, ..., n−1; for other values, it returns false without setting its second parameter. For example:

        Sequence ss;  // ItemType is std::string
        ss.insert(0, "aaa");
        ss.insert(1, "ccc");
        ss.insert(2, "bbb");
        ItemType x = "xxx";
        assert(!ss.get(3, x)  &&  x == "xxx");  // x is unchanged
        assert(ss.get(1, x)  &&  x == "ccc");
This is the same visible behavior as in Homework 1.

Another requirement is that as in Problem 5 of Homework 1, the number of statement executions when swapping two sequences must be the same no matter how many items are in the sequences.

Implement some sequence algorithms
Implement the following two functions. Notice that they are non-member functions: They are not members of Sequence or any other class, so they must not access private members of Sequence.

int subsequence(const Sequence& seq1, const Sequence& seq2);
Consider all the items in seq2; let's call them seq20, seq21, ..., seq2n. If there exists at least one k such that seq1k == seq20 and seq1k+1 == seq21 and ... and seq1k+n == seq2n, and k+n < seq1.size(), then this function returns the smallest such k. (In other words, if seq2 is a consecutive subsequence of seq1, the function returns the earliest place in seq1 where that subsequence starts.) If no such k exists or if seq2 is empty, the function returns -1. For example, if seq1 were a sequence of ints consisting of

     30 21 63 42 17 63 17 29 8 32
and seq2 consists of

     63 17 29
then the function returns 5, since the consecutive items 63 17 29 appear in seq1 starting with the 63 at position 5. (The result is not 2, because while there's a 63 at position 2, followed eventually by a 17 and a 29, those items are not consecutive in seq1.) With the same seq1, if seq2 consists of

     17 63 29
then the function returns -1.

void concatReverse(const Sequence& seq1, const Sequence& seq2, Sequence& result);
This function produces as a result a sequence that consists of the items in seq1 in reverse order of their occurrence in seq1 followed by the items in seq2 in reverse order of their occurrence in seq2.

More formally: Consider the items in seq1; let's call them seq10, seq11, …, seq1m, and let's call the items seq2 contains seq20, seq21, …, seq2n. When this function returns, result must consist of the sequence seq1m, seq1m-1, …, seq11, seq10, seq2n, seq2n-1, …, seq21, seq20, and no other items.

If seq1 is empty, then when this function returns, result must consist of the sequence seq2n, …, seq20, and no other items. If seq2 is empty, then when this function returns, result must consist of the sequence seq1m, …, seq10, and no other items. If seq1 and seq2 are empty, then when this function returns, result must be empty.
When this function returns, result must not contain any items that this spec does not require it to contain. (You must not assume result is empty when it is passed in to this function; it might not be.)

As an example, if seq1 were a sequence of chars consisting of

     p a r
and seq2 consists of

     r o t
then no matter what value it had before, result ends up consisting of:

     r a p t o r
Be sure that in the face of aliasing, these functions behave as this spec requires: Does your implementation work correctly if seq1 and result refer to the same Sequence, for example?

Other Requirements
Regardless of how much work you put into the assignment, your program will receive a zero for correctness if you violate these requirements:

Your class definition, declarations for the two required non-member functions, and the implementations of any functions you choose to inline must be in a file named Sequence.h, which must have appropriate include guards. The implementations of the functions you declared in Sequence.h that you did not inline must be in a file named Sequence.cpp. Neither of those files may have a main routine (unless it's commented out). You may use a separate file for the main routine to test your Sequence class; you won't turn in that separate file.

Except to add a destructor, copy constructor, assignment operator, and dump function (described below), you must not add functions to, delete functions from, or change the public interface of the Sequence class. You must not declare any additional struct/class outside the Sequence class, and you must not declare any public struct/class inside the Sequence class. You may add whatever private data members and private member functions you like, and you may declare private structs/classes inside the Sequence class if you like.

If you wish, you may add a public member function with the signature void dump() const. The intent of this function is that for your own testing purposes, you can call it to print information about the sequence; we will never call it. You do not have to add this function if you don't want to, but if you do add it, it must not make any changes to the sequence; if we were to replace your implementation of this function with one that simply returned immediately, your code must still work correctly. The dump function must not write to cout, but it's allowed to write to cerr.

The source files you submit for this project must not contain the word friend or pragma or vector or the character [ (open square bracket). You must not use any global variables whose values may be changed during execution. (Global constants are fine.)

Sequence.cpp must not contain the word string. (Sequence.h may contain it only in a using statement introducing a type alias, and must contain #include <string> if a using statement introducing a type alias contains the word string.)

Your code must build successfully (under both g32 and either Visual C++ or clang++) if linked with a file that contains a main routine.

You must have an implementation for every member function of Sequence, as well as the non-member functions subsequence and concatReverse. Even if you can't get a function implemented correctly, it must have an implementation that at least builds successfully. For example, if you don't have time to correctly implement Sequence::erase or concatReverse, say, here are implementations that meet this requirement in that they at least build successfully:

        bool Sequence::erase(int pos)
        {
            return true;  // not correct, but at least this compiles
        }

        void concatReverse(const Sequence& seq1, const Sequence& seq2, Sequence& result)
        {
            // does nothing; not correct, but at least this compiles
        }
You've probably met this requirement if the following file compiles and links with your code. (This uses magic beyond the scope of CS 32.)

        #include "Sequence.h"
        #include <type_traits>

        #define CHECKTYPE(c, f, r, a)  \
        {  \
         static_assert(std::is_same<decltype(&c::f), r (c::*)a>::value, \
             "You did not declare " #c "::" #f " as the Project 2 spec does");  \
         auto p = static_cast<r (c::*)a>(&c::f);  \
         (void) p;  \
        }
        #define CHECKTYPENONMEMBER(f, r, a)  \
        {  \
         static_assert(std::is_same<decltype(&f), r (*)a>::value, \
             "You did not declare " #f " as the Project 2 spec does");  \
         auto p = static_cast<r (*)a>(f);  \
         (void) p;  \
        }

        static_assert(std::is_default_constructible<Sequence>::value,
                "Sequence must be default-constructible.");
        static_assert(std::is_copy_constructible<Sequence>::value,
                "Sequence must be copy-constructible.");
        static_assert(std::is_copy_assignable<Sequence>::value,
                "Sequence must be assignable.");

        void thisFunctionWillNeverBeCalled()
        {
            CHECKTYPE(Sequence, empty,  bool, () const);
            CHECKTYPE(Sequence, size,   int,  () const);
            CHECKTYPE(Sequence, erase,  bool, (int));
            CHECKTYPE(Sequence, remove, int,  (const ItemType&));
            CHECKTYPE(Sequence, get,    bool, (int, ItemType&) const);
            CHECKTYPE(Sequence, set,    bool, (int, const ItemType&));
            CHECKTYPE(Sequence, find,   int,  (const ItemType&) const);
            CHECKTYPE(Sequence, swap,   void, (Sequence&));
            CHECKTYPENONMEMBER(subsequence,   int,  (const Sequence&, const Sequence&));
            CHECKTYPENONMEMBER(concatReverse, void, (const Sequence&, const Sequence&, Sequence&));
            { auto p = static_cast<int (Sequence::*)(int, const ItemType&)>(&Sequence::insert); (void) p; }
            { auto p = static_cast<int (Sequence::*)(const ItemType&)>(&Sequence::insert); (void) p; }
        }

        int main()
        {}
If you add #include <string> to Sequence.h and have the type alias for ItemType specify std::string, then if we make no change to your Sequence.cpp, compile it, and link it to a file containing

        #include "Sequence.h"
        #include <string>
        #include <iostream>
        #include <cassert>
        using namespace std;

        void test()
        {
            Sequence s;
            assert(s.insert(0, "lavash") == 0);
            assert(s.insert(0, "tortilla") == 0);
            assert(s.size() == 2);
            ItemType x = "injera";
            assert(s.get(0, x)  &&  x == "tortilla");
            assert(s.get(1, x)  &&  x == "lavash");
        }

        int main()
        {
            test();
            cout << "Passed all tests" << endl;
        }
the linking must succeed. When the resulting executable is run, it must write Passed all tests to cout and nothing else to cout, and terminate normally.

If we successfully do the above, then make no changes to Sequence.h other than to change the type alias so that ItemType specifies unsigned long, recompile Sequence.cpp, and link it to a file containing

        #include "Sequence.h"
        #include <iostream>
        #include <cassert>
        using namespace std;

        void test()
        {
            Sequence s;
            assert(s.insert(0, 10) == 0);
            assert(s.insert(0, 20) == 0);
            assert(s.size() == 2);
            ItemType x = 999;
            assert(s.get(0, x)  &&  x == 20);
            assert(s.get(1, x)  &&  x == 10);
        }

        int main()
        {
            test();
            cout << "Passed all tests" << endl;
        }
the linking must succeed. When the resulting executable is run, it must write Passed all tests to cout and nothing else to cout, and terminate normally.

During execution, if a client performs actions whose behavior is defined by this spec, your program must not perform any undefined actions, such as dereferencing a null or uninitialized pointer.

Your code in Sequence.h and Sequence.cpp must not read anything from cin and must not write anything whatsoever to cout. If you want to print things out for debugging purposes, write to cerr instead of cout. cerr is the standard error destination; items written to it by default go to the screen. When we test your program, we will cause everything written to cerr to be discarded instead — we will never see that output, so you may leave those debugging output statements in your program if you wish.

Turn it in
By Monday, April 24, there will be a link on the class webpage that will enable you to turn in your source files and report. You will turn in a zip file containing these three files:

Sequence.h. When you turn in this file, the using statement must specify ItemType as a type alias for std::string.

Sequence.cpp. Function implementations should be appropriately commented to guide a reader of the code.

report.docx or report.doc (in Microsoft Word format) or report.txt (an ordinary text file) that contains:

a description of the design of your doubly-linked list implementation. (A couple of sentences will probably suffice, perhaps with a picture of a typical Sequence and an empty Sequence. Is the list circular? Does it have a dummy node? What's in your list nodes?)

pseudocode for non-trivial algorithms (e.g., Sequence::remove and subsequence).

a list of test cases that would thoroughly test the functions. Be sure to indicate the purpose of the tests. For example, here's the beginning of a presentation in the form of code:

The tests were performed on a sequence of strings (i.e., ItemType was a type alias for std::string).

  // default constructor
Sequence s;
  // For an empty sequence:
assert(s.size() == 0);             // test size
assert(s.empty());                 // test empty
assert(s.remove("paratha") == 0);  // nothing to remove 
Even if you do not correctly implement all the functions, you must still list test cases that would test them. Don't lose points by thinking "Well, I didn't implement this function, so I won't bother saying how I would have tested it if I had implemented it."


## SOLUTION
Project 2 Solution
In this solution, the functions with small, fast implementations are inlined. Alternatively, the inline keyword can be removed and the function implementations moved to Sequence.cpp. (inline will be mentioned at some point in class, so don't worry if you've never seen it before.)

// Sequence.h

#ifndef SEQUENCE_INCLUDED
#define SEQUENCE_INCLUDED

  // Later in the course, we'll see that templates provide a much nicer
  // way of enabling us to have Sequences of different types.  For now,
  // we'll use a type alias.

using ItemType = some type;

class Sequence
{
  public:
    Sequence();          // Create an empty sequence (i.e., one whose size() is 0).
    bool empty() const;  // Return true if the sequence is empty, otherwise false.
    int size() const;    // Return the number of items in the sequence.

    int insert(int pos, const ItemType& value);
      // Insert value into the sequence so that it becomes the item at
      // position pos.  The original item at position pos and those that
      // follow it end up at positions one greater than they were at before.
      // Return pos if 0 <= pos <= size() and the value could be
      // inserted.  (It might not be, if the sequence has a fixed capacity,
      // e.g., because it's implemented using a fixed-size array.)  Otherwise,
      // leave the sequence unchanged and return -1.  Notice that
      // if pos is equal to size(), the value is inserted at the end.

    int insert(const ItemType& value);
      // Let p be the smallest integer such that value <= the item at
      // position p in the sequence; if no such item exists (i.e.,
      // value > all items in the sequence), let p be size().  Insert
      // value into the sequence so that it becomes the item in position
      // p.  The original item in position p and those that follow it end
      // up at positions one greater than before.  Return p if the value
      // was actually inserted.  Return -1 if the value was not inserted
      // (perhaps because the sequence has a fixed capacity and is full).

    bool erase(int pos);
      // If 0 <= pos < size(), remove the item at position pos from
      // the sequence (so that all items that followed that item end up at
      // positions one lower than they were at before), and return true.
      // Otherwise, leave the sequence unchanged and return false.

    int remove(const ItemType& value);
      // Erase all items from the sequence that == value.  Return the
      // number of items removed (which will be 0 if no item == value).

    bool get(int pos, ItemType& value) const;
      // If 0 <= pos < size(), copy into value the item at position pos
      // of the sequence and return true.  Otherwise, leave value unchanged
      // and return false.

    bool set(int pos, const ItemType& value);
      // If 0 <= pos < size(), replace the item at position pos of the
      // sequence with value and return true.  Otherwise, leave the sequence
      // unchanged and return false.

    int find(const ItemType& value) const;
      // Let p be the smallest integer such that value == the item at
      // position p in the sequence; if no such item exists, let p be -1.
      // Return p.

    void swap(Sequence& other);
      // Exchange the contents of this sequence with the other one.

      // Housekeeping functions
    ~Sequence();
    Sequence(const Sequence& other);
    Sequence& operator=(const Sequence& rhs);

  private:
      // Representation:
      //   a circular doubly-linked list with a dummy node.
      //   m_head points to the dummy node.
      //   m_head->m_prev->m_next == m_head and m_head->m_next->m_prev == m_head
      //   m_size == 0  iff  m_head->m_next == m_head->m_prev == m_head
      //   if m_size > 0
      //       m_head->next points to the node at position 0.
      //       m_head->prev points to the node at position m_size-1.

    struct Node
    {
        ItemType m_value;
        Node*    m_next;
        Node*    m_prev;
    };

    Node* m_head;
    int   m_size;

    void createEmpty();
      // Create an empty list.  (Should be called only by constructors.)

    void insertBefore(Node* p, const ItemType& value);
      // Insert value in a new Node before Node p, incrementing m_size.

    Node* doErase(Node* p);
      // Remove the Node p, decrementing m_size.  Return the Node that
      // followed p.

    Node* nodeAtPos(int pos) const;
      // Return pointer to Node at position pos.  If pos == m_size, return
      // m_head.  (Will be called only when 0 <= pos <= size().)
};

// Declarations of non-member functions

int subsequence(const Sequence& seq1, const Sequence& seq2);
      // If seq2 is a contiguous subsequence of seq1, return the position in
      // seq1 where that subsequence starts (the earliest such position if more
      // than one).  If not, or if seq2 is empty, return -1.

void concatReverse(const Sequence& seq1, const Sequence& seq2, Sequence& result);
      // Set result to the concatenation of the reverses of seq1 and seq2


// Inline implementations

inline
int Sequence::size() const
{
    return m_size;
}

inline
bool Sequence::empty() const
{
    return size() == 0;
}

#endif // SEQUENCE_INCLUDED

===================================================================

// Sequence.cpp

#include "Sequence.h"

Sequence::Sequence()
{
    createEmpty();
}

Sequence::~Sequence()
{
      // Delete all Nodes from first non-dummy up to but not including
      // the dummy

    while (m_head->m_next != m_head)
        doErase(m_head->m_next);

      // Delete the dummy

    delete m_head;
}

Sequence::Sequence(const Sequence& other)
{
    createEmpty();

      // Copy all non-dummy other Nodes.  (This sets m_size.)
      // Inserting each new node before the dummy node that m_head points to
      // puts the new node at the end of the list.

    for (Node* p = other.m_head->m_next; p != other.m_head; p = p->m_next)
        insertBefore(m_head, p->m_value);
}

Sequence& Sequence::operator=(const Sequence& rhs)
{
    if (this != &rhs)
    {
        Sequence temp(rhs);
        swap(temp);
    }
    return *this;
}

int Sequence::insert(int pos, const ItemType& value)
{
    if (pos < 0  ||  pos > m_size)
        return -1;

    Node* p = nodeAtPos(pos);
    insertBefore(p, value);

    return pos;
}

int Sequence::insert(const ItemType& value)
{
      // Find the Node before which to insert
    Node* p;
    int pos;
    for (p = m_head->m_next, pos = 0; p != m_head  &&
                                value > p->m_value; p = p->m_next, pos++)
        ;

      // Insert the value there
    insertBefore(p, value);
    return pos;
}

bool Sequence::erase(int pos)
{
    if (pos < 0  ||  pos >= m_size)
        return false;

    Node* p = nodeAtPos(pos);
    doErase(p);

    return true;
}

int Sequence::remove(const ItemType& value)
{
    int count = 0;

      // Walk through the list, erasing matching items

    Node* p = m_head->m_next;
    while (p != m_head)
    {
        if (p->m_value == value)
        {
                count++;
                p = doErase(p); // p now points to successor of erased Node
        }
        else
                p = p->m_next;  // p now points to successor of non-erased Node
    }
    return count;
}

bool Sequence::get(int pos, ItemType& value) const
{
    if (pos < 0  ||  pos >= m_size)
        return false;

    Node* p = nodeAtPos(pos);
    value = p->m_value;

    return true;
}

bool Sequence::set(int pos, const ItemType& value)
{
    if (pos < 0  ||  pos >= m_size)
        return false;

    Node* p = nodeAtPos(pos);
    p->m_value = value;

    return true;
}

int Sequence::find(const ItemType& value) const
{
      // Walk through the list, keeping track of position

    int pos = 0;
    Node* p = m_head->m_next;
    for ( ; p != m_head  &&  p->m_value != value; p = p->m_next, pos++)
        ;
    return p == m_head ? -1 : pos;
}

void Sequence::swap(Sequence& other)
{
      // Swap head pointers

    Node* p = other.m_head;
    other.m_head = m_head;
    m_head = p;

      // Swap sizes

    int s = other.m_size;
    other.m_size = m_size;
    m_size = s;
}

void Sequence::createEmpty()
{
    m_size = 0;

      // Create dummy node

    m_head = new Node;
    m_head->m_next = m_head;
    m_head->m_prev = m_head;
}

void Sequence::insertBefore(Node* p, const ItemType& value)
{
      // Create a new node

    Node* newp = new Node;
    newp->m_value = value;

      // Insert new item before p

    newp->m_prev = p->m_prev;
    newp->m_next = p;
    newp->m_prev->m_next = newp;
    newp->m_next->m_prev = newp;

    m_size++;
}

Sequence::Node* Sequence::doErase(Node* p)
{
      // Save pointer to p's successor

    Node* pnext = p->m_next;

      // Unlink p from the list and destroy it

    p->m_prev->m_next = p->m_next;
    p->m_next->m_prev = p->m_prev;
    delete p;

    m_size--;

    return pnext;
}

Sequence::Node* Sequence::nodeAtPos(int pos) const
{
    Node* p;

      // If pos is closer to the head of the list, go forward to find it.
      // Otherwise, start from tail and go backward.

    if (pos <= m_size / 2)  // closer to head
    {
        p = m_head->m_next;
        for (int k = 0; k != pos; k++)
            p = p->m_next;
    }
    else  // closer to tail
    {
        p = m_head;
        for (int k = m_size; k != pos; k--)
            p = p->m_prev;
    }

    return p;
}

int subsequence(const Sequence& seq1, const Sequence& seq2)
{
    if (seq2.empty())
        return -1;

      // Walk through seq1

    for (int pos = 0; pos <= seq1.size() - seq2.size(); pos++)
    {
          // Assume there's a match starting at pos

        bool allMatched = true;

          // Check if all corresponding positions match

        for (int k = 0; k < seq2.size(); k++)
        {
            ItemType v1;
            ItemType v2;
            seq1.get(pos+k, v1);
            seq2.get(k, v2);
            if (v1 != v2)
            {
                allMatched = false;
                break;
            }
        }

          // If we never found a mismatch, we've found the match.

        if (allMatched)
            return pos;
    }

      // If we never found a match, there is none.

    return -1;
}

void concatReverse(const Sequence& seq1, const Sequence& seq2, Sequence& result)
{
      // Guard against the case that result is an alias for seq1 or seq2
      // (i.e., that result is a reference to the same sequence that seq1 or
      // seq2 refers to) by building the answer in a local variable res.  When
      // done, swap res with result; the old value of result (now in res) will
      // be destroyed when res is destroyed.

    Sequence res;

	for (int k = seq1.size() - 1; k >= 0; k--)
	{
		ItemType v;
		seq1.get(k, v);
		res.insert(res.size(), v);
	}

	for (int k = seq2.size() - 1; k >= 0; k--)
	{
		ItemType v;
		seq2.get(k, v);
		res.insert(res.size(), v);
	}

    result.swap(res);
}
