#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define PI 3
#define ShortEdge 5     //Short Edge of Rectangular
#define SQUARE 1
#define RECTENGULAR 2
#define CIRCULAR 3
#define Red 0
#define Yellow 1
#define Blue 2
#define Black 3
#define White 4


double CreateBody (int shape);

int SetColor (int color);
double LoadMoves(int shape, double body_size);
int SetAttackPower(int lower_bound, int upper_bound);
void ShowPokemon(int shape, double body_size, int color, double move_length, int attack_power);

int main(){

	int shape, color, attack_power;
	double size_of_body, move_length;
	time_t t;
	srand((unsigned) time(&t));
	shape =  RECTENGULAR; //CIRCULAR//SQUARE// Pick one of them
	size_of_body = CreateBody (shape);
	color = 798	;
	color = SetColor(color);
	move_length = LoadMoves(shape, size_of_body);
	attack_power = SetAttackPower (0, 150);
	ShowPokemon(shape, size_of_body, color, move_length, attack_power);

return 0 ;
}
//############CREATE BODY##############//
//Square is 1, rectangular is 2 and circular is 3
//It takes shape of the Pokémon as an input and calculates area of the shape and returns it.
//The shapes could be rectangular,square or circular. 
//In order to what is the shape The function takes the edge or radius from user .
double CreateBody (int shape){
	double size,Edge,secondEdge,radius;
	if(shape==SQUARE){
		printf("\nEnter Edge of Square: ");
		scanf("%lf",&Edge);
		return pow(Edge,2);
	}
	else if(shape==RECTENGULAR){
		printf("\nEnter Edge of Rectengular: ");
		scanf("%lf",&Edge);
		printf("\nEnter Second Edge of Rectengular: ");
		scanf("%lf",&secondEdge);
		return Edge*secondEdge;	
	}
	else if(shape==CIRCULAR){
		printf("\nEnter Radius of Circle: ");
		scanf("%lf",&radius);
		return PI*pow(radius,2);
	}
}

//############SET COLOR##############//
//It takes a color code as an integer input to paint the Pokémon and returns revised color code.
//If the color code is between 0 and 1000 then the function 
//returns modulo five of the code, otherwise, it always returns 1
int SetColor (int color){
	if(color>=0&&color<=1000){
		return color%5;
	}
	else
		return 0;
}
//############LENGTH OF MOVES##############//
//The shapes could be rectangular,square or circular.
//In order to what is the shape The function calculates perimeter of the shape
//and return the length of one move.
double LoadMoves(int shape, double body_size){

	if(shape==SQUARE){
		return 4*sqrt(body_size);
	}
	else if(shape==RECTENGULAR){
		return 2*(body_size/ShortEdge)+2*ShortEdge;
	}
	else if(shape==CIRCULAR){
		return 2*PI*sqrt((body_size/PI));
	}
}

//############ATTACK POWER##############//
//It takes lower and upper bound of the attack power and generates 
//a random integer attack power between the bounds and returns the power.
int SetAttackPower(int lower_bound, int upper_bound){
	return lower_bound + rand() % (upper_bound-lower_bound+1);
}

//############CREATED POKEMON##############//
// It prints created Pokémon with its specifications
void ShowPokemon(int shape, double body_size, int color, double move_length, int attack_power){
	int i,j,k,initial,end,temp;
	//Initial is tab parameter for top of the line(FOR CIRCULAR)
	//End is tab parameter for between two stars.(FOR CIRCULAR)
	//Temp is holder parameter.(FOR CIRCULAR)
	if(shape==SQUARE){
	//The nested loop for shape of square
	//First for loop turns until number of sides and second loop
	//starts. Second loop makes star as much as number of sides.
		for(i=0; i<sqrt(body_size) ;i++){
			for(j=0; j<sqrt(body_size) ;j++){
				printf("*");
			}
			printf("\n");
		}

		printf("\nName: Square Pokémon");
		printf("\nSize: %.2f",body_size);
		if(color==Red)
			printf("\nColor: Red ");
		else if(color==Yellow)
			printf("\nColor: Yellow");
		else if(color==Blue)
			printf("\nColor: Blue");
		else if(color==Black)
			printf("\nColor: Black");
		else if(color==White)
			printf("\nColor: White");
		printf("\nMove: %.2f",move_length);
		printf("\nAttack Power: %d",attack_power);
	}
	if(shape==RECTENGULAR){
	//The nested loop for shape of rectangular
	//First for loop turns until number of sides(ShortEdge) and second loop
	//starts. Second loop makes star as much as number of sides.
		for(i=0; i<ShortEdge ;i++){
			for(j=0; j< (int)body_size/ShortEdge ;j++){
				printf("*");
			}
			printf("\n");
		}

		printf("\nName: Rectengle Pokémon");
		printf("\nSize: %.2f",body_size);
		if(color==Red)
			printf("\nColor: Red ");
		else if(color==Yellow)
			printf("\nColor: Yellow");
		else if(color==Blue)
			printf("\nColor: Blue");
		else if(color==Black)
			printf("\nColor: Black");
		else if(color==White)
			printf("\nColor: White");
		printf("\nMove: %.2f",move_length);
		printf("\nAttack Power: %d",attack_power);
	}

	if(shape==CIRCULAR){
	//This if else separate even and odd radius
	//The first lines and the last lines that valid
	//The number of tab in the beginning depends on the radius.
	//Example r=7 tab=3 ,r=6 tab=2
		if((int) sqrt(body_size/PI)%2!=0){
			temp=(sqrt(body_size/PI)-1)/2;
			for(j=temp; j!=0 ;j--){
				printf("\t");
			}
			printf("*\n");
			end=2;
			initial=temp-1;
		}
		else{
			temp=(sqrt(body_size/PI))/2;
			for(j=temp-1; j!=0 ;j--){
				printf("\t");
			}
			printf("    *\n");
			end=1;
			initial=temp-1;
		}
		//This if control the radius whether it is 1 or not
		//If radius is one,it doesn't enter this structure.
		if(temp-1!=-1){
			//This for loop make work between first row and middle row
			for(k=temp-1; k!=0 ;k--){
				for(j=initial; j!=0 ;j--){		
					printf("\t");		
				}
				printf("*");
				for(i=end; i!=0 ;i--){
					printf("\t");		
				}
				printf("*\n");
				initial-=1;
				end+=2;
			}
			printf("*");
			//This for loop make work at middle row
			for(j=sqrt(body_size/PI)-1; j!=0 ;j--){
				printf("\t");
			}
			printf("*\n");
			initial+=1;
			end-=2;
			//This for loop make work between middle row and last row
			for(k=temp-1; k!=0 ;k--){
				for(j=initial; j!=0 ;j--){		
					printf("\t");		
				}
				printf("*");
				for(i=end; i!=0 ;i--){
					printf("\t");		
				}
				printf("*\n");
				initial+=1;
				end-=2;
			}
			//This if else separate even and odd radius
			//And last row loop
			if((int)sqrt(body_size/PI)%2!=0){
				for(j=(sqrt(body_size/PI)-1)/2; j!=0 ;j--){
					printf("\t");
				}
				printf("*\n");
			}
			else{
				for(j=temp-1; j!=0 ;j--){
					printf("\t");
				}
				printf("    *\n");
			}
		}

		printf("\nName: CIRCULAR Pokémon");
		printf("\nSize: %.2f",body_size);
		if(color==Red)
			printf("\nColor: Red ");
		else if(color==Yellow)
			printf("\nColor: Yellow");
		else if(color==Blue)
			printf("\nColor: Blue");
		else if(color==Black)
			printf("\nColor: Black");
		else if(color==White)
			printf("\nColor: White");
		printf("\nMove: %.2f",move_length);
		printf("\nAttack Power: %d",attack_power);
	}
}
