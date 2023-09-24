#include <vector>
#include <iostream>
#include <chrono>

std::vector<int> Vector;
void swap(std::vector<int>& v, int x, int y);

void create_vector(std::vector <int> v)
{
    for (int i = 0; i < 10000; i++)
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

void swap(std::vector<int>& v, int x, int y) {
    int temp = v[x];
    v[x] = v[y];
    v[y] = temp;

}

void print_vector(std::vector <int> v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << std::endl;
    }
}

void Selection_sort(std::vector <int> v)
{
    int min_index;
    for (size_t i = 0; i < v.size() - 1; i++)
    {
        min_index = i;
        for (size_t j = i + 1; j < v.size(); j++)
        {
            if (v[j] < v[min_index])
            {
                min_index = j;
            }
        }
        std::swap(v[min_index], v[i]);
    }
    Vector = v;
}

int main(int argc, char* argv[])
{
    std::srand(std::time(nullptr));
    create_vector(Vector);
    auto TimeStart = std::chrono::high_resolution_clock::now();
    //bubblesort(Vector);
    //quicksort(Vector,0,Vector.size()-1);
    Selection_sort(Vector);
    auto TimeEnd = std::chrono::high_resolution_clock::now();
    print_vector(Vector);
    std::cout << "Time to sort:" << std::chrono::duration_cast<std::chrono::milliseconds>((TimeEnd) - (TimeStart)).count() << "ms" << std::endl; 
    return 0;
}

