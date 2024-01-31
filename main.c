//
//  main.c
//  finalProject.c
//
//  Created by Sonia Sidi on 4/26/23.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include <time.h>

////////////////// DEFINE /////////////////////

#define  NUMBER_OF_TRIES    (5)


///////////////// VARIABLE GLOBAL//////////////
int category = 1;
int numberUser =4;
int actuelUser =0;
char users[100] [100] = {"micipssa","Sonia","samira","kader"};
char users_score[100] = {0};
char animals[3][10] = {"dog","cat","worm"};
char planets[3][10] = {"Venus","Mars","Mercure"};
char country[3][10] = {"mexico","USA","canada"};

char mycategory[3][10] = {};

/////////*********//////////////

///////// PROTOTYPE/////////////

void Menu( void );


////////// FUNCTIONS ///////////////////////

void Category(void)
{
char choose[10];
int value = 0;


printf("please choose one categories : \n ");

printf("1. animals\n");
printf("2. planets\n");
printf("3. countrys\n");

scanf("%s",choose);
value = atoi(choose);

if ( (value >3) || (value <1) )
{
printf("not a valid category \n ");
}
else
{
category = value;
printf("valid category %d \n ",category);
}

printf("end\n ");

}
int n =0;
int tryActuel = 0;
int numberOfTries = 0;
char reponse [5] ={0};
void Play(void)
{
int lenght = 0;
bool play = true;
int numEssaye = 5;
char letter [1] ;

srand(time(NULL));

tryActuel = 0;
n= rand()%3 ; // entre 1 et 2
printf("number random: %d \n",n);
printf("category: %d \n",category);
if (category == 1)
{

memcpy(mycategory,animals,sizeof(animals));
}
else if (category == 2)
{

memcpy(mycategory,planets,sizeof(planets));

}
else if (category == 3)
{
memcpy(mycategory,country,sizeof(animals));
}


//printf("animals: %s \n",mycategory[n]);


lenght = strlen((const char*)mycategory[n]);
//printf("length: %d \n",lenght);


while (play)
{
printf("Enter a letter to guess: \n");
scanf("%s",&letter);
//printf("animals: %s \n",mycategory[n]);
//printf("the letter is : %s  %d  %d\n",letter , letter[0],mycategory[n][tryActuel]);
        printf("the letter is : %s\n",letter);


if (mycategory[n][tryActuel] == letter[0]) // juste s a n d r a
{

reponse[tryActuel]=letter[0];
printf("nice , you can try next letter \n");
printf("actuel word : %s \n",reponse);
tryActuel++;
if (tryActuel>=lenght)
{
printf("congratulations \n");
users_score[actuelUser]++;
play = false;


}

}
else
{

numberOfTries++;
printf("wrong, Please try again %d  \n",NUMBER_OF_TRIES-numberOfTries);
if (numberOfTries >= NUMBER_OF_TRIES)
{
printf("lost \n");
play = false;
}

}

}
numberOfTries =0;
memset(reponse,0,sizeof(reponse));


}

void Team()
{
//Credits
int i = 0;
char rep [5] = {0};
char userName;


printf(" Your name is already on the list ");

for (i = 0 ; i<numberUser;i++)
{
printf("%d- %s  score %d\n",i,users[i],users_score[actuelUser]);
}

printf("number users  :%d \n",numberUser);
printf("Hello, are you new player ? please write yes or no\n");

scanf("%s",rep);


if (strcmp(rep,"yes") == 0)
{
printf("please write your user name : \n");
scanf("%s",&userName);
strcpy((char*)users[numberUser],&userName);
actuelUser =numberUser;
numberUser++;

}
else if (strcmp(rep,"no") == 0)
{
printf("who are you ? ");
scanf("%d",&actuelUser);

}
else
{
printf("sorry i dont understand : %s",rep);
}
Menu();

}

void Select(int x)
{
//Mode Selection
if (x == 1){
Play();
}
else if (x == 2){
Category();
}
else if (x == 3){
Team();
}
}
char category_name [10] ={0};

void Menu( void )
{
//Home Menu
int num = 0;

while (1)
{
printf("hung game\n");
printf("1. Play\n");
printf("2. Categories\n");
printf("3. Team\n");
printf("actual user : %s , score %d \n",users[actuelUser],users_score[actuelUser]);

if (category == 1)
{
strcpy(category_name,"animals");
}
else if (category == 2)
{
strcpy(category_name,"planetes");
}
else if (category == 3)
{
strcpy(category_name,"countrys");
}

printf("actual categories : %s \n",category_name);
printf("Select Option: ");
scanf("%d", &num);
Select(num);
}
}

int main()
{
Menu();
exit(0);
}

