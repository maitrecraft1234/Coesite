# only rules from general are valid here

<asm_def> =
    [<attributes>],
    [<ws>],
    "asm",
    <ws>,
    <identifier>,
    [<ws>],
    <block>;

<block> =
    <block_start>,
    [<ws>],
    {
        <statement>,
        [<ws>],
        ";",
        [<ws>],
    },
    <block_end>;

<attribute> = 
        "noreturn"
        "contained"
        ;


<statement> = <hex_litteral> 
