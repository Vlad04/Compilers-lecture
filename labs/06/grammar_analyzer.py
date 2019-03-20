import re 
import sys 
from collections import namedtuple 
 
try: 
    filename = sys.argv[1] 
    my_file = open(filename, "r") 
    grammar = my_file.read() 
except: 
    print("File not found, now we are going to use the default grammar") 
    grammar = 'S -> A | B\nA -> a\nB -> B b\nC -> c' 
 
status = True 
 
grammar = grammar.replace(" ", "") 
 
Production = namedtuple("Production", "right productive") 
 
upperCase = re.compile(r'[A-Z]') 

nonTerminals = list(set(upperCase.findall(grammar))) 

prodRightSide = re.compile(r'(?<=\->).*') 
 
productions = filter(None, grammar.split('\n')) 

d = {} 
 
for p in productions: 
    rs = prodRightSide.findall(p) 
    rse = rs[0] 
    d[p[0]] = Production(rse, rse.islower()) 
 
default = Production("",False) 
 
for k in range(0,2): 
    for i in d: 
        if(d[i].productive): 
            continue 
        else: 
            right = d[i].right 
            for l in range(len(right)): 
                if(right[l].isalpha() and d.get(right[l],default).productive): 
                    d[i] = d[i]._replace(productive=True) 
                elif(right[l] == '|' and right[l+1].islower()): 
                    d[i] = d[i]._replace(productive=True) 
 
reachable = [grammar[0]] 

erase = [] 
 
for element in d: 

    rnt = list(upperCase.findall(d[element].right)) 
    reachable = reachable + rnt 
    if(d[element].productive): 
        continue 
    else: 
        erase.append(element) 
        status = False 
 
for non_terminals in nonTerminals: 
    if non_terminals not in reachable: 
        erase.append(non_terminals) 
        status = False 
        #print(nt +" is non reachable") 
 
print(str(status)+"\n") 
 
if(not status): 
 rep = {} 
 for e in erase: 
   opt = "|"+e 
   rep[opt] = "" 
   rep[e] = "" 
 
 cleanGrammar = "" 
 
 for element in d: 
     if(d[element].productive and elem not in erase): 
                rs = d[elem].right 
                cleanGrammar = cleanGrammar+elem+" -> "+rs+"\n" 
 
 rep = dict((re.escape(k),v) for k, v in iter(rep.items())) 
 pattern = re.compile("|".join(rep.keys())) 
 cleanGrammar = pattern.sub(lambda m: rep[re.escape(m.group(0))], cleanGrammar) 
 
 print(cleanGrammar) 
