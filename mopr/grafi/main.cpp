#include<iostream>
#include<stdio.h>
#include <fstream>
#include <sstream>
using namespace std;
#define INFINITY 9999
const int maxx = 5;
// int get_matrix_size();


void dijkstra(int G[maxx][maxx],int n,int startnode);

int createMatrix(int G[maxx][maxx], int maxx);

// int get_matrix_size(){
//   ifstream file("a.txt");
//   string line;
//   getline(file, line);
//   stringstream s;
//   s << line;
//
//   int columns = 0;
//   double value;
//
//   while(s >> value) columns++;
//
//   // cout << columns;
//   file.close();
//   const int maxx = columns;
//   return columns;
// }

int main() {
   // printf("%d\n", get_matrix_size());
   // int get_matrix_size();
   int G[maxx][maxx];
   createMatrix(G, maxx);
   int n=5;
   int u=0;
   dijkstra(G,n,u);
   return 0;
}

int createMatrix(int G[maxx][maxx], int maxx){
  ifstream in("a.txt");

  for (int i = 0; i < maxx; i++){
    for (int j = 0; j < maxx; j++){
        in >> G[i][j];
    }
  }
  return G[maxx][maxx];
}

void dijkstra(int G[maxx][maxx], int n, int startnode) {
   int cost[maxx][maxx], distance[maxx], pred[maxx];
   int visited[maxx], count, mindistance, nextnode, i, j;
   for(i=0; i<n; i++)
      for(j=0; j<n; j++)
   if(G[i][j] == 0)
      cost[i][j] = INFINITY;
   else
      cost[i][j] = G[i][j];
   for(i=0; i<n; i++) {
      distance[i] = cost[startnode][i];
      pred[i] = startnode;
      visited[i] = 0;
   }
   distance[startnode] = 0;
   visited[startnode] = 1;
   count = 1;
   while(count < n-1) {
      mindistance = INFINITY;
      for(i=0; i<n; i++)
         if(distance[i] < mindistance &&! visited[i]) {
         mindistance = distance[i];
         nextnode = i;
      }
      visited[nextnode] = 1;
      for(i=0; i<n; i++)
         if(!visited[i])
      if(mindistance + cost[nextnode][i] < distance[i]) {
         distance[i] = mindistance + cost[nextnode][i];
         pred[i] = nextnode;
      }
      count++;
   }
   for(i=0; i<n; i++)
   if(i != startnode) {
      cout<<"\nDistance of node"<<i<<" = "<<distance[i];
      cout<<"\nPath= "<<i;
      j = i;
      do {
         j = pred[j];
         cout<<" <- "<<j;
      } while(j != startnode);
   }
}
