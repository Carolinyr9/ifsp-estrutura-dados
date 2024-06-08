#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main() {
    int* array = NULL;
    double arrayExecutionTime[10];
    double averageTimes, ascOrderTime, decOrderTime;
    int choiceElement, choiceSorting, size;
    int sizeMin = 1, sizeMax = 1000000;
    struct timeval startTime, endTime;

    showSortingMethodMenu();
    scanf("%d", &choiceSorting);

    showElementQuantityMenu();
    scanf("%d", &choiceElement);

    switch (choiceElement) {
        case 1:
            size = 1000;
            break;
        case 2:
            size = 5000;
            break;
        case 3:
            size = 10000;
            break;
        case 4:
            size = 20000;
            break;
        case 5:
            size = 50000;
            break;
        case 6:
            size = 100000;
            break;
        default:
            printf("Opcao invalida escolhida!\n");
            return 1;
    }

    switch (choiceSorting) {
        case 1:
            for (int i = 0; i < 10; i++) {
                array = allocateAndFillArray(size, sizeMin, sizeMax);
                gettimeofday(&startTime, NULL);
                bubbleSort(array, size);
                gettimeofday(&endTime, NULL);
                arrayExecutionTime[i] = (endTime.tv_sec + endTime.tv_usec / 1000000.0) -
                      (startTime.tv_sec + startTime.tv_usec / 1000000.0);

                if(i == 9){
                    gettimeofday(&startTime, NULL);
                    bubbleSort(array, size);
                    gettimeofday(&endTime, NULL);
                    ascOrderTime = (endTime.tv_sec + endTime.tv_usec / 1000000.0) -
                        (startTime.tv_sec + startTime.tv_usec / 1000000.0);

                    sortArrayDescending(array, size);
                    gettimeofday(&startTime, NULL);
                    bubbleSort(array, size);
                    gettimeofday(&endTime, NULL);
                    decOrderTime = (endTime.tv_sec + endTime.tv_usec / 1000000.0) -
                        (startTime.tv_sec + startTime.tv_usec / 1000000.0);
                }
                free(array);
            }
            break;

        case 2:
            for (int i = 0; i < 10; i++) {
                array = allocateAndFillArray(size, sizeMin, sizeMax);
                gettimeofday(&startTime, NULL);
                selectionSort(array, size);
                gettimeofday(&endTime, NULL);
                arrayExecutionTime[i] = (endTime.tv_sec + endTime.tv_usec / 1000000.0) -
                      (startTime.tv_sec + startTime.tv_usec / 1000000.0);
                if(i == 9){
                    gettimeofday(&startTime, NULL);
                    selectionSort(array, size);
                    gettimeofday(&endTime, NULL);
                    ascOrderTime = (endTime.tv_sec + endTime.tv_usec / 1000000.0) -
                        (startTime.tv_sec + startTime.tv_usec / 1000000.0);

                    sortArrayDescending(array, size);
                    gettimeofday(&startTime, NULL);
                    selectionSort(array, size);
                    gettimeofday(&endTime, NULL);
                    decOrderTime = (endTime.tv_sec + endTime.tv_usec / 1000000.0) -
                        (startTime.tv_sec + startTime.tv_usec / 1000000.0);
                }
                free(array);
            }
            break;

        case 3:
            for (int i = 0; i < 10; i++) {
                array = allocateAndFillArray(size, sizeMin, sizeMax);
                gettimeofday(&startTime, NULL);
                insertionSort(array, size);
                gettimeofday(&endTime, NULL);
                arrayExecutionTime[i] = (endTime.tv_sec + endTime.tv_usec / 1000000.0) -
                      (startTime.tv_sec + startTime.tv_usec / 1000000.0);
                if(i == 9){
                    gettimeofday(&startTime, NULL);
                    insertionSort(array, size);
                    gettimeofday(&endTime, NULL);
                    ascOrderTime = (endTime.tv_sec + endTime.tv_usec / 1000000.0) -
                        (startTime.tv_sec + startTime.tv_usec / 1000000.0);

                    sortArrayDescending(array, size);
                    gettimeofday(&startTime, NULL);
                    insertionSort(array, size);
                    gettimeofday(&endTime, NULL);
                    decOrderTime = (endTime.tv_sec + endTime.tv_usec / 1000000.0) -
                        (startTime.tv_sec + startTime.tv_usec / 1000000.0);
                }
                free(array);
            }
            break;

        case 4:
            for (int i = 0; i < 10; i++) {
                array = allocateAndFillArray(size, sizeMin, sizeMax);
                gettimeofday(&startTime, NULL);
                int* sortedArray = countingSort(array, size);
                free(array);
                array = sortedArray;
                gettimeofday(&endTime, NULL);
                arrayExecutionTime[i] = (endTime.tv_sec + endTime.tv_usec / 1000000.0) -
                      (startTime.tv_sec + startTime.tv_usec / 1000000.0);
                if(i == 9){
                    gettimeofday(&startTime, NULL);
                    int* sortedArray = countingSort(array, size);
                    free(array);
                    array = sortedArray;
                    gettimeofday(&endTime, NULL);
                    ascOrderTime = (endTime.tv_sec + endTime.tv_usec / 1000000.0) -
                      (startTime.tv_sec + startTime.tv_usec / 1000000.0);

                    sortArrayDescending(array, size);
                    gettimeofday(&startTime, NULL);
                    sortedArray = countingSort(array, size);
                    free(array);
                    array = sortedArray;
                    gettimeofday(&endTime, NULL);
                    decOrderTime = (endTime.tv_sec + endTime.tv_usec / 1000000.0) -
                      (startTime.tv_sec + startTime.tv_usec / 1000000.0);
                }
                free(array);
            }
            break;

        case 5:
            for (int i = 0; i < 10; i++) {
                array = allocateAndFillArray(size, sizeMin, sizeMax);
                gettimeofday(&startTime, NULL);
                heapSort(array, size);
                gettimeofday(&endTime, NULL);
                arrayExecutionTime[i] = (endTime.tv_sec + endTime.tv_usec / 1000000.0) -
                      (startTime.tv_sec + startTime.tv_usec / 1000000.0);
                if(i == 9){
                    gettimeofday(&startTime, NULL);
                    heapSort(array, size);
                    gettimeofday(&endTime, NULL);
                    ascOrderTime = (endTime.tv_sec + endTime.tv_usec / 1000000.0) -
                        (startTime.tv_sec + startTime.tv_usec / 1000000.0);

                    sortArrayDescending(array, size);
                    gettimeofday(&startTime, NULL);
                    heapSort(array, size);
                    gettimeofday(&endTime, NULL);
                    decOrderTime = (endTime.tv_sec + endTime.tv_usec / 1000000.0) -
                        (startTime.tv_sec + startTime.tv_usec / 1000000.0);
                }
                free(array);
            }
            break;

        case 6:
            for (int i = 0; i < 10; i++) {
                array = allocateAndFillArray(size, sizeMin, sizeMax);
                gettimeofday(&startTime, NULL);
                mergeSort(array, 0, size - 1);
                gettimeofday(&endTime, NULL);
                arrayExecutionTime[i] = (endTime.tv_sec + endTime.tv_usec / 1000000.0) -
                      (startTime.tv_sec + startTime.tv_usec / 1000000.0);
                if(i == 9){
                    gettimeofday(&startTime, NULL);
                    mergeSort(array, 0, size - 1);
                    gettimeofday(&endTime, NULL);
                    ascOrderTime = (endTime.tv_sec + endTime.tv_usec / 1000000.0) -
                        (startTime.tv_sec + startTime.tv_usec / 1000000.0);

                    sortArrayDescending(array, size);
                    gettimeofday(&startTime, NULL);
                    mergeSort(array, 0, size - 1);
                    gettimeofday(&endTime, NULL);
                    decOrderTime = (endTime.tv_sec + endTime.tv_usec / 1000000.0) -
                        (startTime.tv_sec + startTime.tv_usec / 1000000.0);
                }
                free(array);
            }
            break;

        case 7:
            for (int i = 0; i < 10; i++) {
                array = allocateAndFillArray(size, sizeMin, sizeMax);
                gettimeofday(&startTime, NULL);
                timSort(array, size);
                gettimeofday(&endTime, NULL);
                arrayExecutionTime[i] = (endTime.tv_sec + endTime.tv_usec / 1000000.0) -
                      (startTime.tv_sec + startTime.tv_usec / 1000000.0);
                if(i == 9){
                    gettimeofday(&startTime, NULL);
                    timSort(array, size);
                    gettimeofday(&endTime, NULL);
                    ascOrderTime = (endTime.tv_sec + endTime.tv_usec / 1000000.0) -
                        (startTime.tv_sec + startTime.tv_usec / 1000000.0);

                    sortArrayDescending(array, size);
                    gettimeofday(&startTime, NULL);
                    timSort(array, size);
                    gettimeofday(&endTime, NULL);
                    decOrderTime = (endTime.tv_sec + endTime.tv_usec / 1000000.0) -
                        (startTime.tv_sec + startTime.tv_usec / 1000000.0);
                }
                free(array);
            }
            break;

        case 8:
            for (int i = 0; i < 10; i++) {
                array = allocateAndFillArray(size, sizeMin, sizeMax);
                gettimeofday(&startTime, NULL);
                quickSort(array, 0, size - 1);
                gettimeofday(&endTime, NULL);
                arrayExecutionTime[i] = (endTime.tv_sec + endTime.tv_usec / 1000000.0) -
                      (startTime.tv_sec + startTime.tv_usec / 1000000.0);
                if(i == 9){
                    gettimeofday(&startTime, NULL);
                    quickSort(array, 0, size - 1);
                    gettimeofday(&endTime, NULL);
                    ascOrderTime = (endTime.tv_sec + endTime.tv_usec / 1000000.0) -
                        (startTime.tv_sec + startTime.tv_usec / 1000000.0);

                    sortArrayDescending(array, size);
                    gettimeofday(&startTime, NULL);
                    quickSort(array, 0, size - 1);
                    gettimeofday(&endTime, NULL);
                    decOrderTime = (endTime.tv_sec + endTime.tv_usec / 1000000.0) -
                        (startTime.tv_sec + startTime.tv_usec / 1000000.0);
                }
                free(array);
            }
            break;

        case 9:
            for (int i = 0; i < 10; i++) {
                array = allocateAndFillArray(size, sizeMin, sizeMax);
                gettimeofday(&startTime, NULL);
                shellSort(array, size);
                gettimeofday(&endTime, NULL);
                arrayExecutionTime[i] = (endTime.tv_sec + endTime.tv_usec / 1000000.0) -
                      (startTime.tv_sec + startTime.tv_usec / 1000000.0);
                if(i == 9){
                    gettimeofday(&startTime, NULL);
                    shellSort(array, size);
                    gettimeofday(&endTime, NULL);
                    ascOrderTime = (endTime.tv_sec + endTime.tv_usec / 1000000.0) -
                        (startTime.tv_sec + startTime.tv_usec / 1000000.0);

                    sortArrayDescending(array, size);
                    gettimeofday(&startTime, NULL);
                    shellSort(array, size);
                    gettimeofday(&endTime, NULL);
                    decOrderTime = (endTime.tv_sec + endTime.tv_usec / 1000000.0) -
                        (startTime.tv_sec + startTime.tv_usec / 1000000.0);
                }
                free(array);
            }
            break;

        case 10:
            for (int i = 0; i < 10; i++) {
                array = allocateAndFillArray(size, sizeMin, sizeMax);
                gettimeofday(&startTime, NULL);
                radixSortLSD(array, size);
                gettimeofday(&endTime, NULL);
                arrayExecutionTime[i] = (endTime.tv_sec + endTime.tv_usec / 1000000.0) -
                      (startTime.tv_sec + startTime.tv_usec / 1000000.0);
                if(i == 9){
                    gettimeofday(&startTime, NULL);
                    radixSortLSD(array, size);
                    gettimeofday(&endTime, NULL);
                    ascOrderTime = (endTime.tv_sec + endTime.tv_usec / 1000000.0) -
                        (startTime.tv_sec + startTime.tv_usec / 1000000.0);

                    sortArrayDescending(array, size);
                    gettimeofday(&startTime, NULL);
                    radixSortLSD(array, size);
                    gettimeofday(&endTime, NULL);
                    decOrderTime = (endTime.tv_sec + endTime.tv_usec / 1000000.0) -
                        (startTime.tv_sec + startTime.tv_usec / 1000000.0);
                }
                free(array);
            }
            break;

        default:
            printf("Opcao invalida escolhida!\n");
            free(array);
            return 1;
    }

    printf("\nTempos de execucao:\n");
    for (int i = 0; i < 10; i++) {
        printf("%f ", arrayExecutionTime[i]);
    }

    averageTimes = calculateAverageTime(arrayExecutionTime, 10);
    printf("\nTempo para ordenar array crescente: %f", ascOrderTime);
    printf("\nTempo para ordenar array decrescente: %f\n", decOrderTime);

    free(array);
    return 0;
}
