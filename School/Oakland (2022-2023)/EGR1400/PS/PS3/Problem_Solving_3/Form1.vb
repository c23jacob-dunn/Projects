Imports Excel = Microsoft.Office.Interop.Excel
Public Class Form1
    Private Sub btnExcel_Click(sender As Object, e As EventArgs) Handles btnExcel.Click
        '------------------------------------------------------
        'The Setup - always the same
        Dim oXL As Excel.Application
        Dim oWB As Excel.Workbook
        Dim oSheet As Excel.Worksheet
        oXL = New Excel.Application
        oXL.Visible = True 'this makes it so they can see what's happening
        oWB = oXL.Workbooks.Add
        oSheet = oWB.ActiveSheet
        '--------------------------------------------
        'SOLVING MX = N
        'now you have a sheet open
        'ENTER MATRIX M
        oSheet.Cells(2, "A") = "=8" 'row, column -- refers to cell A2
        oSheet.Cells(3, "A") = "=303" 'row, column -- refers to cell A3
        oSheet.Cells(2, "B") = "=303" 'row, column -- refers to cell B2
        oSheet.Cells(4, "A") = "=13323"
        oSheet.Cells(3, "B") = "=13323" 'row, column -- refers to cell B3
        oSheet.Cells(2, "C") = "=13323"
        oSheet.Cells(4, "B") = "=646443"
        oSheet.Cells(3, "C") = "=646443"
        oSheet.Cells(4, "C") = "=33380163"
        'matrix has been entered in A2..B3

        'ENTER MATRIX N
        oSheet.Cells(2, "E") = "=397" 'row, column -- refers to cell E2
        oSheet.Cells(3, "E") = "=16097" 'row, column -- refers to cell E3
        oSheet.Cells(4, "E") = "=739297"
        'matrix has been entered in E2..E3

        'now put the in the inverse command in a cell
        'Since this has to be entered as an array formula
        'follow the directions in MS Excel and use FormulaArray
        oSheet.Range("A6", "C8").FormulaArray = "=MINVERSE(A2:C4)"
        'the inverse for matrix M is there in A6:B7

        'To solve MX = N, take X = (Minverse)N
        'So Matrix is A6:B7 times E2:E3 and put answer in A10:A11
        'This is also an array formula operation just like above
        oSheet.Range("A10", "A12").FormulaArray = "=MMULT(A6:C8, E2:E4)"
        'the solution matrix X is now in A10:A11

        oWB.SaveAs("C:\Users\Jacob\Documents\Fall 2022\EGR1400\PS\PS#3\PartE.xlsx")
        oXL.Quit()
    End Sub
End Class
