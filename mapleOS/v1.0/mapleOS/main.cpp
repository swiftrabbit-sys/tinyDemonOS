#include <iostream>
#include "headerfiles/instructions.h"
#include "headerfiles/mainarch.h"
#include "headerfiles/sustem.h"

using namespace std;
int main () {
    instruction(1,1); 
    bool run = true;
    funcStep("getting this ready for you");
    while (run == true) {
      string input;
      printf("c:/home> "); cin>>input;
      if(input == "shell"){ system("./shell"); }
      if(input == "cal"){ system("./cal"); }
      if(input == "update"){ 
          system("./update.sh && disk1/./manupdate");
      }
      else {mainarc(input);}
    }
  return 0;
}
