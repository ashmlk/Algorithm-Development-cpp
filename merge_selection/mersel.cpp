//
//
//  Created by ARSHIA on 1/23/20.
//  Copyright © 2020 ARSHIA. All rights reserved.
//

#include <iostream>
#include <map>
#include <ctime>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>

/*
 We will be using two algorithms, merge sort and selection sort
 */

void selectionSort(int array[], int start, int size);
void merselSort(int array[], int size, int start, int end);
void mergeSort(int array[], int start, int end);
void merge(int array[], int p, int q, int r);
void swap(int *p1, int *p2);
void populate(int array[], int n);

/*
 merselSort (Merge & Selection sort) algorithm implementation
 */

void merselSort(int array[], int size, int start, int end){
    int middle; //declare new variable for showing the middle index
    if(start < end){
        middle = (start + end) / 2;
        
        if(end - start > size){
            merselSort(array, size, start, middle-1);
            merselSort(array, size, middle+1, end);
        }
        else{
            selectionSort(array, start, middle);
            selectionSort(array, middle, end);
        }
        
        merge(array, start, middle, end);
    }
}
/*
 Recursive merge sort (Divide and conquer) algorithm
 */

void mergeSort(int array[], int start, int end){
    int middle; //declare new variable for showing the middle index
    if(start < end){
        middle=(start + end) / 2;
        mergeSort(array, start, middle); //recursive approach; apply mergeSort on the firt half of the array
        mergeSort(array, middle + 1, end); //apply meargeSort to second half of the array
        merge(array, start, middle, end); //merge the new arrays
    }
}

/*
 Merge algorithm to combine to sorted arrays together
 */

void merge(int array[], int p, int q, int r){
    int leftIndex = q - p + 1;
    int rightIndex = r - q;
    int i,j,k;
    
    int leftArray[leftIndex+1];
    int rightArray[rightIndex+1];
    
    for(i = 0; i < leftIndex; i++){
        leftArray[i] = array[p+i];
    }
    for(j = 0; j < rightIndex; j++){
        rightArray[i]=array[q+j+1];
    }
    //we use sentinel value to not check if we have reached the end of arrays in every iteration to terminate loop
    leftArray[leftIndex] = INT_MAX;
    rightArray[rightIndex] = INT_MAX;
    
    i=0;
    j=0;
    
    for(k = p; k <= r; k++){
        if(leftArray[i] <= rightArray[j]){
            array[k] = leftArray[i++];
        }
        else{
            array[k] = rightArray[j++];
        }
    }
}

/*
 Selection sort algorithm
 */

void selectionSort(int array[], int start, int size){
    int i,j, minIndex;
        
    for (i = start; i < size-1; i++){
        minIndex = i;
        for (j = i+1; j < size; j++){
            if (array[j] < array[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex!=i){
            swap(&array[minIndex], &array[i]);
        }
    }
}

/*
 Swap function to swap two elements
 */

void swap(int *p1, int *p2){
    int temp=*p1;
    *p1=*p2;
    *p2=temp;
}

/*
 Populate arrays with random variable between 0 to n
 */

void populate(int array[], int n){
    for(int i = 0; i < n; i++){
        array[i] = rand() % (4*n) + 1;
    }
}
int main(int argc, const char * argv[]){
     std::cout << "Running...please wait \n" << std::endl;
    
    //different size of arrays to be sorted, six numbers requested from user
    int n[6] = {10,100,1000,10000,25000,50000};
    
    /*
    std::cout << "Please enter different numbers to set array sizes to be sorted" << std::endl;
    int counter = 0;
    while(counter < 6){
        int var;
        std::cin >> var;
        if(var > 0){
            n[counter] = var;
            counter++;
        }
        else{
            std::cout << "Please enter integer greater than zero" << std::endl;
        }
    }
    */
    
    //Hashmap to save running time of algorithms
    std::map<int, double> timesMergeSort;
    std::map<int, double> timesSelectionSort;
    std::map<int, double> timesMerselSort;
    
    int array1[n[0]];
    populate(array1, n[0]);
    int array2[n[1]];
    populate(array2, n[1]);
    int array3[n[2]];
    populate(array3, n[2]);
    int array4[n[3]];
    populate(array4, n[3]);
    int array5[n[4]];
    populate(array5, n[4]);
    int array6[n[5]];
    populate(array6, n[5]);
    
    //Merge Sort
    clock_t begin_mergeSort_1 = clock();
    mergeSort(array1, 0, n[0] - 1);
    clock_t end_mergeSort_1 = clock();
    timesMergeSort.insert( {n[0], (double(end_mergeSort_1 - begin_mergeSort_1) / CLOCKS_PER_SEC) } );
    
    clock_t begin_mergeSort_2 = clock();
    mergeSort(array2, 0, n[1] - 1);
    clock_t end_mergeSort_2 = clock();
    timesMergeSort.insert( {n[1], (double(end_mergeSort_2 - begin_mergeSort_2) / CLOCKS_PER_SEC) } );
    
    clock_t begin_mergeSort_3 = clock();
    mergeSort(array3, 0, n[2] - 1);
    clock_t end_mergeSort_3 = clock();
    timesMergeSort.insert( {n[2], (double(end_mergeSort_3 - begin_mergeSort_3) / CLOCKS_PER_SEC) } );
    
    clock_t begin_mergeSort_4 = clock();
    mergeSort(array4, 0, n[3] - 1);
    clock_t end_mergeSort_4 = clock();
    timesMergeSort.insert( {n[3], (double(end_mergeSort_4 - begin_mergeSort_4) / CLOCKS_PER_SEC) } );
    
    clock_t begin_mergeSort_5 = clock();
    mergeSort(array5, 0, n[4] - 1);
    clock_t end_mergeSort_5 = clock();
    timesMergeSort.insert( {n[4], (double(end_mergeSort_5 - begin_mergeSort_5) / CLOCKS_PER_SEC) } );
    
    clock_t begin_mergeSort_6 = clock();
    mergeSort(array6, 0, n[5] - 1);
    clock_t end_mergeSort_6 = clock();
    timesMergeSort.insert( {n[5], (double(end_mergeSort_6 - begin_mergeSort_6) / CLOCKS_PER_SEC) } );
    
    //Selection Sort
    clock_t begin_selectionSort_1 = clock();
    selectionSort(array1, 0, n[0] - 1);
    clock_t end_selectionSort_1 = clock();
    timesSelectionSort.insert( {n[0], (double(end_selectionSort_1 - begin_selectionSort_1) / CLOCKS_PER_SEC) } );
    
    clock_t begin_selectionSort_2 = clock();
    selectionSort(array2, 0, n[1] - 1);
    clock_t end_selectionSort_2 = clock();
    timesSelectionSort.insert( {n[1], (double(end_selectionSort_2 - begin_selectionSort_2) / CLOCKS_PER_SEC) } );
    
    clock_t begin_selectionSort_3 = clock();
    selectionSort(array3, 0, n[2] - 1);
    clock_t end_selectionSort_3 = clock();
    timesSelectionSort.insert( {n[2], (double(end_selectionSort_3 - begin_selectionSort_3) / CLOCKS_PER_SEC) } );
    
    clock_t begin_selectionSort_4 = clock();
    selectionSort(array4, 0, n[3] - 1);
    clock_t end_selectionSort_4 = clock();
    timesSelectionSort.insert( {n[3], (double(end_selectionSort_4 - begin_selectionSort_4) / CLOCKS_PER_SEC) } );
    
    clock_t begin_selectionSort_5 = clock();
    selectionSort(array5, 0, n[4] - 1);
    clock_t end_selectionSort_5 = clock();
    timesSelectionSort.insert( {n[4], (double(end_selectionSort_5 - begin_selectionSort_5) / CLOCKS_PER_SEC) } );
    
    clock_t begin_selectionSort_6 = clock();
    selectionSort(array6, 0, n[5] - 1);
    clock_t end_selectionSort_6 = clock();
    timesSelectionSort.insert( {n[5], (double(end_selectionSort_6 - begin_selectionSort_6) / CLOCKS_PER_SEC) } );
    
    //Combined Sort (Mersel Sort)
    clock_t begin_merselSort_1 = clock();
    merselSort(array1, n[0] - 1, 0, n[0] - 1);
    clock_t end_merselSort_1 = clock();
    timesMerselSort.insert( {n[0], (double(end_merselSort_1 - begin_merselSort_1) / CLOCKS_PER_SEC) } );
    
    clock_t begin_merselSort_2 = clock();
    merselSort(array2, n[1] - 1, 0, n[1] - 1);
    clock_t end_merselSort_2 = clock();
    timesMerselSort.insert( {n[1], (double(end_merselSort_2 - begin_merselSort_2) / CLOCKS_PER_SEC) } );
    
    clock_t begin_merselSort_3 = clock();
    merselSort(array3, n[2] - 1, 0, n[2] - 1);
    clock_t end_merselSort_3 = clock();
    timesMerselSort.insert( {n[2], (double(end_merselSort_3 - begin_merselSort_3) / CLOCKS_PER_SEC) } );
    
    clock_t begin_merselSort_4 = clock();
    merselSort(array4, n[3] - 1, 0, n[3] - 1);
    clock_t end_merselSort_4 = clock();
    timesMerselSort.insert( {n[3], (double(end_merselSort_4 - begin_merselSort_4) / CLOCKS_PER_SEC) } );
    
    clock_t begin_merselSort_5 = clock();
    merselSort(array5, n[4] - 1, 0, n[4] - 1);
    clock_t end_merselSort_5 = clock();
    timesMerselSort.insert( {n[4], (double(end_merselSort_5 - begin_merselSort_5) / CLOCKS_PER_SEC) } );
    
    clock_t begin_merselSort_6 = clock();
    merselSort(array6, n[5] - 1, 0, n[5] - 1);
    clock_t end_merselSort_6 = clock();
    timesMerselSort.insert( {n[5], (double(end_merselSort_6 - begin_merselSort_6) / CLOCKS_PER_SEC) } );
    
    using std::setw;
    std::cout << std::left;
    std::cout << "Results:" << '\n' << '\n' <<
    setw(25) << "Size" << setw(10) << n[0] << setw(10) << n[1] <<  setw(10) << n[2] << setw(10) << n[3] <<  setw(10) << n[4] << setw(10) << n[5] <<'\n' <<
    setw(25) << "Merge Sort" << setw(10) << timesMergeSort[n[0]] << setw(10) << timesMergeSort[n[1]] <<  setw(10) << timesMergeSort[n[2]] << setw(10) <<
    timesMergeSort[n[3]] << setw(10) << timesMergeSort[n[4]] << setw(10) << timesMergeSort[n[5]] <<'\n' <<
    setw(25) << "Selection Sort" << setw(10) << timesSelectionSort[n[0]] << setw(10) << timesSelectionSort[n[1]] <<  setw(10) << timesSelectionSort[n[2]] << setw(10) <<
    timesSelectionSort[n[3]] << setw(10) << timesSelectionSort[n[4]] << setw(10) << timesSelectionSort[n[5]] <<'\n' <<
    setw(25) << "Combined Search" << setw(10) << timesMerselSort[n[0]] << setw(10) << timesMerselSort[n[1]] << setw(10) << timesMerselSort[n[2]] << setw(10) <<
    timesMerselSort[n[3]] <<  setw(10) << timesMerselSort[n[4]] << setw(10) << timesMerselSort[n[5]] <<'\n' << '\n';
    
    return 0;
}
