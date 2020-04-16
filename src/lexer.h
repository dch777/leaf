#pragma once

#include <memory>
#include <string>
#include <stack>
#include "token.h"
#include "AST.h"

class Lexer
{
	public:
		Lexer(std::string file) {}

		void tokenize(std::string[]);
		std::stack<Token> TokenList;

		void constructAST();
		std::unique_ptr<ASTNode> root;
};
