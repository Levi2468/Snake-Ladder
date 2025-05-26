#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>
class all{
public:
void space(int s){
for(int o=0;o<s;o++){
cout<<"   ";
}
}
void basic(){
clrscr();
space(10);
cout<<"Snake and Ladders"<<endl;
}
void welcome(){
space(8);
cout<<"WELCOME TO SNAKES AND LADDERS\n"<<endl;
cout<<"instructions:\n"<<endl;
cout<<"Ladders # moves player 7 steps forwards\n"<<endl;
cout<<"Snakes  S moves player 6 steps backwards\n"<<endl;
cout<<"Press q  to quit the game\n"<<endl;
cout<<"roll 1 at end to win\n"<<endl;
space(9);
cout<<"press  any key to enter "<<endl;
getch();
}

int winner(int p01,int p02,int temp1,int temp2,int choose){
if(p01==99 && temp1==1 && choose==0){
space(11);
cout<<"Player  1 got 1"<<endl;
space(12);
cout<<"Player 1 win";
getch();
return 0;
}else if(p02==99 && temp2==1 && choose==1){
space(11);
cout<<"Player  2 got 1"<<endl;
space(12);
cout<<"Player 2 win";
getch();
return 0;
}else{
  return 1;
}

}

void commentry(int p01,int p02){
if(p01==7||p01==35||p01==56||p01==70){
cout<<"Player 1 got ladder +7"<<endl;
}
if(p02==7||p02==35||p02==56||p02==70){
cout<<"Player 2 got ladder +7"<<endl;
}
if(p01==10||p01==21||p01==40||p01==82||p01==95){
cout<<"Player 1 bite by snake -6"<<endl;
}
if(p02==10||p02==21||p02==40||p02==82||p02==95){
cout<<"Player 2 bite by snake -6"<<endl;
}

}

};
int main(){
clrscr();
all sl;
int p01=0,p02=0,temp1=0,temp2=0,control=1,choose=0;
char tiles[100],quit;
srand(time(0));
sl.welcome();
clrscr();
while(control==1){
sl.basic();
temp1=((rand()%6)+1);
temp2=((rand()%6)+1);
control=sl.winner(p01,p02,temp1,temp2,choose);
if(control==0){
continue;
}
if(choose==1){
cout<<"Player 2 turn"<<endl;
cout<<"press any key to roll dice";
getch();
cout<<"....Rolling dice...."<<endl;
delay(1000);
cout<<"Player 2 got "<<temp2<<endl;
p02=p02+temp2;
if(p02>=99){
p02=99;
}
choose--;
}else{
cout<<"Player 1 turn"<<endl;
cout<<"press any key to roll die";
getch();
cout<<"....Rolling dice...."<<endl;
delay(1000);
cout<<"Player 1 got "<<temp1<<endl;
p01=p01+temp1;
if(p01>=99){
p01=99;
}
choose++;
}

sl.commentry(p01,p02);

for(int i=100;i>0;i--){
if(i%10==0){
cout<<endl;
for(int j=0;j<=38;j++){
cout<<"-";
}
cout<<endl;
}
tiles[i]=' ';
if(i==7||i==35||i==56||i==70){
tiles[i]='#';
}
if(i==10||i==21||i==40||i==82||i==95){
tiles[i]='S';
}

if(i==p01){
tiles[i]='1';
}
if(i==p02){
tiles[i]='2';
}
if(p01==7||p01==35||p01==56||p01==70){
p01=p01+7;
}
if(p02==7||p02==35||p02==56||p02==70){
p02=p02+7;
}
if(p01==10||p01==21||p01==40||p01==82||p01==95){
p01=p01-6;
}
if(p02==10||p02==21||p02==40||p02==82||p02==95){
p02=p02-6;
}

cout<<tiles[i]<<" | ";
}
quit=getch();
if(quit=='q'){
control=0;
}
}
if(quit=='q'){
sl.space(8);
cout<<"\n\nclick any key to leave the game";
}
getch();
return 0;
}
