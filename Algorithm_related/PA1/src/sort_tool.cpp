// **************************************************************************
//  File       [sort_tool.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The implementation of the SortTool Class]
//  Modify     [2020/9/15 Mu-Ting Wu]
// **************************************************************************

#include "sort_tool.h"
#include<iostream>
#include <stdlib.h> /* 亂數相關函數 */
#include <time.h>   /* 時間相關函數 */
// Constructor
SortTool::SortTool() {}

// Insertsion sort method
void SortTool::InsertionSort(vector<int>& data) {
    // Function : Insertion sort
    // TODO : Please complete insertion sort code here
    for(int i=1; i<data.size(); i++)
    {
        int key = data[i];
            int j = i-1;
            while(data[j]>key && j>0 )
            {
                data[j+1]=data[j];
                j=j-1;
            }
         data[j+1]=key;
    }
}

// Quick sort method
void SortTool::QuickSort(vector<int>& data){
    QuickSortSubVector(data, 0, data.size() - 1);
}
// Sort subvector (Quick sort)
void SortTool::QuickSortSubVector(vector<int>& data, int low, int high) {
    // Function : Quick sort subvector
    // TODO : Please complete QuickSortSubVector code here
    // Hint : recursively call itself
    //        Partition function is needed
     if(low<high)
    {
        int partition_pivot=Partition(data,low,high);
        QuickSortSubVector(data,low ,partition_pivot);
        QuickSortSubVector(data,partition_pivot+1,high);
    }
}
int SortTool::RandomPartition(vector<int>& data,int low,int high)
{

}
int SortTool::Partition(vector<int>& data, int low, int high) {
    // Function : Partition the vector 
    // TODO : Please complete the function
    // Hint : Textbook page 171
   int x=data[high];
   int i=low-1;
   for(int j=low; j<=high-1; j++)
   {
            if( data[j]<=x)
            {
                i++;
                swap(data[i],data[j]);
            }
           
   }
    swap(data[i+1],data[high]);
    return i+1;
}

// Merge sort method
void SortTool::MergeSort(vector<int>& data){
    MergeSortSubVector(data, 0, data.size() - 1);
}

// Sort subvector (Merge sort)
void SortTool::MergeSortSubVector(vector<int>& data, int low, int high) {
    // Function : Merge sort subvector
    // TODO : Please complete MergeSortSubVector code here
    // Hint : recursively call itself
    //        Merge function is needed
   if(low<high)
   {
    int middleOne=(low+high)/2;
    int middleTwo=middleOne+1;
    MergeSortSubVector(data,low,middleOne);
    MergeSortSubVector(data,middleTwo,high);
    Merge(data,low,middleOne,middleTwo,high);
   }
}

// Merge
void SortTool::Merge(vector<int>& data, int low, int middle1, int middle2, int high) {
    // Function : Merge two sorted subvector
    // TODO : Please complete the function
     int n1=middle2-low;
     int n2=high-middle1;
     int *Larray=new int(n1+1);
     int *Rarray=new int(n2+1);
     for(int i=0; i<=n1; i++)
        Larray[i]=0;
     for(int i=0; i<n1; i++)
          Larray[i]=data[low+i-1];
     Larray[n1]=INT32_MAX;
     for(int i=0; i<=n2; i++)
        Rarray[i]=0;
    for(int i=0; i<n2; i++)
            Rarray[i]=data[middle1+i] ;
    Rarray[n2]=INT32_MAX;
    int lptr=0,rptr=0;
    for(int ptr=low; ptr<=high; ptr++)
    {
        if (Larray[lptr]<=Rarray[rptr])
             {data[ptr]=Larray[lptr]; 
             lptr++;
             }
        else 
          {data[ptr]=Rarray[rptr]; 
             rptr++;
             }
    }
     
}

// Heap sort method
void SortTool::HeapSort(vector<int>& data) {
    // Build Max-Heap
    BuildMaxHeap(data);
    // 1. Swap data[0] which is max value and data[i] so that the max value will be in correct location
    // 2. Do max-heapify for data[0]
    for (int i = data.size() - 1; i >= 1; i--) {
        swap(data[0],data[i]);
        heapSize--;
        MaxHeapify(data,0);
    }
}

//Max heapify
void SortTool::MaxHeapify(vector<int>& data, int root) {
    // Function : Make tree with given root be a max-heap if both right and left sub-tree are max-heap
    // TODO : Please complete max-heapify code here
   
}

//Build max heap
void SortTool::BuildMaxHeap(vector<int>& data) {
    heapSize = data.size(); // initialize heap size
    // Function : Make input data become a max-heap
    // TODO : Please complete BuildMaxHeap code here
     for(int i=heapSize/2-1; i>=0; i--)
     {
        MaxHeapify(data,i);
     }

}
void  SortTool::swap(int a ,int b){
   int temp=a;
   b=a;
   a=temp;
}