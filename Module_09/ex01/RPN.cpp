#include "RPN.hpp"

#include <sstream>
#include <stack>
#include <stdexcept>

static inline
void s_fetch_operands(long &rhs, long &lhs, std::stack<long> &operands)
{
	if (operands.size() < 2)
		throw std::runtime_error("missing operand");

	rhs = operands.top();
	operands.pop();
	lhs = operands.top();
	operands.pop();
}

static
void s_operate(char operation, std::stack<long> &operands)
{
	long lhs, rhs, result;

	if (operation == '+')
	{
		s_fetch_operands(rhs, lhs, operands);
		result = (lhs + rhs);
	}
	else if (operation == '-')
	{
		s_fetch_operands(rhs, lhs, operands);
		result = (lhs - rhs);
	}
	else if (operation == '*')
	{
		s_fetch_operands(rhs, lhs, operands);
		result = (lhs * rhs);
	}
	else if (operation == '/')
	{
		s_fetch_operands(rhs, lhs, operands);
		if (rhs == 0)
			throw std::runtime_error("division by zero");
		result =  (lhs / rhs);
	}
	else
		throw std::runtime_error("invalid token");
	operands.push(result);
}

long	evaluate_rpn(const std::string &expression)
{
	std::istringstream	input(expression);
	std::stack<long>	operands;
	std::string		token;

	while (input >> token)
	{
		if (token.length() != 1)
			throw std::runtime_error("invalid token");
		if (token[0] >= '0' && token[0] <= '9')
			operands.push(token[0] - '0');
		else
			s_operate(token[0], operands);
	}
	if (operands.size() != 1)
		throw std::runtime_error("invalid expression");
	return (operands.top());
}
