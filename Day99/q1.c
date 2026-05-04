/*
Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
Sort cars by position in descending order and calculate time to reach target.
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int pos,speed;
}Car;

int cmp(const void* a,const void* b){
    return ((Car*)b)->pos-((Car*)a)->pos;
}

int carFleets(int target,Car cars[],int n){
    qsort(cars,n,sizeof(Car),cmp);
    int fleets=0; double lastTime=0;
    for(int i=0;i<n;i++){
        double time=(double)(target-cars[i].pos)/cars[i].speed;
        if(time>lastTime){
            fleets++;
            lastTime=time;
        }
    }
    return fleets;
}

int main(){
    int n,target; scanf("%d%d",&n,&target);
    Car cars[n];
    for(int i=0;i<n;i++)scanf("%d%d",&cars[i].pos,&cars[i].speed);
    printf("%d\n",carFleets(target,cars,n));
    return 0;
}
