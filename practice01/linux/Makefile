all: linux


linux: linux.tex
	pdflatex -shell-escape linux.tex
	pdflatex -shell-escape linux.tex

clean:
	rm -rf *.dvi *.log *.ps *.aux *.bbl *.blg *.nav *.out *.snm *.toc *.vrb  _minted-linux
