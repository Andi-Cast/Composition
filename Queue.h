#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>
#include <exception>
#include "Array.h"

/**
 * @class Queue
 *
 * Basic implementation of a standard queue class.
 */
template <typename T>
class Queue 
{
public:
 ///Type definition of the type. 
 typedef T type;

/**
 * @class empty_exception
 *
 * Exception thrown to indicate the queue is empty.
*/
 class empty_exception : public std::exception
 {
  public:
    //
    // Initializing constructor.
    //empty_exception(string&)
    //
    empty_exception (const std::string& errorMessage)
    :errorMessage_(errorMessage)
    {
    }

    //Override what() to display string errorMessage_
    virtual const char* what() const noexcept override
    {
	    return errorMessage_.c_str();
    }

   private:
    std::string errorMessage_;

  };

 ///Default constructor
 Queue(void);

 ///Copy constructor
 Queue(const Queue & q);

 ///Destructor 
 ~Queue(void);

 /**
  * Assignment operator
  *
  * @param[in]      rhs           Right-hand side of operator
  * @return         Reference to self
 */
 const Queue & operator = (const Queue & rhs);

 /**
  * Add element to end of queue.
  * 
  * @param[in]        element       Element to add end of queue
 */
 void enqueue(T element); 

 /**
  * Removes element at the front of the queue. If there is no 
  * elements, throw empty_exception
  * 
  * @return       Element at front of queue
  * @exception    empty_exception             There are no elements to dequeue
 */
 T dequeue();

 /**
  * Checks if queue is empty. True if the queue is empty
  * and false if queue is not empty.
  * 
  * @return        true        The queue is empty.
  * @return        false       The queue is not empty.
 */
 bool is_empty(void) const;

 /**
  * Number of elements in the queue.
  * 
  * @return       Size of the queue.
 */
 size_t size(void) const;

 ///Removes all elements in the queue
 void clear(void);

private:
 Array<T> array_;
 int array_size_;
 int queue_size_;
 int front_;
 int back_;
};

//include the source file since template class
#include "Queue.cpp"

#endif