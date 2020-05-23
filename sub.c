#include &lt;stdio.h&gt;
int count = 1;
void subset(int n, int d, int s[])
{
int x[10]; //Shows elements in subset (0 - Absent 1 - Present)
int sum; //Stores current sumset sum
int i, k; //index variables
//Initialise x[] to 0. (None of the elements in set are selected)
for(i = 1; i &lt;= n; i++)
x[i] = 0;
sum = 0;
k = 1; //Take first element
x[k] = 1; //Add first element to subset
while(1)
{
if(k &lt;= n &amp;&amp; x[k] == 1) //k in range(1 to n) &amp; kth element selected
{
//If required subset sum found then print solution
if(sum+s[k] == d)
{
count++;
printf(&quot;Solution is \n&quot;);
for(i = 1; i &lt;= n; i++)
{
if(x[i] == 1)
printf(&quot;%5d&quot;, s[i]);
}
printf(&quot;\n&quot;);
x[k] = 0; //Proceed to find next solution
}
else if(sum + s[k] &lt; d) //If subset sum is &lt; required sum,
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
while(k &gt; 0 &amp;&amp; x[k] == 0) //Find recently added element to
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
printf(&quot;Enter the value of n&quot;);
scanf(&quot;%d&quot;,&amp;n);
//2. Read the elements in the set
printf(&quot;Enter the set in increasing order\n&quot;);
for(i=1;i&lt;=n;i++)
{
scanf(&quot;%d&quot;,&amp;s[i]);
sum += s[i];
}
//3. Read required subset sum
printf(&quot;Enter the maximum subset value of d: &quot;);
scanf(&quot;%d&quot;,&amp;d);
//4. Call function
if(sum &lt; d)
printf(&quot;Solution NOT possible.\n&quot;);
else
{
if(count == 0)
printf(&quot;No solutions possible.&quot;);
else
subset(n, d, s);
}
return 0;
}


//{1,3,5,7,8}

// d=8

//{3,5}
//{1,7}
//{8}