//Base_Array.cpp
//Andi Castillo-Mauricio

#include <stdexcept> //for std::out_of_bounds exception

//
//Base_Array
//
template <typename T>
Base_Array <T>:: Base_Array(void)
:data_(new T[10]),
 cur_size_(10),
 max_size_(10)
{
}

//
//Base_Array(size_t)
//
template <typename T>
Base_Array <T>:: Base_Array(size_t length)
:data_(new T[length]),
 cur_size_ (length),
 max_size_(length)
{
}

//
//Base_Array(size_t, T)
//
template <typename T>
Base_Array <T>:: Base_Array(size_t length, T fill)
:data_(new T[length]),
 cur_size_(length),
 max_size_(length)
{
	for(int i = 0; i < cur_size_; i++) {
		data_[i] = fill;
	}
}

//
//Base_Array(const Array &)
//
template <typename T>
Base_Array <T>::Base_Array(const Base_Array & arr)
:data_(new T[arr.max_size_]),
 cur_size_(arr.cur_size_),
 max_size_(arr.max_size_)
{
	for(int i = 0; i < cur_size_; i++) {
		data_[i] = arr.data_[i];
	}
}

//
//~Base_Array
//
template <typename T>
Base_Array <T>:: ~Base_Array(void)
{
	delete [] data_;
	data_ = nullptr;
}

//
//size
//
template <typename T>
size_t Base_Array <T>::size(void) const
{
	return cur_size_;
}

//
//max_size
//
template <typename T> 
size_t Base_Array <T>::max_size(void) const
{
	return max_size_;
}

//
//operator []
//
template <typename T>
T & Base_Array <T>::operator [] (size_t index)
{	
	//throws out_of_range() if index not in range
	if(index < 0 || index >= cur_size_) {
		throw std::out_of_range("Not in range");
	}
	return data_[index];
}

//
//operator []
//
template <typename T>
const T & Base_Array <T>::operator [] (size_t index) const
{
	//throws out_of_range() if index not in range
	if(index < 0 || index >= cur_size_) {
                throw std::out_of_range("Not in range");
        }
        return data_[index];
}

//
//get
//
template <typename T>
T Base_Array <T>::get(size_t index) const
{
	//throws out_of_range() if index not in range
	if(index < 0 || index >= cur_size_) {
		throw std::out_of_range("Not in range");
	}
	return data_[index];
}

//
//set
//
template <typename T>
void Base_Array <T>::set(size_t index, T value)
{
	//throws out_of_range() if index not in range
	if(index < 0 || index >= cur_size_) {
		throw std::out_of_range("Not in range");
	}
	else {
		data_[index] = value;
	}
}

//
//find(T)
//
template <typename T> 
int Base_Array <T>::find(T value) const
{
	for(int i =0; i < cur_size_; i++) {
		if(data_[i] == value) {
			return i;
		}
	}
	return -1;
}

//
//find(T, size_t)
//
template <typename T>
int Base_Array <T>::find(T val, size_t start) const
{
	if(start < 0 || start >= cur_size_) {
		throw std::out_of_range("Not in range");
	}
	else {
		for(int i = start; i < cur_size_; i++) {
			if (data_[i] == val) {
				return i;
			}
		}
		return -1;
	}
}

//
//fill(T)
//
template <typename T>
void Base_Array <T>::fill(T value)
{
	for(int i = 0; i < cur_size_; i++) {
		data_[i] = value;
	}
}