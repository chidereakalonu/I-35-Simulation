.PHONY: html
html:	## run Sphinx to generate html pages
	cd rst && \
	sphinx-build -b html -d _build/doctrees . ../docs
