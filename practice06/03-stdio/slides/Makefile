all: stdio


stdio: stdio.tex
	pdflatex -shell-escape stdio.tex
	pdflatex -shell-escape stdio.tex

clean:
	rm -rf *.dvi *.log *.ps *.aux *.bbl *.blg *.nav *.out *.snm *.toc *.vrb *.pdf
