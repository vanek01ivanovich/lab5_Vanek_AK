#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>



int main (int argc, char **argv)
{
  int b;
  int h = 0, v = 0, l = 0, f = 0, i = 0;
 

  while (true)
    {
      static struct option long_options[] =
        {
          
          {"help",     no_argument, 0, 'h'},
          {"version",  no_argument,0, 'v'},
          {"list",  no_argument, 0, 'l'},
          {"file",    no_argument, 0, 'f'},
	  {"information",no_argument,0,'i'}
         
        };
      
      int option_index = 0;

      b = getopt_long (argc, argv, "ihvlf",
                       long_options, &option_index);

     
      if (b == -1)
        break;

      switch (b)
        {

        case 'h':
	  if (h == 0) {
          	puts ("Args: Help");
		h = 1;
	  }
          break;


	case 'i':
	  if(i == 0){
	  	puts("Args: Information");
		i = 1;
		
	  }
	  break;

        case 'v':
	  if (v == 0) {
          	puts ("Args: Version");
		v = 1;
	  }
          break;

        case 'l':
	  if (l == 0) {
          	puts("Args: List");
		l = 1;
        	
	  }	
	  break;

        case 'f':
	  if (f == 0) {
          	puts("Args: File");
          	f = 1;
		
	  }	
	  break;


        case '?':
          break;

        default:
          break;
        }
    }

  

  if (optind < argc)
    {
      printf ("non-option ARGV-elements: ");
      while (optind < argc)
        printf ("%s ", argv[optind++]);
      putchar ('\n');
    }

  exit (0);
}
