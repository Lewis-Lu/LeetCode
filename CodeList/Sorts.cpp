#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> result;

class BubbleSort
{
private:
    /* data */
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

public:
    void Sort(vector<int> &nums)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = 0; j < nums.size() - 1; j++)
            {
                if (nums[j] > nums[j + 1])
                    swap(nums[j], nums[j + 1]);
            }
        }
    }
};

class QuickSort
{
private:
    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    int Partition(vector<int> &nums, int begin, int end)
    {
        int l = begin, r = end;
        int base = nums[l];

        // this loop ends when l == r, where pivot at
        while (l < r)
        {
            while (l < r && nums[r] > base)
                --r;
            swap(&nums[l], &nums[r]);
            while (l < r && nums[l] <= base)
                ++l;
            swap(&nums[l], &nums[r]);
        }
        return l;
    }

    void qSort(vector<int> &nums, int begin, int end)
    {
        // sub-problem return
        if (begin >= end)
            return;

        // recursive sorting
        int mid = Partition(nums, begin, end);
        qSort(nums, begin, mid - 1);
        qSort(nums, mid + 1, end);
    }

public:
    void Sort(vector<int> &nums)
    {
        qSort(nums, 0, nums.size() - 1);
    }
};

// different from BubbleSort swapping adjuntive elements
// SelectSort swap elements from whole vector
class SelectSort
{
private:
    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void selectSort(vector<int> &nums)
    {
        if (nums.empty())
            return;
        int minIndex = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            minIndex = i;
            for (int j = i + 1; j < nums.size() - 1; j++)
            {
                if (nums[minIndex] > nums[j])
                    minIndex = j;
            }
            // find smaller value
            if (minIndex != i)
                swap(&nums[i], &nums[minIndex]);
        }
    }

public:
    void Sort(vector<int> &nums)
    {
        selectSort(nums);
    }
};

// like playing cards sorting

class InsertSort
{
private:
public:
    void insertSort(vector<int> &nums)
    {
        if (nums.empty())
            return;
        for (int i = 1; i < nums.size(); i++)
        {
            int j = i;
            int target = nums[j];
            while (j >= 0 && target < nums[j - 1])
            {
                nums[j] = nums[j - 1];
                j--;
            }
            nums[j] = target;
        }
    }
};

// two problems in heap sort
// 1. how to build up the heap from unarranged vector
// 2. how to adjust the heap after taking away the top element

// array index starts from 0
class HeapSort
{
private:
    void swap(int *a, int *b)
    {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
    // adjust heap to little heap
    void AdjustHeap(vector<int> &heap, int top, int n)
    {
        int j = 2 * top + 1; // point to first left child
        int tmp = heap[top];

        while (j < n)
        {
            // if right child is smaller, go to right child
            if (j < n && heap[j] > heap[j + 1])
                ++j;

            // right child is smaller too, check temporature right!
            if (heap[j] >= tmp)
                break;

            // heap[j] < tmp , swap value
            heap[top] = heap[j];

            // go deeper to find smaller value
            top = j;
            j = 2 * top + 1;
        }
        heap[top] = tmp;
    }

    // practise
    void HeapAdjust(vector<int> &heap, int top, int n)
    {
        int temp = heap[top];
        int j = top * 2 + 1;

        while (j < n)
        {
            if (j < n && heap[j] > heap[j + 1])
                ++j;

            if (heap[j] >= temp)
                break;

            heap[top] = heap[j];

            top = j;
            j = 2 * top + 1;
        }
        heap[top] = temp;
    }

    void BuildHeap(vector<int> &nums, int n)
    {
        int begin = ((n - 1) - 1) / 2;
        for (int i = begin; i >= 0; i--)
        {
            AdjustHeap(nums, i, n);
        }
    }

    void CreateHeap(vector<int> &nums)
    {
        if (nums.empty())
            return;
        BuildHeap(nums, nums.size());
    }

public:
    void heapSort(vector<int> &nums)
    {
        // createheap first
        CreateHeap(nums);

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            swap(&nums[0], &nums[i]);
            AdjustHeap(nums, 0, i - 1);
        }
    }
};

// divide and conquer
// using recursive way to sort
class MergeSort
{
private:
    // merge two sorted arrays
    void merge(vector<int> &nums, int left, int right, int mid)
    {
        vector<int> tmp;
        int
            p = left,
            q = mid + 1;

        while (p <= mid && q <= right)
        {
            if (nums[p] <= nums[q])
            {
                tmp.push_back(nums[p++]);
            }
            else
            {
                tmp.push_back(nums[q++]);
            }
        }
        while (p <= mid) tmp.push_back(nums[p++]);
        while (q <= right) tmp.push_back(nums[q++]);

        // recursive so left is the boundry
        for (int i = 0; i < tmp.size(); i++)
        {
            nums[left + i] = tmp[i];
        }
    }
public:
    void mergeSort(vector<int>& nums, int left, int right){
        if(left >= right) return;
        int mid = (left + right)/2;
        
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);
        merge(nums,left, right, mid);
    }

};

int main(int argc, char const *argv[])
{
    vector<int> m1 = {1, 2, 5, 4, 5, 6};
    vector<int> nums = {1, 2, 5, 4, 5, 6,4,6,1,7,6,4,12,4,6,1};
    vector<int>::iterator iter;
    // BubbleSort bubble;
    // bubble.Sort(nums);

    // QuickSort q;
    // q.Sort(nums);

    // SelectSort s;
    // s.Sort(nums);

    // InsertSort i;
    // i.insertSort(nums);

    // HeapSort h;
    // h.heapSort(nums);

    MergeSort m;
    m.mergeSort(nums,0,nums.size()-1);

    for (iter = nums.begin(); iter != nums.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
    return 0;
}
