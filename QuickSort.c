
void QuickSort(int* array, int n);
void Qsort(int* array, int right, int left);
int Partition(int* array, int right, int left);
void swap(int* array, int a, int b);
void InsertionSort(int* array, int right, int left);
void Isort(int* array, int n);

#define MAX_INSERTION_LENGTH 7

void QuickSort(int* array, int n)
{
	Qsort(array, 0, n - 1);
}

void Qsort(int* array, int right, int left)
{
	int point;
	if (left - right > MAX_INSERTION_LENGTH)
	{
		while (right < left)
		{
			//产生尾递归， 使之不断递归分小
			point = Partition(array, right, left);
			if (point - right < left - point)
			{
				Qsort(array, right, point - 1);
				right = point + 1;
			}
			else
			{
				Qsort(array, point + 1, left);
				left = point - 1;
			}
		}
	}
	else
	{
		InsertionSort(array, right, left);
	}
}
int Partition(int* array, int right, int left)
{
	int point;
	int m = (left + right) / 2;
	if (array[right] > array[left])
		swap(array, right, left);
	if (array[m] > array[left])
		swap(array, m, left);
	if (array[m] > array[right])
		swap(array, m, right);
	point = array[right];
	while (right < left)
	{
		while (right < left && array[left] >= point)
			left--;
		array[right] = array[left];
		while (right < left && array[right] <= point)
			right++;
		array[left] = array[right];
	}
	array[right] = point;
	return right;
}
void swap(int* array, int a, int b)
{
	int temp;
	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

void InsertionSort(int* array, int right, int left)
{
	Isort(array + right, left - right + 1);
}


void Isort(int* array, int n)
{
	int i, j, key;
	for (i = 1; i < n; i++)
	{
		key = array[i];
		for (j = i - 1; j >= 0  && key < array[j]; j--)
		{
			array[j + 1] = array[j];
		}
		array[j + 1] = key;
	}
}
