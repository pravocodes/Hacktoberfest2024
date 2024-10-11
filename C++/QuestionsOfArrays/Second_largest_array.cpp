#include <iostream>
#include <climits>

using namespace std ;

int main(){

int number;

cout << "Enter The Number of Elements : " ;

cin >> number;

int arr[number];

cout << "Enter The elements :";

for(int i = 0 ; i < number ; i++){

    cin >> arr[i];
}

int largest = INT_MIN;
int secondLargest = INT_MIN;

for(int i = 0 ; i < number ; i++){

if( arr[i] > largest ){

secondLargest = largest;
largest = arr[i];
}

else if( arr[i] > secondLargest && arr[i] != largest){

secondLargest = arr[i];
}
}

if( secondLargest == INT_NUM){

cout << "There i s no Second (2nd) Largesr Number :" << endl;
}

else {

cout << "The Second Largest Number is : " << secondLargest << endl;
  
}

return 0 ;
}
