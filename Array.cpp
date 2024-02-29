#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Array <T>::Array (void)
:Base_Array<T>::Base_Array()
{
}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length)
:Base_Array<T>::Base_Array(length)
{
}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill)
:Base_Array<T>::Base_Array(length, fill)
{
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array)
:Base_Array<T>::Base_Array(array)
{ 
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
	delete [] this->data_;
	this->data_ = nullptr;
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
	//checks for self assignement first
	if (this == &rhs) {
		return *this;
	}
	else {
		if(rhs.max_size_ > this->max_size_) {
			//creates new array to hold new size
			delete [] this->data_;
			T * copyData_ = new T[rhs.max_size_];

			for(int i = 0; i < rhs.max_size_; i++) {
				copyData_[i] = rhs.data_[i];
			}

			this->data_ = copyData_;
			this->cur_size_ = rhs.cur_size_;
			this->max_size_ = rhs.max_size_;
		}
		else {
			//copies over data if there is enough spaces and updates cur_size_
			for(int j = 0; j < rhs.max_size_; j++) {
				this->data_[j] = rhs.data_[j];
			}
			this->cur_size_ = rhs.cur_size_;
		}
	}
	return *this;
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
	//if new_size is smaller than the max_size_,
	//the cur_size_ is updated to the new_size
	if(new_size <= this->max_size_) {
		this->cur_size_ = new_size;
	}
	else {
		//if new_size is bigger than the max size, a new
		//array is created to hold the new_size
		T * newBiggerData_ = new T[new_size];

		for(int i = 0; i < this->cur_size_; i++) {
			newBiggerData_[i] = this->data_[i];
		}

		delete [] this->data_;
		this->data_ = newBiggerData_;
		this->cur_size_ = new_size;
		this->max_size_ = new_size;
	}
}

//
// operator ==
//
template <typename T>
bool Array <T>::operator == (const Array & rhs) const
{
	//checks for self assignment first
	if(this == &rhs) {
		return true;
	}	
	//compares data members before data in the array 
	if(this->cur_size_ != rhs.cur_size_ || this->max_size_ != rhs.max_size_) {
		return false;
	}
	//finally compares array data to see if they match
	for(int i = 0; i < this->cur_size_; i++) {
		if(this->data_[i] != rhs.data_[i]) {
			return false;
		}
	}
	return true;
}

//
// operator !=
//
template <typename T>
bool Array <T>::operator != (const Array & rhs) const
{
	return !(*this == rhs);
}