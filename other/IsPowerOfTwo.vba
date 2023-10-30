Function IsPowerOfTwo(number As Long) As Boolean
    If number <= 0 Then
        IsPowerOfTwo = False
    Else
        IsPowerOfTwo = (number And (number - 1)) = 0
    End If
End Function
