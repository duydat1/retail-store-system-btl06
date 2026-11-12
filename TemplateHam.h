#pragma once
#include <bits/stdc++.h>

using namespace std;

// ================= 1. 04 HÀM TEMPLATE CƠ BẢN(MỤC 12.2) =================
template <class T>
void hoanDoi(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
T timMax(T a, T b){
    return(a > b) ? a : b;
}

template <class T>
T timMin(T a, T b){
    return(a < b) ? a : b;
}

template <class T>
int timKiemTuanTu(T ds[], int n, T x){
    for(int i = 0; i < n; i++){
        if(ds[i] == x) return i;
    }
    return -1;
}

// ================= 2. 03 THUẬT TOÁN TÌM KIẾM(MỤC 12.5) =================
//(1) Tìm kiếm tuần tự theo điều kiện tùy chỉnh(tìm theo mã, tên, phòng ban...)
template <class T, typename Predicate>
int sequentialSearch(T ds[], int n, Predicate dieuKien){
    for(int i = 0; i < n; i++){
        if(dieuKien(ds[i])) return i;
    }
    return -1;
}

//(2) Tìm kiếm nhị phân(Mảng BẮT BUỘC phải sắp xếp tăng dần trước)
// getKey: hàm lấy giá trị khóa của đối tượng(ví dụ: [](const KhachHang& k){ return k.getMa(); })
template <class T, class Key, typename KeyExtractor>
int binarySearch(T ds[], int n, Key target, KeyExtractor getKey){
    int left = 0, right = n - 1;
    while(left <= right){
        int mid = left +(right - left) / 2;
        Key midVal = getKey(ds[mid]);
        if(midVal == target) return mid;
        if(midVal < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

//(3) Tìm kiếm nội suy(Áp dụng cho khóa là SỐ đã sắp xếp tăng dần: lương, đơn giá, điểm...)
template <class T, typename NumberExtractor>
int interpolationSearch(T ds[], int n, double target, NumberExtractor getNum){
    int low = 0, high = n - 1;
    while(low <= high && target >= getNum(ds[low]) && target <= getNum(ds[high])){
        double lowVal = getNum(ds[low]);
        double highVal = getNum(ds[high]);

        // Xử lý trường hợp các khóa bằng nhau(tránh chia cho 0 theo đúng yêu cầu đề)
        if(lowVal == highVal){
            if(lowVal == target) return low;
            return -1;
        }

        int pos = low +(((double)(high - low) /(highVal - lowVal)) *(target - lowVal));
        double posVal = getNum(ds[pos]);

        if(posVal == target) return pos;
        if(posVal < target) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

// ================= 3. 04 THUẬT TOÁN SẮP XẾP(MỤC 12.6) =================
// cmp(a, b) trả về true nếu a đứng trước b

//(1) Bubble Sort
template <class T, typename Compare>
void bubbleSort(T ds[], int n, Compare cmp){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(!cmp(ds[j], ds[j + 1])){
                hoanDoi(ds[j], ds[j + 1]);
            }
        }
    }
}

//(2) Selection Sort
template <class T, typename Compare>
void selectionSort(T ds[], int n, Compare cmp){
    for(int i = 0; i < n - 1; i++){
        int idx = i;
        for(int j = i + 1; j < n; j++){
            if(cmp(ds[j], ds[idx])) idx = j;
        }
        if(idx != i) hoanDoi(ds[i], ds[idx]);
    }
}

//(3) Quick Sort
template <class T, typename Compare>
int partitionQS(T ds[], int low, int high, Compare cmp){
    T pivot = ds[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(cmp(ds[j], pivot)){
            i++;
            hoanDoi(ds[i], ds[j]);
        }
    }
    hoanDoi(ds[i + 1], ds[high]);
    return i + 1;
}

template <class T, typename Compare>
void quickSort(T ds[], int low, int high, Compare cmp){
    if(low < high){
        int pi = partitionQS(ds, low, high, cmp);
        quickSort(ds, low, pi - 1, cmp);
        quickSort(ds, pi + 1, high, cmp);
    }
}

//(4) Merge Sort
template <class T, typename Compare>
void mergeArr(T ds[], int left, int mid, int right, Compare cmp){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    T* L = new T[n1];
    T* R = new T[n2];

    for(int i = 0; i < n1; i++) L[i] = ds[left + i];
    for(int j = 0; j < n2; j++) R[j] = ds[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2){
        if(cmp(L[i], R[j])) ds[k++] = L[i++];
        else ds[k++] = R[j++];
    }
    while(i < n1) ds[k++] = L[i++];
    while(j < n2) ds[k++] = R[j++];

    delete[] L;
    delete[] R;
}

template <class T, typename Compare>
void mergeSort(T ds[], int left, int right, Compare cmp){
    if(left < right){
        int mid = left +(right - left) / 2;
        mergeSort(ds, left, mid, cmp);
        mergeSort(ds, mid + 1, right, cmp);
        mergeArr(ds, left, mid, right, cmp);
    }
}