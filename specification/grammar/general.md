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


```ebnf
<program> =
    [<ws>],
    {
        <definition>,
        [<ws>]
    },
    "EOF";


<definition> = 
    <dbg> | <function!> | <method!> | <asm_def!> | <macro!>;


<type> =
    ("u" | "i", "8" | "16" | "32" | "64" | "128") |
    "int" |
    "fint" |
    str |
    bool |
    none
    ;

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


<block_start> = "{";
<block_end> = "}";

<attribute_start> = "[";
<attribute_end> = "]";

<hex_litteral> =
    "0x",
    {<num> | "a" | ... "f" }-;
```
