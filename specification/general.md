# THIS LANGUAGE IS indev for now

## The syntax used is the EBNF syntax from the iso/iec 14977 standard
### differences from the standard:

* ranges are added to the syntax
in the form of ` {<start> | ... <end>} ` where ` <start> ` and ` <end> `
must be ascii characters and ` <start> ` must be lexicographically 
smaller than ` <end> `

* the ! mark indicates the the rule is a work in progress

* each subfolder has its own 'scope' for the syntax meaning that
the syntax is not shared between subfolders but any subfolder can
use the rules from any of the parent folders files

### why use the iso ebnf ?
no good reason iso is the worst ebnf syntax out there


```
<program> =
    [<ws>],
    {
        <definition>,
        [<ws>]
    },
    "EOF";


<definition> = 
    <function!> | <method!> | <asm_def!> | <macro!>;
```

the following types should hold values in the followin way:
* uN -> unsigned integer of N bits (from 0 to 2^N - 1)
* iN -> signed integer of N bits (from -2^(N-1) to 2^(N-1) - 1)
* int -> signed integer no size limit (dynamic allocation will encure)
* fint -> fast integer (should probably be C int size)
* str -> string list of characters utf-8 (cstring should be an array of uint8)
* bool -> boolean value False or True (no guarantee of representation)
* void -> no value (no real use for now)
```
<type> =
    ("u" | "i", "8" | "16" | "32" | "64" | "128") |
    "int" |
    "fint" |
    str |
    bool |
    void
    ;
```

```
<identifier> =
    {<alpha>}-, {<alphanum> | "_"};

<id> = <identifier>;

<alpha> =
    "a" | ... "z" | "A" | ... "Z";

<num> = 
    "0" | ... "9";

<alphanum> = <alpha> | <num>;


<whitespace> =
    {"\n" | "\t" | "\s"}-;

<ws> = <whitespace>;
```

note that each attribute might be better off as an identifier
```
<attributes> =
    <attribute_start>,
    {   
        {
            <attribute>,
            [<ws>],
            ",",
            [<ws>],

        },
        <attribute>,
    },
    <attribute_end>;
```


```
<block_start> = [<ws>], "{", [<ws>];
<block_end> = [<ws>], "}", [<ws>];

<attribute_start> = <ws>, "[", <ws>;
<attribute_end> = <ws>, "]", <ws>;

<hex_litteral> =
    "0x",
    {<num> | "a" | ... "f" }-;

<oct_litteral> =
    "0o",
    {"0" | ... "8"}-;
```
