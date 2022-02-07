#include <fstream>
#include <iostream>

using namespace std;

int kModQsort(int* mass, int left, int right, int k) {
    if (right - left < 1) { 
        return mass[left]; 
    }
    else {

		int i, j, pivot;

		i = left;
		j = right;
		pivot = mass[left + rand() % (right - left + 1)];

        while (i <= j){
			while (mass[i] < pivot) {
				i++;
			}

			while (mass[j] > pivot) {
				j--;
			}

            if (i <= j){
                int t = mass[i];
                mass[i] = mass[j];
                mass[j] = t;
                i++;
                j--;
            }
        }

        if (k <= j) {
            return kModQsort(mass, left, j, k);
        }
        else{
            return kModQsort(mass, j + 1, right, k);
        }           
    }
}

int main(){
    int n, k, A, B, C;
    
    ifstream input("kth.in");
    ofstream output("kth.out");

    input >> n >> k;
	

    int* a;
    a = new int[n];

    input >> A >> B >> C >> a[0] >> a[1];

    for (int i = 2; i < n; i++){
        a[i] = A * a[i - 2] + B * a[i - 1] + C;
    }

    output << kModQsort(a, 0, n - 1, k-1);

    delete[] a;
    input.close();
    output.close();

    return 0;
}

