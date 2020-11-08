#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//Dzień dobry lub wieczor panie Doktorze mam problem z tym programem przy kompilacji nie ma zadnych bledow lecz gdy chce go uruchomic konsola sie zawiesza domyslam sie ze to problem z pamiecia ale nie wiem jak go rozwiazac czy moblby mi Pan pomoc?
struct macierz 
{
    int a;
    int b;
    float T[200][200];

};

void wczytaj (FILE *fin, struct macierz *m)
{
    int i,j;
    fscanf (fin, "%d", &m->a);
    fscanf (fin, "%d", &m->b);
    
    for (i=0;i<(*m).a;i++)
        for (j=0; j<(*m).b;i++)
            fscanf(fin,"%f",&(*m).T[i][j]);
}
void wypisz (struct macierz m)
{
    int i,j;
    printf("[ ");
    for (i=0;i<m.a;i++)
    {  
        for (j=0; j<m.b;i++)
        {
            printf("%.2f\t", m.T[i][j]);
        }
        printf("\n");
    }
}
struct macierz sum (struct macierz a, struct macierz b)
{
    struct macierz suma;
    int j,i;
    suma.a=a.a;
    suma.b=a.b;
    for (i=0;i<a.a;i++)
        for (j=0; j<a.b;i++)
            suma.T[i][j]=a.T[i][j]+b.T[i][j];
    
    return suma;

}
struct macierz subtract (struct macierz a, struct macierz b)
{
    struct macierz sub;
    int j,i;
    sub.a=a.a;
    sub.b=a.b;
    for (i=0;i<a.a;i++)
        for (j=0; j<a.b;i++)
            sub.T[i][j]=a.T[i][j]+b.T[i][j];

}
struct macierz multiply (struct macierz a, float x)
{
    int j,i;
    for (i=0;i<a.a;i++)
        for (j=0;j<a.b;j++)
            a.T[i][j]*=x;
}

struct macierz prod(struct macierz a, struct macierz b)
{
    struct macierz prodo;
    for (int i=0; i<a.a;i++)
    {
        for (int j=0; j<b.b;j ++)
            {
                for (int k=0;k<a.a;i++)
                {
                    prodo.T[i][j]+=(b.T[i][k]*b.T[k][j]);
                }
            }
}
}
float norm (struct macierz a)
{
    float s=0;
    int i,j;
    for (i=0;i<a.a;i++)
        for(j=0;j<a.b;j++)
            s+=a.T[i][j]*a.T[i][j];
    
    return sqrt(s);
}
void zapisz(char nazwa[], struct macierz a)
{
    FILE *fout = fopen(nazwa,"w+");
    fprintf(fout,"%d\n%d\n",a.a,a.b);
    for (int i=0;i<a.a;i++)
     {
        for (int j=0;j<a.b;j++)
            fprintf(fout,"%f\t",a.T[i][j]);
        fprintf(fout,"\n");
    }
    fclose(fout);

}
int main (int argc, char *argv[])
{

    if (strcmp(argv[1],"sum")==0)
    {
        FILE *fina = fopen(argv[2],"r");
        FILE *finb = fopen(argv[3],"r");
        struct macierz a;
        struct macierz b;
        wczytaj(fina,&a);
        wczytaj(finb,&b);
        if ((a.a==b.a)&&(a.b==b.b))
        {
            struct macierz suma = sum(a, b);
            if (argc==4)
            {
                
                zapisz(argv[4],suma);
            }
            else if (argc==3)
            {
                wypisz(suma);
            }
            
        }
        fclose(fina);
        fclose(finb);
        
        
        
    }
    else if (strcmp(argv[1],"subtract")==0)
    {
        FILE *fina = fopen(argv[2],"r");
        FILE *finb = fopen(argv[3],"r");
        struct macierz a;
        struct macierz b;
        wczytaj(fina,&a);
        wczytaj(finb,&b);
        if ((a.a!=b.a)||(a.b!=b.b))
        {
            printf("Macierze są różnych rozmiarów nie można ich odjąć");
            exit(-2);
        }
        else 
        {
            struct macierz subtr = subtract(a, b);
            if (argc==4)
            {
                
                zapisz(argv[4],subtr);
            }
            else if (argc==3)
            {
                wypisz(subtr);
            }
        }
        fclose(fina);
        fclose(finb);
    }
    else if (strcmp(argv[1],"prod")==0)
    {
        FILE *fina = fopen(argv[2],"r");
        FILE *finb = fopen(argv[3],"r");
        struct macierz a;
        struct macierz b;
        wczytaj(fina,&a);
        wczytaj(finb,&b);
        if (a.b!=b.a)
        {
            printf("Macierze mają złe rozmiary i nie da się ich przemnożyć przez siebie");
            exit(-2);
        }
        else 
        {
            struct macierz pro = prod(a, b);
            if (argc==4)
            {
                
                zapisz(argv[4],pro);
            }
            else if (argc==3)
            {
                wypisz(pro);
            }
        }
        fclose(fina);
        fclose(finb);
    }
    else if (strcmp(argv[1],"multiply")==0)
    {
        FILE *fina = fopen(argv[2],"r");
        struct macierz a;
        wczytaj(fina,&a);
        float x = atof(argv[3]);
        
        
            struct macierz multi = multiply(a, x);
            if (argc==4)
            {
                
                zapisz(argv[4],multi);
            }
            else if (argc==3)
            {
                wypisz(multi);
            }
            
        
        fclose(fina);
        
    }
else if (strcmp(argv[1],"norm")==0)
    {
        FILE *fina = fopen(argv[2],"r");
        struct macierz a;
        wczytaj(fina,&a);
        float x = norm(a);
            if (argc==4)
            {
                FILE *fout = fopen(argv[3],"w+");
                fprintf(fout,"%f",x);
                fclose(fout);
            }
            else if (argc==3)
            {
                printf("Norma to %f",x);
            }
            
        
    }   
    return 0;
}