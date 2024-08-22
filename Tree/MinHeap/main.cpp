#include"MinHeap.h"
#include<iostream>

int main() { 
     int arr[200]; 
     srand(time(0)); 
     for(int i=0;i<=10;i++){ 
         arr[i] = rand()%10; 
         cout<<arr[i]<<' '; 
     } 
     cout<<'\n'; 
     MinHeap<int> heap(arr, 11); 
     heap.print(); 
     while(!heap.isEmpty()){ 
         cout<<heap.pop()<<endl; 
     } 
     system("pause"); 
 }