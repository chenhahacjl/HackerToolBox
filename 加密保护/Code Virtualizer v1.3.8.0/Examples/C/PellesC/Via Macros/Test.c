/****************************************************************************** 
/* Module: Test.c
/* Description: Shows how to call Code Virtualizer Macros in PellesC
/*
/* Authors: Rafael Ahucha  
/* (c) 2006 Oreans Technologies
/*****************************************************************************/ 


/****************************************************************************** 
/*                   Libraries used by this module
/*****************************************************************************/ 

#include <stdio.h>
#include "VirtualizerSDK.h"


/****************************************************************************** 
/*                          Function prototypes
/*****************************************************************************/ 


/****************************************************************************** 
/*                          Global variables
/*****************************************************************************/ 


/*****************************************************************************
* Main
*
*  Main program function
*
* Inputs
*  None
* 
* Outputs
*  None
*
* Returns
*  Exit Code
******************************************************************************/


int main(void)
{

   VIRTUALIZER_START

   printf("Hello, world!\n");
 
   VIRTUALIZER_END
   
   return 0;
 
}

