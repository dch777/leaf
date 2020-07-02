#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <memory>
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
	TokenType currentType;

	std::string line;
	while (getline(file, line))
	{
		start_pos = 0;
		for (size_t charIndex = 0; charIndex <= line.length(); charIndex++) 
		{
			type = currentType;
			end_pos = charIndex;
			tokenDefined = true;
			
			char currentChar = line[charIndex];
			if(std::isblank(currentChar)) {
				currentType = TokenWhitespace;
			} else if(std::isalpha(currentChar) || (std::isdigit(currentChar) && currentType == TokenIdentifier)) {
				currentType = TokenIdentifier;
				std::cout << "test" << std::endl;
			} else if(std::isdigit(currentChar)) {
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

			if(type != currentType && currentType == TokenWhitespace) {
				createToken(type, line.substr(start_pos, end_pos - start_pos), lineNumber, start_pos);
				start_pos = charIndex + 1;
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
	std::cout << "\tToken type is " << token.type << std::endl;
}

void Lexer::constructAST()
{
	Token currentToken;
	std::unique_ptr<ASTNode> node;
	std::unique_ptr<ASTNode> parent;
	size_t block = 0;
	for(size_t i = 0; i < TokenList.size(); ++i) 
	{
		currentToken = TokenList[i];
		switch(currentToken.type) 
		{
			case TokenNumberLiteral:
				break;

			case TokenIdentifier:
				std::cout << currentToken.data << std::endl;
				break;

			default:
				logCompileError(currentToken);
		}
	}
}

std::unique_ptr<ASTNode> Lexer::ParseIdentifier(int* token)
{
	Token currentToken = TokenList[*token];
	if(currentToken.data == "def")
	{
		
	} else if(TokenList[*token + 1].type == TokenOpenParameterBlock) {
		
	} else {
		return std::make_unique<VariableExprASTNode>(currentToken.data);
	}
}

std::vector<NodePtr> Lexer::ParseParameterBlock(int* token)
{
	
}

int main(int argc, char *argv[])
{
	Lexer lex("test");
	lex.tokenize();
	lex.constructAST();
	return 0;
}
