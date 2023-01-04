#include <stdio.h>
#include <conio.h>

#define N 20

void menu(int laberinto[N][N]);
void impresion(int x,int y,int laberinto[N][N]);
void movimiento(int laberinto[N][N],int num);
void arch_arr(char cad[],int array[N][N]);

int main()
{
    int laberinto[N][N];
    menu(laberinto);
    return 0;
}

void menu(int laberinto[N][N])
{
    int opcion,numero;
    do
    {
        printf("\nBienvenido al juego");
        printf("\n1)---Laberinto 1---\n");
        printf("\n2)---Laberinto 2---\n");
        printf("\n3)-----Salir------\n");
        printf("\nSeleccione una opcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1 :
            numero=0;
            arch_arr("laberinto.txt",laberinto);
            movimiento(laberinto,numero);
            break;
        case 2 :
            numero=16;
            arch_arr("laberinto_2.txt",laberinto);
            movimiento(laberinto,numero);
        break;
        default:break;
        }
    }while(opcion!=3);
}

void arch_arr(char cad[],int array[N][N])
{
    FILE *lab;
    lab = fopen(cad,"r");
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            fscanf(lab,"%d\n",&array[i][j]);
        }
    }
    fclose(lab);
}

void impresion(int x,int y,int laberinto[N][N])
{
    int i,j;
    system("cls");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(x==i && y==j)
            {
                printf("%c",254);
            }
            else
            {
                printf("%c",laberinto[i][j]);
            }
        }
        printf("\n");
    }
    printf("X= %d\n",x);
    printf("Y= %d\n",y);
}

void movimiento(int laberinto[N][N],int num)
{
    int x=num,y=0,tcl;
    impresion(x,y,laberinto);
    while(laberinto[x][y]!=178)
    {
        tcl=getch();
        if(tcl==224)
        {
            tcl=getch();
        }
        switch(tcl)
        {
            case 72 :
                if(laberinto[x-1][y]==176)
                {
                    break;
                }
                x--;
                impresion(x,y,laberinto);
                break;
            case 80 :
                if(laberinto[x+1][y]==176)
                {
                    break;
                }
                x++;
                impresion(x,y,laberinto);
                break;
            case 75 :
                if(laberinto[x][y-1]==176)
                {
                    break;
                }
                y--;
                impresion(x,y,laberinto);
                break;
            case 77 :
                if(laberinto[x][y+1]==176)
                {
                    break;
                }
                y++;
                impresion(x,y,laberinto);
                break;
        }
    }
    if(laberinto[x][y]==178)
    {
        printf("\nHas ganado felicidades");
    }
}
