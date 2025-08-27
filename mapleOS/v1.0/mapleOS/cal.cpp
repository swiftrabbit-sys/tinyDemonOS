#include <iostream>
#include "headerfiles/sustem.h"
#include "headerfiles/instructions.h"

using namespace std;

int main (int argc, char *argv[]) {
   funcStep("loading calculator");
   instruction(1,1);
   instruction(1,2);
   int nu1,nu2;
   std::string opr;
   while(1 == 1){     
      
      printf("enter your first number: ");cin>>nu1;
      printf("enter your secound number: ");cin>>nu2;
      printf("enter your operator: ");cin>>opr;
      if(opr == "exit"){
         break;
      }
      ALU(nu1,nu2,opr);
   }
   
  return 0;
}
