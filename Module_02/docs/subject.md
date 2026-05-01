# Chapter V

# Exercise 00: My First Class in

# Orthodox Canonical Form

```
Exercise: 00
```
```
My First Class in Orthodox Canonical Form
Directory: ex 00 /
Files to Submit: Makefile, main.cpp, Fixed.{h, hpp}, Fixed.cpp
Forbidden: None
```
```
You think you know integers and floating-point numbers. How cute.
```
```
Please read this 3 pages article (1, 2, 3) to discover that you don’t. Go on, read it.
```
Until today, every number you used in your code was basically either an integer or a
floating-point number, or any of their variants (short, char, long, double, and so forth).
After reading the article above, it’s safe to assume that integers and floating-point num-
bers have opposite characteristics.

But today, things will change. You are going to discover a new and awesome number
type: **fixed-point numbers**! Forever missing from the scalar types of most languages,
fixed-point numbers offer a valuable balance between performance, accuracy, range and
precision. That explains why fixed-point numbers are particularly applicable to computer
graphics, sound processing or scientific programming, just to name a few.

As C++ lacks fixed-point numbers, you’re going to add them. This article from
Berkeley is a good start. If you have no idea what Berkeley University is, read this
section of its Wikipedia page.


C++ - Module 02

```
Ad-hoc polymorphism, operator overloading
and the Orthodox Canonical class form
```
```
Create a class in Orthodox Canonical Form that represents a fixed-point number:
```
- Private members:

```
◦ An integer to store the fixed-point number value.
◦ A static constant integer to store the number of fractional bits. Its value
will always be the integer literal 8.
```
- Public members:

```
◦ A default constructor that initializes the fixed-point number value to 0.
◦ A copy constructor.
◦ A copy assignment operator overload.
◦ A destructor.
◦ A member function int getRawBits( void ) const;
that returns the raw value of the fixed-point value.
◦ A member function void setRawBits( int const raw );
that sets the raw value of the fixed-point number.
```
```
Running this code:
#include <iostream>
int main( void ) {
Fixed a;
Fixed b( a );
Fixed c;
c = b;
std::cout << a.getRawBits() << std::endl;
std::cout << b.getRawBits() << std::endl;
std::cout << c.getRawBits() << std::endl;
return 0;
}
```
```
Should output something similar to:
$> ./a.out
Default constructor called
Copy constructor called
Copy assignment operator called // <-- This line may be missing depending on your implementation
getRawBits member function called
Default constructor called
Copy assignment operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called
$>
```

# Chapter VI

# Exercise 01: Towards a more useful

# fixed-point number class

```
Exercise
```
```
Towards a more useful fixed-point number class
Directory: ex 01 /
Files to Submit: Makefile, main.cpp, Fixed.{h, hpp}, Fixed.cpp
Authorized: roundf (from <cmath>)
```
The previous exercise was a good start, but our class is pretty useless. It can only
represent the value 0.0.

```
Add the following public constructors and public member functions to your class:
```
- A constructor that takes a **constant integer** as a parameter.
    It converts it to the corresponding fixed-point value. The fractional bits value
    should be initialized to 8, like in exercise 00.
- A constructor that takes a **constant floating-point number** as a parameter.
    It converts it to the corresponding fixed-point value. The fractional bits value
    should be initialized to 8, like in exercise 00.
- A member function float toFloat( void ) const;
    that converts the fixed-point value to a floating-point value.
- A member function int toInt( void ) const;
    that converts the fixed-point value to an integer value.

```
And add the following function to the Fixed class files:
```
- An overload of the insertion («) operator that inserts a floating-point representation
    of the fixed-point number into the output stream object passed as a parameter.


C++ - Module 02

```
Ad-hoc polymorphism, operator overloading
and the Orthodox Canonical class form
```
```
Running this code:
```
```
#include <iostream>
int main( void ) {
Fixed a;
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );
a = Fixed( 1234.4321f );
std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;
return 0;
}
```
```
Should output something similar to:
$> ./a.out
Default constructor called
Int constructor called
Float constructor called
Copy constructor called
Copy assignment operator called
Float constructor called
Copy assignment operator called
Destructor called
a is 1234.
b is 10
c is 42.
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
Destructor called
Destructor called
Destructor called
Destructor called
$>
```

# Chapter VII

# Exercise 02: Now we’re talking

```
Exercise
```
```
Now we’re talking
Directory: ex 02 /
Files to Submit: Makefile, main.cpp, Fixed.{h, hpp}, Fixed.cpp
Authorized: roundf (from <cmath>)
```
```
Add public member functions to your class to overload the following operators:
```
- The 6 comparison operators: >, <, >=, <=, ==, and !=.
- The 4 arithmetic operators: +, -, *, and /.
- The 4 increment/decrement (pre-increment and post-increment, pre-decrement and
    post-decrement) operators, which will increase or decrease the fixed-point value by
    the smallest representable _ε_ , such that 1 + _ε >_ 1.

```
Add these four public overloaded member functions to your class:
```
- A static member function min that takes two references to fixed-point numbers as
    parameters, and returns a reference to the smallest one.
- A static member function min that takes two references to **constant** fixed-point
    numbers as parameters, and returns a reference to the smallest one.
- A static member function max that takes two references to fixed-point numbers as
    parameters, and returns a reference to the greatest one.
- A static member function max that takes two references to **constant** fixed-point
    numbers as parameters, and returns a reference to the greatest one.


C++ - Module 02

```
Ad-hoc polymorphism, operator overloading
and the Orthodox Canonical class form
```
```
It’s up to you to test every feature of your class. However, running the code below:
```
```
#include <iostream>
int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}
```
Should output something like (for greater readability, the constructor/destructor mes-
sages are removed in the example below):

```
$> ./a.out
0
0.
0.
0.
0.
10.
10.
$>
```
```
If you ever do a division by 0, it is acceptable that the program
crashes
```

# Chapter VIII

# Exercise 03: BSP

```
Exercise
```
```
BSP
Directory: ex 03 /
Files to Submit: Makefile, main.cpp, Fixed.{h, hpp}, Fixed.cpp,
Point.{h, hpp}, Point.cpp, bsp.cpp
Authorized: roundf (from <cmath>)
```
```
Now that you have a functional Fixed class, it would be nice to use it.
```
Implement a function that indicates whether a point is inside a triangle or not. Very
useful, isn’t it?

```
BSP stands for Binary Space Partitioning. You are welcome. :)
```
```
You can pass this module without completing exercise 03.
```

C++ - Module 02

```
Ad-hoc polymorphism, operator overloading
and the Orthodox Canonical class form
```
Let’s start by creating the **Point** class in Orthodox Canonical Form that represents
a 2D point:

- Private members:

```
◦ A Fixed const attribute x.
◦ A Fixed const attribute y.
◦ Anything else useful.
```
- Public members:

```
◦ A default constructor that initializes x and y to 0.
◦ A constructor that takes two constant floating-point numbers as parameters.
It initializes x and y with those parameters.
◦ A copy constructor.
◦ A copy assignment operator overload.
◦ A destructor.
◦ Anything else useful.
```
```
To conclude, implement the following function in the appropriate file:
```
```
bool bsp( Point const a, Point const b, Point const c, Point const point);
```
- a, b, c: The vertices of our beloved triangle.
- point: The point to check.
- Returns: True if the point is inside the triangle. False otherwise.
    Thus, if the point is a vertex or on an edge, it will return False.

```
Implement and turn in your own tests to ensure that your class behaves as expected.
```

# Chapter IX

# Submission and Peer-Evaluation

Turn in your assignment in your Git repository as usual. Only the work inside your repos-
itory will be evaluated during the defense. Don’t hesitate to double-check the names of
your folders and files to ensure they are correct.

During the evaluation, a brief **modification of the project** may occasionally be re-
quested. This could involve a minor behavior change, a few lines of code to write or
rewrite, or an easy-to-add feature.

While this step may **not be applicable to every project** , you must be prepared for it
if it is mentioned in the evaluation guidelines.

This step is meant to verify your actual understanding of a specific part of the project.
The modification can be performed in any development environment you choose (e.g.,
your usual setup), and it should be feasible within a few minutes — unless a specific
timeframe is defined as part of the evaluation.
You can, for example, be asked to make a small update to a function or script, modify a
display, or adjust a data structure to store new information, etc.

The details (scope, target, etc.) will be specified in the **evaluation guidelines** and may
vary from one evaluation to another for the same project.
