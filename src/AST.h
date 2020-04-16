#pragma once

#include <memory>
#include <vector>

class ASTNode;
typedef std::unique_ptr<ASTNode> NodePtr;

class ASTNode
{
	public:
		virtual ~ASTNode() {}
		void addChild(NodePtr child) {children.push_back(std::move(child));}
		void setChildren(std::vector<NodePtr> newChildren) {children = std::move(newChildren);}
		std::vector<NodePtr> getChildren() {return children;}
	protected:
		std::vector<NodePtr> children;
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
		VariableExprASTNode(std::string name) : name(name) {}
};

class OperationExprASTNode : public ExprASTNode
{
		char op;
	public:
		OperationExprASTNode(char op, std::unique_ptr<ExprASTNode> RHS, std::unique_ptr<ExprASTNode> LHS) : op(op) {children.push_back(std::move(RHS));children.push_back(std::move(LHS));}
};

class CallExprASTNode : public ExprASTNode
{
		std::string name;
	public:
		CallExprASTNode(std::string name, std::vector<NodePtr> args) : name(name) {setChildren(std::move(args));};
};

class VariableDefASTNode : ASTNode
{
		std::string name;
	public:
		VariableDefASTNode(std::string name, std::unique_ptr<ExprASTNode> value) : name(name) {children.push_back(std::move(value));}
};

class FunctionDefASTNode : ASTNode
{
		std::string name;
	public:
		FunctionDefASTNode(std::string name, std::vector<NodePtr> operations) : name(name) {setChildren(std::move(operations));}
};


