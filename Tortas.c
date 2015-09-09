#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
void menu(void);
void Pago(void);
void orden(void);

int desi,op,a,x=1;
struct tortas
	{
		int CantTortacub,clavecub;
		int CantTortajam,clavejam;
		int CantTortaesp,claveesp;
		int CantTortaref,claveref,clavesal;
		int PresTortacub,PresTortacub1;
		int PresTortajam,PresTortajam1;
		int PresTortaesp,PresTortaesp1;
		int PresTortaref,PresTortaref1;
		int Sumatotal;
		char NomCub[50],NomJam[50],NomEsp[50],NomRef[50],NomSal[50];
		
	}tortas;
void menu(void){
		
	system("cls");
	printf("\t\tMenu\n\n");
	printf("%d %s %d\n",tortas.clavecub,tortas.NomCub,tortas.PresTortacub1);
	printf("%d %s %d\n",tortas.clavejam,tortas.NomJam,tortas.PresTortajam1);
	printf("%d %s %d\n",tortas.claveesp,tortas.NomEsp,tortas.PresTortaesp1);
	printf("%d %s %d\n",tortas.claveref,tortas.NomRef,tortas.PresTortaref1);
	printf("%d %s \n",tortas.clavesal,tortas.NomSal);
	printf("¿Que desea pedir?...");

}


void orden(void){
	
	
		system("cls");
		printf("Cantidad                Nombre                   Presio               Total");
		printf("\n\n");
		if (tortas.CantTortacub>0){
			printf("%d                      Cubana                    %d",tortas.CantTortacub,tortas.PresTortacub);
			printf("\n\n");			
		}
		if (tortas.CantTortajam>0){
			printf("%d                      Jamon                     %d",tortas.CantTortajam,tortas.PresTortajam);
			printf("\n\n");			
		}
		if (tortas.CantTortaesp>0){
			printf("%d                      Especial                  %d",tortas.CantTortaesp,tortas.PresTortaesp);
			printf("\n\n");			
		}
		if (tortas.CantTortaref>0){
			printf("%d                      Refresco                  %d",tortas.CantTortaref,tortas.PresTortaref);
			printf("\n\n");			
		}
		printf("\n\n                                                                      %d\n\n",tortas.Sumatotal=tortas.PresTortacub+tortas.PresTortaesp+tortas.PresTortajam+tortas.PresTortaref);
		printf("\n\nDesea Ordenar Algo mas....(Si=1 / No=0)\n");
		scanf("%i",&desi);
}
void pago(void){
	int pago,subpago;
	
	system("cls");
		printf("\n\nMonto a pagar :  %d",tortas.Sumatotal);
		printf("\n\nIngrese el monto recibido :  ");scanf("%d",&pago);
		if (pago==tortas.Sumatotal){
			printf("\n\nEl pago fue exacto.");
		}
		if (pago>tortas.Sumatotal){
			subpago=pago-tortas.Sumatotal;
			printf("\n\nDevuelve de cambio %d pesos",subpago);
			printf("\n\nRegresando al menu\n\n",subpago);
		}printf("\n");
		getch();	
	
}
int main() {
	FILE *ap;
	ap=fopen("Tortas.txt","r");
	
	fscanf(ap,"%d ",&tortas.clavecub);
	fgets(tortas.NomCub, 20, ap);
	fscanf(ap,"%d ",&tortas.PresTortacub1);
	fscanf(ap,"%d ",&tortas.clavejam);
	fgets(tortas.NomJam, 20, ap);
	fscanf(ap,"%d ",&tortas.PresTortajam1);
	fscanf(ap,"%d ",&tortas.claveesp);
	fgets(tortas.NomEsp, 20, ap);
	fscanf(ap,"%d ",&tortas.PresTortaesp1);
	fscanf(ap,"%d ",&tortas.claveref);
	fgets(tortas.NomRef, 20, ap);
	fscanf(ap,"%d ",&tortas.PresTortaref1);
	fscanf(ap,"%d ",&tortas.clavesal);
	fclose(ap);
	while (x==1){
		menu();
		scanf("%dop",&op);
		switch(op){
		case 1:
			tortas.CantTortacub=tortas.CantTortacub+1;
			tortas.PresTortacub=tortas.PresTortacub+40;
			orden();
			if (desi !=1){
				pago();
				getch();
			}
			
			break;
		case 2:
			tortas.CantTortajam=tortas.CantTortajam+1;
			tortas.PresTortajam=tortas.PresTortajam+20;
			orden();
			if (desi !=1){
				pago();
			}
			break;
		case 3:
			tortas.CantTortaesp=tortas.CantTortaesp+1;
			tortas.PresTortaesp=tortas.PresTortaesp+55;
			orden();
			if (desi !=1){
				pago();
			}
			break;
		case 4:
			tortas.CantTortaref=tortas.CantTortaref+1;
			tortas.PresTortaref=tortas.PresTortaref+10;
			orden();
			if (desi !=1){
				pago();
			}
			break;
		case 5:
			printf ("\nGracias por usar el programa.\n");
			x=0;
			getch();
			break;
		default:
			printf("numero incorrecto");
			printf("\n");
			system("pause");
			break;
		}
		
	}
	
	return 0;
}
