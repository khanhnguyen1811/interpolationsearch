//pos = id_0 + ((id_cuoi - id_dau)/ (value_ind_cuoi - value_id_dau))* (num - value_id_dau)

#include <iostream> 
using namespace std; 
int InterpolationSearch(int arr[], int sopt, int num){
	int pos; 
	int low = 0, high = sopt - 1; 
	while (low <= high && arr[low] <= num && arr[high] >= num)
	{
		pos = low + ((high - low) / (arr[high] - arr[low])) * (num - arr[low]);
		if (arr[pos] == num)
		{
			return pos; 
		}
		else if (arr[pos] < num)
		{
			low = pos + 1; 
		}
		else
		{
			high = pos - 1; 
		}
	}
	return -1;
}

int main(){
	int arr[100], i, sopt; 
	cout << "nhap so pt: "; cin >> sopt; 
	cout << "nhap mang : " << "\n";
	for (i = 0; i < sopt; i++)
	{
		cin >> arr[i];
	}
	int x; 
	cout << "nhap x: "; cin >> x; 
	int location = InterpolationSearch(arr, sopt, x);
	if (location == -1)
	{
		cout << x << " khong thuoc mang arr" << "\n";
	}
	else
	{
		cout << x << " thuoc mang arr, vi tri trong mang:  " << location << "\n";
	}
	return 0;
}