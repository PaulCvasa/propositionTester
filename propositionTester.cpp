#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main()
{
   cout << "~~~~~~~~~~NOTATIONS FOR OPERATORS~~~~~~~~~~\n\n" << "\t- ~ NEGATION\n" << "\t& ~ CONJUNCTION and\n" << "\t| ~ CONJUNCTION or\n" << "\t> ~ IMPLICATION\n" << "\t= ~ EQUIVALENCE\n" << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
   cout << "\n!!! USE ONLY CAPITAL LETTERS, PARANTHESIS AND THE SPECIFIED OPERATORS SO THIS PROGRAM CAN WORK !!! \n\n";
   char prop[101];
   cout << "Proposition: ";
   cin >> prop;
   int brackets_open = 0, brackets_closed = 0, op = 0, t = 1;
   for (int i = 0; i <= strlen(prop)-1; i++)
   {
	   if (strchr("-&|>=", prop[i]))
		   op++;
	   if (prop[i] == '(')
		   brackets_open++;
	   if (prop[i] == ')')
		   brackets_closed++;
	   if (prop[i] == ')' && (prop[i+1] >= 'A' and prop[i+1] <= 'Z'))
	   {
		   cout << "This is not a proposition because after ')' you can't have the " << prop[i + 1] << " variable without an operator between.\n";
		   t = 0;
	   }
	   if (prop[i] == '(' && prop[i + 1] == ')')
	   {
		   cout << "This is not a proposition because of an empty set of brackets.\n";
		   t = 0;
	   }
	   if ((prop[i] >= 'A' and prop[i] <= 'Z') && (prop[i + 1] >= 'A' and prop[i + 1] <= 'Z'))
	   {
		   cout << "This is not a proposition because variable " << prop[i] << " is followed by variable " << prop[i + 1] << ", and you can't have two consecutive propositional variables without an operator between.\n";
		   t = 0;
	   }
	   if (strchr("-&|>=", prop[i]) && strchr("-&|>=", prop[i + 1]))
	   {
		   cout << "This is not a proposition because operator " << prop[i] << " is followed by operator " << prop[i + 1] << " and you can't have two consecutive porpositional operators.\n";
		   t = 0;
	   }
	   if ((prop[i] >= 'A' and prop[i] <= 'Z') && (prop[i + 1] == '-' || prop[i+1]=='('))
	   {
		   cout << "This is not a proposition because variable " << prop[i] << " is followed by " << prop[i + 1] << ", and you can't have '-' (non) operator or '(' after a propositional variable.\n";
		   t = 0;
	   }
	   if (prop[i] == '(' and strchr("&|>=", prop[i + 1]))
	   {
		   cout << "This is not a proposition because " << prop[i] << " is followed by " << prop[i + 1] << " and you can't have an operator after an opened bracket.";
		   t = 0;
	   }
   }

   if (brackets_closed != brackets_open)
   {
	   cout << "This is not a proposition because the number of opened brackets is not equal to the closed ones.\n";
	   t = 0;
   }

   if (op != (brackets_closed + brackets_open) / 2)
   {
	   cout << "This is not a proposition because the number of operators exceeds the number of brackets used divided by 2.";
	   t = 0;
   }
   
   cout << "\nOperators: " << op << "\n";
   cout << "\nOpened brackets: " << brackets_open << " Brackets closed: " << brackets_closed;

   if (t)
	   cout << "This is a proposition.\n";
   return 0;
}
// ex: (P=(Q&R))
// (a) (((PQ)|S)=T) ~ This is not a proposition because variable P is followed by variable Q, and you can't have two consecutive propositional variables without an operator between.
// (b) ((P>(Q&(S>T)))) ~ This is a proposition.
// (c) (-(B(-Q))&R) ~ This is not a proposition because variable B is followed by (, and you can't have '-' (non) operator or '(' after a propositional variable.
// (d) (P&((-Q)&(-(-(Q=(-R)))))) ~ This is a proposition.
// (e) ((P|Q)>-(P|Q))&(P|(-(-Q))) ~ This is not a proposition because operator > is followed by operator - and you can't have two consecutive porpositional operators.