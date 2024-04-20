int i, j, k;
// Resultado simplificado: 5n^2 + 6n + 4
// Resultado: 5n^2 + 6n + 3 + 1 = 5n^2 + 6n + 4
s = 0; // 1
// 3 + 3n + n (3 + 5n) = 3 + 3n + 3n + 5n^2 = 5n^2 + 6n + 3
for(i = 1; i < n - 1; i++){ // 3 + 3n
    // 3 + 3n + 2n = 3 + 5n
    for(j = 1; j < 2 * n; j++){ // 3 + 3n
        s = s + 1; // 2n
    }
}
