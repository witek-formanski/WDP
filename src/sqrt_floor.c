int sqrt_floor(int x) // dla x >= 0 zwraca podłogę z pierwiastka z n
{
    int subtrahend = 1;
    int answer = 0;
    while (x >= 0)
    {
        x -= subtrahend;
        subtrahend += 2;
        answer++;
    }
    return answer-1;
}