#include <iostream>
#include <string.h>
#include <vector>
#include <utility>

using namespace std;

bool order(string a,string b);
int kinda_Bsearch(string* v,int l,string p);


int main()
{
	/*  || \ */

	int n = 14;
	string v[] = {"at","","","","ball","","","car","","","dad","","","horn"};

	int x = kinda_Bsearch(v,n,"dad");
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

int kinda_Bsearch(string* v,int l,string p){

	int low = 0;
	int high = l-1;

	int mid;
	int dir = 1;
	while(low <= high){

		mid = (low+high)/2;

		//If mid is an empty string,search the closest non-empty string ****

		if(v[mid] == ""){
			int k;
			int temp_mid;
			if(dir == 1){
				k = low;
				temp_mid = mid;
				while(v[temp_mid] == ""){
					k++;
					temp_mid = (k+high)/2;
					if(temp_mid >= l){
						break;
					}
				}
			}
			if(dir == 0){
				k = high;
				temp_mid = mid;
				while(v[temp_mid] == ""){
					k--;
					temp_mid = (low+k)/2;
					if(temp_mid <= 0){
						break;
					}
				}
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

