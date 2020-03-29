#pragma once

#include <memory>
#include <vector>

class ASTNode
{
	public:
		virtual ~ASTNode() {}
		void addChild(std::unique_ptr<ASTNode> child) {children.push_back(std::move(child));}
		void overrideChildren(std::vector<std::unique_ptr<ASTNode>> newChildren) {children = std::move(newChildren);}
	protected:
		std::vector<std::unique_ptr<ASTNode>> children;
};

class ExprASTNode : public ASTNode
{
	public:
		virtual ~ExprASTNode() {}
};

class NumberExprASTNode : public ExprASTNode
{
		double value;
	public:
		NumberExprASTNode(double value) : value(value) {}
};

class StringExprASTNode : public ExprASTNode
{
		std::string value;
	public:
		StringExprASTNode(std::string value) : value(value) {};
};

class VariableExprASTNode : public ExprASTNode
{
		std::string name;
	public:
		VariableExprASTNode(std::string name, std::unique_ptr<ExprASTNode> value) : name(name) {children.push_back(std::move(value));}
};

class OperationExprASTNode : public ExprASTNode
{
		char op;
	public:
		OperationExprASTNode(char op, std::unique_ptr<ExprASTNode> RHS, std::unique_ptr<ExprASTNode> LHS) : op(op) {children.push_back(std::move(RHS));children.push_back(std::move(LHS));}
};

class CallExprASTNode : public ExprASTNode
{
		std::string func;
	public:
		CallExprASTNode(std::string func, std::vector<std::unique_ptr<ASTNode>> args) : func(func) {overrideChildren(std::move(args));};
};

class ExprBlockASTNode : ASTNode {};

class VariableDeclASTNode : ASTNode
{
		std::string name;
	public:

};

class VariableDefASTNode : ASTNode
{
	public:
		VariableDefASTNode(std::unique_ptr<ExprASTNode> value) {children.push_back(std::move(value));}
};

class PrototypeASTNode : ASTNode
{
		std::string name;
	public:

};
