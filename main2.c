#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#define alphhei 9
#define alphlen 3

void main(){

    char selectedLetter = ' ';    
	int numSuccess = 0;
	int numberRightAnswer=0;
    char line1 = ' ';
    char line2 = ' ';
    char line31 = ' ';
	char line32 = ' ';
	char line33 = ' ';
    char line41 = ' ';
	char line42 = ' ';
    bool levelInput= false;
	bool success = false;
	bool charfound = false;
	bool charRepeat= true;
	char level;
    int i=0;
    int j;

	int k=0;
	srand (time(NULL));
	int posWord = rand()%10;
	int numberAttempts = 0;
	char alphabet [3][9]= {{'A','B','C','D','E','F','G','H','I'},
						   {'J','K','L','M','N','N','O','P','Q'},
						   {'R','S','T','U','V','W','X','Y','Z'}};
	char str1;
	const char *word[]={"AGULLA","PILOTA","CARTULINA","RATOLI","METALL","NAUFRAGI","VEHICLE","COMPILADOR","PARAFERNALIA", "AVIONETA"};
	char wordToComplete[strlen(word[posWord])];
	char insertedchars[25]; //array on emmagatzemarem els inputs del jugador

		
	printf("                  ******************************************************\n");
	printf("                  ************ BENVINGUTS AL JOC DEL PENJAT ************\n");
	printf("                  ******************************************************\n");

	printf("\n                     Siusplau, introdueix el nivell de dificultat :\n");
	printf("\n        1. Facil \n");
	printf("        2. Normal \n");
	printf("        3. Dificil \n");
	printf("        4. Extrem \n");
	fflush(stdout);
        

    do {
    	scanf(" %c", &level);		//fem un scan del nivell que entra l'usuari per teclat i determinem el nombre d'intents que tindra segons el nivell seleccionat. 
		switch (level){
		case '1':
			printf("\n Has escollit el nivell FACIL\n Tindras 7 intents per trobar la paraula amagada!"); //mostrem en pantalla el nivell seleccionat per l'usuari
            numberAttempts = 7;
			levelInput=true;
            break;
		case '2':
			printf("\n Has escollit el nivell NORMAL\n Tindras 5 intents per trobar la paraula amagada!");
            numberAttempts = 5;
			levelInput=true;
            break;
		case '3':
			printf("\n Has escollit el nivell DIFICIL\n Tindras 4 intents per trobar la paraula amagada!");
            numberAttempts = 4;
			levelInput=true;
            break;
		case '4':
			printf("\n Has escollit el nivell EXTREM\n Tindras 3 intents per trobar la paraula amagada!");
            numberAttempts = 3;
			levelInput=true;
            break;
		default :
			printf("Nivell no valid. Torna'l a introduir.\n" );

		}
    }while (levelInput==false);
	printf("\n Les lletres que introdueixis aniran desapareixent de l'alfabet.\n");
	printf("\n Pitja qualsevol tecla per continuar. ");

	

	system("pause");

    system("cls");

    printf("Nombre de intents que et queden: %d\n\n", numberAttempts); //mostrem el nombre de intents que li queden a l'usuari
	
    for(i=0; i<alphlen; i++){  //recorrem l'array on hem emmagatzemat l'alfabet i el mostrem en pantalla
        for(j=0; j<alphhei; j++){
            printf("%c ", alphabet[i][j]);
        }
        printf("\n");
    }
	printf("\n");
	for(i=0; i<strlen(word[posWord]); i++){ //omplim l'array amb guions baixos i amb la llargada de la paraula seleccionada per la funcio random
		wordToComplete[i]= '_';
		printf("%c ", wordToComplete[i]);
	}
    printf("\n\n+=======+\n"); 
    printf("|       %c", line1);
    printf("\n|       %c", line2);
    printf("\n|     ");
    printf("\n|      ");
    printf("\n|");
    printf("\n============\n\n");
	
	
	fflush(stdin);
	//comença la comparacio dels inputs amb la paraula
	
	
	do{
		printf("Introdueix una lletra :");
		fflush(stdin);
		scanf(" %c", &selectedLetter);
		selectedLetter= toupper(selectedLetter); //passem l'input de l'usuari a majuscula per fer treballar el programa amb majuscules
												
		for(i=0; i<strlen(insertedchars);i++){			//comprobacio de lletres introduides. 	
			if (selectedLetter==insertedchars[i] ){	
					printf("Aquesta lletra ja ha estat introduida. Torna a introduir-ne una: ");
					fflush(stdin);				
					scanf(" %c", &selectedLetter);
					selectedLetter= toupper(selectedLetter);
					i=0;
			}
		}			
		
		insertedchars[k]= selectedLetter; //emmagatzemament del input de l'usuari a una variable per saber quins caracters ha introduit
		
		system("cls");
		charfound=false;    //reiniciem a false el bolea que utilitzem per restar intents en cas de no encertar 
		for (i=0; i<strlen(word[posWord]); i++){
			if (selectedLetter==word[posWord][i]){
				wordToComplete[i]=selectedLetter;
				numberRightAnswer++;
				charfound=true;
			} 
		}
		if (charfound==false){ //condicio per restar intents al jugador
				numberAttempts--;
			}

		switch (level){ //switch case on donarem diferents valors a les variables que ens mostraran en pantalla el ninot, depenent del nivell seleccionat.
			case '1'://valors de les variables per al nivell de dificultat 1
				switch(numberAttempts){ //creem un switch dins de cada nivell, per donar diferents valors a cada variable segons el nombre de intents que queden
					case 6:
						line1='|';
						break;
					case 5:
						line2='O';
						break;
					case 4:
						line31='|';
						break;
					case 3:
						line32='/';
						break;
					case 2:
						line33='\\';
						break;
					case 1:
						line41='/';
						break;
					case 0:
						line42='/\\';
						break;
				}
				break;
			case '2':
				switch(numberAttempts){					
					case 4:
						line1='|';
						
						break;
					case 3:
						line2='O';
						
						break;
					case 2:
						line31='|';						
						break;
					case 1:
						line32='/';
						line33='\\';						
						break;
					case 0:
					    line41='/';
						line42='/\\';
						break;
				}
				break;
				
			case '3':
				switch(numberAttempts){					
					case 3:
						line1='|';
						line2='O';						
						break;
					case 2:
						line31='|';						
						break;
					case 1:
						line32='/';
						line33='\\';						
						break;
					case 0:
					    line41='/';
						line42='/\\';
						break;
				}
				break;
			case '4':
				switch(numberAttempts){										
					case 2:
						line1='|';
						line2='O';						
						break;
					case 1:
						line31='|';
						line32='/';
						line33='\\';						
						break;
					case 0:
					    line41='/';
						line42='/\\';
						break;
				}
				break;
		}

		printf("Nombre de intents que et queden: %d\n\n", numberAttempts);
	
    	for(i=0; i<alphlen; i++){ //iteracio per mostrar lalfabet en pantalla
        	for(j=0; j<alphhei; j++){
				if(selectedLetter==alphabet[i][j]){ //condicio per eliminar la lletra de la matriu alfabet indicant que ja ha estat utilitzada
					alphabet[i][j]=' ';
				}
            	printf("%c ", alphabet[i][j]);
        	}
        	printf("\n");
    	}

		printf("\n");
		for(i=0; i<strlen(word[posWord]); i++){
			printf("%c ", wordToComplete[i]);
		}
				
		 
		printf("\n\n+=======+\n"); //mostrem en pantalla el ninot de penjat. Depenent dels errors, s'aniran modificant les variables que construeixen el ninot
		printf("|       %c", line1);
		printf("\n|       %c", line2);
		printf("\n|      %c%c%c", line32, line31, line33);
		printf("\n|      %c %c ", line41, line42);
		printf("\n|");
		printf("\n============\n\n");
		
	
		fflush(stdin);		
		k++; //incrementem el comptador que recorrira les posicions del array on guardem els inputs del jugador despres de validarlos.

		
		
	}while (numberRightAnswer<strlen(word[posWord]) && numberAttempts>0); //condicions de sortida de la iteracio principal del joc
	
	if(strcmp(wordToComplete, word[posWord])==0){//condicions per mostrar un missatge de victoria o de derrota al jugador
		printf("\nFelicitats!! Has guanyat!! \n La paraula era: %s\n\n", wordToComplete);
	}else if (numberAttempts==0){
		printf("\n\n\nHas esgotat el nombre d'intents!!\n El joc s'ha acabat!!\n La paraula era : %s\n\n", word[posWord]);
	}

	printf("                  *******************************************************\n");
	printf("                  *********** GRACIES PER JUGAR AL NOSTRE JOC ***********\n");
	printf("                  *******************************************************\n");
	sleep(5);
	
}