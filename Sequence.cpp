// Sequence.cpp
#include "Sequence.h"

// FUNCTION
// Insert value at position pos, shifting items to the right to make
// room for it.  Assume pos is valid and there's room.
void Sequence::uncheckedInsert(int pos, const ItemType &value)
{
    // pointer to iterate through list
    Node *new_node_ptr = new Node;
    Node *current = head->next;

    for (int i = 0; i != pos; ++i)
    { // iterate current until reaches appropriate element
        current = current->next;
    }

    // take care of all pointers
    current->prev->next = new_node_ptr;
    new_node_ptr->next = current;
    new_node_ptr->prev = current->prev;
    current->prev = new_node_ptr;

    // initialize value
    new_node_ptr->value = value;

    ++m_size; // increment size
}

// CONSTRUCTORS, DESTRUCTOR, ASSIGNMENT OPERATOR
// Constructor: create n empty Sequence
Sequence::Sequence()
{
    m_size = 0;
    // circular linked list
    head = new Node;
    head->next = head;
    head->prev = head;
}

// Copy Constructor
Sequence::Sequence(const Sequence &other)
{
    m_size = 0;

    // Make circular
    head = new Node;
    head->next = head;
    head->prev = head;

    Node *current = other.head->next;

    for (int i = 0; i < other.size(); ++i)
    {
        // ++m_size; // increment size

        this->insert(i, current->value); // insert value

        current = current->next; // increment current
    }
}

// Destructor: delete Sequence
Sequence::~Sequence()
{
    Node *current = head->next;
    while (current != head)
    { // delete all nodes other than head
        Node *next = current->next;
        delete current;
        current = next;
    }

    delete head;
}

// Assignment Operator
Sequence &Sequence::operator=(const Sequence &rhs)
{
    if (this != &rhs)
    { // copy and swap
        Sequence temp(rhs);
        swap(temp);
    }
    return *this;
}

// MEMBER FUNCTIONS
// Return true if the sequence is empty, otherwise false.
bool Sequence::empty() const
{
    return (size() == 0);
}

// Return the number of items in the sequence.
int Sequence::size() const
{
    return m_size;
}

// Insert value into the sequence so that it becomes the item at
// position pos.  The original item at position pos and those that
// follow it end up at positions one greater than they were at before.
// Return pos if 0 <= pos <= size() and the value could be
// inserted.  (It might not be, if the sequence has a fixed capacity,
// e.g., because it's implemented using a fixed-size array.)  Otherwise,
// leave the sequence unchanged and return -1.  Notice that
// if pos is equal to size(), the value is inserted at the end.
int Sequence::insert(int pos, const ItemType &value)
{
    if (pos < 0 || pos > size())
    { // not valid
        return -1;
    }
    else
    { // valid
        uncheckedInsert(pos, value);
        return pos;
    }
}

// Let p be the smallest integer such that value <= the item at
// position p in the sequence; if no such item exists (i.e.,
// value > all items in the sequence), let p be size().  Insert
// value into the sequence so that it becomes the item in position
// p.  The original item in position p and those that follow it end
// up at positions one greater than before.  Return p
int Sequence::insert(const ItemType &value)
{
    int pos = 0;
    for (Node *current = head->next; pos < size() && value > current->value; current = current->next)
    { // find the first instance of a value's position (p) where that value <= that positions value
        ++pos;
    }
    uncheckedInsert(pos, value);
    return pos;
}

// If 0 <= pos < size(), remove the item at position pos from
// the sequence (so that all items that followed that item end up at
// positions one lower than they were at before), and return true.
// Otherwise, leave the sequence unchanged and return false.
bool Sequence::erase(int pos)
{
    if (pos < 0 || pos >= size())
    { // not valid
        return false;
    }
    else
    {
        Node *current = head->next; // first element
        for (int i = 0; i < pos; ++i)
        { // iterate node until at target one
            current = current->next;
        }

        // take care of pointers
        current->prev->next = current->next;
        current->next->prev = current->prev;

        delete current;

        m_size--;
        return true;
    }
}

// Erase all items from the sequence that == value.  Return the
// number of items removed (which will be 0 if no item == value).
int Sequence::remove(const ItemType &value)
{
    int pos = 0;     // index of element
    int num_rem = 0; // # of elements removed
    for (Node *current = head->next; current != head; current = current->next)
    { // iterate through list
        if (current->value == value)
        {
            current = current->prev; // set back 1 to cancel out the incrementation
            erase(pos);
            --pos; // set back 1 to cancel out the incrementation

            ++num_rem; // increment count
        }
        ++pos; // go to next element
    }

    return num_rem; // # of elements removed
}

// If 0 <= pos < size(), copy into value the item in position pos
// of the sequence and return true.  Otherwise, leave value unchanged
// and return false.
bool Sequence::get(int pos, ItemType &value) const
{
    if (pos < 0 || pos >= size())
    { // not valid
        return false;
    }
    else
    {
        // get current to correct element
        Node *current = head->next;
        for (int i = 0; i < pos; ++i)
        { // go through until current is at target node
            current = current->next;
        }

        value = current->value; // set value
        return true;
    }
}

// If 0 <= pos < size(), replace the item at position pos of the
// sequence with value and return true.  Otherwise, leave the sequence
// unchanged and return false.
bool Sequence::set(int pos, const ItemType &value)
{
    if (pos < 0 || pos >= size())
    { // not valid
        return false;
    }
    else
    {
        // get current to correct element
        Node *current = head->next;
        for (int i = 0; i < pos; ++i)
        { // go through until current is at target node
            current = current->next;
        }

        current->value = value; // set current->value
        return true;
    }
}

// Let p be the smallest integer such that value == the item at
// position p in the sequence; if no such item exists, let p be -1.
// Return p.
int Sequence::find(const ItemType &value) const
{
    int pos = 0;
    for (Node *current = head->next; pos < size(); current = current->next)
    { // find the first instance of a value's position (p) where that value <= that positions value
        if (value == current->value)
        { // if found a matching value
            return pos;
        }
        ++pos; // increment
    }
    return -1; // no item found
}

// Exchange the contents of this sequence with the other one.
void Sequence::swap(Sequence &other)
{
    // swap head pointers
    Node *temp = other.head;
    other.head = this->head;
    this->head = temp;

    // swap sizes
    int tempSize = m_size;
    m_size = other.m_size;
    other.m_size = tempSize;
}

// NONMEMBER FUNCTIONS
// If there exists at least one k such that seq1k == seq20 and seq1k+1 == seq21 and ... and seq1k+n == seq2n,
// and k+n < seq1.size(), then this function returns the smallest such k. (In other words, if seq2 is a
// consecutive subsequence of seq1, the function returns the earliest place in seq1 where that subsequence starts.)
// If no such k exists or if seq2 is empty, the function returns -1.
int subsequence(const Sequence &seq1, const Sequence &seq2)
{
    // seq sizes
    int seq2Size = seq2.size();
    int seq1Size = seq1.size();

    ItemType seq2First; // first item in seq2
    seq2.get(0, seq2First);

    // position of seq2first element in seq1
    int posInseq1 = seq1.find(seq2First);

    if ((seq1Size < seq2Size) || (seq2Size == 0) || (posInseq1 == -1))
    { // not valid
        return -1;
    }

    bool found = false; // subsequent sequence not found

    for (int index1 = 0; index1 < seq1Size; ++index1)
    { // iterate through seq1

        ItemType seq1Element;
        seq1.get(index1, seq1Element);

        if (seq1Element == seq2First)
        { // match found!
            for (int index2 = 0; index2 < seq2Size; ++index2)
            { // check if all seq2 is in seq1
                ItemType seq1temp;
                seq1.get((index1 + index2), seq1temp);

                ItemType seq2temp;
                seq2.get(index2, seq2temp);

                if ((index2 == seq2Size - 1) && (seq1temp == seq2temp))
                {                 // all of seq2 found in seq1
                    found = true; // found subsequent
                    break;
                }
                if (seq1temp != seq2temp)
                {                                   // go back to
                    index1 = (index1 + index2 - 1); // make index1 value go ahead and check unchecked values
                    break;                          // keep checking seq 1 for values in outer for loop
                }
            }
            if (found)
            { // FOUND!!
                return index1;
            }
        }
    }

    return -1; // no subsequent sequence exists
}
void concatReverse(const Sequence &seq1, const Sequence &seq2, Sequence &result)
{
    Sequence temp; // to take care if result is not an empty Sequence

    // sizes
    int seq1Size = seq1.size();
    int seq2Size = seq2.size();

    // Add seq2 elements if seq2 isnt empty
    if (seq2Size)
    { // seq2 not empty
        for (int j = 0; j < seq2Size; ++j)
        {
            ItemType seq2Element;
            seq2.get(j, seq2Element);

            temp.insert(0, seq2Element); // insert element into result
        }
    }

    // Add seq1 elements if seq1 isnt empty
    if (seq1Size)
    { // seq1 not empty
        for (int i = 0; i < seq1Size; ++i)
        {
            ItemType seq1Element;
            seq1.get(i, seq1Element);

            temp.insert(0, seq1Element); // insert element into result
        }
    }

    result.swap(temp); // swap everything from temp into result
}