# control structures
control structure are when allows computations to happen idk

```<condition> = <expression>```
where the expression evaluates to a boolean

### if
the `<block>` after an `<if>` will only ever evaluate if the condition
evaluates to `True`, if an else follows then either its if or block gets
evaluated, meaning that an `<if>` can only garentee the execution of a block
in the presence of an `"else", <block>`
```<if> = "if", <condition>, <block>, {"else", <if> | <block>}```

### while
the `<block>` will be executed repeteadly as long
as the condition evaluates to true
```<while> = "while", <condition>, <block>```

### for
```<for>```
