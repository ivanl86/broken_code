// who: Ivan Leung ileung2
// what: Bcuket Container
// why: Lab 5a
// when: May/10/2022

// include guard
#ifndef bucket_H
#define bucket_H

// includes (only include these headers from the std library)
#include <stddef.h>
#include <stdexcept>

#define DEFAULT_SIZE 4
#define SCALING_FACTOR 2

/*  The bucket class */
class Bucket
{
private:
	//const size_t DEFAULT_SIZE{4};  // must be initialized
	size_t itemCount{};  // the number of items stored in the bucket
    double *items; // The storage facility for the added items
    size_t currSize;
	
	/** Resizes the bucket and copies old values to new resized "items" array
        destroys old items arry when done */
	void resize();
	
public: 
	/** Constructors: there are two constructors. One takes in the initial 
	    size of the bucket and the other sets it to a default of size 10. 
		The parameterless constructor must call the parametrized constructor with the default value */
	Bucket();
	
	/** Constructor sets the initial size of the bucket
		@param: initial size of the bucket */
	Bucket(const size_t);

    ~Bucket();
	
    /** Gets the current number of entries in this bucket.
        @return The integer number of entries currently in the bucket. */
    size_t count() const;

    /** Sees whether this bucket is empty.
        @return True if the bucket is empty, or false if not. */
    bool isEmpty() const;

    /** Adds a new item to this bucket.
        @param item The object to be added as a new item. 
		       resizes the bucket if the bucket is full. */
    void add(const double item);

    /** Removes one unspecified item from this bucket, if possible.
        @return the removed item or
        @throws runtime_error if the bucket was empty. */
    double remove();

    /** Removes *one* occurrence of a given item from this bucket.
        @param item The item to be removed. This item will not be altered.
        @return True if the removal was successful, or false otherwise. */
    bool remove(const double item);

    /** Removes all entries from this bucket. sets the used elements to NULL */
    void clear();

    /** Counts the number of times a given item appears in this bucket.
        @param item The item to be counted. This item will not be altered.
        @return The number of times item appears in the bucket. */
    size_t getFrequency(const double item) const;

    /** Tests whether this bucket contains a given item.
        @param item The item to locate. This item will not be altered.
        @return True if the bucket contains item, or false otherwise */
    bool contains(const double item) const;
};

#endif // end include guard