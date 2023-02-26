// **************************************************************************
//  File       [sort_tool.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The implementation of the SortTool Class]
//  Modify     [2020/9/15 Mu-Ting Wu]
// **************************************************************************

#include "sort_tool.h"
#include<iostream>

// Constructor
SortTool::SortTool() {}

// Insertsion sort method
void SortTool::InsertionSort(vector<int>& data) {
    // Function : Insertion sort
    // TODO : Please complete insertion sort code here
    //cout<<data.size()<<endl;
    for(int i=0; i<data.size(); i++)
    {
      int temp_i=i;
      while(temp_i>0)
      {
        
        if(data[temp_i]<data[temp_i-1])
        swap(data[temp_i],data[temp_i-1]);
        temp_i--;
        
      }
    }
}//FINISHED okokok

// Quick sort method
void SortTool::QuickSort(vector<int>& data){
    QuickSortSubVector(data, 0, data.size() - 1);
}
// Sort subvector (Quick sort)
void SortTool::QuickSortSubVector(vector<int>& data, int low, int high) {
    if(low<high)
    {int q= Partition_rand(data,low,high);
    QuickSortSubVector(data,low ,q-1);
    QuickSortSubVector(data,q+1,high);
    }
    // Function : Quick sort subvector
    // TODO : Please complete QuickSortSubVector code here
    // Hint : recursively call itself
    //        Partition function is needed
    
}//FINISHED okokok
int SortTool::Partition_rand (vector<int>& data ,int low ,int high)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);
    swap(data[random], data[high]);
    return Partition(data, low, high);
}
int SortTool::Partition(vector<int>& data, int low, int high) {
    // Function : Partition the vector 
    // TODO : Please complete the function
    // Hint : Textbook page 171 
    int pivot=data[high];
    int lptr=low-1;
    for(int rptr=low; rptr<high; rptr++ )
    {
        if(data[rptr]<pivot)
           {
            lptr++;
            swap(data[lptr],data[rptr]);
           }
    }
    swap(data[lptr+1],data[high]);
    return lptr+1;
    

}//FINISHED okokok

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
        int mid1=(low+high)/2;
        int mid2=mid1+1;
        MergeSortSubVector(data,low,mid1);
        MergeSortSubVector(data,mid2,high);
        Merge(data,low,mid1,mid2,high);
    }
    
}//FINISHED okokoko

// Merge use in place merge sort to avoid punishment
//or simple merge ??
void SortTool::Merge(vector<int>& data, int low, int middle1, int middle2, int high) {
    // Function : Merge two sorted subvector
    // TODO : Please complete the function
    int n_left=middle1-low+1,n_right=high-middle2+1;
    int *left_arr = new int[n_left];
    int *right_arr = new int[n_right];
    for(int i=0; i<n_left; i++ )
      left_arr[i]=data[low+i];
    for(int i=0; i<n_right; i++ )
      right_arr[i]=data[middle2+i];
    int lptr=0 ,rptr=0;
    int kptr=low;
    while (lptr<n_left&&rptr<n_right){  
        if (left_arr[lptr] <= right_arr[rptr])  {  
            data[kptr] = left_arr[lptr];  
            lptr++;  
        }     
        else{     
            data[kptr] = right_arr[rptr];  
            rptr++;  
        }  
        kptr++;  
    }  
    while (lptr<n_left)  {  
        data[kptr] = left_arr[lptr];  
        lptr++;  kptr++;    
    }  
    while (rptr<n_right){  
        data[kptr] = right_arr[rptr];  
        rptr++;  kptr++;  
    }  
    delete[] left_arr;
    delete[] right_arr;
    
}
//FINISHED-only for in place okokokokok

// Heap sort method
void SortTool::HeapSort(vector<int>& data) {
    // Build Max-Heap
    heapSize=data.size();
    BuildMaxHeap(data);
    //cout<<"heapSize="<<data.size()<<endl;
    // 1. Swap data[0] which is max value and data[i] so that the max value will be in correct location
    // 2. Do max-heapify for data[0]
    for (int i = heapSize- 1; i > 0; i--) {
        swap(data[0],data[i]);
        heapSize=i;
        //cout<<"heapSize="<<heapSize<<endl;
        MaxHeapify(data,0);
        
    }
}

//Max heapify
void SortTool::MaxHeapify(vector<int>& data, int root) {
    // Function : Make tree with given root be a max-heap if both right and left sub-tree are max-heap
    // TODO : Please complete max-heapify code here
    int left_child=root*2+1;
    int right_child=root*2+2;
    int largest=root;
    if (left_child<heapSize && data[left_child]>data[largest])
       largest=left_child;
    if(right_child<heapSize && data[right_child]>data[largest])
       largest=right_child;
    if(largest!=root)
    {
        swap(data[root],data[largest]);
        MaxHeapify(data,largest);
    }
    
}//FINISHED

//Build max heap
void SortTool::BuildMaxHeap(vector<int>& data) {
    heapSize = data.size();
    //heapSize=32000;
    for(int i= heapSize/2-1; i>=0; i--)
    {
        MaxHeapify(data,i);
    }
     // initialize heap size
    // Function : Make input data become a max-heap
    // TODO : Please complete BuildMaxHeap code here
}//???????????????????????????

void SortTool::swap(int &data1 ,int &data2)
{
     int temp=data1;
     data1=data2;
     data2=temp;
}
