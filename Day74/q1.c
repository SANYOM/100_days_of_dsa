/*
Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

Input Format
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names.

Output Format
Print the name of the winning candidate followed by the number of votes received.

Sample Input
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

Sample Output
john 4

Explanation
Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Candidate {
    char name[100];
    int votes;
};

int main(){
    int n;
    scanf("%d",&n);
    char s[100];
    struct Candidate arr[n];
    int size=0;

    for(int i=0;i<n;i++){
        scanf("%s",s);
        int found=0;
        for(int j=0;j<size;j++){
            if(strcmp(arr[j].name,s)==0){
                arr[j].votes++;
                found=1;
                break;
            }
        }
        if(!found){
            strcpy(arr[size].name,s);
            arr[size].votes=1;
            size++;
        }
    }

    char winner[100];
    int maxVotes=-1;
    for(int i=0;i<size;i++){
        if(arr[i].votes>maxVotes || 
           (arr[i].votes==maxVotes && strcmp(arr[i].name,winner)<0)){
            maxVotes=arr[i].votes;
            strcpy(winner,arr[i].name);
        }
    }

    printf("%s %d\n",winner,maxVotes);
    return 0;
}
