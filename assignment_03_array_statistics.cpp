// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

// finding sum
int findSum(int arr[], int n) {
  int sum = 0;
  for (int i = 0; i < n; i++){
    sum += arr[i];
  }
return sum;
}

//finding maximum value
int findMax(int arr[], int n) {
  int maxNum = arr[0];
  for (int i = 1; i < n; i++){
    if(arr[i] > maxNum) {
      maxNum = arr[i];
    }
  }
  return maxNum;
}


//finding minimum value
int findMin(int arr[], int n) {
  int minNum = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] < minNum) {
      minNum = arr[i];
    }
  }
  return minNum;

}


//finding average
double findAvg(int arr[], int n) {
  return static_cast<double>(findSum(arr, n)) /n;
}



int main() {
  int n;
  int i;
  cout << "How many numbers? ";
  cin >> n;

  if (n <= 0 ) {
    cout << "Error: N must be a positive integer." << endl;
    return 0;
  }

int arr[n];
for (i = 0; i < n; i++) {
  cout << "Enter number " << (i + 1) << ": ";
  cin >> arr[i];
}

cout << endl;
cout << "Results: " << endl;
cout << "Sum: " << findSum(arr, n) << endl;
cout << "Average: " << findAvg(arr, n) << endl;
cout << "Maximum: " << findMax(arr, n) << endl;
cout << "Minimum: " << findMin(arr, n) << endl;

return 0;
}
