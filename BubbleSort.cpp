void swap (int *a, int *b){
    int tmp = *b;
    *b = *a;
    *a = tmp;
}
void BubbleSort (int* first, int* last){
    int size = last - first;
    for(int i=0; i<size; ++i){
        for(int j=1; j<size-i; ++j){
           if(first[j] < first[j-1]){
              swap(&first[j-1], &first[j]);
            }
        }
    }
}
