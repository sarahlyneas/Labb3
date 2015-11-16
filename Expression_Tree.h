/*
 * Expression_Tree.h
 */
#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H
#include <iosfwd>
#include <sstream>
#include <string>
#include <stdexcept>
#include <cmath>
#include <iostream>
#include <iomanip>

class expression_tree_error : public std::logic_error
  {

  public:
    explicit expression_tree_error(const std::string& what_arg) noexcept
      : std::logic_error{what_arg} {}

    explicit expression_tree_error(const char* what_arg) noexcept
      : std::logic_error{what_arg} {}

  };




class Expression_Tree
{
public:
  virtual long double      evaluate() const = 0;
  virtual std::string      str() const = 0;
  virtual std::string      get_postfix() const = 0;
  virtual void             print(std::ostream&, int counter=3) const = 0;
  virtual Expression_Tree* clone() const = 0;
  virtual ~Expression_Tree() = default;
};

class Binary_Operator : public Expression_Tree
{
public:

  void print(std::ostream& os, int counter=3) const override;

  std::string get_postfix() const override;

protected:

  ~Binary_Operator() 
  {
    delete leftop;
    delete rightop;
  };
  Binary_Operator (Expression_Tree* number1, Expression_Tree* number2) : leftop{number1}, rightop{number2} {}
  Expression_Tree* leftop{};
  Expression_Tree* rightop{};

  Binary_Operator& operator =(const Binary_Operator&) = delete;
  Binary_Operator(const Binary_Operator&) = delete;
	
};

class Operand : public Expression_Tree
{

public:

  std::string get_postfix() const override;

  void print(std::ostream& os, int counter=3) const override;

protected:
  Operand() noexcept = default;
  ~Operand() = default;

private:
  Operand& operator =(const Operand&) = delete;
  Operand(const Operand&) = delete;

};



class Integer : public Operand
{

public:
  Integer (long long int tal) : number{tal} {}

  long double evaluate() const override;

  std::string str() const override;

  Integer* clone() const override;

protected:
  Integer() noexcept = default;
  ~Integer() = default;

private:
  long long int number{};
  Integer& operator =(const Integer&) = delete;
  Integer(const Integer&) = delete;

};




class Real : public Operand
{
public:
  Real (long double real) : decimal{real} {}

  long double evaluate() const override;

  std::string str() const override;

  Real* clone() const override;

protected:
  Real() noexcept = default;
  ~Real() = default;

private:
  long double decimal{};
  Real& operator =(const Real&) = delete;
  Real(const Real&) = delete;
};

class Variable : public Operand
{

public:
  Variable (std::string ar, long double val=0) : variabel{ar}, value{val} {}

  long double evaluate() const override;

  std::string str() const override;

  long double get_value() const;

  void set_value(long double val);

  Variable* clone() const override;

protected:
  Variable() noexcept = default;
  ~Variable() = default;

private:

  std::string variabel{};
  long double value{};
  Variable& operator =(const Variable&) = delete;
  Variable(const Variable&) = delete;

};

class Assign : public Binary_Operator
{ 
public:
  Assign (Expression_Tree* leftop, Expression_Tree* rightop) : Binary_Operator{leftop, rightop} {}

  long double evaluate() const override;

  std::string str() const override;

  Assign* clone() const override;

private:
  Assign& operator =(const Assign&) = delete;
  Assign(const Assign&) = delete;

};



class Plus : public Binary_Operator
{ 
public:
  Plus (Expression_Tree* leftop, Expression_Tree* rightop) : Binary_Operator{leftop, rightop} {}
  
  long double evaluate() const override;

  std::string str() const override;

  Plus* clone() const override;

private:
  Plus& operator =(const Plus&) = delete;
  Plus(const Plus&) = delete;

};



class Minus : public Binary_Operator 
{
public:
  Minus (Expression_Tree* leftop, Expression_Tree* rightop) : Binary_Operator{leftop, rightop} {}
  
  long double evaluate() const override;

  std::string str() const override;

  Minus* clone() const override;

private:
  Minus& operator =(const Minus&) = delete;
  Minus(const Minus&) = delete;

};



class Times : public Binary_Operator
{
public:
  Times (Expression_Tree* leftop, Expression_Tree* rightop) : Binary_Operator{leftop, rightop} {}
  
  long double evaluate() const override;

  std::string str() const override;

  Times* clone() const override;

private:
  Times& operator =(const Times&) = delete;
  Times(const Times&) = delete;

};



class Divide : public Binary_Operator
{
public:
  Divide (Expression_Tree* leftop, Expression_Tree* rightop) : Binary_Operator{leftop, rightop} {}
  
  long double evaluate() const override;

  std::string str() const override;

  Divide* clone() const override;

private:
  Divide& operator =(const Divide&) = delete;
  Divide(const Divide&) = delete;

};



class Power: public Binary_Operator
{
public:
  Power (Expression_Tree* leftop, Expression_Tree* rightop) : Binary_Operator{leftop, rightop} {}
  
  long double evaluate() const override;

  std::string str() const override;

  Power* clone() const override;

private:
  Power& operator =(const Power&) = delete;
  Power(const Power&) = delete;

};




#endif
