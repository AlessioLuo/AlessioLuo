/*Si definiscano due tipi di dato adatti a rappresentare triangoli generici e rettangoli con i lati paralleli agli assi:
Un triangolo sia definito come tre punti nel piano,> 
Si scriva quindi un programma che stabilisca se un triangolo è: 
"ragionevolmente" isoscele (o pseudoisoscele)
"ragionevolmente" equilatero (o pseudoequilatero)
Il programma deve verificare se valgono le relative proprietà (lunghezza dei lati) a meno di una ragionevole approssimazione in percentuale,
da impostarsi come costante globale.*/
  
#include <stdio.h>
#include <math.h>
#define ERROR 1.0

typedef struct
{
    float x;
    float y;
    
}punto;

typedef struct
{
    punto A;
    punto B;
    punto C;
}triangolo;

punto inserisciPunto(char c);// in ingresso riceviamo il nome del punto tipo 'A','B','C'
triangolo inserisciTriangolo();
void stampaTriangolo(triangolo tri);
float distanza(punto p1,punto p2);  //in ingresso due punti ci restituisce la distanza tra essi
int nullo(punto p1,punto p2,punto p3);
int uguale(float d1,float d2);

int main()
{
    int ab,bc,ac;  //VARIABILI IN CUI SALVO 1 se i lati a==b, 0 se a!=b;
    float a,b,c; //lati
    int coppie = 0;
    triangolo T;
    T = inserisciTriangolo();
    stampaTriangolo(T);
    a = distanza(T.B,T.C);
    b = distanza(T.A,T.C);
    c = distanza(T.A,T.B);
    ab = uguale(a,b);
    bc = uguale(b,c);
    ac = uguale(a,c);
    
    coppie = ab+bc+ac;
    
    if(coppie >= 1)
    {
        printf("Il triangolo e` isoscele\n");
    }
    else if(coppie == 3)
    {
        printf("Il triangolo e` equilatero\n");
    }
    else
    {
        printf("Il triangolo e` scaleno\n");
    }
    return 0;
}

int uguale(float d1,float d2)
{
    int ris;
    float max = d1;
    float min = d1;
    float diff;
    if (max<d2)
    {
        max = d2;
    }
    if (min>d2)
    {
        min = d2;
    }
    
    diff = max-min;
    
    if(diff>(max/100)*ERROR)
    {
        ris=0;
    }
    else
    {
        ris=1;
    }
    
    return ris;
}




punto inserisciPunto(char c)
{
    punto p;
    printf("Inserisci i dati del punto %c\n",c);
    printf("Inserisci x:");
    scanf("%f",&p.x);
    printf("\nInserisci y:");
    scanf("%f",&p.y);
    return p;
}

triangolo inserisciTriangolo()
{
    triangolo temp;
    int test=0;
    //chiede all`utente di inserire i punti A,B,C del triangolo temp;
    do{
    temp.A = inserisciPunto('A');
    temp.B = inserisciPunto('B');
    temp.C = inserisciPunto('C');
    test = nullo(temp.A,temp.B,temp.C);
    if(test == 0)
    {
        printf("Il triangolo inserito e` degenere/nullo, reinserisci!\n");
    }
    }while(test == 0);
     return temp;
}


int nullo(punto p1,punto p2,punto p3)
{
    
    int res;
    
    if(distanza(p1,p2)==0 || distanza(p2,p3)==0 || distanza(p3,p1)==0)
    {
        res = 0;
    }
    else
    {
        res = 1;
    }
    return res;
}






float distanza(punto p1,punto p2)
{
    float dista;
    float diffx,diffy;
    
    diffx = p1.x - p2.x; //x1-x2
    diffy = p1.y - p2.y;//y1-y2
    
    dista = sqrtf((diffx*diffx)+(diffy*diffy));  //distanza =  radice di (x1-x2)^2 + (y1-y2)^2 //sqrt e` radice intera, mentre sqrtf e` float
    
    
    
    return dista;
}


void stampaTriangolo(triangolo tri)
{
    printf("Punto A - x: %2.2f , y:%2.2f \n",tri.A.x,tri.A.y);
    printf("Punto B - x: %2.2f , y:%2.2f \n",tri.B.x,tri.B.y);
    printf("Punto C - x: %2.2f , y:%2.2f \n",tri.C.x,tri.C.y);
}


