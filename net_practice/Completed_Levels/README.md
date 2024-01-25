# Net Practice
## TCP/IP Adressing

## OSI Model

## Subnet Mask

## About of Net Practice Project Files Errors
> [!WARNING]
> ### Problem 1
> When you try to run the **Net Practice** file on your computer, if some sections are missing (for example, the _Check_, _Get My Config_ buttons in the upper blue area and _error logs in the lower right corner_),
> you are probably encountering an error in the `show.js` file. To find out, open any `levelX.html` file in the browser and verify whether there is an error by opening it in **_Inspect_** mode.
> You may be getting an error. To solve the examples I mentioned above, I solved the problem by finding the following solution for the `g_eval_lvls` variable in the `show.js` file I just mentioned.
> 
> ```
> // Add the following lines to the following function in "show.js" and try again:
>
> function my_console_log(str)
> {
>   // console.log(str);
>   if(!g_eval_lvls)
>   {
>     g_eval_lvls = [];
>   }
> }
> ```
> ### Problem 2
> Although the required input is provided to the desired location on the `index.html` page,
> the reason why it creates problems in level advancement is that the `g_my_login` variable in the `show.js` file does not hold the value you give.
> I did not personally investigate in detail why it did not store the value. The reason was that the problem was solved when I opened index.html in a different browser and advanced the section.
>
> ### Quirks Mode Warning Problem
>
> This is not exactly a problem, but I felt good when he solved it. The reason is that the solution is simple. Of course, if you're in that mood (Quirk).
> The solution is written in the console tab when in inspection mode.

## Resources
1. [TCP/IP Adressing](https://www.techtarget.com/searchnetworking/definition/TCP-IP)
2. [OSI Model](https://www.geeksforgeeks.org/open-systems-interconnection-model-osi/)
   - [MAC Adress](https://www.geeksforgeeks.org/mac-address-in-computer-network/)
3. [Subnet Mask Table Cheat Sheet](https://www.aelius.com/njh/subnet_sheet.html)
6. [Subnet Mask Table Cheat Sheet 2](https://subnet.ninja/subnet-cheat-sheet/)
4. [Subnet Mask Cheat Sheet](https://www.freecodecamp.org/news/subnet-cheat-sheet-24-subnet-mask-30-26-27-29-and-other-ip-address-cidr-network-references/)
5. [Subnet Mask Cheat Sheet](https://www.geeksforgeeks.org/subnet-cheat-sheet/)
6. [ChatGPT](https://chat.openai.com/)
