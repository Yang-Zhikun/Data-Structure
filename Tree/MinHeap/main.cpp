#include"MinHeap.h"
#include<iostream>
#include<time.h>
using namespace std;

int main() { 
     int arr[200]; 
     srand(time(0)); 
     for(int i=0;i<=100;i++){ 
         arr[i] = rand()%100; 
         cout<<arr[i]<<' '; 
     } 
     cout<<'\n'; 
     MinHeap<int> heap(arr, 101); 
     heap.print(); 
     while(!heap.isEmpty()){ 
         cout<<heap.pop()<<endl; 
     } 
     system("pause"); 
 }