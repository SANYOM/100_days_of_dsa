/*
Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i² jumps.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define EMPTY -1

int hash(int key,int m){return key%m;}

int insert(int table[],int m,int key){
    int h=hash(key,m);
    for(int i=0;i<m;i++){
        int pos=(h+i*i)%m;
        if(table[pos]==EMPTY){
            table[pos]=key;
            return 1;
        }
    }
    return 0;
}

int search(int table[],int m,int key){
    int h=hash(key,m);
    for(int i=0;i<m;i++){
        int pos=(h+i*i)%m;
        if(table[pos]==EMPTY) return 0;
        if(table[pos]==key) return 1;
    }
    return 0;
}

int main(){
    int m,q;
    scanf("%d",&m);
    scanf("%d",&q);
    int table[m];
    for(int i=0;i<m;i++) table[i]=EMPTY;
    for(int i=0;i<q;i++){
        char op[10]; int key;
        scanf("%s%d",op,&key);
        if(strcmp(op,"INSERT")==0) insert(table,m,key);
        else if(strcmp(op,"SEARCH")==0){
            if(search(table,m,key)) printf("FOUND\n");
            else printf("NOT FOUND\n");
        }
    }
    return 0;
}
