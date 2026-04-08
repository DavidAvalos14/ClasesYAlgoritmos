// Angel David Avalos Carrillo
// Algoritmo para binary search (O(log n)) (Ordenados o semiordenados)

#include <bits/stdc++.h>
using namespace std;

// Retornar la posición en la que se encuentra el elemento buscado (En un rango determinado)
int binarySearchPos(vector<int>& nums, int target, int L, int R) {

    while(L <= R) {
        int mid = L + (R - L) / 2;

        if(nums[mid] == target) {
            return mid;
        } else {
            if(nums[mid] <= target) {
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }
    }

    return -1;
}

// Retornar solamente si el valor existe
bool binarySearchExiste(vector<int>& nums, int target, int L, int R) {

    while(L <= R) {
        int mid = L + (R - L) / 2;

        if(nums[mid] == target) {
            return true;
        } else {
            if(nums[mid] <= target) {
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }
    }

    return false;
}

int main() {

    // Arreglo ordenado:
    vector<int> nums = {1, 2, 4, 6, 8, 10, 12, 15, 16, 22, 23, 25, 28, 30};

    // Busqueda de los números del 1 al 30 en el arreglo
    for(int i=1; i <= 30; i++) {
        if(binarySearchExiste(nums, i, 0, nums.size()-1)) {
            int pos = binarySearchPos(nums, i, 0, nums.size()-1);
            cout << i << " -> " << pos << endl;
        } else {
            cout << i << " -> NO ENCONTRADO " << endl;
        }
    }

    return 0;
}