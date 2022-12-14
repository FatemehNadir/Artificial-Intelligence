#include <math.h>
#include <stdio.h>
#include <conio.h>
#include "type.h"
#include "utils.c"
#include "init.c"
#include "gen.c"


int erfunc(char *s, int val);
void initialize(char *argv[], POPULATION *p);
void report(int gen, POPULATION *p, IPTR  pop);
void statistics(POPULATION *p, IPTR pop);

int main(int argc, char *argv[])
{
  IPTR tmp, op, np;
  POPULATION population;
  POPULATION *p = &population;

  p->gen = 0;
  
  srand(10);

  if(argc != 2) return erfunc("Usage: ga <inputfile name> ", argc);
  
  initialize(argv, p);

  while(p->gen < p->maxGen){
    p->gen++;
	 generation(p);
	 statistics(p, p->np);
	 report(p->gen, p, p->np);
    tmp = p->op;
    p->op = p->np;
    p->np = tmp;
  }
}


