int partition(int *first, int *last, int pivot) {
    int l = 0;
    int r = last - first -1;
    while (true){
        while (first[l] < pivot) ++l;
        while (first[r] >= pivot) --r;
        if (l >= r) return l;
        swap(&first[l], &first[r]);
    }
}

void QuickSort(int *first, int *last){
    int size = last - first;
    if (size <= 1) return;
    // pivotの決定
    // 先頭・真ん中・末尾の中央値
    int a = first[0];
    int b = first[size/2];
    int c = first[size-1];
    int pivot;
    if ((a-b)*(b-c)*(c-a) != 0){
        pivot = max(min(a,b), min(max(a,b),c));
    } else { // 中央値が取れない場合は最初に見つかった異なる2つの数のうち大きい方
        bool flag = true;
        for (int i=1; i<size; ++i){
            if (first[i-1] != first[i]) {
                pivot = max(first[i-1], first[i]);
                flag = false;
                break;
            }
        }
        if (flag) return; // 全て同じならソート済みと判定
    }
    int k = partition(first, last, pivot); // 配列の分割
    QuickSort(first, first+k);
    QuickSort(first+k, last);
}
