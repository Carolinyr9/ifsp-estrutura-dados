int i, j, k;
// Resultado simplificado: 5n^3 + 5n^2 + 4n + 2
// Resultado: 2 + 2n + n (5n^2 + 5n + 2) = 2 + 2n + 5n^3 + 5n^2 + 2n = 5n^3 + 5n^2 + 4n + 2
for(i = 0; i < n; i++){ // 2 + 2n
    // 2 + 2n + n + n (2 + 5n) = 3n + 2 + 2n + 5n^2 = 5n^2 + 5n + 2
    for(j = 0; j < n; j++){ // 2 + 2n
        r[i][j] = 0; // 1n
        // 2 + 2n + 3n = 2 + 5n
        for(k = 0; k < n; k++){ // 2 + 2n
            r[i][j] += a[i][j] * b[k][j]; // (3n)
        }
    }
}
