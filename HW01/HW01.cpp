#include<iostream>
using namespace std;

// Problme1 //
    // 1. SwapP
        // swapP contains two pointer variables
void swapP(int *a_add, int *b_add){
    // print results before swapping 
    int temp; 
    cout << "Before SwapP: ";
    cout << *a_add << " and " << *b_add << endl; 
    // key function of swapping variables 
    temp = *a_add; 
    *a_add = *b_add; 
    *b_add = temp; 
    // results of swap
    cout << "After SwapP: ";
    cout << *a_add << " and " << *b_add << endl; 
}

    // 2. SwapR
        // swapR contains two address variables 
void swapR(int &a, int &b){
    // print results before swapping 
    cout << "Before SwapR: ";
    cout << a << " and " << b << endl; 
    // key function of swapping variables 
    int temp;
    temp = a;
    a = b;
    b = temp; 
    // results 
    cout << "After SwapP: ";
    cout << a << " and " << b << endl; 
}

// Problem2 //
    // When input list and number, print the maximum values
int MaxFirst(int v[], int num){
    // signate max variables for result
    int max_v;
    max_v = v[0];
    /*
    main key of function, comparing each values in the list and if the next number is bigger than existing value, 
    the function exchnage the numbers 
    */
    for (int i=0; i<num; i++){
        if (max_v < v[i+1]){
            max_v = v[i+1];
        }
    }
    // print max feature 
    cout << "Max Feature: " << max_v << endl;
    return 0;
}

// Problem3 //
    //struct to store student details
struct student{
    string name;
    int grade;
    };

    // Get sort 
        /*
        using two for methods to build sort function 
        when index i is being still in the position, the index j check the all values and compare the size 
        , which is smaller than current value of index i, it switches
        */
int get_sort(student *students, int size){
    int index;
    for (int i=0; i<size; ++i){
        index = i; 
        for (int j=i; j<=size; ++j){
            if (students[j].grade < students[index].grade){
                index = j;
            }
        }
        
        // main function of sorting, exchange the real values in the list
        int temp = students[i].grade;
        students[i].grade = students[index].grade;
        students[index].grade = temp; 

        // change the sring as well 
        string s_temp = students[i].name;
        students[i].name = students[index].name;
        students[index].name = s_temp; 
    }
    return 0; 
}
    // Get Average
        /*
        get average function, when user inputs list and the number of size, 
        it calculates the sum and divdie with the number of size 
        */
void get_average(student* students,int size){
    int s=students[0].grade,e=students[0].grade,avg=students[0].grade;
    for(int i=1;i<size;i++){
        avg+=students[i].grade;
        //checks for smallest grade
        if(s>students[i].grade)
        s=students[i].grade;
        //checks for largest grade
        if(e<students[i].grade)
        e=students[i].grade;
    }
    cout<<"Average: "<<avg/size<<endl;
}
    // Get Median
        /*
        get median function, using sort function in above, 
        calculates the median values. 
        */
void get_median(student *students, int size){
    // case is divied as 2, one is remainder == 1, the other is remainder == 0
    if (size%2==0){
        cout << "Median: ";
        cout << (students[size/2].grade + students[size/2 + 1].grade) / 2 << endl;
    }else{
        cout << "Median: ";
        cout << students[size/2].grade << endl;
    }
}
    // Get Max
        /*
        get max valeus in the list, 
        using for method, get the smallest values of grade and name 
        */
void get_max_name(student* students,int size){
    string name=students[0].name;
    int grade=students[0].grade;
    for(int i=1;i<size;i++){
        if(grade<students[i].grade){
            name=students[i].name;
            grade=students[i].grade;
        }
    }
    cout<<"Maximum name & grade: "<<name<<" ["<<grade<<"]"<< endl;
}
    // Get Min
        /*
        get min values, the method of work is same as the get_max function 
        */
void get_min_name(student* students,int size){
    string name=students[0].name;
    int grade=students[0].grade;
    for(int i=1;i<size;i++){
        if(grade>students[i].grade){
            name=students[i].name;
            grade=students[i].grade;
        }
    }
    cout<<"Minimum name & grade: "<<name<< " ["<< grade<< "]"<<endl;
}

////////////////////////////////////////////////////
int main(){
    // Problem 1 //
    int a=3; int b=5; int c=7; int d=9;
    swapP(&a, &b);
    swapR(c, d);
    
    // Problem 2 //
    int v[]={6,1,7,8,2,5};
    MaxFirst(v, 6);

    // Problem3 //
    /*
    first step, user has to input designate the number of students size 
    secondly, input the values of names and grades in students list
    */
    int no_of_students,temp;
    cout<<"Enter no of students: ";
    cin>>no_of_students;
    
    //created an array of size no_of_students 
    student students[no_of_students];
    for(int i=0;i<no_of_students;i++){
        cout<<"Enter student name: ";
        cin>>students[i].name;
        cout<<"Enter students grade: ";
        cin>>temp;
        /*
        set up the range 1 to 100, if the values are out of range,
        the error code appears
        */
        if(temp>-1 && temp<101){
            students[i].grade=temp;
        }
        else{
            cout<<"Grade should be in range 0 to 100";
        }
    }  
    int size = sizeof(students)/sizeof(students[0]);
    
    // print normal list and list, which the values are sorted 
    cout << "Normal List: ";
    for (int i=0; i<size; ++i){
        cout << students[i].grade << " ";
    } 
    cout << endl;
    
    get_sort(students,size);
    
    cout << "Sorted List: ";
    for (int i=0; i<size; ++i){
        cout << students[i].grade << " ";
    }
    cout << endl;
    
    // print the main functions to calculate average, median, max, and min of students 
    get_average(students,size);
    get_median(students, size); 
    get_max_name(students,size);
    get_min_name(students,size);
    return 0;
}
////////////////////////////////////////////////////
