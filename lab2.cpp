#include <iostream>
#include <ctime>

int** genMatrix(int size){
    int **arr = new int *[size];
    for (int i = 0; i < size; i++){
        arr[i] = new int[size];
    }
    for (int i = 0; i < size;i++)
    {
        for (int j = 0; j < size;j++)
        {
            arr[i][j] = rand() % 100;
        }
    }
    return arr;
}

void printMatrix(int** arr,int size){
    for (int i = 0; i < size;i++)
    {
        for (int j = 0; j < size;j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main()
{
    srand(time(0));
    int size = 0;
    std::cin >> size;
    int **matrix = genMatrix(size);
    printMatrix(matrix,size);

    int* arr = new int[size * size];

    for (int i = 0; i < size * size;i++)
    {
        arr[i] = 0;
    }

    //по правым диагоналям
    int x, y, z = 0, k = 0;
	for (int i = size - 1; i >= 0; i--, z=0)
	{
		arr[k] = matrix[z][i];
		k++;
		for (int j = i + 1; j < size; j++)
		{
			z++;
			arr[k] = matrix[z][j];
            k++;
        }
    }
	for (int i = 1; i <= size - 1; i++, z=0)
	{
		arr[k] = matrix[i][z];
        k++;
        for (int j = i + 1; j < size; j++)
        {
			z++;
			arr[k] = matrix[j][z];
            k++;
        }
    }
    std::cout << "\n";
	for (int i = 0; i < size * size; i++)
	{
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    
    //по левым диагоналям
	int i=0,j=0;
    k = 0;
    for (i = 0; i <= size - 1; i++, z = 0)
    {
		arr[k]=matrix[z][i];
		k++;
		for (j = size - i; j < size; j++)
		{
			z++;
			arr[k] = matrix[z][size - j - 1];
			k++;
		}
	}
	for (i = 1; i <= size - 1; i++)
	{
		z = size - 1;
		arr[k] = matrix[i][z];
		k++; //printf("%ix%d\t",i,z);
		for (j = i + 1; j < size; j++)
		{
			z--;
			arr[k] = matrix[j][z];
			k++; //printf("%dx%d\t", j,z);
		}
	}
    std::cout << "\n";
	for (int i = 0; i < size * size; i++)
	{
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    x = (size - 1) / 2;
	y = x;
	int lim = 0, count = 0;
	while (lim <= size)
	{
		lim++;
		for(i = 0; (i < lim) && (y < size) && (y >= 0) && (x < size) && (x >= 0); i++) //вправо
			arr[count++] = matrix[x][y++];	
		for(i = 0; (i < lim) && (y < size) && (y >= 0) && (x < size) && (x >= 0); i++) //вниз
			arr[count++] = matrix[x++][y];
		lim++;
		for(i = 0; (i < lim) && (y < size) && (y >= 0) && (x < size) && (x >= 0); i++) //влево
			arr[count++] = matrix[x][y--];
		for(i = 0; (i < lim) && (y < size) && (y >= 0) && (x < size) && (x >= 0); i++) //вверх
			arr[count++] = matrix[x--][y];
	}
    std::cout << "\n";
	for (int i = 0; i < size * size; i++)
	{
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

	printf("\n  d) по спирали, начиная с левого верхнего элемента\n");
	lim=size/2;
	count=0;
	int tmp;
	for (tmp = 0; tmp < lim; tmp++)
	{
		for(i = tmp; i < size - tmp; i++, count++) //колонка вниз
			arr[count] = matrix[i][tmp];
		for(j = tmp + 1; j < size - tmp; j++, count++) //строка вправо
			arr[count] = matrix[i - 1][j];
		for(i = size - tmp - 2; i >= tmp; i--, count++) //колонка вверх
			arr[count] = matrix[i][j - 1];
		for(j = size - tmp - 2; j >= tmp + 1; j--, count++) //строка влево
			arr[count] = matrix[i + 1][j];
	}
 
	if(size % 2 != 0)
		arr[count] = matrix[lim][lim];

	for (i = 0; i < size * size; i++)
	{
		printf("%d ", arr[i]);	
	}
	printf("\n");
		
    for (i = 0; i < size; i++)
		delete []matrix[i];
	delete []arr;
	return 0;

}
