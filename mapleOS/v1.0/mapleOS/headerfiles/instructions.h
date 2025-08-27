#pragma once
#include <iostream>
#include <math.h>

// max : 400 - 800

using namespace std;
void instruction(int insVal1, int insVal2){
  if(insVal1 == 1 && insVal2 == 1){ system("lolcat logo"); } // test
  if(insVal1 == 1 && insVal2 == 2){ system("lolcat logocal.txt");}
  if(insVal1 == 1 && insVal2 == 3){ system("clear");}
}
void ALU(float n1, float n2, std::string operation){
  if (operation == "add") { cout<< n1 + n2 <<endl; }
  if (operation == "sub") { cout<< n1 - n2 <<endl; }
  if (operation == "div") { cout<< n1 / n2 <<endl; }
  if (operation == "mod") { cout<< fmod(n1, n2) <<endl; }
  if (operation == "floor") { cout<< floor(n1) <<endl; }
  if (operation == "ceil") { cout<< ceil(n1) <<endl; }
  if (operation == "round") { cout<< round(n1) <<endl; }
  if (operation == "abs") { cout<< abs(n1) <<endl; }
  if (operation == "max") { cout<< max(n1, n2) <<endl; }
  if (operation == "min") { cout<< min(n1, n2) <<endl; }
  if (operation == "pow") { cout<< pow(n1, n2) <<endl; }
  if (operation == "log") { cout<< log(n1) <<endl; }
  if (operation == "log10") { cout<< log10(n1) <<endl; }
  if (operation == "exp") { cout<< exp(n1) <<endl; }
  if (operation == "sin") { cout<< sin(n1) <<endl; }
  if (operation == "cos") { cout<< cos(n1) <<endl; }
  if (operation == "tan") { cout<< tan(n1) <<endl; }
  if (operation == "asin") { cout<< asin(n1) <<endl; }
  if (operation == "acos") { cout<< acos(n1) <<endl; }
  if (operation == "atan") { cout<< atan(n1) <<endl; }
  if (operation == "atan2") { cout<< atan2(n1, n2) <<endl; }
  if (operation == "sinh") { cout<< sinh(n1) <<endl; }
  if (operation == "cosh") { cout<< cosh(n1) <<endl; }
  if (operation == "tanh") { cout<< tanh(n1) <<endl; }
  if (operation == "asinh") { cout<< asinh(n1) <<endl; }
  if (operation == "acosh") { cout<< acosh(n1) <<endl; }
  if (operation == "atanh") { cout<< atanh(n1) <<endl; }
  if (operation == "sqrt") { cout<< sqrt(n1) <<endl; }
  if (operation == "cbrt") { cout<< cbrt(n1) <<endl; }
  if (operation == "hypot") { cout<< hypot(n1, n2) <<endl; }
  if (operation == "lgamma") { cout<< lgamma(n1) <<endl; }
  if (operation == "erf") { cout<< erf(n1) <<endl; }
  if (operation == "erfc") { cout<< erfc(n1) <<endl; }
  if (operation == "tgamma") { cout<< tgamma(n1) <<endl; }
  if (operation == "trunc") { cout<< trunc(n1) <<endl; }
  if (operation == "mul") { cout<< n1 * n2 <<endl; }
  if (operation == "sqrt") { cout<< sqrt(n1) <<endl; }
} 

