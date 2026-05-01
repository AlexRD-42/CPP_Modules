# Proper C++
ClassName() = default;
	Calls the default constructor

ClassName() = delete;
	Forbids this constructor


# 42 C++
ClassName() {};
	Omitting the constructor would be the alternative

private: ClassName();
	Forbids this constructor

# To Remember:
virtual ~ClassName();
	Makes it so derived classes call Derived > Base destructors
	Without this, calling delete on a base class type would only invoke the base destructor

virtual int method() const = 0;
	Pure virtual function
	Makes it so derived classes have to override method() in order to instantiate the class
	Turns it into an abstract class, can no longer be instantiated
	int is just a placeholder, can be any type