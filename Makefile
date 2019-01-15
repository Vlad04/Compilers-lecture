git :
	@git add .
	@git commit -m $(INT)
	@git push origin master

clean:
	find . -name "*~" -type f -delete


