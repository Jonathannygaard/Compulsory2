#include <vector>
#include <iostream>
#include <chrono>

std::vector<int> Vector;

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
    int i, j;
    bool swapped;
    for (i = 0; i < v.size() - 1; i++)
    {
        swapped = false;
        for (j = 0; j < v.size() - i - 1; j++)
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

void print_vector(std::vector <int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << std::endl;
    }
}

int main(int argc, char* argv[])
{
    std::srand(std::time(nullptr));
    create_vector(Vector);
    bubblesort(Vector);
    print_vector(Vector);
    return 0;
}

