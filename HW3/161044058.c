#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define Input 100
#define GRADE 10
#define EXGRADE 2


int add(int number1,int number2);
int sub(int number1,int number2);
int multiply(int number1,int number2);
int divide(int number1,int number2);
int power(int number1,int number2);
int rest(int number1,int number2);
int doit (int calc(int number_1,int number_2),int first_number,int second_number);
void calculator_menu();
void control_input(int *f_number,int *s_number,char operator[2]);

void take_grades(int grade[GRADE]);
void take_exam_grades(int grade[EXGRADE]);
double calculate_homework(int grade[GRADE]);
double calculate_lab(int grade[GRADE]);
double calculate_all(int HW,int grade[EXGRADE],int LB);

void diamond(int height);

void menu();



int main(){

	menu();

	return 0;
}

void menu(){
	int choice; // Selection 
	double HW,LB; // 'HW'Holds average Homework grades ,'LB'Holds average Lab grades
	int hw_grade[GRADE]; // Homework grade
	int lb_grade[GRADE]; // Lab grade
	int ex_grade[EXGRADE]; //Exam grade
	int height; // Diomond height

	do{
		printf("1.Calculator\n");
		printf("2.Student Grade\n");
		printf("3.Diamond\n");
		printf("4.Exit\n");
		scanf("%d",&choice);

		switch(choice){
			case 1:
				calculator_menu();
				break;
			case 2:
				printf("ENTER Homework GRADE\n");
				take_grades(hw_grade);

				printf("ENTER Lab GRADE\n");
				take_grades(lb_grade);

				printf("ENTER Exam (First Midterm Second Final) GRADE\n");
				take_exam_grades(ex_grade);

				HW=calculate_homework(hw_grade);
				LB=calculate_lab(lb_grade);

				printf("\nGrade:%.2f\n",calculate_all(HW,ex_grade,LB));
				break;
			case 3:
				printf("Enter Diamond Height: ");
				scanf("%d",&height);
				diamond(height);
				break;
			case 4:
				break;
			default:
				printf("INVALID CHOICE ! ! ! PLEASE AGAIN COHICE ONE SELECTION !\n");
				break;
		}
	}while(choice!=4);
}

void calculator_menu(){
	char operator[2]; //Take the operator from user
	int f_number,s_number,result=0;
	printf("After each character, you can enter data after inserting a space.\n ");
	printf("When you finished entering value,you will enter, no space.\n ");
	printf("If you want to exit just enter the character '!'\n");

	do{
		/*
		This function take the string from user and is divided into sections 
		and converts char to int for numbers(char).
		*/
		control_input(&f_number,&s_number,operator);
		/*
		If the operator has only one argument, it takes the result of the
		previous operation as the first argument. If there is no previous operation , 
		0 will be used.Indeed previous result is zero
		*/
		if(s_number=='\n'||s_number=='\0'){
			s_number=f_number;
			f_number=result;
		}

		if('+'==operator[0]){
			result=doit(add,f_number,s_number);
			printf("Result:%d",result);	
		}
		else if('-'==operator[0]){
			result=doit(sub,f_number,s_number);
			printf("Result:%d",result);	
		}
		else if('*'==operator[0]&&'*'==operator[1]){
			result=doit(power,f_number,s_number);
			printf("Result:%d",result);	
		}
		else if('*'==operator[0]){
			result=doit(multiply,f_number,s_number);
			printf("Result:%d",result);	
		}
		else if('/'==operator[0]){
			result=doit(divide,f_number,s_number);
			printf("Result:%d",result);	
		}
		else if('%'==operator[0]){
			result=doit(rest,f_number,s_number);
			printf("Result:%d",result);	
		}
		else if('!'==operator[0])
			break;
		operator[1]='0';

		printf("\n'+' Addition \n");
		printf("'-' Substraction\n");
		printf("'*' Multiple\n");
		printf("'/' Divide\n");
		printf("'**' Power\n");
		printf("'' Rest\n");
		printf("'!' Exit\n");
		
	}while(1);
	
}

void control_input(int *f_number,int *s_number,char operator[2]){
	int i,j,len;
	char arr[Input];
	char f_num[Input];
	char s_num[Input];

	fgets(arr,100,stdin);
	len=strlen(arr);
	//Takes operator + 12 13 | '+'
	for(i=0;i<len;i++){
		if(arr[i]==' ')
			break;
		operator[i]=arr[i];
	}
	//Takes first number + 12 13 | '12' if there is
	for(j=0,i=i+1;i<len;j++,i++){
		if(arr[i]==' ')
			break;
		f_num[j]=arr[i];
	}
	//Takes second number + 12 13 | '13' if there is
	for(j=0,i=i+1;i<len;i++,j++){
		s_num[j]=arr[i];
	}	
	//Convert to int first number, if it is not null or new line character
	if(f_num[0]!='\0'&&f_num[0]!='\n')
		*f_number=atoi(f_num);
	else 
		*f_number='\n';
	//Convert to int second number, if it is not null or new line character
	if(s_num[0]!='\0'&&s_num[0]!='\n'){
		*s_number=atoi(s_num);
	}
	else{
		*s_number='\n';
	}
	//Reset arrays
	memset(arr, '\0', sizeof(arr));
	memset(f_num,'\0', sizeof(f_num));
	memset(s_num,'\0', sizeof(s_num));
}


int add(int number1,int number2){
	return number1+number2;
}
int sub(int number1,int number2){
	return number1-number2;
}
int multiply(int number1,int number2){
	return number1*number2;
}
int divide(int number1,int number2){
	return number1/number2;
}
int power(int number1,int number2){
	return pow(number1,number2);
}
int rest(int number1,int number2){
	return number1%number2;
}
int doit (int calc(int number_1,int number_2),int first_number,int second_number){
	return calc(first_number,second_number);
}

void take_grades(int grade[GRADE]){
	for(int i=0;i<GRADE;i++){
		printf("%d.",i);
		scanf("%d",&grade[i]);
	}
}
void take_exam_grades(int grade[EXGRADE]){
	for(int i=0;i<EXGRADE;i++){
		printf("%d.",i);
		scanf("%d",&grade[i]);
	}
}
double calculate_homework(int grade[GRADE]){
	double result=0;
	for(int i=0;i<GRADE;i++){
		result=result+grade[i];
	}

	return result/GRADE;
}
double calculate_lab(int grade[GRADE]){
	double result=0;
	for(int i=0;i<GRADE;i++){
		result=result+grade[i];
	}
	return result/GRADE;
}
double calculate_all(int HW,int grade[EXGRADE],int LB){
	return ((HW/100)*10)+((LB/100)*20)+((grade[0]/100)*30)+((grade[1]/100)*40);
}

void diamond(int height){
	int i,j,k,space,stars=2;
	space=height-1;
	
	for(i=0;i<height;i++){
		//Space pressure, a lack of height, every loop space=space-1; 
		//Indeed every line one missing
		for(j=space;j>0;j--){
			printf(" ");	
		}
		//First statement
		if(i==0)	printf("/\\\n");	
	
		else{
			printf("/");
			//Start two stars and every loop stars=stars+2;
			for(k=0;k<stars;k++){
				printf("*");	
			}
			printf("\\\n");
			stars+=2;
		}
		space--;
	}

	space+=1;
	stars-=2;
	//space is zero
	for(i=0;i<height;i++){
		for(j=space;j>0;j--){
			printf(" ");	
		}

		if(i==height-1)	printf("\\/\n");		
		else{
			printf("\\");

			for(k=stars;k>0;k--){
				printf("*");	
			}
			printf("/\n");
			stars-=2;
		}
		space++;
	}
}
