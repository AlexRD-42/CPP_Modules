# Chapter IV
# Exercise 00: Aaaaand... OPEN!

```
Exercise: 00
```
```
Aaaaand... OPEN!
Directory: ex 00 /
Files to Submit: Makefile, main.cpp, ClapTrap.{h, hpp}, ClapTrap.cpp
Forbidden: None
```
```
First, you have to implement a class! How original!
```
It will be called **ClapTrap** and will have the following private attributes initialized
to the values specified in brackets:

- Name, which is passed as a parameter to the constructor
- Hit points (10), representing the health of the ClapTrap
- Energy points (10)
- Attack damage (0)

Add the following public member functions so that the ClapTrap behaves more real-
istically:

- void attack(const std::string& target);
- void takeDamage(unsigned int amount);
- void beRepaired(unsigned int amount);

When ClapTrap attacks, it causes its target to lose <attack damage> hit points.
When ClapTrap repairs itself, it regains <amount> hit points. Attacking and repairing
each cost 1 energy point. Of course, ClapTrap can’t do anything if it has no hit points or
energy points left. However, since these exercises serve as an introduction, the ClapTrap
instances should not interact directly with one another, and the parameters will not refer
to another instance of ClapTrap.


C++ - Module 03 Inheritance

In all of these member functions, you need to print a message to describe what hap-
pens. For example, the attack() function may display something like (of course, without
the angle brackets):

```
ClapTrap <name> attacks <target>, causing <damage> points of damage!
```
The constructors and destructor must also display a message, so your peer-evaluators
can easily see that they have been called.

```
Implement and turn in your own tests to ensure your code works as expected.
```

# Chapter V

# Exercise 01: Serena, my love!

```
Exercise: 01
```
```
Serena, my love!
Directory: ex 01 /
Files to Submit: Files from the previous exercise + ScavTrap.{h, hpp},
ScavTrap.cpp
Forbidden: None
```
Because you can never have enough ClapTraps, you will now create a derived robot.
It will be named **ScavTrap** and will inherit the constructors and destructor from Clap-
Trap. However, its constructors, destructor, and attack() will print different messages.
After all, ClapTraps are aware of their individuality.

Note that proper construction/destruction chaining must be shown in your tests.
When a ScavTrap is created, the program starts by constructing a ClapTrap. Destruc-
tion occurs in reverse order. Why?

**ScavTrap** will use the attributes of ClapTrap (update ClapTrap accordingly) and
must initialize them to:

- Name, which is passed as a parameter to the constructor
- Hit points (100), representing the health of the ClapTrap
- Energy points (50)
- Attack damage (20)
    ScavTrap will also have its own special ability:
       void guardGate();

This member function will display a message indicating that ScavTrap is now in Gate
keeper mode.

```
Don’t forget to add more tests to your program.
```

# Chapter VI

# Exercise 02: Repetitive work

```
Exercise: 02
```
```
Repetitive work
Directory: ex 02 /
Files to Submit: Files from previous exercises + FragTrap.{h, hpp},
FragTrap.cpp
Forbidden: None
```
```
Making ClapTraps is probably starting to get on your nerves.
```
Now, implement a **FragTrap** class that inherits from ClapTrap. It is very similar to
ScavTrap. However, its construction and destruction messages must be different. Proper
construction/destruction chaining must be shown in your tests. When a FragTrap is cre-
ated, the program starts by constructing a ClapTrap. Destruction occurs in reverse order.

```
Same goes for the attributes, but with different values this time:
```
- Name, which is passed as a parameter to the constructor
- Hit points (100), representing the health of the ClapTrap
- Energy points (100)
- Attack damage (30)

```
FragTrap has a special ability too:
```
```
void highFivesGuys(void);
```
This member function displays a positive high-fives request on the standard output.

```
Again, add more tests to your program.
```

# Chapter VII

# Exercise 03: Now it’s weird!

```
Exercise: 03
```
```
Now it’s weird!
Directory: ex 03 /
Files to Submit: Files from previous exercises + DiamondTrap.{h, hpp},
DiamondTrap.cpp
Forbidden: None
```
In this exercise, you will create a monster: a ClapTrap that’s half FragTrap, half Scav-
Trap. It will be named **DiamondTrap** , and it will inherit from both FragTrap AND
ScavTrap. This is so risky!

The DiamondTrap class will have a private attribute named name. This attribute must
have exactly the same variable name as in the ClapTrap base class (without referring to
the robot’s name).
To be clearer, here are two examples:
If ClapTrap’s variable is name, give the DiamondTrap’s variable the name name.
If ClapTrap’s variable is _name, give the DiamondTrap’s variable the name _name.

```
Its attributes and member functions will be inherited from its parent classes:
```
- Name, which is passed as a parameter to a constructor
- ClapTrap::name (parameter of the constructor + "_clap_name" suffix)
- Hit points (FragTrap)
- Energy points (ScavTrap)
- Attack damage (FragTrap)
- attack() (ScavTrap)


C++ - Module 03 Inheritance

In addition to the special functions from both parent classes, DiamondTrap will have
its own special ability:

```
void whoAmI();
```
This member function will display both its name and its ClapTrap name.

Of course, the ClapTrap instance of DiamondTrap will be created once, and only once.
Yes, there’s a trick.

```
Again, add more tests to your program.
```
```
Do you know the -Wshadow and -Wno-shadow compiler flags?
```
```
You can pass this module without completing exercise 03.
```

# Chapter VIII

# Submission and Peer-Evaluation

Submit your assignment in your Git repository as usual. Only the work within your repos-
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
