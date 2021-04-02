/*lex program to count number of words*/
%{
//#include<stdio.h>
//" " {printf("%d----\n", m); m = 0;}
#include<string.h>
int i = 0;
int m=0;
int tchar=0;
%}

/* Rules Section*/
%%
([a-zA-Z0-9])* {i++;
                 //printf("%s\t",yytext);   
                } 

[^\n\t] tchar++;
"\n" {printf("%d\n", i); i = 0;}
%%

int yywrap(void){}

int main()
{
	// The function that starts the analysis
	yylex();
	printf("Number of character:: %d\n",tchar);

	return 0;
}

