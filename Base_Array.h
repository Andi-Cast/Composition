//Base_Array.h
//Andi Castillo-Mauricio

//Both Array and Fixed_Array inherit from this class.

#ifndef _BASE_ARRAY_H_
#define _BASE_ARRAY_H_

#include <iostream>

/**
 * @class Base_Array
 *
 * This array's size can not be modified.
*/
template <typename T> 
class Base_Array
{
public:
 //Type definition of the element type
 typedef T type;

 //Default constructor.
 Base_Array(void);

 /**
   * Initializing constructor.
   *
   * @param[in]      length        Initial size
 */
 Base_Array(size_t length);

 /**
   * Initializing constructor.
   *
   * @param[in]      length        Initial size
   * @param[in]      fill          Initial value for each element
 */
 Base_Array(size_t length, T fill);

 /**
   * Copy constructor
   *
   * @param[in]     arr         The source array.
 */
 Base_Array(const Base_Array & arr);

 //Destructor.
 ~Base_Array(void);

 /**
   * Retrieve the current size of the array.
   *
   * @return          The current size
 */
 size_t size(void) const;

 /**
   * Retrieve the maximum size of the array.
   *
   * @return          The maximum size
 */ 
 size_t max_size(void) const;

 /**
   * Get the type T at the specified index. If the index is not
   * within the range of the array, then std::out_of_range exception
   * is thrown.
   *
   * @param[in]       index               Zero-based location
   * @exception       std::out_of_range   Invalid \a index value
 */
 T & operator [] (size_t index);

 /**
   * @overload
   *
   * The returned type T is not modifiable.
 */
 const T & operator [] (size_t index) const;

 /**
   * Get the type T at the specified index. If the \a index is not within
   * the range of the array, then std::out_of_range exception is thrown.
   *
   * @param[in]       index                 Zero-based location
   * @return          Character at \index
   * @exception       std::out_of_range     Invalid index value
 */
 T get(size_t index) const; 

 /** 
   * Set the type T at the specified \a index. If the \a index is not
   * within range of the array, then std::out_of_range exception is 
   * thrown.
   *
   * @param[in]       index                 Zero-based location
   * @param[in]       value                 New value for character
   * @exception       std::out_of_range     Invalid \a index value
 */
 void set(size_t index, T value);

 /**
  * Find the specified element and return index of the first occurence.
  * If type T is not found, return -1.
  * 
  * @param[in]        value       Element to look for  
  * @return           index of first occurence 
 */
 int find(T value) const;

/**
 * This method allows user to specify the start index of search. If start
 * index is out of range throe::out_of_range exception.
 * 
 * @param[in]       val                     Element to look for
 * @param[in]       start                   Zero-based start location
 * @exception       std::out_of_range       Invalid index value  
*/
 int find(T val, size_t start) const;

/**
 * Fills the contents of the array with input value.
 * 
 * @param[in]       element       Fill element
*/
 void fill(T element);

protected:
  ///Pointer to the actual data.
  T * data_;

  ///Current size of the array.
  size_t cur_size_;

  ///Max size of the array. 
  size_t max_size_;
};

#include "Base_Array.cpp"

#endif 
