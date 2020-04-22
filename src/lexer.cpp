#include <cctype>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include "lexer.h"
#include "AST.h"

void Lexer::tokenize()
{
	std::ifstream file("test"); 
	size_t start_pos;
	size_t end_pos;
	size_t lineNumber = 0;
	TokenType type;

	bool tokenDefined = false;
	TokenType currentType = TokenIdentifier;

	std::string line;
	while (getline(file, line))
	{
		start_pos = 0;
		for (int charIndex = 0; charIndex <= line.length(); charIndex++) 
		{
			type = currentType;
			end_pos = charIndex;
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
				createToken(type, line.substr(start_pos, end_pos - start_pos), lineNumber, start_pos);
				start_pos = charIndex;
			}
		}
		lineNumber++;
	}
}

void Lexer::createToken(TokenType type, std::string data, size_t line, size_t pos)
{
	TokenList.push_back({type, data, line, pos});
}

void Lexer::logCompileError(Token token)
{
	std::cout << "Syntax Error at " << token.line << "," << token.pos << ": " << token.data << std::endl;
}

void Lexer::constructAST()
{
	Token currentToken;
	std::unique_ptr<ASTNode> node;
	size_t block = 0;
	for(int i = 0; i < TokenList.size(); ++i) 
	{
		currentToken = TokenList[i];
		switch (currentToken.type) 
		{
			case TokenNumberLiteral:
				node = std::make_unique<NumberExprASTNode>(stod(currentToken.data));
				break;

			default:
				logCompileError(currentToken);
		}
	}
}

int main(int argc, char *argv[])
{
	Lexer lex("test");
	lex.tokenize();
	lex.constructAST();
	return 0;
}
