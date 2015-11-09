/*
 * Expression_Tree.cc
 */
#include "Expression_Tree.h"

using namespace std;

void Binary_Operator::print(std::ostream& os, int counter) const 
 {
   rightop->print(os, ++counter);
    os << std::setw(counter) << " /" << '\n';
    os << std::setw(counter - 1) << str() << '\n';
    os << std::setw(counter) << " \\" << '\n';
    leftop->print(os, counter);
  }

std::string Binary_Operator::get_postfix() const 
  {
    return leftop->get_postfix() + " " + rightop->get_postfix() + " " + str();
  }

std::string Operand::get_postfix()  const 
  {
    return str();
  }

void Operand::print(std::ostream& os, int counter) const
  {
    os << std::setw(++counter) << str() << '\n';
  }
  

long double Integer::evaluate() const 
  {
    return number;    
  }

std::string Integer::str() const 
{
  return std::to_string (number);
}

Expression_Tree* Integer::clone() const 
{
  return new Integer{number};
}

long double Real::evaluate() const 
{
  return decimal;    
}

std::string Real::str() const 
{
  return std::to_string (decimal);
}
  

Expression_Tree* Real::clone() const 
{
  return new Real{decimal};
}

long double Variable::evaluate() const 
{
  return value;  
}

std::string Variable::str() const 
{
  return variabel;
}
   
long double Variable::get_value() const
{
  return value;
}

void Variable::set_value(long double val)
{
  value=val;
}

Expression_Tree* Variable::clone() const
{
  return new Variable{variabel, value};
}

long double Assign::evaluate() const 
{
  long double op;
  op = rightop->evaluate();

  Variable* point;
  point = dynamic_cast<Variable*>(leftop); 
  point->set_value(op); 

  return op;

}

std::string Assign::str() const 
{
  return "=";
}
 

Expression_Tree* Assign::clone() const 
{
  Expression_Tree* newleft = leftop->clone();
  Expression_Tree* newright = rightop->clone();
  return new Assign{newleft, newright};
}

long double Plus::evaluate() const
{
  long double op;
  op = leftop->evaluate() + rightop->evaluate();
  return op;
}

std::string Plus::str() const 
{
  return "+";
}


Expression_Tree* Plus::clone() const 
{
  Expression_Tree* newleft = leftop->clone();
  Expression_Tree* newright = rightop->clone();
  return new Plus{newleft, newright};
}

long double Minus::evaluate() const 
{
  long double op;
  op = leftop->evaluate() - rightop->evaluate();
  return op;
}

std::string Minus::str() const 
{
  return "-";
}


Expression_Tree* Minus::clone() const
{
  Expression_Tree* newleft = leftop->clone();
  Expression_Tree* newright = rightop->clone();
  return new Minus{newleft, newright};
}

long double Times::evaluate() const
  {
  long double op;
  op = leftop->evaluate() * rightop->evaluate();
  return op;
}

std::string Times::str() const
{
  return "*";
}

Expression_Tree* Times::clone() const 
{
  Expression_Tree* newleft = leftop->clone();
  Expression_Tree* newright = rightop->clone();
  return new Times{newleft, newright};
}

long double Divide::evaluate() const 
{
  long double op;
  if (rightop->evaluate() == 0)
    {
      throw expression_tree_error {"do not divide by zero"};
    }
  else
    {
      op = leftop->evaluate() / rightop->evaluate();
      return op;
    }
}

std::string Divide::str() const 
{
  return "/";
}

Expression_Tree* Divide::clone() const 
{
  Expression_Tree* newleft = leftop->clone();
  Expression_Tree* newright = rightop->clone();
  return new Divide{newleft, newright};
}

long double Power::evaluate() const 
{
  long double op;
  op = pow(leftop->evaluate(), rightop->evaluate());
  return op;
}

std::string Power::str() const
{
  return "^";
}

Expression_Tree* Power::clone() const
{
  Expression_Tree* newleft = leftop->clone();
  Expression_Tree* newright = rightop->clone();
  return new Power{newleft, newright};
}
