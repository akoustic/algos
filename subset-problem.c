#include <stdio.h>
int count = 1;
void subset(int n, int d, int s[])
{
int x[10]; //Shows elements in subset (0 - Absent 1 - Present)
int sum;  //Stores current sumset sum
int i, k; //index variables
//Initialisex[] to 0. (None of the elements in set are selected)
for(i = 1; i<= n; i++)
x[i] = 0;
sum = 0;
k = 1; //Take first element
x[k] = 1; //Add first element to subset
while(1)
{
if(k <= n && x[k] == 1) //k in range(1 to n) & kth element selected
{
//If required subset sum found then print solution
if(sum+s[k] == d)
{
count++;
printf("Solution is \n");
for(i = 1; i<= n; i++)
{
if(x[i] == 1)
printf("%5d", s[i]);
}
printf("\n");
x[k] = 0; //Proceed to find next solution
}
else if(sum + s[k] < d) //If subset sum is < required sum,
sum += s[k]; //then add the current element to
//subset
else
x[k] = 0; //If subset sum is morethan required
//sum, then remove the current
//element
}
else
{
k--; //Bring k within range
while(k > 0 && x[k] == 0) //Find recently added element to
k--; //subset and remove it
if(k == 0) break; //No more solutions exists, so quit
x[k] = 0; //Remove recently added element
sum = sum - s[k];
}
k = k + 1; //Take next element
x[k] = 1; //Add next element to subset
} //end while
}

int main()
{
int n; //No. of elements in set
int d; //Required subset sum
int s[10]; //Array: Elements in the set
int i; //index variable
int sum = 0;
//1. Read no. of elements in set
printf("Enter the value of n");
scanf("%d",&n);
//2. Read the elements in the set
printf("Enter the set in increasing order\n");
for(i=1;i<=n;i++)
{
scanf("%d",&s[i]);
sum += s[i];
}
//3. Read required subset sum
printf("Enter the maximum subset value of d: ");
scanf("%d",&d);
//4. Call function
if(sum < d)
printf("Solution NOT possible.\n");
else
{
if(count == 0)
printf("No solutions possible.");
else
subset(n, d, s);
}
return 0;
}
