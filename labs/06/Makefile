all :
	lex compiler.l
	gcc lex.yy.c -o lexical_analyzer -ll
	gcc syntax_calculator.c -o syntax_calculator
	python3 grammar_analyzer.py my_new_grammar.txt

clean:
	find . -name "*~" -type f -delete


