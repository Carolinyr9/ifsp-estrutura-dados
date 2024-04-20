int i, j, k, s;
// Resultado simplificado: 3n^3 + 4n^2 + 6n + 3
// Resultado: 3 + 3n + n (3n^2 + 4n + 3) = 3 + 3n + 3n^3 + 4n^2 + 3n = 3n^3 + 4n^2 + 6n + 3
for(i = 0; i < n - 1, i++){ // 3 + 3n
    // 3 + 2n + n (3n + 2) = 3 + 2n + 3n^2 + 2n = 3n^2 + 4n + 3
    for (j = i + 1; j < n; j++){ // 3 + 2n
        // 2 + 2n + n = 3n + 2
        for(k = 1; k < j; k++){ // 2 + 2n
            s = 1; // n
        }
    }
}
