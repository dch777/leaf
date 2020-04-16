#include "lexer.h"
#include "AST.h"
#include <cctype>
#include <iostream>
#include <string>

void Lexer::tokenize(std::string input[])
{
	size_t start_pos;
	size_t end_pos;
	size_t lineNumber;
	TokenType type;

	bool tokenDefined = false;
	Token currentToken;
	TokenType currentType = TokenIdentifier;

	for(int lineIndex = 0; input[lineIndex] != "\0"; lineIndex++)
	{
		std::string line = input[lineIndex];
		start_pos = 0;
		for (int charIndex = 0; charIndex <= line.length(); charIndex++) 
		{
			type = currentType;
			end_pos = charIndex;
			lineNumber = lineIndex;
			tokenDefined = true;
			
			char currentChar = line[charIndex];
			if(std::isalpha(currentChar)) {
				currentType = TokenIdentifier;
			} else if(std::isspace(currentChar) != 0) {
				currentType = TokenWhitespace;
			} else if(std::isdigit(currentChar) || (currentType == TokenNumberLiteral && currentChar == '.')) {
				currentType = TokenNumberLiteral;
			} else if(currentChar == '"') {
				currentType = TokenQuote;
			} else if(currentChar == ';') {
				currentType = TokenTerminateExpression;
			} else if(currentChar == '{') {
				currentType = TokenOpenExpressionBlock;
			} else if(currentChar == '}') {
				currentType = TokenCloseExpressionBlock;
			} else if(currentChar == '(') {
				currentType = TokenOpenParameterBlock;
			} else if(currentChar == ')') {
				currentType = TokenCloseParameterBlock;
			} else {
				currentType = TokenSymbol;
			}

			if(type != currentType) {
				currentToken = createToken(type, line.substr(start_pos, end_pos - start_pos));
				start_pos = charIndex;
			}
		}
		currentToken = createToken(type, line.substr(start_pos, end_pos - start_pos));
		TokenList.push(currentToken);
	}
}

Token createToken(TokenType type, std::string data)
{
	Token tok{type, data};
	return tok;
}

void Lexer::constructAST()
{
	
}

int main(int argc, char *argv[])
{
	ASTNode ast;
	return 0;
}
