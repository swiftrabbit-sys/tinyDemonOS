#pragma once

#include "instructions.h"
#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

void mainarc(string input)
{
    if(input == "clear"){ system("clear"); }
    if(input == "help"){system("less manual.txt");}
    if(input == "ls"){ system("ls -al"); }
    if(input == "exit"){ exit(0); }
    
    
}
