all: strptr


strptr: strptr.tex
	pdflatex -shell-escape strptr.tex
	pdflatex -shell-escape strptr.tex

clean:
	rm -rf *.dvi *.log *.ps *.aux *.bbl *.blg *.nav *.out *.snm *.toc *.vrb *.pdf
