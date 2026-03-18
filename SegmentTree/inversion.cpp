// Angel David Avalos Carrillo
// Segment Tree [Inversion] (Algoritmo)

#include <bits/stdc++.h>
using namespace std;

vector<long long> seg;

void update(int idx, int pos, int val, int l, int r) {
    if(l == r) {                                
        seg[idx] = val;
        return;
    }

    int mid = (l + r) / 2;
    if(pos <= mid) {
        update(idx*2, pos, val, l, mid);        
    } else {
        update(idx*2+1, pos, val, mid+1, r);   
    }
    seg[idx] = (seg[idx*2] + seg[idx*2+1]);     
}

long long query(int idx, int l, int r, int ql, int qr) {
    if(ql > r || qr < l) {                      
        return 0;
    }

    if(ql <= l && qr >= r) {                    
        return seg[idx];
    }

    long long mid = (l + r) / 2;
    long long left = query(idx*2, l, mid, ql, qr);        
    long long right = query(idx*2+1, mid+1, r, ql, qr);   

    return (long long)(left + right);                            
}

int main() {
    int n = 0; cin >> n;

    vector<int> vec(n, 0);
    for(auto &v: vec) cin >> v;

    seg.assign(4*n, 0);

    for(int i=0; i < n; i++) {
        int x = vec[i]; 
    
        cout << query(1, 0, n-1, x, n-1) << " "; 
    
        update(1, x-1, 1, 0, n-1);
    }

    return 0;
}