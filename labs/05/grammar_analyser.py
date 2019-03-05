import re
from sys import argv

my_grammar = argv[1]
f = open(my_grammar, "r")
grammar=f.read()

upperCase=re.compile(r'[A-Z]')

defined_nonTerminals = list(set(upperCase.findall(grammar)))

production = re.compile(r'(?<=\->).*')
productions = list(production.findall(grammar))

leftRecursive = re.compile(r'((.*){1})->[A-Z][a-z]')
leftRecursive = list(leftRecursive.findall(grammar.replace(" ", "")))

resultingLeft = []

for l in leftRecursive:
    resultingLeft = resultingLeft + (list(l))
resultingLeft = list(set(resultingLeft))

reachable = ['S']

for p in productions:
    nonTerminal = list(upperCase.findall(p))
    reachable = reachable + nonTerminal
reachable = list(set(reachable))

print("\n"+grammar+"\n")

for nt in defined_nonTerminals:
    if nt not in reachable:
        print("\n"+ nt + " is not reachable\n")
for lr in resultingLeft:
    print("\n"+ lr + " is left recursive\n")
