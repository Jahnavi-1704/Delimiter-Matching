/*
 * delimiters.cpp
 *
 *  Created on: 03-Oct-2019
 *      Author: Hemant Shah
 */
#include <iostream>
#include <cassert>
#include "project_1.hpp"
int main();
void print_program();
bool does_delimiter_match(char del);
bool do_delimiters_nest();

int main()
{
    print_program();
    std::cout<<does_delimiter_match('(')<<std::endl;
    std::cout<<does_delimiter_match('[')<<std::endl;
    std::cout<<does_delimiter_match('{')<<std::endl;
    std::cout<<do_delimiters_nest()<<std::endl;
	return 0;
}
void print_program()
{
	char ch;
	ece150::start_reading_file();
	while(!ece150::at_eof())
	{
		ch=ece150::get_next_character();
		std::cout<<ch;
	}
}
bool does_delimiter_match(char del)
{
   int i=0,n=0,m=1;
   char z;
   ece150::start_reading_file();
   while(!ece150::at_eof())
   {
      char ch=ece150::get_next_character();
      if(del=='{')
      {
		  if(ch=='{')
			   i++;
		  else if(ch=='}')
		  {
			   if(i==0)
			   {
				   std::cout<<"Unmatched }"<<std::endl;
				   m=0;
				   n=1;
			   }
			   else
					i--;
			   if(i>0){}
			   //std::cout<<"Unmatched }"<<std::endl;
		  }
      }
	  else if(del=='(')
	  {
		 if(ch=='(')
				 i++;
	     else if(ch==')')
		 {
	    	 if(i==0)
			 {
				 std::cout<<"Unmatched )"<<std::endl;
				 m=0;
				 n=1;
			 }
			 else
				 i--;
			 if(i>0){}
					   //std::cout<<"Unmatched )"<<std::endl;
		  }
	   }
       else if(del=='[')
       {
	      if(ch=='[')
	   		 i++;
	      else if(ch==']')
	      {
	   		  if(i==0)
	   		  {
	   			  std::cout<<"Unmatched ]"<<std::endl;
	   			  m=0;
	   			  n=1;
	   		  }
	   		  else
	   			  i--;
	   		  if(i>0){}
	   			   //std::cout<<"Unmatched ]"<<std::endl;
	      }
       }
       else if(ch!='{' && ch!='(' && ch=='[')
       {
    	   m=0;
       }
   }
   if(del=='{')
	   z='}';
   else if(del=='(')
	   z=')';
   else if(del=='[')
	   z=']';

   if(i>0)
   {
	   std::cout<<"Missing ";
	   while(i>0)
	   {
		   m=0;
		   std::cout<<z;
		   i--;
	   }
   }
  std::cout<<std::endl;
  return m;
}
bool do_delimiters_nest()
{
	char ch,w,x;
    int w1,w2,m=0;
    ece150::initialize_table();
	ece150::start_reading_file();
	while(!ece150::at_eof())
	{
	   ch=ece150::get_next_character();
	   if(ch=='{' || ch=='(' || ch=='[')
	      ece150::place_character(ch);
	   else if(ch=='}' || ch==')' || ch==']')
	   {
	      w=ece150::get_right_most_character();
	      if((w=='{' && ch=='}')||(w=='(' && ch==')')||(w=='[' && ch==']'))
	    	 ece150::erase_right_most_character();
	      else
	      {
	    	 std::cout<<"Unmatched "<<ch<<std::endl;
	         w2=0;
	      }

	    		/*if(ece150::is_table_empty())
	    		{
	    			std::cout<<"Unmatched "<<ch<<std::endl;
	    			word1=0;
	    		}*/

	    }
	}
	if(ece150::is_table_empty())
	{
	    w1=1;
	    w2=1;
	}
	else
	{
	    std::cout<<"Missing ";
	    while(!ece150::is_table_empty())
	    {
	        x=ece150::get_right_most_character();
	        if(x=='{')
	           std::cout<<"}";
	        else if(x=='(')
	           std::cout<<")";
	        else if(x=='[')
	           std::cout<<"]";
	        ece150::erase_right_most_character();
	     }
	     std::cout<<std::endl;
	}
	if(w1==1 && w2==1)
	   m=1;
	else
	   m=0;
	return m;
}


