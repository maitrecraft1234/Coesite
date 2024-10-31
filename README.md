# NAME

this is meant to be a programming language that supports
both functional and imperative programming paradigms.
functional and imperative blocks will not be able to call each other
freely. the grammar and the syntax is different for each block type.

## Quirks
the lexer is separated into two parts, a tokenizer and a lexer
(I know that both mean the same thing but I don't care).
The tokenizer does not do any checks for stuff like number literals
and it only produces tokens one by one. The lexer creates and array
of lexems which are slightly higher level than my tokens.

The code base is also has very verbose names for everything including
things that shouldn't be here such as the _t for types. The reason for
this is that I want to be compliant to the epitech coding style.
anther side effect is that I can't get keep the symbols simples becasause
of the limit of functions per file and line per function meaning that big
files with static functions that only exist for one file are not allowed.
