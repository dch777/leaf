#pragma once

#include <string>
#include <stack>
#include "token.h"

class Lexer
{
	public:
		void tokenize(std::string[]);
		std::stack<Token> TokenList;

		
};
