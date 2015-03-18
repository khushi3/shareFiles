#include <stdio.h>

main()
{ FILE *fp1, *fp2; int i;char c;

  fp1 = fopen("clipp3.wav","r");
  fp2 = fopen("speech3.pcm", "w");
  for (i=0; i <15890; i++)
{   
c= fgetc(fp1);
  if (i>43) fputc(c,fp2); 
} 
 fclose(fp1);
   fclose(fp2);
}
