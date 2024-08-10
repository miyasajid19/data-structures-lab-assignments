#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
bool check(float arr[], float nthterm, int index)
{
    if (arr[index] != nthterm)
    {
        return true;
    }
    return false;
}
void commonDifference(float arr[], int size)
{
    float cd = ((arr[size - 1] - arr[0]) / (float)(size));
    float nthterm = 0;
    int i = 0;
    while (nthterm < arr[size - 1])
    {
        i++;
        nthterm = arr[0] + i * cd;
        if (check(arr, nthterm, i))
        {
            cout << nthterm << " is missing";
            break;
        }
    }
}
void commonRatio(float arr[], int size)
{
    float cr = pow(((float)arr[size - 1] / arr[0]), ((float)1 / (size)));
    float nthterm = 0;
    int i = 0;
    while (nthterm < arr[size - 1])
    {
        i++;
        nthterm = arr[0] * pow(cr, i - 1);
        if (check(arr, nthterm, i - 1))
        {
            cout << nthterm << " is missing";
            break;
        }
    }
}
void harmonictoarithmetic(float arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = (float)1 / arr[i];
    }
    cout << "1 / ";
    commonDifference(arr, size);
}
void checkprogression(float arr[], int size)
{

    float cr = pow(((float)arr[size - 1] / arr[0]), ((float)1 / (size)));

    float cd = ((arr[size - 1] - arr[0]) / (float)(size));

    if ((arr[1] == arr[0] + cd) or (arr[size - 2] == (float) arr[size-1]- cd))
    {
        cout << "is arithematic progression" << endl;
        commonDifference(arr, size);
    }
    else if ((arr[1] == arr[0] * cr) or (arr[size - 2] == arr[size-1]/cr))
    {
        cout << "is geometric progression" << endl;
        commonRatio(arr, size);
    }
    else
    {
        cout << "is harmonic progression" << endl;
        harmonictoarithmetic(arr, size);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int size;
    float *arr = nullptr;
    cout << "enter the size of array : ";
    cin >> size;
    arr = new float[size]();
    for (int i = 0; i < size; i++)
    {
        cout << "element " << i + 1 << endl;
        cin >> arr[i];
    }
    checkprogression(arr, size);
    delete[] arr;
    return EXIT_SUCCESS;
}