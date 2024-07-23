//#include<iostream>
//using namespace std;
//int main()
//{
//	int a;
//	int n;
//	cin >> a;
//	for(int k=0 ; k<a ; k++)
//	{
//		cin >> n;
//		int arr[n];
//		for(int i=0 ; i<n ; i++)
//		{
//			cin >> arr[i];
//		}
//		int ce=0,co=0;
//		for(int i=0 ; i<n ; i++)
//		{
//			if(arr[i]%2 == 0)
//			{
//				ce = ce + arr[i];
//			}
//			else
//			{
//				co = co + arr[i];
//			}
//		}
//		if(ce>co)
//		{
//			cout << "YES" << endl;
//		}
//		else
//		{
//			cout << "NO" << endl;
//		}
//	}
//}
#include <iostream>
#include <queue>

using namespace std;

struct Task {
    int taskID;
    int executionTime;
    int memoryMB;
    int storageGB;

    // Define a custom comparison function for the priority queue
    bool operator<(const Task& other) const {
        // Prioritize tasks with lower execution time and memory requirements
        if (executionTime != other.executionTime) {
            return executionTime > other.executionTime;
        } else {
            return memoryMB > other.memoryMB;
        }
    }
};

int main() 
{
    // Initialize a priority queue for task scheduling
    priority_queue<Task> taskQueue;

    // Add tasks to the priority queue
    taskQueue.push({1, 20, 512, 2});
    taskQueue.push({2, 15, 256, 1});
    taskQueue.push({3, 25, 768, 3});
    taskQueue.push({4, 18, 384, 2});

    int currentMemory = 0;
    int currentTime = 0;

    while (!taskQueue.empty()) {
        Task currentTask = taskQueue.top();
        taskQueue.pop();

        // Check if executing the current task would exceed memory limit
        if (currentMemory + currentTask.memoryMB <= 1024) {
            currentMemory += currentTask.memoryMB;
            currentTime += currentTask.executionTime;
            cout << "Task " << currentTask.taskID << " executed (Execution Time: " << currentTask.executionTime << " minutes, Memory: " << currentTask.memoryMB << " MB)" << endl;
        } else {
            // If adding the task would exceed memory limit, skip it
            cout << "Task " << currentTask.taskID << " skipped due to memory constraints" << endl;
        }
    }

    cout << "Total execution time: " << currentTime << " minutes" << endl;

    return 0;
}
