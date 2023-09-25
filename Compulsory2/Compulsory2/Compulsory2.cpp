#include <vector>
#include <iostream>
#include <chrono>

std::vector<int> Vector;
void swap(std::vector<int>& v, int x, int y);
int Sorting;
int Size;

void create_vector(std::vector <int> v)
{
    for (int i = 0; i < Size; i++)
    {
        v.push_back(rand() % 10000);
    }
    Vector = v;
}

void bubblesort(std::vector <int> v)
{
    bool swapped;
    for (size_t i = 0; i < v.size() - 1; i++)
    {
        swapped = false;
        for (size_t j = 0; j < v.size() - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                std::swap(v[j], v[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
    Vector = v;
}

void swap(std::vector<int>& v, int x, int y) {
    int temp = v[x];
    v[x] = v[y];
    v[y] = temp;

}

void quicksort(std::vector<int> &vec, int L, int R) {
    int i, j, mid, piv;
    i = L;
    j = R;
    mid = L + (R - L) / 2;
    piv = vec[mid];

    while (i<R || j>L) {
        while (vec[i] < piv)
            i++;
        while (vec[j] > piv)
            j--;

        if (i <= j) {
            swap(vec, i, j);
            i++;
            j--;
        }
        else {
            if (i < R)
                quicksort(vec, i, R);
            if (j > L)
                quicksort(vec, L, j);
            return;
        }
    }
}

void merge(std::vector<int>& vec, int L, int M, int R) {
    int i, j, k;
    int n1 = M - L + 1;
    int n2 = R - M;

    std::vector<int> L_vec(n1);
    std::vector<int> R_vec(n2);

    for (i = 0; i < n1; i++)
        L_vec[i] = vec[L + i];
    for (j = 0; j < n2; j++)
        R_vec[j] = vec[M + 1 + j];

    i = 0;
    j = 0;
    k = L;

    while (i < n1 && j < n2) {
        if (L_vec[i] <= R_vec[j]) {
            vec[k] = L_vec[i];
            i++;
        }
        else {
            vec[k] = R_vec[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vec[k] = L_vec[i];
        i++;
        k++;
    }

    while (j < n2) {
        vec[k] = R_vec[j];
        j++;
        k++;
    }
}

void merge_sort(std::vector<int>& vec, int L, int R) {
    if (L < R) {
        int M = (L + R) / 2;
        merge_sort(vec, L, M);
        merge_sort(vec, M + 1, R);
        merge(vec, L, M, R);
    }
}
void print_vector(std::vector <int> v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << std::endl;
    }
}

int main(int argc, char* argv[])
{
    std::srand(std::time(nullptr));
    std::cout << "How many numbers in vector?" << std::endl;
    std::cin >> Size;
    create_vector(Vector);
    std::cout << "Choose sorting algorithm:"<< "\n" << "1. Bubblesort" << "\n" << "2. Quicksort" << "\n" << "3. Mergesort"<< std::endl;
    std::cin >> Sorting;
    auto TimeStart = std::chrono::high_resolution_clock::now();
    switch (Sorting)
    {
        case 1:
            bubblesort(Vector);
            break;
        case 2:
            quicksort(Vector, 0, Vector.size() - 1);
            break;
         default:
            merge_sort(Vector, 0, Vector.size() - 1);
            break;
    }
    auto TimeEnd = std::chrono::high_resolution_clock::now();
    print_vector(Vector);
    std::cout << "Time to sort:" << std::chrono::duration_cast<std::chrono::milliseconds>((TimeEnd) - (TimeStart)).count() << "ms" << std::endl; 
    return 0;
}

