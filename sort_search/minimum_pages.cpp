/*Lets discuss the approach.In the question it is given that the student who gets allocated maximum count
of pages must have him sum of pages minimum that means  we need to find minimum of maximums.It is also
given that there must be atleast one book allocated to each student.lets suppose we gave one book to one
student.Since we are finding the minimum of maximum the other student gets rest books now his sum must be
minimum to minimise this what if we give maximum number of pages book to student 1 thats why we
initialise low to max_pages book . Note this example is for no of students=2.We can also keep low
as min_pages but the difference is it requires more iterations.At each stage we find the max_pages one
student can read initially it will be low+high/2.If the condition is valid we minimise this value
until it gives valid value.Now how to check if its valid or not.To do this we keep on iterating the
students array and take their sums if the sum is less we can add since the student can read it but if
becomes more its not possible because max_limit is reached and the book must be given to new student
so count is increased and new sum is that array position value where the condition is violated.After
all the iterations are happened we check if the students are greater than given k if its true its not
valid and we increase max_pages if its false there is possibility of getting much smaller values.*/

#include <iostream>
#include <algorithm>

using namespace std;

bool isValid(int n, int arr[], int k, int max) {
    int students = 1;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        if(sum > max) {
            students++;
            sum = arr[i];
        }
    }
    if(students > k)
        return false;
    else
        return true;
}

int findPages(int A[], int N, int M) {
    if(N < M) return -1;
    int sum = 0;
    for(int i = 0; i < N; i++)
        sum += A[i];
    int low = *max_element(A, A + N);
    int high = sum;
    int res = -1;
    while(low <= high) {
        int max_pages = low + (high - low) / 2;
        if(isValid(N, A, M, max_pages) == true) {
            high = max_pages - 1;
            res = max_pages;
        }
        else {
            low = max_pages + 1;
        }
    }
    return res;
}

int main() {
    int A[] = {12, 34, 67, 90};
    int N = sizeof(A) / sizeof(A[0]);
    int M = 2;
    int ans = findPages(A, N, M);
    cout << "The minimum number of pages allocated is: " << ans << endl;
    return 0;
}
