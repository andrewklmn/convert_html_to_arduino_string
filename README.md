# HTML to Arduino string variable converter
This script converts HTML code to C++ string variables and adds arduino esp8266 webserver answer command like this: 
## Source HTML code (index.html):
```
<html>
  <body>
    <h1><Header/h1>
    <p>some text</p>
  </body>
</html>
```

## Result Arduino code(index.c):
```
 String message0 = "<html> \
   <body> \
    <h1><Header/h1>";
    
 String message1 = <p>some text</p> \
  </body> \
</html> \
";

   server.setContentLength( 552 );
   server.send(200, "text/html", message0 );
   server.sendContent( message1 );
```
## Usage:

php -f convert_html_to_arduino_string.php index.html

result file with arduino code will have same name with .cpp extension.


## HTML Restriction!
Do not use // comments in javascript! only this one /* */
