First Fit Method 1 (Only Single Processes Allowed in Blocks)

#include <stdio.h>

void implimentFirstFit(int blockSize[], int blocks, int processSize[], int processes)
{
int allocate[processes];
int occupied[blocks];
int freeSpace[blocks];

// Initialize all allocations and free spaces to -1 and block sizes, respectively
for (int i = 0; i < processes; i++)
{
allocate[i] = -1;
}
for (int i = 0; i < blocks; i++)
{
occupied[i] = 0;
freeSpace[i] = blockSize[i];
}

for (int i = 0; i < processes; i++)
{
for (int j = 0; j < blocks; j++)
{
if (!occupied[j] && blockSize[j] >= processSize[i])
{
allocate[i] = j;
occupied[j] = 1;

// Update free space in the allocated block
freeSpace[j] = blockSize[j] - processSize[i];

break;
}
}
}

printf("\nProcess No.\t\tProcess Size\t\tBlock no.\t\tFree Space\n");
for (int i = 0; i < processes; i++)
{
printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
if (allocate[i] != -1)
{
printf("%d \t\t\t%d\n", allocate[i]+1, freeSpace[allocate[i]]);
}
else
{
printf("Not Allocated\n");
}
}
}

int main()
{
int blockSize[] = {30, 5, 10};
int processSize[] = {10, 6, 9};
int m = sizeof(blockSize) / sizeof(blockSize[0]);
int n = sizeof(processSize) / sizeof(processSize[0]);

implimentFirstFit(blockSize, m, processSize, n);
return 0;
}

First Fit Method 2 (Multiple Processes Allowed)

#include <stdio.h>

void implementFirstFit(int blockSize[], int blocks, int processSize[], int processes)
{
// This will store the block id of the allocated block to a process
int allocate[processes];
// initially assigning -1 to all allocation indexes
// means nothing is allocated currently
for (int i = 0; i < processes; i++)
{
allocate[i] = -1;
}
// take each process one by one and find first block that can accomodate it
for (int i = 0; i < processes; i++)
{
for (int j = 0; j < blocks; j++)
{
if (blockSize[j] >= processSize[i])
{
// allocate block j to process i
allocate[i] = j;
// Reduce size of block j as it has accommodated process i
blockSize[j] -= processSize[i];
break;
}
}
}

printf("\nProcess No.\t\tProcess Size\t\tBlock no.\t\tFree Space\n");
for (int i = 0; i < processes; i++)
{
printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
if (allocate[i] != -1) {
printf("%d \t\t\t %d\n", allocate[i] + 1, blockSize[allocate[i]]);
} else {
printf("Not Allocated \t\t %d\n", 0);
}
}
}

int main()
{
int blockSize[] = {30, 5, 10};
int processSize[] = {10, 6, 9};
int m = sizeof(blockSize) / sizeof(blockSize[0]);
int n = sizeof(processSize) / sizeof(processSize[0]);
implementFirstFit(blockSize, m, processSize, n);
return 0;
}

Best Fit Method 1 (Processes not Allowed sharing BlockSpace)

#include <stdio.h>

void implimentBestFit(int blockSize[], int blocks, int processSize[], int proccesses)
{
// This will store the block id of the allocated block to a process
int allocation[proccesses];
int occupied[blocks];
int freeSpace[blocks];

// initially assigning -1 to all allocation indexes
// means nothing is allocated currently
for(int i = 0; i < proccesses; i++){
allocation[i] = -1;
}

for(int i = 0; i < blocks; i++){
occupied[i] = 0;
freeSpace[i] = blockSize[i];
}

// pick each process and find suitable blocks
// according to its size ad assign to it
for (int i = 0; i < proccesses; i++)
{

int indexPlaced = -1;
for (int j = 0; j < blocks; j++) {
if (blockSize[j] >= processSize[i] && !occupied[j])
{
// place it at the first block fit to accomodate process
if (indexPlaced == -1)
indexPlaced = j;

// if any future block is smalller than the current block where
// process is placed, change the block and thus indexPlaced
// this reduces the wastage thus best fit
else if (blockSize[j] < blockSize[indexPlaced])
indexPlaced = j;
}
}

// If we were successfully able to find block for the process
if (indexPlaced != -1)
{
// allocate this block j to process p[i]
allocation[i] = indexPlaced;

// reduce free space of block
freeSpace[indexPlaced] -= processSize[i];

// make the status of the block as occupied
occupied[indexPlaced] = 1;
}
}

printf("\nProcess No.\t\tProcess Size\t\tBlock no.\t\tFree Space\n");
for (int i = 0; i < proccesses; i++)
{
printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
if (allocation[i] != -1)
printf("%d\t\t\t%d\n",allocation[i] + 1, freeSpace[allocation[i]]);
else
printf("Not Allocated\n");
}
}

// Driver code
int main()
{
int blockSize[] = {100, 50, 30, 120, 35};
int processSize[] = {40, 10, 30, 60};
int blocks = sizeof(blockSize)/sizeof(blockSize[0]);
int proccesses = sizeof(processSize)/sizeof(processSize[0]);

implimentBestFit(blockSize, blocks, processSize, proccesses);

return 0 ;
}

Best Fit Method 2 (Processes Allowed sharing BlockSpace)

#include <stdio.h>

void implimentBestFit(int blockSize[], int blocks, int processSize[], int processes)
{
// This will store the block id of the allocated block to a process
int allocation[processes];

// initially assigning -1 to all allocation indexes
// means nothing is allocated currently
for(int i = 0; i < processes; i++){
allocation[i] = -1;
}

// pick each process and find suitable blocks
// according to its size ad assign to it
for (int i=0; i < processes; i++)
{

int indexPlaced = -1;
for (int j=0; j < blocks; j++) 
{ 
if (blockSize[j] >= processSize[i])
{
// place it at the first block fit to accomodate process
if (indexPlaced == -1)
indexPlaced = j;

// if any future block is better that is 
// any future block with smaller size encountered
// that can accomodate the given process
else if (blockSize[j] < blockSize[indexPlaced])
indexPlaced = j;
}
}

// If we were successfully able to find block for the process
if (indexPlaced != -1)
{
// allocate this block j to process p[i]
allocation[i] = indexPlaced;

// Reduce available memory for the block
blockSize[indexPlaced] -= processSize[i];
}
}

printf("\nProcess No.\t\tProcess Size\t\tBlock no.\t\tFree Space\n");
for (int i = 0; i < processes; i++)
{
printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
if (allocation[i] != -1) {
printf("%d \t\t\t %d\n", allocation[i] + 1, blockSize[allocation[i]]);
}
else {
printf("Not Allocated \t\t\t -\n");
}
}
}

// Driver code
int main()
{
int blockSize[] = {50, 20, 100, 90};
int processSize[] = {10, 30, 60, 80};
int blocks = sizeof(blockSize)/sizeof(blockSize[0]);
int processes = sizeof(processSize)/sizeof(processSize[0]);

implimentBestFit(blockSize, blocks, processSize, processes);

return 0 ;
}

Worst Fit Method 1 (Block allowed to keep one Process)

#include <stdio.h>

void implimentWorstFit(int blockSize[], int blocks, int processSize[], int processes)
{
// This will store the block id of the allocated block to a process
int allocation[processes];
int occupied[blocks];

// initially assigning -1 to all allocation indexes
// means nothing is allocated currently
for(int i = 0; i < processes; i++){
allocation[i] = -1;
}

for(int i = 0; i < blocks; i++){
occupied[i] = 0;
}

// pick each process and find suitable blocks
// according to its size ad assign to it
for (int i=0; i < processes; i++)
{
int indexPlaced = -1;
for(int j = 0; j < blocks; j++)
{
// if not occupied and block size is large enough
if(blockSize[j] >= processSize[i] && !occupied[j])
{
// place it at the first block fit to accomodate process
if (indexPlaced == -1)
indexPlaced = j;

// if any future block is larger than the current block where
// process is placed, change the block and thus indexPlaced
else if (blockSize[indexPlaced] < blockSize[j])
indexPlaced = j;
}
}

// If we were successfully able to find block for the process
if (indexPlaced != -1)
{
// allocate this block j to process p[i]
allocation[i] = indexPlaced;

// make the status of the block as occupied
occupied[indexPlaced] = 1;

// Reduce available memory for the block
blockSize[indexPlaced] -= processSize[i];
}
}

printf("\nProcess No.\t\tProcess Size\t\tBlock no.\t\tFree Space\n");
for (int i = 0; i < processes; i++)
{
printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
if (allocation[i] != -1)
{
printf("%d \t\t\t%d\n", allocation[i] + 1, blockSize[allocation[i]]);
}
else
{
printf("Not Allocated\t\t-\n");
}
}
}

// Driver code
int main()
{
int blockSize[] = {100, 50, 30, 120, 35};
int processSize[] = {40, 10, 30, 60};
int blocks = sizeof(blockSize)/sizeof(blockSize[0]);
int processes = sizeof(processSize)/sizeof(processSize[0]);

implimentWorstFit(blockSize, blocks, processSize, processes);

return 0;
}

Worst Fit Method 2 (Block Allowed to keep multiple Processes)

#include <stdio.h>

void implimentWorstFit(int blockSize[], int blocks, int processSize[], int processes)
{
// This will store the block id of the allocated block to a process
int allocation[processes];
// This will store the amount of free space in each block
int freeSpace[blocks];

// initially assigning -1 to all allocation indexes
// means nothing is allocated currently
for (int i = 0; i < processes; i++) {
allocation[i] = -1;
}

// initially all blocks are free
for (int i = 0; i < blocks; i++) {
freeSpace[i] = blockSize[i];
}

// pick each process and find suitable blocks
// according to its size and assign to it
for (int i = 0; i < processes; i++) {
int indexPlaced = -1;
for (int j = 0; j < blocks; j++) { 
if (blockSize[j] >= processSize[i]) {
// place it at the first block fit to accommodate process
if (indexPlaced == -1)
indexPlaced = j;
// if any future block is larger than the current block where
// process is placed, change the block and thus indexPlaced
else if (blockSize[indexPlaced] < blockSize[j])
indexPlaced = j;
}
}

// If we were successfully able to find block for the process
if (indexPlaced != -1) {
// allocate this block j to process p[i]
allocation[i] = indexPlaced;
// Reduce available memory for the block
blockSize[indexPlaced] -= processSize[i];
// Update the amount of free space in the block
freeSpace[indexPlaced] = blockSize[indexPlaced];
}
}

printf("\nProcess No.\t\tProcess Size\t\tBlock no.\t\tFree Space\n");
for (int i = 0; i < processes; i++) {
printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
if (allocation[i] != -1)
printf("%d \t\t\t %d\n", allocation[i] + 1, freeSpace[allocation[i]]);
else
printf("Not Allocated\n");
}
}

// Driver code
int main()
{
int blockSize[] = {5, 4, 3, 6, 7};
int processSize[] = {1, 3, 5, 3};
int blocks = sizeof(blockSize) / sizeof(blockSize[0]);
int processes = sizeof(processSize) / sizeof(processSize[0]);

implimentWorstFit(blockSize, blocks, processSize, processes);
return 0;
}
