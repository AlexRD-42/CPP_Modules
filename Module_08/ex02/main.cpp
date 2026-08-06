#include "MutantStack.hpp"
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	if (std::find(mstack.begin(), mstack.end(), 737) != mstack.end())
		std::cout << "Found 737" << std::endl;

	const MutantStack<int> copy(mstack);
	MutantStack<int>::const_iterator cit = copy.begin();
	std::cout << "Const copy:";
	while (cit != copy.end())
	{
		std::cout << " " << *cit;
		++cit;
	}
	std::cout << std::endl;

	std::stack<int> stackCopy(mstack);
	std::cout << "Stack copy size: " << stackCopy.size() << std::endl;

	MutantStack<std::string> words;
	words.push("templates");
	words.push("work");
	for (MutantStack<std::string>::iterator word = words.begin(); word != words.end(); ++word)
		std::cout << *word << std::endl;
	return (0);
}
