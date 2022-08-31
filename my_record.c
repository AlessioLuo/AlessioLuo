/*Si consideri la seguente funzione boo(), che opera sulla struttura dati my_record facendo uso di memoria dinamica. L’implementazione di boo() contiene un bug,
dovuto ad un uso improprio della memoria dinamica attraverso i puntatori. Individuare tale bug e spiegarne, in un massimo di 80 parole,
la natura e le problematiche che può comportare.*/
  
typedef struct {
  	int a;
    int b;					
} my_record; 

int boo() {					
    my_record *p;
    my_record *q;
    p = malloc (sizeof(my_record));  //viene allocato una parte di memoria di grandezza my_record chiamata p
    q = p; //q punta a p
    free(p); //libero la memoria p
    q->a++;		//qui q punta a una parte di memoria gia` liberata quindi le operazioni successive non sono piu` corrette
    return q->a; 
}
