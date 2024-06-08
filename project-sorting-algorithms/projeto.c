#include <assert.h>
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <sys/time.h>

#define MIN_RUN 32
#define DECIMAL 10
#define T int

void showSortingMethodMenu() {
    printf("\n\tEscolha um algoritmo de ordenacao");
    printf("\n1- Bubble Sort");
    printf("\n2- Selection Sort");
    printf("\n3- Insertion Sort");
    printf("\n4- Counting Sort");
    printf("\n5- Heap Sort");
    printf("\n6- Merge Sort");
    printf("\n7- Tim Sort");
    printf("\n8- Quick Sort");
    printf("\n9- Shell Sort");
    printf("\n10 - Radix Sort");
    printf("\nDigite o numero do algoritmo escolhido: ");
}

void showElementQuantityMenu() {
    printf("\n\tEscolha a quantidade de elementos a serem ordenados");
    printf("\n1- 1.000");
    printf("\n2- 5.000");
    printf("\n3- 10.000");
    printf("\n4- 20.000");
    printf("\n5- 50.000");
    printf("\n6- 100.000");
    printf("\nDigite o numero equivalente a quantidade escolhida: ");
}

int* allocateAndFillArray(int size, int min, int max) {
    int* array = (int*)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Erro na alocação de memória!\n");
        exit(1);
    }

    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        array[i] = rand() % (max - min + 1) + min;
    }

    return array;
}

// Função embaralha array
void shuffleArray(int* array, int size) {
    for (int i = size - 2; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[j];
        array[j] = array[i];
        array[i] = temp;
    }
}

double calculateAverageTime(double executionTimes[], int numberOfExecutions) {
    double sum = 0.0;
    for(int i = 0; i < numberOfExecutions; i++) {
        sum += executionTimes[i];
    }
    double average = sum / numberOfExecutions;
    printf("\n\nMedia dos tempos: %f", average);
    return average;
}

void sortArrayDescending(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i; j < size - 1; j++) {
            if (array[i] < array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

// Bubble Sort
void bubbleSort(int *array, int size) {
    int temp, sorted, end = size;
    do {
        sorted = 0;
        for (int i = 0; i < end - 1; i++) {
            if (array[i] > array[i + 1]) {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                sorted = i;
            }
        }
        end--;
    } while (sorted != 0);
}

// Selection Sort
void selectionSort(int *array, int size) {
    int minIndex, temp;
    for (int i = 0; i < size - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        if (i != minIndex) {
            temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}

// Insertion Sort
void insertionSort(int *array, int size) {
    int temp, j;
    for (int i = 1; i < size; i++) {
        temp = array[i];
        for (j = i; j > 0 && (temp < array[j - 1]); j--) {
            array[j] = array[j - 1];
        }
        array[j] = temp;
    }
}

// Counting Sort
int* countingSort(int array[], int size) {
    int maxVal = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > maxVal) {
            maxVal = array[i];
        }
    }

    int *count = (int *)calloc(maxVal + 1, sizeof(int));
    int *output = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    for (int i = 1; i <= maxVal; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    free(count);
    return output;
}

// Heap Sort
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int array[], int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && array[left] > array[largest]) {
        largest = left;
    }

    if (right < size && array[right] > array[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&array[i], &array[largest]);
        heapify(array, size, largest);
    }
}

void heapSort(int array[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(array, size, i);
    }

    for (int i = size - 1; i > 0; i--) {
        swap(&array[0], &array[i]);
        heapify(array, i, 0);
    }
}

// Merge Sort
void merge(int *array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) {
        L[i] = array[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = array[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k++] = L[i++];
        } else {
            array[k++] = R[j++];
        }
    }

    while (i < n1) {
        array[k++] = L[i++];
    }
    while (j < n2) {
        array[k++] = R[j++];
    }

    free(L);
    free(R);
}

void mergeSort(int *array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

// Tim Sort
void insertionSortTim(int *array, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = array[i];
        int j = i;
        while (j > left && temp < array[j - 1]) {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = temp;
    }
}

int minRunLength(int size) {
    int r = 0;
    while (size >= MIN_RUN) {
        r |= (size & 1);
        size >>= 1;
    }
    return size + r;
}

void timSort(int *array, int size) {
    int minRun = minRunLength(size);

    for (int start = 0; start < size; start += minRun) {
        int end = (start + minRun - 1 < size - 1) ? (start + minRun - 1) : (size - 1);
        insertionSortTim(array, start, end);
    }

    int runSize = minRun;
    while (runSize < size) {
        for (int left = 0; left < size; left += 2 * runSize) {
            int mid = left + runSize - 1;
            int right = (left + 2 * runSize - 1 < size - 1) ? (left + 2 * runSize - 1) : (size - 1);
            merge(array, left, mid, right);
        }
        runSize = 2 * runSize;
    }
}

// Quick Sort
int partition(int *array, int start, int end) {
    int pivot = array[start];
    int left = start + 1;
    int right = end;
    int temp;

    while (left <= right) {
        while (left <= right && array[left] <= pivot) {
            left++;
        }
        while (left <= right && array[right] > pivot) {
            right--;
        }
        if (left < right) {
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            left++;
            right--;
        }
    }
    array[start] = array[right];
    array[right] = pivot;

    return right;
}

void quickSort(int *array, int start, int end) {
    if (start < end) {
        int pivotIndex = partition(array, start, end);
        quickSort(array, start, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, end);
    }
}

// Radix Sort
static int getMax(const int *array, size_t size) {
    int max = array[0];
    for (size_t i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

int countingSortForRadix(int *array, size_t size, int exponent) {
    int count[DECIMAL] = {0};
    int *output = (int *)malloc(size * sizeof(int));
    if (output == NULL) {
        return ENOMEM;
    }

    for (size_t i = 0; i < size; i++) {
        count[(array[i] / exponent) % DECIMAL]++;
    }

    for (size_t i = 1; i < DECIMAL; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / exponent) % DECIMAL] - 1] = array[i];
        count[(array[i] / exponent) % DECIMAL]--;
    }

    for (size_t i = 0; i < size; i++) {
        array[i] = output[i];
    }

    free(output);
    return EXIT_SUCCESS;
}

int radixSortLSD(int *array, size_t size) {
    int maxVal = getMax(array, size);
    for (int exponent = 1; maxVal / exponent > 0; exponent *= DECIMAL) {
        int result = countingSortForRadix(array, size, exponent);
        assert(result == EXIT_SUCCESS);
        if (result != EXIT_SUCCESS) {
            return result;
        }
    }

    return EXIT_SUCCESS;
}

// Shell Sort
void shellSort(int *array, int size) {
    int interval;
    for (interval = 1; interval < size / 3; interval = 3 * interval + 1);

    while (interval > 0) {
        for (int i = interval; i < size; i++) {
            int temp = array[i];
            int j = i;
            while (j >= interval && array[j - interval] > temp) {
                array[j] = array[j - interval];
                j -= interval;
            }
            array[j] = temp;
        }
        interval = (interval - 1) / 3;
    }
}
