//
//  VectorRecursion.h
//  Project11
//
//  Created by Renat Norderhaug on 12/07/17.
//  Copyright � 2017 Renat Norderhaug. All rights reserved.
//

#ifndef VECTORRECURSION_H
#define VECTORRECURSION_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


template <class T>
    void swap(vector<T>& vec ,T i,T j);
template <class T>
    T partition(vector<T>& A, T p,T q);
template <class T>
    void vector_resort(vector<T>& A, T p,T q);
template <class T>
    T vector_research(vector<T>& vec,T low,T high,const T key);


template <class T>
void swap(vector<T> &vec,T i,T j)
{
    T a=vec[i];
    vec[i]=vec[j];
    vec[j]=a;

}

template <class T>
T partition(vector<T> &vec, T low,T high)
{
    T pi= vec[high]; //taking last element as pivot
    T i= low-1;
    for(T j=low;j<=high-1;j++){    // If current element is smaller than or equal to pivot.
        if(vec[j] <= pi){
            i++;
            swap(vec,i,j);
        }
    }
    swap(vec,i+1,high);
    return (i+1);

}

template <class T>
void vector_resort(vector<T> & vec, T low,T high)
{
    if(low<high){
        T pi=partition(vec,low,high);
        vector_resort(vec,low,pi-1);
        vector_resort(vec,pi+1,high);
    }
}

template <class T>
T vector_research(vector<T>& vec,T low,T high,const T key)
{

    if(low>high)
    {
        return -1;
    }

    T mid=(low+high)/2;

    if(vec[mid]==key)
    {
        return mid;
    }

    if(vec[mid]>key)
    {
        return vector_research(vec,low,mid-1,key);
    }

    return vector_research(vec,mid+1,high,key);

}

#endif // VECTORRECURSION_H
