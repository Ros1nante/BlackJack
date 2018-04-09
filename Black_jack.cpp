#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

int Cpucmp(void);
int Playercmp(void);
int First_cmp(void);
int Second_cmp(void);
int GetYesNokey(void);

int flag[21]={0}; //card tap
int cpu[21]={0};
int player[21]={0};
//////////////////////
int rand_cmp;
int rand_cpu;
int rand_n;
int rand_player;
//////////////////////
int sum_player;
int sum_cpu;
//////////////////////
int n_cpu;
int n_player;
//////////////////////
int cnt;
int cpu_cnt;
int player_cnt;
int flag_cnt;
//////////////////////
int cpu_sum;
int player_sum;
//////////////////////
int end_cpu;
int end_player;
//////////////////////
int i;
int j;
int n;
int m;
int f_cmp;
//////////////////////
char YN;

int main(void)
{
	printf("//  ..____.._............_.........._............_....\n");
	printf("//  .|.__.)|.|.__._..___|.|.__.....|.|.__._..___|.|.__\n");
	printf("//  .|.._.\\|.|/._`.|/.__|.|/./.._..|.|/._`.|/.__|.|/./\n");
	printf("//  .|.|_).|.|.(_|.|.(__|...<..|.|_|.|.(_|.|.(__|...<.\n");
	printf("//  .|____/|_|\\__,_|\\___|_|\\_\\..\\___/.\\__,_|\\___|_|\\_|\n");
	printf("//  ..................................................\n");
	getch();
	srand(time(NULL));
	flag[12]=1;
	//game start
	//printf("**game start**\n");
	
	/*
	for(i=1; i<=2; i++){
		if(i==1){
			/////*First Rand/////
			cnt++; //counter number
			cpu_cnt++;
			player_cnt++;
			//////////////////////
			cpu[cpu_cnt]=First_cmp(); // Random Number of CPU
			sum_cpu+=cpu[cpu_cnt];
			//////////////////////
			player[player_cnt]=First_cmp(); //Random Number of Player
			sum_player+=player[player_cnt];
			//////////////////////
			rand_cmp=f_cmp=0; //set
			printf("dsfd");
		}
		if(i==2){
			printf("second");
			/////*Second Rand/////
			cnt++; //counter number
			cpu_cnt++;
			player_cnt++;
			//////////////////////
			cpu[cpu_cnt]=Second_cmp(); // Random Number of CPU
			sum_cpu+=cpu[cpu_cnt];
			//////////////////////
			player[player_cnt]=Second_cmp(); //Random Number of Player
			sum_player+=player[player_cnt];
			//////////////////////
			rand_cmp=f_cmp=0; //set
			/////////////////////
		}
	}
	*/
	//////////////////////////////Set//////////////////////////////
	rand_cmp=0;
	rand_cpu=0;
	rand_n=0;
	rand_player=0;
	sum_player=0;
	sum_cpu=0;
	n_cpu=0;
	n_player=0;                                                                    
	cnt=0;
	cpu_cnt=0;
	player_cnt=0;
	flag_cnt=0;
	cpu_sum=0;
	player_sum=0;
	end_cpu=0;
	end_player=0;
	f_cmp=0;
	for(i=1; i<=21; i++){
		flag[i]=0;
		cpu[i]=0;
		player[i]=0;
	}
	///////////////////////////////////////////////////////////////
	for(;;) // Roop 
	{
		system("cls");
		cnt++; //counter number
		cpu_cnt++; //counter cpu number
		player_cnt++; //counter player number
		cpu[cpu_cnt]=Cpucmp(); // Random Number of CPU
		sum_cpu+=cpu[cpu_cnt];
		system(
		"cls");
		printf("C P U  Number : ");
		for(i=1; i<=cnt; i++){
			if(i==1) printf("?  ");
			if(i>1) printf("%d  ", cpu[i]);
		}
		printf(">>?+%d =21", sum_cpu-cpu[1]);
		printf("\n\n");
		player[player_cnt]=Playercmp(); //Random Number of Player
		sum_player+=player[player_cnt]; //sum
		printf("Player Number : ");
		for(i=1; i<=cnt; i++)
			printf("%d  ", player[i]);
		printf(">> %d  =21", sum_player);
		printf("\n\n\n");
		//print $//
		//   $$  //
		///////////
		rand_cmp=f_cmp=0;
		for(i=1; i<=11; i++)
			if(flag[i]==0) f_cmp=1;
		if(f_cmp==0) return 0;
		f_cmp=0;
		printf("Keep? [Y/N]");
		YN=getche();
		if(YN=='N' || YN=='n') break; 
//		printf("Player Number : ");
//		for(i=1; i<=cnt; i++) printf("%d  ", player[i]);
//		printf("Cpu Number : ");
//		for(i=1; i<=cnt; i++) printf("%d  ", cpu[i]);
	}
	//////////////////////////////////
	if(sum_cpu<21)                  //
		end_cpu=21-sum_cpu;         //
	if(sum_cpu==21)                 //
		end_cpu=0;                  //
	if(sum_cpu>21)                  //       C
		end_cpu=sum_cpu-21;         //         M
	if(sum_player<21)               //           P   U
		end_player=21-sum_player;   //             N   M
	if(sum_player==21)              //                   B  R
		end_player=0;               //                     E
	if(sum_player>21)               //                        
		end_player=sum_player-21;   //
	//////////////////////////////////
	system("cls");
	printf("C P U  Number : ");
	for(i=1; i<=cpu_cnt; i++) printf("%d  ", cpu[i]);
	printf("Sum : %d ", sum_cpu);
	printf("\n\n");
	printf("Player Number : ");
	for(i=1; i<=cnt; i++) printf("%d  ", player[i]);
	printf("Sum %d ", sum_player);
	
	if(end_player<end_cpu)
		printf("\n\n\n                                   Player Win!");
	if(end_player==end_cpu)
		printf("\n\n\n                                      Draw!");
	if(end_player>end_cpu)
		printf("\n\n\n                                   C P U Win!");
	printf("\n\n\n                                   Retry?[Y/N]");
	while(1){
		YN=getche();
		if(YN=='Y' || YN=='y') main();
		if(YN=='N' || YN=='n') return 0;
		else printf(" Nop!");
	}
	return 0;
}
/*
void Playercmp()
{
	while(1){
			rand_cmp=(rand()%11)+1; //cmp rand or player Number
			if(flag[rand_cmp]==0){
				rand_player=rand_cmp;
				player[cnt]=rand_cmp;
				flag[rand_cmp]=1;
				break;
			} 
		}
}
*/
int Cpucmp(void)
{
	/*
	if(cnt==1){
		rand_cmp=(rand()%5)+1; //cmp rand or player Number
		if(flag[rand_cmp]==0){ //Cmp Numb er >> not
			rand_cpu=rand_cmp;
			flag[rand_cmp]=1; //Use Number Delete
			return (rand_cpu) ;
		}
		else Cpucmp();
	}
	*/
	rand_cmp=(rand()%11)+1; //cmp rand or player Number
	if(flag[rand_cmp]==0){ //Cmp Numb er >> not
		rand_cpu=rand_cmp;
		flag[rand_cmp]=1; //Use Number Delete
		return (rand_cpu) ;
	}
	else Cpucmp();
	return (rand_cpu);
}
int Playercmp(void)
{	
	/*
	if(cnt==1){
		rand_cmp=(rand()%5)+1; //cmp rand or player Number 
		if(flag[rand_cmp]==0){ //Cmp Number >> not 
			rand_player=rand_cmp;
			flag[rand_player]=1; // Delete to Use Number
			return (rand_player) ;
		}
		else Playercmp();
	}
	*/
	rand_cmp=(rand()%11)+1; //cmp rand or player Number 
	if(flag[rand_cmp]==0){ //Cmp Number >> not 
		rand_player=rand_cmp;
		flag[rand_player]=1; // Delete to Use Number
		return (rand_player) ;
	}
	else {
		flag_cnt=0;
		for(i=1; i<=player_cnt+cpu_cnt; i++)
			if(flag[i]==0) flag_cnt=1;
		if(flag_cnt==1)	Playercmp();
		if(flag_cnt==0)	return 0;
	}
	return (rand_player);
}
