#include "statPlayer.h"

void displayStat(Stdt a){
  char* txt1 = "Stat actuel de votre personnage : \n\n";
  int size1 = strlen(txt1);
  displayTxt(size1, txt1);
  printf("[%s %s]\n", a.name, a.sname);
  printf("Reputation : %d\n", a.fame);
  printf("Intelligence : %d\n", a.intellect);
  printf("Force : %d\n", a.power);
  printf("Mental : %d\n", a.wellness);
}

void displayBag(Stdt* main_character){
  //ROBUST
	if(main_character == NULL)
	{
		printf("Quelque chose ne vas pas avec main_character(displayBag)\n");
		exit(13);
	}

  printf("\nContenu de votre sac :\n");
  if(main_character->bag_size == 0)
  {
  	printf("Votre sac est vide ~0/8~\n");
  	return;
  }
  
  for(int i=0; i < main_character->bag_size; i++)
  {
  	printf("%s\n", main_character->Bag[i]);
  }
}

void fight(Stdt a, Stdt b)
{
  Stdt tmp;
  int rounds = 0;
  //while ninjas are still alive
  while(a.health>0 && b.health>0){
    rounds = rounds + 1;
    printf("---- ROUND %d ----\n", rounds);
    //a=attacker b=defender
    int randomValue = rand()%101;
        //check if b dodges
        if(randomValue > b.dodge){
            //the defender takes damages
            //damages are reduced
            int dmg = a.power - b.defence;
            if(dmg < 0){
                dmg = 0;
            } 
            b.health = b.health - dmg;
			if(b.health < 0){
				b.health = 0;
			}
            printf("%s prend %d dommages de %s\n", b.name, dmg, a.name);
            printf("%s a %d HP restant\n", b.name, b.health);
        } else {
            printf("%s esquive l'attaque de %s\n", b.name, a.name);
        }
    //swap attacker and defender
    tmp = a; 
    a = b;
    b = tmp;
    WaitPress();
  }
  // Display winner
  if(a.health > 0){
    printf("%s a vaincu %s !\n", a.name, b.name);
    printf("%s a %d HP restant\n", a.name, a.health);
  } else {
    a.health = 0;
	printf("\n");
    printf("~~> %s a mis KO %s avec %d HP restant!\n", b.name, a.name, b.health);
    WaitPress();
  }
  printf("\n");
}

void displayBeforeFight(Stdt fighter, Stdt main){
    printf("Personnage Principal :\n");
    printf("[%s %s]\n", main.name, main.sname);
    printf("Attaque = %d\n", main.power);
    printf("Defense = %d\n", main.defence);
    printf("Esquive = %d\n", main.dodge);
    printf("\n");
    printf("VS\n\n");
    printf("Adversaire :\n");
    printf("[%s %s]\n", fighter.name, fighter.sname);
    printf("Attaque = %d\n", fighter.power);
    printf("Defense = %d\n", fighter.defence);
    printf("Esquive = %d\n", fighter.dodge);
    printf("\n\n\n");
    WaitPress();
}

