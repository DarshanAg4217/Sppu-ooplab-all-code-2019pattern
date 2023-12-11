/* Title:Write a function template selection Sort. Write a program that inputs, sorts and outputs an int
	array and a float array.
ASSIGNMENT NO. :
GROUP          :
ROLL NO.       :
BATCH          :
*/
#include <iostream>
using namespace std;
template <typename T>
//template <class T>
void sort()
{
	int i, j,count;
	T temp;
	cout<<"\n How many no. u want to enter in array : ";
	cin>>count;	
	T n[count];
	cout<<"\n Enter" <<count<<" numbers : ";
	for(i=0;i<count;i++)
	{
		cin>>n[i];
	}
	for(i=0;i<(count-1);i++)
	{
		for(j=i+1;j<count;j++)
		{
			if(n[i]>n[j])
			{
				temp=n[i];
				n[i]=n[j];
				n[j]=temp;
			}
		}
	}
	cout<<"\n The array in the sorted order is : "<<endl;
	for(i=0;i<count;i++)
	{
		cout<<"\t"<<n[i];
	}
}


int main()
{
	int choice;
	char ans;
	do
	{
		cout<<"\n 1. Integer  sort. \n 2. Float sort.";
		cout<<"\n Enter the input you want to sort : ";
		cin>>choice;
		switch(choice)
		{
			case 1 : sort<int>();
					 break;
			case 2 : sort<float>();
					 break;
			case 3 : cout<<"\n Invalid choice.";
					 break;
		}
		cout<<"\n Do u wish to continue (Y/N)?";
		cin>>ans;
	}while(ans=='Y' || ans=='y');
	return 0;
}


