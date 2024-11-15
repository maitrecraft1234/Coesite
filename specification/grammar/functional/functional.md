# only rules from general are valid here

<function> = 
    [<attributes>], 
    "f" | "F" ,
    <ws>,
    <identifier>,
    <ws>,
    <params>,
    <block>;


<attribute> =
    "impure" |
    "entry" |
    "io"
    ;

<params> = 
    {
        <identifier>,
        ":",
        [<ws>],
        <type>
    };

<block> =
    <block_start>,
    [<ws>],
    {
        <statement>,
        [<ws>],
    },
    <block_end>;
    ;
