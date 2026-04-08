// Angel David Avalos Carrillo - 22130800
// Segment Tree [for sum] (Algoritmo)

#include <bits/stdc++.h>
using namespace std;

vector<long long> seg;

void build(vector<int>& nums, int idx, int l, int r) {
    if(l == r) {                            // Llegamos a una hoja
        seg[idx] = nums[l];         
        return;
    }

    int mid = (l + r) / 2;                  
    build(nums, idx*2, l, mid);             // Hijo izquierdo
    build(nums, idx*2+1, mid+1, r);           // Hijo derecho
    seg[idx] = seg[idx*2] + seg[idx*2+1];   // Suma de ese rango

}

void update(int idx, int pos, int val, int l, int r) {
    if(l == r) {                                // Llegamos a la hoja
        seg[idx] = val;
        return;
    }

    int mid = (l + r) / 2;
    if(pos <= mid) {
        update(idx*2, pos, val, l, mid);        // Nos vamos a la izquierda si la posición que queremos actualizar esta ahí
    } else {
        update(idx*2+1, pos, val, mid+1, r);    // A la derecha si el indice esta ahí
    }
    seg[idx] = seg[idx*2] + seg[idx*2+1];       // Actualizamos la suma
}

long long query(int idx, int l, int r, int ql, int qr) {
    if(ql > r || qr < l) {                      // El rango buscado esta fuera del rango actual (0 no suma nada)
        return 0;
    }

    if(ql <= l && qr >= r) {                    // El rango buscado esta dentro del rango actual
        return seg[idx];
    }

    long long mid = (l + r) / 2;
    long long left = query(idx*2, l, mid, ql, qr);        // Guardamos la suma del rango izquierdo
    long long right = query(idx*2+1, mid+1, r, ql, qr);   // Guardamos la suma del rango derecho

    return (long long)left + right;                            // Retornamos la suma de ambos rangos
}

int main() {
    int n, m; cin >> n >> m;

    vector<int> nums(n, 0);

    for(auto &a: nums) cin >> a;

    seg.assign(4*n, 0);
    build(nums, 1, 0, n-1);

    while(m--) {
        int q, q1, q2; cin >> q >> q1 >> q2;

        if(q == 1) {
            update(1, q1, q2, 0, n-1);
        } else {
            cout << query(1, 0, n-1, q1, q2-1) << endl;
        }
    }

    return 0;
}