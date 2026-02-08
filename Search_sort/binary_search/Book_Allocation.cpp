/*Problem statement
Given an array ‘arr’ of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book.



There are ‘m’ number of students, and the task is to allocate all the books to the students.



Allocate books in such a way that:

1. Each student gets at least one book.
2. Each book should be allocated to only one student.
3. Book allocation should be in a contiguous manner.


You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.



If the allocation of books is not possible, return -1.



Example:
Input: ‘n’ = 4 ‘m’ = 2
‘arr’ = [12, 34, 67, 90]

Output: 113

Explanation: All possible ways to allocate the ‘4’ books to '2' students are:

12 | 34, 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12’, and student two is ‘34+ 67+ 90 = 191’, so the maximum is ‘max(12, 191)= 191’.

12, 34 | 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 = 46’, and student two is ‘67+ 90 = 157’, so the maximum is ‘max(46, 157)= 157’.

12, 34, 67 | 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 +67 = 113’, and student two is ‘90’, so the maximum is ‘max(113, 90)= 113’.

We are getting the minimum in the last case.

Hence answer is ‘113’.*/

#include <iostream>
#include <vector>
using namespace std;
int checking(vector<int> &arr, int max, int student)
{
    int i = 0;
    int pages = 0, studentsUsed = 1;
    for (i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= max)
        {
            if (pages + arr[i] <= max)
            {
                
                pages = pages + arr[i];
            }
            else
            {
                
                pages = arr[i];
                studentsUsed++;
                
            }
        }
        else
        {
            return -1;
        }
    }
    if (studentsUsed <= student)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
int MinBookAll(vector<int> &arr,int students){
    int arrsum=0;
    for(int i=0;i<arr.size();i++){
        arrsum+=arr[i];
    }
    int s=0,e=arrsum;
    int mid=s+(e-s)/2;
    int ans;
    while(s<=e){
        int check=checking(arr,mid,students);
        
        if(check==1){
            e=mid-1;
            ans=mid;

        }
        else if(check==-1){
            s=mid+1;
        }
        mid=s+(e-s)/2;
        
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4,5};
    cout<<MinBookAll(arr,2);
    
}