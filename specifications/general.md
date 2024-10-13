# THIS LANGUAGE IS tHE VERSION 0.0.1-alpha1

## EBFN grammar extention, ! means it is not ready yet
## The rules defined here are valid everywhere, 
## This is not the case for the other files that will only have their own "scope"

<program> =
    {<ws>},
    {
        <definition>,
        {<ws>}
    },
    "EOF";


<definition> = 
    <function> | <method> | <asm_def> | <macro!>;


<type> =
    ("u" | "i", "8" | "16" | "32" | "64" | "128") |
    "int" |
    str |
    bool |
    none
    ;

<identifier> =
    {<alpha>}-, {<alphanum> | "_"};

<id> = <identifier>;

<alpha> =
    "a" | "b" | ... "z" | "A" | ... "Z";

<num> = 
    "0" | "1" | ... "9";

<alphanum> = <alpha> | <num>;


<whitespace> =
    {"\n" | "\t" | "\s"}-;

<ws> = <whitespace>;

<attributes> =
    "[",
    {   
        {
            <attribute>,
            {<ws>},
            ",",
            {<ws>},

        },
        <attribute>,
    },
    "]";


<block_start> = "{"
<block_end> = "}"

<attribute_start> = "["
<attribute_end> = "]"

<hex_litteral> =
    "0x",
    {<num> | "a" | ... "f" }-;
