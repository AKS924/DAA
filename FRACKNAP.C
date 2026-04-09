#include<stdio.h>
#include<conio.h>
void main()
{
 int w=80;
 int wt[]={10,30,20,18,12,55,3,34};
 int val[]={10,23,12,16,19,23,13,15};
 float ratio[3];
 float total=0;
 int i;
 clrscr();
 for(i=0;i<3;i++)
 {
   ratio[i]=(float)val[i]/wt[i];
 }
 for(i=0;i<3;i++)
 {
   if(w>=wt[i]){
     w-=wt[i];
     total+=val[i];
 }
   else
   {
    total+=ratio[i]*w;
    break;
   }
 }
 printf("maximum benfits=%.2f",total);
 getch();
}