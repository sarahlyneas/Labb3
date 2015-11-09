 /*
 * expression_tree-test.cc
 */
#include "Expression_Tree.h"
#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
   // Ska inte vara möjligt - Expression_Tree ska vara abstrakt:
   // Expression_Tree* t0{new Expression_Tree};

  //Expression_Tree* t1{ new Plus{ new Integer{9}, new Minus{ new Real{3.14}, new Divide{ new Integer{8}, new Integer{2} }  } }};
/*  Expression_Tree* t2{t1->clone() };
    Expression_Tree* t3{ new Assign{ new Variable{"x"}, new Real{2.3} } };
  Expression_Tree* t4{ t3->clone() };
  Expression_Tree* t5{ new Divide{ new Integer{8}, new Integer{2} } };
  Expression_Tree* t6{ t5->clone() };

  cout << "t1->get_postfix() = " << t1->evaluate() << '\n';
  cout << "t2->get_postfix() = " << t2->get_postfix() << '\n';
  cout << "t3->get_postfix() = " << t3->evaluate() << '\n';
  cout << "t4->get_postfix() = " << t4->get_postfix() << '\n';
  cout << "t5->get_postfix() = " << t5->evaluate() << '\n';
  cout << "t6->get_postfix() = " << t6->evaluate() << '\n';*/

/*  t1->print(cout);
  
      cout << "t1->str() = " << t1->str() << "\n\n";

   cout << "t1->get_postfix() = " << t1->get_postfix() << '\n';

     try
   {
      cout << "t1->evaluate() = " << t1->evaluate() << '\n';
   }
   catch (const exception& e)
   {
      cout << "Undantag fångat: " << e.what() << '\n';
   }

   cout << "t1->get_postfix() = " << t1->get_postfix() << '\n';
   cout << "t1->str() = " << t1->str() << "\n\n";

   Expression_Tree* t2{ t1->clone() };

   try
   {
      cout << "t2->evaluate() = " << t2->evaluate() << '\n';
   }
   catch (const exception& e)
   {
      cout << "Undantag fångat: " << e.what() << '\n';
   }
   cout << "t2->get_postfix() = " << t2->get_postfix() << '\n';
   cout << "t2->str() = " << t2->str() << "\n\n";*/

   return 0;
}
