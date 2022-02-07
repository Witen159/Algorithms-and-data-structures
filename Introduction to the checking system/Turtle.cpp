#include <fstream>
#include <vector>

using namespace std;
 
int main()
{
    int width, height;
    ifstream input("turtle.in");
    ofstream output("turtle.out");
    input >> height >> width;
    vector<int> matrix(width * height);
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            input >> matrix[i * width + j];
    for (int i = height - 1; i >= 0; i--) 
        for (int j = 0; j < width; j++) 
	{
            int down = (i + 1 >= 0 && j >= 0 && i + 1 < height && j < width) ? matrix[(i + 1) * width + j] : 0;
            int left = (i >= 0 && j - 1 >= 0 && i < height && j - 1 < width) ? matrix[i * width + j - 1] : 0;
            matrix[i * width + j] = matrix[i * width + j] + ((down > left) ? down : left);
        }
    output << matrix[width - 1];
    input.close();
    output.close();
    return 0;
}