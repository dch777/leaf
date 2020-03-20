#pragma once

#include <stack>
#include <string>

enum TokenType
{
	TokenIdentifier,
	TokenSymbol,
	TokenIntegerLiteral,
	TokenStringLiteral,
	TokenFloatLiteral,
	TokenWhitespace,
};

struct Token
{
	TokenType type;
	size_t start_pos;
	size_t end_pos;
	size_t line;
};

std::stack<Token> TokenList;
void tokenize(std::string[]);
void createToken(TokenType, unsigned long, unsigned long, unsigned long);
