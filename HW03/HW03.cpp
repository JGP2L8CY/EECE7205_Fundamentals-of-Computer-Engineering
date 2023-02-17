/// HW03
#include <iostream>
#include <cmath>
#include <random>
using namespace std;

/// Problme02
/*
Build Hash Table
a. 1000 random integers -> Birthdays of people born 01012000-12312004
   All people born before 28th day 
b. Define 3 Hash tables m1=97, m2=98, m3=100
c. h(key) = key mod m(i), collision=chaining (Save next slot)
d. min, amx, mean, and variance 
*/

// Auxiliary functions 
int h1(int birth, int m){
    /*Make Hash Table using remainder*/
    return birth % m;
}
int max(int a[], int size){
    int maximum = a[0]; 
    /*Scan the maximum value*/
    for (int i=1; i<size; ++i){
        if (a[i]>maximum){
            maximum=a[i];
        }
    }
    return maximum; 
}
int min(int a[], int size){
    /*Scan the minimum value*/
    int minimum = a[0];
    for (int i=1; i<size; ++i){
        if (a[i]<minimum){
            minimum=a[i];
        }
    }
    return minimum; 
}
int average(int a[], int size){
    /*Get average using for loop*/
    int sum=0;
    for (int i=0; i<size; ++i){
        sum += a[i];
    }
    return sum/size;
}
double variance(int a[], int size){
    /*Get variance using for loop*/
    double sum=0; 
    double ave = average(a, size);

    for (int i=0; i<size; ++i){
        sum += pow(a[i]-ave,2);
    }
    return sum/size;
}


//////////////////////////////////////////////////////////
int main(){
    // Hash Table Size 
    int m1 = 97;
    int m2 = 98;
    int m3 = 100;
    int Birth_num = 1000;

    // Create arrays
    int m1_array[m1]; 
    int m2_array[m2]; 
    int m3_array[m3]; 
    int Birth_array[Birth_num];

    // Input 0 into arrays 
    for (int i1=0; i1<m1; ++i1){
        m1_array[i1] = 0;
    }
    for (int i2=0; i2<m2; ++i2){
        m2_array[i2] = 0;
    }
    for (int i3=0; i3<m3; ++i3){
        m3_array[i3] = 0;
    }

    // Generate Random Birth_num 
    random_device rd; 
    mt19937 gen(rd());
    /*Generate Birthday Number mmddyy*/
    uniform_int_distribution<> disM(1, 12);
    uniform_int_distribution<> disD(01, 28);
    uniform_int_distribution<> disY(00, 04);

    /*Store Birth_num into Birth_array*/
    for (int i=0; i<Birth_num; ++i){
        Birth_array[i] = disM(gen)*10000+disD(gen)*100+disY(gen);
    }
    
    /*
    Put the Birthday numbers into Birth_Arrays 
    Connect to Hash Table 
    */
    for (int j=0; j<Birth_num; ++j){
        int rend1 = h1(Birth_array[j], m1); 
        int rend2 = h1(Birth_array[j], m2); 
        int rend3 = h1(Birth_array[j], m3); 

        // Count number of collisions in each slots 
        for (int p=0; p<m1; ++p){
            if (rend1==p){
                cout << "Collision in m1_array: " << m1_array[p] << endl; 
                m1_array[p] += 1;
                break; 
            }
        }

        for (int q=0; q<m2; ++q){
            if (rend2==q){
                cout << "Collision in m2_array: " << m1_array[q] << endl; 
                m2_array[q] += 1;
                break; 
            }
        }

        for (int l=0; l<m3; ++l){
            if (rend3==l){
                cout << "Collision in m3_array: " << m1_array[l] << endl; 
                m3_array[l] += 1;
                break; 
            }
        }
    }

    // Calculate Max, Min, Mean, and Variance value for each hash table
    int max1 = max(m1_array, m1); 
    int min1 = min(m1_array, m1);
    int average1 = average(m1_array, m1); 
    double variance1 = variance(m1_array, m1); 

    int max2 = max(m2_array, m2); 
    int min2 = min(m2_array, m2);
    int average2 = average(m2_array, m2); 
    double variance2 = variance(m2_array, m2); 

    int max3 = max(m3_array, m3); 
    int min3 = min(m3_array, m3);
    int average3 = average(m3_array, m3); 
    double variance3 = variance(m3_array, m3); 

    // Display Results 
    cout << "Maximum value of hash97: " << max1 << endl; 
    cout << "Minimum value of hash97: " << min1 << endl; 
    cout << "Average value of hash97: " << average1 << endl; 
    cout << "Varaince value of hash97: " << variance1 << endl; 

    cout << "Maximum value of hash98: " << max2 << endl; 
    cout << "Minimum value of hash98: " << min2 << endl; 
    cout << "Average value of hash98: " << average2 << endl; 
    cout << "Varaince value of hash98: " << variance2 << endl; 
    
    cout << "Maximum value of hash100: " << max3 << endl; 
    cout << "Minimum value of hash100: " << min3 << endl; 
    cout << "Average value of hash100: " << average3 << endl; 
    cout << "Varaince value of hash100: " << variance3 << endl; 
    
    cout << m1_array[0] << endl;
    cout << Birth_array[0] << endl;

    return 0;
}
//////////////////////////////////////////////////////////
