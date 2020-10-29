#include <stdio.h>
#include <stdlib.h>


void wypisz (FILE *fin,int a, int b, float m1[a][b])
{
    for (int i=0;i<a;i++)
    {
        for (int j=0; j<b;j++){
           fscanf(fin,"%f\t", &m1[i][j]);
           //printf("%f\t",m1[i][j]); aby wypisac mozna uzyc tej linijki
        }
        //printf("\n");
    }
    //printf("\n");
}
void mnozenie (int w3,int k3,int b,float W[w3][k3],float A[][b],float X[][k3])
{
    
    for (int i=0;i<w3;i++)
    {
        for (int j=0;j<k3;j++)
            W[i][j]=0;
    }
    printf("(%d)[",w3);
    for (int i=0;i<w3;i++)
    {
        
        for (int j=0;j<k3;j++)
        {
            
            for (int l=0;l<=k3;l++)
            {
            W[j][i]+=A[i][l]*X[l][j];
            }
            printf("%.1f ",W[i][j]);
        }
        
    
        
    }
    printf("]");
}
int main (int argc,char *argv[])
{
    int a,b,c,d;
    FILE *fina,*finx;
    fina = fopen(argv[1],"r");
    finx = fopen(argv[2],"r");
    fscanf(fina,"%d\n%d",&a,&b);
    fscanf(finx,"%d\n%d",&c,&d);

    float A[a][b],X[c][d],W[a][d];
    wypisz(fina,a,b,A);
    wypisz(finx,c,d,X);
    mnozenie(a,d,b,W,A,X);

    return 0;
}