#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define sizex 23
#define sizey 13



char plaser = '|';
char enemy = 'U';
char enemylaser = 'T';
char explosion ='X';
int menu=0;
int level=0;
int skin=0;
int gre=-1;

//basic functions
void slow(int sec){
    int millisec=500*sec;
    clock_t start_time =clock();
    while(clock()<start_time+millisec);
}

void jump(int x, int y){
    COORD coord;
    coord.X =x;
    coord.Y =y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int locatex(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwCursorPosition.X;
}

int locatey(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwCursorPosition.Y;
}

void slow2(int sec){
    int millisec=15*sec;
    clock_t start_time =clock();
    while(clock()<start_time+millisec);
}


//game related functions
int starting(){
	int on=1;
	int input2;
	jump(24,10);
	printf("START GAME");
	jump(24,13);
	printf("INSTRUCTIONS");
	jump(24,16);
	printf("HIGH SCORE");
	jump(24,19);
	printf("EXIT");
	jump(20,10);
	printf(">>>");
	
	while(on==1){
	if(kbhit()){
        input2 = getch();
    }
	if(input2==224){
		do {
            input2=getch();
        } while(input2==224);
        
		if(input2==72){           //up
			jump(locatex()-3,locatey());
			printf("   ");
			jump(locatex(),locatey()-3);
			jump(locatex()-3,locatey());
			printf(">>>");
		}
		if(input2==80){           //down
			jump(locatex()-3,locatey());
			printf("   ");
			jump(locatex(),locatey()+3);
			jump(locatex()-3,locatey());
			printf(">>>");	
		}
		if(input2==77){				//right
			on=0;
			if(locatey()==10){
				Beep(300,100);
				menu=1;
			}
			if(locatey()==13){
				Beep(300,100);
				menu=2;
			}
			if(locatey()==16){
				Beep(300,100);
				menu=3;
			}
			if(locatey()==19){
				Beep(300,100);
				menu=4;
			}
		}
		}	
	if(locatey()==22){						//if cursor is out of lower boundry
		jump(locatex()-3,locatey());
		printf("   ");
		jump(locatex()-3,19);
		printf(">>>");
	}
	
	if(locatey()==7){						//if cursor is out of upper boundry
		jump(locatex()-3,locatey());
		printf("   ");
		jump(locatex()-3,10);
		printf(">>>");
	}
	}	
}

int congrats(){
	//c
	Beep(200,50);
	printf("     ____   \n");
	printf("  __|\\   \\  \n");
	printf(" /   /\\   \\ \n");
	printf("|   |  |   |\n");
	printf("|   |  |___|\n");
	printf("|   |   ___ \n");
	printf("|   |  |   |\n");
	printf("|\\___\\/   /|\n");
	printf("| |  /___/ |\n");
	printf(" \\|__|   | /\n");
	printf("  \\( |___|/ \n");
	printf("    '   )/    \n");
	printf("        '     \n");	
	
	slow(3);
	//o
	Beep(200,50);
	jump(13,0);
	printf("      ____    \n");
	jump(13,1);
	printf("   __|\\   \\   \n");
	jump(13,2);
	printf("  /   /\\   \\  \n");
	jump(13,3);
	printf(" /   /  \\   \\ \n");
	jump(13,4);
	printf("|   |    |   |\n");
	jump(13,5);
	printf("|   |    |   |\n");
	jump(13,6);
	printf("|\\   \\  /   /|\n");
	jump(13,7);
	printf("| \\___\\/___/ |\n");
	jump(13,8);
	printf(" \\ |  ||   | /\n");
	jump(13,9);
	printf("  \\|__||___|/ \n");
	jump(13,10);
	printf("   \\(    )/   \n");
	jump(13,11);
	printf("    '    '    \n");
	
	slow(3);
	//n	
	Beep(200,50);
	jump(27,0);	
	printf(" ___   ____   \n");
	jump(27,1);
	printf("|\\  \\ |\\   \\  \n");
	jump(27,2);
	printf(" \\\\  \\| \\   \\ \n");
	jump(27,3);
	printf("  \\|  \\  \\   |\n");
	jump(27,4);
	printf("   |   \\  |  |\n");
	jump(27,5);
	printf("   |    \\ |  |\n");
	jump(27,6);
	printf("   |  |\\ \\|  |\n");
	jump(27,7);
	printf("   |__||\\___/|\n");
	jump(27,8);
	printf("   |  |/ |  ||\n");
	jump(27,9);
	printf("   |__|  |__|/\n");
	jump(27,10);
	printf("    \\(     )/  \n");
	jump(27,11);
	printf("     '     '   \n");

	slow(2);
	//g
	Beep(200,50);
	jump(42,0);	
	printf("     _____    \n");
	jump(42,1);
	printf("  __|\\    \\   \n");
	jump(42,2);
	printf(" /   /\\    \\  \n");
	jump(42,3);
	printf("|   |  |____| \n");
	jump(42,4);
	printf("|   |    ____ \n");
	jump(42,5);
	printf("|   |   |    |\n");
	jump(42,6);
	printf("|   |   |_,  |\n");
	jump(42,7);
	printf("|\\ __\\___/  /|\n");
	jump(42,8);
	printf("| |  /____ / |\n");
	jump(42,9);
	printf(" \\|__|    | / \n");
	jump(42,10);
	printf("  \\( |____|/  \n");
	jump(42,11);
	printf("   '   )/     \n");
	jump(42,12);
	printf("       '      \n");
	
	slow(2);
	//r
	Beep(200,50);
	jump(57,0);	
	printf("    ____   \n");
	jump(57,1);
	printf(" __|\\   \\  \n");
	jump(57,2);
	printf("|   |\\   \\ \n");
	jump(57,3);
	printf("|   | |   |\n");
	jump(57,4);
	printf("|   |/___/ \n");
	jump(57,5);
	printf("|   |\\   \\ \n");
	jump(57,6);
	printf("|   | |   |\n");
	jump(57,7);
	printf("|___| |___|\n");
	jump(57,8);
	printf("|   | |   |\n");
	jump(57,9);
	printf("|___| |___|\n");
	jump(57,10);
	printf(" \\(     )/ \n");
	jump(57,11);
	printf("  '     '  \n");

	slow(1);
	//a
	Beep(200,50);
	jump(70,0);	
	printf("      ___   \n");
	jump(70,1);
	printf("  ___|\\  \\  \n");
	jump(70,2);
	printf(" /   /\\   \\ \n");
	jump(70,3);
	printf("|   |  |   |\n");
	jump(70,4);
	printf("|   |__|   |\n");
	jump(70,5);
	printf("|   .--.   |\n");
	jump(70,6);
	printf("|   |  |   |\n");
	jump(70,7);
	printf("|___|  |___|\n");
	jump(70,8);
	printf("|   |  |   |\n");
	jump(70,9);
	printf("|___|  |___|\n");
	jump(70,10);
	printf(" \\(      )/ \n");
	jump(70,11);
	printf("  '      '  \n");

	slow(1);
	//t
	Beep(200,50);
	jump(83,0);	
	printf(" _______________ \n");
	jump(83,1);
	printf("/               \\\n");
	jump(83,2);
	printf("\\_____     _____/\n");
	jump(83,3);
	printf("  \\( /    /  )/  \n");
	jump(83,4);
	printf("   ' |   |   '   \n");
	jump(83,5);
	printf("     |   |       \n");
	jump(83,6);
	printf("    /   //       \n");
	jump(83,7);
	printf("   /___//        \n");
	jump(83,8);
	printf("  |`   |         \n");
	jump(83,9);
	printf("  |____|         \n");
	jump(83,10);
	printf("    \\(           \n");
	jump(83,11);
	printf("     '           \n");

	slow(1);
	//s
	Beep(200,50);
	jump(102,0);	
	printf("      ______  \n");
	jump(100,1);
	printf("    ___|\\     \\ \n");
	jump(100,2);
	printf("   |    |\\     \\\n");
	jump(99,3);
	printf("    |    |/____/|\n");
	jump(99,4);
	printf(" ___|    \\|   | |\n");
	jump(99,5);
	printf("|    \\    \\___|/ \n");
	jump(99,6);
	printf("|    |\\     \\    \n");
	jump(99,7);
	printf("|\\ ___\\|_____|   \n");
	jump(99,8);
	printf("| |    |     |   \n");
	jump(99,9);
	printf(" \\|____|_____|   \n");
	jump(99,10);
	printf("    \\(    )/     \n");
	jump(99,11);
	printf("     '    '      \n");
}

int title(){
	printf(" ________  ________  ________  ________  _______        ________  _________  _________  ________  ________  ___  __       \n");
	printf("|\\   ____\\|\\   __  \\|\\   __  \\|\\   ____\\|\\  ___ \\      |\\   __  \\|\\___   ___\\\\___   ___\\\\   __  \\|\\   ____\\|\\  \\|\\  \\      \n");
	printf("\\ \\  \\____\\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\___|\\ \\   __/|     \\ \\  \\|\\  \\|___ \\  \\_\\|___ \\  \\_\\ \\  \\|\\  \\ \\  \\___|\\ \\  \\/  /|_   \n");
	printf(" \\ \\_____  \\ \\   ____\\ \\   __  \\ \\  \\    \\ \\  \\_|/__    \\ \\   __  \\   \\ \\  \\     \\ \\  \\ \\ \\   __  \\ \\  \\    \\ \\   ___  \\  \n");
	printf("  \\|____|\\  \\ \\  \\___|\\ \\  \\ \\  \\ \\  \\____\\ \\  \\_|\\ \\    \\ \\  \\ \\  \\   \\ \\  \\     \\ \\  \\ \\ \\  \\ \\  \\ \\  \\____\\ \\  \\\\ \\  \\ \n");
	printf("    ____\\_\\  \\ \\__\\    \\ \\__\\ \\__\\ \\_______\\ \\_______\\    \\ \\__\\ \\__\\   \\ \\__\\     \\ \\__\\ \\ \\__\\ \\__\\ \\_______\\ \\__\\\\ \\__\\ \n");
	printf("   |\\_________\\|__|     \\|__|\\|__|\\|_______|\\|_______|     \\|__|\\|__|    \\|__|      \\|__|  \\|__|\\|__|\\|_______|\\|__| \\|__| \n");
	printf("   \\|_________|\n");
}

int difficulty(){
	int on=1;
	int input2;
	jump(24,10);
	printf("{SELECT DIFFICULTY}");
	jump(24,13);
	printf("easy");
	jump(24,15);
	printf("medium");
	jump(24,17);
	printf("hard");
	jump(20,13);
	printf(">>>");
	
	while(on==1){
	if(kbhit()){
        input2 = getch();
    }
	if(input2==224){
		do {
            input2=getch();
        } while(input2==224);
        
		if(input2==72){           //up
			jump(locatex()-3,locatey());
			printf("   ");
			jump(locatex(),locatey()-2);
			jump(locatex()-3,locatey());
			printf(">>>");
		}
		if(input2==80){           //down
			jump(locatex()-3,locatey());
			printf("   ");
			jump(locatex(),locatey()+2);
			jump(locatex()-3,locatey());
			printf(">>>");	
		}
		if(input2==77){				//right
			on=0;
			if(locatey()==13){
				level=1;
				Beep(300,100);
			}
			if(locatey()==15){
				level=2;
				Beep(300,100);
			}
			if(locatey()==17){
				level=3;
				Beep(300,100);
			}
		}
		}	
	if(locatey()==19){						//if cursor is out of lower boundry
		jump(locatex()-3,locatey());
		printf("   ");
		jump(locatex()-3,17);
		printf(">>>");
	}
	
	if(locatey()==11){						//if cursor is out of upper boundry
		jump(locatex()-3,locatey());
		printf("   ");
		jump(locatex()-3,13);
		printf(">>>");
	}
	}
}

int skins(){
	int on=1;
	int input2;
	jump(28,10);
	printf("{SELECT SKIN}");
	
	jump(24,12);
	printf("----------");
	jump(24,13);		//player1
	printf(" M ");
	jump(24,14);
	printf("-V-");
	jump(24,15);
	printf("----------");
	
	jump(24,16);		//player2
	printf(" O ");
	jump(24,17);
	printf("<Y>");
	jump(24,18);
	printf("----------");
	
	jump(24,19);		//player3
	printf(" ^ ");
	jump(24,20);
	printf("(W)");
	jump(24,21);
	printf("----------");
	
	jump(24,22);		//player4
	printf(" A ");
	jump(24,23);
	printf("dHb");
	jump(24,24);
	printf("----------");
	
	jump(20,13);
	printf(">>>");
	
	while(on==1){
	if(kbhit()){
        input2 = getch();
    }
	if(input2==224){
		do {
            input2=getch();
        } while(input2==224);
        
		if(input2==72){           //up
			jump(locatex()-3,locatey());
			printf("   ");
			jump(locatex(),locatey()-3);
			jump(locatex()-3,locatey());
			printf(">>>");
		}
		if(input2==80){           //down
			jump(locatex()-3,locatey());
			printf("   ");
			jump(locatex(),locatey()+3);
			jump(locatex()-3,locatey());
			printf(">>>");	
		}
		if(input2==77){				//right
			on=0;
			if(locatey()==13){
				skin=1;
				Beep(300,100);
			}
			if(locatey()==16){
				skin=2;
				Beep(300,100);
			}
			if(locatey()==19){
				skin=3;
				Beep(300,100);
			}
			if(locatey()==22){
				skin=4;
				Beep(300,100);
			}
		}
		}	
	if(locatey()==25){						//if cursor is out of lower boundry
		jump(locatex()-3,locatey());
		printf("   ");
		jump(locatex()-3,22);
		printf(">>>");
	}
	
	if(locatey()==10){						//if cursor is out of upper boundry
		jump(locatex()-3,locatey());
		printf("   ");
		jump(locatex()-3,13);
		printf(">>>");
	}
	}
}

int ending_title(){
	
	jump(20,10);
	printf(" ________   ________  _____  ______  _______       \n");
	jump(20,11);
	printf("|\\   ____\\ |\\   __  \\|\\   __ \\  _  \\|\\  ___ \\      \n");
	jump(20,12);
	printf("\\ \\  \\___| \\ \\  \\|\\  \\ \\  \\\\\\__\\ \\  \\ \\   __/|     \n");
	jump(20,13);
	printf(" \\ \\  \\  __ \\ \\   __  \\ \\  \\|__|\\ \\  \\ \\  \\_|/__   \n");
	jump(20,14);
	printf("  \\ \\  \\_\\  \\\\ \\  \\ \\  \\ \\  \\    \\ \\  \\ \\  \\_|\\ \\  \n");
	jump(20,15);
	printf("   \\ \\_______\\\\ \\__\\ \\__\\ \\__\\    \\ \\__\\ \\_______\\ \n");
	jump(20,16);
	printf("    \\|_______| \\|__|\\|__|\\|__|     \\|__|\\|_______| \n\n\n");
	Beep(300,300);
	slow(2);
	jump(20,19);
	printf("\t ________  ___      ___ _______   ________      \n");
	jump(20,20);
	printf("\t|\\   __  \\|\\  \\    /  /|\\  ___ \\ |\\   __  \\     \n");
	jump(20,21);
	printf("\t\\ \\  \\|\\  \\ \\  \\  /  / \\ \\   __/|\\ \\  \\|\\  \\    \n");
	jump(20,22);
	printf("\t \\ \\  \\\\\\  \\ \\  \\/  / / \\ \\  \\_|/_\\ \\   _  _\\   \n");
	jump(20,23);
	printf("\t  \\ \\  \\\\\\  \\ \\    / /   \\ \\  \\_|\\ \\ \\  \\\\  \\   \n");
	jump(20,24);
	printf("\t   \\ \\_______\\ \\__/ /     \\ \\_______\\ \\__\\\\ _\\  \n");
	jump(20,25);
	printf("\t    \\|_______|\\|__|/       \\|_______|\\|__|\\|__| \n");
	Beep(300,300);
}

int instructions(){
	jump(1,1);
	printf("<<<");
	jump(10,5);
	printf(" __________________________________________________________________________");
	jump(10,6);
	printf("|welcome to instructions!                                                  |\n");
	jump(10,7);
	printf("|--------------------------------------------------------------------------|\n");
	jump(10,8);
	printf("|1 ~ player can choose out of 4 skins once the game starts                 |\n");
	jump(10,9);
	printf("|2 ~ player can choose difficulty level once the game starts               |\n");
	jump(10,10);
	printf("|3 ~ OBJECTIVE is to finish enemy swarm before it hits our spaceship       |\n");
	jump(10,11);
	printf("|4 ~ if an enemy laser passes by you ,your life is decreased by one level  |\n");
	jump(10,12);
	printf("|5 ~ number of lives of a spaceship depends on the difficulty level        |\n");
	jump(10,13);
	printf("|6 ~ if player shoots the enemy laser score increases by 100               |\n");
	jump(10,14);
	printf("|7 ~ if player shoots enemy spaceship score increases by 50                |\n");
	jump(10,15);
	printf("|8 ~ player wins if total enemies left are zero                            |\n");
	jump(10,16);	
	printf("|__________________________________________________________________________|");
	jump(60,30);
	printf("MADE BY:");
	jump(60,32);
	printf("yousuf ahmed siddiqui K21~4594");
	jump(60,33);
	printf("syed arhum ");
	jump(60,34);
	printf("taha abbas ");
	jump(60,35);
	printf("muhammad aliyan");
}

int load(){
	int i,ld=0,cnt=0;
	int  ch[36]={177,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176};
	system("cls");
	jump(72,20);
	printf("LOADING..");
	while(cnt<3){
	if(ld==60){
		ld=0;
		cnt++;	
	}
	jump(58,23);
	for(i=0;i<36;i++){
		printf("%c",ch[i]);
	}
	if(ld<=5){
		ch[0]=177;
	}
	else if(ld<=14){
		ch[0]=178;
	}
	else if(ld<=20){
		ch[0]=177;
	}
	else if(ld>20 ){
		ch[0]=176;
	}
	for(i=35;i>=0;i--){
		ch[i+1]=ch[i];
	}
	slow2(2);
	jump(58,23);
	printf("                                   ");
	jump(58,23);
	ld++;
 }
 system("cls");
}


void check(FILE * fPtr){
    int ch,i,n=0;
    int highscore[100]={0};
    for(i=0;i<100000;i++){
//        fscanf(fPtr,"%d",&ch);
//        fscanf(fPtr,"\n");
		if(fscanf(fPtr,"%d",&ch)==EOF){
        Beep(200,200);
		break;
		}
//        printf("\n\t%d ",ch);
     	highscore[i]=ch;
		n++;
	}
	
	for(i=0;i<n;i++){
		if(highscore[i]>gre){
			gre=highscore[i];
		}
	}

}

void readFile(FILE * fPtr){
    char ch;
    do {
        ch = fgetc(fPtr);
        putchar(ch);
    }while(ch != EOF);
}


int main(){
	int x,y;                	//temporary incremental values
	int totenemy=0;				//total enemies present
	int down =0;	             	//if down=1 enemy goes down
	int direction=1;			//if direction=1 enemy goes right       if direction=0 enemy goes left
	int left=0;             	//enemy is in left motion
	int right=1;            	//enemy is in right motion
	int input;              	//var in which player inputs up right left
	int input3;
	int input4;
	int life,score=0;	
	int lasready=0;				//check if the laser shooting button is pressed		
	char world[sizey][sizex];	//world array 
	char player1;
	char player2;
	char player3;
	char player4;
	int gameover=0;				//if gameover =1 then while loop breaks and game is over
	int c=0;
	int mod2=10;					//ye start hojaega agar divisible by 3 hoa tou enemy left ya right jaeng
	int exit=0;
	
	FILE *fPtr;

	
	system("MODE 1000,1000");
	
	
	title();
	starting();
	
	while(menu!=1){
	system("cls");
	
		if(menu==2){
		system("cls");
		instructions();
		while(menu==2){
			if(kbhit()){
        		input3=getch();
        	}
        
    		if(input3==224){
			do {
            	input3=getch();
        	} while(input3==224);
		
			if(input3==75){
				menu=1;
			}
		}
		}
		system("cls");
		}
		
		if(menu==4){
			system("cls");
			exit=1;
			break;	
		}
		
		if(menu==3){
			
			
			fPtr = fopen("HIGHSCORE.txt", "r");
			system("cls");
			printf("<<<<   SCORE BOARD:\n\n\n");
			readFile(fPtr);
			while(menu==3){
			if(kbhit()){
        		input4=getch();
        	}
        
    		if(input4==224){
			do {
            	input4=getch();
        	} while(input3==224);
		
			if(input4==75){
				menu=1;
			}
			
			
			}
			}
			system("cls");
			fclose(fPtr);
		}
		
		title();
		starting();
		
	}
	if(exit==0){
	system("cls");
	difficulty();
	system("cls");
	skins();
	system("cls");	
	
	if(skin==1){
		player1='M';
		player2='-';
		player4='V';
		player3='-';
	}
	if(skin==2){
		player1='O';
		player2='<';
		player4='Y';
		player3='>';
	}
	if(skin==3){
		player1='^';
		player2='(';
		player4='W';
		player3=')';
	}
	if(skin==4){
		player1='A';
		player2='d';
		player4='H';
		player3='b';
	}
	

	
	while(menu==1){
		
	srand(time(0));
	
	jump(72,20);
	load();
	
	
	if(level==1){
		life=15;
	}
	if(level==2){
		life=10;
	}
	if(level==3){
		life=5;
	}
	gameover=0;
	lasready=0;
	score=0;
	totenemy=0;
	down =0;
	direction=1;
	left=0;
	right=1;   
		
	//enemy generation in world at start
	for(y=0;y<sizey;y++){
		for(x=0;x<sizex;x++){
			if( (y%2==0) && y<(sizey/3) && (x>3) && (x<=sizex-4) && (x%2==0) ){
				world[y][x]=enemy;
				totenemy++;
			}
			else {
				world[y][x]= ' ';
			}		
		}
	}
	//player skin generation and spawning place
	world[sizey-2][sizex/2]=player1;
	world[sizey-1][(sizex/2)-1]=player2;
	world[sizey-1][(sizex/2)+1]=player3;
	world[sizey-1][sizex/2]=player4;
	
	
	//the loop which will ficker
	while(totenemy>0 && life>0 && gameover==0 ){
	down=0;		//else zigzag jaega enemy	
	mod2++;
	
	for(x=0;x<sizex;x++){			//yahan par y ka loop esa isliye he kwnk below 3 lines wo loop infinite times chlta rahega phir
		for(y=sizey-1;y>=0;y--){
			if(world[y][x]==enemylaser && world[y+1][x]!=plaser && c%5==0){ //enemy laser trail increases
				world[y+1][x]=enemylaser;
				world[y][x]=' ';
			}
			else if(world[y+1][x]==enemylaser && (y+2==sizey)){
				world[y+1][x]=' ';
				Beep(10000,10);
				life--;
			}
			if(world[y][x]==enemylaser && world[y+1][x]==plaser){
				Beep(300,10);
				score+=100;
			}
		}
	}
	

	
	for(x=0;x<sizex;x++){
		for(y=0;y<sizey;y++){
			if((c%2==0) && (world[y][x]==enemy) && (world [y+2][x] !=enemy) && (x!=sizex-1) && (rand()%5>1) && ((rand()%15)>13) ){  //generates enemy laser only trail run nae hori isme
				world[y+1][x]=enemylaser;
			}
			
			if( world[y][x]==enemylaser && (world[y+1][x]==player1 || world[y+1][x]==player2 || world[y+1][x]==player3 || world[y+1][x]==player4 )){ //if enemy laser hits us on head
				gameover=1;
			}
			else if(world[y][x]==explosion){         			//Explosion check krraha he agar maujood he tou spacebar dalde
				world[y][x]=' ';
			}
			else if(world[y][x]==plaser && world[y-1][x]!=enemy){ //yahan par laser bhaag rahi he lekin wo sirf enemy ke neech aake ruk jaegi
				world[y-1][x]=plaser;
				world[y][x]=' ';
			}
			else if(world[y][x]==plaser && world[y-1][x]==enemy){   //hmari laser enemy par hit hori ,score increases,explosion
				score+=50;
				totenemy--;
				world[y][x]=' ';
				world[y-1][x]=explosion;
				Beep(700,10);
			}
			
			
			
				
			
			
	
	}
	}
	for (y=0;y<sizey;y++){
        if (world[y][0]==enemy){		// if enemy touches left border ,now the upcoming direction is to be to the right and also generates signal to drop down the array 
            direction=1;
            down=1;
            break;
        }
        if (world[y][sizex-1] == enemy){	//if enemy touches right border,now upcoming direction is to be to the left and also generates signal to drop down
            direction=0;
            down=1;							//reminder! direction 1 means to the right  
            break;							//			direction 0 means to the left
        }									//			drop 1 means ke bhai drop down hoja neeche
    }
    if( direction==0){
		if(c%10==0){
   		 for(x=0;x<sizex;x++){
    		for(y=0;y<sizey;y++){
   				if(world[y][x]==enemy &&down==0){
    				world[y][x]=' ';
    				world[y][x-1]=enemy;
				}
				if(world[y][x]==enemy &&down==1){
    				world[y][x]=' ';
    				world[y+1][x-1]=enemy;
				}
			}
		}
		}
	}
    else{
    	if(c%10==0){
   		 for(x=sizex-1;x>=0;x--){
    		for(y=0;y<sizey;y++){
   				if(world[y][x]==enemy &&down==0){
    				world[y][x]=' ';
    				world[y][x+1]=enemy;
				}
				if(world[y][x]==enemy &&down==1){
    				world[y][x]=' ';
    				world[y+1][x+1]=enemy;
				}
			}
		}
		}
	}
	for(x=0;x<sizex;x++){
        if(world[sizey-2][x]==enemy){                       /////agr enemy reach krliya end game tou game ki baj gai phir
            gameover=1;
        }
    }
    
	
	
	
	if(lasready==1){
			for(x=0;x<sizex;x++){					//yahan par plaser player1 ke upar rakhdi he
				if(world[sizey-2][x]==player1){
					world[sizey-3][x]=plaser;
					lasready=0;
					break;
				}				
			}
	}	
	
	
	
	
	
	
	
	
	
	
	
		
	//controls
		if(kbhit()){
            input = getch();
        }
		if(input==224){
		do {
            input=getch();
        } while(input==224);
        
		if(input==77){               //right
				for(x=0;x<sizex;x++){
					if(world[sizey-2][x-2]==player1){
						world[sizey-2][x-1]=player1;
						world[sizey-2][x-2]=' ';
						
						world[sizey-1][x-1]=player4;
						world[sizey-1][x]=player3;
						world[sizey-1][x-2]=player2;
						world[sizey-1][x-3]=' ';

						
						break;
					}
				}
			}
		if(input==75){             //left
				for(x=0;x<sizex;x++){
					if(world[sizey-2][x+2]==player1){
						world[sizey-2][x+2]=' ';
						world[sizey-2][x+1]=player1;
						
						world[sizey-1][x]=player2;
						world[sizey-1][x+1]=player4;
						world[sizey-1][x+2]=player3;
						world[sizey-1][x+3]=' ';
						

						break;
					}
				}
		}
		if(input==72 && mod2>1){
			lasready=1;
			Beep(400,30);
			mod2=0;
		}
	}
	system("cls");
		printf("    LIVE:%d\tSCORE:%d\tTOTAL ENEMY:%d\n\n",life,score,totenemy);
		for(y=0;y<sizey;y++){
			printf("|");
			for(x=0;x<sizex;x++){
				printf("%c",world[y][x]);
			
			}
			printf("|\n");
		}
	if(gameover==1){
		Beep(600,1000);
	}

	c++;

	}//while loop terminates
	
	char ends,name[50];
	int on5=1;//same working as (on) variable
	
	
	
	
    FILE *f;
	
	fPtr = fopen("HIGHSCORE.txt", "a");
    f=fopen("sc.txt","a");
	
	fprintf(f,"%d\n",score);
    
  	f = freopen("sc.txt", "r", f);
  	
  	check(f);
  	
  	fclose(f);
	
	if(totenemy==0){
		system("cls");
		congrats();
		slow(1);
		printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\tYOUR SCORE:%d\tHIGHSCORE:%d",score,gre);
		menu=0;
		jump(20,34);
		printf("enter your name:");
		gets(name);
		fprintf(fPtr,"\n");
  		fputs(name, fPtr);
		fprintf(fPtr,"\t%d",score);
		
	}
	if(gameover==1 ||life <=0){
		system("cls");
		ending_title();
		jump(20,30);
		printf("YOUR SCORE:%d\tHIGHSCORE:%d",score,gre);
		Beep(400,20);
		menu=0;
		jump(20,34);
		printf("enter your name:");
		gets(name);
		fprintf(fPtr,"\n");
 	   fputs(name, fPtr);
		fprintf(fPtr,"\t%d",score);
		
		
		
	}
	fclose(fPtr);
	}//if menu==1

		
	
}
}



