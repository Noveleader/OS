FIFO Page Replacement Algorithm in C

#include<stdio.h>
int main()
{
int incomingStream[] = {4, 1, 2, 4, 5};
int pageFaults = 0;
int frames = 3;
int m, n, s, pages;

pages = sizeof(incomingStream)/sizeof(incomingStream[0]);

printf("Incoming \t Frame 1 \t Frame 2 \t Frame 3");
int temp[frames];
for(m = 0; m < frames; m++)
{
temp[m] = -1;
}

for(m = 0; m < pages; m++)
{
s = 0;

for(n = 0; n < frames; n++)
{
if(incomingStream[m] == temp[n])
{
s++;
pageFaults--;
}
}
pageFaults++;

if((pageFaults <= frames) && (s == 0))
{
temp[m] = incomingStream[m];
}
else if(s == 0)
{
temp[(pageFaults - 1) % frames] = incomingStream[m];
}

printf("\n");
printf("%d\t\t\t",incomingStream[m]);
for(n = 0; n < frames; n++)
{
if(temp[n] != -1)
printf(" %d\t\t\t", temp[n]);
else
printf(" - \t\t\t");
}
}

printf("\nTotal Page Faults:\t%d\n", pageFaults);
return 0;
}

Optimal Page Replacement Algorithm in C

#include <stdio.h>

int search(int key, int frame_items[], int frame_occupied)
{
for (int i = 0; i < frame_occupied; i++)
if (frame_items[i] == key)
return 1;
return 0;
}

void printOuterStructure(int max_frames){
printf("Stream ");

for(int i = 0; i < max_frames; i++)
printf("Frame%d ", i+1);
}
void printCurrFrames(int item, int frame_items[], int frame_occupied, int max_frames){
printf("\n%d \t\t", item);

for(int i = 0; i < max_frames; i++){
if(i < frame_occupied)
printf("%d \t\t", frame_items[i]);
else
printf("- \t\t");
}
}

int predict(int ref_str[], int frame_items[], int refStrLen, int index, int frame_occupied)
{
int result = -1, farthest = index;
for (int i = 0; i < frame_occupied; i++) {
int j;
for (j = index; j < refStrLen; j++) 
{ 
if (frame_items[i] == ref_str[j]) 
{ 
if (j > farthest) {
farthest = j;
result = i;
}
break;
}
}

if (j == refStrLen)
return i;
}

return (result == -1) ? 0 : result;
}

void optimalPage(int ref_str[], int refStrLen, int frame_items[], int max_frames)
{
int frame_occupied = 0;
printOuterStructure(max_frames);

int hits = 0;
for (int i = 0; i < refStrLen; i++) {

// If found already in the frame items : HIT
if (search(ref_str[i], frame_items, frame_occupied)) {
hits++;
printCurrFrames(ref_str[i], frame_items, frame_occupied, max_frames);
continue;
}

if (frame_occupied < max_frames){
frame_items[frame_occupied] = ref_str[i];
frame_occupied++;
printCurrFrames(ref_str[i], frame_items, frame_occupied, max_frames);
}

else {
int pos = predict(ref_str, frame_items, refStrLen, i + 1, frame_occupied);
frame_items[pos] = ref_str[i];
printCurrFrames(ref_str[i], frame_items, frame_occupied, max_frames);
}

}
printf("\n\nHits: %d\n", hits);
printf("Total Page Faults: %d\n", refStrLen - hits);
}

int main()
{
int ref_str[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
int refStrLen = sizeof(ref_str) / sizeof(ref_str[0]);
int max_frames = 3;
int frame_items[max_frames];

optimalPage(ref_str, refStrLen, frame_items, max_frames);
return 0;
}

LRU Page Replacement Algorithm in C

#include<stdio.h>
#include<limits.h>

int checkHit(int incomingPage, int queue[], int occupied){

for(int i = 0; i < occupied; i++){
if(incomingPage == queue[i])
return 1;
}

return 0;
}

void printFrame(int queue[], int occupied)
{
for(int i = 0; i < occupied; i++)
printf("%d\t\t\t",queue[i]);
}

int main()
{

int incomingStream[] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3};

int n = sizeof(incomingStream)/sizeof(incomingStream[0]);
int frames = 3;
int queue[n];
int distance[n];
int occupied = 0;
int pagefault = 0;

printf("Page\t Frame1 \t\t Frame2 \t\t Frame3\n");

for(int i = 0;i < n; i++)
{
printf("%d:  \t\t",incomingStream[i]);
if(checkHit(incomingStream[i], queue, occupied)){
printFrame(queue, occupied);
}

else if(occupied < frames){
queue[occupied] = incomingStream[i];
pagefault++;
occupied++;

printFrame(queue, occupied);
}
else{

int max = INT_MIN;
int index;
for (int j = 0; j < frames; j++)
{
distance[j] = 0;
for(int k = i - 1; k >= 0; k--)
{
++distance[j];

if(queue[j] == incomingStream[k])
break;
}

if(distance[j] > max){
max = distance[j];
index = j;
}
}
queue[index] = incomingStream[i];
printFrame(queue, occupied);
pagefault++;
}

printf("\n");
}

printf("Total Page Faults: %d\n",pagefault);

return 0;
}

All Page Replacement Algorithms in a single program

#include <stdio.h>

#define FRAMES 3
#define PAGES 15

int fifo(int[], int);
int optimal(int[], int[], int, int);
int lru(int[], int[], int, int);

int main() {
int pages[PAGES] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3};
int i, faults;

faults = fifo(pages, PAGES);
printf("FIFO faults: %d\n", faults);

int frames[FRAMES] = {0};
faults = optimal(pages, frames, PAGES, FRAMES);
printf("Optimal faults: %d\n", faults);

faults = lru(pages, frames, PAGES, FRAMES);
printf("LRU faults: %d\n", faults);

return 0;
}

int fifo(int pages[], int n) {
int frames[FRAMES] = {0};
int i, j, faults = 0, next_frame = 0, in_frames;

for (i = 0; i < n; i++) {
in_frames = 0;
for (j = 0; j < FRAMES; j++) {
if (frames[j] == pages[i]) {
in_frames = 1;
break;
}
}
if (!in_frames) {
frames[next_frame] = pages[i];
next_frame = (next_frame + 1) % FRAMES;
faults++;
}
}

return faults;
}

int optimal(int pages[], int frames[], int n, int m) {
int i, j, k, l, faults = 0, max, farthest;

for (i = 0; i < n; i++) {
int in_frames = 0;
for (j = 0; j < m; j++) {
if (frames[j] == pages[i]) {
in_frames = 1;
break;
}
}
if (!in_frames) {
faults++;
if (i < m) {
frames[i] = pages[i];
} else {
max = -1;
for (j = 0; j < m; j++) {
int found = 0;
for (k = i + 1; k < n; k++) {
if (pages[k] == frames[j]) {
found = 1;
if (k > max) {
max = k;
farthest = j;
}
break;
}
}
if (!found) {
farthest = j;
break;
}
}
frames[farthest] = pages[i];
}
}
}

return faults;
}

int lru(int pages[], int frames[], int n, int m) {
int i, j, k, l, faults = 0, min, oldest;

for (i = 0; i < n; i++) {
int in_frames = 0;
for (j = 0; j < m; j++) {
if (frames[j] == pages[i]) {
in_frames = 1;
break;
}
}
if (!in_frames) {
faults++;
if (i < m) {
frames[i] = pages[i];
} else {
min = i;
for (j = 0; j < m; j++) {
int found = 0;
for (k = i - 1; k >= 0; k--) {
if (pages[k] == frames[j]) {
found = 1;
if (k < min) {
min = k;
oldest = j;
}
break;
}
}
if (!found) {
oldest = j;
break;
}
}
frames[oldest] = pages[i];
}
}
}

return faults;
}
