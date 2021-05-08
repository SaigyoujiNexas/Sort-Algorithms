void ShellSort(int* arr, int n)
{
	int j;
	int temp;
	int gap = n;
	do 
	{
		gap--;
		for (int i = gap; i < n; i += gap)
		{
			temp = arr[i];
			j = i - gap;
			while (j >= 0 && arr[j] > temp)
			{
				arr[j + gap] = arr[j];
				j -= gap;
			}
			arr[j + gap] = temp;
		}
	} while (gap > 1);
}
