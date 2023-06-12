#include <iostream>
#include <string.h>
#include <vector>
#include <utility>

using namespace std;

bool order(string a,string b);
int kinda_Bsearch(string* v,int l,string p,int start);
int search_string(string* v,int l,string p);

int main()
{
	/*  || \ */

	int n = 14;
	string v[] = {"at","","","","ball","","","car","","","dad","","","horn"};

	int x = search_string(v,n,"car");
	printf("%d",x);


	return 0;
}

bool order(string a,string b){

	//checks if string a comes before b in alphabetical order
	int n = a.length()-1;
	int m = b.length()-1;
	int i = 0;
	while(a[i] == b[i]){
		i++;
		if(i > n || i > m){
			i--;
			break;
		}
	}

	//if a = "vastator" and b = "vastatoris",it will return true

	if(a[i] <= b[i]){
		return true;
	}
	return false;
}

int kinda_Bsearch(string* v,int l,string p,int start){

	int low = 0;
	int high = l-1;

	int mid;
	int dir = start;
	while(low <= high){

		mid = (low+high)/2;

		//If mid is an empty string,search the closest non-empty string ****
		//printf("%d\n",mid);
		if(v[mid] == ""){
			int k;
			int temp_mid;
			if(dir == 1){
				k = low;
				temp_mid = mid;
				while(v[temp_mid] == ""){
					k++;
					temp_mid = (k+high)/2;
					if(v[temp_mid] == p){
						return temp_mid;
					}
					if(temp_mid >= l){
						break;
					}
				}
				low = k;
				mid = temp_mid;
			}
			if(dir == 0){
				k = high;
				temp_mid = mid;
				while(v[temp_mid] == ""){
					k--;
					temp_mid = (low+k)/2;
					if(v[temp_mid] == p){
						return temp_mid;
					}
					if(temp_mid <= 0){
						break;
					}
				}
				high = k;
				mid = temp_mid;
			}

		}

		//*****

		if(v[mid] == p){
			return mid;
		}
		if(order(v[mid],p)){
			//p comes after v[mid] -->
			low = mid+1;
			dir = 1;
		}
		if(!order(v[mid],p)){
			//p comes before v[mid] <--
			high = mid-1;
			dir = 0;
		}

	}
	return -1;
}

int search_string(string* v,int l,string p){

	int x = kinda_Bsearch(v,l,p,1);
	if(x == -1){
		return kinda_Bsearch(v,l,p,0);
	}
	return x;
}
