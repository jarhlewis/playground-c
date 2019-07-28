#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#define MAX 35

void llenar(int vidas, int tamano, char A[MAX][MAX], char B[MAX][MAX]);
void cambia_color();
void limpiar(char Arr[MAX][MAX], int tamano);
void imprimir(char VAR[MAX][MAX], int tamano);
void llenab (int tamano, char A[MAX][MAX], char B[MAX][MAX]);
int vivos(int n, int m, char A[MAX][MAX]);

int p=0;
int main(){
    int tamano, i, vidas, m, j, d;
    printf("Bienvenid@s al juego de la vida\n");
    printf("Presione una tecla para comenzar :)");
    getch();
    system("cls");
    printf("Introduzca el tama%co n que desea para el cuadrado (n*n): ",164);
    scanf("%d", &tamano);
    while (tamano> MAX || tamano<=0){
        system("cls");
        printf("Por favor, introduzca un tama%co n valido para el cuadrado(n<=35): ",164);
        scanf("%d", &tamano);
    }
    char A[tamano][tamano];
    char B[tamano][tamano];
    system("cls");
        int h;
        h=pow(tamano,2)/2;
    printf("Introduzca el numero m%cximo de vidas con las que desea comenzar: ", 160);
    scanf("%d", &vidas);
//Mirar la condicion, REVISAR
    while (vidas > h || vidas<=0){
        system("cls");
        printf("Por favor, introduzca un numero de vidas v%clido\n (No puede ser mayor que la mitad de cantidad de casillas del cuadrado): \n (En su caso no puede ser mayor a %d)",160,h);
        scanf("%d", &vidas);
    }
    system("cls");
    printf("%cLISTO PARA ASOMBRARTE?",168);
    getch();
    llenar(vidas, tamano, A, B);
}
void llenar(int vidas, int tamano, char A[MAX][MAX], char B[MAX][MAX]){
    int i, m, j, d;
    srand(time(NULL));
    limpiar(A, tamano);
    limpiar(B,tamano);
    //Llenar las vidas
    m=0;
    while(m<vidas){
    j=(rand()% tamano);
    d=(rand()% tamano);
    A[j][d]= 3;
    m++;
    }
    llenab(tamano,A,B);
}
//Cambiar Colores *-*
void cambia_color(){
if(p<12){
    switch(p){
    case 1:
    system ("color 01");
    break;
    case 2:
    system ("color 02");
    break;
    case 3:
    system ("color 03");
    break;
    case 4:
    system ("color 04");
    break;
    case 5:
    system ("color 05");
    break;
    case 6:
    system ("color 06");
    break;
    case 7:
    system ("color 09");
    break;
    case 8:
    system ("color 0A");
    break;
    case 9:
    system ("color 0B");
    break;
    case 10:
    system ("color 0C");
    break;
    case 11:
    system ("color 0D");
    break;
    case 12:
    system ("color 0E");
    break;
    }
}else{
    p=0;
    system ("color 08");
}
 

}
void limpiar(char Arr[MAX][MAX], int tamano){
    int i,m;
for(i=0; i<tamano; i++){
        for(m=0; m<tamano; m++){
            Arr[i][m]= ' ';
        }
    }
}
void imprimir(char VAR[MAX][MAX], int tamano){
        int p,k, i;
//El inicio del cuadrado
printf("%c",201);
for(i=0; i<tamano*2; i++){
    printf("%c",205);
}
printf("%c \n",187);
//lateral Izquierdo
for(i=0; i<(tamano); i++){
    printf("%c",186);
    //Lineas centrales
    for(p=0; p<(tamano); p++){
        printf("%c ",VAR[i][p]);
        }
    //Lateral derecho
    printf("%c \n",186);
}
printf("%c",200);
//Inferior
for(k=0; k<(tamano*2); k++){
    printf("%c",205);
}
printf("%c", 188);
}
void llenab (int tamano, char A[MAX][MAX], char B[MAX][MAX]){
   int i, j;
    limpiar(B,tamano);
    for (i=0;i<tamano;i++){
        for(j=0; j<tamano; j++){
            if (A[i][j]==' '){
                if (vivos(i,j,A)==3){
                    B[i][j]=("%c",3);
                }else B[i][j]=' ';
            }else if (A[i][j]==("%c",3)){
                if (vivos(i,j,A)==3){
                    B[i][j]=("%c",3);
                }else if (vivos(i,j,A)==2){
                    B[i][j]=("%c",3);
                }else if (vivos(i,j,A)>3){
                   B[i][j]=' ';
                }else if (vivos(i,j,A)<2){
                   B[i][j]=' ';
                    }
                }
            }
        }
system("cls");
imprimir(A, tamano);
cambia_color();
p++;
Sleep(100); // Retraso.
system("cls");
imprimir(B, tamano);
llenab(tamano,B,A);
llenab(tamano,A,B);
Sleep(100);
cambia_color();
p++;
}
//para contar los vivos
int vivos(int n, int m, char A[MAX][MAX]){
int x=0;
    if (A[n][m-1]==("%c",3)){
        x++;
    }if(A[n][m+1]==("%c",3)){
        x++;
    }
    if(A[n+1][m]==("%c",3)){
        x++;
    }
    if(A[n+1][m+1]==("%c",3)){
        x++;
    }
    if(A[n+1][m-1]==("%c",3)){
        x++;
    }
    if(A[n-1][m-1]==("%c",3)){
        x++;
    }
    if(A[n-1][m]==("%c",3)){
        x++;
    }
    if(A[n-1][m+1]==("%c",3)){
        x++;
    }
return x;
}
