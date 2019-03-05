.PHONY: ignore
ignore:			## generates a .gitignore file with objects and executables
	@python mk/pyignore.py $(TARGET) $(TSTAPP) $(ALLOBJS)
