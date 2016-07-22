@echo off
REM PdfToText -h
REM PdfToText -layout m2cm-manual-QAC9.0.1.pdf m2cm-manual-QAC9.0.1.txt
REM PdfToText -layout m3cm-manual-QAC9.0.1.pdf m3cm-manual-QAC9.0.1.txt
REM PdfToText -htmlmeta -layout -raw m3cm-manual-QAC9.0.1.pdf m3cm-manual-QAC9.0.1.html
REM PdfToText -htmlmeta -layout m3cm-manual-QAC9.0.1.pdf m3cm-manual-QAC9.0.1.html
PdfToText -raw m3cm-manual-QAC9.0.1.pdf m3cm-manual-QAC9.0.1_withoutform.txt
pause 