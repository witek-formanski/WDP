Function HasAdjacentOnes(binNumber As String) As Integer
    Dim i As Integer
    Dim count As Integer
    count = 0
    
    For i = 1 To Len(binNumber)
        If Mid(binNumber, i, 1) = "1" Then
            count = count + 1
            If count >= 2 Then
                HasAdjacentOnes = 1
                Exit Function
            End If
        Else
            count = 0
        End If
    Next i
    
    HasAdjacentOnes = 0
End Function
