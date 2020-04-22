#pragma once

#include <stack>
#include <string>

enum TokenType
{
	TokenIdentifier,
	TokenNumberLiteral,
	TokenQuote,
	TokenWhitespace,
	TokenTerminateExpression,
	TokenOpenExpressionBlock,
	TokenOpenParameterBlock,
	TokenCloseExpressionBlock,
	TokenCloseParameterBlock,
	TokenSymbol,
};

struct Token
{
	TokenType type;
	std::string data;
	size_t line;
	size_t pos;
};
