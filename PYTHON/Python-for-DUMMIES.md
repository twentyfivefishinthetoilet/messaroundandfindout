<small><em>* All of this is written from my own learning experience, so take this with a grain of salt.</em></small>
<h2>Python for DUMMIES <label style="font-size: 14px;">by @twentyfivefishinthetoilet</label></h2>
<br>

| TABLE OF CONTENTS | |
| --- | --- |
| Lesson 1 | Hello, World! |
| Lesson 2 | Data types, variables, and comments |
| Lesson 3 | User input |
| Lesson 4 | Lists |
| Lesson 5 (A, B) | Math |
| Lesson 6 | If statements |

<br>
<label>this course was made to use as a cheat sheet for whenever i decide to put on my big boy pants and tutor people. in this course we'll be covering basic python functions and syntax to get you started on whatever the hell you want to do with this. before we start, let's go over some history of python.
</label>
<br>
<br>
<label>once upon a time in the 1990s, some nerd named Guido van Rossum was bored during christmas and decided to release a high leveled multi purpose programming language named Python. Rossum's main goal was to make an "easy to learn but hard to master" programming language by creating simple to read syntax while still being powerful.</label>
<br>
<em><small>→ &nbsp;<a href="https://www.geeksforgeeks.org/history-of-python/">geeks for geeks' long wordy version that i boiled down. if you're interested in a professional's artical, read this.</a></small></em>
<br>
<br>

| PROS    | CONS |
| -------- | ------- |
| easy to use syntax makes for efficiency | memory usage is through the roof |
| easy for beginners, even @IsacVR can learn it | unsecure, prone to security breaches |
| self compiling | self compiling |
| crap ton of libraries to pick and choose from | |
| used by TONS of people today, jobs are looking for people who know Python. | |
| bragging rights | |

<small>fun fact: python is so far away from binary that it has precision issues from time to time. running "`print(0.3 == (0.2 + 0.1))`" will return False!</small>
<br>
<br>
<label>quick little message, i fully recommend using W3School, Geeksforgeeks, learnpython, or BroCode's videos on Youtube to learn Python. the only reason im making this is for a quick little cheat sheet and for fun. heck, maybe i'll even make a dollar off of this! ...right? <small>...right?</small></label>
<br>
<br>

## Lesson 1: Hello, World!
#### CODE: 

    print("Hi Mom!!")

*functions introduced: `print()`*

`print()` is how you send messages to the output. We'll be covering why `"Hi Mom!!"` is in quotations later, but just know that if you want to print text like `Hello, World!`, you need to put it in single quotes `('')` or quotation marks/double quotes `("")`.

## Lesson 2: Data types, variables, and comments.
#### CODE: 

    # this is a comment, the code ignores this.

    """
    This
    is
    a
    muiltiline
    comment
    """

    s = "This is a string"  # you can guess what this is
    i = 5                   # int
    f = 3.1415              # float
    t = True                # bool
    f = False               # bool
    n = None                # a decloration of a variable, this variable doesn't have any value (hence "None")

*functions introduced: `None`*

*variables*
<br>
let's travel back in time to 6th grade algebra. remember variables like `x` and `y`? well, programming languages have variables too. they hold whatever information it's given, it's like a container. say i'm too lazy to type in "This is a string", i can just `print(s)` instead.

*data types*
<br>
there are 5 types in Python which are labeled in the code above. 

| Type | Description |
| --- | --- |
| String | String of characters, can be a sentence or a word |
| Int | Integer, a full number |
| Float | A number with a floating point | 
| Bools | Can only return True or False |
| `None` / Void | Has no value, placeholder. | 

*<small>\* don't know what a value is? use `type()` and then put the variable you want to check inside the parentheses. (e.x. `print(type(variable))`)</small>*
<br>
*<small>\* to print a variable, use `print(var)`, make sure not to have quotation marks around the varibale because it's not a string.</small>*

Python sets data types for you, it's smart enough to figure out that `1` is an int and `1.9` is a float. Know that in other languages, this isn't the case (in all low leveled languages at least).

## Lesson 3: User input
#### CODE: 

    i = input("What is your age? ")
    print(f"Oh! Your age is {i}.")

*functions introduced: `input()`*

`input()` is pretty self explainatory, but let's break it down. `input()` takes one parameter and it's a string to print to the output, which in this case it's "What is your age? " (added space after the question mark for readability). assigning a variable to the input allows for the user's input to be used again, in this case it's variable `i`. note that i will ALWAYS be a string until changed via type conversion.

## Lesson 4: Lists
#### CODE: 

    fruitBasket = ["Banana", "Apple", "Orange"]

*functions introduced: `None`*

A list is like a basket of fruit. in this case our list holds 3 strings: a banana, an apple, and an orange. our fruit basket variable is able to hold multiple values at once, rather than assigning something like...

    fruitBasket = "Banana"
    fruitBasket = "Apple"
    fruitBasket = "Orange"

in this instance if you were to try and print this, it would only print `"Orange"`. if we were to print our original instance of our fruitBasket lists, it would print `['Banana', 'Apple', 'Orange']`.

to sum lists up, lists can hold multiple values in once variable.

## Lesson 5 (A): Math: Arithmetic functions
#### CODE: 

    x = 5

    # Basic math functions
    x += 1  # increment by 1 - shortened version of "x = x + 1"
    x -= 1  # decrement by 1 - shortened version of "x = x - 1"
    x /= 1  # divide x by 1 - shortened version of "x = x / 1"
    x *= 1  # multiply x by 1 - shortened version of "x = x * 1"
    x **= 1 # exponent - shortened version of "x = x ** 1"
    x %= 2 # modulus - shortaned version of "x = x % 2"

    # Math functions continued
    abs(-26)   # absolute value
    pow(5, 2)   # exponent; power (5 to the power of 2)
    round(3.1415926535, 5)  # rounds a given float to the nearest digit provided
    max(1, 1, 1, 5, 1000, 2)    # prints the greatest digit given out of all the of the digits
    min(1, 1, 1, 5, 1000, 2)    # same thing as max but the most less digit
    sum([5, 4, 5, 6])   # adds the 4 numbers in the list given

*functions introduced: a crap ton; listed above*

everything is explained in the comments. 

## Lesson 5 (B): Math continued: Math functions
#### CODE: 

    import math
    
    # trigonometry
    math.sin(5 / 2)  # sine
    math.cos(0)  # cosine
    math.tan(math.pi / 4)  # tangent
    math.asin(1)  # asine 
    math.acos(1)  # acosine
    math.atan(1)  # atangent

    # other useful functions 
    math.ciel(3.1415)   # rounds up
    math.floor(3.1415)   # rounds down
    math.sqrt(5)    # square root
    math.factorial(5)   # returns the factorial of a number (5!)

    # constants
    math.pi    # math.pi = 3.141592653589793
    math.e     # math.e = 2.718281828459045
    
*functions introduced: a crap ton; listed above*

theres more math functions but these are the ones people use a lot. everything is explained in the comments. 


## Lesson 6: If statements
#### CODE: 

    age = 36
    if age >= 21:
        print("You can enter the bar!")
    else:
        print("You can't enter the bar.")

*functions introduced: `None`*

If statements are a decision making process. if a condition is true, it'll execute a block of code. otherwise (or else), it'll execute a fallback block of code. 

in my example, we have a variable that says a guy's age is 36. if we wanted to get into a bar, he could since he is of legal age. otherwise, if he were under 21, he wouldn't be denied access to the bar.


<hr>
<br>
<p style="text-align: center;">it's pretty bare bones here... don't worry, this is markdown page is still a work in progress!</p>
<br>
<hr>

<label><small><em>Thanks for reading!</small></em></label>
<br>
<label><small><em><a style="color: yellow;" href="https://buymeacoffee.com/twentyfivefishinthetoilet">Buy me a coffee...</a> &nbsp;&nbsp; <a style="color: #5865F2;" href="https://discord.com/users/867068028658909234">Contact me on Discord...</a></small></em></label>