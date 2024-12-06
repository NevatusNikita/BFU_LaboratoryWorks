#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

// Увеличение размера стека (автоматической памяти),
// чтобы влезло 3 млн интов, 16777216 - размер стека в байтах.
#pragma comment(linker, "/STACK:16777216")

void bubble_sort(std::vector<int> &mas)
{
    int c = 1;
    while (c != 0) 
    {
        c = 0;
        for (int i = 0; i + 1 < mas.size(); i++) 
        {
            if(mas[i] > mas[i + 1]) 
            {
                std::swap(mas[i], mas[i + 1]);
                c++;
            }
        }
    }
}

void insertion_sort(std::vector<int> &mas)
{
    int n = mas.size();
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (mas[i] > mas[j])
                std::swap(mas[i], mas[j]);
        }
    }
}

void shell_sort(std::vector<int> &mas)
{
    int n = mas.size();
    for (int d = n / 2; d > 0; d /= 2) 
    {
        for (int i = d; i < n; i++) 
        {
            int temp = mas[i];
            int j;
            for (j = i; j >= d && mas[j - d] > temp; j -= d) 
            {
                mas[j] = mas[j - d];
            }
            mas[j] = temp;
        }
    }
}

int partition(std::vector<int> &mas, int low, int high, int pivot){
	int PIndex = low;
    
	// Traverse the array from low to high
    for(int i=low;i<=high;i++) {   
        
        // If the current element is smaller than the pivot element
        if(mas[i]<=pivot) {
            // Swap PIndex element with current element.
            std::swap(mas[PIndex],mas[i]);
            // Increment the pointer.
            PIndex++;
        }
    }
    
    PIndex--;
    
	return PIndex;
}

// We divide the array into two subarrays around 
// the pivot and recursively call for them separately.
void quickSort(std::vector<int> &mas, int low, int high){
	if(low < high) {
	    int pivot = mas[high];
        
            //Rearrange and get the actual pivot index
	    int PIndex = partition(mas, low, high, pivot);
	
            // solve for the left and right subarrays
            quickSort(mas, low, PIndex-1);
            quickSort(mas, PIndex+1, high);
	}
}


int separation(std::vector<int>& mas, int r, int l) 
{
    int base_ind = r + (l - r) / 2; 
    int base_elem = mas[base_ind];
    std::swap(mas[base_ind], mas[l]);
    int i = r;     
    for (int j = r; j < l; j++) 
    {
        if (mas[j] <= base_elem)
        {
            std::swap(mas[j], mas[i]);
            i++;
        }
    }
    std::swap(mas[i], mas[l]); 
    return i; 
}

void quick_sort(std::vector<int>& mas, int r, int l) 
{
    if (r < l) 
    {
        int sep_ind = separation(mas, r, l);
        quick_sort(mas, r, sep_ind - 1); 
        quick_sort(mas, sep_ind + 1, l);  
    }
}

void merge(std::vector<int> &mas, const std::vector<int> &left, const std::vector<int> &right)
{
    int i = 0, k = 0, n = 0;
    while (i < left.size() &&  k < right.size())
    {
        if (left[i] <= right[k])
            mas[n] = left[i++];
        else 
            mas[n] = right[k++];
        n++;
    }
    while (i < left.size())
        mas[n++] = left[i++];
    while (k < right.size())
        mas[n++] = right[k++];
}

void merge_sort(std::vector<int> &mas)
{
    int n = mas.size();
    if (n <= 1)
        return;
    std::vector<int> left;
    std::vector<int> right;
    for (int i = 0; i < n / 2; ++i)
        left.push_back(mas[i]);
    for (int i = n / 2; i < n; ++i)
        right.push_back(mas[i]);
    merge_sort(left);
    merge_sort(right);
    merge(mas, left, right);
}

void heapify(std::vector<int> &mas, int n, int i)
{
    int largest = i;   
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && mas[l] > mas[largest])
        largest = l;
    if (r < n && mas[r] > mas[largest])
        largest = r;
    if (largest != i)
    {
        std::swap(mas[i], mas[largest]);
        heapify(mas, n, largest);
    }
}

void heap_sort(std::vector<int> &mas)
{
    int n = mas.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(mas, n, i);
    for (int i=n-1; i>=0; i--)
    {
        std::swap(mas[0], mas[i]);
        heapify(mas, i, 0);
    }
}

void counting_sort(std::vector<int> &mas)
{
    int n = mas.size();
    int max = INT_MIN;
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (mas[i] > max)
            max = mas[i];
        else if (mas[i] < min)
            min = mas[i];
    }
    std::vector<int> negative_numbers(std::fabs(min) + 1);
    std::vector<int> positive_numbers(max + 1);
    for (int i = 0; i < n; ++i)
    {
        if (mas[i] < 0)
            negative_numbers[std::fabs(mas[i])]++;
        else
            positive_numbers[mas[i]]++;
    }
    int cur = 0;
    for (int i = std::fabs(min); i > 0; --i)
    {
        for (int j = 0; j < negative_numbers[i]; ++j)
        {
            mas[cur] = -i;
            cur++;
        }
    }
    for (int i = 0; i < max + 1; ++i)
    {
        for (int j = 0; j < positive_numbers[i]; ++j)
        {
            mas[cur] = i;
            cur++;
        }
    }
}

int main()
{
	std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    int n;
    in >> n;
    std::vector<int> mas(n);
    for (int i = 0; i < n; ++i)
        in >> mas[i];
    heap_sort(mas);
    for (int i = 0; i < n; ++i)
         out << mas[i] << " ";
}