#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

typedef struct morse{
	
	char *harf;
	char *sembol;
	struct morse *sol,*sag;
	
}morse;



morse *kok=NULL;



ekle(char *karakter,char *isaret)
{
	short i=0;
	
	morse *yeni=malloc(sizeof(morse));
	
	yeni->harf=karakter;
	yeni->sembol=isaret;
	
	yeni->sol=NULL;
	yeni->sag=NULL;
	
	if(kok==NULL)
	{
		kok=yeni;
	}
	
	else
	{
		morse *nomad=kok;
		morse *mother=kok;
		
		while(nomad!=NULL && i<strlen(isaret))
		{
			mother=nomad;
			
			if(isaret[i] == '.')
			{
				nomad=nomad->sol;
			
			}
			else if(isaret[i]=='-')
			{
				nomad=nomad->sag;
				
			}
			
			i++;
			
				
		}
				
	
		if(isaret[strlen(isaret)-1]=='.')
		{
			mother->sol=yeni;
		}
		else if(isaret[strlen(isaret)-1]=='-')
		{
			mother->sag=yeni;
		}
		
		
	}
	
}




morsacevir(char *x,morse *nomad)
{
		
		if(nomad!=NULL)
		{
			
			morsacevir(x,nomad->sol);
			if(strcmp(x,nomad->harf)==0)
			{
				
				short j=0;
				while(nomad->sembol[j]!='\0') 
				{
					printf("%s ",nomad->sembol);
					j++;
				}
			}
			else if(x==' ')
			{
				printf(" ");				
			}
			
			morsacevir(x,nomad->sag);
		
		}
	
	
}

morstancevir(char *kod)
{
	morse *nomad=kok;
	short i=0;
	
	while(i<strlen(kod))
	{
		
		while(kod[i] != ' ' && kod[i]!='\0')
		{
			if(kod[i]=='.')
			{
				nomad=nomad->sol;
			}
			else
			{
				nomad=nomad->sag;
			}	
			i++;
		}
		printf("%s",nomad->harf);
		
		nomad=kok;
		
		while(kod[i]==' ')
		{
			printf(" ");
			i++;
		}
		
		
				
	}
	
	
	
	
	
}

show(morse *nomad)
{
	
	if(nomad!=NULL)
	{	
		show(nomad->sol);
		printf("%s  (%s) ,\n",nomad->harf,nomad->sembol);
		show(nomad->sag);
	}	
}


main()
{
	ekle(" "," ");
	ekle("E",".");
	ekle("T","-");
	ekle("I","..");
	ekle("A",".-");
	ekle("N","-.");
	ekle("M","--");
	ekle("S","...");
	ekle("U","..-");
	ekle("R",".-.");
	ekle("W",".--");
	ekle("D","-..");
	ekle("K","-.-");
	ekle("G","--.");
	ekle("O","---");
	ekle("H","....");
	ekle("V","...-");
	ekle("F","..-.");
	ekle("L",".-..");
	ekle("P",".--.");
	ekle("J",".---");
	ekle("B","-...");
	ekle("X","-..-");
	ekle("C","-.-.");
	ekle("Y","-.--");
	ekle("Z","--..");
	ekle("Q","--.-");
	
	

	short sayac=0;
	char *cumle="DEU";
	char *code="-- . .-. .... .- -... .-   -.. ..- -. -.-- .-";
	
	morstancevir(code);
	
	
	while(cumle[sayac]!='\0')
	{
		morsacevir(cumle[sayac],kok);
		sayac++;
	}
	
	
	
		
	
	
	
	
	
	
	
	
}
