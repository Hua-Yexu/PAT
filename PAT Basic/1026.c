#include <stdio.h>

#define CLK_TCK 100

int main(void)
{
  int C1, C2, C;
  int h = 0, m = 0, s = 0;
  
  scanf("%d %d", &C1, &C2);
    
  C = (C2 - C1) / CLK_TCK;
  if(((C2 - C1) % CLK_TCK) >= 50)
    C++;
  
  if(C >= 3600） {h = C / 3600; C = C % 3600;}
  if(C >= 60)  {m = C / 60; C = C % 60;}
  s = C;
  
  printf("%02d:%02d:%02d", h, m, s);
  
  return 0;
}
