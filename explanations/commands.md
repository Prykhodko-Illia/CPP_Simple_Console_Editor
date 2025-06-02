# 🧪 Usage & Testing
> ❕️There are shown testing for the version with an implemented cursor \
> ❔It asks for a line and char index in the version without it

## Commands 
### Command 1: Append
#### Asking for the text to append

>Here: 
> 1. version with cursor,
> 2. version without cursor

1. Append text on the cursor position and move it on the size of the appended string.
2. Append to the end of the last char of the last line
````
Choose the command:
>1
Enter text to append:
Hello, text editor!

Successfully added
````

- Result:
> Command `5` printing all current text

![img_2.png](images/img_2.png)

### Command 2: New line
#### Creates new line
1. Adds new line after current, keeping structure.
2. Adds new line to the end of all lines.
```
Choose the command:
>2
New line is started
Choose the command:
>1
Enter text to append:
12345

Successfully added
```

- Result:

- ![img_3.png](images/img_3.png)

### Command 3: Save to file
#### Saving current text to the file
```
Choose the command:
>3
Enter the file name for saving:
sas.txt
Content were successfully written to the file
```

- Result:

![img_15.png](images/img_15.png)

### Command 4: Load from file
#### Loading content from the file
```
Choose the command:
>4
Enter the file name for loading:
sas.txt
```
- Result:

![img_16.png](images/img_16.png)

### Command 5: 
#### Print all content
```
Choose the command:
>5
Hello, text editor!
12345
```
### Command 6: Insert
#### Insert at `line` `index`
```
>6
Choose line and index:1 7
Enter text to append:
 my
```

- Result:

![img_4.png](images/img_4.png)

### Command 7: Search
#### Search for all string or char from `input` and shows where it is located
```
Hello, my text editor!
12345
Choose the command:
>7
Enter text to search:
e
Was found on:
line: 1, char: 2
line: 1, char: 12
line: 1, char: 16
```
### Command 8: Delete
#### Deletes string
1. Deletes the next `size` chars from the current cursor position
2. Deletes the next `size` chars from `line` `index` got from user
```
Choose the command:
>8
Choose number of size to delete
6
Succesfully deleted
```
>To show deletion cursor was set on line **1** index **0**

- Result:

![img_5.png](images/img_5.png)

### Command 9: Undo
#### Rejects the last change
>Contains all the changes from the start of the execution
```
 my text editor!
12345
Choose the command:
>9
```

- Result:

- ![img_6.png](images/img_6.png)

### Command 10: Redo
#### Return the last rejected change
>Contains all the rejected changes from the start of the execution
```
Hello, my text editor!
12345
Choose the command:
>10
```

- Result:

![img_7.png](images/img_7.png)

### Command 11: Cut
#### Cuts string and save it to the `copyBuffer`
1. Cuts the next `size` chars from the current cursor position
2. Cuts the next `size` chars from `line` `index` got from user
>For the demonstration cursor was set on line **2** index **0**
```
Choose the command:
>11
Choose number of symbols to cut
3
```

- Result:

![img_8.png](images/img_8.png)

### Command 12: Paste
#### Paste string from the `copyBuffer`
1. Paste string on the current cursor position
2. Paste string on `line` `index` got from user
>For the demonstration cursor was set on line **1** index **0**
```
Choose the command:
>12
```

- Result:

![img_9.png](images/img_9.png)

### Command 13: Copy
#### Copy string and save it to the `copyBuffer`
1. Copy the next `size` chars from the current cursor position
2. Copy the next `size` chars from `line` `index` got from user
>For the demonstration cursor was set on line **1** index **8**
```
Choose the command:
>13
Choose number of symbols to copy
11
// Creating new line
Choose the command:
>2
// Paste
Choose the command:
>12
```

- Result:

![img_10.png](images/img_10.png)

### Command 14: Insert with replacement
#### Inserts text with replacing current characters
1. Inserts the user `input` from the current cursor position
2. Inserts the user `input` from `line` `index` got from user
>For the demonstration cursor was set on line **2** index **0**
```
Choose the command:
>14
Enter text to append:
(*)(*)
```

- Result:

![img_11.png](images/img_11.png)

### Command 15: Set cursor
#### Sets cursor on the `line` `index`
```
123 my text editor!
(*)(*)ditor
45

Choose the command:
>15
Choose line and index for cursor
3 3
Choose the command:
>1
Enter text to append:
new Text
```

- Result:

![img_12.png](images/img_12.png)

### Command 0: end execution
#### Ends execution of the program

### Command: help
#### Shows available commands

![img_14.png](images/img_14.png)