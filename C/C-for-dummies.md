<small><em>* All of this is written from my own learning experience, so take this with a grain of salt.</em></small>
<h2>C for DUMMIES <label style="font-size: 14px;">by @twentyfivefishinthetoilet</label></h2>
<label style="font-size: 17px; padding-bottom: 3px;">What will we cover in this crash course?</label><br>
<span style="padding-left: 20px; padding-bottom: 12px;">>> One word: syntax.</span>
<br>
<br>
<label style="font-size: 17px; padding-bottom: 5px;">"Why did you make this if there's like 500 other tutorials out there?"</label><br>
<span style="padding-left: 20px; padding-bottom: 12px;">>> I made this as a cheet sheet for myself so if I ever go dumb and forget what a switch does I don't need to go onto GeeksForGeeks for the 1000th 
<span style="padding-left: 20px; padding-bottom: 7px;">.&nbsp;.&nbsp;.&nbsp;time (though that may be easier than what I'm doing...). I'm posting this to github to keep track of my progress and <em>maybe</em> build my portfolio.<br><br>
<label style="font-size: 17px; padding-bottom: 5px;">"What the hell is C?"</label><br>
<span style="padding-left: 20px; padding-bottom: 7px;">>> Well, since you're on github, I'm assuming you have access to the internet and could look it up yourself, but I guess I can explain it myself with my little-to-no knowlage.<br>
<span style="padding-left: 20px; padding-bottom: 7px;">>> C is what people call a <a href="https://en.wikipedia.org/wiki/Low-level_programming_language" target="_blank">low leveled programming language</a>, it's perfect for making the backends of operating systems (e.g. Windows, Linux, Android). C is more flexable with<br>
<span style="padding-left: 20px; padding-bottom: 7px;">.&nbsp;.&nbsp;.&nbsp; memory usage, unlike a high leveled programming language like Python or (excuse my french) <em>Java</em>. C is considered the motherload of all programming languages due to it<br>
<span style="padding-left: 20px; padding-bottom: 7px;">.&nbsp;.&nbsp;.&nbsp; being so fast like the awesome programming language it is. (Fun fact: C stands for cool! <label style="font-size: 11px;"><em>just kidding, C is a spin off of B, so it doesn't stand for anything.</em></label>)
<hr>
I'm tired of using html, let's get started already.


<h2>LESSON 1: <label style="color: #32a852;">"Hello, World!"</label></h2>
<p>CODE:</p>
    
    #include <stdio.h>

    int main(){
        printf("Hello, World!");
        return 0;
    }

<label>The class</label> 
`<stdio.h>` 
<label>imports basic input and output functions, along with file editing and more.</label>
`int main(){...}` is where your main code goes. functions can be defined outside of main with `type functionName (paramaterType parameterName){...}` above `main()` and can be used in `main()`. 
<br><br>
What is a return type?<br>
<span style="padding-left: 20px; padding-bottom: 7px;">>> <a href="https://en.wikipedia.org/wiki/Return_type"><em>From Wikipedia:</em></a> In computer programming, the return type (or result type) defines and constrains the data type of the value returned from a subroutine or method.<br>
<span style="padding-left: 20px; padding-bottom: 7px;">>> Return types include `int`, `char`, `"A String"`, `float`, and `double`.
<hr>


<h2>LESSON 2: <label style="color: #32a852;">USER INPUT</label></h2>
<p>CODE:</p>
    
    #include <stdio.h>

    int main(){
        double num;

        printf("NUMBER GUESSING GAME!\n");
        printf("QUESTION: WHAT IS YOUR NUMBER? ");
        scanf("%lf",&num);
        printf("GOT IT! IS YOUR NUMBER %lf?",num);
        
        return 0;
    }

<label>This code right here is a magical number guessing game that takes one question in order to work. To take user input in C, you need to use `scanf()`. The syntax for `scanf()` is `scanf("%format", &var)`.</label><br>
<br>What is that `&` sign there for?<br>
<span style="padding-left: 20px; padding-bottom: 7px;">>> Good question! `&` is an address operator, it finds location of the variable. Giving `scanf()` a variable without a `&` sign is like telling a mailman to give a package to "John".<br>
<span style="padding-left: 20px; padding-bottom: 7px;">.&nbsp;.&nbsp;.&nbsp; Since there's like 10000 Johns out there, the mailman will just ask himself "Who the hell is John?!" and throws the package away.<br>
<span style="padding-left: 20px; padding-bottom: 7px;">>> Now, if you were to give the mailman a package with the home address, zip code, and full name, then the package will be sent successfully given to the buyer.<br><br>
Small stuff I didn't explain:
<ol>
    <li>"\n" is an escape sequence, it brings you to a new line.</li>
    <li>"%lf" is a format specifier, it'll print any double provided.</li>
    <li>I probably should have probably said this beforehand, but the semicolon (;) at the end of each line declares the end of the line.</li>
</ol>
<hr>
