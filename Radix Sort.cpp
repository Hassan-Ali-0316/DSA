//#include<iostream>
//#include<ctime>
//using namespace std;
//
//// function counting sort will be called number of times that max element has digits
//
//void countingSort(int *arr,int size,int div)
//{
//	int output[size] = {0};
//	int count[10] = {0};
//	
//	for(int i=0 ; i<size ; i++)
//	{
//		count[(arr[i]/div)%10]++;          // store number of count of each digit
//	}
//	
//	for(int i=1 ; i<10 ; i++)
//	{
//		count[i] = count[i] + count[i-1];  // stores accumulative count in count arr
//	}
//	
//	for(int i=size-1 ; i>=0 ; i--)
//	{
//		output[count[(arr[i]/div)%10]-1] = arr[i];
//		count[(arr[i]/div)%10]--;
//	}
//	
//	for(int i=0 ; i<size ; i++)
//	{
//		arr[i] = output[i];
//	}
//}
//int getmax(int *arr , int size)
//{
//    int maxi = INT_MIN;
//	
//	for(int i = 0 ; i < size ; ++i)
//	{
//		if(arr[i] > maxi)
//		{
//			maxi = arr[i];
//		}
//	}
//	
//	return (maxi);	
//}
//void radixSort(int *arr,int size)
//{
//	int m = getmax(arr,size);
//	
//	for(int i = 1 ; m/i > 0 ; i *= 10)
//	{
//		countingSort(arr,size,i);
//	}
//}


void call(int *arr,int s,int pos)
{
	int count[s]{0};
	int output[s]{0};
	
	for(int i=0 ; i<s ; i++)
	{
		count[(arr[i]/pos)%10]++;
	}
	
	for(int i=1 ; i<s ; i++)
	{
		count[i] = count[i] + count[i-1];
	}
	
	for(int i=s-1 ; i>=0 ; i--)
	{
		output[--count[arr[i]/pos%10]] = arr[i];
		//count[(arr[i]/pos)%10]--;  199--------
	}
	
	for(int i=0 ; i<s ; i++)
	{
		arr[i] = output[i];
	}
}

int getMax(int *arr,int s)
{
	int m = INT_MIN;
	
	for(int i=0 ; i<s ; i++)
	{
		if(arr[i]>m)
		{
			m = arr[i];
		}
	}
	return m;
}

void radixSort(int *arr,int s)
{
	int m = getMax(arr,s);
	
	for(int i=1 ; m/i>1 ; i=i*10)
	{
		call(arr,s,i);
	}
}


int main()
{
	int size = 10;
	int *arr = new int[size]{};
	
	srand(time(0));
	for(int i=0 ; i<size ; i++)
	{
		int r = rand() % 500;
		arr[i] = r;	
	}
	for(int i=0 ; i<size ; i++)
	{
		cout << arr[i] << "   ";
	}
	cout << endl;
	
	radixSort(arr,size);
	
	for(int i=0 ; i<size ; i++)
	{
		cout << arr[i] << "   ";
	}
	delete[] arr;
}


/* radix sort steps 

  1. make function radix sort pass array and its size as parameters
  2. find max element in array in fucntion radix sort
  3. write a for loop with base condition max/div>0 initialize  div = 1 and increment div with div = div * 10
  4. in that loop call function CountingSort with parameters array,size and div (basically CountingSort function will be called the number of digits maximum
     element has)
  5. in CountingSort make two arrays count[10] to count frequency of each digit and output[size]
  6. initialize count with 0
  7. count frequency of digits by count[(arr[i]/div)%10]++;
  8. find accumulative count of count array by writing a for loop from i=1 i<size store accumulative count in count array by
     		count[i] = count[i] + count[i-1]
  9. in output array's particular index store arr[i] by write one more for loop for i=0 to i=size , index is found by : 
  			output[count[(arr[i]/div)%10]-1] = arr[i]
			count[(arr[i]/div)%10]--
  10. Finally store output[i] in arr[i]	*/		  	 
	    