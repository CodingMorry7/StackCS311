//INSTRUCTION
//Look for ** to complete this program 
//The output should match my hw1stackDemo.out 

//=========================================================
//HW#: HW1P1 stack
//Your name: Chris Morikawa
//Complier:  g++
//File type: client program
//===========================================================

using namespace std;

#include <iostream>
#include <string>
#include "stack.h"

//Purpose of the program: To have the user enter in a postfix experssion and output an mathatical result.
//Algorithm: The user will enter in an experssion (example: 34+). Within the while loop, it will grab the first element of the expression and change it to a character. 
// If the item is a number it will change it to a integer and push it into the interger stack. If the program finds an operator, then it will pop out two numbers, do the
//calulation and push the result back into the stack. The program will catch errors such as: if there is too few, too many operands,and invald symbols or letters. After going through
// the while loop, It will test to see if there is only one element left in the stack, if there is more than one element it will throw an imcomplete exression error.  
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  int result; //result of the two pop numbers
  
  while (expression[i] != '\0')
    {
      try
	{
	  item = expression[i];  // current char
	  
	  //2.  if it is an operand (number), 
	  //    push it (you might get Overflow exception)
	if ((item == '0') || (item == '1') || (item == '2') || (item == '3') || (item == '4') || (item == '5') || (item == '6') || (item == '7') || (item == '8') || (item == '9'))
	{  
	   postfixstack.push(int(item)-48);
	   postfixstack.displayAll();
	} 
	  
	  //3.  else if it is an operator,
	  //    pop the two operands (you might get Underflow exception), and
	  //	apply the operator to the two operands, and
	  //    push the result.
	  else if ( (item == '+') || (item == '-') || (item == '*'))
	    {
	      postfixstack.pop(box1);
	      postfixstack.pop(box2);
	      //cases for different operators follow:
	      if (item == '-')
		{
		  result = box2-box1;
		  postfixstack.push(result);
		}
	      if (item == '+')
		{
		  result = box2+box1;
		  postfixstack.push(result);
		}
	      if (item == '*')
		{
		  result = box2*box1;
		  postfixstack.push(result);
		}
	    }
	  else throw "invalid item";
	} // this closes try
      
      // Catch exceptions and report problems and quit the program now. 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow) 
	{
	  cerr << "Expression is too long." << endl;
	  exit(1);
	}
      catch (stack::Underflow) // for too few operands
	{
	  cerr << "You do not have enough operands." << endl;
	  exit(1);
	}
      catch (char const* errorcode) // for invalid item
	{
	  cerr << "Sorry! This " << errorcode << " is invalid";
	  exit(1);
	}
      // go back to the loop after incrementing i
     i++; 
    }// end of while
  
  // After the loop successfully completes: 
  // The result will be at the top of the stack. Pop it and show it.
	try 
	{
		postfixstack.pop(box1);
		postfixstack.displayAll();
		if(!postfixstack.isEmpty())
		  throw stack::Overflow();
		postfixstack.push(box1);
	}
	// If anything is left on the stack, an incomplete expression was found.
  	// Inform the user.
	catch (stack::Overflow)
	{
		cerr << "Incomplete Expression.";
		exit(1);
	}
	cout << "Your result is: ";
	postfixstack.displayAll();
	return 0;
}// end of the program
