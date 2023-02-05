#include <iostream>
#include <cmath>
#include <random> 
using namespace std;

//// EECE7205 HW02 ////
// Problme01
/*
Sorting array A by using the Merge Sort algorithm 
Input value n: 1 < n <= 50
Generate random numbers for value (Fill A with random integers)
Two Functions required 1. Merge-Sort 2. Merge 
*/
void Merge(int Arr[], int p, int q, int r){
    // index of q and r~q 
    int n1 = q - p + 1; 
    int n2 = r - q; 

    // Create temporary arrays
    int Left[n1], Right[n2];

    // Copy the left, right array
    for (int i=0; i<n1; i++){
        Left[i] = Arr[p+i];
    }
    for (int j=0; j<n2; j++){
        Right[j] = Arr[q+1+j];
    }

    // Variables 
    int i=0;
    int j=0;
    int k=p;

    // Loop until (i<n1) && (j<n2)
    while ((i<n1) && (j<n2)){
        // Check the Left and Right value and sort 
        // Sort the values in the array
        if (Left[i]<=Right[j]){
            Arr[k] = Left[i];
            i++; 
        }else{
            Arr[k] = Right[j];
            j++; 
        }
        k++;
    }

    // The role of sentinel
	while (i < n1) {
        /*
        the functions help to get the remainders and 
        the role of sentinel(The end of values)
        */
		Arr[k] = Left[i];
		i++;
		k++;
	}

	while (j < n2) {
		Arr[k] = Right[j];
		j++;
		k++;
	}
}

void Merge_Sort(int Arr[], int p, int r){
    /*
    Split the left and right side of values 
    as possible as it can
    */
    if (p>=r){
        return;
    }
    int q = p + (r-p)/2;

    // Call functions to split
    Merge_Sort(Arr, p, q); // 다시 한 번 쪼개기 
    Merge_Sort(Arr, q+1, r); // 오른쪽 다시 한 번 더 쪼개기 
    Merge(Arr, p, q, r);

}

void print_function(int Arr[], int size){
    /*
    print the arrays
    */
    for (int i=0; i<size; ++i){
        cout << Arr[i] << " ";
    }
}

// Problem03
int F1(int n){
    if (n==0){
         return 1;
    }
    return F1(n-1) + F1(n-1);
}

int F2(int n){
    if (n==0){
        return 1;
    }
    if (n%2==0){
        int result = F2(n/2);
        return result * result; 
    }else{
        return 2*F2(n-1); 
    }
    return 0;
}

// Problme04
int ProcedureX(int Arr[], int n){
    int x; 
    for (int i=1; n; ++i){
        for (int j=i+1; n; ++j){
            if (Arr[j] < Arr[j+1]){
                x = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = x;
            }
        }
    }
    return 0;
}

////////////////////////////////////////////////////////////
int main(){
    // Problem01
    
    int size;
    cout << "Input the size of Array: ";
    cin >> size;
    int Arr[size]; 

    // Random variable range 0 to 100
    for (int i=0; i<size; ++i){
        int r = (rand()%101); 
        Arr[i] = r;
    }

    cout << "Initial array is ";
    print_function(Arr, size);
    cout << endl; 
    Merge_Sort(Arr, 0, size-1);

    // Print sorted array
    cout << "Sorted array is ";
    print_function(Arr, size);
    cout << endl;

    // Problem03
    int n;
    cout << "Enter the number: ";
    cin >> n; 
    cout << "F1 result is: ";
    cout << F1(n);
    cout << endl; 
    cout << "F2 result is: ";
    cout << F2(n);
    cout << endl; 

    return 0;
}
////////////////////////////////////////////////////////////
