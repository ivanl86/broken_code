#ifndef SET_H
#define SET_H

/** The Set interface 
 *  DO NOT change this file unless instructed to by the Professor */

template<typename T>
struct Set
{
    /** Inserts an item into the set. Returns true if successful or false otherwise.
     *  Param item: the item to be inserted
     *  return: true if successful or false otherwise. */ 
    virtual bool insert(const T& item) = 0;

    /** Removes an item from the Set.
     * Param item: the item to removed
     * return: true if an item was removed and false otherwise */ 
    virtual bool erase(const T& item) = 0;
    
    /** retrieves a an item
     *  Param item: the item to retrieved
     *  return: a constant pointer to an item if it exists and nullptr otherwise */
    virtual const T* find(const T& item) = 0;

    /** Checks for membership
     * Param item: the item to searched for
     * return: true of the item is a member of the set and false otherwise. */
    virtual bool contains(const T& item) = 0;
};

#endif  /* SET_H */