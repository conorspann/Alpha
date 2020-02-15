# Alpha Interpreter

A BASIC-style interpreter written in C++. Currently runs scripts as console applications.

## Usage

```
alpha <filename>
```

## Current Commands

### Variable assignment

```
@<varname> = X
```

### General

```
ConsoleOut
ConsoleIn
MemoryDump
If
EndIf
While
EndWhile
Cmd
EndCmd
```

## Example

### Script

```
Cmd loopMe()
	@foo = 1
	While(@foo < 10)
		ConsoleOut(@foo)
		@foo = @foo + 1
	EndWhile
EndCmd

loopMe()
```

### Output

```
Alpha Interpreter v 0.1
1
2
3
4
5
6
7
8
9

```