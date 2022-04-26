class Solution {
public:
    void sortColors(vector<int>& arr) {
        int low=0 ,high=arr.size()-1 , mid=0;
	
	for(int i=0 ;i<arr.size();i++)
	{
		if(arr[mid]==0)
		{
			swap(arr[low],arr[mid]);
			low++;
			mid++;
		}
		
		else if(arr[mid]==1)
			mid++;
		
		else
		{
			swap(arr[mid],arr[high]);
			high--;
		}
		
			
	}
        
    }
};