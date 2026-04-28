#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

static void printSeparator(const std::string& title)
{
	std::cout << std::endl;
	std::cout << "========== " << title << " ==========" << std::endl;
}

static void testAbstractAnimalNote(void)
{
	printSeparator("abstract Animal contract");
	std::cout << "Animal has a pure virtual makeSound() and cannot be instantiated." << std::endl;
	std::cout << "Uncommenting 'Animal animal;' in main.cpp would make compilation fail." << std::endl;
	/* Animal animal; */
}

static void testSubjectSnippet(void)
{
	const Animal* j;
	const Animal* i;

	printSeparator("subject snippet: delete as Animal");
	j = new Dog();
	i = new Cat();
	std::cout << "j type: " << j->getType() << std::endl;
	std::cout << "i type: " << i->getType() << std::endl;
	j->makeSound();
	i->makeSound();
	delete j;
	delete i;
}

static void testAnimalArray(void)
{
	Animal* animals[10];
	int i;

	printSeparator("array of Animal pointers: half Dogs, half Cats");
	i = 0;
	while (i < 10)
	{
		if (i < 5)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		i++;
	}
	printSeparator("sounds from array through Animal pointers");
	i = 0;
	while (i < 10)
	{
		std::cout << "animals[" << i << "] type: " << animals[i]->getType() << " -> ";
		animals[i]->makeSound();
		i++;
	}
	printSeparator("delete array through Animal pointers");
	i = 0;
	while (i < 10)
	{
		delete animals[i];
		i++;
	}
}

static void testDogCopyConstructorDeepCopy(void)
{
	Dog original;

	printSeparator("Dog copy constructor deep copy");
	original.setIdea(0, "Chase the postman");
	original.setIdea(1, "Guard the house");
	Dog copy(original);
	std::cout << "original brain address: " << original.getBrainAddress() << std::endl;
	std::cout << "copy brain address:     " << copy.getBrainAddress() << std::endl;
	std::cout << "copy idea before original changes: " << copy.getIdea(0) << std::endl;
	original.setIdea(0, "Eat all the kibble");
	std::cout << "original idea after change: " << original.getIdea(0) << std::endl;
	std::cout << "copy idea after original change: " << copy.getIdea(0) << std::endl;
}

static void testCatCopyConstructorDeepCopy(void)
{
	Cat original;

	printSeparator("Cat copy constructor deep copy");
	original.setIdea(0, "Knock cup from table");
	original.setIdea(99, "Sleep in a cardboard box");
	Cat copy(original);
	std::cout << "original brain address: " << original.getBrainAddress() << std::endl;
	std::cout << "copy brain address:     " << copy.getBrainAddress() << std::endl;
	std::cout << "copy idea before original changes: " << copy.getIdea(99) << std::endl;
	original.setIdea(99, "Demand food immediately");
	std::cout << "original idea after change: " << original.getIdea(99) << std::endl;
	std::cout << "copy idea after original change: " << copy.getIdea(99) << std::endl;
}

static void testAssignmentOperatorDeepCopy(void)
{
	Dog dogA;
	Dog dogB;
	Cat catA;
	Cat catB;

	printSeparator("assignment operator deep copy");
	dogA.setIdea(2, "Original dog assignment idea");
	catA.setIdea(2, "Original cat assignment idea");
	dogB = dogA;
	catB = catA;
	std::cout << "dogA brain address: " << dogA.getBrainAddress() << std::endl;
	std::cout << "dogB brain address: " << dogB.getBrainAddress() << std::endl;
	std::cout << "catA brain address: " << catA.getBrainAddress() << std::endl;
	std::cout << "catB brain address: " << catB.getBrainAddress() << std::endl;
	dogA.setIdea(2, "Changed dog assignment idea");
	catA.setIdea(2, "Changed cat assignment idea");
	std::cout << "dogB idea remains: " << dogB.getIdea(2) << std::endl;
	std::cout << "catB idea remains: " << catB.getIdea(2) << std::endl;
}

static void testSelfAssignmentAndBounds(void)
{
	Dog dog;
	Cat cat;
	Dog* dogPtr;
	Cat* catPtr;

	printSeparator("self-assignment and Brain bounds");
	dogPtr = &dog;
	catPtr = &cat;
	dog.setIdea(0, "Keep this dog idea");
	cat.setIdea(0, "Keep this cat idea");
	dog = *dogPtr;
	cat = *catPtr;
	std::cout << "dog idea after self-assignment: " << dog.getIdea(0) << std::endl;
	std::cout << "cat idea after self-assignment: " << cat.getIdea(0) << std::endl;
	dog.setIdea(-1, "invalid negative index");
	cat.setIdea(100, "invalid high index");
	std::cout << "dog invalid read: '" << dog.getIdea(-1) << "'" << std::endl;
	std::cout << "cat invalid read: '" << cat.getIdea(100) << "'" << std::endl;
}

int main(void)
{
	testAbstractAnimalNote();
	testSubjectSnippet();
	testAnimalArray();
	testDogCopyConstructorDeepCopy();
	testCatCopyConstructorDeepCopy();
	testAssignmentOperatorDeepCopy();
	testSelfAssignmentAndBounds();
	return (0);
}
