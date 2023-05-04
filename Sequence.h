// Sequence.h

#ifndef SEQUENCE_INCLUDED
#define SEQUENCE_INCLUDED

#include <string>

typedef std::string ItemType;

class Sequence
{
private:
    struct Node
    {
        ItemType value;
        Node *next;
        Node *prev;
    };
    Node *head;
    int m_size;

    // Insert value at position pos, shifting items to the right to make
    // room for it.  Assume pos is valid and there's room.
    void uncheckedInsert(int pos, const ItemType &value);

public:
    // Constructor: create n empty Sequence
    Sequence();

    // Copy Constructor
    Sequence(const Sequence &other);

    // Destructor: delete Sequence
    ~Sequence();

    // Assignment Operator
    Sequence &operator=(const Sequence &rhs);

    // Return true if the sequence is empty, otherwise false.
    bool empty() const;

    // Return the number of items in the sequence.
    int size() const;

    // Insert value into the sequence so that it becomes the item at
    // position pos.  The original item at position pos and those that
    // follow it end up at positions one greater than they were at before.
    // Return pos if 0 <= pos <= size() and the value could be
    // inserted.  (It might not be, if the sequence has a fixed capacity,
    // e.g., because it's implemented using a fixed-size array.)  Otherwise,
    // leave the sequence unchanged and return -1.  Notice that
    // if pos is equal to size(), the value is inserted at the end.
    int insert(int pos, const ItemType &value);

    // Let p be the smallest integer such that value <= the item at
    // position p in the sequence; if no such item exists (i.e.,
    // value > all items in the sequence), let p be size().  Insert
    // value into the sequence so that it becomes the item in position
    // p.  The original item in position p and those that follow it end
    // up at positions one greater than before.  Return p
    int insert(const ItemType &value);

    // If 0 <= pos < size(), remove the item at position pos from
    // the sequence (so that all items that followed that item end up at
    // positions one lower than they were at before), and return true.
    // Otherwise, leave the sequence unchanged and return false.
    bool erase(int pos);

    // Erase all items from the sequence that == value.  Return the
    // number of items removed (which will be 0 if no item == value).
    int remove(const ItemType &value);

    // If 0 <= pos < size(), copy into value the item in position pos
    // of the sequence and return true.  Otherwise, leave value unchanged
    // and return false.
    bool get(int pos, ItemType &value) const;

    // If 0 <= pos < size(), replace the item at position pos of the
    // sequence with value and return true.  Otherwise, leave the sequence
    // unchanged and return false.
    bool set(int pos, const ItemType &value);

    // Let p be the smallest integer such that value == the item at
    // position p in the sequence; if no such item exists, let p be -1.
    // Return p.
    int find(const ItemType &value) const;

    // Exchange the contents of this sequence with the other one.
    void swap(Sequence &other);
};

// Nonmember functions
int subsequence(const Sequence &seq1, const Sequence &seq2);
void concatReverse(const Sequence &seq1, const Sequence &seq2, Sequence &result);

#endif // SEQUENCE_INCLUDED