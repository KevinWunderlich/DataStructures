

/***** Program using a stack to convert from the Base 10 rep of an integer to base 2.....D. Pinto...CS 501 Spring 2018........****/

#include <iostream>
using namespace std;

int const maxstack = 51;
class stack_type            // declaration of class//
{
public:
    void clear_stack();    //member functions//
    bool empty_stack(); //of class stack_type//
    bool full_stack();
    void push(int numb);
    void pop(int& numb);
    void charpush(char hex);
    void charpop(char& hex);
    
    int stack[maxstack];
    int top;
};
//---------------------------------------------------------------------
int main()
{
    stack_type remainder_stack;
    int i,n,number[11],remainder;
    remainder_stack.clear_stack();
    
    
    for(i=1;i<=10;i++)
    {
        cout << "Enter positive integer to convert to Octal and Hexadecimal:\n\n";
        cin >> number[i];
        n = number[i];
       
        while (number[i] != 0)
        {
            remainder = number[i] % 8;
            remainder_stack.push(remainder);
            number[i] /= 8;
        }
        
        cout << "Octal representation of "<< n
        << " is ";
        while (!remainder_stack.empty_stack())
        {
            remainder_stack.pop(remainder);
            cout << remainder;
        }
        
        number[i] = n;
        remainder_stack.clear_stack();
        while (number[i] != 0)
        {
            remainder = number[i] % 16;
            remainder_stack.push(remainder);
            number[i] /= 16;
        }
        
        cout << "Hex representation of "<< n
        << " is ";
        while (!remainder_stack.empty_stack())
        {
            remainder_stack.pop(remainder);
            cout << remainder;
        }
        
        cout << "\n";
    }
    
}


//----------------------------------------------------------------------
void stack_type::clear_stack()
{
    top = 0;
}
//----------------------------------------------------------------------
bool stack_type::empty_stack()
{
    if (top==0)
        return true;
    else
        return false;
}
//----------------------------------------------------------------------
bool stack_type::full_stack()
{
    if (top==maxstack-1)
        return true;
    else
        return false;
}
//----------------------------------------------------------------------
void stack_type::push(int numb)
{
    top = top + 1;
    stack[top]=numb;
}
//----------------------------------------------------------------------
void stack_type::pop(int& numb)
{
    numb = stack[top];
    top = top - 1;
}



