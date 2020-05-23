#include<bits/stdc++.h>
using namespace std;

int W,n;
int maxi=-1;
vector<int>best;

void knapsack(int wts[],int val[],int vw[],int subset[],int size,int index,int w_count,int v_count){

    if(index<n-1){
        if(w_count+wts[index]<=W){
            int upperbound=v_count+val[index]+(W-(w_count+wts[index]))*vw[index+1];
            if(upperbound>maxi){
                subset[size]=index;
                knapsack(wts,val,vw,subset,size+1,index+1,w_count+wts[index],v_count+val[index]);
            }
        }
        knapsack(wts,val,vw,subset,size,index+1,w_count,v_count);
    }
    else{
        //adding or not the last element
        if(w_count+wts[index]<=W){
            int upperbound=v_count+val[index]+(W-(w_count+wts[index])*vw[index]);
            if(upperbound>maxi){
                subset[size]=index;
                maxi=upperbound;
                best.clear();
                for(int i=0;i<size+1;i++){
                    best.push_back(subset[i]);
                }
            }
        }
        else{
            int upperbound=v_count;
            if(upperbound>maxi){
                maxi=upperbound;
                best.clear();
                for(int i=0;i<size;i++){
                    best.push_back(subset[i]);
                }
            }
        }
    }
    return;
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int vw[], int vals[], int wts[], int low, int high)
{
    int pivot = vw[high];   
    int i = (low - 1);  

    for (int j = low; j <= high- 1; j++)
    {
        
        if (vw[j] > pivot)
        {
            i++;   
            swap(&vw[i], &vw[j]);
            swap(&vals[i], &vals[j]);
            swap(&wts[i], &wts[j]);
        }
    }
    swap(&vw[high], &vw[i+1]);
    swap(&vals[high], &vals[i+1]);
    swap(&wts[high], &wts[i+1]);
    return (i + 1);
}

void quacksort(int vw[], int vals[], int wts[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(vw, vals, wts, low, high);
        quacksort(vw, vals, wts, low, pi - 1);
        quacksort(vw, vals, wts, pi + 1, high);
    }
}

int main(){
    cout<<"Enter capacity of knapsack"<<endl;
    cin>>W;
    cout<<"Enter number of items of knapsack"<<endl;
    cin>>n;
    int weights[n],values[n],vw[n],subset[n];
    for(int i=0;i<n;i++){
        cin>>weights[i]>>values[i];
    }
    for(int i=0;i<n;i++){
        vw[i]=values[i]/weights[i];
    }
    quacksort(vw,values,weights,0,n-1);
    knapsack(weights,values,vw,subset,0,0,0,0);
    for(int i=0;i<best.size();i++){
        cout<<best[i]+1<<" ";
    }
    cout<<"\n"<<maxi<<endl;
}

