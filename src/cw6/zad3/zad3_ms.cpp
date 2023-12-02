#include <iostream>
#include <stack>

using namespace std;

bool is_ice(int layer)
{
    return layer < 0;
}

void stack_layer(stack<int> *layers, int layer, bool isIce)
{
    if (isIce)
    {
        layers->push(-abs(layer));
    }
    else
    {
        if (!layers->empty())
            layers->push(abs(layer));
    }
}

void put_on_stack(stack<int> *layers, int layer)
{
    if (layers->empty())
    {
        stack_layer(layers, layer, is_ice(layer));
        return;
    }

    int sameType = 0, otherType = 0;
    while (otherType < abs(layer) && !layers->empty())
    {
        int topLayer = layers->top();
        if (is_ice(layer) != is_ice(topLayer))
        {
            otherType += abs(topLayer);
        }
        else
        {
            sameType += topLayer;
        }
        layers->pop();
    }

    if (otherType < abs(layer))
    {
        put_on_stack(layers, layer);
        return;
    }

    int remainingLayerOfOtherType = otherType - abs(layer);
    stack_layer(layers, remainingLayerOfOtherType, !is_ice(layer));
    stack_layer(layers, sameType+layer, is_ice(layer));
}

int sadzawka(int size, int arr[])
{
    stack<int> layers;
    for (int i = 0; i < size; i++)
    {
        put_on_stack(&layers, arr[i]);
    }

    // copy results
    int resultsCount = (int)layers.size();
    for (int i = 0; i < resultsCount; i++)
    {
        arr[i] = layers.top();
        layers.pop();
    }
    return resultsCount;
}

int main()
{
    int size;
    cin >> size;
    int *arr = (int *)malloc((size_t)size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int results = sadzawka(size, arr);
    for (int i = 0; i < results; i++)
    {
        cout << arr[i] << endl;
    }

    free(arr);
}