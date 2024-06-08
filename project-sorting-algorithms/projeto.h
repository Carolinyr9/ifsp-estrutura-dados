void bubbleSort(int *array, int size);
void selectionSort(int *array, int size);
void insertionSort(int *array, int size);
int* countingSort(int array[], int size);
void heapSort(int array[], int size);
void mergeSort(int *array, int start, int end);
void timSort(int *array, int size);
void quickSort(int *array, int start, int end);
int radixSortLSD(int *array, size_t size);
void shellSort(int *array, int size);

void showSortingMethodMenu();
void showElementQuantityMenu();
int* allocateAndFillArray(int size, int min, int max);
void shuffleArray(int* array, int size);
double calculateAverageTime(double executionTimes[], int numberOfExecutions);
void sortArrayDescending(int array[], int size);
