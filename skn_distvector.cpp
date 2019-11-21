//5. Write a program for distance vector algorithm to find suitable path for transmission

/*
Distance Vector Routing in this program is implemented using Bellman Ford Algorithm:-
*/
#include <iostream>
using namespace std;

struct node{
    unsigned dist[20];
    unsigned from[20];
}rt[10];

int main(){
    	int costmat[20][20];
    	int nodes,i,j,k,count=0;
	cout<<"\nEnter the number of nodes : ";
    	cin>>nodes;//Enter the nodes
    	cout<<"\nEnter the cost matrix :\n";
    	for(i=0;i<nodes;i++) {
        	for(j=0;j<nodes;j++){
            		scanf("%d",&costmat[i][j]);
            		costmat[i][i]=0;
            		rt[i].dist[j]=costmat[i][j];//initialise the distance equal to cost matrix
            		rt[i].from[j]=j;
        	}//end of loop
    	}//end of loop
        do{
            count=0;
            for(i=0;i<nodes;i++)//We choose arbitary vertex k and we calculate the direct distance from the node i to k using the cost matrix
            //and add the distance from k to node j
            	for(j=0;j<nodes;j++)
           	 	for(k=0;k<nodes;k++)
                		if(rt[i].dist[j]>costmat[i][k]+rt[k].dist[j])
                		{//We calculate the minimum distance
                    			rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
                    			rt[i].from[j]=k;
                    			count++;
                		}//end of if
        }while(count!=0);
        
        for(i=0;i<nodes;i++){
            cout<<"\n\n For router"<<i+1<<"  :\n";
            for(j=0;j<nodes;j++)
                cout<<"\t\nnode"<< j+1<<" via "<< rt[i].from[j]+1 <<"Distance "<< rt[i].dist[j] ;
        }//end of loop
    cout<<"\n\n";
    return 0;
}//end of main

/*
OUTPUT:
Enter the number of nodes : 3

Enter the cost matrix :
0 2 7
2 0 1
7 1 0


 For router1  :
	
node1 via 1 Distance 0	
node2 via 2 Distance 2	
node3 via 2 Distance 3

 For router2  :
	
node1 via 1 Distance 2	
node2 via 2 Distance 0	
node3 via 3 Distance 1

 For router3  :
	
node1 via 2 Distance 3	
node2 via 2 Distance 1	
node3 via 3 Distance 0
*/
