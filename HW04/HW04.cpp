//// HW04 ////
#include <iostream>
#include <fstream> 
#include <stdexcept>
#include <chrono>
#include <cmath> 
#include <string>
using namespace std; 

// Problme01
/*Make 3 Algorithms Insertion, Heap, and Quick Sort*/

// Declare Global Variables
int moves = 0;
int comps = 0;

// Insertion Sort
void Insertion(int Arr[], int Insert_size){
/*Make Insertion Sort Algorithm*/
    for (int i=1; i<Insert_size; ++i){
        int key = Arr[i];
        int j = i-1;

        while(j>=0){
            /*Tract the moves and comps and switch the big element*/
            comps += 1;
            if (Arr[j]>key){
                /*
                Scan the bigger value and switch
                When search is done, exit the loop 
                */
                moves+=1; 
                Arr[j+1] = Arr[j]; 
                j -= 1;
            }else break; 
        }
        Arr[j+1] = key; 
    }
}

// Heap Sort
/*Construct Max Binary Tree*/
int Left(int i){
    /*(+1) because index starts at 0*/
    return 2*i+1; 
}

int Right(int i){
    return 2*i+2;
}

void Find_max(int Arr[], int i, int heap_size){
    int l = Left(i); 
    int r = Right(i); 
    int max; 

    /*Compare element i with Left i*/
    comps += 1;
    if (l<heap_size && Arr[l]>Arr[i]){
        max = l; 
    }else{
        max = i; 
    }

    /*Compare element i with Right i*/
    comps += 1;
    if (r<heap_size && Arr[r]>Arr[max]){
        max = r; 
    }

    /*Set the max to the root*/
    if (max!=i){
        int pr = Arr[i]; 
        Arr[i] = Arr[max]; 
        Arr[max] = pr;
        moves += 3;

        Find_max(Arr, max, heap_size);
    }
}

/*Build Find_max*/
void Build_Find_max(int Arr[], int heap_size){
    /*Find the parent index of deepeset level and compare elements*/
    for (int i=ceil(heap_size/2)-1; i>-1; --i){
        Find_max(Arr, i, heap_size); 
    }
}

/*Heap Sort main*/
 void Heap(int Arr[], int heap_size){
    /*Call Build_Find_max to build tree*/
    Build_Find_max(Arr, heap_size); 

    /*Switch Root element and the last element*/
    for (int i=heap_size-1; i>0; --i){
        int pr = Arr[0]; 
        Arr[0] = Arr[i]; 
        Arr[i] = pr; 
        moves += 3; 

        /*Rearrange Tree to find max except sorted value*/
        heap_size -= 1; 
        Find_max(Arr, 0, heap_size); 
    }
}

// Quick Sort 
/*Build Partition*/
int Partition(int Arr[], int p, int r){
    int x = Arr[r]; 
    int i = p-1; 

    /*Compare the elements to pivot and switch*/
    for (int j=p; j<r; ++j){
        /*Compare the elements*/ 
        comps += 1; 
        if (Arr[j]<=x){
            i += 1; 
            int pr1 = Arr[j]; 
            Arr[j] = Arr[i]; 
            Arr[i] = pr1; 
            moves += 3; 
        }
    }
    /*Move pivot to correct place*/ 
    int pr2 = Arr[r]; 
    Arr[r] = Arr[i+1]; 
    Arr[i+1] = pr2; 
    moves += 3; 

    return i+1;
}

void Quick_sort(int Arr[], int p, int r){
    /*Devide array into two parts*/
    if (p<r){
        int q = Partition(Arr, p, r); 
        Quick_sort(Arr, p, q-1); 
        Quick_sort(Arr, q+1, r); 
    }
}

 void Check_result(int Arr[], int size, string name){
    /*Check the results that function is correct or wrong*/
    bool coin=true; 
    for (int i=0; i<size-1; ++i){
        /*Compare i and i+1 elements to check*/
        if (Arr[i] > Arr[i+1]){
            coin=false; 
            break;   
        }
    }
    /*Print the result*/
    if (coin){
        cout << "The result of "<<name<<" is correct." << endl; 
    }else{
        cout<<"The result of "<<name<<" is wrong." << endl; 
    }
 }

void Stamp_memo(string name, int moves, int comps){
    /*Write the moves and comps via memo*/
    ofstream records; 

    records.open("Sort.txt", ios::app); 
        if (records.fail()){
            cerr << "Error: Could not open the file.\n";
            exit(1); 
        }

    records << "The number of moves of and comps of " << name << ": " << moves << " and " << comps << "\n"; 
    records << endl; 

    records.close(); 
}

int main(){
    /*Define array size*/
    int size = 1000; 

    /*Define arrays used in different sort functions*/
    int BST_Insert[size];
    int BST_Heap[size];
    int BST_Quick[size];
    int AVG_Insert[size];
    int AVG_Heap[size];
    int AVG_Quick[size];
    int WST_Insert[size];
    int WST_Heap[size];
    int WST_Quick[size];

    /*Create Best case*/
    for (int i=0; i<size; ++i){
        BST_Insert[i] = i; 
        BST_Heap[i] = i; 
        BST_Quick[i] = i; 
    }

    /*Create Average case*/
    srand(time(nullptr));

    for (int i=0; i<size; i++){
        AVG_Insert[i] = rand() % 100000;
        AVG_Heap[i] = AVG_Insert[i];
        AVG_Quick[i] = AVG_Insert[i];
    }

    /*Create Worst case*/
    for (int i=0; i<size; ++i){
        WST_Insert[size-i] = i; 
        WST_Heap[size-i] = i; 
        WST_Quick[size-i] = i; 
    }

    /*Check BST Insert Sort*/
    Insertion(BST_Insert, size); 
    Check_result(BST_Insert, size, "BST Insertion Sort"); 
    Stamp_memo("BST Insertion Sort", moves, comps); 

    /*Reset the moves and comps*/
    moves = 0;
    comps = 0; 

    /*Check AVG Insert Sort*/
    Insertion(AVG_Insert, size); 
    Check_result(AVG_Insert, size, "AVG Insertion Sort"); 
    Stamp_memo("AVG Insertion Sort", moves, comps); 

    /*Reset the moves and comps*/
    moves = 0;
    comps = 0; 

    /*Check the WST Insert Sort*/
    Insertion(WST_Insert, size); 
    Check_result(WST_Insert, size, "WST Insertion Sort"); 
    Stamp_memo("WST Insertion Sort", moves, comps); 

    /*Reset the moves and comps*/
    moves = 0;
    comps = 0; 

    /*Check BST Heap Sort*/
    Heap(BST_Heap, size); 
    Check_result(BST_Heap, size, "BST Heap Sort"); 
    Stamp_memo("BST Heap Sort", moves, comps); 

    /*Reset the moves and comps*/
    moves = 0;
    comps = 0; 

    /*Check AVG Heap Sort*/
    Heap(AVG_Heap, size); 
    Check_result(AVG_Heap, size, "AVG Heap Sort"); 
    Stamp_memo("AVG Heap Sort", moves, comps); 

    /*Reset the moves and comps*/
    moves = 0;
    comps = 0; 

    /*Check the WST Heap Sort*/
    Heap(WST_Heap, size); 
    Check_result(WST_Heap, size, "WST Heap Sort"); 
    Stamp_memo("Hash Heap Sort", moves, comps); 

    /*Reset the moves and comps*/
    moves = 0;
    comps = 0; 

    /*Check the BST Quick Sort*/
    Quick_sort(BST_Quick, 0, size-1); 
    Check_result(BST_Quick, size, "BST Quick Sort"); 
    Stamp_memo("BST Quick Sort", moves, comps); 

    /*Reset the moves and comps*/
    moves = 0;
    comps = 0; 

    /*Check AVG Insert Sort*/
    Quick_sort(AVG_Quick, 0, size-1); 
    Check_result(AVG_Quick, size, "AVG Quick Sort"); 
    Stamp_memo("AVG Quick Sort", moves, comps); 

    /*Reset the moves and comps*/
    moves = 0;
    comps = 0; 

    /*Check the WST Insert Sort*/
    Quick_sort(WST_Quick, 0, size-1); 
    Check_result(WST_Quick, size, "WST Quick Sort"); 
    Stamp_memo("WST Quick Sort", moves, comps); 

    /*Reset the moves and comps*/
    moves = 0;
    comps = 0; 
    return 0; 
}
