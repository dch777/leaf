#include "tokenizer.h"
#include <cctype>
#include <iostream>
#include <string>

void tokenize(std::string input[])
{
	size_t start_pos;
	size_t end_pos;
	size_t lineNumber;
	TokenType type = TokenIdentifier;

	bool tokenDefined = false;
	Token currentToken;
	TokenType currentType;

	for(int lineIndex = 0; input[lineIndex] != "\0"; lineIndex++)
	{
		std::string line = input[lineIndex];
		start_pos = 0;
		for (int charIndex = 0; charIndex < line.length(); ++charIndex) {
			char currentChar = line[charIndex];
			if(std::isalpha(currentChar)) {
				currentType = TokenIdentifier;
			} else if(std::isspace(currentChar) != 0) {
				currentType = TokenWhitespace;
			} else if(std::ispunct(currentChar)) {
				currentType = TokenSymbol;
			}

			if(type != currentType || type == TokenSymbol) {
				createToken(type, start_pos, end_pos, lineNumber);
				start_pos = charIndex;
			}
			type = currentType;
			end_pos = charIndex;
			lineNumber = lineIndex;
			tokenDefined = true;
		}
		createToken(type, start_pos, end_pos, lineNumber);
	}
}

void createToken(TokenType type, unsigned long start_pos, unsigned long end_pos, unsigned long line)
{
	Token token{type, start_pos, end_pos, line};
	TokenList.push(token);
}

int main(int argc, char *argv[])
{
	std::string test[] = {"this.; iaklfjs", "is", "a", "test", "\0"};
	tokenize(test);
	return 1;
}
