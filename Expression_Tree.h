/*
 * Expression_Tree.h
 */
#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H
#include <iosfwd>
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

  ~Binary_Operator() = default;
  Binary_Operator (Expression_Tree* number1, Expression_Tree* number2) : leftop{number1}, rightop{number2} {}
  Expression_Tree* leftop{};
  Expression_Tree* rightop{};

	
};

class Operand : public Expression_Tree
{

public:

  std::string get_postfix() const override;

  void print(std::ostream& os, int counter=3) const override;

protected:
  Operand() noexcept = default;
  ~Operand() = default;

};



class Integer : public Operand
{

 public:
  Integer (long long int tal) : number{tal} {}

  long double evaluate() const override;

  std::string str() const override;

  Expression_Tree* clone() const override;

protected:
   Integer() noexcept = default;
  ~Integer() = default;

 private:
   long long int number{};
};




class Real : public Operand
{
 public:
  Real (long double real) : decimal{real} {}

  long double evaluate() const override;

  std::string str() const override;

  Expression_Tree* clone() const override;

protected:
  Real() noexcept = default;
  ~Real() = default;

 private:
    long double decimal{};
};

class Variable : public Operand
{

 public:
  Variable (std::string ar, long double val=0) : variabel{ar}, value{val} {}

  long double evaluate() const override;

  std::string str() const override;

  long double get_value() const;

  void set_value(long double val);

  Expression_Tree* clone() const override;

protected:
  Variable() noexcept = default;
  ~Variable() = default;

private:

  std::string variabel{};
  long double value{};
};

class Assign : public Binary_Operator
{ 
public:
  Assign (Expression_Tree* leftop, Expression_Tree* rightop) : Binary_Operator{leftop, rightop} {}

  long double evaluate() const override;

  std::string str() const override;

  Expression_Tree* clone() const override;

protected:
  ~Assign() 
  {
    delete leftop;
    delete rightop;
  };

};



class Plus : public Binary_Operator
{ 
 public:
  Plus (Expression_Tree* leftop, Expression_Tree* rightop) : Binary_Operator{leftop, rightop} {}
  
  long double evaluate() const override;

  std::string str() const override;

  Expression_Tree* clone() const override;

protected:
  ~Plus() 
  {
    delete leftop;
    delete rightop;
  };
};



class Minus : public Binary_Operator 
{
 public:
  Minus (Expression_Tree* leftop, Expression_Tree* rightop) : Binary_Operator{leftop, rightop} {}
  
  long double evaluate() const override;

  std::string str() const override;

  Expression_Tree* clone() const override;

protected:
  ~Minus() 
  {
    delete leftop;
    delete rightop;
  };
};



class Times : public Binary_Operator
{
 public:
  Times (Expression_Tree* leftop, Expression_Tree* rightop) : Binary_Operator{leftop, rightop} {}
  
  long double evaluate() const override;

  std::string str() const override;

  Expression_Tree* clone() const override;

protected:
  ~Times() 
  {
    delete leftop;
    delete rightop;
  };
};



class Divide : public Binary_Operator
{
 public:
  Divide (Expression_Tree* leftop, Expression_Tree* rightop) : Binary_Operator{leftop, rightop} {}
  
  long double evaluate() const override;

  std::string str() const override;

  Expression_Tree* clone() const override;

protected:
  ~Divide() 
  {
    delete leftop;
    delete rightop;
  };
};



class Power: public Binary_Operator
{
 public:
  Power (Expression_Tree* leftop, Expression_Tree* rightop) : Binary_Operator{leftop, rightop} {}
  
  long double evaluate() const override;

  std::string str() const override;

  Expression_Tree* clone() const override;

protected:
  ~Power()
  {
    delete leftop;
    delete rightop;
  };
};




#endif
