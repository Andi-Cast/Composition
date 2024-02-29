//
// Stack
//
template <typename T>
Stack <T>::Stack (void)
:array_(Array<T>(10)),
 size_(10),
 top_(-1)
{

}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
:array_(Array<T>(stack.size_)),
 size_(stack.size_),
 top_(stack.top_)
{

}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
	//check to see if there is space
	if(top_ != size_ - 1) {
		top_++;
		array_.set(top_, element);
	}
	//increase size if there is not enough
	else {
		array_.resize(size_ + 10);
		size_ = size_ + 10;
		top_++;
		array_.set(top_,element);
	}
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
	//check to see if there are any elements in the stack
	//if not exception will be thrown
	if(top_ == -1) {
		throw empty_exception("Stack is empty.");
	}
	else {
		std::cout<<array_.get(top_)<<std::endl;
		top_--;
	}
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	if(this == &rhs) {
		return *this;
	}
	else {
		array_ = rhs.array_;
		size_ = rhs.size_;
		top_ = rhs.top_;
	}
	return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
	top_ = -1;
}
