#include <DOS.H>
#include <STDIO.H>
#include <CONIO.H>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
int hor_num;
int ver_num;

void drawline(int hor,int ver,int blue){
union REGS in1,out1;
in1.h.ah = 0x0C;
in1.h.al=blue;
in1.x.bx=0;
in1.x.cx = hor;
in1.x.dx= ver;
int86(0x10,&in1,&out1);  }

void clean(){
union REGS a_in,a_out;
a_in.x.ax=0x0060;
a_in.h.bh=7;
a_in.x.cx =0;
a_in.x.dx= 0x184f;
int86(0x10, &a_in,&a_out);}

void drawgridhorizontal(int horizontal){

int distance1= 381;
if(horizontal>=2){
distance1= 380/(horizontal-1);}

for (int y=50;y<=430; y+=distance1)
	for (int i=50;i<=590; i++)
   	drawline(i,y,1 );}

void drawgridvertical(int vertical){

int distance2= 541;
if(vertical>=2){
distance2= 540/(vertical-1);}

for (int i=50;i<=590; i+=distance2 )
	for (int y=50;y<=430; y++)
   	drawline(i,y,1);}

void get_num(){
	cout<<"Welcome to the Grid Program";
	cout<<"\nPlease input the number of your horizontal lines? (0-99)=";
	cin>>hor_num;
	while(hor_num<0 || hor_num>99){
	cin.clear();
	cout<<"it should be 0-99,try again: ";
	cin>>hor_num;}
	cout<<"Please input the number of your vertical lines? (0-99)=";
	cin>>ver_num;
	while(ver_num<0 || ver_num>99){
	cin.clear();
	cout<<"it should be 0-99,try again: ";
	cin>>ver_num;}
	cout << "Now I will draw your "<<hor_num<<"x"<<ver_num<<" grid. Thank you :)";
	cout<<"\nI am going to clean the screen and then start drawing your Grid. ";
	cout<<"\nPlease press any key to start the drawing operation! ";}
int main(){

union REGS in2,out2;
in2.h.ah=0 ;
in2.h.al=0x12;
int86(0x10,&in2,&out2) ;


get_num();
getch();
clean();

in2.h.ah=0 ;
in2.h.al=0x12;
int86(0x10,&in2,&out2) ;


if(hor_num>0){
drawgridhorizontal(hor_num);}
if(ver_num>0){
drawgridvertical(ver_num) ;}
getch();
exit(0);
}