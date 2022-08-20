//Si consideri il seguente programma:

#include <stdio.h>

int f(int n, int r);

int main (){
	printf("%d\n",f(7891,0));
	return 0;
}
int f(int n, int r) {
    if(n == 0)
    {
        return r;
    }
    else
    {
    	return f(n / 10, r * 10 + n % 10);
    }
}



//Cosa viene stampato a video?  1987
//Che cosa ritorna la funzione f quando viene chiamata con  argomenti n>0 e r=0?  Inverte n
