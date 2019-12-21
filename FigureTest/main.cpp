#include <string.h>
     #include <grx20.h>
     #include <grxkeys.h>
     #include "Figure.h"
	 #include <Math.h>
     int main()
     {

     
       GrSetMode( GR_default_graphics );

       Figure f(320,240,70,0);
	   f.Show();
	   GrKeyRead();
	   //f.Expand(2);
	   //f.Show();
	   //GrKeyRead();
	   f.Rotate(M_PI/4.0);
	   f.Show();
	
       GrKeyRead();
	   
     
       return 0;
     }
