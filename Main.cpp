#include "SDL.h"
#include <limits>
#include <time.h>
#include <string>
#include <iostream>
#include <SDL_ttf.h>



SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
const int screenWidth = 500;
const int screenHeight = 500;
int arr[screenWidth];
bool sorted = false;
int colorArr[255];

void visualize(int x = 0, int y = 0, int z = 0) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);

	int j = 0;
	for (int i = 0; i < screenWidth; i++)
	{
		SDL_PumpEvents();


		if (i == x || i == z)
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
			SDL_RenderDrawLine(renderer, screenWidth - i, screenHeight, screenWidth - i, arr[j]);
		}
		else if (i == y)
		{
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
			SDL_RenderDrawLine(renderer, screenWidth - i, screenHeight, screenWidth - i, arr[j]);
		}
		else
		{
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
			SDL_RenderDrawLine(renderer, screenWidth - i, screenHeight, screenWidth - i, arr[j]);
		}
		j++;
	}
	SDL_RenderPresent(renderer);
}

void appMenu() {
	//transfer all surfaces and textures to a separate function
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	TTF_Font* font = TTF_OpenFont("arial.ttf", 50);
	SDL_Color color = { 255, 0, 0 };
	SDL_Surface* surface = TTF_RenderText_Solid(font,
		"Selection Sort", color);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_Surface* surface2 = TTF_RenderText_Solid(font,
		"Bubble Sort", color);
	SDL_Texture* texture2 = SDL_CreateTextureFromSurface(renderer, surface2);
	SDL_Surface* surface3 = TTF_RenderText_Solid(font,
		"Insertion Sort", color);
	SDL_Texture* texture3 = SDL_CreateTextureFromSurface(renderer, surface3);
	SDL_Surface* surface4 = TTF_RenderText_Solid(font,
		"Merge Sort", color);
	SDL_Texture* texture4 = SDL_CreateTextureFromSurface(renderer, surface4);
	SDL_Surface* surface5 = TTF_RenderText_Solid(font,
		"Quick Sort", color);
	SDL_Texture* texture5 = SDL_CreateTextureFromSurface(renderer, surface5);
	SDL_Surface* surface6 = TTF_RenderText_Solid(font,
		"Heap Sort", color);
	SDL_Texture* texture6 = SDL_CreateTextureFromSurface(renderer, surface6);
	SDL_Surface* surface7 = TTF_RenderText_Solid(font,
		"Generate New Array", color);
	SDL_Texture* texture7 = SDL_CreateTextureFromSurface(renderer, surface7);
	SDL_Rect bubbleSortButton = { 25, 30, 200, 50 };
	SDL_Rect selectionSortButton = { 25, 100, 200, 50 };
	SDL_Rect insertionSortButton = { 25, 170, 200, 50 };
	SDL_Rect mergeSortButton = { 25, 240, 200, 50 };
	SDL_Rect quickSortButton = { 25, 310, 200, 50 };
	SDL_Rect heapSortButton = { 25, 380, 200, 50 };
	SDL_Rect newArrayButton = { 275, 170, 200, 50 };
	SDL_RenderCopy(renderer, texture2, NULL, &bubbleSortButton);
	SDL_RenderCopy(renderer, texture, NULL, &selectionSortButton);
	SDL_RenderCopy(renderer, texture3, NULL, &insertionSortButton);
	SDL_RenderCopy(renderer, texture4, NULL, &mergeSortButton);
	SDL_RenderCopy(renderer, texture5, NULL, &quickSortButton);
	SDL_RenderCopy(renderer, texture6, NULL, &heapSortButton);
	SDL_RenderCopy(renderer, texture7, NULL, &newArrayButton);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
	SDL_RenderDrawRect(renderer, &bubbleSortButton);
	SDL_RenderDrawRect(renderer, &selectionSortButton);
	SDL_RenderDrawRect(renderer, &insertionSortButton);
	SDL_RenderDrawRect(renderer, &mergeSortButton);
	SDL_RenderDrawRect(renderer, &quickSortButton);
	SDL_RenderDrawRect(renderer, &heapSortButton);
	SDL_RenderDrawRect(renderer, &newArrayButton);
	SDL_RenderPresent(renderer);
	TTF_CloseFont(font);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture2);
	SDL_FreeSurface(surface2);
	SDL_DestroyTexture(texture3);
	SDL_FreeSurface(surface3);
	SDL_DestroyTexture(texture4);
	SDL_FreeSurface(surface4);
	SDL_DestroyTexture(texture5);
	SDL_FreeSurface(surface5);
	SDL_DestroyTexture(texture6);
	SDL_FreeSurface(surface6);
	SDL_DestroyTexture(texture7);
	SDL_FreeSurface(surface7);
}

void displayText() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	TTF_Init();

	TTF_Font* font = TTF_OpenFont("arial.ttf", 50);
	SDL_Color color = { 255, 0, 0 };
	SDL_Surface* surface = TTF_RenderText_Solid(font,
		"Welcome to Sort Visualizer", color);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_Surface* surface2 = TTF_RenderText_Solid(font,
		"Press 0 to generate an array", color);
	SDL_Texture* texture2 = SDL_CreateTextureFromSurface(renderer, surface2);
	SDL_Rect button = { 50, 250, 400, 50 };
	SDL_Rect welcomeTextRect = { 50, 50, 400, 50 };
	SDL_Rect genArrayTextRect = { 50, 250, 400, 50 };
	SDL_RenderCopy(renderer, texture, NULL, &welcomeTextRect);
	SDL_RenderCopy(renderer, texture2, NULL, &genArrayTextRect);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
	SDL_RenderDrawRect(renderer, &button);
	SDL_RenderPresent(renderer);

	TTF_CloseFont(font);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

void quit() {
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;
	SDL_DestroyWindow(window);
	window = nullptr;
	TTF_Quit();
	SDL_Quit;
}

void swap(int* i, int* j) {
	int k = *i;
	*i = *j;
	*j = k;
}

/*void visualizeColorArray() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	int x = 250;
	int yFirst = 150;
	int ySec = 150;
	for (int i = 0; i < 255; i++) {
		SDL_SetRenderDrawColor(renderer, i, 0, 0, 0);
		SDL_RenderDrawLine(renderer, 250, 250, x, yFirst);
		if (ySec < 350 && ySec >= 150) {
			yFirst++;
			yFirst++;
		}
		else if (ySec == 350) {
			ySec = 0;
			yFirst--;
		}
		else if (ySec < 200) {

		}
	}
}*/

void visualizeUnsortedArray() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	for (int i = 0; i < screenWidth; i++) {
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
		SDL_RenderDrawLine(renderer, screenWidth - i, screenHeight, screenWidth - i, arr[i]);
	}
	SDL_RenderPresent(renderer);
}

void visualizeSortedArray() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	for (int i = 0; i < screenWidth; i++) {
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
		SDL_RenderDrawLine(renderer, screenWidth - i, screenHeight, screenWidth - i, arr[i]);
	}
	SDL_RenderPresent(renderer);
	sorted = true;
}

void mergeSortHelper(int array[], int left, int mid, int right) {
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	auto* leftArray = new int[subArrayOne];
	auto* rightArray = new int[subArrayTwo];

	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	auto indexOfSubArrayOne = 0;
	auto indexOfSubArrayTwo = 0; 
	int indexOfMergedArray = left; 


	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
			visualize(indexOfSubArrayOne, indexOfSubArrayTwo);
			visualize(0, indexOfMergedArray);
			SDL_Delay(10);
		}
		else {
			array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
			visualize(indexOfSubArrayOne, indexOfSubArrayTwo);
			visualize(0, indexOfMergedArray);
			SDL_Delay(10);
		}
		indexOfMergedArray++;
	}

	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
		visualize(0, indexOfSubArrayOne);
		SDL_Delay(15);
	}

	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
		visualize(0, indexOfSubArrayTwo);
		SDL_Delay(15);
	}
}

void mergeSort(int array[], int begin, int end) {
	if (begin >= end) {
		return;
	}
	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	mergeSortHelper(array, begin, mid, end);
}

void heapSortHelper(int array[], int n, int i) {
	int largest = i;
	int leftIdx = 2 * i + 1;
	int rightIdx = 2 * i + 2;


	if (leftIdx < n && array[leftIdx] > arr[largest]) {
		largest = leftIdx;
	}
	if (rightIdx < n && array[rightIdx] > array[largest]) {
		largest = rightIdx;
	}
	if (largest != i) {
		swap(&array[i], &array[largest]);
		visualize(array[largest], array[i]);
		SDL_Delay(25);
		heapSortHelper(array, n, largest);
	}
}

void heapSort(int array[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapSortHelper(array, n, i);
	}
	for (int i = n - 1; i > 0; i--) {
		swap(&array[0], &array[i]);
		heapSortHelper(array, i, 0);
	}
}

int quickSortHelper(int array[], int startIdx, int endIdx) {
	int pivotIdx = array[endIdx];
	int i = (startIdx - 1);

	for (int j = startIdx; j <= endIdx - 1; j++) {
		if (array[j] < pivotIdx) {
			i++;
			swap(&array[i], &array[j]);
		}
		visualize(array[i], array[j]);
		SDL_Delay(5);
	}
	swap(&array[i + 1], &array[endIdx]);
	return i + 1;
 }

void quickSort(int array[], int startIdx, int endIdx) {

	if (startIdx < endIdx) {
		int p = quickSortHelper(array, startIdx, endIdx);

		quickSort(array, startIdx, p - 1);
		quickSort(array, p + 1, endIdx);
	}
	
}

void insertionSort() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	int k, j;
	for (int i = 1; i < screenWidth; i++)
	{
		k = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > k)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
			visualize(i, j + 1);
			SDL_Delay(1);
		}
		arr[j + 1] = k;
	}
}

void selectionSort() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	int min_idx;
	for (int i = 0; i < screenWidth; i++)
	{
		min_idx = i;
		for (int j = i + 1; j < screenWidth; j++) {
			if (arr[j] < arr[min_idx]) {
				min_idx = j;
				visualize(i, min_idx);
				SDL_Delay(5);
			}
		}
		swap(&arr[min_idx], &arr[i]);
	}
}


void bubbleSort() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	for (int i = 0; i < screenWidth; i++) {

		for (int j = 0; j < screenWidth - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				visualize(j + 1, j, screenWidth);
			}
			SDL_Delay(1);
		}

	}
}

void generateRandArray() {

	for (int i = 0; i < screenWidth; i++) {
		std::fill_n(arr, i, 0);
	}

	for (int i = 0; i < screenWidth; i++) {
		arr[i] = rand() % (screenHeight);
	}

	sorted = false;
}


void createWindowApp() {

	window = SDL_CreateWindow("Sorting Visualizer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	bool appIsRunning = true;
	while (appIsRunning) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {

			if (event.type == SDL_QUIT) {
				quit();
				appIsRunning = false;
			}

			else if (event.type == SDL_KEYDOWN) {

				switch (event.key.keysym.sym)
				{
				case(SDLK_BACKSPACE):
					appMenu();
					break;
				case(SDLK_0):
					generateRandArray();
					appMenu();
					break;
				case(SDLK_1):
					if (sorted) {
						visualizeSortedArray();
					}
					else {
						visualizeUnsortedArray();
					}
					break;
				case(SDLK_r):
					generateRandArray();
					visualizeUnsortedArray();
					break;
				case(SDLK_b):
					bubbleSort();
					visualizeSortedArray();
					break;
				case(SDLK_s):
					selectionSort();
					visualizeSortedArray();
					break;
				case(SDLK_i):
					insertionSort();
					visualizeSortedArray();
					break;
				case(SDLK_3):
					displayText();
					break;
				case(SDLK_q):
					quickSort(arr, 0, screenWidth - 1);
					visualizeSortedArray();
					break;
				case(SDLK_h):
					heapSort(arr, screenWidth);
					visualizeSortedArray();
					break;
				case(SDLK_m):
					mergeSort(arr, 0, screenWidth - 1);
					visualizeSortedArray();
					break;
				}
			}
		}
	}
}

void displayInstructions() {
	std::cout << "WELCOME TO SORTING VISUALIZER" << std::endl;
	std::cout << "PRESS 3 to start" << std::endl << "PRESS 0 to generate an array" << std::endl;
	std::cout << "To see the unsorted array PRESS 1" << std::endl;
	std::cout << "PRESS 'b' to use BUBBLE SORT" << std::endl << "PRESS 's' to use SELECTION SORT"
		<< std::endl << "PRESS 'i' to use INSERTION SORT" << std::endl << "PRESS 'm' to use MERGE SORT"
		<< std::endl << "PRESS 'q' to use QUICK SORT" << std::endl << "PRESS 'h' to use HEAP SORT" << std::endl;
	std::cout << "To reset the array PRESS 'r'";
}



int main(int argc, char* argv[]) {
	displayInstructions();
	createWindowApp();
	quit();
	return 0;
}