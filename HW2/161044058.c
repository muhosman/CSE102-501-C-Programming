#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#define Trial 10

void menu();
int make_a_guess (int trial,int min,int max);
void draw_hourglass (int height);
void draw_mountain_road(int length,int max_radius);
void show_scores(int score_human,int score_computer);

int main(){
	srand(time(NULL));
	menu();
	return 0;
}


void menu(){
/*If user enters an invalid choice (such as entering a negative number, 0, and
more than 4), then you must warn user by saying “This is an invalid choice.
Try again!”.*/
	int n,temp,i;
//Case-1 implementation | 'Temp' holds the result(Lucky_number-guess) | 'n' power of the two for distance | 'i' for array
	int lucky_number,guess,choice;//Case-1 implementation
	int min,max,distance;//Case-1 implementation
	int Human_score=0,Program_score=0;//Case-1 implementation
	int height;//Case-2 implementation
	int length,max_radius;//Case-3 implementation

	do{
		printf("\n***** MENU *****");
		printf("\n1. Play Lucky Number");
		printf("\n2. Draw Hourglass");
		printf("\n3. Draw Mountains Road");
		printf("\n4. Exit");
		printf("\nChoice: ");
		scanf("%d",&choice);

		switch(choice){
		case 1:
			min=1,max=1024,i=0;
			lucky_number=1+rand()%max;
			/*The reason for the initial call before while loop("guess=make_a_guess()") is to check the probability 
			that the first estimate is correct*/
			guess=make_a_guess(i,min,max);
			/*IF 'luck_number' is equal to 'guess' program ignores the while loop 
			and go to if statement*/
			while(lucky_number!=guess){
				i++;
				/*If the value of Guess is greater than lucky number,
				the value is assigned to the minimum*/
				if(guess<lucky_number)
					min=guess;
				/*If the value of Guess is smaller than lucky number,
				the value is assigned to the minimum*/
				if(guess>lucky_number)
					max=guess;
				if(lucky_number-guess<0)
					temp=-(lucky_number-guess),n=10;
				else
					temp=lucky_number-guess,n=10;
				while(pow(2,n)>temp)
					n-=1;
				printf("Distance: %d\n\n",n+1);
				//If 'i' is equal to 'Trial' ,Program wil be win this game and go back to menu
				if(i==Trial){
					Program_score++;
					printf("Program Win !\n");
					show_scores(Human_score,Program_score);
					break;
				}
				else
					guess=make_a_guess(i,min,max);
			}
			//Program is end and go back to menu
			if(lucky_number==guess){
					Human_score++;
					printf("Distance: 0\n");
					printf("You Win !\n");
					show_scores(Human_score,Program_score);
			}
			break;
		case 2:
			do{
				printf("Height: ");
				scanf("%d",&height);
				if(height%2==0)	
					printf("Please Enter Odd number !");
			}while(height%2==0);
			draw_hourglass(height);
			break;
		case 3:
			printf("Length: ");
			scanf("%d",&length);
			printf("Max Radius: ");
			scanf("%d",&max_radius);
			draw_mountain_road(length,max_radius);
			break;
		default:
			printf("\nThis is invalid choice.Try again !\n");
			break;
		}
	}while(choice!=4);


}
// This Function just print
int make_a_guess (int trial,int min,int max){
	int guess,distance,n=9;
	printf("(Trial: %d)Make a guess between %d and %d: ",trial,min,max);
	scanf("%d",&guess);
	return guess;
}
// This Function just print
void show_scores(int score_human,int score_computer){
	printf("Your Score: %d Program Score: %d",score_human,score_computer);
}

void draw_hourglass (int height){
	int i,j,space;
	//'j' is constant variable,it takes the height value
	//'i' is the number of stars for each row
	//'space' is equal to '(j-i)/2'
	j=height,i=height;
	//TOP OF HOURGLASS
	while(height!=1){
	//If height is 5,First space will be 0.
		for(space=(j-i)/2; space>0 ;space--){
			printf(" ");
		}
		while(i!=0){
			printf("*");
			i--;	
		}
		printf("\n");
		height-=2;
		i=height;
	}
	//MIDDLE OF HOURGLASS
	for(space=(j-i)/2; space>0 ;space--){
		printf(" ");
	}
	printf("*\n");
	//LAST OF HOURGLASS
	while(height!=j){
		height+=2;
		for(space=(j-height)/2; space>0 ;space--){
			printf(" ");
		}
		i=0;
		while(i!=height){
			printf("*");
			i++;
		}
		printf("\n");
	}
}

void draw_mountain_road(int length,int max_radius){
	int i,j,k;
	int radius,counter=0;
	//'j' takes the space value for first row,this value is max radius
	//Because After a small radius, a large radius may cause overflow from left.
	j=max_radius+1;
	//If the 'counter' exceed the 'length' limit,while loop will be end.
	while(counter<length){
		radius=rand()%(max_radius+1);
	//'k' takes the radius
		k=radius;
		counter++;
		//1-Forexample radius is four. Four row will be until middle row.
		//2-And One Middle row
		//3-And Again will be four row
		//1.(shape=/)
		while(k!=0){
			j--;
			k--;
			for(i=j; i>0 ;i--){
				printf(" ");
			}		
			printf("/\n");

		}
		j--;
		//2.(shape=|)
		for(i=j; i>0 ;i--){
			printf(" ");
		}		
		printf("|\n");
		k=radius;
		//3.(shape=\)
		while(k!=0){
			j++;
			k--;
			for(i=j; i>0 ;i--){
				printf(" ");
			}		
			printf("\\ \n");
		}
		if(!(counter<length))
			break;
///--------------------------///
		radius=rand()%(max_radius+1);
		counter++;
		k=radius;
		//1.(shape=\)
		while(k!=0){
			j++;
			k--;
			for(i=j; i>0 ;i--){
				printf(" ");
			}		
			printf("\\ \n");
		}
		j++;
		//2.(shape=|)
		for(i=j; i>0 ;i--){
			printf(" ");
		}	
		printf("|\n");
		k=radius;
		//3.(shape=/)
		while(k!=0){
			j--;
			k--;
			for(i=j; i>0 ;i--){
				printf(" ");
			}		
			printf("/ \n");
		}
	}
}

