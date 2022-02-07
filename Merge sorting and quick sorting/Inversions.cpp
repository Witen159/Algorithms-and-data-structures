#include<iostream>
#include<fstream>
using namespace std;

long long int Merge(int* massLeft, int* massRight, int* arr, int massLeftLength, int massRightLength){

	int i = 0, j = 0, k = 0;
	long long int inverseCounter = 0;

	while (i < massLeftLength && j < massRightLength){
		if (massLeft[i] <= massRight[j]){
			arr[k] = massLeft[i];
			i++;
		}
		else{
			arr[k] = massRight[j];
			j++;
			inverseCounter += massLeftLength - i;
		}
		k++;
	}

	while (i < massLeftLength){
		arr[k] = massLeft[i];
		i++;
		k++;
	}

	while (j < massRightLength){
		arr[k] = massRight[j];
		j++;
		k++;
	}

	return inverseCounter;
}

long long int MergeSort(int* mas, int masLength){

	long long int inverseCounter = 0;

	if (masLength < 2)
		return 0;

	int mid = masLength / 2;
	int* masLeft = new int[mid];
	int* masRight = new int[masLength - mid];

	for (int i = 0; i < mid; i++)
		masLeft[i] = mas[i];
	for (int i = mid; i < masLength; i++)
		masRight[i - mid] = mas[i];

	inverseCounter += MergeSort(masLeft, mid);
	inverseCounter += MergeSort(masRight, masLength - mid);
	inverseCounter += Merge(masLeft, masRight, mas, mid, masLength - mid);

	delete[] masLeft;
	delete[] masRight;

	return inverseCounter;
}

int main(){
	int n;

	ifstream input("inversions.in");
	ofstream output("inversions.out");

	input >> n;
	int* mass = new int[n];

	for (int i = 0; i < n; i++){
		input >> mass[i];
	}

	output << MergeSort(mass, n);

	delete[] mass;

	input.close();
	output.close();
}