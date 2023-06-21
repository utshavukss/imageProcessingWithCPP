# MARKDOWN DOCUMENTATION SYSTEM
This is a basic document that demonstrates the use of markdown documentation system and it's components, under the **C++ Internship 2023** program.

## Header Types (This is Header 2):
Headers are specified in a markdown document by inserting hashtags before any text. the number of hashtags indicate the header levels. there are 6 header levels
### Header 3
#### Header 4
##### Header 5
###### Header 6

## Code Blocks
Code blocks are used to display code or code snippets in your Markdown document. To create a code block, you can use triple backticks ``` before and after the code. Here's an example:
### Javascript:
```javascript
    var s = "this is a js string"
    console.log(s);
```
### Python:
```python
def function()
    #this is a python comment
    s = "Python programming language"
    print s
```

## Tables
Tables are used to display tabular data in your Markdown document. To create a table, we can use the pipe character | to separate columns, and use a hyphen - to separate the header row from the rest of the table. Example:
| Heading1 | Heading2 | Heading3 |
| :----    | :-----:  | -----:   |
| Cell 1   | Cell 2   | Cell 3   |
| Cell 4   | Longer Cell 5 | Longest cell 6 .............. |

## Images
Images can be added by using the syntax: '![alt text](image URL)'
Example: "![alt text] (img/markdown_logo.png)" gives:
![alt text](img/markdown_logo.png "This is the title text")

## Links
Links can be added by using the syntax "[Link text](URL)"
The URL can represent a website link, a file existing in the same or higher directory, or a link with a title text.

[Google](https://www.google.com/:)
[This link has a title text](https://www.google.com "This takes you to google")

## Lists
Markdown Documentation system supports ordered and unordered lists. unordered lists can be created by using astreak(*) or hyphen(-) symbols before a text. nested unordered lists can also be created by indenting a symbol with 4 spaces or a tab
*Item 1
*Item 2
    Item 2.1
Ordered list can be created by prefixing a text with a number followed by a period (.). Nested ordered lists can be created through indentation as well

1. Item 1
2. Item 2
    3. Item 2.1
    4. Item 2.2


