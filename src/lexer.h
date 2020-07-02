#pragma once

#include <fstream>
#include <memory>
#include <string>
#include <stack>
#include <set>
#include "token.h"
#include "AST.h"

class Lexer
{
	public:
		Lexer(std::string file) : file(file) {}
		std::ifstream file;

		void tokenize();
		void createToken(TokenType type, std::string data, size_t line, size_t pos);
		std::vector<Token> TokenList;

		void constructAST();
		NodePtr ParseIdentifier(int* token);
		std::vector<NodePtr> ParseParameterBlock(int* token);
		ASTNode root;

		void logCompileError(Token token);
};
